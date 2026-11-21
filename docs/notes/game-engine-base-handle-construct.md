# Object base, Handle family and array construction

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Eight ordinary C++ constructor units match 2,852 original code bytes, 1,496
extab bytes, 96 extabindex bytes and all 230 real relocations. Independent
production recompilation checks every emitted allocated byte, symbol extent and
resolved target. There are no extra helpers, weak backup destructors, literals
or padding. These are partial original units pending central DOL acceptance.

| Original entry | Code | EH/index | Actual relocations |
| --- | ---: | ---: | ---: |
| 800272F0 | 448 | 300 | 34 |
| 8002DC0C | 416 | 240 | 27 |
| 80074BC0 | 384 | 220 | 35 |
| 800754C8 | 336 | 220 | 32 |
| 800AA554 | 396 | 220 | 34 |
| 800ABFDC | 188 | 72 | 17 |
| 800C20E8 | 356 | 100 | 19 |
| 800E0EE4 | 328 | 220 | 32 |

Five units inline the established ObjectsBase802EB3F8 initialization: the
0x20-byte native Root, typed Handles20/24/28, four arrays38..5C, Handle68,
array6C, word78 and Handle12C within the 0x168-byte base. Each array is the
observed count/capacity/data triple with its existing native destructor identity.
Separate zeroing layers preserve the two-, three- and four-store Handle
initialization sequences. The compiler emits every original intermediate-base
and member cleanup action, including the exact destructor addresses and action
deduplication. Root construction calls the existing native constructor through
its original extern-C identifier; no Root implementation is replaced here.

The three resource setup variants and E0EE4 construct the existing secondary
Object8007D594 through fn8007D550 and overwrite its table with finalTable+0x120.
The private secondary extent is 0x2C, established by E0EE4's genuine derived
storage member at0x194 and the accepted corresponding resource destructor.
The other three have an explicit derived opaque194..198 gap before their
observed vector or resource fields. This separates derived storage from the
native base. The earlier small-EH destruction view's unused sizeof0x30 is
preserved unchanged; its isolated table-only body does not establish an extent.

272F0 adds typed Handles168/16C/180/184/1AC/1B0 around opaque gaps. 2DC0C uses
the established 0x60-byte ContainerBase, one-layer Handle60 and the original
four-/five-store typed Handle family at6C..90, plus word64 and byte94. The final
Handle90 has four zero stores; its type is inferred only to that observed
construction depth because this unit has no cleanup action for the final
member. ABFDC retains the native 0xC Root, array14, Handle150, scalar14C,
indices20/24 and flags before the original storage allocation. C20E8 uses the
same-size 0x20 ManipulatorDraw base and its observed Handle20, sparse scalar
and vector fields, and Handles604/608/60C. All unknown bytes remain opaque.

All original tables, scalar constants, mutable zero vectors, allocation labels,
base bodies and external member destructors retain their original ownership.
Ordinary scalar assignments and member initializer expressions reproduce the
original store order and call lifetimes. Only actual undefined ELF symbols are
published as dependencies; local exception object names stay local.

Each proposed native constructor symbol has an original_symbol guard. Every
old identifier has exactly one declaration and one call in an accepted factory
source. The pending consumer records freeze current source/canonical hashes
and two identifier occurrences for the integrator's accepted identifier-only
migration gate. Current factories8007E160 includes the already proven prior
C42D8 and derived-six migrations; its current hashes and the migration registry
provenance are recorded. This handoff changes no consumer or shared metadata.

The full original extabindex80015F60..8001F2C0, constructors80299920..80299980
and destructors80299980..802999A0 are scanned. Each true function extent owns
exactly one complete original EH/index record and has no startup reference.
Every initialized original data section is scanned for callable word pointers;
only each function's own extabindex pointer is present. Source, verifier,
manifest and ownership hashes are frozen; quoted header inventories are empty
because these private units have no includes. Full central original DOL hash
and regression checks remain required before source credit.
