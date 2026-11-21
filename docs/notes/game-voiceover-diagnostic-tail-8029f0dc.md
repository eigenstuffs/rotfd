# Voice-over diagnostic tail at 8029F0DC

The existing `src/Game/native_readable_pools_8029EFF8.cpp` now owns 272
`.rodata` bytes at `8029EFF8..8029F108`, with its prior 228-byte array unchanged.
Three complete arrays add 39 string bytes and five bytes of natural compiler
alignment: `In SendEndMsg`, `File_Z.h`, and `VOICE_OVER_DATA`.

The original logging routine at `800AD54C` directly references the first
array. The parser at `800AD694` keeps the existing `8029EFC0` base and uses
offsets `0x12C` and `0x138` for the filename and parser token. Its instructions
and relocations remain unchanged. The 6,869-input census at capture found
12 relevant relocations and no raw data pointers into the added interval.

The former 44-byte `lbl_8029F0DC` lump is repartitioned into complete GLOBAL
arrays of 14, nine, and 16 bytes. No trailing original residual remains;
the accepted buffer initializers still begin at `8029F108`. The compiler
emits only the 272-byte data allocation, with no text, weak allocations,
relocations, or undefined symbols.

The frozen source evidence is in
`scratch/voiceover_diagnostic_strings_20261020_parallel/`; production backups
and complete object/native proofs are in
`scratch/voiceover44_integration_20261020/`. The bounded historical successor
preserves the old 228-byte owner, 4,216-byte provider, and 4,245-byte fragment
receipts while checking all three current owners and their complete 4,694
native bytes. Only 44 bytes receive new credit.

Acceptance: the standard DOL SHA-1 passes, `ninja changes` reports no
regressions, the source-extent audit passes, and all 66 tooling tests pass.
Generated progress is 1,937,408 code bytes, 7,989 functions, and 976,276 data
bytes. This data continuation does not complete the original voice-over unit.
