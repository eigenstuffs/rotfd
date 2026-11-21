# CScriptAgent and AnimatedAgent Python argument formats

Two ordinary C++ data units reconstruct 193 existing GLOBAL format strings used
by accepted Python bindings. Each definition is a complete typed
`extern "C" const char[size]` array containing its meaningful ASCII argument
format and final NUL. These are partial data splits.

| Family | Owned `.rodata` interval | GLOBAL strings | Allocated bytes | String/NUL bytes | Natural alignment bytes |
| --- | --- | ---: | ---: | ---: | ---: |
| CScriptAgent_Z tail | `802A3228..802A49F0` | 164 | 6088 | 5857 | 231 |
| AnimatedAgent_Z | `802A4DC0..802A51A6` | 29 | 998 | 958 | 40 |

All 7,086 allocated bytes match the original. The compiler naturally aligns
independent char objects to four-byte boundaries inside an eight-byte aligned
section. There are no explicit padding objects, pragmas, aliases, byte-blob
initializers, helpers, code or emitted relocations. The 136 original synthetic
`gap_06_*_rodata` GLOBAL labels cover the 271 natural internal alignment bytes;
their bytes are reproduced naturally and those labels must disappear from both
complete native ELFs, including any zero-size aliases.

Native GLOBAL identities, original bytes, source definitions, current splits
and all canonical schemas were checked before source creation. A supplemental
complete canonical scan covers 1,768 files and
14,929 physical ranges, including
733 legacy map ranges, with no overlap.
The complete stable post349 census covers 10,428
original/current inputs and 204,101
allocated relocations. Each format has one named, zero-addend HA/LO pair in
original input and one in its accepted source: 772 union records (386 original,
386 active). A bytewise scan of 501,416 initialized DOL positions finds no
pointers into the strings or alignment. No named or physical relocation,
undefined declaration, cross-extent addend or initialized pointer targets the
136 synthetic internal gap identities or bytes. Every word of all 3,144
exception-index, 24 constructor and eight destructor records was checked.

The preceding CScriptAgent format at `802A3204` and its original two-byte tail
`802A3226..802A3228` remain external. The ABC formats starting `802A49F0` and
following compound factory-name pools remain external. The AnimatedAgent owned
range ends at `802A51A6`; its original two-byte tail `802A51A6..802A51A8` and
compound 64-byte pool at `802A51A8` remain external. Explicit original-only
align1 tail ownership may be needed during DTK splitting. These four boundary
bytes are excluded from source credit. A separate topology supplement also
checks the five earlier frozen format groups: all ten boundary gaps total
18 original-only bytes, with zero named/physical/pointer/table references.
That supplement does not modify the earlier handoff.

Two fresh production compiles reproduce the entire objects through the
unchanged strict ELF verifier and complete allocation inventory. Two positive
fixtures and twenty adverse allocation/identity cases pass. Two actual
private MWLD links at original addresses reproduce all 193 GLOBAL objects and
7,086 bytes with exact production-basename owner and placement rows, no gap
symbols, and six rejecting map mutations. No source credit is accepted here.

Root integration must prove exact sole production ownership in both complete
native ELFs/maps, retain every genuine string identity, remove all 136 internal
synthetic gap identities, preserve external boundary bytes and neighboring
objects, and repeat complete postintegration consumers. The original DOL hash,
unchanged denominator, baseline, regressions and all previous acceptance gates
remain mandatory. This proposal credits zero code bytes and zero functions.
This producer note is permanently frozen; acceptance belongs in a separate note.
