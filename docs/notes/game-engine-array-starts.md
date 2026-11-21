# Engine paired-array reader and child start loops

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Frozen isolated handoff: two original routines, 1,348 retained text bytes, zero data bytes and 45 actual relocations. Existing external names are preserved. GC/1.3.2 uses the ordinary hardware Gekko optimization flags, exceptions off, and no extra compiler flags. Production sources recompile and pass strict original-byte, symbol extent, allocated-section and actual-relocation checks. Parent integration and full DOL/regression acceptance remain required.

`fn_801D020C` (780 bytes, 40 relocations, 0x801D020C..0x801D0518) calls the base stream reader, reads a signed count, resizes the arrays at owner +0x24 and +0x30 without retaining excess capacity, and reads count*2 and count*28 packed bytes into their respective storage. Empty ordinary element constructors and destructors retain the original counter loops.

`fn_801C7FD0` (568 bytes, five relocations, 0x801C7FD0..0x801C8208) first calls the base start operation. On success it starts children from handle arrays at owner +0x20 and +0x2C, then valid children from 28-byte records at +0x38 and the final handle at +0x44. Handle resolution uses the observed signed 8-bit generation and signed 24-bit index and a 16-byte manager entry. The first two arrays are resolved without a separate validity call, as in the original. Reusing one ordinary local loop index across all three loops reproduces the original register moves; independent loop declarations produce two real word differences and are not credited.

`final_integration.json` under `scratch/game_engine_array_starts_continuation` freezes source SHA256, empty recursive quoted-header inventories, exact function extents, all allocated bytes and actual relocations. Proposed central splits and configuration are siblings. No helper or weak functions, data, BSS, padding, exception records or constructor/destructor references are emitted or owned. Full original-table audits cover extabindex 0x80015F60..0x8001F2C0, ctors 0x80299920..0x80299980 and dtors 0x80299980..0x802999A0. The original C7FD0 unit is fully covered; original 0x801CFE40..0x801D020C and 0x801D0518..0x801D05D8 remain assembly, so the reader is a partial text split.
