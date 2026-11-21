# Menu color setup

Integrated on 2026-09-27. Two text-only sources recover the 260-byte routines
at `8021693C..80216A40` (Menu2D) and `80219060..80219164` (Menu3D).
Each has four actual relocations and no other allocated output.

Both call their derived preparation routine followed by the common menu routine
at `8021D51C`, preserving the incoming second argument. They multiply the
start, end, selected-start, selected-end and grey RGB triples by 0.5, then set
the grey alpha to 1.0. The inline three-component setter evaluates all three
products before storing them, matching the original load/store scheduling.
Menu2D's additional alternate-color group remains untouched by this routine.
The shared header is an offset-based storage view, not a recovered original
class declaration. All float constants remain in their original owners.

`python3 scratch/game_menu_color_setup/verify.py --production` verifies all
520 code bytes and eight relocations. The full rebuild is byte-identical,
all 630 source units match, the baseline and previous source files are unchanged,
and all 23 tests, progress checks and source audits pass.
`scratch/menu_color_setup_checkpoint.json` records acceptance.
