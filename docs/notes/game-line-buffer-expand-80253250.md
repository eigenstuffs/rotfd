# Line-buffer bracket removal and semicolon expansion

The original `fn_80253250` at `80253250..80253388` has 312 text bytes. The
observed prefix has a buffer pointer at `0x0C`, signed length at `0x10`,
and cursor at `0x14`; the routine replaces only the pointer and length.
It removes `[` and `]`, expands `;` to LF followed by CR, and retains every
other byte. It counts the result, allocates length plus one through the
existing heap `fn_801EFA1C` with the original two diagnostic strings, line
40 and alignment 4, fills and terminates the replacement, then frees the
old buffer through `fn_801EF610`. The second loop reloads the original
buffer and length each iteration because character writes can alias the
owner. Those reloads must be preserved.

The 2026-10-12 private probe
`scratch/game_frontier_20261012_b/line_expand_life_decl2.cpp` emits exactly
312 bytes with GC 1.3.2, ordinary Gekko `-O4,p`, exceptions and RTTI off.
Its object has only `.text` and the original external relocations; no
helpers or data are emitted. The relocation-resolved `.json` comparison
contains two differing words: the saved allocation pointer `mr r29,r3`
and the input index initialization `li r7,0` trade positions at offsets
`0x90` and `0x98`. All other 76 instruction words match. This is research,
not matching source, and remains outside production.

Initializing the advancing output pointer from the allocation call, then
copying it to the saved replacement pointer, removes an otherwise extra
move. Declaring the input index before the output count fixes the entire
second-loop register assignment. Supported optimization options, compiler
versions, inline cursor/accessor/predicate wrappers, and reference helper
variants have not fixed the final instruction schedule. Neighboring
accepted line-reader routines remain separate partial text splits; all
heap and diagnostic storage is borrowed original ownership.
