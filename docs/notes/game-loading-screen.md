# Loading-screen resource methods

`src/Game/loading_screen.cpp` recovers the contiguous methods at
`0x800C5BB0..0x800C5EC8`: 792 code bytes and 232 exception-table/index bytes.
The first method delegates the base mark test and marks the resolved resource.
The second creates the `LoadingScreen` resource lazily, initializes it, assigns
its owner handle, and registers it with the renderer's observed subobject.
The source's feature and layout names are reconstructed; the original complete
class identity and translation-unit extent are not claimed.

The lazy lookup returns a genuine four-byte nontrivial native handle by value.
Ordinary typed conversions and assignments reproduce all reference-count calls,
temporary lifetimes and cleanup flags. The identity field at owner offset four
is exposed by an inline accessor returning `const HandleRef&`. Passing the
member directly causes the compiler to rematerialize that address after the
native constructor, removing one instruction. The reference-returning accessor
preserves the original r29 pointer across construction, value load and retain.
No source-level instruction substitutes or forced register placement are used.

GC/1.3.2 with `-O4,s -inline auto`, exceptions enabled and the complete flags in
the manifest produces exact retained code and exception metadata. The compiler
also emits six weak typed-handle destructors already present elsewhere in the
original program. Every instruction and exception record of these duplicates
matches its canonical original, and they receive no additional matching credit.
All allocated object bytes, alignment, symbol extents and relocations are
checked, including those duplicate bodies.

```
python3 scratch/game_loading_screen/verify.py src/Game/loading_screen.cpp
```

The strict isolated check passes 52 retained relocations, protected original
DOL SHA-1, both methods and all emitted metadata. The integrated methods pass full-DOL byte equality, native objdiff checks
and the original-source regression audit. Shared globals and the original `LoadingScreen` string
remain external.

The preceding setup method at `0x800C59E8..0x800C5BB0` and its base helper at `0x800C58F8..0x800C59E8` are now verified source; see [setup](game-loading-screen-setup.md) and [base setup](game-loading-screen-base-setup.md).
It clears two globals, delegates initialization, and constructs/destroys two
scoped event-like objects with 0x58-byte layouts. It is outside this candidate.
