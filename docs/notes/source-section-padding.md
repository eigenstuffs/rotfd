# Trailing source-section padding audit

The compiler section extent, not the next original symbol's address, determines
where a reconstructed source section ends. A successful full-DOL link can hide
an oversized source split because the linker recreates the same zero alignment
bytes. Native objdiff can then credit those original bytes as source data.

The audit compared all 555 linked source units and 1,308 allocated section
pairs. It found 111 trailing data/BSS ranges in 82 units, totaling 366 bytes
beyond the compiler-emitted section extents. Every initialized tail consists
of zero bytes in the protected original DOL; every NOBITS tail lies in its
zero-initialized BSS allocation. No central object overlaps these ranges.
The full machine-readable range inventory is
[`source_padding.json`](../../config/GSQE78/source_padding.json).

Each corrected source split ends at its emitted extent and preserves the
original source-section alignment. Its tail has a separate NonMatching unit
under `padding/source_extents/`, with an explicit byte-aligned object. Existing
generated gap names are retained where available. These are original fallback
bytes, so they receive no matched or linked source-data credit. No C/C++ source,
emitted instructions, data objects, original DOL bytes, or expected hash changed.

The correction reduces matched data from 300,899 to 300,533 bytes. Code remains
879,980 bytes and 2,855 functions; 555 units remain linked from source. Original
denominators remain 2,607,204 code bytes, 1,030,936 data bytes and 8,801 functions.
The 82 additional padding partitions increase the provisional build-unit
denominator from 3,935 to 4,017; these are not recovered original source files.

Moduleobject owns 387 bytes in `.data` through `0x802D4403` and 20 bytes of `.sdata`,
for 407 data bytes. Its one-byte tail at `0x802D4403` is the only additional
regression against the immutable four-unit initial baseline, which recorded
408 data bytes. Tupleobject's two-byte `.sdata` tail at `0x8037647E` is also
excluded, but its initial baseline credited no data. The separately documented
[GetR2 correction](runtime-init-cpp-exceptions.md) remains unchanged.

MetroTRK's four `.text` alignment bytes at `0x8011DC4C` were examined separately.
The target ELF has a generated function-kind gap, but the native report already
excludes it from the unit's 13 functions and 3,936 code bytes. No code accounting
change or new reconstructed function was introduced for that gap.

After the boundary changes, the standard configure/build, original SHA-1 check,
direct whole-DOL comparison, native objdiff report, generated progress check and
saved-baseline comparison pass. Every linked unit retains complete code and
owned-data matches. The source extent guard additionally checks these boundaries
before progress exports are accepted; larger compiler sections containing
dead-stripped weak helpers are not mistaken for a trailing-source deficit.
