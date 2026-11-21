# Box corner connectivity at 802EA9B0

`src/Game/geometry_box_topology_data_802EA9B0.cpp` reconstructs twelve typed edge-index pairs and six typed face-index quads for the eight native box corners. All entries are ordinary corner indices 0..7. The complete `.data` allocation is 192 bytes with natural alignment 8, matching the protected original DOL exactly, with no relocations, padding, helpers, text, BSS, EH or startup data.

Existing positive GLOBAL identities are unchanged: `lbl_802EA9B0`/96 at 802EA9B0 and `lbl_802EAA10`/96 at 802EAA10. Compile with GC/1.3.2 and the normal Gekko/O4,p flags recorded in the owned manifest. Preserve the preceding original 64-byte object at 802EA970 and the following original data at 802EAA70.

The independent original initialized-data pointer census scans every byte offset, including unaligned locations: 501,416 positions, zero pointers into these two arrays. Five native absolute code-address materializations reference them. This data-only partial split leaves all geometry functions external until independently exact; no instruction credit is claimed.

Frozen evidence is in `scratch/game_frontier_20261012_b/geometry_box_topology_data_802EA9B0.o` and `.owned.json`. Reproduce with `audit_box_topology_data.py`. Current `main.elf` was observed during concurrent integration and has transient shifted addresses; its observed GLOBAL binding/96-byte extents are recorded separately. Isolated bytes and canonical addresses come from the protected original DOL and original symbol map. The integrator must verify final native GLOBAL placements and the original full DOL hash before promotion.

The related private `geometry_box_identity64.cpp` reconstructs the 1,156-byte box collision query with 19 remaining GPR-assignment differences. Its fourth argument is one 64-bit identity in EABI r7/r8, with r6 skipped for alignment; the output identity occupies 0x28..0x30. Its matrix helper needs an ordinary local Vec3 with component assignments before returning by value; this recovers all native FPR/load scheduling. The three remaining register lifetimes belong to result, face-table base and first-point cursor. It remains uncredited research.

The complete data fragment is now linked from Matching source. The original
DOL hash and native GLOBAL allocations pass, with no regression and complete
original section coverage. Acceptance logs are
`scratch/continuation_20261012_b/build-record-child-promote.log` and
`changes-record-child-promote.log`; source extents and all 66 tests pass.
