# Scene mode selection

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`scene_mode_selection.cpp` reconstructs original `fn_800C4984` at
`800C4984..800C4A74`: 240 code bytes and the complete 8-byte exception record
and 12-byte exception index. It selects mode 10 for category 4 in states 0/1,
otherwise mode 1, applies the owner value at `8C`, stores the resolved returned
Handle at `78`, then forwards to the existing base operation.

The original callee `8005863C` receives a hidden return pointer and initializes
a four-byte typed Handle through the native base constructor and reference
manager. The caller consumes that temporary directly. An ordinary derived
Handle view and inline `get()` preserve its lifetime: the pointer is stored
before destruction of the base subobject with flag 0. A named base Handle
local instead introduces a slicing copy and additional cleanup; that earlier
probe is preserved without credit. The view does not claim the original
template argument name or reconstruct the callee's constructor hierarchy.

The compiler also emits an unused 76-byte destructor plus 20 exception/index
bytes. All allocations and real relocations are frozen under the existing
strict weak-EH gate with an empty strong-override list. No retained reference
targets the backup. Those bytes receive no credit and must be discarded in
the production native link. The complete original exception/startup tables,
initialized pointers and source consumers are inventoried in
`scratch/game_scene_mode_selection/`; borrowed context and callee definitions
retain their existing owners. This is a partial original translation unit.

Full native integration passed, including complete backup code/EH/index discard.
