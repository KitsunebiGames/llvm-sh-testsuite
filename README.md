# SuperH LLVM Backend Testsuite

This is a test suite built atop of sheval, to use the test suite, compile sheval and put it in the
bin/ directory.

After this, create a symbolic link to the LLVM install directory called "llvm/" in the root of this directory.

You can then run `test.py` to run the entire test suite.

The LLVM build needs to include lld (`-DLLVM_ENABLE_PROJECTS="clang;lld"`). On Windows, a directory junction
works for the link: `mklink /J llvm C:\path\to\llvm`.

Run `test.py --help` for its options, e.g. `test.py -O1 -c c/matrix` runs only the `c/matrix` tests at `-O1`.

Tests are grouped into categories by the folder they're in (e.g. `testsuite/c/matrix` is `c/matrix`).
Results are printed category by category with a summary table at the end, and saved to
`results/<category>.txt` and `results/summary.txt`.
