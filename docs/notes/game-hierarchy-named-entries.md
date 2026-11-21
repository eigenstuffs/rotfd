# Named-object group and entry commands

`src/Game/hierarchy_named_entries.cpp` recovers four contiguous methods at
`0x80205964..0x80205F1C`:

| Method | Code bytes | Observed action |
| --- | ---: | --- |
| `fn_80205964` | 308 | `SwitchGameToMono`: find the named object's group and forward to `fn_801FED04` |
| `fn_80205A98` | 384 | `DeactivateGamePlayer`: find a group with the requested entry and forward to `fn_80201A14` |
| `fn_80205C18` | 384 | `ACtivateGamePlayer`: forward the corresponding entry to `fn_80201B14` |
| `fn_80205D98` | 388 | `ReMoveGamePlayer`: forward the entry to `fn_80200CBC` with its flush argument set to one |

All four pass strict isolated comparison, complete DOL comparison, and native objdiff.
The command spellings above are established by the original registration;
the original class names and full translation unit boundary remain unknown.

Each method hashes console `argv[1]` at offset `0x868` and the original `WORLD`
string, then uses `fn_801B5054` to retrieve a native handle. The typed owned
handle adds one observed zeroing layer, copies the returned value, and increments
its reference count. Ordinary C++ construction and destruction reproduce both
the returned base-handle temporary and the owned wrapper's lifetimes.

The first command requires console `argc == 2`, including the command token. It checks the retrieved handle,
finds its group through `fn_801FE99C`, rejects a negative result, and dispatches
the existing switch-to-mono action. The following three require `argc == 3`
and convert `values[2]` at console offset `0x8BC` into an entry number without
an additional numeric-validity check. These are argument-count guards, not
engine states; see [console argument layout](console-argument-layout.md).
`fn_801FEADC` performs the named-handle and group-capacity lookup and returns the
matched group index. The temporary handles are destroyed before its signed-byte
result is tested. On success, each method resolves that group handle and passes
`number - 1` to its respective entry operation.

The private header `src/Game/hierarchy_named_entries_internal.h` extends a copy
of the already verified command layouts with the observed group list and
16-byte manager entries. The later console-field naming refinement preserves
the layouts and complete compiled objects. The `WORLD` bytes at
`0x8037A918` remain an external original string; this candidate claims no data,
BSS, exception records, or padding.

## Compiler and verification

GC/1.3.2 uses `-O4,p -inline auto -Cpp_exceptions off -use_lmw_stmw on`, standard
Gekko hardware-FP flags, and `-i src/Game`. Its deferred emission reverses these
four independent source definitions. Their definition order therefore produces
the original ascending machine-function order. The verifier explicitly checks
that retained functions occur in original address order in the compiled object;
no linker function reordering is needed.

Reproduce with:

```sh
python3 scratch/game_hierarchy_named_entries/verify.py
```

All 1,464 retained instruction bytes and 67 actual ELF relocations match the
untouched original DOL after relocation. Verification checks the production
source and private-header hashes, complete function extents and allocated-section
coverage, alignment, retained order, and every relocated byte. No mismatch masks
or post-relocation byte changes are used.

Two unused weak destructors for `CommandOwnedHandle` and `CommandZeroHandle`
occupy 172 bytes and contain four relocations. Their exact extents and weak
binding are checked, and retained references into their bodies are rejected.
Normal linker dead stripping removes them; they receive no source progress
credit. Initial probes, including the alternative definition order, are
preserved in `scratch/game_hierarchy_named_entries/`; no unresolved instruction
differences remain in this handoff.

The original DOL SHA-1 remains
`5da8295a79bf297ab62c620e6ac66210be1c6ef5`. The manifest is
`config/GSQE78/candidates/game_hierarchy_named_entries.json`; the transcript is
`scratch/game_hierarchy_named_entries/verification.txt`.

Central integration passes the original DOL hash and direct whole-file byte
comparison. Native objdiff records all 1,464 code bytes and 4 functions as
matching, with zero owned data. The source-section extent guard and generated
progress checks pass. Original baseline source remains exact after the
documented native-accessor and padding accounting corrections.
