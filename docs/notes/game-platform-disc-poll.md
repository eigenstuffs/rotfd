# Disc polling and persistent error state

The poll function in `src/Game/platform_disc_wait.cpp` reconstructs the complete 536-byte
`8028F29C..8028F4B4` body and its 52-byte compiler-generated status table at
`802F2334..802F2368`. The seven static-state bytes at `80378170..80378177` retain original ownership. The four versioned symbols
represent a remembered status, its initialization guard, a pending-error
byte and that byte's initialization guard. Names and original TU boundaries
remain provisional.

The routine initializes its persistent state once, queries global drive
status and serializes retryable/fatal error handling through the shared
error flag. A pending error keeps the polling loop alive. Recovery to status
zero clears the pending byte and sends the same event mapping as the disc
wait routine: 5 → 0, 4 → 1, 6 → 2, 11 → 3, -1 → 4. Callback delivery requires
the original enable flag and callback pointer. The routine logs after an
error/recovery sequence, clears its shared error flag and returns success
unless a fatal error occurred.

An ordinary C++ function-local-static probe reproduces all 536 text bytes,
the switch table and the seven state bytes with GC/1.3.2. Its automatic
guard checks confirm the interpretation of the four state symbols.
All 13 original loads/stores of these four symbols are inside this routine;
`scratch/game_disc_wait/poll_static_state_references.json` records the scan.

Code order places this function before the accepted disc-status query;
data order places its static state after that query's owned SBSS word.
Giving both ranges to one incremental split causes a DTK link-order cycle.
The accepted partial reconstruction therefore expresses the observed guard
checks explicitly and borrows the original state from an explicit original-data split.
Both compile to the same original instructions and storage. Earlier status
source remains unchanged. The compiler emits the separate C definitions in
reverse declaration order, as reflected in the state source.

The separate table input inserted four bytes of compiler alignment. The
accepted wait/poll unit therefore compiles the two adjacent functions together,
preserving both tables contiguously with their native eight-byte section
alignment. A separate seven-byte state definition was exact in isolation but
introduced alignment in the full link; it remains an uncredited private probe.
The original flags, guards, state, following padding and neighboring words
remain in `original/platform_disc_flags.s`, outside source progress.

Strict production proofs are `scratch/game_disc_wait/verify_wait_poll.py`: 96 actual relocations for
the combined 1,328-byte code and 104-byte table group. The seven-byte private
state proof and all 13 original references are preserved as research evidence.
Original diagnostic text, shared callback/flag storage and neighboring
routines remain outside these partial units. Full integration is recorded
in `scratch/platform_disc_poll_checkpoint.json` and its linked-byte proof.
