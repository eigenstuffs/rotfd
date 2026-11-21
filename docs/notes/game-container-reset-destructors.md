# Native handle reset and service cleanup destructors

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

These partial source splits reconstruct three ordinary C++ destructor bodies:

| Address | Native identity | Text | Original EH/index |
| --- | --- | ---: | ---: |
| 8004ACA4 | Object_8004ACA4 | 680 | 100 |
| 8004FB54 | Agent_8004FAE8 | 424 | 88 |
| 8002D0F8 | Agent_8002CF70 | 512 | 176 |

All 1,616 text bytes and 364 compiler-generated exception/index bytes match
after applying actual relocations. The first entry replaces an unused provisional
spelling through a guarded migration; the other two retain their existing native
identities. The production build passes the original executable hash and native
linker-discard acceptance at the `native-reset-sparse-pools` checkpoint.

The first destructor resets the native Handle at `70` and two native Handles
at `74`/`78` through typed default temporaries and assignments, followed by two
zero vectors and the identity quaternion. Inline base layers preserve the
observed vtable transitions. The minimum base view owns a pool at `48` and a
two-layer Handle at `58`; bytes `5C..60`, `60..68`, and `68..70` remain opaque.
Private scalar copy operators preserve the original floating load/store order.

The second destructor zeros the external state word, resolves its owner Handle
at `04`, and conditionally forwards a typed copy to the service at context
offset `164`. The final destructor creates a genuine typed temporary and local
Handle copy, then conditionally passes another value copy to its service. Its
copy constructor calls the external base constructor, copies the word, and
retains the source. The explicit temporary expression preserves the native
compiler's distinct exception lifetimes. Their remaining inherited and member
destruction follows the observed typed layouts and vtable writes.

Retained exception records refer to defined weak native Handle destructors.
Those exact original names already have accepted strong source owners. The
bounded [strong-over-weak audit](game-weak-override-verifier.md) independently
recompiles each owner, verifies all its original sections, and requires exact
source, recursive header, canonical manifest, and production object hashes.
It applies the actual retained pointers to those proven original definitions.
Every other retained reference to a discarded backup is rejected.

All 528 emitted backup code bytes and 228 backup EH/index bytes are separately
inventoried with exact extents, bindings, actual relationships and raw hashes.
They receive no progress credit. Native final linking proves their complete
discard, keeps one exact strong owner for each overridden name, and preserves all
retained exception pointers. The full target is relinked with its exact Ninja
inputs and flags plus native unused-allocation map output; the audit checks both
that link and the standard live ELF. Its DOL retains the original hash. The map
parser also rejects an input listed under the wrong duplicate symbol or missing
from a real multi-copy duplicate block. Full original table scans establish precisely the
three owned exception-index records and no startup-table references. External
data and other original routines remain outside these splits. Frozen production
proofs are in `scratch/game_container_reset_destructors/final_integration.json`.
Final native evidence is in
`scratch/continuation_20261010/native-reset-sparse-pools-native-override-proof.json`.
