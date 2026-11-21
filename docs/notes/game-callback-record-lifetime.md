# Callback record lifetime

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

`src/Game/callback_record_lifetime.cpp` reconstructs two adjacent complete
functions and 244 text bytes at `80253388..8025347C`.

The 160-byte deleting destructor restores the original table at `+08`, frees
non-null backing storage at `+0C`, and resets length at `+10` only in that
storage branch. The inlined resource destructor restores its original base
table and invokes the native root destructor. Positive signed-short deletion
flags free the receiver through the original allocation context. Both native
receiver null checks are retained by ordinary inline C++ helpers.

The 84-byte constructor invokes the original root constructor, installs the
resource and derived tables through an inline base initializer, and clears
storage/length. The source models only the observed 20-byte prefix; original
tables and allocation storage remain externally owned.

`scratch/game_callback_construction/package_lifetime.py` recompiles final
source and verifies all 244 allocated bytes, both global function extents and
16 actual relocations. No data, BSS, weak helpers, exception records or padding
are emitted. Central original-table ownership, production object and full-DOL
acceptance checks remain required.

Other constructor probes in this directory remain private and uncredited.
The placement-new variants introduce native-unobserved null branches; direct
initialization methods retain register allocation differences. The original
destructor probe reset length outside the storage branch and had three
instruction differences; the corrected conditional cleanup matches exactly.
