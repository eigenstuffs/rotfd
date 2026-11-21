# Callback typed-handle assignment

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Five complete functions in five text splits reconstruct 1,124 retained bytes.
Ordinary C++ handle layers express native initialization, two inherited zero
stores, copied-word ownership, and scoped cleanup. The base destructor calls
the original native destructor with flag zero; native returned lookup values
are separately destroyed with flag minus one. Prefixes describe observed
storage and methods without claiming original template or class identities.

`80255140` (180) constructs an owned copy of its incoming handle, releases the
receiver's handle at `+64`, copies the token, retains it, and cleans up the
copy. `80255750` (236) looks up the original named handle when state bit `800`
is set and performs the same assignment. `8025A3C8` (196) assigns handle `+70`
and then sets 64-bit state mask `400000`; adjacent `8025A48C` (256) performs
original setup and a named lookup before the same scoped assignment when
state bit one is set. `8025C3B4` (256) invokes virtual slot `28` with zero and
conditionally performs named assignment at `+60` when state bit `400` is set.

Each source object additionally emits four unused weak destructors of 96, 92,
88 and 84 bytes. These 360 bytes per object are outside the retained split and
receive no matching credit. Manifests enumerate every weak extent, raw byte
hash and its eight actual relocations, and prove retained code/data never
references them. Final-link acceptance must prove all four compiler symbols
absent. No original native function is replaced by these unused helpers.

`scratch/game_callback_typed_assignment/verify.py` recompiles final source,
checks all retained bytes with actual relocations, complete global function
extents, every emitted allocation and all weak-helper accounting. There is no
source data, BSS, exception metadata or padding. Full original-table ownership,
production object, original-DOL hash and baseline regression acceptance remain
required. The earlier explicit-cleanup probe coalesces its temporary pointer
and remains private; automatic ordinary C++ lifetime preserves native code.

A combined A3C8/A48C probe reordered the strong functions around the weak
destructors and is retained under `failed-grouped-A3C8.cpp`. The final
functions use separate bounded compilation units to preserve original order.
