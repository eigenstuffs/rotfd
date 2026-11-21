# Collision event dispatch — `8021DA20`

The recovered routine queries a collision sphere, constructs eight result
records, resolves generation-checked handles, and dispatches collision events
through native virtual methods. It handles event responses and child recipients
using the observed result type and movement flag. The nested vector expression
and the lifetimes of the constant recipient pointer and reused hit-object pointer
reproduce native register allocation.

GC/1.3.2 with `-O4,s -inline auto -fp_contract on` reproduces all 1,528 text
bytes at `8021DA20..8021E018` and its eight-byte signed conversion pool at
`8037B048..8037B050`. All 20 allocated relocations match their original
addresses. One non-allocated compiler-category relocation is checked separately.
There are no additional weak functions, EH, BSS or startup allocations.

The eight-byte pool was transferred from the end of
`scalar_constant_8037B040.c`, preserving its other 112 bytes and all 16 global
symbols. Its only original consumer was this function. The pool now has its
compiler-generated local identity `@145`; data credit is unchanged. The
remaining original text at `8021E018..8021E454` stays outside this partial split.

## Linkage and acceptance

The first full link detected that this old compiler gives external C declarations
inside an anonymous namespace local undefined bindings. Moving only those
declarations outside that namespace preserves all code, data and symbol extents
and makes the eight dependency references global. The private handoff remains
unchanged. Production verification explicitly rejects local undefined symbols
and checks final ELF placement and binding for both providers.

The normalized DOL SHA-1 is still `5da8295a79bf297ab62c620e6ac66210be1c6ef5`.
`ninja changes` reports no regressions, source extents pass for 5,768 linked
source units and 6,740 data/BSS sections, and all 66 tests pass. Generated totals
are 1,926,252 / 2,607,776 code bytes (73.8657%), 7,979 / 8,803 functions,
and 971,636 / 1,030,936 data bytes.

Private recovery and complete incoming-reference audits are under
`scratch/collision_event_dispatch_8021DA20_20261020/`. Production backups,
linkage repair and verification are under
`scratch/collision_dispatch_integration_20261020/`.
