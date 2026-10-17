/* Store to a fixed hardware address (Dreamcast MMIO-style write; real MMIO
 * code would use volatile, which isn't implemented yet).
 *
 * Compile-only: 0x12345678 is outside the simulated 16 MiB address space. */
void f(void) { *(unsigned *)0x12345678u = 0x30; }
