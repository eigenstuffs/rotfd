# Early indexed record dispatch

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

fn_800A7840 matches164text bytes,44extab and12extabindex withGC1.3.2,-O4,s and
C++ exceptions. When byte18 is set, it copies the retained Handle04, passes the
list at context114 + signed index2C*4C to fn801E1F3C, then finishes through
fn802139D8. The accepted800E73B8 pattern differs only in its index20 field;
its source remains untouched. The private zero helper has unique identity
RecordZero_A7840, avoiding an unrelated weak symbol collision.

Strict production verification accounts for all512emittedtext,164extab and
48index bytes. Only164/44/12receive source credit. The three weak destructor
backups total348text+156metadata: native8002F6B0(120),native80021BCC(116),
privateRecordZero_A7840(112). Two retained EH references resolve to the freshly
recompiled, strictly verified existing strong native owners; their bounded
production-defined-weak-eh-override-v1 proofs are frozen. The private zero
backup is unreferenced. All backup text/metadata must be discarded by final
native linking; no separate adapter is needed.

All13retained and21backup actual relocations are inventoried. Complete original
extabindex/ctors/dtors tables and initialized data-pointer references are audited.
No new data/BSS/padding, function alias, native identity or consumer migration.
Frozen handoff: scratch/game_engine_batch123/HANDOFF.md. Central final native
link/hash/regression acceptance remains pending.
