# Render-owner initialization

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

`src/Game/render_owner_init.cpp` reconstructs `fn_80275A44`, original `.text`
range `80275A44..80275AF4` (176 bytes). This ordinary C++ reconstruction
is an isolated exact match awaiting central integration.

The partial owner calls its original base initializer, installs the original table at offset 0x278, and invokes __construct_array for three and 128 twelve-byte buffer descriptors at offsets 0x3B4 and 0x3D8. It zeros the observed pointer, size and flag fields plus two external small-BSS words, then sets the active byte at offset 0xA00. The initializer and destructor function pointers remain externally owned.

Run `python3 scratch/game_render_owner_init/verify.py`. Standard optimized GC/1.3.2 Game
flags reproduce all 176 emitted text bytes, the original global symbol and
15 actual relocations. The verifier checks every allocated byte,
exact relocation site/kind/symbol/addend and original symbol target. SDA21
relocations select r2 or r13 from the original symbol's small-data section and
apply the verified anchors 0x803801C0 or 0x8037BE40 with a signed sixteen-bit
range check. The resulting instructions, not masked relocations, match the
protected original DOL.

No weak helpers, other allocated sections, initialized data, BSS or padding
are emitted. External constants and small-BSS storage retain original ownership.
Candidate, actual-relocation and original-metadata JSON preserve all exact
hashes, dependencies and evidence. The original extabindex, `.ctors` and
`.dtors` audit finds no overlapping exception entry or table reference into
the retained range. Other native functions, original tables and neighboring
code remain externally owned. This is a partial text-only split. Central
integration must still pass complete DOL hash, native objdiff, source-extent
and regression checks; no new symbols, owned data or special flags are needed.
