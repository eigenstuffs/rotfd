# Named actor targets and controller setup

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

fn80085C14 owns628text at80085C14..80085E88,8exception bytes at8000DDE8..8000DDF0 and12index bytes at8001A034..8001A040. Ordinary C++ source src/Game/early_actor_named_targets_setup_80085C14.cpp reproduces all retained bytes and19real relocations using GC1.3.2/Gekko/O4,s/exceptions on/use_lmw_stmw. Central original-DOL acceptance remains pending.

The routine copies a three-float scene position, looks up a first named target from the scene, resolves a two-link actor chain and looks up a second named target, and obtains a third target through virtual slot9C. It then configures actor event/controller options and conditionally notifies the global service. Distinct concrete SceneNode and Node entry types preserve the original nested manager reload. Genuine Name temporaries and a private derived Handle return wrapper preserve all stack allocations and normal base cleanup calls.

There is one unused compiler Return_80085C14 destructor76 with8EH+12index and4discarded relocations. The unchanged standard production-defined-weak-eh-override-v1 route with no strong owners verifies all emitted allocations and actual relocations; an actual isolated MWLD link discards all three backups. No defined weak helper is retained by primary metadata. The original C entry and every dependency identity remain unchanged.

The full original EH records/final descriptor, ctor/dtor tables, initialized pointer words and compiled-source consumers are audited. Original GLOBAL callback table lbl802B8E44[1C] retains unchanged pointer802B8E50. Borrowed strings lbl8029D6B4 and SDA lbl80378B18 remain external. No literal/data/BSS/padding ownership transfers. Full native original placement/discard and original-DOL/hash/baseline/extents/progress/tests remain integrator requirements. Evidence is frozen in scratch/game_engine_batch196; no whole original translation-unit recovery is claimed.
