# Checked actor and named resource setup: 800E079C

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The ordinary C++ production object strictly reproduces all 848 code bytes, the 44-byte exception record, the 12-byte index and seventeen retained actual relocations. Independent recompilation repeats the complete byte/relocation proof. The compiler additionally emits two uncredited weak destructors: the accepted typed Handle backup is112 bytes and the private return-Handle backup is76 bytes, with72 bytes of backup metadata and eleven backup relocations. Every emitted allocation is inventoried; none of those backup bytes earns new source credit.

The routine resolves a checked actor through global +0x13C, the service Handle pointer at +0x1C, a child Handle pointer at +0xB0 and the actor Handle at +0x70. It stores the actor pointer at owner+0x18. A genuine retained Handle_8002B67C copy of the service Handle then supplies a separately checked child lookup; the copy's base constructor, retain and destructor lifetimes reproduce the original exception actions. The child node's Handle+0x64 and resulting node's Handle+0x1F0 resolve a resource. A Name built from the unchanged five-byte SDA string at8037975C identifies a returned Handle from fn_8024BDA0; its resolved pointer is stored at owner+0x10. Finally actor virtual slot+0x9C(selector0) returns a Handle pointer whose resolution is stored at owner+0x14.

The named original Handle reference preserves the source pointer before construction. Ordinary inline checked lookup and typed generation accessors preserve repeated manager loads. Declaring the string's established five-byte extent emits the original SDA relocation; the first unspecified-array declaration emitted one extra address instruction. Private views establish owner storage through+0x1B, node storage through+0x1F3, service storage through+0x1F and the previously established eight-byte prefix/vtable at+0x08. They do not assert complete factory allocation sizes.

| Section | Original range | Bytes |
| --- | --- | ---: |
| `.text` | 800E079C..800E0AEC | 848 |
| `extab` | 80014470..8001449C | 44 |
| `extabindex` | 8001E5C4..8001E5D0 | 12 |

The unchanged standard weak/EH verifier schema applies. The accepted dictionary canonical for strong __dt__15Handle_8002B67CFv supplies original GLOBAL FUNC identity, all owned original bytes, actual relocations and recursive header hashes; a fresh compile matches the production object exactly. An actual MWLD fixture selects that production strong definition and discards all six backup code/EH/index allocations. The wrong fixture basename rejects. The fixture uses the legitimate original .sdata2 input containing8037975C; an earlier missing-input failure is preserved separately. Full original placement and DOL acceptance remain integrator requirements.

The full original exception-index/startup tables and initialized-data pointer words were audited. Only the owned index transfers; no startup entry targets this body. The external28-byte lbl_802C8260 pool contains a pointer at802C826C to the preserved C entry; the complete pool hash and original ownership remain unchanged. Original strings, service data and all unrelated functions remain external to this partial split. Source/header consumers are inventoried unchanged; no identity migration, shared declaration edit or new gate is needed.

Frozen evidence is under scratch/game_early_actor_resource_setup_continuation. verify.py NEW_DIRECTORY recompiles every retained original byte/actual relocation and independently checks the strong owner. native.py NEW_DIRECTORY repeats real native backup discard. Established GC1.3.2 space optimization, exceptions and lmw/stmw are used; final original DOL hash, no regressions and standard acceptance checks remain required.
