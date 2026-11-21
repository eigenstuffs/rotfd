# Additional native Python argument-format strings

Seven ordinary C++ data units reconstruct 78 existing GLOBAL char arrays used
by accepted Python bindings. Each array has its exact declared size, meaningful
ASCII argument format and final NUL. These are bounded partial data splits;
all compound strings/factory-name pools and neighboring formats stay external.

| Family | Owned `.rodata` interval | GLOBAL strings | Allocated bytes | String/NUL bytes | Natural alignment bytes |
| --- | --- | ---: | ---: | ---: | ---: |
| Game player formats | `802A2E28..802A2FA2` | 13 | 378 | 358 | 20 |
| Game manipulator formats | `802A3088..802A31A4` | 8 | 284 | 269 | 15 |
| ABC_Agent | `802A49F0..802A4A35` | 3 | 69 | 64 | 5 |
| Agent_Z registration/query formats | `802A4AA0..802A4D3E` | 18 | 670 | 638 | 32 |
| Throwable_Z | `802A52F0..802A543B` | 9 | 331 | 318 | 13 |
| CameraAgent_Z accessors | `802A5878..802A5950` | 7 | 216 | 209 | 7 |
| ParticlesAgent_Z / VolumeAgent_Z | `802A5980..802A5BF2` | 20 | 626 | 599 | 27 |

The first probes and fresh replays reproduce all 2,574 allocated bytes:
2,455 string/NUL bytes and 119 natural internal alignment bytes. There are no
padding variables, alignment pragmas, aliases, byte blobs, helpers, emitted
relocations, metadata or code. The compiler section alignment is eight and
independent objects naturally align to four. The 53 original synthetic internal
`gap_06_*_rodata` GLOBAL labels are unreferenced and must disappear from both
complete native ELFs, including any zero-size aliases; their bytes remain.

Native names/addresses/sizes/bytes and absence of aliases were checked before
source creation, along with all source definitions and current split ownership.
The complete canonical supplement checks 1,768
files and 14,929 physical ranges,
including 733 legacy map records. None
overlap the proposed intervals. The stable census checks
10,428 original/current inputs and
204,101 allocated relocations. All 312
consumer records are named zero-addend HA/LO pairs: 156 original and 156 active.
There are no initialized pointers into the strings, no cross-extent addends,
and no named/physical relocations, undefined declarations or bytewise DOL
pointers into the internal alignment bytes. All words in the 3,144 exception
index, 24 constructor and eight destructor records were checked.

The precise boundary topology has nine excluded original gaps, totaling
19 bytes. Preceding gaps are `802A2E25..802A2E28` (3),
`802A3085..802A3088` (3), `802A4A9F..802A4AA0` (1), and
`802A5876..802A5878` (2). Following gaps are `802A2FA2..802A2FA4` (2),
`802A4A35..802A4A38` (3), `802A4D3E..802A4D40` (2),
`802A543B..802A543C` (1), and `802A5BF2..802A5BF4` (2).
All are original-only assembly bytes, excluded from credit; unique explicit
align1 ownership avoids DTK omitting boundary padding. The first three-byte gap
is already identified in the older Game format handoff and must not receive a
second owner. The full input and bytewise pointer/table audit finds zero
references to these nine excluded gaps. Exact previous/following GLOBAL
identities appear in `boundary_topology.json`, rather than assuming round-eight
alignment or claiming the following compound pool.

Seven actual private MWLD links reproduce all 78 GLOBAL identities and all
allocated bytes, with exact production-basename owner and placement rows and
no synthetic gap labels. Seven positive fixtures, twenty adverse raw object
cases and twenty-one adverse native map cases pass. The strict ELF core remains
unchanged. No source credit is accepted by this handoff alone.

Root integration must repeat dual complete ELF/map placement and sole owners,
retain the exact original boundary bytes and neighbors, remove all 53 synthetic
internal gap identities, and repeat postintegration consumers. The original
DOL hash, unchanged denominator, baseline/regressions and every prior gate
remain mandatory. This proposal credits zero code bytes and zero functions.
This producer note is permanently frozen; acceptance belongs in a separate note.
