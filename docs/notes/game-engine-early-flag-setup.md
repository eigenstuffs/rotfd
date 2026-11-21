# Early flag setup fragments

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Eighteen existing C entry points recover 2,244 text bytes and 360 EH/index bytes. The functions call one original base/setup entry and then write ordinary tables, scalar fields, vectors, or flags. No existing function name, accepted caller, table, global, or shared file changes.

The repeated 80035B2C..8003AEE8 family inlines the defaults of the now-native Agent_80035294 constructor: root table 802B29D0, short 0x86=1, low flag bit 4 cleared, low flag 0x20000000 and high flag 0x800 set. Each then sets its derived table; 80036C1C and 80038150 also clear words 0x88/8C/90 and the latter sets one further table. The private field at 0x38 is unsigned long long, preserving the original low/high two-word mask sequence and its identity high-word AND. The generator recognizes observed constant field/flag semantics and writes ordinary C++ statements, without emitting assembly or instruction bytes.

8002823C/8002A8C4 call existing reset fn_8002AE88 and set high flag 4; their original void-return behavior is preserved. 8006565C/80065C60 call the native Agent_80062E18 constructor, install primary/secondary tables (secondary at 0x94 is primary+0xB4), and set high flag 0x100. 8006590C uses the same base/table pattern and sets low flag 0x10000000. 80072CD0 calls native Agent_8002B5F4, initializes shorts 0x90/92=-1, word 0x94 and byte 0x98 zero, vector 0x9C from the existing mutable game_vec3_zero, and float 0xA8 from original SDA data; it clears low flag 8 and sets high flag 1.

The compiler is GC 1.3.2 with established container-base flags, including -O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on. Strict production recompilation verifies every allocated byte, function/object symbol, and actual relocation. Each routine owns only its original text plus compiler-emitted extab8/index12. The full original exception index and constructor/destructor registration tables are audited, with no registration entries moved. All referenced data retains original ownership. Root integration/full original DOL hash are required before progress credit; these are bounded fragments rather than recovered original translation-unit boundaries.
