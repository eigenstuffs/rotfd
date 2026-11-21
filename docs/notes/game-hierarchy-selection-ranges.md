# Hierarchy range selection and activation

`hierarchy_select_range.cpp` recovers `fn_80204CC0` at
`0x80204CC0..0x80204E38` (376 bytes), registered as `REsetGame`. With console
`argc == 2` and nonzero `numeric[1]` at `0x8A5`, it converts `values[1]` at
`0x8B8` to an integer and scans the global group
entries. A valid entry with a nonnegative offset is selected when
`offset < selection <= offset + width`. It returns true after selecting the
first matching group and false when no entry qualifies.

`hierarchy_activate_range.cpp` recovers `fn_80204E38` at
`0x80204E38..0x80204F80` (328 bytes), registered as `SetPersoCamera`. It
requires `argc == 2`, obtains a group index from integer-converted `values[1]`,
and retains the corresponding handle. A
negative offset returns false. Otherwise it invokes the existing hierarchy
method with `selection - offset` and releases the handle on scope exit. The
original method performs no numeric-validity check and no additional
lookup-bounds check. Counts include the command token. The numeric byte used
by `REsetGame` records parsing success, not argument truth; see
[console argument layout](console-argument-layout.md).

The private `hierarchy_selection_ranges_internal.h` preserves both typed
manager-table access paths visible in the original code. Its field accessors
and signed index/generation accessors retain the original intermediate values
across the two resolutions. The const manager accessor preserves the observed
register lifetimes. All methods are ordinary C++, without volatile accesses,
register directives, inline assembly or modified instruction encodings.

Run `python3 scratch/game_hierarchy_selection_ranges/verify.py` to compile
the production sources with GC/1.3.2 and apply all 14 actual relocations.
Every retained instruction matches the protected original DOL. Neither unit
owns data, BSS, exception records or padding. The activation source emits one
unused 84-byte weak wrapper destructor with two relocations; the verifier
checks its extent and lack of retained references, and the linker removes it.

Central integration passes all 704 code bytes, two functions, the full DOL
hash/direct comparison, native objdiff and the source-section extent guard.
The acceptance manifests are `game_hierarchy_select_range.json` and
`game_hierarchy_activate_range.json` under `config/GSQE78/candidates/`.
