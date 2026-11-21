# Reverse fixed-handle search

`src/Game/handle_reverse_find.cpp` reconstructs `fn_80269F2C`, the 180-byte
function at `80269F2C..80269FE0`. It scans an inline eight-handle array in
reverse, starting at count minus one. Each handle is resolved through the
established manager table and passed to `fn_8024E200` with the two caller
arguments. The first object whose signed-byte predicate result is nonzero is
returned; otherwise the result is null. The original behavior passes null
resolution results directly to the predicate.

The nested fixed array begins at `C140`, followed by a signed count at
`C160`. Its unsigned index accessor preserves the original cached high-address
base and per-iteration address formation. A flattened accessor on the whole
object or a signed accessor generates different pointer lifetimes. The
read-only handle-resolution layout comes from
`handle_list_operations_internal.h`; no earlier header was changed.

GC/1.3.2 with the standard optimized Game flags emits exactly 180 text bytes,
one global function and three real relocations (the predicate call and two
manager-global address halves). The verifier applies all three and compares
the complete emitted allocation against the verified original DOL:

```
python3 scratch/game_handle_reverse_find/verify.py
```

There are no weak functions, constants, data, BSS, constructor/destructor
entries, exception tables or padding. Original assembly references are calls
and definitions, with no constructor-table entry to transfer. The candidate
and applied relocation inventory are in the same scratch directory with
preserved intermediate probes.

This source is integrated and accepted by the full executable build. The partial
split owns only this text function; original neighboring functions and data
remain outside it. No original translation-unit boundary is claimed.

Accepted continuation checkpoint: the native build reproduces the original
DOL SHA-1 `5da8295a79bf297ab62c620e6ac66210be1c6ef5`; `ninja changes` reports
no regressions, the source-extent audit passes, and generated progress checks
pass. The original denominators remain unchanged.
