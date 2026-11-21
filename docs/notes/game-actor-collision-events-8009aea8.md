# Actor collision events — `8009AEA8`

The routine obtains an actor collision sphere, searches eight collision results,
and dispatches native events and response callbacks through generation-checked
handles. The fallback sphere-query flags and indexed result iteration distinguish
it from the neighboring collision dispatcher recovery.

GC/1.3.2 with `-O4,s -inline auto -fp_contract on` and C++ exceptions enabled
reproduces the complete 1,636-byte function, eight exception bytes and twelve
exception-index bytes. All 22 allocated relocations resolve to original addresses.
There is one separately checked compiler-category relocation, no unused weak
functions, and no additional data, BSS or startup allocations. The five undefined
dependency symbols have global bindings and unique native providers.

## Complete native constant ownership

The unit owns the entire 32-byte pool at `80378D58..80378D78`: five existing
global floats, four native interior alignment bytes, and the compiler's signed
conversion bias. Small inline getters returning constant references are defined
before the global scalar definitions; the exported routine follows. This source
order preserves the original global scalar loads while allowing the compiler to
emit the conversion bias last, with its natural alignment. No source padding
array, symbol alias or extra literal pool is introduced.

The prior `actor_vector_interpolation_scalar_constants.c` build unit and split
are retired. Its source is preserved, all 32 emitted bytes are equal in the new
owner, and every original global scalar consumer keeps the same symbol, address
and extent. Only the conversion bias changes to its native local identity
`@152`; exception records use local `@153` and `@154`.

## Acceptance

The normalized DOL SHA-1 remains `5da8295a79bf297ab62c620e6ac66210be1c6ef5`.
`ninja changes` reports no regressions, source extents pass for 5,768 linked
source units and 6,742 data/BSS sections, and all 66 tests pass. Generated totals
are 1,927,888 / 2,607,776 code bytes (73.9284%), 7,980 / 8,803 functions,
and 971,656 / 1,030,936 data bytes (94.2499%). This adds 1,636 code bytes and
20 exception-data bytes; existing scalar and alignment credit is preserved.

Complete immutable recovery evidence is under
`scratch/actor_collision_events_8009AEA8_20261020/`, particularly
`manifest-complete.json` and `FINDINGS-COMPLETE.md`. The earlier partial pool
proposal is superseded private research. Integration backups and final object/ELF
verification are under `scratch/actor_collision_integration_20261020/`.
