# Scene property setup: 8005074C

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Ordinary C++ reproduces all 380 original code bytes, the 8-byte exception record and 12-byte index of `fn_8005074C`. The first isolated body probe was exact. A fresh production compile matches every allocated byte and all 18 actual relocations, with no additional helpers, data, padding or exception records. Full integration and the original DOL hash remain the integrator's acceptance requirements.

The routine sets the owner's 64-bit flag mask 0x40000000 at +0x38, queries the established floating-point property API, narrows six results through integer conversion to bytes, stores two floats, and assigns two retained Handles at +0x80 and +0x84. The word at +0x64 receives an explicitly byte-narrowed property value. The observed query indices are 0, 1, 2, 5, 4, 7, 8 and 3. Handle assignment releases the destination, copies its word, and retains the source using the unchanged external manager.

The private owner view establishes a minimum extent of 0x88; it does not assert the full allocation size. All external identities and data ownership remain unchanged. Existing source/header consumers are inventoried without edits.

| Section | Original range | Bytes |
| --- | --- | ---: |
| `.text` | 8005074C..800508C8 | 380 |
| `extab` | 80009A78..80009A80 | 8 |
| `extabindex` | 80017D54..80017D60 | 12 |

The complete original exception-index and constructor/destructor tables were audited. Exactly one index record transfers, and no startup pointer transfers. The initialized-data pointer audit finds the owned index and an unchanged callable-table pointer at 802B418C inside the 144-byte original `lbl_802B414C` pool. The entire pool's original bytes and symbol extent are recorded; its ownership stays external and its pointer continues to resolve to the preserved C entry. No verifier extension or identifier migration is required.

Evidence is frozen in `scratch/game_early_scene_property_setup_continuation`. Run `verify.py NEW_DIRECTORY` for a fresh production compile and exact allocated-byte/actual-relocation replay. Flags are the established GC 1.3.2 space-optimization flags with exceptions and lmw/stmw enabled.
