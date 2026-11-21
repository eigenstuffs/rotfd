# Nested pair-pool destructor at 801EB89C

`src/Game/nested_pair_pool_destructor_801EB89C.cpp` reconstructs the complete
468-byte entry at `801EB89C..801EBA70`. This is a genuine CodeWarrior-generated
C++ destructor, `__dt__14NestedPairPoolFv`. Each 24-byte element contains a
12-byte word pool as its base and another 12-byte word pool as its member.
The compiler naturally destroys the member before the base, preserves the
empty element-destruction loops, frees the three arrays, tests the signed-short
deleting flag and returns the original object pointer.

GC1.3.2, Gekko, O4,p, inline auto, exceptions off, RTTI off and lmw/stmw on
emit exactly one GLOBAL function and one allocated `.text` section of 468
bytes. All bytes and 12 actual relocations resolve exactly to the protected
original DOL. There are no additional functions, weak definitions, EH records,
initialized data, BSS, startup entries or padding. A fresh compile of the
formatted production source passed the same strict check.

The genuine destructor is essential. A manually exported C wrapper around
an inline clear method had 18 register differences. Explicit loop-offset
lifetimes reduced that to one zero-copy instruction, but only the real
compiler-generated destructor produces the native loop registers and two
independent zero loads with ordinary indexed iteration.

`audit_nested_pair_pool_destructor.py` and the frozen `.owned.json` under
`scratch/game_frontier_20261012_b/` record the complete object and ownership
proof. The audit scanned all 3,109,410 aligned and unaligned original word
positions, all original direct branches, EH/startup metadata and every actual
relocation in 6,899 active input objects (133,736 relocations). No initialized
pointers, EH/startup entries or genuine absolute/interior materializations
reference the entry. One external direct call occurs at `8026F0E8`.
Two naive LIS/low scan coincidences were excluded after proving that their
r4 base register is overwritten by the `_stack_end` LIS before the low word.

The existing positive GLOBAL entry needs a canonical name change from generic
`fn_801EB89C` to genuine `__dt__14NestedPairPoolFv`, preserving its address and
468-byte extent. No alias or second definition is proposed. The only active
source consumer is `src/Game/member_cleanup_98.cpp`: its existing foreign ABI
declaration at line 5 and call at line 19 must use the genuine destructor name.
A private rename-only copy compiles to the same exact 120 bytes and seven
actual relocation targets; no shared consumer has been edited by this agent.
No header consumer exists. Original assembly consumers will follow the
canonical symbol spelling when regenerated.

The root integrator owns the canonical symbol change, consumer edit, splits,
configuration and final original-DOL/hash/regression checks. This source owns
only the 468-byte destructor; all neighboring code and both allocators remain
external. Root is also investigating a larger contiguous local-storage closure
in this region. This proof gives no credit to that unfinished closure.

Integrated on 2026-10-12. The normal native build and independent mapped
relink both reproduce the immutable original DOL hash. Complete raw ELF
allocations, symbols and actual relocations match; all original ownership,
caller, regression and coverage checks pass. Source extents and all 66 tests
pass. Root receipts are in `scratch/continuation_20261012_b/`, including
`readable-dtors-native-proof.json`. All neighboring original data remains
outside these partial text-only splits.
