# Fixed world handle array lifetime

`src/Game/world_handle_array.cpp` reconstructs four native lifetime routines
at `0x801E55C4..0x801E5724`, totaling 352 code bytes. The object is a fixed
array of 144 four-byte handles. Its native constructor/destructor invoke the
compiler's `__construct_array` and `__destroy_arr` helpers with the verified
count, stride and element function pointers.

The element constructor calls the base Handle constructor and performs four
inlined initialization layers. Its destructor reproduces the corresponding
empty inheritance layers and invokes the native Handle destructor. Deleting
forms use the arena allocator. The recovered class/template names identify
the observed layout and addresses; the original template arguments are unknown.

The compiler emits four additional unreferenced inline destructors totaling
360 bytes. These are absent from the final executable and receive no credit.
The unit emits no data or BSS. All 16 retained relocations, every retained
instruction and all emitted allocations are checked by:

```
python3 scratch/game_world_handle_array/verify.py --production
python3 scratch/game_world_handle_array/link_proof.py
```

The nearby population routine at `0x801E52EC` is investigated separately and
is not credited by this lifetime split. Its current private probe and precise
differences are preserved in `scratch/game_world_handle_fill/`. Full integration
evidence is in `scratch/world_handle_array_checkpoint.json`.


## Population continuation, 2026-10-15

`src/Game/world_related_handle_fill_801E52EC.cpp` now owns the adjacent 728-byte
population routine as a separate verified text split. The borrowed pointer
value reproduces the native argument and register allocation with the verified
ObjectsOwner base. Its five natural unused helpers total 452 bytes and receive
no credit. Both native links, original DOL hash, full historical ownership and
regression checks, and 66 tests pass. The earlier private probes remain
preserved; the accepted receipt is
`scratch/continuation_20261012_b/world-record-copy-acceptance.json`.
