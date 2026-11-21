# Paired owner-slot teardown: 8002C130

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Ordinary C++ reproduces all 492 original text bytes, the 8-byte exception table, and the 12-byte index of `fn_8002C130`. The first isolated probe matches all instructions; the production source adds a comment only and strictly matches all 20 actual relocations. It emits no additional code, data, helpers, padding, or exception records. Full native integration and the original DOL hash remain the integrator's acceptance requirements.

The routine handles the two external owner slots `lbl_803775C8` and `lbl_803775CC`. An all-bits-set pointer sentinel clears one slot and, when the other owner is eligible, resets the resolved actor's word at +0x3C4 and byte at +0x390. It then processes each remaining eligible owner through `fn_8005EE10` and `fn_80069654` before clearing the slot. Eligibility observes the owner's 64-bit flags at +0x38 with mask 0x2000000. The private Handle view preserves the signed eight-bit generation and signed 24-bit index used by the original manager lookup.

The owner view establishes storage through +0x73; the actor view establishes storage through +0x3C7. These are minimum observed extents, not asserted allocation sizes. All globals and original data remain external, and the C entry identity is unchanged. Existing source/header callers are inventoried without edits.

| Section | Original range | Bytes |
| --- | --- | ---: |
| `.text` | 8002C130..8002C31C | 492 |
| `extab` | 80006AF4..80006AFC | 8 |
| `extabindex` | 80016A64..80016A70 | 12 |

The complete original exception-index table and both startup tables were audited. Exactly one owned index record points to this function, and no constructor or destructor startup entry transfers. The initialized-data pointer scan finds only the original owned exception-index pointer. No identifier migration or verifier extension is needed.

Frozen evidence is under `scratch/game_early_owner_slot_teardown_continuation`. Run `verify.py NEW_DIRECTORY` for a fresh production compile and exact allocated-byte/actual-relocation replay. The production flags are the established GC 1.3.2 space optimization flags with exceptions and lmw/stmw enabled.
