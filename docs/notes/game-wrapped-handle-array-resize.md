# Wrapped Handle array resize

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_801AD6A0..801AD8D4` is an ordinary 564-byte array resize reconstruction. The element is28 bytes: a two-byte key base, a two-layer four-byte Handle at offset4, and20 bytes outside the observed lifetime operations. Growth uses native base Handle construction, two explicit zero layers and assignment from a full-expression zero Handle temporary. Shrink destroys rows backward and retains capacity when requested.

The production GC1.3.2 Gekko/O4,p object matches all564 retained text bytes and26 real relocations. Two fresh unchanged-core strict recompiles account for all736 emitted allocated bytes and30 relocations. The two unique unused weak destructors (88 and84 bytes; four relocations combined) require final native absence and receive no code credit. There are no owned literal/data/BSS/EH/startup allocations.

Current original C identity and complete canonical text-overlap preflight pass. A stable5,586-object snapshot accounts for119,086 actual relocations and777,360 initialized words, verifies all config/input hashes unchanged during the scan, and finds one original GLOBAL definition with no alias, initialized data pointer or external entry relocation. The sole original direct caller is801AD68C in the same original unit. Full original extabindex/ctors/dtors ownership scans have no references. No shared declaration or identifier migration is required.

Evidence: `scratch/game_wrapped_handle_array_resize_801ad6a0`; frozen handoff: `scratch/game_engine_batch243`. Central/native acceptance remains pending.
