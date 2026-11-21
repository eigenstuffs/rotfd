# Bitset range clearing and lifetime

`src/Game/bitset_lifecycle.cpp` recovers the consecutive range-clear method
at `0x80207DE4` (260 bytes) and native destructor at `0x80207EE8` (220 bytes).
The recovered object contains a word-array base with count/capacity/data at
0/4/8 and the bit count at 0xC. The semantic class name is inferred.

The complete source object verifies with GC/1.3.2 and the candidate's recorded
flags: 480 text bytes, no allocated data, and all six relocations are exact.
Run `python3 scratch/game_bitset/verify.py`. This checks all allocated sections,
exact size/alignment, real relocation results, and the protected DOL SHA-1.
The full DOL, native objdiff code checks and original-source regression audit pass.

The destructor's canonical C++ name is `__dt__15BitSet_80207EE8Fv`, replacing
the old address-based `fn_80207EE8`. Ordinary base-class destruction produces
both original null checks; the array's scalar pseudo-destructor loop produces
the original optimized empty loops. Backing storage is released through
`fn_8028FD50`, and the native positive destructor flag invokes class operator
delete through `fn_801EF610`. Neither original allocator storage object is
redefined. The clear method's masks and ordinary loop produce the exact
compiler-generated eight-word unrolling. No unused weak functions are emitted.

## Preserved search candidate

The adjacent `fn_80207B94` occupies 592 bytes through `0x80207DE4`. The Ghidra
summary's 580-byte count excludes three unreachable return instructions; the
original disassembly and symbol extent include them. The routine scans for
the next requested bit value, starting with a masked partial word, then full
words. Its lowest-set-bit helper uses the original five mask tests.

`scratch/game_bitset/result0.cpp` and `bitset.cpp` retain a coherent near match.
All text outside three repeated inline result-return blocks matches, but those
blocks differ by 57 bytes total. The source preloads -1 into the return register
and branches on the opposite comparison; the original calculates the result
directly in the return register, conditionally returns it, then returns -1 and
retains an extra unreachable return. Removing the inline result wrapper recovers
the latter branch shape but removes the three extra returns and changes two
intermediate registers. This search routine is excluded from the production
candidate and earns no credit.

`scratch/game_bitset/probe.py` is a diagnostic for that wider near-match TU;
it reports size differences and is deliberately distinct from the strict
production verifier. Local declaration, helper scope/return form, compiler
version, and optimization probes remain in the scratch directory. The original
code and reference DOL were never modified.

## 2026-10-02 search continuation

A fresh search-only probe under `scratch/game_bitset_search/` reproduces the
original 592-byte extent with 18 instruction differences (57 differing bytes)
confined to the three inline result-return blocks. New helper member/reference
forms, definition order and optimizer probes do not improve the accepted near
match. These are diagnostic research only and receive no source credit. The
shared lifecycle header and pool construction/destruction remain verified.
