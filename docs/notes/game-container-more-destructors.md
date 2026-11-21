# Further typed container lifetime fragments

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Five ordinary C++ destructor fragments match their first typed probes, with
1,520 code bytes and 260 compiler-generated original EH/index bytes:

| Address | Code bytes | Destruction view |
| --- | ---: | --- |
| 800C4E04 | 316 | Outer table layer over a Handle/pool container |
| 800B7B28 | 312 | Service cleanup and high-offset Handle storage |
| 8002CFCC | 300 | Three-layer Handle at `60` plus container prefix |
| 800B9598 | 300 | Three-layer Handle at `64` plus container prefix |
| 80044BA8 | 292 | Three empty table layers over the container prefix |

The common minimum container destruction view contains the external native
`Object_8025F0D8` prefix, a dynamic pool of four-byte empty elements at `48`, a
word at `54`, a two-layer Handle at `58`, and an opaque `5C..60` span. Typed
inheritance and member destruction supply the observed null guards and table
transitions. The `64` Handle views leave `60..64` opaque; the three empty-layer
view preserves the `60..68` and `68..70` opaque spans.

The high-offset fragment calls the external service cleanup before destroying
a two-layer Handle at `1506C` and a pool of three-layer Handles at `1504C`.
Its external base view places the primary table pointer at `30`, with opaque
padding through `1504C`; this is a minimum destruction view, not a reconstructed
complete base class. The base destructor's unused provisional spelling is
guardedly migrated to its native class spelling for the external call. Its
original 652-byte body remains outside this split and receives no source credit.

Native non-throwing class deletion produces each original 40-byte exception
table and 12-byte index. Every allocated section, symbol extent and actual
relocation verifies without masks or assembly; there is no extra compiler
output or owned padding. Full original tables establish the five original
exception records and no startup pointers. All migrated provisional names have
no compiled callers. External tables, services and neighboring functions remain
outside these splits. Final executable acceptance is required. Frozen proofs:
`scratch/game_container_more_lifetime/final_integration.json`.
