# Platform draw-dispatch wrapper

`src/Game/platform_draw_dispatch.cpp` owns `.text 0x80284D80..0x80284DB0`,
**48 bytes / one function**, with no data or relocations. It passes its two
arguments and the owner's offset-`B0` storage address to virtual slot `60`.
A bounded derived declaration adds slots `5C/60` to the previously verified
draw-owner interface without changing the shared base layout or table.

The source object matches all 12 native instructions. It emits no vtable,
weak function or unrelated section. The earlier 1,256-byte trig unit remains
exact after moving lookup-array declarations into their shared ownership header.
The larger preceding renderers remain original and uncredited; this partial
split is not a claim of a recovered original translation unit.

Acceptance: `scratch/game_platform_draw_dispatch/verify.py --production`,
`scratch/platform_draw_dispatch_link_proof.json`,
`scratch/platform_draw_tables_build.log`,
`scratch/platform_draw_tables_changes.log`,
`scratch/platform_draw_tables_tests.log` and
`scratch/platform_draw_tables_checkpoint.json`. The full DOL is byte-identical,
all 690 source units remain fully matched, all 23 tests pass, and the initial
baseline is unchanged. Native source/data extents and source-assembly audits pass.
