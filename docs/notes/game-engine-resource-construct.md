# Resource owner construction and scalar setup

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Fourteen ordinary native C++ constructor units reproduce2,164 original code
bytes,512 extab bytes and168 extabindex bytes. Production recompilation checks
all actual relocation targets, emitted allocations and symbol extents. There
are no additional helpers, weak backups, literals or padding. These partial
units require full central original DOL acceptance before source credit.

| Original entry | Code | EH/index |
| --- | ---: | ---: |
| 8007F4AC | 204 | 80 |
| 80095E90 | 188 | 40 |
| 80096954 | 156 | 40 |
| 800972AC | 112 | 40 |
| 800978D8 | 180 | 40 |
| 80098470 | 168 | 40 |
| 8009D07C | 260 | 40 |
| 800A2E68 | 120 | 40 |
| 800A3FB4 | 120 | 40 |
| 800A4970 | 120 | 40 |
| 800AF2A8 | 160 | 80 |
| 800CC644 | 136 | 40 |
| 800E2A14 | 120 | 60 |
| 800E2D20 | 120 | 60 |

Five variants construct Object80098A70 through the unchanged fn800989C0 C
entry, install primary/secondary tables, allocate their resource storage and
initialize observed scalar fields. The complete base extent0x3E8 is established
by its accepted original factory allocation; the sparse view exposes observed
fields inside that base, including resource slot344, rather than incorrectly
placing them after the full base. Some derived classes add scalar/index3E8 and
byte3EC. Existing destructor-only views of this base establish smaller minimum
prefixes; those accepted sources remain unchanged.

9D07C constructs Object8009AA98 with established extent0x390, installs its
tables, initializes two vectors and six scalar fields, allocates storage344,
then sets the original final constants in derived and base fields. A2E68,
A3FB4 and A4970 use the established0x3F8 Object8009DAB0 extent and derived
storage3F8. CC644 uses Object800A8F90 extent0x3B0 and initializes its derived
scalar3B0 along with observed base fields. The original factories and accepted
setup sources establish these extents; unknown bytes remain explicitly opaque.
Existing C setup entries are called through ordinary inline base constructors,
without changing their identities or bodies.

7F4AC and AF2A8 construct the established Objects802EB518/Objects802EB7C0
base and secondary Object8007D594, install their tables, and construct the
native0x94-byte Record800218F8 through fn800219A8. The complete secondary base
extent is0x2C, with an explicit derived four-byte gap before the Record member.
They initialize their observed scalar/vector/flag fields and allocate storage.
E2A14 and E2D20 use the same multiple-base layout and allocate resource arrays
after installing their tables. Every original compiler cleanup action points
to the existing native base or Record destructor at the original address.

All scalar constants, mutable vector globals, original table arrays, allocation
labels and external base bodies retain their original ownership. Only actual
undefined ELF targets become dependency symbols; local EH objects remain local.
The native constructor symbols each carry an original_symbol guard. Every
compiled consumer is inventoried with its source and canonical manifest hashes,
and exactly one declaration and one call per source. Root's accepted
identifier-only migration gate must preserve original/current snapshots and
prove unchanged consumer allocated bytes and resolved targets before staging.
This handoff changes no consumer, shared header or central metadata.

Full original extabindex and constructor/destructor tables are scanned. Each
true original function extent owns exactly one complete EH/index record and
has no startup-table reference. Every initialized original data section is
scanned for callable word pointers; only the owned extabindex function pointer
is present. Frozen source, verifier, ownership and manifest hashes accompany
the handoff. Recursive quoted-header inventories are empty because these
private units have no includes.
