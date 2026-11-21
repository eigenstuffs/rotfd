# Verified continuation on 2026-10-10

This continuation began at 969,820 / 2,607,776 matched code bytes,
3,148 / 8,803 matched functions, and 334,952 / 1,030,936 matched data bytes.
The original baseline was saved with `ninja baseline` before matching changes
and has not been replaced. Current accepted totals are generated in
`PROGRESS.md`; the complete original code, function and data denominators
remain unchanged.

New matching source includes the DPCM decoder, game allocation shims,
bounded leaf/scalar fragments, aligned allocation wrappers, fixed-size pool
resize/release, selected-index collection, grid records/growth, handle-list
operations, sparse callbacks, fixed-record copies, movie interpolation and
dispatch, and bit/Huffman-symbol readers. Each source handoff is compiled
as NonMatching before promotion. Strict isolated checks apply actual ELF
relocations and audit allocated section ownership and complete function
extents. The native report and full-DOL hash determine accepted progress.
Original startup references travel with their reconstructed initializers.

Private near-matches remain uncredited: the world loader, bit search, audio
acquisition with unresolved conversion-pool ownership, movie DMA/YUV workers,
plane unpacker, allocator pool-growth probes, and unresolved SDK Light/Tev
routines. Their scratch artifacts and findings are retained. Original native
ABI and adjusting branch thunks also remain fallback code.

The changes formatter now ignores an empty-data percentage difference only
when both old and new native measures have zero data bytes. Native objdiff
assigns 100% to empty data sets; removing a text-only fallback split otherwise
reported a false 100%-to-0% data regression. Actual nonempty data and code
regressions remain visible, the raw native report is unchanged, and three
meaningful formatter tests cover these cases.

Acceptance runs the original SHA-1 check, `ninja changes`,
`python3 tools/audit_source_extents.py`, `python3 tools/progress.py --check`,
and all 26 unit tests. The protected snapshot in
`scratch/continuation_20261010/checkpoint.json` records the original/reference
executables, expected hash, 641 preexisting linked source files and 56 headers.
Their SHA-256 values are unchanged. `latest-proof.json` in the same directory
records a verified checkpoint; build logs and strict relocation inventories
remain available alongside the individual source notes. Unrelated local changes and original inputs are preserved.

The request remains active. A passing reconstruction and these new source
fragments do not constitute 100% decompilation; the remaining original code
and data require further verified C/C++ reconstruction.

At the latest checkpoint, matching source covers 1,830,144 / 2,607,776 code
bytes (70.180261%), 7,734 / 8,803 functions, and 511,842 / 1,030,936 data
bytes. That is 860,324 additional code bytes, 4,586 functions, and 176,890 data
bytes since this continuation began. These figures describe this checkpoint;
`PROGRESS.md` remains the generated current report.

An agent reused the earlier late-scalar research directory and overwrote
several scripts and its note. Accepted production sources and the canonical
manifest remained intact. The final manifest, strict verifier, split/config
handoff and ownership findings were restored or reconstructed and reverified.
The original generator text and intermediate candidate lists could not be
recovered; their replacement and this loss are documented in
`docs/notes/game-scalar-late.md`. New record-setup work uses a separate directory.
