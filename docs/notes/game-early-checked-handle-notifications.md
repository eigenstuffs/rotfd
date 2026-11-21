# Checked Handle notifications: 8002F7C0 and 80052FEC

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Two ordinary C++ routines match all 2,164 original code bytes and their two 8-byte exception records plus 12-byte indices. Both first probes were exact. Independent production recompilation verifies every allocated byte and all 65 actual relocations. Neither object emits additional functions, tables, padding or exception records. Full original-placement linking and the DOL hash remain the integrator's acceptance requirements.

Each routine first calls the unchanged native `slot1C__13Root_80207414Fv` entry, returning zero when its signed-byte result is false. When its enabled byte is nonzero, it checks a fixed sequence of Handle fields with the existing `fn_801F7EB8`, resolves each valid Handle through the generation/index manager, and calls virtual slot +0x1C. It returns one after the notifications and zero when disabled. `8002F7C0` reads the enabled byte from the scene owner at global +0x124, scene +0x15058, owner +0x2F4; `80052FEC` reads its own byte at +0x2F4.

The first sequence uses offsets 0x6C, 0x70, 0x74, 0x78, 0x84, 0x80, 0x8C, 0x88 and 0x90. The second uses 0x60, 0x68, 0x2F8, 0x2FC, 0x300, 0x304, 0x308, 0x30C, 0x310 and 0x64. Explicit named fields preserve the original ordering; the inline notification/lookup helpers reproduce the original repeated bodies. The combined private owner view establishes storage through +0x313, and the scene view through +0x1505B. The notified object has an observed eight-byte nonvirtual prefix and vtable pointer at +0x08. These are minimum views, not asserted full original allocation sizes.

| Function | Code range | Extab range | Index range | Actual rels |
| --- | --- | --- | --- | ---: |
| `fn_8002F7C0` | 8002F7C0..8002FBD0 | 8000747C..80007484 | 80016BCC..80016BD8 | 32 |
| `fn_80052FEC` | 80052FEC..80053450 | 80009E24..80009E2C | 80017F64..80017F70 | 33 |

Both existing C entries and all native dependency names are preserved. Original globals/data and callable tables remain external. The complete exception-index and startup-table scans find exactly each owned index and no startup entries. Initialized-data pointer scans also record unchanged callable pointers at 802B1C90 inside the 148-byte `lbl_802B1C74` pool, and 802B4CE0 inside the 124-byte `lbl_802B4CC4` pool. Complete original pool extents and raw hashes are recorded. Existing source/header consumers are inventoried without edits. No native identity migration or verifier extension is needed.

Frozen evidence is under `scratch/game_early_checked_handle_notifications_continuation`. `verify.py NEW_DIRECTORY` recompiles both production sources and checks every byte and actual relocation. The two separate translation units preserve the disjoint original text extents. Flags are the established GC 1.3.2 space optimization flags with exceptions and lmw/stmw enabled.
