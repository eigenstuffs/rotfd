# Additional callback dispatch actions

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Frozen isolated production matches for six original C entries:8002BE80 (688),80042340 (652),80044D98 (664),80045F34 (664),8004CBC0 (716),800623FC (676). All six match their first ordinary C++ probes. Existing names stay unchanged. Together they own4,060 text bytes,120 exception/index bytes and168 compiler jump-table bytes with172 actual relocations, without weak functions or extra allocated output.

The common events0–6, original scratch globals, event11/index-minus-one return, signed index-adjusted action, callback controls and final update follow the accepted ordinary dispatcher family. These six differ in supported actions.2BE80 queries controls51/52 through short-circuit OR for action9, returns one for14 and invokes virtual slotB0 for15.42340 queries control51 for action9, returns one for14 and invokes slotB0 for15.623FC has the same OR and14 behavior, but action15 passes self+60 to existing5EED4. The unsigned-byte conversion of the OR result is explicit and reproduces the original truncation.

44D98/45F34 have no action14 case: they invoke the original setter for events7/8, then action15 calls slot90(0,0) and clears callback bit2; unsupported actions retain result2.4CBC0 likewise has no action14 case. Its action15 reads floating controls0/1, converts through signed int and unsigned char, stores the first into word60 and the second into byte64, invokes slots78(0,0) and7C(0,0), then clears callback bit2. Ordinary float-to-int casts emit the original FCTIWZ/stack conversion sequence. These are observed scalar offsets and call signatures, not a complete class-layout claim.

Private callback fields establish ushort flags28 and signed short index2A; MemberPointer is the observed twelve-byte aggregate. Object views establish only two opaque prefix words, vptr8, the observed virtual slots and bounded fields. External Pool views preserve opaque mixed prefixes and five actual member-pointer entries at the native offsets. No methods or vtables are emitted. All original member-pointer pools, strings, class/function tables, surrounding data and adjacent functions remain assembly-owned.

Each original seven-word compiler jump table transfers with its function. data_audit.json freezes original bytes, local compiler symbol, each actual bounded target, absent compiled consumers of provisional table identifiers and original/compiler alignments. Some tables are4-aligned despite compiler ELF .data alignment8; proposed split alignment4 preserves original placement. Borrowed pool span hashes, original object inventories and exact action/setter behavior remain recorded separately.

GC1.3.2 uses established -O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on flags. Strict production compilation and independent verify.py recompilation pass every emitted allocation, every allocated symbol extent, every original byte and all actual resolved relocations. allocated_inventory.json records object/section raw hashes and complete allocated symbols. Sources expand private declarations and have no quoted-header dependencies. Dependencies include actual ELF undefined symbols only.

ownership_audit.json scans full original exception-index80015F60..8001F2C0, ctors80299920..80299980 and dtors80299980..802999A0. Each complete function owns exactly its8-byte extab and12-byte index, with no startup pointers. Initialized-data words into every full extent and current compiled callers are frozen; original callable tables keep their ownership and entries. No accepted source or header was changed.

Exact ranges, flags, symbols, source hashes and resolved relocations are in final_integration.json and split/config companions. handoff.json freezes all evidence. Central original-DOL hash, baseline regression, progress and repository acceptance checks remain root integration work.
