# Platform record selection

`src/Game/platform_record_selection.cpp` owns **256 matching code bytes**:

| Entry | Original range | Bytes |
| --- | --- | ---: |
| Repeated record removal | `80283D5C..80283DE4` | 136 |
| Greatest-age selection | `80283DE4..80283E5C` | 120 |

Selection scans the 24-byte records, admitting records with status zero at
`+4`. It subtracts the record timestamp at `+14` from the owner's clock at
`+10`. An age that does not compare less than or equal to the current
threshold replaces both the selected index and threshold. The negated
comparison preserves the original unordered floating-point behavior; replacing
it with a greater-than comparison changes the code and NaN behavior. The
one-word result uses the native hidden structure-result pointer. Its default
constructor stores index -1, indicating no selection.

Removal uses the owner's threshold at `+14` and stops when its signed 16-bit
remaining count is nonpositive or selection fails. It subtracts the signed
16-bit sum of record counts at `+C/+12`, preserving the sum's narrowing,
and delegates removal to `8026EB34` with mode 2. That larger operation and
other array operations remain original. The shared tables retain original
ownership outside this partial text split.

The shared array declaration now identifies these observed record fields and
owner threshold without changing storage extent, alignment or trivial record
lifetime. The two earlier array-lifetime units remain exact after recompilation.
All earlier source files are unchanged. A normal pointer-returning inline
array accessor reproduces the selection register allocation. GC/1.3.2 uses
`-O4,p -inline deferred,noauto`, avoiding automatic inlining of the separate
selection entry into removal while preserving the explicit accessor and result
constructors. No source assembly, data, BSS, metadata, padding or weak helpers
are emitted or credited. Names describe observed behavior provisionally.

The strict production proof accounts for all 256 allocated bytes and both
actual branch relocations. Linked symbols occupy their original addresses and
match every instruction byte. The full DOL remains byte-identical, all 675
source units retain their matches, and all 23 tooling tests, generated progress
checks, source extents and source assembly audits pass. The saved original
baseline remains unchanged. Evidence is in
`scratch/platform_record_selection_checkpoint.json`, the strict verifier under
`scratch/game_platform_record_selection/`, and the shared-header/link proofs.
