# Object-list pools and group removal

Seven partial source units reconstruct **1,556 code bytes / twelve functions**.
Names describe verified layouts and operations; the original class names and
translation-unit boundary remain unproven.

| Source | Native range | Functions | Code bytes |
| --- | --- | ---: | ---: |
| `object_list_records.cpp` | `80285C74..80285CDC` | 2 | 104 |
| `object_list_node_release.cpp` | `80285CDC..80285D34` | 1 | 88 |
| `object_list_node_acquire_trivial.cpp` | `80285D34..80285DB4` | 1 | 128 |
| `object_list_pool_init.cpp` | `80285DB4..80285E10` | 1 | 92 |
| `object_list_group_clear_80285E10.cpp` | `80285E10..80285ED8` | 1 | 200 |
| `object_list_group_remove.cpp` | `80285ED8..80286158` | 2 | 640 |
| `object_list_group_helpers.cpp` | `80286158..80286288` | 4 | 304 |

The pool contains 2,048 twenty-byte nodes at offset `44`, with a free-list
head at `40`. Each node holds a four-byte native handle, key at `4`, next
pointer at `8`, and two floats at `C` and `10`. A second head at `A044`
precedes 1,024 forty-four-byte records at `A048`, whose next pointer is at
`1C`. The observed pool extent is `15048` bytes. Its prefix remains unknown;
these declarations do not claim the complete original class hierarchy.

Initialization links 2,047 node successors and 1,023 record successors.
The record loop is naturally unrolled three times by GC/1.3.2. The routine
does not explicitly null either final successor. Record release invokes
`fn_8025F7FC` before pushing the record; acquisition pops and nulls its next
pointer without an empty-list check. The external reset routine and its
storage remain original.

Node release pushes the node and assigns a null native handle, then cleans
up the temporary with the existing `Handle_801F7F10` destructor ABI. The new
header shares the existing handle declaration and uses an explicit four-byte
temporary storage view to reproduce its bitfield initialization and cleanup.
It leaves earlier source and headers unchanged. The compiler also emits an
unused 84-byte temporary cleanup helper; it is excluded from source progress
and must be absent from the final ELF.

Group list pairs are at `18/1C` and `20/24`, with the record pair at `10/14`.
`fn_80285ED8` removes all entries with the requested key and, when supplied,
a matching object resolved from the handle. `fn_80286058` removes the first
matching key across the two node lists. Both preserve head/tail updates and
release nodes through the pool pointer at global-manager offset `124`.
The helpers clear the first node list, acquire a node, clear the record list,
and acquire a record. The removal loops keep separate traversal lifetimes to
reproduce native register allocation; no inline assembly is used.

Strict proof applies all **27 retained relocations** to actual GSQE78
addresses, checks every retained allocated byte and all emitted section and
symbol extents, and accounts separately for the unused cleanup helper.
That original five-unit proof remains preserved. The later
[node acquisition](game-object-list-acquire-trivial.md) adds 128 exact bytes and
four actual relocations with no weak backup. The combined node-list clear adds
200 bytes and four actual relocations, saving each successor before release and
clearing both head/tail pairs. Its ordinary head-value wrapper preserves the
native register lifetimes; both existing callers remain unchanged. These seven
units now cover all 1,556 code bytes in `80285C74..80286288`. They own no data or
alignment padding. Pool storage, float constants and external reset operations
retain their separate ownership.

Acceptance evidence is in `scratch/game_object_list_pool/verify.py`,
`scratch/object_list_pool_link_proof.json`, and
`scratch/object_list_pool_checkpoint.json`. Acceptance requires the original
DOL hash and direct byte comparison, current native objdiff progress, all
previous source matches, source extent and assembly audits, immutable original
baseline, and all 23 tooling tests. The unit names are provisional; nearby
particle filename references do not establish that these pools are particles.


The 2026-10-15 completion receipt is
`scratch/continuation_20261012_b/property-list-acceptance.json`, with complete
native ownership proof in `object-list-clear-native-proof.json` beside it.
Both native outputs pass the original DOL hash, all previous match checks,
full section coverage, source extents and all 66 current tooling tests.
