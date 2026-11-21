# Named-object binding command

`src/Game/hierarchy_named_binding.cpp` recovers `fn_80205F1C`, the complete
912-byte method at `0x80205F1C..0x802062AC`. The stack restore at `0x802062A4`
and return at `0x802062A8` belong to this function; a 904-byte extent would omit
those required instructions. The next already recovered wrapper begins at
`0x802062AC`. No symbol-boundary correction is required.

The method implements the registered `AddGamePlayer` and `AddMenuPlayer`
wrappers. It requires console `argc >= 4`, including the command token, and
nonzero `numeric[2]` at `0x8A6`. It retrieves a native handle using `argv[1]`
and the shared `WORLD` type hash, then wraps it in the observed owned-handle
form. After checking the handle, it converts `values[2]` at `0x8BC` to an
entry number. The numeric flag indicates parse validity, including boolean
aliases, rather than a true/nonzero argument value. The
original lower and upper bounds both equal one. The existing group lookup must
also succeed before dispatch continues.

A nonzero mode (`AddMenuPlayer`) forwards through `fn_80200EEC`; a zero mode
(`AddGamePlayer`) uses `fn_802017D8`. In each path, the method resolves the
matching group object, hashes the player name in `argv[3]` at `0x870`, and
passes that hash with the entry number. Exactly `argc == 5` supplies an
additional integer from `values[4]` at `0x8C4`; other accepted argument counts
pass zero. There is no additional numeric-validity check for that optional
argument. The owned handle is destroyed after dispatch, and the method returns
one. Early failures clean up the same native objects and return zero. The
original class identity remains unknown.

The source deliberately stores the resolved object in an ordinary local before
constructing the argument hash. This preserves the original pointer across the
hash call and the original evaluation order. Putting resolution directly in the
call argument causes the compiler to hash first, then resolve, and removes 16
bytes across the four branches. No register barriers or explicit stack
manipulation are used.

The new private `src/Game/hierarchy_named_binding_internal.h` extends a copy of
the verified name/hash and owned-handle views with two additional console
argument fields; see [console argument layout](console-argument-layout.md).
Existing shared headers are unchanged. The `WORLD` string at
`0x8037A918` remains external original storage; no data ownership is claimed.

## Verification

GC/1.3.2 uses `-O4,p -inline auto -Cpp_exceptions off -use_lmw_stmw on`, standard
Gekko hardware-FP flags, and `-i src/Game`. Reproduce with:

```sh
python3 scratch/game_hierarchy_named_binding/verify.py
```

All 912 retained instruction bytes and all 26 actual retained ELF relocations
match the untouched original DOL after relocation. The verifier checks source
and private-header hashes, complete function and section coverage, symbol sizes,
alignment, retained order, and every relocated byte. The source emits no data,
BSS, exception records, or padding.

Two unused weak destructors occupy 172 bytes and contain four relocations.
Their exact extents and weak binding are checked, and retained references into
their bodies are rejected. Normal linker dead stripping removes them; they
receive no source progress credit. Both initial and exact probes are retained
under `scratch/game_hierarchy_named_binding/`; no unresolved instruction
differences remain in this handoff.

Complete DOL and native objdiff integration are verified below. The original DOL SHA-1
is `5da8295a79bf297ab62c620e6ac66210be1c6ef5`. The manifest is
`config/GSQE78/candidates/game_hierarchy_named_binding.json`; the transcript is
`scratch/game_hierarchy_named_binding/verification.txt`.

Central integration passes the original DOL SHA-1 and direct whole-file byte
comparison. Native objdiff records 912/912 code bytes and 1 matching function;
owned data is zero. The source-section extent guard and generated progress
checks pass. All linked source remains exact; the original baseline is preserved
with only the documented native-accessor and trailing-padding corrections.
