# Menu3D item insertion and Root callback

Integrated on 2026-09-27. `src/Game/menu3d_item_append.cpp` supplies the
572-byte function at `80219164..802193A0` and
`src/Game/menu3d_root_callback.cpp` supplies the 32-byte function at
`802193A0..802193C0`. Their 18 and one actual relocations respectively match.
There is no emitted data, weak code, exception metadata or padding.

The item and array storage layouts coincide with the verified Menu2D append
view. The Menu3D source reuses that partial storage view through an explicitly
named alias. Both arrays grow by 32 elements through the original arena
allocation functions. Insertion copy-constructs a 188-byte item, then appends
its address to the inherited pointer array and returns the pointer's index.
The qualified Root callback preserves its native signed-char return value.
No guards or changed container behavior are introduced.

The source units are separate to preserve the compiler's natural function
order. Tables, strings and allocator storage retain their existing ownership.
The Menu3D parser can now call this source-owned insertion routine.

`python3 scratch/game_menu3d_item_append/verify.py --production` checks every
allocated byte and resolves all actual relocations. The full rebuild is
byte-identical, all 628 source units match, the baseline and all previous source
files are unchanged, and all 23 tests plus the progress/source audits pass.
`scratch/menu3d_item_append_checkpoint.json` records acceptance.
