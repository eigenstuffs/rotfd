# Engine transformed query result builder

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_801BCB78`, range `0x801BCB78..0x801BCD74`, is recovered in ordinary
C++ as a partial text-only split. The isolated compiler object matches all
508 retained bytes and all four actual relocations. No helper functions,
data, BSS, exception records or constructor references are emitted or owned.
The existing external symbol is preserved; accepted record transfer and
output routines already call it.

The input record supplies an object at `+0x30`, a point at `+0`, two float
coordinates at `+0x20`, a 64-bit flag word at `+0x28`, and three opaque
pointers. The output stores those fields and two transformed points. Its
`+0x10..+0x1C` vector is not written by this routine and remains untouched.
The private declarations describe only offsets established by the original
loads and stores.

When the object's `+0x120` flags contain `0x20`, the routine selects a matrix
from the global cache at `lbl_801E9D24+0x134`, using its active byte at `+0x18`
and the object's signed short index at `+0x12E`. Matrices occupy 64 bytes.
It stores the selected pointer at object `+0x128`, calls `fn_801F230C` with
the object's `+0x124` source matrix, and clears the dirty flag. It transforms
the input point and that point plus the caller's offset, adds the translation
column, stores `lbl_8037A2D8` at result `+0x50`, and returns the result pointer.

CodeWarrior GC/1.3.2 uses the standard game flags with `-fp_contract on`.
Fused operations are present in the original. A matrix method returning a
local vector with individually assigned components reproduces the original
floating-point allocation and instruction scheduling exactly; returning a
vector constructor expression gives the same extent but different registers.

The original assembly fragment continues through `0x801BE46C` and contains
other functions. Those functions retain original ownership. The audit checks
the retained function's complete extent, the fragment's zero data size, every
original exception index entry and constructor pointer, and every compiler
allocation. `source_sha256` and the recursive quoted-header inventory (empty)
are frozen in the final manifest.

Verification and proposed integration are under
`scratch/game_engine_transform_build_continuation/`: `verify.py`,
`final_integration.json`, `ownership_audit.json`, `final_splits.txt`, and
`final_config.txt`. Strict production recompilation and relocation verification
passed. Central integration and the full DOL hash remain the integrator's job.

## Uncredited append investigation

`fn_801B5664` (400 bytes) hashes two names into a 16-byte record, stores a
caller value and zero halfword, walks a compiler-emitted empty loop, grows an
array at owner `+0x28` by 16 slots when necessary, and copies the record into
the next slot. The raw capacity growth and copy behavior match ordinary C++.
The closest source, `probe_801B5664_loop_in_outer_0.cpp`, has the exact
400-byte extent and differs in two instructions only: the original uses
`cmpw r5,r4; bge`, while the compiler folds the zero loop start into
`cmpwi r4,0; ble`. Both represent the same signed comparison. Constructor,
index wrapper, comparator, iterator, inline helper, empty hook and optimizer
variants did not remove this difference. No production source or credit is
claimed for it; all probes remain research artifacts.
