# Platform record access and reactivation

Verified source: `src/Game/platform_record_access.cpp`, GC/1.3.2 with the
standard `-O4,p` flags and `-inline off`. The two global functions own
`0x80283954..0x80283AA0`: 332 text bytes, no data or padding.

`fn_80283954` (96 bytes) rejects the sentinel/out-of-range index and nonzero
status, then refreshes the timestamp and index-storage address.
`fn_802839B4` (236 bytes) also reports a status-2 reactivation through its
optional signed-byte output. It requests the signed-short sum of the two
record counts from `fn_80283AA0`, and returns null if growth fails. Status 1
is rejected. The original sentinel check does not reject every negative index;
the reconstruction preserves that behavior.

Both declarations use the already verified record-index reference ABI.
Disabling inlining preserves native leaf/nonleaf emission order. The full
allocated section, both strong symbols and the one actual call relocation
match. No shared declaration or earlier source was changed.

Evidence: `scratch/game_platform_record_access/verify.py --production`,
`scratch/platform_record_access_link_proof.json`, and
`scratch/platform_record_access_checkpoint.json`. The full DOL is
byte-identical; 679 source units and 676 candidate hashes pass, all 271 mapped
header hashes pass, source extent and assembly audits pass, the original
baseline is unchanged, and all 23 tooling tests pass.

This increment reaches 944,392 / 2,607,744 code bytes (36.2149%),
3,052 / 8,802 functions and 301,600 / 1,030,936 data bytes. The adjacent
record growth and linked-index helpers remain original at this checkpoint.
