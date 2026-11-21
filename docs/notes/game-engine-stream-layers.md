# Engine stream layers

Four ordinary C++ stream entries are exact in isolated GC 1.3.2 production objects.

| Entry | Original extent | Text | Real relocations |
| --- | --- | ---: | ---: |
| `fn_80243D38` | `80243D38..80243D84` | 76 | 2 |
| `fn_80243DE4` | `80243DE4..80243E44` | 96 | 3 |
| `fn_80243E44` | `80243E44..80243E90` | 76 | 2 |
| `fn_80244190` | `80244190..802441E4` | 84 | 2 |

The core layer calls the original Root stream entry, then reads 0x64 bytes beginning at object+0x0C. The scalar layer reads four bytes at +0x0C and sixteen at +0x10. Two derived layers call the external core entry and read sixteen or twenty-four bytes beginning at +0x74. The cursor advances to the value returned by `fn_801E9F40` after each read. Names and object fields remain provisional partial views.

The twenty-four-byte layer keeps the original address subtraction by subtracting the unsigned target addresses of +0x88 and +0x74, then adding four. Plain subtraction of decayed array pointers folds to a constant and produces76 bytes; the ordinary integer-address expression and explicit casts of member-array addresses both reproduce84 exact bytes.

Each source is separate so the base stream function remains an external call. The unchanged Game flags are `-O4,p -inline auto -Cpp_exceptions off`. All four allocated sections contain only the retained function, totaling332 bytes and nine actual REL24 relocations. There are no weak helpers, owned data, literal pools, BSS, exception tables, startup entries or padding. Complete original extabindex `80015F60..8001F2C0`, constructors `80299920..80299980`, and destructors `80299980..802999A0` scans have no ownership in these ranges. Original global C identities and all external owners remain unchanged.

`current_source_reference_inventory.json` records all current source/header references. Some older callers retain incomplete one-argument or return-value declarations of `fn_80243DE4`; this tranche preserves those accepted files and their historical approximations. The recovered stream definitions take the observed object and cursor arguments. No caller migration or caller credit is proposed.

Frozen evidence is in `scratch/engine_record_stream_layers_20261011fo/`: original disassembly, source variants, full allocation and symbol inventories, actual relocation targets, full original table audit, and `final_integration.json`. `python3 scratch/engine_record_stream_layers_20261011fo/verify.py` recompiles the four production sources, verifies every allocated byte and actual relocation, and checks frozen hashes. This is an isolated readiness proof; root performs production integration, the original DOL hash check and regression acceptance.
