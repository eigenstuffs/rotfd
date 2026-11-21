# Native resource-owner destruction

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Three ordinary C++ destructor fragments match their first typed probes, with
908 code bytes and 196 original compiler exception/index bytes:

| Address | Code bytes | Destruction view |
| --- | ---: | --- |
| 800C224C | 300 | Resource pointer, four Handle members, and two inline base layers |
| 8007F578 | 304 | Four resource pointers, a pair of Handles, and two external bases |
| 800AF348 | 304 | Three resource pointers, a pair of Handles, and two external bases |

The first view places its external ObjectsOwner table at offset `8`, a Handle
at `20`, three more Handles at `604..610`, and a resource pointer at `624`.
The resource's non-polymorphic eight-byte prefix accounts for the observed
virtual destructor table at offset `8`. Inline Root and Draw destruction
provides the original intermediate table writes before the external base call.

The two multiple-base views have a primary table at offset `8` and an external
secondary base at `318` or `1F8`. Their record contains two nested Handle
members. Each body virtually deletes the fixed number of resource pointers,
then releases their pointer storage. Ordinary non-throwing global deletion
shares the compiler's original exception action between storage release and
final owner deletion, producing the exact 60-byte exception table. The first
fragment uses class deletion and a 40-byte exception table. Each has its
original 12-byte exception index.

Opaque spans represent minimum destruction layouts; external tables, resource
destructors, allocator code, and base definitions remain outside these splits.
No array of encoded instructions, aliases, assembly, or masked relocation
comparisons is used. All emitted allocations and symbol extents are accounted
for, and all 49 actual allocated relocations verify. Full original exception
and startup table audits establish exclusive ownership of the three exception
records. The provisional entry names have no compiled callers and are guarded
for native destructor identity migration.

Frozen source and production-object checks:
`scratch/game_complex_owner_lifetime/final_integration.json` and `verify.py`.
Full executable acceptance is pending.
