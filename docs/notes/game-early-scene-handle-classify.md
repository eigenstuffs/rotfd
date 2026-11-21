# Early scene Handle assignment/classification: 8002B824

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The first ordinary C++ probe reproduces every instruction of the original 508-byte `fn_8002B824`. The production source additionally matches all retained exception bytes and actual relocations through the unchanged strong-override verifier. Full native placement and original DOL hash acceptance remain the integrator's requirements.

The routine sends virtual event 0x86, forwards the incoming Handle to the base control when flag 0x2000000 is clear, and assigns the incoming Handle to owner+0x80 with release/copy/retain. It copies the related Handle at resolved owner+0x2C into a typed local, checks that local, reads a line, and compares the line with the external original string at 80299FF0. An equal line enables owner flag 0x1000000000000. Finally it clears flag 0x200 in the resolved actor's 64-bit flags at +0x30.

A named reference to the related member preserves the original source pointer across native Handle construction. The real hierarchy uses `Handle_8001FF78` as the base of `Handle_8002BA20`, including the observed default zero initialization and copy/retain body. The final local cleanup is an actual native destructor call.

Private views establish owner storage through +0x83 and related/actor storage through +0x37. They do not claim full allocation extents. The parameter is recovered as a reference to a four-byte Handle, passed by address in r4. Existing callers use earlier provisional pointer/word declarations; their original C identity and code remain untouched, and all current source/header consumers are inventoried.

| Section | Original range | Bytes |
| --- | --- | ---: |
| `.text` | 8002B824..8002BA20 | 508 |
| `extab` | 80006A88..80006AB4 | 44 |
| `extabindex` | 80016A28..80016A34 | 12 |

There are 17 retained actual relocations and no owned literals or additional original data. The complete original exception-index table and startup tables were audited. Exactly one owned exception-index record and no startup entries transfer. Initialized-data pointers also include a callable entry in the unchanged external `lbl_802B170C` table; its complete original 180-byte extent and hash are preserved in the pointer audit. The original string, callable table, and all other data stay with their original owners.

Two emitted weak destructor backups contribute 228 uncredited text bytes and 104 exception/index bytes, with 14 actual relocations. Both accepted GLOBAL strong owners were independently recompiled, and their complete production bytes and real relocations match. The real native link selects those strong owners and discards all six backup text/EH/index allocations; a wrong fixture basename is rejected. Original-placement and full-game acceptance are still mandatory centrally.

Frozen evidence and replay scripts are under `scratch/game_early_scene_handle_classify_continuation`. `verify.py NEW_DIRECTORY` performs fresh strict production and private strong-owner compilation; `native.py NEW_DIRECTORY` repeats actual strong selection and complete backup discard. The standard existing `production-defined-weak-eh-override-v1` schema suffices, with no new outer route or shared-file edits.
