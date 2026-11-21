# Viewport storage and native lifetime

Verified text-only source: `src/Game/viewport_storage.cpp`,
`0x801E2E04..0x801E30E4`, eight functions and 736 code bytes.
The allocation diagnostics point to `Viewport_Z.cpp`, line 33. This split
covers storage/lifetime helpers, not the complete original translation unit.

## Recovered behavior

The three leading helpers replace the reference at offset `0x10` (release,
copy, retain), read the four viewport bounds, and write those bounds.
The viewport is `0x4C` bytes. It owns two handles at `0x10`/`0x14`, eight
four-byte handles at `0x28`, and a dynamically allocated array of twelve
`0x1C4`-byte records at `0x20`. Construction clears the handle layers and
word `0x48`; the bounds and unidentified fields remain uninitialized.
Each record contains sixteen eight-byte vector entries followed by sixteen
20-byte entries and one unidentified word. Both entry constructors are empty.
The eight-byte entry constructor at `0x800C3BC4` remains original code under
its recovered native C++ symbol. The 20-byte entry constructor is owned here.
Class names describe observed ABI roles and do not claim original identifiers.

Native constructors, destructors, array members, `new[]`, and `delete[]`
produce the compiler's actual array helpers and 16-byte allocation cookie.
The array of handles reuses the existing strong destructor at `0x8002F6B0`.
The two other handle members have two observed typed layers; their inline
cleanup produces the original nested null checks. No manually copied assembly
or explicit calls to compiler array helpers are needed.

## Ownership and acceptance

The compiler emits 908 text bytes: all 736 retained bytes plus two
unreferenced weak destructors totaling 172 bytes. The weak helpers are
absent from the linked executable and receive no credit. This object emits
no data, BSS, or padding. Original allocation strings, the arena, globals,
and all neighboring viewport functions retain separate ownership.

`scratch/game_viewport_lifetime/verify.py --production` recompiles ordinary
C++ with GC/1.3.2, checks every allocated symbol/byte, applies all 39 actual
retained relocations, and compares all eight functions against the immutable
DOL. `scratch/viewport_storage_link_proof.json` checks their final addresses,
sizes, and bytes, preserved external definitions, and discarded weak helpers.

The standard build passes the original DOL hash. All 633 source units match;
630 candidate source/object hashes and 82 recorded header hashes are current.
All previously linked source files and the original baseline are unchanged.
The 23 tooling tests, progress check, extent audit, and assembly audit pass.
See `scratch/viewport_storage_checkpoint.json` and the corresponding build,
changes, and test logs. Verified coverage is 916,144 code bytes and 2,973
functions; data remains 301,448 bytes.
