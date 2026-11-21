# Readable resource and music names

Five bounded additions to existing C++ data units reproduce **264 more original
`.rodata` bytes**. They use named, fixed-width string records rather than raw
byte copies:

| Linked source | Added original range | Bytes | Meaning |
| --- | --- | ---: | --- |
| `native_readable_pools_80299AA0.cpp` | `80299AAA..80299AC8` | 30 | `P_SENDER` and `0 STREAMAGENT_Z`, with the two preceding alignment bytes |
| `native_readable_pools_80299BB8.cpp` | `80299C5A..80299C67` | 13 | `Karate.cpp` and two preceding alignment bytes |
| `music_names_8029ACA8.cpp` | `8029ADAC..8029AE06` | 90 | Six fifteen-byte SpongeBob variant names |
| `native_readable_pools_8029AAF8.cpp` | `8029AB22..8029AB60` | 62 | Two fixed-width costume tent messages and internal alignment |
| `native_readable_pools_8029AE18.cpp` | `8029B1FA..8029B23F` | 69 | Four twelve-byte counters and the music diagnostic string |

The remaining bytes at `80299C67`, `8029AE06..8029AE08`, and `8029B23F`
remain original-owned alignment. The two original-only intervals now wholly
covered by the adjacent source units had no remaining unknown bytes. The
overall data-byte denominator remains `1,030,936`.

Fresh GC/1.3.2 objects matched their complete allocated sections and symbol
extents. The standard relink passed the normalized GSQE78 DOL SHA-1
`5da8295a79bf297ab62c620e6ac66210be1c6ef5`; `ninja changes` reported no
regressions, source extents and generated progress checks passed, and all 66
repository tests passed. The earlier `ninja baseline` snapshot was retained.
These are bounded data splits, not claims to complete original translation
units.
