# Callback pointer search and snapshots

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Accepted production integration passes the original full-DOL SHA-1,
`ninja changes` with no regressions, source-extent/progress audits and all
26 unit tests. The final canonical manifest is `config/GSQE78/candidates/game-callback-snapshot.json`.

Three partial source units reconstruct five complete functions and 440 original
code bytes: disabling by member pointer (`8025EEB4`, 128), finding by member
pointer (`8025F074`, 100), copying snapshot bytes into/out of a node (`8025F620`
and `8025F658`, 116 combined), and allocating snapshot storage (`8025F694`, 96).
The GC/1.3.2 verifier is `scratch/game_callback_snapshot/verify.py`; the frozen
manifest is `integration.json` in the same directory. It checks every allocated
byte, complete function extent and actual relocation.

Search uses native member-function-pointer equality. Disabling clears flag bit
two on the first matching node; finding returns that node or null. Snapshot
views record only the buffer at `20` and its size at `24`. Copying occurs when
both the supplied buffer and stored size are nonzero. Allocation records the
requested size and calls the original allocation wrapper with the same context,
source strings, line and alignment. No external table/string/context definition
is reconstructed in these fragments. Private names remain provisional.

The larger activation and excluded-key-filter probes still differ and receive
no matching credit. Full executable acceptance has passed.
