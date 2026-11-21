# Callback reset, initialization and recursive destruction

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Accepted production integration passes the original full-DOL SHA-1,
`ninja changes` with no regressions, source-extent/progress audits and all
26 unit tests. The final canonical manifest is `config/GSQE78/candidates/game-callback-reset-and-destruction.json`.

Three partial C++ source units reconstruct four complete original functions:
node reset at `8025F7FC` (304 bytes), node initialization at `8025F92C` (344),
group destruction at `8025FA84` (168), and entry destruction at `8025FB2C` (440).
The frozen manifest and strict current-source verifier are in
`scratch/game_callback_reset/` (`integration.json` and `verify.py`).

Reset releases snapshot storage, clears its pointer and size, clears the low
three flag bits, zeros the counter/next pointer and clears the key array.
The clear method preserves both native branches: a negative length releases
storage then placement-constructs the missing records up to length zero; a
positive length destroys records backward, then releases storage. This unusual
negative-length path is present in the original inlined array code and is not
simplified away. Key construction sets the key to minus one and its byte state
to zero; its destructor is empty. Initialization stores the original table,
zeros the array and snapshot fields, then inlines reset. Repeated native loads
and stores remain present through ordinary inline functions.

Group destruction releases two entry chains, then its recursive group chain,
and optionally the group itself according to the signed 16-bit flag. This unit
uses `-inline off` to reproduce the native calls. Entry destruction uses normal
`-inline auto`; the compiler reproduces the original recursive expansion, null
guards, child storage releases and pointer-zero stores before the final optional
object release. Both functions return the original supplied pointer.

The units own only their exact text extents; referenced allocation contexts,
tables and adjacent original functions retain their owners. No weak helper,
owned data or padding is emitted. Original exception/startup ownership was independently checked, and full
executable acceptance passed.
