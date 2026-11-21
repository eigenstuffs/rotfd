# Platform reset-monitor thread

`src/Game/platform_reset_thread.cpp` owns three routines at
`801E9F8C..801EA0FC`, totaling 368 matching code bytes. Two 40-byte wrappers
suspend and resume the original thread storage at `8033E758`; the 288-byte
monitor waits for video retrace and responds to reset-switch transitions.

The monitor preserves the signed-byte narrowing of the hardware switch
state and the ordering of its shared flag checks. When reset is permitted,
it logs the existing soft-reset message, blacks and flushes the display,
waits for retrace, finishes and aborts graphics work, disables the locked
cache and pad recalibration, checks the disc, and selects the original
reset-system argument. Deferred reset and frame flags retain their original
update order. The routine loops indefinitely.

This is a partial text split. The thread storage, four referenced flag
bytes, global logger and shared message remain under their original or
existing source ownership; this unit claims no data. In particular the
symbol at `80377FC9` also spans original following bytes, which are not
claimed or changed by its one-byte declaration here.

Strict production verification accounts for exactly 368 text bytes, no
weak helpers or allocated data, and all 34 actual relocations, including
SDA21 references against R13. Final ELF checks and the complete DOL match
prove the source integration. All 667 source units remain exact, all 23
tests and progress/extent/assembly audits pass, and the original baseline
is unchanged. Evidence: `scratch/game_platform_reset_thread/verify.py`,
`scratch/platform_reset_thread_link_proof.json`, and
`scratch/platform_reset_thread_checkpoint.json`.
