# Seeded random-number generation

Five C++ functions at `0x801F1184..0x801F14E0` reproduce 860 game code bytes.
They accept a seed from the console, return a random fraction, choose an
inclusive integer interval, accept an explicit seed directly, and advance the
generator. The former settings-object view is the console reached through
`lbl_801E9D24 + 0x110`; see [console argument layout](console-argument-layout.md).
The command method at `0x801F1184` preserves the original `argc >= 1` guard
and requires nonzero `numeric[1]` at `0x8A5`, then converts `values[1]` at
`0x8B8` to the seed. `argc` includes the command token; the weaker count guard
is preserved exactly. The numeric flag records successful parsing, including
`TRUE`/`On` and `FALSE`/`Off`, rather than whether the seed is nonzero.

The generator advances a multiplicative recurrence with multiplier 16807,
modulus 2147483647 and quotient/remainder constants 127773 and 2836. A 32-entry
shuffle table follows forty initialization advances. It scales the selected
integer into a floating-point fraction and caps the result below one.

Signed `long` state, quotient and shuffle entries are required. They are
32-bit on this target, but substituting `int` changes the compiler's redundant
load elimination and removes an instruction. The original one-byte signed
initialization guard is retained explicitly in C++, with the same first-use
zeroing and exact instructions. The negative
seed convention uses an ordinary comparison; the compiler's branchless
absolute-value intrinsic produces different instructions.

`random_state.c` owns the 128-byte table at `0x80340B80` and twelve bytes of
state and guard storage at `0x80377FD8`. Separating storage from the code
allows the original math globals to precede the random state in BSS even
though their initialization code follows the random functions. Both objects
retain every original byte; `scratch/game_random/verify_state.py` checks the
four state objects, sizes and alignment.

`random.cpp` owns a 52-byte shared constant pool at `0x8037A6E0`.
The first 28 bytes serve the generator; six named floats at
`0x8037A6FC..0x8037A714` serve the scalar math routines. The compiler emits
these definitions after the random-number constants in the same object,
preserving the original eight-byte section alignment. Separating the latter
constants into a new object would insert four bytes of unwanted alignment.
The four bytes following the state remain outside this split. Surrounding
paired-single math routines remain fallback code.

GC/1.3.2 with ordinary scalar-save game flags matches all instructions,
constants and relocations. `scratch/game_random/verify.py` checks these
extents before integration; the candidate manifest records the full DOL and
native objdiff acceptance result.
