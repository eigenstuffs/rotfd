# Menu backdrop and text renderer at 80219510

`src/Game/menu3d_render_80219510.cpp` reconstructs the complete 1,464-byte
renderer at 80219510..80219AC8. It draws the viewport backdrop, four material
quadrants and visible menu records, applying alignment and selected/disabled
text colors. The loop uses a short control index and a byte-displacement cursor
for 188-byte records. Each access resolves against the current array after
formatting. The formatter retains its established int-parameter ABI.

The source owns all 32 scalar bytes at 8037AED8..8037AEF8, including four
natural double-alignment bytes. All 23 old references to the six scalars occur
inside this renderer. The original data scan found no external pointers into
the pool. Three former source owners are retired from the active graph, with
their source files and historical receipts preserved. New data credit is zero.

The complete compiler object has 42 retained relocations, eight unused weak
relocations and three category entries. Its two weak destructors (88 and
84 bytes) are unreferenced duplicates discarded by the native linker. The
existing GLOBAL providers (116 and 112 bytes) remain selected and unchanged;
their different exception-enabled bodies are not claimed equivalent to the
unused definitions. No allocated exception metadata is emitted.

The original input also contained `fn_80219AC8`, a 2,168-byte adjacent function.
Normal splitting preserves that complete function in an original object. The
new source covers only the renderer and its scalar pool.

The immutable package is
`scratch/resource_finder_inline_20261020/menu_engine_renderer_80219510/`.
`scratch/menu_renderer_integration_20261020/verify_production.py --linked`
checks the complete object inventory, actual relocations, native local symbols,
weak discard, unique strong providers and original adjacent function. The
standard and mapped ELF outputs are identical, and the original DOL hash,
`ninja changes`, source extent audit and all 66 tests pass.
