# Paired array append, resize, and initialization

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The frozen handoff under `scratch/engine_array_pair_resize_20261010z/` contains
three complete ordinary C functions: 1,620 text bytes, no owned data, and
55 actual relocations. All use GC/1.3.2 with the standard game flags and no
extra compiler options.

| Source | Original text | Bytes | Behavior |
| --- | --- | ---: | --- |
| `engine_array_append_pair.c` | `8021C558..8021C740` | 488 | Append a 144-byte record, then append its address to a pointer array; both grow in blocks of 32. |
| `engine_array_resize_168.c` | `80227380..80227518` | 408 | Resize a 168-byte entry array, optionally retain capacity, and construct newly added entries. |
| `engine_array_triple_init.c` | `802358E8..80235BBC` | 724 | Initialize arrays of eight-byte, sixteen-byte, and two-byte records through their zero-size resize operations. |

The paired append copies the record's 128-byte aggregate and subsequent
fields independently. Its last short is unsigned, matching the original
zero-extending load. Both append layers retain their null checks around
construction. The triple initializer's default record values and trivial
destruction loops reproduce the original inlined array lifecycle operations;
general allocation helpers simplify to free-only paths at the constant zero
sizes used by this function.

`freeze.py` and a fresh `verify.py` run passed using production source.
Verification applies every relocation to its actual versioned address,
compares all bytes, and rejects extra functions, unexpected allocated
sections, or incorrect extents. `audit.py` confirmed the complete original
function ranges and checked all 3,141 extabindex entries, 24 constructor
entries, and eight destructor entries. None references these functions.
Only the listed text ranges are source-owned; all original allocator data,
external element construction, adjacent functions, and other ranges retain
their existing owners. These are partial text splits rather than claims to
recover complete original translation units.

Use `final_integration.json`, `final_splits.txt`, `final_config.txt`,
`scope_edits.txt`, and `ownership_audit.json` for integration. Register as
NonMatching, verify native comparison, then promote after the full original
DOL hash and regression checks pass. This handoff does not modify central
configuration, original inputs, expected hashes, or generated progress.

The default record constructor at `80227518` now uses its native C++ symbol `__ct__16BitDefaultRecordFv`. The shared declaration and resize caller were migrated together, and all three production consumers still reproduce their complete 1,620 allocated code bytes and actual relocations. The original DOL hash, baseline comparison, generated progress, and all 26 tests pass. Original source/header/manifests and their SHA inventory are preserved in `scratch/continuation_20261010/default-record-motion-caller-history/`.
