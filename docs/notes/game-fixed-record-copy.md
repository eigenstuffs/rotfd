# Fixed record copy

`src/Game/fixed_record_copy.cpp` reconstructs `fn_80268B80`, the 332-byte
function at `80268B80..80268CCC`. It clears a fixed-capacity destination
container, then placement-copies every source element. The container stores
256 records inline, followed by a signed count at `2800`. When appending at
capacity, it overwrites element 255 without increasing the count, preserving
the original bounded-container behavior.

Each 40-byte record has seven floats through offset `18`, a pointer at `1C`
and an opaque two-word payload at `20`. The source groups the floats as a
three-component point, scalar and three-component normal, consistent with
the adjacent math routine. These descriptive names remain inferred. Default
construction initializes only the pointer; destruction is empty. Copy
construction copies the float components and pointer individually, then the
two-word payload in the native order.

The inline resize handles both grow and shrink paths even for the constant
requested size zero. Consequently the original empty destruction loop and
negative-count placement-construction path remain present. An unsigned
index accessor reproduces their address formation and null checks through
ordinary C++ placement construction.

GC/1.3.2 with standard optimized Game flags emits exactly 332 text bytes,
one global function and no relocations. The strict verifier compares the
complete object allocation directly to the verified original DOL:

```
python3 scratch/game_fixed_record_copy/verify.py
```

No weak functions, constants, data, BSS, constructor/destructor entries,
exception tables or padding are emitted. Original assembly references are an
ordinary call and definitions, with no constructor-table entry to transfer.
Candidate and empty applied-relocation manifests are preserved in the same
scratch directory with intermediate probes.

This source is integrated and accepted by the full executable build. Only this
text function is owned by the partial split; original neighboring code and
all data remain outside it. No original translation-unit boundary is claimed.

Accepted continuation checkpoint: the native build reproduces the original
DOL SHA-1 `5da8295a79bf297ab62c620e6ac66210be1c6ef5`; `ninja changes` reports
no regressions, the source-extent audit passes, and generated progress checks
pass. The original denominators remain unchanged.
