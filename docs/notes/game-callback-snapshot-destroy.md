# Callback snapshot destruction at 8025F6F4

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Accepted production integration passes the original full-DOL SHA-1,
`ninja changes` with no regressions, source-extent/progress audits and all
26 unit tests. The final canonical manifest is `config/GSQE78/candidates/game-callback-snapshot-destroy.json`.

`src/Game/callback_snapshot_destroy.cpp` reconstructs the complete 264-byte
function at `8025F6F4..8025F7FC`. It restores the original table, releases a
nonempty snapshot buffer through the original allocation context, destroys
its key array and optionally releases the object when the signed 16-bit flag
is positive. It returns the original object pointer, including null.

The private array has length at `10`, capacity at `14`, and eight-byte key
records at `18`. Its inline C++ destructor reproduces the original native
member null guard, empty element destructor loop (including eight-iteration
unrolling), buffer release using capacity times eight, and both pointer-zero
stores. No fabricated volatile access or hand-written instruction is needed.
The explicit source null guard on the member was removed because the native
compiler already generates it for the destructor call; retaining both would
add eight mismatching bytes. Type and member names are provisional.

`python3 scratch/game_callback_snapshot_destroy/verify.py` compiles the current
source with GC/1.3.2 and verifies every allocated byte, complete function binding
and extent, every actual relocation and nonallocated compiler metadata. No weak
function, owned table, scalar constant, startup entry or exception record is
claimed. External contexts, tables and adjacent functions retain their original
owners. Full executable acceptance has passed.
