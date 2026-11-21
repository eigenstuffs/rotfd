# Controller cleanup and output

Seven adjacent functions at `0x801F00B0..0x801F0290` reproduce 480 bytes of game
code from C++. Their surrounding class hierarchy is not fully recovered;
local storage views expose only fields accessed by these routines.

The cleanup function implements the observed destructor ABI: restore the
virtual table, destroy the action array, call the base cleanup with a zero
deleting flag, and release the object if its signed deleting flag is positive.
The array owns 140-byte actions with empty destructors. Ordinary C++ element
destruction produces the original otherwise-empty loops; allocation cleanup
uses the same allocator calls as the previously recovered action initializer.

Two functions set and clear bits at offset `0xB04`, and two are empty hooks.
Another function terminates a buffered message, reports it through
`OSReport`, clears the 24 KiB buffer and resets its recorded length. The
original length assumptions are preserved in this reconstruction.

The initialization entry point calls the recovered action initializer,
selects action bit one through its virtual method, and returns success.
`include/game_controller.h` shares the inferred class and action layouts with
the previously recovered callback unit. Both units retain their exact bytes
after replacing their separate action declarations with this shared header.

GC/1.3.2 with `-O4,p -inline auto` and the normal Gekko game flags matches all
480 text bytes and 14 relocations. The virtual table, format string, allocator
and base destructor remain external; this partial split owns no data or BSS.
`scratch/controller_cleanup/verify.py` is the isolated verifier. Final DOL
SHA-1 and native objdiff verification passed after integration.
