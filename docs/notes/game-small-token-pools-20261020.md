# Native small token pools

Four original `.sdata2` ranges now have matching source declarations. They
contain menu/resource tokens, editor object names, and two integer conversion
bias constants. The strings retain their original spelling, global identities,
sizes and four-byte alignment; the doubles use native eight-byte alignment.

| Source under `src/Game/` | Complete owned range | New bytes |
| --- | --- | ---: |
| `scalar_constant_80379218.c` | `80379178..8037921C` | 160 |
| `scalar_constant_80379240.c` | `80379240..803792BC` | 116 |
| `frame_lifecycle_scalar_constants.c` | `8037A988..8037AA4C` | 184 |
| `scalar_constant_8037AC68.c` | `8037AC68..8037AD54` | 228 |

The existing constants at `803792B8` and `8037AD50` were absorbed into the
preceding sources and retired as separate build units. Their source backups
remain available. The float at `803792B8` explicitly retains eight-byte
alignment to reproduce the preceding inter-unit gap. No padding objects were
introduced. Trailing bytes beyond the listed extents retain original ownership.

GC/1.2.5n and each source's existing flags emit exact allocated sections with
no relocations. Independent verification of the production objects checks all
92 added global object extents as well as all 720 enclosing bytes. These data
splits do not establish complete original translation-unit boundaries.

Acceptance: original DOL SHA-1 passes, `ninja changes` reports no regressions,
the source extent audit passes (5,777 linked source units and 6,750 data/BSS
sections), and all 66 tooling tests pass. Generated matched data increases by
688 bytes to 953,748 / 1,030,936 (92.5128%). Matched code remains 1,920,872 /
2,607,776 bytes. The native objdiff report and complete denominators remain
intact. Build-unit counts decrease because six fallback/standalone units were
consolidated into four existing source units.

The manifest, candidates, source backups and integration snapshots are under
`scratch/small_data_token_scout_20261020_parallel/`.

## Additional bounded pools

Four more ranges contribute 540 bytes and 70 complete named strings:

| Source under `src/Game/` | Complete owned range | New bytes |
| --- | --- | ---: |
| `scene_resource_token_names_803793A0.c` | `803793A0..803794C8` | 296 |
| `model_attachment_token_names_8037A768.c` | `8037A768..8037A7A4` | 60 |
| `menu_item_token_names_8037AF20.c` | `8037AF20..8037AF70` | 80 |
| `scalar_constant_8037B040.c` | `8037AFD8..8037B044` | 104 |

The first attempt extended two pools through complete strings ending at
`8037A7F9` and `8037AF8E`. Those isolated sections matched, but the linker
inserted extra alignment before the following original objects despite their
one-byte ELF alignment. The full DOL check correctly rejected the promotion.
The accepted source ends at the earlier word boundaries shown above. The
remaining strings, gaps, and ambiguous zero-valued objects retain original
ownership. No new padding object was introduced.

The accepted manifest and failed-attempt evidence are preserved under
`scratch/bounded_token_scout_20261020_parallel/`. All four production objects
pass exact bytes and global symbol extent checks. The DOL SHA-1, empty
regression check, extent audit (5,780 sources, 6,753 data/BSS sections), and all
66 tests pass. Matched data is now 954,288 / 1,030,936 bytes (92.5652%).

## Fifteen further scalar and token closures

The next batch joins complete native strings, four-byte floats and verified
eight-byte numeric conversion constants with adjacent accepted scalar sources.
It adds 804 bytes and 108 globals while preserving all 84 previously accepted
globals in the affected ranges. Nine following source units are absorbed into
their predecessors; their original source files and backups remain available.

| Added original range | Added bytes |
| --- | ---: |
| `803783B4..80378410` | 92 |
| `80378294..803782E8` | 84 |
| `80378E64..80378EB0` | 76 |
| `8037910C..80379150` | 68 |
| `803796CC..80379710` | 68 |
| `80379714..80379750` | 60 |
| `80378744..80378770` | 44 |
| `80378A7C..80378AA8` | 44 |
| `8037AB04..8037AB30` | 44 |
| `80378498..803784C0` | 40 |
| `803794F0..80379518` | 40 |
| `80378C94..80378CB8` | 36 |
| `8037921C..80379240` | 36 |
| `803797A4..803797C8` | 36 |
| `8037A904..8037A928` | 36 |

The earlier menu token pools at `80379178..8037921C` and
`80379240..803792BC` are now one source range with their intervening tokens.
All enclosing sections start at eight-byte boundaries and end at word
boundaries. Internal compiler alignment produces the observed gaps, with no
padding declarations or trailing source credit. All production bytes and
symbol extents match; these pools have no relocations.

The original DOL, empty regression check, extent audit (5,797 source units /
6,770 data/BSS sections), and all 66 tests pass. Matched data is 965,785 /
1,030,936 bytes (93.6804%); the complete denominator is unchanged. Evidence
and integration snapshots are in
`scratch/scalar_pool_closure_scout_20261020_parallel/`.

A separate zero-extent audit identified 49 eight-byte original symbols used
only by first-word single-float loads. None has observed double loads, second
element loads or array-address references. Those ambiguous float/alignment
ranges remain original-owned; no doubles or two-element arrays were invented.

## Further scalar and token closures

Ninety-two disjoint closures add 1,536 bytes and 189 new globals. All 359
retained globals preserve their native identity, absolute address, size and
binding/type. Every allocated small-data byte and all retained symbol extents
match in production; no relocation masking or raw-zero padding arrays are
used. The 49 ambiguous eight-byte float tails remain original.

Together with the Camera constructor integration, the original DOL hash and
no-regression check pass, source extents cover 5,768 units / 6,741 sections,
and all 66 tests pass. Matched data is 970,559 / 1,030,936 bytes (94.1435%).
Evidence: `scratch/small_scalar_pool_closure_20261020_parallel/manifest.json`
and its `production-verification.json`.

## Individual scalar and short-token closures

Another 240 closures add 980 bytes and 240 complete globals while retaining
354 previously accepted globals. This includes complete four-byte floats,
four eight-byte Agent_Z/CState strings and one complete eight-byte double.
The 49 ambiguous float tails remain original-owned. Every production object's
allocated bytes, symbol extents and actual relocations match its private
candidate and the native executable.

The original DOL hash, empty regression check, source extent audit (5,766
units / 6,739 sections), and all 66 tests pass. Matched data is now
971,539 / 1,030,936 bytes (94.2385%). The native denominator is unchanged.
Evidence: `scratch/tiny_scalar_pool_closure_20261020_parallel/manifest.json`
and `production-verification.json`.
