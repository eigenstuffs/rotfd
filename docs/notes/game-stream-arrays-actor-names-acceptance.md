# Stream arrays, actor names and renderer acceptance

The `stream-arrays-actor-names` checkpoint is fully accepted. Three ordinary
C++ functions add 11,352 matching text bytes, and the actor-state char arrays add
1,299 initialized bytes (1,196 strings and NULs plus 103 bytes of natural
four-byte alignment). The original DOL SHA1 remains
`5da8295a79bf297ab62c620e6ac66210be1c6ef5`. Full `ninja`, `ninja changes`, source
extent and generated-progress checks pass; all 43 unit tests pass. No baseline
was replaced.

| Production source | Retained code | Initialized data |
| --- | ---: | ---: |
| `src/Game/multi_array_stream_read_801cdcb0.cpp` | 3,464 | 0 |
| `src/Game/typed_array_stream_read_801dab34.cpp` | 4,036 | 0 |
| `src/Game/actor_state_type_names_8029D7F0.cpp` | 0 | 1,299 |
| `src/Game/render_pipeline_flags_8027353c.cpp` | 3,852 | 0 |

The renderer is a partial text-only split. Its original owner contains 7,492
bytes; the other 3,640 bytes and their 180 actual relocations remain original
fallback code and receive no source credit. All four original-owner partitions
preserve the complete 28,940-byte physical union and 744 original allocated
relocations. Two original-only actor alignment boundaries total eight bytes,
use exact alignment one and receive no source credit.

The source objects contain 571 actual allocated relocation records: 564 retained
and seven in four unused weak backups totaling 316 bytes. Every unused
allocation is proved discarded in both native ELF views. All 75 owned native
identities, 587 union references, 69 initialized pointers and 180 distinct
borrowed providers are checked. The original WEAK delete provider remains WEAK,
size 76, with its original bytes. No alias or positive-size physical overlap is
accepted as another provider.

Two source-specific audit corrections are preserved with their counterexamples.
The unused 84-byte multi-array destructor has a projected fixture address equal
to an existing 588-byte original callee. A retained call reaches the original
callee; it does not give the discarded backup a native placement. The bounded
LM guard proves the exact source/object/relocation and the sole original callee
in both linked ELFs. An independent real-ELF mutation also showed that ignoring
natural-gap identities without checking multiplicity could accept a duplicate
GLOBAL gap label. The unconditional supplement now requires exactly 52 original
gap identities before and after, 52 active identities before and zero after,
with exact types, sizes, bindings and owners and no allocated gap references.
Its inventory hash must equal the main successor-scope inventory hash.

The complete original-plus-active input union is now 10,538 inputs and 204,858
actual allocated relocations. Every historical gate remains mandatory; exact
private split/configuration afterimages and untouched inputs are rechecked.
Both new supplements and the actual outer acceptance route passed independent
SDK/World review. Earlier rejected preparations and adverse fixtures are
preserved.

Generated progress is 1,847,528 / 2,607,776 code bytes (70.8468825543%),
7,742 / 8,803 functions, 514,255 matching data bytes, and 526,951 complete data
bytes out of the unchanged 1,030,936-byte denominator. Completed units are
4,745 / 5,793. These figures come from the generated report, not a probe score.

The complete acceptance receipt is
`scratch/continuation_20261010/stream-arrays-actor-names-complete-proof-snapshot.json`.
The immutable route seal is
`scratch/continuation_20261010/stream-arrays-actor-names-root-route-seal-v1.json`,
SHA256 `5dc6834665d54b97c79fc3b1b9a2a4b107d6238c4f6c4efbfca685fdafa06b99`,
with 97,587 pinned files. Root independently rehashed every pin and the built
DOL afterward; the receipt is
`scratch/continuation_20261010/stream-arrays-actor-names-post-seal-verification-v1.json`.
