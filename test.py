#!/bin/python3
from pathlib import Path
import argparse
import contextlib
import io
import re
import sys
import tempfile
import subprocess
import os

SHEVAL_PATH = "bin/sheval"
CLANG_PATH = "llvm/bin/clang"
LDC_PATH = "llvm/bin/ldc2"
LD_PATH = "llvm/bin/ld.lld"
OBJDUMP_PATH = "sh-elf-objdump"
ARCH = "sh4el-elf"

# Apply Windows-specific name fixes.
if os.name == 'nt':
	SHEVAL_PATH += ".exe"
	CLANG_PATH += ".exe"
	LDC_PATH += ".exe"
	LD_PATH += ".exe"
	OBJDUMP_PATH += ".exe"

# Windows can't start a program from a relative path with forward slashes.
SHEVAL_PATH = os.path.abspath(SHEVAL_PATH)
CLANG_PATH = os.path.abspath(CLANG_PATH)
LDC_PATH = os.path.abspath(LDC_PATH)
LD_PATH = os.path.abspath(LD_PATH)

parser = argparse.ArgumentParser(description="Runs the SuperH LLVM backend test suite.")
parser.add_argument("tests", nargs="*", help="test files to run (default: all)")
parser.add_argument("-O", dest="opt", type=int, default=0, help="optimisation level (default: 0)")
parser.add_argument("-c", "--category", action="append", default=[],
	help="only run this category, e.g. c/matrix (can be repeated)")
parser.add_argument("--dump-asm", action="store_true", help="disassemble programs with failing tests")
parser.add_argument("--debug", default="", metavar="TYPES", help="'all' for -debug, otherwise -debug-only=TYPES")
parser.add_argument("--timeout", type=float, default=5, help="seconds per sheval run (default: 5)")
parser.add_argument("--compile-timeout", type=float, default=1, help="seconds per compile (default: 1)")
args = parser.parse_args()

# OPT LEVEL
OPT = args.opt

# TESTS TO RUN
TO_RUN = [Path(t) for t in args.tests]

# DUMP ASM?
DUMP_ASM = args.dump_asm

LL_DEBUG = ""
if args.debug:
	if args.debug == "all":
		LL_DEBUG = "-debug"
	else:
		LL_DEBUG = "-debug-only=" + args.debug

TIMEOUT = args.timeout
COMPILE_TIMEOUT = args.compile_timeout

def dump_asm(file):
	proc = subprocess.run([OBJDUMP_PATH, "-m", "sh4", "--disassemble", "--disassembler-color=extended", file], stdout=subprocess.PIPE, encoding='utf-8')
	print(proc.stdout, end='')

def consume_whitespace(str):
	return str.strip()

SEP_SIZE = 64
def print_seperator(title):
	if len(title) == 0:
		i = 0
		while i < SEP_SIZE:
			print("=", end='')
			i += 1
		print()
		return

	bars = SEP_SIZE - (len(title)+2)
	i = 0
	while i < bars / 2:
		print('=', end='')
		i += 1

	print(f" {title} ", end='')

	while i < bars:
		print('=', end='')
		i += 1

TEST_FAIL = 0
TEST_PASS = 1
TEST_SKIP = 2
TEST_TIMEOUT = 3

# An indvidual test within a test bundle.
class Test:
	def __init__(self, file, name, expected, type):
		self.file = file
		self.name = name
		self.expected = expected
		self.type = type

	@staticmethod
	def parse(file, teststr):
		if not teststr.startswith("//"):
			return None
		
		# Run and expect success.
		line = consume_whitespace(teststr[2:])
		if line.startswith("RUN:"):
			line = consume_whitespace(line[4:])
			sides = line.split('=')
			lhs = consume_whitespace(sides[0])
			rhs = consume_whitespace(sides[1])
			return Test(file, lhs, rhs, "RUN")

		# Run and expect failure.
		if line.startswith("FAIL:"):
			line = consume_whitespace(line[4:])
			sides = line.split('=')
			lhs = consume_whitespace(sides[0])
			rhs = consume_whitespace(sides[1])
			return Test(file, lhs, rhs, "FAIL")

		# Do not run
		if line.startswith("SKIP:"):
			line = consume_whitespace(line[4:])
			sides = line.split('=')
			lhs = consume_whitespace(sides[0])
			rhs = consume_whitespace(sides[1])
			return Test(file, lhs, rhs, "SKIP")

		return None

	# The core sheval execution function
	def exec(self, obj, timeout):
		proc = subprocess.run([SHEVAL_PATH, obj.name, "-e", self.name], stdout=subprocess.PIPE, timeout=timeout, encoding='utf-8')
		return proc.stdout.strip()

	# Runs the test, returning true if it succeeded,
	# false if it failed, raises an Exception if it
	# failed due to timeout.
	def run(self, obj, timeout):
		print(f"    {self.name}: ", end='', flush=True)
		match self.type:
			case "SKIP":
				print("\033[1;33mSKIPPED\033[0m")
				return TEST_SKIP

			case "RUN":
				try:
					res = self.exec(obj, timeout)
					if res == self.expected:
						print("\033[0;32mPASSED\033[0m")
						return TEST_PASS
					else:
						print(f"\033[0;31mFAILED\033[0m (expected {self.expected}, got {res})")
						return TEST_FAIL

				except subprocess.TimeoutExpired as ex:
					print("\033[1;33mTIMEOUT\033[0m")
					return TEST_TIMEOUT

				return TEST_FAIL

			case "FAIL":
				try:
					res = self.exec(obj, timeout)
					if res != self.expected:
						print("\033[0;32mFAILED\033[0m (expected)")
						return TEST_PASS
					else:
						print(f"\033[0;31mPASSED\033[0m (unexpected)")
						return TEST_FAIL

				except subprocess.TimeoutExpired as ex:
					print("\033[1;33mTIMEOUT\033[0m")
					return TEST_TIMEOUT

				return TEST_FAIL

			case _:
				print(f"\033[0;31mFAILED\033[0m (unknown test type {self.type})")
				return TEST_FAIL



# A test file bundle
class TestFile:
	def __init__(self, file):
		self.file = file;
		self.category = Path(file).parent.relative_to("testsuite").as_posix()
		self.f = open(file, "r", encoding="utf-8")
		self.tests: list[Test] = []
		
		# Parse test strings.
		for line in self.f:
			if line.startswith("//"):
				ntest = Test.parse(self, line)
				if ntest != None:
					self.tests.append(ntest)

	def skips_all(self):
		skipc = 0
		for test in self.tests:
			if test.type == "SKIP":
				skipc += 1

		return skipc == len(self.tests)


	# Compiles a test file.
	def compile(self):
		# On Windows, clang, ld.lld and sheval can't open the temporary file while it's
		# open here, and a default temporary file is deleted as soon as it's closed. So keep
		# it (delete=False), close it straight away, and remove it ourselves afterwards.
		with tempfile.NamedTemporaryFile(suffix=".o", delete=False) as obj:
			obj.close()
			if self.file.endswith(".c"):
				args = [CLANG_PATH, "-nostdlib", "-ffreestanding", "-Itestsuite/c", f"--target={ARCH}", f"-O{OPT}", "-c", self.file, "-o", obj.name]
				if len(LL_DEBUG) != 0:
					args.append(f"-mllvm={LL_DEBUG}")

				res = subprocess.run(args, timeout=COMPILE_TIMEOUT, capture_output=True, encoding='utf-8')
			elif self.file.endswith(".d"):
				args = [LDC_PATH, "-nostdlib", f"--arch={ARCH}", f"-O{OPT}", "-c", self.file, f"-of={obj.name}"]
				if len(LL_DEBUG) != 0:
					args.append(LL_DEBUG)

				res = subprocess.run(args, timeout=COMPILE_TIMEOUT, capture_output=True, encoding='utf-8')
			else:
				raise Exception("Unsupported filetype!")

			if len(res.stdout) != 0 or len(res.stderr) != 0:
				print_seperator("COMPILER LOG")
				print(res.stdout)
				print(res.stderr, end='')
				print_seperator("")

			of = tempfile.NamedTemporaryFile(delete=False)
			of.close()
			try:
				if res.returncode == 0:
					res = subprocess.run([LD_PATH, "-EL", obj.name, "-o", of.name], capture_output=True, encoding='utf-8')
					if res.returncode == 0:
						return of

				os.remove(of.name)
				raise Exception(res.stderr)
			finally:
				os.remove(obj.name)

	def run_tests(self) -> list[int]:
		results: list[int] = [0, 0, 0, 0]

		# Skip compilation if unneccesary.
		if self.skips_all():
			for test in self.tests:
				res = test.run(None, TIMEOUT)
				results[res] += 1
			return results

		try:
			obj = self.compile()

		except subprocess.TimeoutExpired as ex:
			print(f"\033[0;31mERROR\033[0m: failed to compile!\n")
			if ex.stderr:
				print_seperator("ERROR LOG")
				print("\n"+ex.stderr.decode('utf-8'), end='', flush=True)
				print_seperator("")
			results[TEST_FAIL] = len(self.tests)
			return results

		except Exception as ex:
			print(f"\033[0;31mERROR\033[0m: failed to compile or link!")
			if len(str(ex)) > 0:
				print(str(ex).rstrip())

			results[TEST_FAIL] = len(self.tests)
			return results

		for test in self.tests:
			res = test.run(obj, TIMEOUT)
			results[res] += 1

		if (results[TEST_FAIL] > 0 or results[TEST_TIMEOUT] > 0) and DUMP_ASM:
			print_seperator("ASSEMBLY")
			dump_asm(obj.name)
			print_seperator("")

		os.remove(obj.name)
		return results


class Tee:
	"""Writes to several streams at once (the console and a category's results)."""
	def __init__(self, *streams):
		self.streams = streams

	def write(self, text):
		for s in self.streams:
			s.write(text)

	def flush(self):
		for s in self.streams:
			s.flush()


# Find all tests in directory.
ALL_TESTS = sorted(list(Path("./testsuite").glob('**/*.c')) + list(Path("./testsuite").glob('**/*.d')))

TOTAL = 0
TESTS: list[TestFile] = []
for f in ALL_TESTS:
	tf = TestFile(str(f))
	if len(tf.tests) > 0:
		if len(args.category) > 0 and not any(tf.category == c.strip("/") or tf.category.startswith(c.strip("/") + "/") for c in args.category):
			continue
		if (len(TO_RUN) > 0):
			if Path(tf.file) in TO_RUN:
				TESTS.append(tf)
				TOTAL += len(tf.tests)
			continue

		TESTS.append(tf)
		TOTAL += len(tf.tests)

if TOTAL == 0:
	print("No tests to run...")
	quit()

# Group the tests by category (the folder they're in, e.g. c/matrix).
CATEGORIES: dict[str, list[TestFile]] = {}
for test in TESTS:
	CATEGORIES.setdefault(test.category, []).append(test)

RESULTS: list[int] = [0, 0, 0, 0]
SUMMARY = []
Path("results").mkdir(exist_ok=True)
print(f"Running {TOTAL} tests...")
for category, tests in CATEGORIES.items():
	cat_passed = cat_failed = cat_timedout = cat_skipped = 0
	log = io.StringIO()
	with contextlib.redirect_stdout(Tee(sys.stdout, log)):
		print("")
		print_seperator(category)
		print("")
		for test in tests:
			print("")
			print(f"{test.file} ({len(test.tests)} tests): ")
			res = test.run_tests()
			cat_failed += res[TEST_FAIL]
			cat_passed += res[TEST_PASS]
			cat_skipped += res[TEST_SKIP]
			cat_timedout += res[TEST_TIMEOUT]
		print(f"\n{category}: {cat_passed} passed, {cat_failed} failed, {cat_skipped} skipped, {cat_timedout} timed out")

	# Save this category's results, without colour codes.
	text = re.sub(r"\033\[[0-9;]*m", "", log.getvalue())
	Path("results", category.replace("/", "_") + ".txt").write_text(text.lstrip("\n"), encoding="utf-8")
	SUMMARY.append((category, cat_passed, cat_failed, cat_skipped, cat_timedout))
	RESULTS[TEST_FAIL] += cat_failed
	RESULTS[TEST_PASS] += cat_passed
	RESULTS[TEST_SKIP] += cat_skipped
	RESULTS[TEST_TIMEOUT] += cat_timedout

# Colours a count (already padded) if it's non-zero.
def colour(text, count, code):
	return f"{code}{text}\033[0m" if count > 0 else text

def summary_row(category, passed, failed, skipped, timedout, colours):
	if not colours:
		return f"{category:<20} {passed:>7} {failed:>7} {skipped:>8} {timedout:>10}"
	# The category name is green if everything in it passed, red otherwise.
	name = f"\033[0;32m{category:<20}\033[0m" if failed == 0 and timedout == 0 else f"\033[0;31m{category:<20}\033[0m"
	return (name + 
		" " + colour(f"{passed:>7}", passed, "\033[0;32m") + 
		" " + colour(f"{failed:>7}", failed, "\033[0;31m") + 
		" " + colour(f"{skipped:>8}", skipped, "\033[1;33m") +
		" " + colour(f"{timedout:>10}", timedout, "\033[1;33m") 
	)

header = f"{'CATEGORY':<20} {'PASSED':>7} {'FAILED':>7} {'SKIPPED':>8} {'TIMED OUT':>10}"
summary = "\n".join([header] + [summary_row(*row, False) for row in SUMMARY])
Path("results", "summary.txt").write_text(f"OPT={OPT}\n\n{summary}\n", encoding="utf-8")
print("")
print_seperator("RESULTS BY CATEGORY")
print("")
print(header)
for row in SUMMARY:
	print(summary_row(*row, True))

COVERAGE = int((float(RESULTS[TEST_PASS]+RESULTS[TEST_SKIP]) / float(TOTAL)) * 100)

print("")
print_seperator("TOTAL")
print(f"\nPASSED:\t\t" + colour(str(RESULTS[TEST_PASS]), RESULTS[TEST_PASS], "\033[0;32m"))
print(f"SKIPPED:\t" + colour(str(RESULTS[TEST_SKIP]), RESULTS[TEST_SKIP], "\033[1;33m"))
print(f"FAILED:\t\t" + colour(str(RESULTS[TEST_FAIL]), RESULTS[TEST_FAIL], "\033[0;31m"))
print(f"TIMED OUT:\t" + colour(str(RESULTS[TEST_TIMEOUT]), RESULTS[TEST_TIMEOUT], "\033[1;33m"))
print("\nResults for each category are in results/")
print("")
print(f"Coverage %:\t{COVERAGE}%");
