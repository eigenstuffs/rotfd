# Native Python argument-format strings

Five ordinary C++ data units reconstruct forty existing GLOBAL strings used by
accepted Python bindings. Each initializer is a typed `const char[size]` array
containing its meaningful argument format and final NUL. These are partial data
splits; the complete original translation unit is not claimed.

| Family | Owned `.rodata` interval | GLOBAL strings | Allocated bytes | String/NUL bytes | Natural alignment bytes |
| --- | --- | ---: | ---: | ---: | ---: |
| Game_Z | `802A2D30..802A2E25` | 11 | 245 | 221 | 24 |
| MovingAgent_Z | `802A51E8..802A5283` | 6 | 155 | 147 | 8 |
| Breakable_Z | `802A54B8..802A553F` | 5 | 135 | 130 | 5 |
| LodAgent_Z | `802A5578..802A5611` | 6 | 153 | 148 | 5 |
| RtcAgent_Z | `802A56B8..802A57E2` | 12 | 298 | 277 | 21 |

All five first probes reproduce the entire original allocated ranges exactly.
The compiler naturally aligns independent char objects to four-byte boundaries
within a section aligned to eight bytes. Several internal native objects begin
at addresses congruent to four modulo eight; their observed offsets are
preserved in the ordinary grouped source. There are no explicit alignment
pragmas, padding members, dummy arrays, aliases, byte-blob initializers or code.
The following compound factory-name pools and every trailing alignment gap stay
outside the claimed intervals.

The native identity and ownership preflight precedes source creation. It checks
all forty GLOBAL OBJECT names, addresses, sizes, bytes and absence of aliases in
string extents; all canonical schemas including legacy `splits`; current split
ranges; and source definitions. Whole-range inspection additionally inventories
all twenty-seven existing synthetic `gap_06_*_rodata` GLOBAL labels covering the
63 internal alignment bytes. These DTK-generated labels are not recovered
source variables. Their bytes are emitted naturally, and the labels must be
absent from both final ELFs after adoption. No exception permits extra GLOBAL
aliases in the owned ranges.

The complete original/current census covers 10,391 inputs and 204,101 allocated
relocations. Each string has one original and one accepted-source HA/LO pair,
160 union records total (80 original, 80 active), all named with zero addend.
There are no undefined declarations or named relocations for any synthetic gap
label, no physical relocations to alignment bytes, and no cross-extent addends.
A bytewise scan of 501,416 initialized DOL positions finds no pointers into the
strings or gaps. All words of all 3,144 exception-index, 24 constructor and
eight destructor records were checked with no references to these ranges.

Fresh production compiles verify all 986 allocated bytes, all forty symbols,
and zero code/helpers/metadata/actual relocations through the unchanged strict
ELF verifier plus a complete allocation inventory guard. Five positive fixtures
and twenty adverse raw allocation/identity cases pass. Five actual private MWLD
links at original addresses reproduce all data and forty GLOBAL identities,
with exact production-basename owner/placement map rows and no synthetic gap
symbols. Fifteen wrong-owner/address/duplicate-owner map mutations reject.

Root integration must repeat dual complete native ELF/map placement, sole
production ownership, exact bytes, disappearance of all twenty-seven gap
identities, and unchanged neighboring original bytes. The original DOL hash,
baseline, regressions and all previous acceptance gates remain mandatory.
This proposal credits zero code bytes and zero functions. The producer note
is permanently frozen; later acceptance belongs in a separate note.
