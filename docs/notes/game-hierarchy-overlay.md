# Hierarchy position overlay at 80203D98

Status: bounded near match, not eligible for code or data credit. The private reconstruction is `scratch/game_hierarchy_overlay/overlay.cpp`; no production source or exact candidate has been promoted. The original range is `80203D98..80204000` (616 bytes).

The method checks bit 3 of the global flags at `lbl_801E9D24 + 104`. It obtains the renderer at the context's `+48`, initializes four vertical line offsets, and visits the group's hierarchy handles. Hierarchies with nonnegative `+E4` contribute valid secondary members from the array at `+B0`, bounded by `+DC`. Each member supplies a view index through vtable offset `+A0`; values outside zero through three select view zero. The method gets the view rectangle, increments that view's line offset by ten, formats the associated transform's three position floats, and invokes the renderer's virtual draw method at `+90` with the computed two-dimensional position and original color.

The private view preserves renderer vptr offset `278`, 76-byte view records, native 8-bit generation/24-bit signed index handle resolution, component transform handle `+58`, and position floats at `+B8/+BC/+C0`. The original format string `lbl_802AD970` and color `lbl_8033E738` remain external.

GC/1.3.2 with the adjacent accepted game flags produces the exact 616-byte size and 240-byte stack frame. Applying all 12 genuine ELF relocations leaves 14 differing bytes in 13 instructions. Every discrepancy is a register assignment: the reconstructed renderer occupies r26 instead of original r28, while the two derived loop offsets occupy r27/r28 instead of original r26/r27. The remaining instructions, branch targets, stack offsets, call targets and float operations agree. The strict verifier fails with status 1 and writes `scratch/game_hierarchy_overlay/mismatch_report.json`; it does not generate an accepted candidate or source credit.

Two ordinary source details materially improved the reconstruction: initializing the four offsets with a loop produces the original single scalar load and four stores, while an inline two-float position constructor preserves the original argument evaluation and float conversion temporaries. The initial aggregate initializer emitted an unrelated 16-byte template and 20 excess code bytes; that variant is preserved only as `overlay_initial.cpp`. The best 14-byte state is also saved as `overlay_14byte_near.cpp`. Bounded checks of renderer/list accessors, loop-variable scopes and int/long types, typed handle resolution, and a drawing helper did not resolve the register assignment. No compiler-flag sweep, register binding, assembly substitution or byte masking was used.

The numeric constants have precise separate ownership:

| Original address | Value | Original direct SDA2 consumers | Proposed ownership if code becomes exact |
| --- | --- | --- | --- |
| `8037A928` | 0.0f | `80203DC0`, `802046E8`, `80204A5C` | External named original constant |
| `8037A92C` | 10.0f | `80203EE8` | External named original constant |
| `8037A930..8037A938` | signed integer conversion bias | `80203F08` | Eight genuine compiler-emitted bytes |

The shared floats are declared as ordinary external named constants. Only the normal integer-to-float bias is emitted in this probe's `.sdata2`, aligned to eight bytes, and all eight bytes exactly match the original. No padding is emitted. Because the code remains unmatched, these eight data bytes are also uncredited. `literal_consumers.py` verifies the original DOL hash, scans every original text section for direct SDA2 users, rejects aligned absolute pointers to these constants, and checks that equal-low-half address instructions are solely unrelated SDA accesses rather than ordinary absolute address construction/load/store. This includes the newly integrated selection-parameters consumer at `80204A5C`.

Run `python3 scratch/game_hierarchy_overlay/literal_consumers.py` for the passing consumer inventory, and `python3 scratch/game_hierarchy_overlay/verify.py` for the deliberately failing strict byte comparison. The latter checks all retained sections and records the zero-difference eight-byte constant result separately from the 14-byte code discrepancy. Existing production sources, shared headers and central configuration were not changed.
