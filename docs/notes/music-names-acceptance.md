# Music-name data production acceptance

The `music-names` checkpoint accepts the original GLOBAL object
`lbl_8029ACA8`, a 260-byte array containing thirteen music filenames.
Ordinary C++ initializers reproduce every owned byte, symbol extent, and
alignment. This contributes 260 initialized data bytes and no code or functions.

The full build preserves original DOL SHA-1
`5da8295a79bf297ab62c620e6ac66210be1c6ef5`, with no baseline regressions and all
43 repository tests passing. All 174 native weak override cases and every
preceding acceptance gate pass. Both actual native ELFs retain the original
GLOBAL object's unique identity and all 260 bytes. The complete consumer census
and original exception, constructor, and destructor tables remain verified.

Generated progress is 1,829,524 / 2,607,776 matching code bytes
(70.156485833%), 7,732 / 8,803 functions, and 500,847 matching data bytes.
The complete proof and generated progress snapshots are pinned by
`scratch/continuation_20261010/music-names-root-route-seal-v1.json`
(SHA-256 `3058734f9f65a4a2185073eca080f4b82a7485684209651b9a0f663f2afa599d`,
1,456 pins). The frozen producer note remains untouched; this note records
completed full-game acceptance. Original functions and data outside the declared
split remain with their existing owners. `PROGRESS.md` is the current generated
report.
