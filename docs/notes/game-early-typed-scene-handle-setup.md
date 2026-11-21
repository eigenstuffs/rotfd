# Early typed scene Handle setup: 8002D2F8

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The isolated ordinary C++ source reconstructs the original `fn_8002D2F8` entry without an identifier migration. It retains 420 text bytes, 200 exception-table bytes, and the original 12-byte exception index. All retained bytes and actual relocations match after real ELF strong-symbol resolution. Full-game integration and the original DOL hash remain the integrator's acceptance requirements.

The routine forwards to the scene setup, looks up and assigns the resource Handle at owner+0x60, copies the owner Handle at +4 into a retained local, passes a converted Handle to the service at globals+0x164, and invokes the owner's virtual method at table+0x8C with two zero arguments. The private owner view only establishes storage through +0x63; it does not claim the complete allocation size.

The native Handle hierarchy is established by the retained EH actions and the accepted destructor bodies. Resource conversion uses `Handle_80021BCC` and `Handle_8002D590`; the scene copy uses `Handle_8002D518` and `Handle_8002D49C`; the service argument uses `Handle_80020478`. Three private empty layers express observed construction and destruction structure without inventing original template names. In particular, the scene conversion has three default zero initializations in its bases, followed by a copy/retain body. Putting the last zero in the copy body instead produced two wrong store operands. A reference accessor for the native word, a named reference to the owner's original member, and a service-pointer local preserve the original storage and argument lifetimes.

The resource lookup returns a nontrivial four-byte native Handle through the actual hidden result pointer ABI. The service Handle argument is passed as a real C++ value, preserving its temporary construction and cleanup. The lookup label remains an external eight-byte `.sdata2` array so its actual SDA21 relocation remains exact.

## Ownership

| Section | Original range | Bytes |
| --- | --- | ---: |
| `.text` | 8002D2F8..8002D49C | 420 |
| `extab` | 80006C08..80006CD0 | 200 |
| `extabindex` | 80016AD0..80016ADC | 12 |

The full original exception-index table (80015F60..8001F2C0) and both startup tables were audited. There is exactly one owned index record and no constructor or destructor startup entry. An initialized-pointer scan finds the index and one callable-table reference in the unchanged external 148-byte `lbl_802B1884` pool. The complete original pool extent and hash are preserved in `original_pointer_audit.json`. The pool and all other original data remain external. No other source/header consumer uses this original entry.

The emitted object additionally contains eight weak destructor backups: 896 text bytes and 384 exception/index bytes, with 53 actual relocations. These are fully inventoried and receive no credit. Five retained EH targets have accepted GLOBAL strong owners; every strong owner's complete production object was independently recompiled and strictly verified against the original bytes and real relocations. The unchanged weak/EH verifier proves 37 retained relocations, complete allocated coverage, and exact EH action categories.

The real MWLD link selects all five accepted strong production objects and discards all 24 backup allocations (eight text bodies, exception tables, and indices). A wrong input basename is rejected. This isolated link proves strong selection and discard; original placement and the full original DOL hash must still pass centrally.

Evidence and replay scripts are frozen under `scratch/game_early_typed_scene_handle_setup_continuation`. `verify.py NEW_DIRECTORY` performs a fresh production compile plus private strong-owner recompiles. `native.py NEW_DIRECTORY` repeats actual native linker selection/discard. No verifier extension or central metadata change was made by this work; it uses the unchanged `production-defined-weak-eh-override-v1` schema.
