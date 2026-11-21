# Scene setup and enum controls

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Four original functions in three ordinary C++ source units match isolated
production recompiles. Parent integration must repeat full original-DOL checks.

| Entry | Original text | Original metadata/data | Actual relocations |
| --- | ---: | ---: | ---: |
| `fn_80031CB0` + `fn_80031D0C` | 92 + 92 | 56 jump table data | 18 |
| `fn_80033040` | 216 | 8 EH + 12 index | 9 |
| `fn_80039454` | 180 | 8 EH + 12 index | 7 |

Total: 580 text bytes, 56 original jump-table data bytes, 40 exception metadata
bytes and 34 actual relocations. The established GC 1.3.2 -O4,s -inline auto
-Cpp_exceptions on -use_lmw_stmw on flags reproduce every allocation, symbol,
raw byte and actual target. There are no weak helpers, pools, added padding,
renames, migrations or verifier adapters.

The two enum conversions preserve out-of-range values and remap the original
seven cases. Original case order 0,3,6,1,2,4,5 reproduces both compiler jump tables
and branch layouts. Their text is contiguous 80031CB0..80031D68. Both complete
28-byte tables are contiguous at 802B1960..802B1998. Keeping the adjacent pair
in one source unit preserves the original 8-aligned section start and internal
4-aligned second table at 802B197C. No preceding record ownership or synthetic
padding is needed. All actual original references to either table come from
these two functions; no compiled source names either original local table.
jump_table_ownership_audit.json pins original symbols, compiler local names,
consumers and hashes. A genuine isolated MWLD link places both text and data at
their original addresses and proves all 240 resolved bytes exactly; its actual
ELF data section has alignment eight and size 56. Parent full link must retain
this entire original contiguous ownership in one source unit.

33040 toggles the first scene target's signed byte +2EC, preserves the resulting
byte in a local, invokes service virtual slots +34 and +38 through derived vptr
+1C, queries the original selection 0x29, and dispatches event E0 or CF with the
existing float constant. Computing the local before assigning the stored byte
closes the initial seven/eight register and reload differences. Direct memory
readback and assignment-expression variants remain private and uncredited.

39454 preserves its original C entry and calls the existing native callback
base initializer. It installs the two original vtable pointers, stores one at
+86, clears bit 2 of 64-bit flags +38, sets bits 29 and 43, clears byte +88 and
word +DC, then clears twenty four-byte words at +8C. Its private view ends at
E0, agreeing with the original initial factory allocation. The first ordinary
probe was exact. Original accepted factory and startup callers keep their names
and files; consumer hashes are recorded in ownership_audit.json.

Every original function extent was individually checked, including both 92-byte
functions inside the combined enum unit. Full extabindex80015F60..8001F2C0,
ctors80299920..80299980 and dtors80299980..802999A0 scans show precisely the two
owned exception records and no constructor/destructor table references.
All initialized-data references and enclosing original object identities are
inventoried. External callback/vtable/string/constant ownership stays unchanged;
these are partial original translation-unit recoveries.

The fresh namespace is scratch/game_engine_scene_setup_more_continuation.
final_integration.json pins sections, source hashes, symbols and all actual
relocations. Split/config fragments are proposals only. allocated_inventory.json
covers every emitted raw allocation. verify.py recompiles all three production
units. native_enum.py records original-placement leaf/table link evidence.
No central file, shared header, old accepted source or frozen gate was changed.
