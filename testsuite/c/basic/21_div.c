/* Divide (libcall to __sh_divsi3 / __sh_udivsi3).
 *
 * Compile-only: the helpers are still empty stubs in
 * compiler-rt/lib/builtins/superh, and nothing else provides them, so this
 * can't be linked yet. Kept apart from 05_mul.c so the unresolved helpers
 * don't stop the multiply tests from linking. */
int      sdiv(int a, int b)           { return a / b; }
unsigned udiv(unsigned a, unsigned b) { return a / b; }
