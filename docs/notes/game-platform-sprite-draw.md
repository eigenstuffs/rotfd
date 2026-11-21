# Platform sprite display-list research — uncredited

The next draw candidate is `fn_80283160`, `.text
0x80283160..0x80283954`, **2,036 native bytes**. It remains original code in the
matching build. Private ordinary C++ probes and full relocation diagnostics
are preserved in `scratch/game_platform_sprite_draw/`; no probe bytes are
counted as source completion.

Assembly establishes these views:

- Owner: vertex-record key at `20`, group count at `24`, group pointer at `2C`,
  link-record key at `34`. Groups have stride `14`, signed head/count at `10/12`.
- Vertex: stride `8C`, facing fields `0C/14`, angle `20`, RGBA floats `64..70`,
  position `74..7C`, dimensions `80/84`, next signed link index `8A`.
- Input: renderer at `0`, camera at `8`, transform at `C`, material resource
  at `10`, culling mask at `1C`, depth-sort fields `A8/AC`.
- Draw state: flag/mask at `2D0/2D2`, display-list pointer/count at `9E4/9E8`.
  Display-list entries contain a pointer, capacity and used size (12 bytes).
- Transform: dirty flags `120`, source pointer `124`, matrix pointer `128`,
  signed matrix-bank slot `12E`. Global matrix-bank owner is at `134`; its
  active bank byte is at `18`. The copied local matrix has 16 float words.

The renderer retrieves the vertex record, reactivates the link record and
moves one reserved link into its used chain when required. It resolves two
manager handles using signed 24-bit indices and signed 8-bit generations,
prepares render state and ambient color, updates a dirty transform, and chooses
billboard/default axes from the sprite flags. It allocates a 32-byte-aligned
GX display list using `(groupCount * 99 * firstGroupCount + 63) & ~31`.

For each visible group it follows signed vertex links, calls the now-matching
sine/cosine interpolators, computes transformed positions, skips the native
nonnegative/unordered depth cases, emits four rotated corners with RGBA and
texture coordinates to the write-gather pipe, closes/stores the list, and
submits it with the sum of the input depth-sort fields. The native `bge` after
an ordered floating-point comparison tests the absence of the less-than bit;
`!(z < zero)` preserves its unordered behavior, whereas plain `z >= zero`
produces an additional CR instruction and different NaN handling.

The first vertex-key call stores two stack copies, while the link-key call
stores one. A non-POD `PlatformRecordIndex` passed by value, with an inlined
by-value getter on the first path, reproduces these copies in a private probe.
The existing accepted accessors use reference declarations with identical
callee machine ABI. Shared declarations should be reconciled and all affected
units strictly rechecked when the caller is ready for integration.

The initial probe has the original 2,036-byte size but extensive instruction
differences. Later probes explore typed link-record views, explicit vector
operators, separate floating-point products and reference-based output.
Diagnostic volatile-field variants investigate the native retained facing
comparisons; volatility is not established as an original declaration.
The backend `ppc_unroll_instructions_limit 0` pragma preserves the native
four-corner loop. An uninitialized three-float array with component assignment
and reference-based position output reproduces the native partial-vector stores
at stack `24/28/2C`. Reference-based texture output reproduces sequential
load/write pairs. The established manager getter shape reloads the entry base
on the second resolution, and moving state/bounds setup before object resolution
recovers native scheduling. Signed-byte color locals reproduce the four unsigned
narrowing instructions before the corner loop. Late signed-byte casts on the
flag tests recover the native flag-conversion pattern.

A signed-byte/integer return from the inlined facing comparison member retains
both native floating comparisons; a `bool` return drops the final comparison.
The diagnostic volatile fields remain necessary in these probes, so the original
declaration is still uncertain. Separating the initial group-array pointer from
the advancing loop pointer reproduces the native extra pointer move. Declaring
the culling word before ambient color reproduces native stack `20` for culling
and `1C` for color.

The text-only private `culling_before_color.cpp` probe emits the original
**2,036 bytes**, with **164 differing instruction positions** after actual
relocation application. It owns only text and remains uncredited. Remaining
work includes link-access address forms, manager temporary choices, extensive
general/floating register allocation and scheduling, and reconciliation of the
private calling declarations with accepted record-access declarations.
Comparison-return, pointer, loop-shape, color-aggregate, transform and
compiler-option variants are preserved in the scratch directory. None is
counted as source completion; diagnostic register-normalized diffs are also
research only. No production sprite source or split has been promoted.

Original corner and texture-coordinate arrays at `0x8035D360/0x8035D380`,
their constructor initializer and borrowed scalar constants remain original.
The larger adjacent routines at `0x80283EB8` and `0x8028437C` also remain
original. This note supersedes truncated Ghidra output for these details;
pseudocode and assembly remain research evidence only.

## Literal constants and initializer research

The newer `literal_constants.cpp` probe replaces the three borrowed scalar
constants with native float literals. It still emits **2,036 code bytes**,
with **158 differing instruction positions** after actual address relocation.
Its emitted 12-byte constant pool has the observed order `255, 1, 0`, but the
renderer still has register and link-address differences and remains uncredited.
Pool payloads are mapped to verified native scalar addresses; this diagnostic
comparison does not mask relocation fields.

Equivalent nested culling/depth branches produce the same remaining
differences. GC/1.3.2r and GC/2.0 produce the same text as GC/1.3.2 for the
borrowed-constant probe. Older GC/1.2.5 variants emit 1,972 bytes with 506
differing positions; GC/1.3 emits 2,040 bytes with 342 differences. Their
private compatibility header omits an unused derived declaration; no accepted
compiler flags or shared production declarations changed.

The table initializer at `80283E5C..80283EB8` is 92 bytes. Native assignments
establish four corners `(-.5,-.5), (.5,-.5), (.5,.5), (-.5,.5)` and UVs
`(0,1), (1,1), (1,0), (0,0)`. Float-literal constructors reproduce every
initializer instruction after actual relocations, plus the constructor pointer
at `80299960`, and emit the two 32-byte BSS arrays. Their local constants
emit in order `-.5, .5, 0, 1`; original data instead places `1, 0` before
`-.5, .5`. The differing pool order prevents full object ownership and the
initializer remains uncredited. Mixed literal/borrowed forms and explicit
local-variable permutations are preserved in
`scratch/game_platform_sprite_tables/`; none has been promoted.
