# Named-world group creation command

`src/Game/hierarchy_create_command.cpp` reconstructs `fn_802062F4` at
`0x802062F4..0x802064DC`: one 488-byte method, with no owned data.
It is shared by the registered `SetGame` and `SetMonoGame` wrappers. It requires
console `argc >= 3`, including the command token, and nonzero `numeric[2]` at
`0x8A6`. It looks up `argv[1]` as the named `WORLD`, retains the returned native
handle, and converts `values[2]` at `0x8BC` to an integer before validating the
handle. The numeric flag means successful parsing, not a true/nonzero value.
The original three bound checks (less than one, greater than one, greater than
four) are preserved, including the redundant upper check.

For `argc == 4`, it hashes `argv[3]` at `0x870` as the camera type;
otherwise it uses the external `CameraAgent_Z` default string at `0x802AD998`. It copies that
hash into the observed name/type wrapper and calls the now recovered group
creation routine `fn_801FF4F8`, forwarding the world handle, `argv[1]`, count,
and incoming shared-mode byte. It cleans up the owned handle and returns one.
Invalid argument count, handle or player count returns zero with the appropriate
native cleanup. Argument counts above four still use the default camera type, as in the
original guard. The [console argument layout](console-argument-layout.md) is
now established; the wider class identity remains provisional.

This source reads the existing named-binding private header without modifying
it. The WORLD and default-camera strings remain external original storage.
GC/1.3.2 with the recorded normal Gekko optimization flags emits the exact
488-byte body and two unreferenced weak destructor tails totaling 172 bytes.
The four tail relocations are confined to those unused helpers, which are
excluded by ordinary dead stripping and receive no source credit.

`python3 scratch/game_hierarchy_create_command/verify.py` checks all retained
allocated bytes and applies all 25 real retained relocations against the
protected original DOL. The result is zero differences, with no data, BSS,
exception record or alignment ownership. The manifest is
`config/GSQE78/candidates/game-hierarchy-create-command.json`.

Central integration passes the original DOL SHA-1 and direct whole-file byte
comparison. Native objdiff records 488/488 code bytes and 1 matching function;
owned data is zero. The source-section extent guard and generated progress
checks pass. All linked source remains exact; the original baseline is preserved
with only the documented native-accessor and trailing-padding corrections.
