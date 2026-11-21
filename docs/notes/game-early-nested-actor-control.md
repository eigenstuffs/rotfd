# Nested actor control: 8005AD94

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The first ordinary C++ probe matches all 860 original instructions. Production compilation and a separate replay strictly reproduce all 860 code bytes, the 8-byte exception record and 12-byte index, including all eight actual relocations. The object emits no additional functions, tables, padding or exception records. Full original placement and the DOL hash remain the integrator's acceptance requirements.

The routine follows the related service at global +0x13C, resolves its Handle pointer at +0x1C, resolves that node's child Handle pointer at +0xB0, and conditionally resolves the resulting node's Handle at +0x70 through the unchanged validity API. It checks the actor's nested Handle at +0x1AC. When valid, it repeats the same lookup, resolves the nested target, and obtains a Handle pointer through virtual slot +0x9C with selector zero. It resolves that Handle and the returned node's Handle at +0x20, then calls virtual slot +0x40 with argument minus one. A second slot +0x9C lookup identifies the node whose word at +0x120 receives flag0x10000, followed by the unchanged `fn_80057E40(self)` call.

Inline typed Handle lookup and checked-actor helpers preserve the original repeated manager-entry loads and conditional zero results. The node view establishes storage through +0x1AF and an observed eight-byte prefix with the vtable pointer at +0x08; the related-service view establishes storage through +0x1F. These are minimum observed views, not asserted complete original allocation sizes. All C/native identities and data ownership remain unchanged; no constructor, destructor, temporary or weak backup is introduced.

| Section | Original range | Bytes |
| --- | --- | ---: |
| `.text` | 8005AD94..8005B0F0 | 860 |
| `extab` | 8000AAFC..8000AB04 | 8 |
| `extabindex` | 800180F0..800180FC | 12 |

The complete original exception-index and startup tables were audited. Exactly the owned index points to the body, no startup entry transfers, and the full initialized-data pointer scan finds no additional callable-table pointer. Existing source/header consumers are inventoried without edits. The unchanged strict verifier schema suffices; no new gate, identifier migration or extra data ownership is needed.

Frozen evidence is under `scratch/game_early_nested_actor_control_continuation`. `verify.py NEW_DIRECTORY` recompiles the production source and checks every allocated byte and actual relocation. Flags are established GC 1.3.2 space optimization with exceptions and lmw/stmw enabled.
