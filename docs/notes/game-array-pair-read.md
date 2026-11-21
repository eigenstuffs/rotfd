# Two dynamic arrays from a serialized stream

`src/Game/array_pair_read.cpp` reconstructs the 768-byte `fn_8026DFD8` at
`8026DFD8..8026E2D8`. It invokes the base reader, reads a count, resizes the
16-byte-element array at offset `EC`, and copies its serialized payload. It
then reads another count, resizes the four-byte-element array at offset `F8`,
copies that payload, and writes the updated cursor back to the stream.

The array implementation retains native allocation/reallocation/free behavior
for both growth and shrinkage. Its records have empty constructors and
destructors, preserving the observed empty counter loops. An integer-word
cursor with post-increment reproduces the original early cursor advance, and
one count variable is reused for both arrays to recover register allocation.
The source uses ordinary C++ loops, placement construction and destruction.

GC/1.3.2 with standard optimized Game flags reproduces all 768 emitted bytes
after all 39 actual relocations are applied. Run:

```
python3 scratch/game_array_pair_read/verify.py
```

The complete object contains just the 768-byte text function and one global
symbol, with no weak functions, constants, data, BSS, constructor/destructor
tables, exception tables or padding. Allocator state remains external. Original
references are calls, with no constructor entry or owned data to transfer.
This partial text split leaves adjacent functions and original data in their
existing ownership; no original translation-unit boundary is claimed.

`candidate.json` and `actual_relocations.json` preserve the isolated evidence.
Full executable acceptance passed: the rebuilt DOL has the original SHA-1,
`ninja changes` reports no regressions, and source-extent/progress audits pass.
All 26 unit tests pass. Any emitted unlinked weak helpers are absent from the
final ELF and receive no matching credit.
