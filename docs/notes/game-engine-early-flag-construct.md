# Early native flag and member constructors

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Five native constructors recover 648 bytes of text and 180 bytes of compiler-generated original EH/index records. All existing constructor/dependency identities and source caller names remain unchanged. The compiler is GC 1.3.2 with established container-base flags, including -O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on.

Four routines call existing setup entries and assign ordinary table/scalar/64-bit flag fields. Agent_8002CF70 (92 bytes) clears bit 0x400 in the low flags word. Agent_80035294 (128) sets short 0x86 to one, clears low bit 4, sets low 0x20000000 and high 0x800. Agent_8003CD88 (116) clears words 0x170/174/178, low flag bit 0x100000, and byte 0x70. Agent_800737D8 (124) clears the word/byte/short/word fields at 0x80/84/86/88, clears low flag bit 4, and sets high 0x4000. Flags use an ordinary unsigned-long-long field at 0x38; this reproduces the original two-word mask operations, including the high-word AND with -1, rather than optimizing them away as isolated 32-bit fields.

Agent_80061AC0 (188 bytes) has a 0x60-byte ContainerBase_802563CC primary base and 0x160-byte Object_8005E258 secondary base. Its ordinary Handle members at 0x1EC, 0x1F0, and 0x1F4 have three, one, and two inline zeroing layers. Their destructor identities in the original unwind records establish the distinct native Handle types. A member initializer expression assigns primary/secondary tables and clears words 0x1CC/1D0/1D4 before the first Handle constructor. The body clears 0x1F8 and publishes the typed secondary-base pointer to the existing global at 803776B8; the ordinary implicit base conversion reproduces the original null-preserving pointer adjustment and branch. External native destructors and declared-only intermediate layers emit no extra helper allocations.

Private layouts record accessed offsets and proven base extents only. No original table, global, or caller is rewritten. Each production object is strictly verified for every emitted allocated byte, symbol and actual relocation. The full original extabindex/ctors/dtors tables are audited, with no registration ownership moved. These fragments remain subject to root full-link hash acceptance before progress credit.
