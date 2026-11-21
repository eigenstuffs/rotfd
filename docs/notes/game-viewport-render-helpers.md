# Viewport render entry and callback-handle helpers

`src/Game/viewport_render_helpers.cpp` owns two routines in
`801E8A88..801E8B10`, totaling 136 matching code bytes. The native
`ViewEntry_801E8A88` default constructor initializes the sphere of a 32-byte
render entry from the existing zero vector and original radius constant.
The remaining entry fields are not initialized here. `fn_801E8AB0` returns
a retained copy of the handle at world offset `C164`.

The shared header records only the layouts needed by these helpers. Their
original vector and radius data remain external; this partial text split
claims no data. The strict production proof applies all seven actual
relocations, including SDA21 against the verified R2 anchor. The object
emits exactly 136 text bytes and no weak helpers or allocated data.

The adjacent 2,068-byte render-preparation routine at `801E8274` remains
original and uncredited. Its preserved private implementation in
`scratch/game_viewport_render/near49.cpp` has the correct size and 49
instruction differences, all currently involving floating-point register
allocation. It includes camera resolution, lazy inverse matrices, entry
culling, world bounds, render dispatch and transformed line drawing. Those
findings do not establish a source match; actual relocated equality is
still required before integration.

Evidence: `scratch/game_viewport_render_helpers/verify.py`,
`scratch/viewport_render_helpers_link_proof.json`, and
`scratch/viewport_render_helpers_checkpoint.json`. At that checkpoint all
663 source units were exact, the DOL was byte-identical, all 23 tests and
progress/extent/assembly audits passed, and the original baseline was
unchanged.
