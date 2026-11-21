# Python global-object strings

Three linked C++ data units now reproduce 441 original `.rodata` bytes across
global-variable, stored-object, lookup, Python-agent registration, and
BaseObject binding strings. They contain sixteen ordinary constant character
arrays and their compiler-generated internal alignment. No code, relocation,
metadata, constructor, or destructor is claimed.

| Source extent | String objects | Original bytes |
| --- | ---: | ---: |
| 802A2AA0..802A2AE2 | 3 | 66 |
| 802A2B40..802A2C38 | 8 | 248 |
| 802A2C38..802A2CB7 | 5 | 127 |

The middle source, `src/Game/python_global_object_strings_802A2B40.cpp`,
originally ended at `802A2BD1`. It now includes the four agent-registration
and BaseObject binding strings at `802A2BD4..802A2C38`. GC/1.3.2 emits the
three intervening alignment bytes, the exact 248-byte section, and eight
global objects at their original addresses. The separate original 100-byte
auto unit and three-byte padding unit were absorbed into this one compiler
section. The measured data denominator stays unchanged, while matched data
increases by 103 bytes. Two strings without direct relocation consumers,
`lbl_802A2C00` and `lbl_802A2C14`, require `force_active` retention.

The external gaps at `802A2A9C..802A2AA0`, `802A2AE2..802A2AE4`, and
`802A2CB7..802A2CB8` remain original-only. The other compound native objects
at `802A2AE4` and `802A2CB8` remain outside these source units. The full DOL
passes the original SHA-1 check, `ninja changes` has no regressions, the
source extent audit passes, and all 66 repository tests pass. Earlier isolated
evidence is preserved in `scratch/sdk_python_global_object_strings_20261011/`;
the 2026-10-20 merged probe is in
`scratch/python_agent_strings_802A2BD4_20261020/`.
