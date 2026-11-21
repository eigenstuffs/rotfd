# Early nested state controls

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Five ordinary C++ partial text units exactly match GC1.3.2 production
compilation with `-O4,s -Cpp_exceptions on`. They retain 1,644 text bytes and
100 exception table/index bytes. Central native acceptance is pending.

| Function | Text bytes | extab | extabindex | Actual retained relocations |
| --- | ---: | --- | --- | ---: |
| fn_80056668 | 392 | 80009F1C..80009F24 | 80017FDC..80017FE8 | 6 |
| fn_800732B8 | 340 | 8000C8B8..8000C8C0 | 800192FC..80019308 | 4 |
| fn_800E1CB0 | 236 | 8001474C..80014754 | 8001E6F0..8001E6FC | 4 |
| fn_800E1498 | 344 | 80014670..80014678 | 8001E66C..8001E678 | 5 |
| fn_800AF150 | 332 | 800110C0..800110C8 | 8001BE70..8001BE7C | 6 |

56668 conditionally binds a node and copied position to the current selection
record. It updates the record's enabled byte and sends the nested virtual
command when the group is controlled; the disabled branch clears the original
state and returns false. The observed group and record strides are 0x94 and
0x20. 732B8 clears state98, updates the resolved actor/resource flags and sends
the nested command. E1CB0 invokes a component callback, then resolves its two
handles and invokes each target callback. E1498 registers the owner with the
scene, clears resource/actor flags, forwards the owner through virtual slot13C
and marks its event state. AF150 clears the timer and actor flags, resolves the
resource and optional related child, then runs the child callback and updates
its event flags. Its child clear mask is 0x20000 and set mask is 0x40000.

The new `early_nested_state_control_views.h` supplies partial observed layouts
and declaration-only virtual interfaces, with all five production consumers
frozen in the batch inventory. Distinct entry views reproduce the original
manager-array reload for nested handle resolution. The original signed24-bit
index/signed8-bit generation checks remain ordinary C++ bitfields. All floating
constants, the zero vector and context globals retain their borrowed original
identities. No helper definitions, weak backups, new data, BSS, padding,
aliases or native entry migrations are emitted.

`scratch/game_engine_batch127/manifest-list.json` lists five independent
contiguous original section mappings. Each fresh production verifier checks
all allocated bytes, actual relocation targets, compiler local symbols and
extents, and the original DOL hash. The full 3,141-entry exception index plus
descriptor and all ctor/dtor entries establish complete original table
ownership. Frozen source/header/evidence hashes are in `frozen-sha256.json`.
Full native link/hash, regression checks and progress acceptance remain with
the central integrator. The preserved candidate inventory is diagnostic only.
