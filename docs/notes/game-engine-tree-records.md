# Engine transform and group records

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Two complete ordinary C++ functions form this text-only handoff, using the
standard Game GC/1.3.2 flags without additions:

| Source | Complete text | Bytes |
| --- | --- | ---: |
| `src/Game/engine_tree_orientation.cpp` | `8023D120..8023D258` | 312 |
| `src/Game/engine_tree_group.cpp` | `8023DE28..8023DEF8` | 208 |

The two functions require global scope and total 520 text bytes with no owned
data. Their dedicated declarations are in `include/Game/engine_tree_records.h`.
The packed parent handle at offset 0xC carries a signed 8-bit generation and
signed 24-bit index. Resolution uses the original context's manager at 0x118,
its entry pointer at 8, and 16-byte entries with object pointer at 0 and signed
generation byte at 0xC.

`fn_8023D120` first calls the existing position update `fn_8023D258`. It resolves
the parent and refreshes its cached transposed 3-by-3 basis at 0x54 when flag
0x40 is set, using `fn_801F2124` on its basis at 0x30 and then clearing the flag.
The existing matching `src/Game/matrix3.cpp` establishes that operation's
transpose semantics. The routine copies that matrix into a local value,
converts the input quaternion using `fn_801F1CD8`, multiplies the two matrices
using `fn_801F223C`, converts back using `fn_801F20F4`, and stores four components
at 0xC8..0xD4. Ordinary structure assignment preserves all nine native word
copies and the original local layout.

`fn_8023DE28` reads the group index at 0x134. Index -1 yields a null group;
otherwise it resolves a packed handle from the original context's table at
0x11C, whose handle array is at offset 8. It separately resolves the parent and
passes the owner, group object, and parent to the existing `fn_8023D9B8`.

The strict manifest `scratch/engine_tree_records_20261010i/final_integration.json`
records complete bounds, compiler options, symbol bindings, and all 12 actual
REL24/HA/LO relocations. `freeze.py` compiles the production sources and builds
the manifest from strict comparisons; `verify.py` independently recompiles and
checks every relocated byte against the original DOL without masking. It rejects
additional functions and unexpected allocated sections. Both it and `audit.py`
pass. The original assembly confirms both full extents. All 3,141 original
extabindex entries, 24 ctor entries, and 8 dtor entries were scanned; none refer
into the selected text. Source data, BSS, startup, and exception ownership are
all zero. The original context, matrices, tables, neighboring routines, and all
original translation-unit data retain their existing owners. This split does
not claim to recover an original whole translation unit.

Private probes of `fn_8023CEC4`/`fn_8023CFE4` (scale), `fn_8023D258` (position),
`fn_8023D66C` (typed handle traversal), and `fn_8023BD78` (triple-handle setup)
still differ and earn no matching-source credit. The traversal probe verifies
its switch, recursive propagation, and handle counter semantics, but retains
register and helper-inlining differences. Some inline variants emit additional
helpers, which the production strict checks would reject. All research variants
and their results are preserved. Only the two complete functions above are
included in this handoff; central NonMatching registration, whole DOL hash and
native regression acceptance remain the integrator's promotion steps.
