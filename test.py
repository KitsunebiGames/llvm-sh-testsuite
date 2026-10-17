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

def exec_sheval(file, fn):
	proc = subprocess.run([SHEVAL_PATH, file, "-e", fn], stdout=subprocess.PIPE, timeout=TIMEOUT, encoding='utf-8')
	return proc.stdout

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


class TestFile:
	def __init__(self, file):
		self.file = file;
		self.category = Path(file).parent.relative_to("testsuite").as_posix()
		self.f = open(file, "r", encoding="utf-8")
		self.tests: list[tuple[str, str]] = []
		
		# Parse test strings.
		for line in self.f:
			if line.startswith("//"):
				line = consume_whitespace(line[2:])
				if line.startswith("RUN:"):
					line = consume_whitespace(line[4:])
					sides = line.split('=')
					lhs = consume_whitespace(sides[0])
					rhs = consume_whitespace(sides[1])
					self.tests.append((lhs, rhs))



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

	def run_tests(self):
		passed = 0
		failed = 0
		timedout = 0
		try:
			obj = self.compile()
		except subprocess.TimeoutExpired as ex:
			print(f"\033[0;31mERROR\033[0m: failed to compile!\n")
			if ex.stderr:
				print_seperator("ERROR LOG")
				print(ex.stderr.decode('utf-8'), end='', flush=True)
				print_seperator("")
			return (0, len(self.tests), 0)
		except Exception as ex:
			print(f"\033[0;31mERROR\033[0m: failed to compile or link!")
			if len(str(ex)) > 0:
				print(str(ex).rstrip())
			return (0, len(self.tests), 0)

		for test in self.tests:
			print(f"    {test[0]}: ", end='', flush=True)
			try:
				res = exec_sheval(obj.name, test[0]).strip()
				if res == test[1]:
					print("\033[0;32mSUCCESS\033[0m")
					passed += 1
				else:
					print(f"\033[0;31mFAILURE\033[0m (expected {test[1]}, got {res})")
					failed += 1

			except subprocess.TimeoutExpired:
				print("\033[1;33mTIMEOUT\033[0m")
				timedout += 1

		if (failed > 0 or timedout > 0) and DUMP_ASM:
			print_seperator("ASSEMBLY")
			dump_asm(obj.name)
			print_seperator("")

		os.remove(obj.name)
		return (passed, failed, timedout)


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

# Group the tests by category (the folder they're in, e.g. c/matrix).
CATEGORIES: dict[str, list[TestFile]] = {}
for test in TESTS:
	CATEGORIES.setdefault(test.category, []).append(test)

PASSED = 0
FAILED = 0
TIMEDOUT = 0
SUMMARY = []
Path("results").mkdir(exist_ok=True)
print(f"Running {TOTAL} tests...")
for category, tests in CATEGORIES.items():
	cat_passed = cat_failed = cat_timedout = 0
	log = io.StringIO()
	with contextlib.redirect_stdout(Tee(sys.stdout, log)):
		print("")
		print_seperator(category)
		print("")
		for test in tests:
			print("")
			print(f"{test.file} ({len(test.tests)} tests): ")
			res = test.run_tests()
			cat_passed += res[0]
			cat_failed += res[1]
			cat_timedout += res[2]
		print(f"\n{category}: {cat_passed} passed, {cat_failed} failed, {cat_timedout} timed out")

	# Save this category's results, without colour codes.
	text = re.sub(r"\033\[[0-9;]*m", "", log.getvalue())
	Path("results", category.replace("/", "_") + ".txt").write_text(text.lstrip("\n"), encoding="utf-8")
	SUMMARY.append((category, cat_passed, cat_failed, cat_timedout))
	PASSED += cat_passed
	FAILED += cat_failed
	TIMEDOUT += cat_timedout

# Colours a count (already padded) if it's non-zero.
def colour(text, count, code):
	return f"{code}{text}\033[0m" if count > 0 else text

def summary_row(category, passed, failed, timedout, colours):
	if not colours:
		return f"{category:<20} {passed:>7} {failed:>7} {timedout:>10}"
	# The category name is green if everything in it passed, red otherwise.
	name = f"\033[0;32m{category:<20}\033[0m" if failed == 0 and timedout == 0 else f"\033[0;31m{category:<20}\033[0m"
	return (name + " " + colour(f"{passed:>7}", passed, "\033[0;32m") + " "
		+ colour(f"{failed:>7}", failed, "\033[0;31m") + " " + colour(f"{timedout:>10}", timedout, "\033[1;33m"))

header = f"{'CATEGORY':<20} {'PASSED':>7} {'FAILED':>7} {'TIMED OUT':>10}"
summary = "\n".join([header] + [summary_row(*row, False) for row in SUMMARY])
Path("results", "summary.txt").write_text(f"OPT={OPT}\n\n{summary}\n", encoding="utf-8")
print("")
print_seperator("RESULTS BY CATEGORY")
print("")
print(header)
for row in SUMMARY:
	print(summary_row(*row, True))

print(f"\nPASSED:\t\t" + colour(str(PASSED), PASSED, "\033[0;32m"))
print(f"FAILED:\t\t" + colour(str(FAILED), FAILED, "\033[0;31m"))
print(f"TIMED OUT:\t" + colour(str(TIMEDOUT), TIMEDOUT, "\033[1;33m"))
print("\nResults for each category are in results/")
