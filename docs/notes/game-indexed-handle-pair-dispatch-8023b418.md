# Indexed handle-pair dispatch, 8023B418

`src/Game/indexed_handle_pair_dispatch_8023B418.cpp` replaces the complete
240-byte function at 8023B418..8023B508 with ordinary C++. Its ten retained
actual relocations and every linked instruction match the native executable.
The original function identity is retained, so its five existing callers
require no changes.

For a nonnegative index, the routine obtains a handle using the device,
index and event key, constructs a retained copy, and calls the device's
virtual slot 54 with the incoming flags and handle pair. The second copied
handle is a full-expression temporary. Its lifetime determines the native
SP+8 stack slot and reverse cleanup order. This closes the older six-offset
near match without changing behavior or introducing assembly.

The object retains two compiler-generated weak destructor backups (88 and
84 bytes), four unlinked relocations and all three `.mwcats.text` records.
Both unique weak functions are absent from the final native ELF. No EH,
startup data, literal pool, BSS or neighboring code belongs to this split.
Existing providers retain all dependencies.

Evidence and integration snapshots are in
`scratch/handle_dispatch_8023B418_20261020/`; the canonical acceptance
manifest is `config/GSQE78/candidates/game_indexed_handle_pair_dispatch_8023B418.json`.

The original DOL hash, empty regression check, extent audit (5,770 units /
6,739 data/BSS sections), and all 66 tests pass. Matched code is now
1,922,508 / 2,607,776 bytes (73.7221%), with 7,976 / 8,803 functions.
Matched data remains 971,539 / 1,030,936 (94.2385%).
