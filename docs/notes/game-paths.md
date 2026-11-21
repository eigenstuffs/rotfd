# Filename and database-path helpers

`src/Game/paths.cpp` recovers three consecutive routines at
`0x802077B4..0x80207B94`: filename component splitting, conversion to the
game's `DB:` path representation, and conversion back with optional `_MASTER`
root remapping. Names reflect observed behavior; the wider source TU remains
unestablished.

GC/1.3.2 with the flags in `config/GSQE78/candidates/game-paths.json` reproduces
all 992 code bytes, the eight-byte `_MASTER` string at `0x8037A980`, and all
39 relocations exactly. Run `python3 scratch/game_paths/verify.py`. It checks
every allocated ELF section, original-address alignment, exact section sizes,
all relocated bytes, and the protected DOL SHA-1. Full DOL byte equality, native objdiff code/data checks and the preserved
original-source regression audit pass.

The four-byte `DB:` constant at `0x8037A97C` remains external original data,
owned by the NonMatching `original/path_prefix.s` split.
Defining it together with the eight-byte `_MASTER` array would give this
section eight-byte alignment at a four-byte-aligned original start. Keeping
the separate original literal as an explicitly sized external array preserves
the original SDA references and permits strict alignment verification without
altering preceding accepted source ownership. The global path/base/remap
storage at `0x801E9D24` also remains external.

The splitter's original fixed-buffer copies and loop conditions are preserved.
Declaring buffers in drive/directory/name/extension order produces the original
stack layout. Reusing the backward scan index across the extension/name scans
reproduces the branch and register layout. For decoding, an unsigned loop
index declared before the cached root pointer and an integer temporary holding
a signed input byte reproduce the original saved-register assignment. The
suffix pointer is calculated before the final concatenate call. These are
ordinary C++ operations; no assembly, instruction patching, or comparison masks
are used. Earlier register-allocation variants remain in `scratch/game_paths/`.
