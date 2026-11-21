# Indexed streaming cleanup

`src/Game/platform_audio_stream_release.cpp` reconstructs the complete 468-byte
function `8028A4F0..8028A6C4`, together with its two 16-byte diagnostic strings at
`802AF640..802AF660`. These are partial splits of an original streaming unit;
neighboring setup, worker and I/O functions remain original. The two strong
string definitions fill the entire emitted 32-byte `.rodata` section, without
padding, anonymous conversion pools, or helper functions.

The source preserves the unchecked channel index. Unless the high record flag
is set or its name equals the shared path buffer, it closes the embedded DVD
record at offset `04`. For unsigned indices below four, it logs and clears the
name, stops the single AX voice, releases its mixer channel and AX allocation,
and clears the observed secondary voice/control fields. For index four it
stops/releases both mixer voices, clears fields at `320`, frees the pointer at
`324`, and resets fields `324`, `32C`, and `330`. Both branches set bit `40` and
then clear the entire record flags word, matching the original store order.
The common tail clears record words `00`, `48`, `4C`, `44`, `40`, then sets `58`
to one. Channel five reaches that common tail without voice teardown.

The new release header contains a physical record/voice/state view and the
logger field at global offset `110`. These declarations are inferred from
observed accesses; their names do not establish original class identity. The
existing shared cleanup declaration now returns `void`. All callers discard its
result, and the void signature preserves the native common-tail register/store
sequence. The apparent zero remaining in r3 is not counted as a recovered return
contract.

An initial name-pointer local placed before each diagnostic call caused six
relocated instruction differences per call. Computing that name directly as the
call argument and declaring the reusable local after the call gives the exact
compiler scheduling. Neither a volatile logger nor alternate compiler pragmas
is needed. Earlier private alternatives remain preserved as research artifacts.

`python3 scratch/game_audio_stream_release/verify_release.py --production`
checks the complete text and rodata bytes, all 26 actual relocations, strong
symbol types/sizes/offsets, exact allocated section extents and every included
header. All six earlier units using the corrected shared header are reverified
with their original strict scripts. Full linked proof, unchanged baseline and
previous source matches, original DOL SHA-1, source audits and tooling tests are
required for integration credit. No partial or relocation-masked score is used.
