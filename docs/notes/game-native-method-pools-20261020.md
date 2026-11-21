# Native method pools from active automatic splits

Nine initialized-data pools now have C++ source owners. Their original
ownership was confirmed in both the active native objdiff report and generated
DTK configuration; stale generated assembly was not used to infer missing
ownership. Every table also has an existing source/header consumer.

| Source under `src/Game/` | Owned `.data` range | Bytes | Pointer relocations |
| --- | --- | ---: | ---: |
| `menu_object_native_method_tables_802EB240.cpp` | `802EB240..802EBF00` | 3,264 | 765 |
| `platform_native_method_tables_802ED178.cpp` | `802ED178..802ED6F8` | 1,408 | 260 |
| `spatial_resource_method_tables_802EA180.cpp` | `802EA180..802EA4F8` | 888 | 199 |
| `agent_container_method_tables_802EC6A0.cpp` | `802EC6A0..802EC9D0` | 816 | 188 |
| `draw_manipulator_method_tables_802EB000.cpp` | `802EB000..802EB180` | 384 | 81 |
| `resource_method_tables_802EA558.cpp` | `802EA558..802EA6C0` | 360 | 82 |
| `record_container_method_tables_802ECF88.cpp` | `802ECF88..802ED0B0` | 296 | 66 |
| `spatial_binding_method_tables_802EC0A0.cpp` | `802EC0A0..802EC3D8` | 824 | 179 |
| `animation_draw_method_tables_802E9EA0.cpp` | `802E9EA0..802EA0C0` | 544 | 115 |

The 81 complete global tables retain their original symbol extents and all
1,935 relocation identities, kinds and addends. Numeric sentinel and null
entries preserve the original native records. No function-interior pointers,
instruction arrays or reconstructed code are included. These remain data-only
splits rather than complete original translation units.

GC/1.3.2 with the existing Gekko/O4,p, automatic inline, exceptions/RTTI off,
and load/store-multiple settings emits the exact allocated `.data` sections.
All section boundaries align to eight bytes. The candidates need no headers;
unused private include search paths were removed from production flags, and
production objects were independently reverified.

Two four-byte prefixes, `802EC09C..802EC0A0` and `802E9E9C..802E9EA0`, retain
explicit original ownership. DTK initially omitted them when only the adjacent
source ranges were declared, reducing the native report's data denominator by
eight despite an exact DOL. Explicit NonMatching splits restore those bytes
to the report. No original bytes or unknown units are excluded from progress.

All acceptance checks pass: the original DOL SHA-1, no baseline regressions,
the extent audit (5,793 sources and 6,766 data/BSS sections), and all 66 tooling
tests. Added matched data is 8,784 bytes, bringing the total to 963,965 /
1,030,936 (93.5039%). Matched code remains 1,920,872 / 2,607,776 bytes.

The manifests, active-input census, source usage evidence, exact relocation
checks, and integration snapshots are preserved in
`scratch/data_inventory_20261020_parallel/`. Its inventory snapshots identify
remaining work but are not current progress exports.

## Thirteen smaller pools

A further 1,016 bytes in thirteen source units reconstruct 21 complete method
tables and one 24-byte geometry index table. Their 194 pointer relocations,
all 22 symbol extents, and all production section bytes match.

| Original start | Owned bytes |
| --- | ---: |
| `802E9D98` | 64 |
| `802E9DE8` | 32 |
| `802E9E20` | 80 |
| `802EA128` | 40 |
| `802EA7D8` | 56 |
| `802EA908` | 168 |
| `802EAED0` | 64 |
| `802EAFA0` | 32 |
| `802EBFD8` | 72 |
| `802ED0C0` | 168 |
| `802EDCA8` | 40 |
| `802F14E8` | 88 |
| `802F1550` | 112 |

The zero-valued table at `802EAFA0` is supported by the accepted HashKey
constructors, which assign it as the PointerKey/IntegerKey base table. It is
not an inferred padding object. The array `lbl_802ED130[6][4]` has unsigned-byte
elements: native `fn_80267748` scales the face selector by four, reads four
bytes, and uses each as a twelve-byte vertex index. Both are represented by
typed source definitions.

Explicit NonMatching ranges retain the neighboring 12-byte base table at
`802E9E14..802E9E20`, the 160-byte jump tables at `802EBF38..802EBFD8`, and
four original bytes at `802F14E4..802F14E8`. No original data is removed from
the progress denominator. The manifest, symbol/consumer evidence and backups
are in `scratch/small_method_data_scout_20261020_parallel/`.

Acceptance passes the original DOL SHA-1, empty baseline regression report,
extent audit (5,806 sources / 6,779 data/BSS sections), and all 66 tests. The
generated data result is 964,981 / 1,030,936 bytes (93.6024%). Code is unchanged.

## Remaining small runtime tables and callback arrays

The next four complete globals add 168 source data bytes: method tables at
`802BD468..802BD488` and `802BD920..802BD930`, and five-record callback arrays
at `802C8F40..802C8F7C` and `802C11CC..802C1208`. The last array extends
`teleport_volume_events.cpp` after its original compiler switch table.
All ten new pointer relocations and retained code/exception records match.
Neighboring base lists, switch tables and descriptors retain explicit original
ownership. The two callback arrays use the existing `force_active` mechanism
because their consumers address them through borrowed pool bases; the initial
link without retention discarded them and failed the original hash.

The corrected standard build passes the original DOL hash, `ninja changes` is
empty, the extent audit passes 5,800 source units / 6,773 data sections, and
all 66 tooling tests pass. The full data denominator remains 1,030,936 bytes.
Private evidence: `scratch/adjustor_reference_scout_20261020_parallel/`.

## Callback descriptor continuation

Two further batches reconstruct 29 complete callback globals (1,476 data bytes):
744 bytes across eleven new units, and 732 bytes appended to seventeen existing
callback units. Every word is supported by original registration or dispatch
loads. Five explicit original residual ranges retain neighboring switch tables
and unresolved arrays. Borrowed-base descriptors use explicit linker retention.
No new pointer relocations are needed for these virtual member descriptors.
All retained code, metadata, symbols and actual relocations compare exactly.

The standard DOL hash and no-regression checks pass. Extents cover 5,812 source
units / 6,786 data sections; all 66 tests pass. Matched data is now
967,429 / 1,030,936 bytes (93.8399%). Manifests and production object checks are
in `scratch/data_remaining_scout_20261020_parallel/`.

Five additional callback arrays add 276 data bytes to existing sources that
already emit weak helpers. Every retained compiler-emitted byte, symbol and
relocation is unchanged from the saved accepted objects; new data matches
exactly. The final native ELF verifies every owned section and new global at
its original address. Weak helper bodies receive no new credit. The standard
hash, empty regression check, extent audit and all 66 tests pass. Matched data
is 967,705 / 1,030,936 bytes (93.8666%). The retained append manifest and
production receipt are in the same private evidence directory.
