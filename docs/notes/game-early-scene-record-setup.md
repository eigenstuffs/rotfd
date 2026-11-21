# Early scene record setup

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`early_scene_record_setup_8002A900.cpp` reconstructs the unchanged C entry at `8002A900..8002AB04` (516 bytes). It owns only extab `80006964..8000696C` (8 bytes) and index `80016950..8001695C` (12 bytes) in addition to text. Isolated strict verification reproduces every allocated byte and all 20 actual relocations, with no unused helpers, extra metadata, data pools or padding. Parent full DOL hash/regression acceptance remains necessary before source credit.

The function logs through the global service, forwards the owner and second argument to the existing spatial reset routine, then queries the current scene actor for an index. On a false result it resolves the owner's intermediate Handle at `+58` and that object's child Handle at `+20`, calls the child's virtual method at table slot `+40`, sets owner flag `40000`, resets the resolved actor and invokes the owner's virtual method at slot `+30`. It saves the queried index at `+8C`, resolves the actor Handle at `+70`, sets its timer at `+1A4`, resets its component at `+168`, and initializes owner state/scalars at `+7C/+80/+84/+88`.

All private views retain opaque storage around observed fields. The manager uses the original 16-byte entries, object pointer at zero and signed generation byte at `C`. Distinct Intermediate, Child and Actor entry pointer types preserve the original nested table reloads. Both virtual interfaces place the table pointer at `+8` behind an opaque prefix. Owner flags are an unsigned 64-bit field at `+38`. The global view uses logger/manager/scene at `110/118/124`, and the scene's current actor pointer is at `15058`.

The first probe matched every body instruction except four scheduling words around index initialization. Loading the scene's current actor into an ordinary local before assigning `index=-1` reproduced the original load/store order. Inline query and small wrapper-class alternatives preserved the four differences; all probes remain preserved without credit. The final production source adds only a comment to the exact ordinary source.

Compilation uses GC1.3.2 and the established `-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on` flags. The existing signed-byte query return declaration emits the original sign extension; the observed second-argument forwarding remains explicit. No shared signatures, source aliases, native identities or accepted files change. All external constants and the logging string keep their original owners.

The full original extabindex and constructor/destructor startup tables were audited. Only the expected exception pair transfers, and no startup entry belongs to this extent. The initialized-data scan finds its extabindex pointer and one existing callable-table pointer; the complete table symbol extent/raw hash is recorded and that table remains external, referencing the unchanged C identity.

The isolated source, probes, allocation/relocation inventory, ownership audit, replay and frozen handoff are under `scratch/game_early_scene_record_setup_continuation`. The standard unchanged object verifier suffices. Root performs full native placement, DOL hash, baseline, source extents, progress and test acceptance; no new gate is proposed.
