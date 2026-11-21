# Specialized world action-curve lifetime

`src/Game/world_action_curve.cpp` reconstructs the native destructor at
`0x801F7560..0x801F77A4` (580 bytes). Its native virtual table at
`0x802EAAA8..0x802EAAB4` contributes 12 data bytes. The next four original
zero bytes have a separate fallback split and receive no source credit.

The 20-byte curve derives from the four-byte curve base and owns an array of
16-byte rows. Each row has a prefix word and an array of 12-byte action
entries. The compiler places the curve's virtual pointer at offset `0x10`.
Each entry contains a type, an index and an unresolved word. For types 17,
18 and 19, destruction returns the indexed token to the global manager's
pool when its flag is zero and its occupancy bit is set. This clears that
bit and decrements the live count. The manager's token stride is 129 bytes;
the flag is its final byte. Other type meanings and token contents remain
unresolved.

Native member destruction then walks both array levels, releases their
storage through the sized allocator, and invokes the curve-base destructor.
The deleting form also releases the curve object through the arena allocator.
The source uses ordinary C++ construction, destruction and indexed access;
there are no copied instructions or patched objects.

The shared declaration replaces the earlier constructor-only storage view
used by the 80-byte record. Its array constructor leaves initialization to
the containing curve, preserving installation of the virtual table before
the three array words are cleared. Both existing record routines remain
byte-exact. The resize object now emits an unreferenced 316-byte nested-array
destructor in place of its earlier 84-byte partial-storage destructor. All
1,188 weak-helper bytes are absent from the final image and receive no credit.

The strict verifier checks all allocated sections, symbols and 15 actual
relocations, including the native table's destructor pointer:

```
python3 scratch/game_world_action_curve/verify.py --production
python3 scratch/game_world_curve50/verify.py --production
python3 scratch/game_world_action_curve/link_proof.py
```

Full integration evidence is recorded in `scratch/world_action_curve_checkpoint.json`.
World lifetime, neighboring array operations and other shared tables remain
outside this partial source split.
