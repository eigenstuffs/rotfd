# Timed handle owner initialization

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

`src/Game/timed_handle_init.cpp` reconstructs `fn_802617F8`, original `.text`
range `802617F8..80261870` (120 bytes), as ordinary C++.

The initializer constructs the existing native handle, assigns a local empty
handle through the existing refcount helper, destroys that local and initializes
two words and two floats. The local handle retains the native generation/index
bitfield operations; float values use externally owned small-data constants.
The provisional timed-owner name describes its two scalar fields and does not
claim recovered original class/file names.

Run `python3 scratch/game_timed_handle_init/verify.py`. Standard optimized
GC/1.3.2 Game flags reproduce all allocated bytes, the exact function extent and
all actual relocation sites, kinds, symbols, addends and targets, including
SDA21 bases/displacements. Relocated instructions are compared against the
protected original DOL. No weak helpers, owned data, BSS, padding or other
allocated sections are emitted. Original extabindex, `.ctors` and `.dtors`
audits find no overlap or reference into this range. Candidate, relocation and
original-metadata JSON preserve hashes and dependencies.

This partial text-only split leaves neighboring functions and data external.
Central integration must pass the full DOL hash, native objdiff, source-extent
and regression checks. No new symbols, shared headers or special flags are
needed.
