# World record queries and callback dispatch

`src/Game/world_record_queries.cpp` owns the contiguous text range
`0x801E48EC..0x801E4C54`: three functions and 872 code bytes. It emits no
initialized data, BSS, weak helpers or compiler padding.

- `fn_801E48EC` (200 bytes) searches the 28-byte record array for a record
  with a nonzero signed flag whose resolved `handle10` equals the supplied
  handle's resolved pointer. This compares pointers, so two invalid handles
  can compare equal. The source preserves that original behavior.
- `fn_801E49B4` (80 bytes) searches the 76-byte curve-record array by its
  first word and returns the signed 16-bit ID at offset four, or `-1`.
  The name/ID roles remain inferred; the comparison and offsets are verified.
- `fn_801E4A04` (592 bytes) calls the qualified Root `slot1C` first and
  returns zero if it fails. Otherwise it dispatches `slot1C` through each
  28-byte record's first handle and through the three optional handles of
  each 20-byte record, then calls `fn_801F7154` on the embedded action curve
  and returns one. Child callback return values are ignored. The precise
  semantic meaning of `slot1C` remains unresolved.

The signed load in the first query refines `WorldRecord1C::flag0C` from
unsigned to signed byte. All three previously matched loader/callback
routines and both previously matched small-record resize routines were
recompiled with that declaration and remain exact. The existing native
curve-record declaration supplies the second query's field offsets.

The strict verifier applies all nine actual relocations and checks the
entire emitted section and every symbol:

```
python3 scratch/game_world_record_queries/verify.py --production
python3 scratch/game_world_record_callbacks/verify.py --production
python3 scratch/game_world_record_callbacks/verify_resize.py --production
```

See `scratch/world_record_queries_checkpoint.json` for full-DOL, native
objdiff, unchanged-baseline, source-extent, source-assembly and tooling-test
validation. World construction/destruction, later callbacks and other
original data remain outside this partial unit.
