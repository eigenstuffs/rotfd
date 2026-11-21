# Owned handle from a packed token

`src/Game/handle_from_token.cpp` and its private header recover all 960 bytes at
`0x801F8114..0x801F84D4`. The symbol remains `fn_801F8114`. This is a bounded
reconstructed source fragment; the original translation-unit boundary and method
name remain unknown.

The native C++ signature returns `Handle_801F7F10` by value and takes a manager
and packed 32-bit token. The hidden result pointer arrives in `r3`, the manager
in `r4`, and the token in `r5`. A local owned handle is initialized to zero and
then assigned the packed token. The method retains that handle through the
supplied manager. Returning the local invokes its copy constructor, which copies
the token to the result and retains it through the global manager at
`lbl_801E9D24 + 0x118`. The local handle is then destroyed through the canonical
native destructor at `0x801F7F10` with the original temporary-destruction flag.

Both retain paths preserve the complete observed automatic-release branch:
validate index/generation, increment the signed short reference count, and when
the resulting count is zero and automatic release is enabled, detach the name,
clear state/link, delete the object through its virtual destructor, clear the
name hash and reference count, advance the generation while skipping zero,
clear the object pointer, and append the index to the free list. These layouts
and operations agree with the recovered `handle_reference.cpp` and
`handle_retain.cpp` source; those shared sources were not modified.

Two compiler/source details matter:

- `Handle::getIndex() const` supplies the index to `Manager::retain`; generation
  remains a direct signed-byte local and `release` retains direct bitfield
  access. This fixes six register encodings in the return copy's validity check.
  The same accessor independently fixes the adjacent native handle destructor.
- A standard Metrowerks `inline_max_size(1024)` pragma is scoped with push/pop
  around this one function. The default behavior and an explicit limit of 512
  leave the return copy constructor out of line, producing 524 bytes. Limits of
  768, 1024, and 10000 all reproduce the complete 960-byte instruction sequence.
  This is a recovered compilation requirement, not a claim that the original
  source used that exact pragma spelling or limit. Native constructor and return
  semantics remain expressed in ordinary C++.

Independent compiler checks in
`scratch/game_handle_copy_review/pragma_scopes.json` confirm that the scoped
1024 setting produces identical allocated sections and normalized relocation
records to the broader 10000 probe, with illegal pragma warnings treated as
errors. Applying the setting only around the copy-constructor definition does
not inline the call in the returned-value method.

The stable manifest is
`config/GSQE78/candidates/game_handle_from_token.json`. Run
`python3 scratch/game_handle_from_token/verify.py` for the strict isolated proof:
**960 text bytes, seven actual retained ELF relocations, zero byte differences**.
It verifies the original DOL SHA-1
`5da8295a79bf297ab62c620e6ac66210be1c6ef5`, all allocated sections and function
extents, source/header hashes, and fully relocated bytes. No weak helper bodies,
data, BSS, exception metadata, or padding are emitted. The shared empty-name
literal at `0x8037A820` remains external with no source credit.

Full-DOL and native objdiff integration are verified below. The exact
source, header, and object hashes are recorded in the manifest and
`scratch/game_handle_from_token/verification.txt`.

Central integration passes the original DOL SHA-1 and direct whole-file byte
comparison. Native objdiff records 960/960 code bytes and 1 matching function;
owned data is zero. The source-section extent guard and generated progress
checks pass. All linked source remains exact; the original baseline is preserved
with only the documented native-accessor and trailing-padding corrections.
