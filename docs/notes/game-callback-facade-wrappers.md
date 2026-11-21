# Callback facade wrappers

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Production integration is accepted. The canonical manifest is
`config/GSQE78/candidates/game-callback-facade-wrappers.json`. The complete DOL passes its original SHA-1,
`ninja changes` shows no regressions, source extent and progress checks pass,
and all 26 unit tests pass.

Three partial text units reconstruct **ten complete functions and 684 bytes**:
`callback_facade_primary.cpp` owns `8025E064..8025E11C` (184 bytes),
`callback_facade_forward.cpp` owns `8025E2FC..8025E31C` (32 bytes), and
`callback_facade_secondary.cpp` owns `8025E428..8025E5FC` (468 bytes).

The primary and secondary facades forward to their respective global callback
lists and then the shared list. Their query wrappers return the first result
other than minus one, preserving the second query and fallback branch.
The remaining wrappers forward to an existing helper, invoke the target stored
at `lbl_801E9D24+144`, convert the float parameter at `+2C` to an integer or
byte, or invoke virtual table slot `+28` with zero. The no-parameter target
wrapper preserves the incoming second argument; its receiver is unused.

A private C++ prefix places the virtual pointer at receiver `+08`. Virtual
methods are declared without defining any tables or replacing their existing
owners. Original global pointers, constants, table data, neighboring functions
and all dependency bodies retain their prior ownership. These fragments do
not claim the complete original translation units.

`scratch/game_callback_facade_wrappers/verify.py` recompiles each production
unit and verifies every allocated byte, all complete global function extents,
and **27 actual relocations**. All 684 bytes match, with no emitted data,
exception sections, weak functions or padding. Central integration must still
pass original table-ownership and full-DOL/regression checks before credit.
