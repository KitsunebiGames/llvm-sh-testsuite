#!/bin/python3
from pathlib import Path
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

# OPT LEVEL
OPT = 0
if "OPT" in os.environ:
	OPT = int(os.environ["OPT"])

# TESTS TO RUN
TO_RUN = []
if "TO_RUN" in os.environ:
	for i in os.environ["TO_RUN"].split(','):
		TO_RUN.append(i.strip())

# DUMP ASM?
DUMP_ASM = False
if "DUMP_ASM" in os.environ:
	DUMP_ASM = os.environ["DUMP_ASM"] == "1"

LL_DEBUG = ""
if "DEBUG" in os.environ:
	if os.environ["DEBUG"] == "all":
		LL_DEBUG = "-debug"
	else:
		LL_DEBUG = "-debug-only=" + os.environ["DEBUG"]

TIMEOUT = 5
if "TIMEOUT" in os.environ:
	TIMEOUT = float(os.environ["TIMEOUT"])

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
		with tempfile.NamedTemporaryFile(suffix=".o") as obj:
			if self.file.endswith(".c"):
				args = [CLANG_PATH, "-nostdlib", f"--target={ARCH}", f"-O{OPT}", "-c", self.file, "-o", obj.name]
				if len(LL_DEBUG) != 0:
					args.append(f"-mllvm={LL_DEBUG}")

				res = subprocess.run(args, timeout=1, capture_output=True, encoding='utf-8')
			elif self.file.endswith(".d"):
				args = [LDC_PATH, "-nostdlib", f"--arch={ARCH}", f"-O{OPT}", "-c", self.file, f"-of={obj.name}"]
				if len(LL_DEBUG) != 0:
					args.append(LL_DEBUG)

				res = subprocess.run(args, timeout=1, capture_output=True, encoding='utf-8')
			else:
				raise Exception("Unsupported filetype!")

			if len(res.stdout) != 0 or len(res.stderr) != 0:
				print_seperator("COMPILER LOG")
				print(res.stdout)
				print(res.stderr, end='')
				print_seperator("")

			of = tempfile.NamedTemporaryFile()
			if res.returncode == 0:
				res = subprocess.call([LD_PATH, "-EL", obj.name, "-o", of.name], stderr=subprocess.PIPE)
				if res == 0:
					return of
				raise Exception(res.stderr)
			
			raise Exception(res.stderr)

	def run_tests(self):
		passed = 0
		failed = 0
		timedout = 0
		try:
			obj = self.compile()
		except subprocess.TimeoutExpired as ex:
			print(f"\033[0;31mERROR\033[0m: failed to compile!\n")
			if len(ex.stderr) > 0:
				print_seperator("ERROR LOG")
				print(ex.stderr.decode('utf-8'), end='', flush=True)
				print_seperator("")
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

		obj.close()
		return (passed, failed, timedout)


# Find all tests in directory.
ALL_TESTS = list(Path("./testsuite").glob('**/*.c')) + list(Path("./testsuite").glob('**/*.d'))

TOTAL = 0
TESTS: list[TestFile] = []
for f in ALL_TESTS:
	tf = TestFile(str(f))
	if len(tf.tests) > 0:
		if (len(TO_RUN) > 0):
			if tf.file in TO_RUN:
				TESTS.append(tf)
				TOTAL += len(tf.tests)
			continue

		TESTS.append(tf)
		TOTAL += len(tf.tests)

PASSED = 0
FAILED = 0
TIMEDOUT = 0
print(f"Running {TOTAL} tests...")
for test in TESTS:
	print("")
	print(f"{test.file} ({len(test.tests)} tests): ")
	res = test.run_tests()
	PASSED += res[0]
	FAILED += res[1]
	TIMEDOUT += res[2]

print(f"\nPASSED:\t\t{PASSED}")
print(f"FAILED:\t\t{FAILED}")
print(f"TIMED OUT:\t{TIMEDOUT}")
