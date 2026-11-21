# Native owner hook and virtual-method groups

Verified against the unchanged GSQE78 executable on 2026-10-12. These are
partial ABI views, not recovered complete original class declarations or TUs.
The production link retains the original full vtables and unused functions.

`src/Game/leaf_80028134.cpp` replaces the earlier four-byte empty C leaf with
an empty virtual member and the compiler's genuine eight-byte adjustment
thunk. The secondary base begins at `0x318`. The original primary method keeps
its GLOBAL binding; the native thunk is WEAK. The original destructor thunk
at `80028140`, destructor at `80027A08` and 396-byte vtable at `802B074C`
remain external. The emitted 32-byte partial table and unused eight-byte
view-destructor thunk are discarded and earn no source credit. The existing
build-unit name stays `Game/leaf_80028134.c`; its source override has the same
basename with `.cpp` so the compiler dependency/output names agree.

Two larger groups recover the same genuine C++ adjustment mechanism:

| Source stem | Owned text | Preserved text | New thunk text | Owned extab / index |
| --- | --- | ---: | ---: | ---: |
| `agent_owner_virtual_methods_80062A14` | `80062A14..80062D98` | 740 | 160 | 116 / 120 |
| `agent_controller_virtual_methods_80064458` | `80064458..80064694` | 484 | 88 | 56 / 84 |
| `agent_cleanup_virtual_methods_8006565C` | `800656AC..800658D0` | 524 | 24 | 112 / 96 |
| `agent_cleanup_virtual_methods_8006590C` | `80065960..80065C24` | 684 | 24 | 112 / 96 |
| `agent_cleanup_virtual_methods_80065C60` | `80065CB0..80065ED4` | 524 | 24 | 112 / 96 |

The three cleanup groups supersede the intermediate derived-method groups;
all retired source files remain preserved. Shared class views in
`include/Game/agent_cleanup_virtual_view_*.h` let the three original lifetime
callers invoke the real qualified member. All caller instructions and exception
records remain exact. The replacement groups preserve existing cleanup, bind
and virtual-method code while adding authentic adjustment thunks.

These groups consolidate earlier source units without deleting functions or
owned ranges. Previously matched text remains exact. Compiler-emitted partial vtables, unused
thunks and weak handle-destructor backups are inspected in the raw objects;
they do not replace original data or existing strong providers. Every retained
function has its original address, extent and GLOBAL/WEAK binding. Local
exception-record names now agree with compiler identities. This also corrects
56 previously unmatched data bytes in the first group's already source-owned
exception records; these are not 56 newly reconstructed data bytes.

Six further hook pairs add eight bytes each at `800949D0`, `8009651C`,
`8009A9C8`, `800CCEDC`, `800E12F0` and `800E31C8`. The `800E12EC` view uses
secondary-base offset `0x168`; the others use `0x318`. Existing primary methods,
unit identities and adjacent C leaves remain exact. Original following
destructor thunks and complete vtables remain external. Each raw object has
one 32-byte partial table and one unused destructor thunk; both are absent
from the production ELF. The six pairs add 48 bytes, preserving 24 primary
method bytes and 24 neighboring leaf bytes.

`owner_cleanup_virtual_methods_8009A8AC.cpp` owns `8009A8AC..8009A9D8`
(300 text bytes), 72 extab bytes and 60 index bytes. Its shared view in
`include/Game/owner_cleanup_virtual_view_8009A8AC.h` preserves the native
cleanup signature, returned object and low-16-bit delete flag. The existing
`engine_small_eh_80098A70.cpp` caller uses the qualified member with identical
code and metadata. This group absorbs the previous `8009A9C4` hook pair,
preserves its eight-byte thunk and adds another eight-byte cleanup thunk.
The empty-hook receipt explicitly maps its absorbed pair into this owner;
historical receipts must not be summed as disjoint progress.

All groups use GC/1.3.2 with `-O4,s`, automatic inlining, C++ exceptions enabled,
RTTI disabled and the native load/store-multiple option. No assembly,
relocation masking, branch-byte copying or symbol aliasing creates these
matches. Compiler-generated relocations are retained and resolved normally.

Evidence is under `scratch/continuation_20261012_b/`:
`check_mi_hook.py`, `check_mi_groups.py`, `check_mi_empty.py` and their native
proof JSON files verify complete raw allocation/symbol/relocation inventories,
retained native code and exception records, discarded helpers and unchanged
complete tables. Original-table consumers and isolated fixtures are preserved
under `scratch/literal_group_20261012_b/`. Original null/alignment bytes outside
native ELF metadata sections remain covered by the complete DOL hash check.

The complete DOL hash and baseline regression checks pass after integration.
These units recover 384 new code bytes across 48 authentic thunks. Full class
layouts, original TU boundaries and the remaining original code/data still
require reconstruction.
