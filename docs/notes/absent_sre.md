# _sre module presence check

No SRE type names, copyright string, or characteristic engine diagnostics occur in the original GSQE78 DOL. The only `_sre` substring is part of the game event name `msg_anim_srept` at `0x802A9038`.

The builtin module table at `0x802E95F4` contains:

| Module | Initializer |
| --- | --- |
| errno | `0x801A7628` |
| new | `0x801A90E0` |
| _codecs | `0x801A96F4` |
| marshal | `0x801996D4` |
| imp | `0x80195338` |
| __main__ | none |
| __builtin__ | none |
| sys | none |
| exceptions | none |

The terminator is at `0x802E963C`. There is no evidence to assign native code or data to CPython's `_sre.c`; do not create a matching source unit merely because this module exists upstream.

The builtin table is not an exhaustive list of native module implementations: signal and exceptions have explicit initialization paths. The SRE finding therefore also depends on the missing engine type names, copyright, and diagnostic strings; it does not treat table omission alone as proof.
