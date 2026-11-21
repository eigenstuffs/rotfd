# Sparse key acquisition at 801ADB28

Isolated strict match: `src/Game/sparse_key_acquire_801ADB28.cpp` reproduces
`fn_801ADB28`, `801ADB28..801ADC08`, all 224 original text bytes and three
actual REL24 relocations. Full native adoption is pending with the integrator.
No helpers, weak functions, literals, initialized storage, BSS, padding or
exception metadata are emitted. The complete source, object, normal symbol and
allocation inventory, actual RELAs and ownership census are frozen in
`scratch/game_frontier_20261012_b/sparse_key_acquire_801ADB28.owned.json`.
A second compilation of the production source also passes the strict verifier.

GC/1.3.2 settings are standard Gekko `-O4,p`, exceptions off, plus the supported
`-opt noloop` option. Ordinary row `matches(const Word*)` and `setKey(const
Word*)` methods preserve the original key receiver/access lifetimes. The loop
option prevents caching the occupied-bitset subobject address in a third
nonvolatile register. The first raw-array reconstruction emitted 236 bytes;
no near-match from that investigation was promoted.

The owner contains a 36-byte pool at +B0. Its 20-byte rows have a nested array
at +0, unsigned 32-bit key at +C and reference count at +10. Pool row data is
at owner+B8, occupied bits at +BC and high-water limit at +CC. The function
iterates occupied slots through original `fn_80207B94`. A matching key gains
one reference and returns its index. Otherwise accepted `fn_801ADC08` allocates
a slot; the function stores the key, sets its reference count to one and returns
the new index. All original unchecked accesses and allocation behavior remain.

The original ABI is unchanged: owner in r3, pointer to a 32-bit key in r4, and
signed index result in r3. Native callers at 801D0E04 and 8024AE10 pass addresses
of four-byte stack key values and store the returned word. The bit-search
callee's signed-char state argument is declared correctly; the pool passed to
accepted `fn_801ADC08` has its established 20-byte-row/36-byte-pool layout.

A fresh audit scans all 3,109,410 aligned and unaligned original initialized
word positions, all original text branches and nearby absolute materializations,
the complete exception index and constructor/destructor tables. It finds no
initialized pointer, interior external entry, absolute address, exception or
startup consumer. The two external direct calls target the preserved GLOBAL
entry. All 6,246 active native link inputs and 133,691 actual RELAs were scanned
and hash-checked stable; both active call references retain binding GLOBAL and
addend zero. Existing GLOBAL function identity and positive extent stay unchanged.

Integration is text-only: retain original `fn_801AD8D4` and its original metadata
through 801ADB28, then select this source at 801ADB28..801ADC08. Following accepted
`fn_801ADC08`, all row/bitset storage and other functions remain with their
existing owners. No shared declarations, configure entries or split files were
changed by this agent.

Accepted in the standard build on 2026-10-12. The original full DOL hash,
immutable baseline comparison, complete original coverage, raw allocated
symbol/relocation proof, native source placement and all 66 tests pass. Root
evidence: `scratch/continuation_20261012_b/next-plain.frozen.json` and
`build-next-native-promote.log`. No helper, data or padding earns credit.
