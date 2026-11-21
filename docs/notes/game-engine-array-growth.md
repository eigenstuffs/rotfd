# Engine array allocation, append, and pair initialization

The frozen handoff in `scratch/engine_array_growth_20261010y/` reconstructs
three complete ordinary C functions, totaling 784 text bytes and no data.
All use GC/1.3.2 and the standard game flags, with no extra compiler flags.

| Source | Original text | Bytes | Behavior |
| --- | --- | ---: | --- |
| `engine_array_growth.c` | `8023F668..8023F704` | 156 | Resize backing storage for four-byte entries without changing the capacity field. |
| `engine_array_append_168.c` | `80225C58..80225D44` | 236 | Grow a 168-byte entry array by one when full, construct an appended entry, and return its index. |
| `engine_array_pair_init.c` | `8020C744..8020C8CC` | 392 | Initialize two arrays, reserve two 140-byte entries, and obtain the initial three-short range. |

The constructor's `fn_8020C8CC` call returns a six-byte aggregate in r3/r4.
Declaring a three-short C structure reproduces this ABI directly. Copying
its individual fields reproduces the original temporary and signed loads.
The original float constants must be declared `const` to preserve the load
scheduling. Empty construction/destruction loops reflect trivial element
lifecycle operations and reproduce the original counted loops.

`freeze.py` compiles the production files and verifies every original byte
after applying all 36 actual relocations. `verify.py` independently recompiles
the frozen source and rejects unexpected functions, allocated sections, or
section extents. Both passed. `audit.py` checked the complete original
function extents, all 3,141 extabindex entries, 24 constructor entries, and
eight destructor entries; none references the selected functions. These
sources own only their listed text ranges. The original allocator objects,
vtable, float constants, adjacent functions, and all other original ranges
remain with their existing owners. This is a partial text split, not a claim
to recover an entire original translation unit.

The adjacent range builder `fn_8020C8CC` remains private research. Its best
316-byte ordinary C probe has 18 register differences, so it is excluded
from the integration manifest and receives no matching credit. All probes
and results are preserved.

Integration inputs are `final_integration.json`, `final_splits.txt`,
`final_config.txt`, `scope_edits.txt`, and `ownership_audit.json`. Register
the three source files as NonMatching, confirm the native comparison, and
promote only after the full original DOL hash and regression checks pass.
No central configuration, original input, expected hash, or generated
progress file was changed by this handoff.

The original 168-byte record copy callee at `80225D44` now has a matching
native C++ copy constructor. Its declaration and append call use
`__ct__19BitNativeCopyRecordFRC19BitNativeCopyRecord`; all three consumers of
this header retain their exact original bytes. The source/header and manifest
history is preserved under
`scratch/continuation_20261010/record-copy-fixed-vectors-caller-history/`.
