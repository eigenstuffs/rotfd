# Dolphin SDK semaphore operations

`src/dolphin/os/OSSemaphore.c` recovers `OSInitSemaphore`, `OSWaitSemaphore`, and `OSSignalSemaphore` at `0x800F57EC..0x800F5914` (88, 112, and 96 bytes respectively; 296 total).

The [Twilight Princess SDK reconstruction](https://github.com/zeldaret/tp/blob/main/libs/dolphin/src/os/OSSemaphore.c) supplies matching function names and algorithms. The target semaphore is a signed 32-bit count followed by an eight-byte thread queue. Wait returns the count before decrementing; signal returns the count before incrementing and waking queued threads. The reference's assignment in the wait condition is retained because it reproduces the original reload before decrementing. Try-wait and count-query APIs from the reference are absent from this linked group and omitted.

GC/1.2.5n with the normal Gekko C flags and `-O4,p -inline auto -i src/dolphin/os` matches all instructions and relocations. The isolated verifier reports `TEXT 296 296`. No data objects or assembly are emitted. Whole-DOL SHA-1 remains the integration check.
