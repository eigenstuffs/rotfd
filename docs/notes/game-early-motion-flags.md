# Early motion flags and forwarding

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Four ordinary C++ routines own376 text bytes and80 original exception/index bytes: `fn_80090450`(96),`fn_800904B0`(80),`fn_800927C0`(132),`fn_80092E2C`(68). Frozen handoff: `scratch/game_early_motion_flags/final_integration.json`.

The first routine calls its base update, sets low-word flags0x90000 and clears low-word bit31 through genuine64-bit flag operations. The second sets those flags after its base update, invokes its embedded +0x318 component and sends event0. The third forwards the return value of `fn_8009B868`, updates readiness from input flag0x400000 or an override byte, and copies the original64-bit flags. The original callee's return instruction preserves its computed result in r3; returning that same value explains the wrapper's original volatile-register lifetimes. The fourth invokes four state updates in order on the same receiver.

GC1.3.2 with size optimization and C++ exceptions enabled reproduces all allocated bytes, actual relocations and symbol extents. Each function owns its compiler-local eight-byte exception record and twelve-byte index record. The complete original callable index and startup tables, descriptors and trailing slots are audited. No literals, BSS, weak helpers or padding are emitted; neighboring motion math and class ownership remain outside these partial splits. The56-byte vector update remains private because its floating register schedule is unresolved.

Status: frozen isolated match, pending full integration checkpoint.
