# Streaming resource submission

`src/Game/platform_audio_stream_submit.cpp` reconstructs all 468 bytes of
`8028A31C..8028A4F0`. Its new shared header records the 272-byte queued node:
two 128-byte strings at `00` and `80`, a kind word at `100`, signed loop byte at
`104`, cookie word at `108`, and next pointer at `10C`. Physical context/owner/
target views cover only accesses verified here; original class identity and
translation-unit boundaries remain unknown.

A null name returns -1. The routine rejects any of six active 16-byte names with
-2, then resolves the global context's owner handle at `18` and its target handle
at `48`. If both resolve, it writes the original `8028AE40` callback and streaming
owner cookie at target offsets `134` and `138`. Handle lookup preserves native
signed index/generation behavior, including the unchecked manager-entry access.

The original allocator obtains 272 bytes using borrowed diagnostic strings,
line `1E0` and alignment 32. Without an added null check, the routine copies the
input string and its second string at `80`, truncating each to 128 bytes. It
stores kind/loop/cookie, clears next, locks the shared source-owned mutex,
appends at the registry tail or assigns its head, unlocks and returns zero.
Callback execution, allocator implementation and the two borrowed diagnostic
strings remain outside this source split.

`python3 scratch/game_audio_stream_submit/verify.py --production` proves the
entire 468-byte text section, all 22 actual relocations (including the registry
SDA access), strong symbol extent/type, absence of helper/data/padding output,
and every included header. Full DOL SHA-1, linked symbol/byte proof, native objdiff,
previous source/hash preservation, source audits and tooling tests establish
integration credit. Original data and unresolved streaming worker functions
remain in the denominator.

## Uncredited callback investigation

The original `8028AE40..8028AF48` callback scans five records for active bit 2
without bit `40`, queries `8028F4B4` for the first such record, logs nonzero status,
and calls `8028EF84` on its streaming owner for status 4, 5, 6, 11, or -1. It then
stops scanning. The 264-byte original includes materialized intermediate status
predicates and a signed-byte final test. Private candidates with direct logical
expressions emit 188–204 bytes; explicit intermediate conditions emit 232.
Ordinary inline/static helpers are folded into the same shorter predicate and
some emit additional unlinked helper bodies. O3,p gives the same 232-byte result.
None is integrated or credited. Current probe and strict rejection scripts are
in `scratch/game_audio_stream_submit/`; all prior artifacts remain preserved.

Further probes with disabled propagation/dead-store optimization and C dialect
remain nonmatching. A separate completion callback at `80288BD4` emits 296 bytes
rather than the original 300; selecting the command pointer and materializing the
forced flag still differ. Compiler 1.2.5n and 2.6 probes did not resolve either
callback. These are local research limitations, not a blocker for remaining work.
The now accepted global drive-status helper establishes that `8028F4B4` reads no
record argument. Earlier provisional callback prototypes must be revisited when
that body is integrated.
