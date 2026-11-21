# Scene transition controls at 80030E9C

Isolated strict original-byte and actual-relocation verification passes for
`src/Game/early_scene_transition_controls_80030E9C.cpp`: 960 text bytes,
40 extab bytes and 12 extabindex bytes. Parent full-game integration and DOL
acceptance remain required. The existing C entry `fn_80030E9C` is preserved.

The routine selects a scene Handle by mode, resets sound/UI state, disables
unselected scene entries, dispatches event 13, applies the selected owner
resource, resets mode state and passes the selected value to two final module
operations. It returns integer 1. Existing callers that ignore that return
remain unchanged.

The private views establish owner vptr at +8, Handles at +60/+6C/+88/+8C/+90,
active byte +94; resource count/value at +DC/+E4; scene owner pointer +15058;
scene-owner Handle +60 and signed short state +210. Manager entries have
16-byte stride, object pointer +0 and signed generation +C. Opaque spans are
minimum observed storage, not a recovered full class definition. Virtual sound
reset is table slot +38 through object vptr +1C; mode finish/reset are slots
+64/+2C through vptr +7C. The first probe's sole retained instruction mismatch
was an incorrectly declared +68 mode-finish slot, corrected to the observed
+64 slot. No artificial scheduling or instruction forcing is used.

GC 1.3.2 with proc 750, hardware FP, enum int, str reuse, common off, -O4,s,
inline auto, exceptions on and lmw/stmw on reproduces the original. The
const Entry pointer resolver follows the accepted adjacent 80031328 view.
Named nontrivial returned Handle expressions reproduce original temporary
stack positions and the two exception cleanup records.

Both retained cleanup pointers resolve to independently verified accepted
GLOBAL strong destructors: Handle_8002B67C (112 bytes) and Handle_80020C04
(116). Their canonical sources, recursive headers, production objects, fresh
recompiles, original section bytes and actual relocations are frozen in the
strong-owner proof. No shared symbol rename or new verifier adapter is needed.
The unchanged strict ELF/EH gate accounts for 37 retained and 18 discarded real
relocations. All 1,012 original owned bytes are exact after strong resolution.

Three trailing weak backups total 304 text and 124 EH/index bytes, all
uncredited: Handle_80020C04 (116), private TransitionZero_30E9C (76) and
Handle_8002B67C (112). A real MWLD link using current accepted strong production
objects proves all nine backup text/EH/index allocations discarded and both
strong owners selected. Supplying an incorrect fixture input basename is
rejected. This isolated proof does not establish full-game placement.

Complete original-table audit scans extabindex 80015F60..8001F2C0, constructors
80299920..80299980 and destructors 80299980..802999A0. Only the original owned
index points inside this function; there are no startup pointers. A separate
initialized-DOL pointer audit covers every initialized data slot, preserves
the sole exact C-entry identity and records its original index owner. No data,
BSS, literal pool, constructor or destructor table range is transferred.
Existing original/accepted source-header callers are inventoried and untouched.
This is a partial original text/EH split, not recovery of a complete original TU.

Evidence, strict fresh recompile, allocated/symbol inventory, original ownership
and native discard proof are in
`scratch/game_early_scene_transition_controls_continuation/`. The final manifest
and handoff pin production source, complete artifacts and unchanged core hashes.
