# Checked actor events: 8004F498

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The first ordinary C++ probe strictly reproduces all 840 original code bytes, the 8-byte exception record, the 12-byte index and all fourteen actual relocations. A separate production replay verifies every allocated byte. No extra helper, weak backup, data, padding or exception allocation is emitted. Final native placement and the original DOL hash remain the integrator's acceptance requirements.

Event 0x8A checks bit 0x02000000 in the resolved target's 64-bit flags at +0x38. When set, a nested checked actor lookup writes byte +0x435 to one and calls owner virtual slot +0x84, followed by slot +0x7C. If 0x8A does not match, event 0x8B first calls slot +0x7C, then uses the same flag and actor lookup to clear byte +0x435 and call slot +0x84. All calls retain the original entry identities.

The actor lookup follows global +0x13C to a service's Handle pointer at +0x1C, resolves that node's child Handle pointer at +0xB0, then conditionally resolves its Handle at +0x70 through the existing validity API. The ordinary inline helper preserves the original repeated manager loads and conditional zero results. Private views reuse established Handle/index/generation and node-prefix layouts; this routine establishes target flags through +0x3F, actor storage through +0x435, and owner storage through +0x2B. These are observed views, not complete factory allocation claims.

| Section | Original range | Bytes |
| --- | --- | ---: |
| `.text` | 8004F498..8004F7E0 | 840 |
| `extab` | 800098B4..800098BC | 8 |
| `extabindex` | 80017CB8..80017CC4 | 12 |

The full original exception-index and startup tables were audited. Only the owned index transfers; no constructor or destructor entry points into the body. A complete initialized-data pointer scan also finds an original pointer at 802B4330 in the unchanged 144-byte `lbl_802B42A8` pool. Its complete raw hash and original ownership are preserved in the pointer audit. Existing source/header consumers are inventoried without edits. No native identity change, shared declaration edit, additional data ownership or verifier gate is needed.

Frozen evidence is under `scratch/game_early_checked_actor_events_continuation`. `verify.py NEW_DIRECTORY` recompiles production with established GC 1.3.2 space optimization, exceptions and lmw/stmw, checking all allocated original bytes and actual relocations.
