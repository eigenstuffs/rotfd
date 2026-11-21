# Voice-over buffer initializers at 8029F108

Two `const char[2048]` empty-string initializers reconstruct the complete
4,096-byte range 8029F108..802A0108. Their capacities follow directly from the
native parser at 800AD990: two separate loops copy 256 pairs of four-byte words
into its text accumulator and token-reading buffers. The parser reaches them
through offsets 0x148 and 0x948 from the shared pool base at 8029EFC0.

These are complete initialization objects. The source adds no padding-only
arrays, code, relocations, weak functions or exception metadata. Ordinary
`#pragma force_active` retains both globals through native linker dead stripping
because their original accesses use offsets from a neighboring shared base.
The two declared symbols are `lbl_8029F108` and `lbl_8029F908`.

The preceding 44-byte diagnostic at 8029F0DC keeps its original provider and
identity. Its former oversized 0x102C symbol extent is narrowed to 0x2C. All
other shared base symbols and source consumers are preserved. The actual-input
census finds no direct relocation into either initializer; an independent scan
of every aligned and unaligned four-byte window in every initialized original
DOL section likewise finds no pointer into these ranges.

The parser reconstruction remains private and nonmatching at 2,352 versus
2,340 bytes. No parser code is credited by this data addition. Frozen evidence
is in `scratch/voice_record_parser_800AD990_20261020/`; production object and
native acceptance receipts are in `scratch/voice_buffers_integration_20261020/`.

The production objects, full native map, original DOL SHA-1, baseline regression
check, source extent audit and all 66 unit tests pass. The map proves all
12 parser backup allocations discarded and both buffer initializers retained.
The generated report records 74.1341% code and 94.6604% data matched, with
7,984 of 8,803 functions reconstructed. Code and data denominators are unchanged.
