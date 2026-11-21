# Engine 32-byte record-array readback

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Frozen isolated handoff: `fn_801C316C`, 460 retained text bytes, zero data bytes, twenty actual relocations, range 0x801C316C..0x801C3338. Its existing external name is preserved. GC/1.3.2 uses the ordinary hardware Gekko optimization flags with exceptions off and no extra compiler flags.

The routine reads a signed record count through `fn_801F2CB4`, resizes the count/capacity/pointer array at owner +0x40 without retaining excess capacity, then reads each 32-byte element through that same stream routine. Empty ordinary element constructors and destructors reproduce the original counter loops; no assembly or relocation masking is used. Private declarations specify the observed array header and element extent.

`final_integration.json` under `scratch/game_engine_record_stream_more_continuation` freezes source SHA256, an empty recursive quoted-header inventory, all symbol extents, allocated sections and actual relocations. Proposed central split/config edits and `ownership_audit.json` are siblings. Strict production recompile through `verify.py` passes. No helper or weak functions, data, BSS, padding, exception records, constructor references, or destructor references are emitted or owned. Full original-table audits were performed. Original 0x801C3164..0x801C316C stays assembly: this is a partial text split. Parent final DOL and regression acceptance remain required.

Two other routines remain uncredited research with no published source: `fn_801C3B2C` snapshot append retains extra FPU spill/lifetime code under the tested ordinary record shapes, while `fn_801D3DD0` keyed resource detach has genuine handle-key register and scheduling differences. Their reservations are released. Probe sources and bounded variants are preserved in the scratch directory.
