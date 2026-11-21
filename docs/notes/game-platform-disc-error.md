# Disc error callback and fatal reset path

`src/Game/platform_disc_error.cpp` reconstructs all 448 bytes at
`8028F4D8..8028F698` and the 52-byte compiler-generated event table at
`802F2368..802F239C`. The current names and original TU boundary are
provisional. This partial split borrows diagnostic strings, shared drive
status, callback/enable/display flags, input state and one float constant;
those declarations earn no additional data credit.

The function reads the shared global drive status. Its first two physical
arguments are unused; only the signed-byte retryable argument affects the
body. It maps status 5 to event 0, 4 to 1, 6 to 2, 11 to 3 and -1 to 4.
It logs the error, clears video black, flushes video state and waits for a
retrace. If the original callback is enabled and present, it receives the
event. Otherwise the routine marks the error-display flag and invokes the
original fallback display routine.

For fatal errors, it records the OS tick and repeatedly updates the input
interface, querying code 11. The loop exits on that input result or after
1,500 milliseconds, calculated from the original hardware bus-clock word
at `800000F8`. The observed volatile clock access is retained. The reset
sequence sets video black, flushes/waits for retrace, finishes/aborts GX,
disables the locked cache and invokes `OSResetSystem(1, 0, 0)`.

The input object stores its virtual interface at offset `1C`; calls use
slots `20` and `24`. The global physical view identifies its pointer at
`154`, retaining the known logger at `110`. Unknown slots/fields are layout
placeholders. `include/Game/platform_disc_error_internal.h` records these
declarations and target-size checks without supplying their original bodies.

GC/1.3.2 emits the exact body and switch table from ordinary C++ on the first
probe. `scratch/game_disc_wait/verify_error.py --production` proves all 500
retained bytes and 45 actual relocations, including the original r2 float
and r13 global references. No unused helper code, assembly, masks or patched
object bytes are included. Full build and linked-byte evidence are recorded
in `scratch/platform_disc_poll_checkpoint.json` and its linked-byte proof.
