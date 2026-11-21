# Platform record deactivation

Verified source: `src/Game/platform_record_deactivate.cpp`, GC/1.3.2,
standard `-O4,p` / `-inline auto`. `fn_8026E940` owns
`0x8026E940..0x8026E97C`: 60 text bytes and one actual call relocation,
with no owned data, padding, weak functions or other allocated sections.

For a nonnegative record index it invokes the matching release helper with
status 1. It preserves the original absence of an upper-bound check. The
shared record-index reference and inline record-pointer getter match the
native argument and address-calculation sequence.

Evidence: `scratch/game_platform_record_deactivate/verify.py --production`,
`scratch/platform_record_deactivate_link_proof.json` and
`scratch/platform_record_deactivate_checkpoint.json`. The DOL is identical;
685 source units/682 candidate hashes and 299 mapped header hashes pass,
source/progress audits and all 23 tests pass, and all earlier sources and the
original baseline remain unchanged. This reaches 946,180 / 2,607,744 code
bytes (36.2835%) and 3,058 / 8,802 functions, with 301,600 data bytes.

The following reservation routine at 8026E97C remains uncredited. Its private
`near13.cpp` in `scratch/game_platform_record_slots/` reproduces the original
440-byte size, typed two-chain record assignment, capacity growth by 16 and
native placement copy, but has 13 instruction differences in the free-slot
search. All actual relocations are applied in
`record_reservation_near.json`; no bytes/relocations are masked. The bounded
500-byte private group includes the now accepted 60-byte wrapper and receives
no duplicate credit.
