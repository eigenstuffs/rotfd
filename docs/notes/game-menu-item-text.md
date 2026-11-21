# Menu item text formatting

Menu2D (`80216150..80216228`) and Menu3D (`80218874..8021894C`) use the same
216-byte routine shape. Each prepares eight machine-word argument slots,
resolves the object stored in the menu handle at offset 0x24, and calls its
native virtual slot 0x70 with the item's keyword and each parameter hash.
The returned values are passed to the already recovered formatter at
`801F44DC`, with the item's name as format text.

The item pointer is refreshed for each loop condition, preserving the original
reload of the element-array pointer after the virtual call. The final pointer
also supplies the format text when there are zero parameters. The original
lacks a separate parameter-count bound check and a null-object guard; this
behavior is preserved. The shared declarations are partial observed interfaces;
unknown virtual slots and fields are not claims about original names.

`src/Game/menu2d_item_text.cpp` and `src/Game/menu3d_item_text.cpp` reuse the
verified 188-byte menu item layout and generational handle resolution.
Both are ordinary text-only source objects: 432 bytes, six actual relocations,
no data, weak helpers, exception metadata or padding. Verify them with
`python3 scratch/game_menu_item_text/verify.py --production`.

Integrated on 2026-09-27. The rebuilt DOL is byte-identical; all 632 linked
source units match; the original baseline and all previous source files remain
unchanged. All 23 tests plus progress, source-extent and assembly-token audits
pass. Acceptance is recorded in `scratch/menu_item_text_checkpoint.json`.
