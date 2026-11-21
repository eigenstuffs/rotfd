# Menu2D item append and Root callback

The two integrated sources pass comparison of every emitted allocated
byte and all actual relocations: `menu2d_item_append.cpp` owns the 572-byte
`fn_80216A40` at `80216A40..80216C7C`, and `menu2d_root_callback.cpp` owns the
32-byte `fn_80216C7C` at `80216C7C..80216C9C`. Together they cover 604 code bytes
and 19 relocations. They emit no initialized data, BSS, weak helpers, exception
metadata, or padding. The complete byte-identical DOL and native objdiff integration pass.

The original item parser at `80214978` calls the append routine with its
`0xBC`-byte item. The accepted Menu2D lifecycle and factory evidence identify
the owning object; its element array has count, capacity and data at
`+68/+6C/+70`. This routine also exposes the inherited pointer array at
`+38/+3C/+40`. Each array grows by 32 entries through the existing allocate,
resize and release functions, including the original zero-size branch. The
routine copy-constructs an item at the first array's old end, then appends its
address to the pointer array and returns that pointer's index. The allocation
behavior, increments, native placement-construction null checks and signed
capacity arithmetic are retained without added guards.

The item header contains 128 text bytes, three four-byte Name values, and an
unsigned 16-bit flag field. The derived portion contains eight further Name
values at `+90`, four individual bytes at `+B0..B3`, and a two-float position
at `+B4/+B8`. The compiler generates the original sixteen-iteration text copy
and eight-element Name copy from ordinary implicit copy constructors; neither
loop is handwritten. An ordinary position copy constructor copying its two
float members reproduces the original `lfs/stfs` pairs. A plain aggregate copy
instead produced integer load/store instructions; that rejected initial probe
is preserved in `scratch/game_menu_item_append/initial.cpp`.

The Menu2D vtable at `802EB240` contains `fn_80216C7C` in slot `1C`. The callback
makes a qualified call to `Root_80207414::slot1C()` and preserves its signed-char
result. It includes the existing native Root interface without changing that
header. All original tables, strings, zero vectors and allocator objects
remain externally owned.

The two functions are separate ordinary source objects because the combined
template probe naturally emits the Root callback before the append routine.
Splitting the candidates preserves original link order without rewriting
compiler output, introducing artificial helpers, or forcing function ordering.
The same bytes also match in the preserved combined probe; only its emission
order differs.

Run `python3 scratch/game_menu_item_append/verify.py`. The script recompiles
both production sources and compares the complete allocated `.text`
sections after applying each real HA16, LO16 and REL24 relocation. It verifies
that no other allocated sections or weak functions exist. It checks the
protected original DOL SHA1
`5da8295a79bf297ab62c620e6ac66210be1c6ef5` before comparison. Evidence and exact
source/header hashes are recorded in:

- `config/GSQE78/candidates/game-menu2d-item-append.json`
- `config/GSQE78/candidates/game-menu2d-root-callback.json`
- `scratch/game_menu_item_append/strict_summary.json`
- `scratch/game_menu_item_append/original.s`, a saved copy of the original two
  functions from the then-current `auto_03_80215B4C_text.s` fallback

The earlier menu-item parser's two-instruction near-match remains separately
preserved and uncredited in `scratch/game_menu_item_parser/`. Recovering this
append routine does not promote that parser or its shared literal pool.

Final link and source accounting evidence is in `scratch/menu_completion_link_proof.json` and `scratch/menu_completion_checkpoint.json`.
