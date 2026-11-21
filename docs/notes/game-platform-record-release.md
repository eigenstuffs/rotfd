# Platform record release

Verified source: `src/Game/platform_record_release.cpp`, GC/1.3.2 with
standard `-O4,p` / `-inline auto`. `fn_8026EB34` owns
`0x8026EB34..0x8026EBE8`: 180 text bytes and two actual call relocations,
with no owned data, padding, weak functions or extra allocated sections.

An active status-0 record returns both of its signed-short chains (at offsets
08 and 0E) to the owner's free list using the now matched merge helper.
It then sets the supplied status and clears the storage address. Other
statuses skip list merging and still receive those two updates.

The owner now declares its 04 word and six-byte free-list aggregate at
08/0A/0C, retaining the original 0E short and overall 0x34-byte size.
`PlatformIndexList` moved to the shared array header. Direct typed member
access preserves the native scheduling of aggregate assignment between the
two calls. All six earlier array/record/list source units were recompiled and
verified against their exact prior function hashes and allocated bytes.
Their source files are unchanged; candidate header hashes were refreshed only
after these proofs. See `scratch/platform_record_release_header_proof.json`.

Acceptance: `scratch/game_platform_record_release/verify.py --production`,
`scratch/platform_record_release_link_proof.json` and
`scratch/platform_record_release_checkpoint.json`. The DOL is byte-identical;
682 source units, 679 candidate hashes and 285 mapped header hashes pass.
Source extent/assembly/progress audits and all 23 tests pass. The original
baseline and all earlier source files are unchanged.

This increment reaches 945,028 / 2,607,744 code bytes (36.2393%),
3,055 / 8,802 functions and 301,600 / 1,030,936 data bytes. Original array
construction and shared tables remain outside this partial split.
