# Platform cache destructor reconstruction

`src/Game/platform_cache_destructors_801EA278.cpp` reconstructs the two genuine
nonvirtual C++ destructors at `801EA278..801EA4D4` and `801EA4D4..801EA730`,
604 bytes each. Both original GLOBAL names and extents remain unchanged.
The source uses the existing accepted `Game/platform_cache_internal.h`
interface without changing any shared declaration.

The ten-entry and 900-entry caches share count/capacity/node data at offsets
zero/four/eight, stride at C, block descriptors at10 and vptr at14.
Nodes are12 bytes: native handle at zero, mapping index at four, unknown
halfword at six and two unsigned16-bit list neighbors at eight/ten.
Each destructor first unlinks/reinserts node one, then reorders every entry
and zeros its16-byte block descriptor. It frees the first descriptor's
original allocation, resets the base vptr, frees descriptor storage,
destroys each node's handle with the native negative deletion flag, frees
node storage and handles optional deletion of the cache itself.

The remaining32 loop-register differences were closed with an ordinary
`CacheNodeIndex` value object. It stores an unsigned int and exposes that
scalar through an inline `operator const unsigned int&() const`. A const
local `node = i + 1` is then passed to both list operations. Returning the
scalar by value retained23 differences; returning its const reference
preserves the native index, zero, node, neighbor and offset lifetimes.
No register qualifiers, barriers, assembly, aliases or synthesized code
are involved.

GC1.3.2, Gekko, O4,p, inline auto, exceptions off, RTTI off and lmw/stmw on
emit exactly two GLOBAL functions in one1208-byte `.text` section with34
actual relocations. Strict full-object comparison and a fresh compile of
the formatted production source match every allocated byte and relocation.
There are no extra helpers, weak definitions, EH/startup records,
initialized data, BSS or padding. Both original vtables, the base vtable,
heap and allocation service retain their external ownership.

`scratch/game_frontier_20261012_b/audit_platform_cache_destructors.py` and
`platform_cache_destructors_801EA278.owned.json` preserve the normal ELF
symbol/RELA/allocation manifests. The ownership audit scanned all3,109,410
aligned and unaligned original word positions, all original direct
branches and EH/startup records, plus6,899 active inputs/133,736 actual
relocations. No initialized pointers, interior external references or
absolute materializations address either entry. The existing accepted
`platform_shutdown.cpp` is the only active source caller and already uses
the correct destructor names and ABI; no caller edit is required.

Root owns native whole-DOL/hash/regression and split/configuration adoption.
Only these1208 text bytes are covered by this handoff; neighboring original
code/data remain outside this source. Earlier unsuccessful probes remain in
`scratch/game_platform_cache_lifetime/` and receive no credit.

Integrated on 2026-10-12. The normal native build and independent mapped
relink both reproduce the immutable original DOL hash. Complete raw ELF
allocations, symbols and actual relocations match; all original ownership,
caller, regression and coverage checks pass. Source extents and all 66 tests
pass. Root receipts are in `scratch/continuation_20261012_b/`, including
`readable-dtors-native-proof.json`. All neighboring original data remains
outside these partial text-only splits.
