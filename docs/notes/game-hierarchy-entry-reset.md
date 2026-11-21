# Hierarchy entry reset

`src/Game/hierarchy_entry_reset.cpp` and its private header recover all 668 bytes
of `fn_80207004`, at `0x80207004..0x802072A0`. The retained symbol is unchanged.
This is a bounded reconstructed source fragment; the original method name and
translation-unit boundary remain unknown.

The function consists of two native handle-array operations on the list at
object offset `0xD0`: `resize(0, 1)` followed by `resize(count, 0)`. The first
operation destroys existing elements in reverse order while preserving the
allocation. The second reconstructs the requested elements and adjusts storage
and capacity when the requested count differs from the cleared size. A zero
request leaves the empty allocation available for reuse. The caller
`fn_80206F90` resolves a group member and forwards the count to this function.

The resize algorithm agrees with the recovered five- and seven-layer
specializations. This instance uses four native initialization layers over
`Handle_801F7F10`. Ordinary placement construction emits the base constructor and
four zero stores; native destruction preserves the four observed null checks
before calling the base destructor. The original conditional branches, including
those visible after specializing the first resize to zero, are produced by the
same general source algorithm. The first probe already reproduced every
nonrelocated instruction; no special compiler pragmas or scheduling adjustments
were needed. Existing shared headers and integrated resize sources were not
modified.

The stable manifest is
`config/GSQE78/candidates/game_hierarchy_entry_reset.json`. Run
`python3 scratch/game_hierarchy_entry_reset/verify.py` for the strict isolated
proof: **668 text bytes, 25 actual retained ELF relocations, zero byte
differences**. The verifier checks source/header hashes, complete function and
allocated-section extents, the original DOL SHA-1
`5da8295a79bf297ab62c620e6ac66210be1c6ef5`, and all bytes after applying real
relocations. Three unreferenced weak base destructors total 264 bytes and six
relocations; they are accounted for and excluded through normal linker dead
stripping. No data, BSS, exception metadata, or padding is emitted or credited.

Full-DOL and native objdiff integration are verified below. Production
hashes and the strict result are recorded in the manifest and
`scratch/game_hierarchy_entry_reset/verification.txt`.

Central integration passes the original DOL SHA-1 and direct whole-file byte
comparison. Native objdiff records 668/668 code bytes and 1 matching function;
owned data is zero. The source-section extent guard and generated progress
checks pass. All linked source remains exact; the original baseline is preserved
with only the documented native-accessor and trailing-padding corrections.
