# Platform signed-index list initialization and merging

Verified C++ sources: `src/Game/platform_index_list_init.cpp` and
`src/Game/platform_index_list_merge.cpp`, GC/1.3.2, standard `-O4,p` and
`-inline auto`. The shared six-byte `PlatformIndexList` has signed-short
first/last/count fields and the native aggregate return ABI: first/last in
r3, count in the high half of r4. These are partial text splits with no owned
data, padding, weak bodies or relocations.

- `fn_801ECA54`: `0x801ECA54..0x801ECB84`, 304 bytes. It initializes the
  inclusive index range, setting the initial predecessor and final successor
  to -1. Ordinary loop unrolling matches the original four-entry body.
- `fn_8026EBE8`: `0x8026EBE8..0x8026EC80`, 152 bytes. Empty lists return the
  other list. Nonempty lists are linked at the boundary and their signed-short
  count sum is returned with the outer endpoints.

The explicit inline pointer accessor reproduces native indexed halfword
loads/stores. Individual aggregate field assignments preserve the original
store order and avoid compiler-generated zero aggregate data. The initializer
assigns first, count, then last. The source retains native narrowing and the
original zero/negative-range behavior; no new input guards are introduced.

Evidence: `scratch/game_platform_index_lists/verify.py --production`,
`scratch/platform_index_lists_link_proof.json`, and
`scratch/platform_index_lists_checkpoint.json`. All allocated source bytes
and actual linked strong symbol addresses are exact. The DOL is byte-identical,
681 source units/678 candidate hashes and 279 mapped header hashes pass,
source extent/assembly/progress audits pass, all 23 tests pass, all earlier
sources are unchanged, and the original baseline is immutable.

This increment adds 456 code bytes/two functions/two units, reaching
944,848 / 2,607,744 code bytes (36.2324%), 3,054 / 8,802 functions and
301,600 / 1,030,936 data bytes. Original shared array tables remain outside
these splits. The [record-growth routine](game-platform-record-growth.md) subsequently matched all 700 bytes and was integrated.
