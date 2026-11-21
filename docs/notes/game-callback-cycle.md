# Linked callback cycle

`src/Game/callback_cycle.cpp` reconstructs two complete functions at
`8025E910..8025EA74`, totaling 356 text bytes. Its private views record
observed offsets and preserve the distinct dispatch-node and selection-node
layouts; field names remain provisional.

The 236-byte `fn_8025E910` clears flag two in every dispatch node, clears
the restart byte, installs the original global cursor, sets the cycle state,
and invokes `fn_80286158`. It moves the pending selection list into the
active list, clears the pending endpoints, then dispatches each node whose
flag four is set and flag two is clear through `fn_8025F240`. A restart byte
resets the global cursor to the current head. Completion clears the cursor.

The 120-byte `fn_8025E9FC` searches the active selection list for the given
key. On success, it assigns the node handle through `fn_801F7914`, copies
the node's time and key, and returns one. Failure returns zero.

The active original fallback `auto_03_8025E910_text` contains exactly these
356 code bytes and no non-text allocations. The original global cursor
`lbl_80378088` and all neighboring functions retain their existing owners.
The production object emits exactly two global functions and no weak code,
data, BSS, constructor, exception or padding bytes. GC/1.3.2 with the recorded
Game flags reproduces every byte after actual relocation resolution:

```
python3 scratch/game_callback_cycle/verify.py
```

Full executable acceptance passed: the rebuilt DOL has the original SHA-1,
`ninja changes` reports no regressions, and source-extent/progress audits pass.
All 26 unit tests pass. Any emitted unlinked weak helpers are absent from the
final ELF and receive no matching credit.
