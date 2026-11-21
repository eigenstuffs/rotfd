# Platform audio update, path wrappers and scalar data

Five partial source units add **1,200 matching code bytes / five functions**
and **40 matching data bytes**.

| Source | Native range | Owned bytes |
| --- | --- | ---: |
| `platform_audio_update.cpp` | `80286398..80286738` | 928 code |
| `platform_audio_paths.cpp` | `80286CD8..80286D9C` | 196 code / two functions |
| `platform_audio_stream_flush.cpp` | `80286FF8..8028701C` | 36 code |
| `scalar_clamp_800A8E8C.cpp` | `800A8E8C..800A8EB4` | 40 code |
| `platform_audio_constants.cpp` | `8037B898..8037B8C0` | 40 data / nine scalars |

The update walks 32 forty-byte channels and corresponding twenty-eight-byte
tracks. The owner has a native vptr at `7C`, tracks at `80`, flags at `408`,
channels at `410`, and a secondary interface at `420`. Each track contains
three handles at `0`, `4`, `8`, a timer at `10`, and a running byte at `14`.
These physical views and field names are inferred; the complete native class
hierarchy and unused virtual-slot signatures remain unknown. Native virtual
dispatch through table offset `1C` reproduces the completion callback. No
vtable is emitted or credited by this split.

Handle resolution preserves index/generation extraction and the original
unchecked manager indexing. Explicit locals and early returns reproduce the
native register allocation. Active tracks advance their timer. The update
calls original spatial/object callbacks, sets pan, processes fades under
mask `400`, stops completed AX voices, applies input attenuation, and starts
voices with the requested sample-rate ratio. The fused fade operation clears
mask `400`, rather than the earlier private probe's incorrect mask `800`.
`-fp_contract on` reproduces native fused pan and fade arithmetic. Input
attenuation uses 150 times the matching logarithm wrapper, with zero input
represented by -900 and values above one represented by zero attenuation.

The path wrappers split and rejoin a name through matching `fn_802077B4`,
then call the matching uppercase routine `fn_801F459C` before passing the
result to the secondary interface. The second wrapper preserves an early
return on a nonzero helper result: CodeWarrior retains its otherwise unused
comparison, matching all 100 bytes. The flush wrapper forwards directly to
`fn_8028A7DC`.

Eight strong, typed float definitions supply 0, 1, -1, -900, 64, 150, 32000,
and 24. A strong double supplies the signed-integer conversion bias
4503601774854144 (`4330000080000000`). Their actual `.sdata2` extent is exactly
40 bytes, aligned to eight, without padding. Earlier audio units now resolve
these symbols to source definitions; their own source and headers are unchanged.
Original extension strings beginning at `8037B8C0` remain outside this split.

The scalar clamp uses ordered comparisons: return the lower bound when the
value is at most lower, the upper bound when at least upper, otherwise the
value. Its original spatial caller discards the returned value; the native
spatial routine remains original and its observed behavior must be preserved.

Strict evidence in `scratch/game_platform_audio_update/verify.py` applies all
**40 actual code relocations**, checks symbol binding/type, and verifies all
allocated code/data bytes against the immutable DOL. No helper, padding,
pseudocode or masked comparison is credited. Final ELF byte verification is
in `scratch/platform_audio_update_link_proof.json`. Acceptance in
`scratch/platform_audio_update_checkpoint.json` records 714 fully matching
source units, all prior matches and source/header hashes preserved, 711
current candidate manifests, 374 mapped header hashes, the original baseline
unchanged, a byte-identical DOL, passing source/extent audits, and 23 passing
tooling tests. Code/function/data denominators remain unchanged; the provisional
unit count increases by six to 4,209 while retaining original fragments.

These source units do not establish a complete original audio translation
unit. Spatial mixing, channel allocation, stream/resource loading and remaining
shared data still use original code. Private reciprocal-estimate probes show
that the ordinary `__fres(__frsqrte(x))` expression introduces an extra `frsp`;
those probes remain uncredited and do not alter the native implementation.

The subsequent [resource loading split](game-platform-audio-load.md) now matches
its 604-byte loading routine and the eight extension-string bytes. Those
original ranges are no longer unfinished; underlying streaming operations and
spatial mixing remain original.
