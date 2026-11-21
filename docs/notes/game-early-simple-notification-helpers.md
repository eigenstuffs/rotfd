# Early notification and setup helpers

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Ten separate original C entry points are recovered in `early_simple_notification_helpers_*.cpp`. Each owns exactly 96 text bytes, its compiler-emitted 8-byte exception record and 12-byte exception index. These are partial translation units; all neighboring functions and all original data remain outside the sources.

| Entry | Text end | extab | extabindex | Behavior |
| --- | --- | --- | --- | --- |
| 8007D8F4 | 8007D954 | 8000D590 | 80019800 | Store argument at 28, call virtual slot 14, reset active/sentinel fields, then call 7DCDC |
| 80083B18 | 80083B78 | 8000DB68 | 80019DF4 | Controller command 20/76, then notify an active monitor |
| 80083E50 | 80083EB0 | 8000DBA8 | 80019E54 | Controller command 21/76, then notify an active monitor |
| 80083F90 | 80083FF0 | 8000DBC8 | 80019E84 | Controller command 22/76, then notify an active monitor |
| 800844CC | 8008452C | 8000DC18 | 80019EE4 | Controller command 3D/9E, then notify an active monitor |
| 80087CA4 | 80087D04 | 8000DF80 | 8001A1A8 | Controller command 74/7C, then notify an active monitor |
| 80088758 | 800887B8 | 8000E080 | 8001A298 | Controller command 7C/7D, then notify an active monitor |
| 800A5C98 | 800A5CF8 | 8001077C | 8001BAA4 | Copy into empty output; otherwise append original separator and input |
| 800AB29C | 800AB2FC | 80010CB0 | 8001BC84 | Clear resource byte 70, test byte 71 and query 7256C, conditionally report |
| 800B1610 | 800B1670 | 80011324 | 8001BF3C | Copy into empty output; otherwise append its original separator and input |

The six notification bodies establish owner pointers at 8/C, actor token at 320, and monitor active pointer at 130. The virtual setup body establishes a vptr at 0, bytes 4/5, signed sentinel words 8/10, and argument word 28, giving a minimum observed extent of 2C. Its first function-pointer-table probe differed in two dispatch GPR operands. An ordinary C++ virtual declaration with CodeWarrior's two header entries emits the exact slot-14 load and complete original body. No vtable or additional helper is emitted.

The flag/report body establishes owner.serviceC, service.resource94, and signed resource bytes 70/71. `fn_8007256C` has a signed-byte return, and the report declaration is variadic, preserving the original CR setup. It borrows the existing `lbl_801E9D24` absolute anchor for field 110 and original 19-byte `lbl_8029EF38` string. Neither acquires new ownership. The append helpers borrow the original two-byte SDA separators `lbl_80378F70` and `lbl_803791C8`; their contents and original owners remain unchanged.

GC 1.3.2 flags are the established container-base settings: `-proc gekko -fp hardware -enum int -str reuse -common off -O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on`. All ten production recompiles pass strict equality across 960 text bytes, 200 metadata bytes and 53 actual relocations. Every emitted allocated byte and sized symbol is accounted for. There are no extra allocations, unused weak functions, new data, aliases or identifier migrations. This is isolated verification; parent integration must still pass the original full DOL hash and regression checks.

`ownership_audit.json` scans the complete original extabindex at 80015F60..8001F2C0 and startup tables at 80299920..802999A0. Only the ten expected index records transfer; no constructors or destructors reference these extents. `original_pointer_audit.json` scans every aligned word in all eleven original initialized data sections, finding 46 pointers into the ten extents. Thirty target 7D8F4, including its original vtable consumers. All data/table owners remain external except the ten retained exception indices. The audit freezes full containing-symbol hashes and all current source/header caller references; the original C entry identities stay unchanged.

The complete frozen handoff is `scratch/game_early_simple_notification_helpers_continuation/handoff_sha256.json`; integration ranges, symbols, flags, raw allocation inventories, compiler evidence and a fresh recompile verifier are in the same directory. Central configuration, original inputs, progress and all previous handoffs were left unchanged.
