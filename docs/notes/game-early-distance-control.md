# Early distance controller — reset and gates

Frozen isolated ordinary C++ reconstructions, 2026-10-11. Central integration remains pending. Three independent units share the new `include/Game/early_distance_control_views.h`; no existing header was changed.

| Source | Function | Text extent | Text bytes | extab | extabindex |
| --- | --- | --- | ---: | --- | --- |
| early_distance_update_80063a30.cpp | fn_80063A30 | 80063A30..80063B14 | 228 | 8000B70C..8000B714 | 800186CC..800186D8 |
| early_distance_check_80063b14.cpp | fn_80063B14 | 80063B14..80063BDC | 200 | 8000B714..8000B71C | 800186D8..800186E4 |
| early_distance_reset_80063074.cpp | fn_80063074 | 80063074..8006311C | 168 | 8000B5F4..8000B5FC | 8001869C..800186A8 |

All use standard GC1.3.2 plus `-O4,s` and `-Cpp_exceptions on`. Combined: **596 text +60 EH/index =656 allocated bytes**, sixteen text relocations, six EH/index relocations, and three nonallocated compiler metadata references. Each compiler object emits exactly one function and its original eight-byte EH/twelve-byte index pair; no weak helpers, data, BSS or padding are claimed.

Both gates get the current owner's generation-tagged resource and query fn_80066BC8 with the embedded script/controller region at 0x90. The update invokes fn_8025A244 when distance exceeds threshold@D8 or mode@D5 equals one. In that branch oneShot@1E3 equal to one sets active@1E2. When mode is zero, active equal to one or distance <= the existing lbl_80378700 triggers fn_8025A190. The check variant does nothing unless mode is zero, prioritizes that active/low-distance condition, and otherwise invokes the high-distance callback. Floating comparisons retain the native ordered/NaN behavior.

Mode is an unsigned byte; active and oneShot are signed bytes. Signed declarations reproduce the original equality comparisons without requiring explicit sign-extension instructions. All three functions match with the same concrete layout.

Reset clears bit eight in the low word of the 64-bit flags at 0x38, invokes fn_8002B780 and resets the embedded region through fn_8005E66C. Genuine virtual methods at table offsets 0x5C and 0x60 receive 0x85; the virtual at 0x160 receives two zeroes. It sets enabled@1F8 to one. The partial class view has its original eight-byte prefix before the native vtable pointer.

Manifest list: `scratch/game_early_distance_control/manifest-list.json`. Each per-function `verify.py` recompiles production source, verifies all allocated original bytes after real relocations, checks actual ELF local object names/extents, and audits the complete original extabindex/ctors/dtors tables. Only the corresponding retained EH entry is owned; no ctor/dtor-table entries target these ranges. Original SHA1 remains `5da8295a79bf297ab62c620e6ac66210be1c6ef5`. All production sources, shared view, strict emission references, manifests and evidence are frozen for root integration.
