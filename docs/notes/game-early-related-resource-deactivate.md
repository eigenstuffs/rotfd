# Related resource deactivation

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_800AE4A0` is reconstructed in `src/Game/early_related_resource_deactivate_800ae4a0.cpp` with private declarations in `include/Game/early_related_resource_deactivate_views.h`. It resolves the actor's related object chain, invokes its virtual destruction operation, and conditionally deactivates the named resource and the owner's existing effect. Each effect is reset, has flag `0x40000` set, receives the completion call, and has flag `0x20000` cleared. The actor activation byte is cleared last.

The strict isolated GC1.3.2 build matches all 592 original code bytes and the original 8-byte exception table plus 12-byte exception index, including 13 actual retained relocations. Standard O4,s and C++ exceptions are enabled. A trivial typed return wrapper supplies the native full-expression lifetime, whose inline cleanup calls the existing base Handle destructor with argument zero. The compiler emits an additional unique weak wrapper destructor of 76 bytes with 8/12-byte exception metadata. These are wholly inventoried, have four actual relocations, receive no credit, and must be discarded by the final native link. The established bounded weak-EH verifier accepts this inventory with no strong overrides or new adapter.

Original exception ownership is audited over the complete `80015F60..8001F2C0` index and complete constructor/destructor tables. The only initialized original pointers to the retained function are its exception index and the unchanged callable table `lbl_802BD500` at `802BD50C`. The original named string `lbl_802A0178` remains external. No shared literal, BSS, padding, callback table or native identifier migration is supplied.

The optional adjacent `fn_800AE7E4` activation routine is private and uncredited. Its best ordinary helper shape matches the 1,024-byte extent and every instruction except the final virtual binding argument resolution, which uses 19 different words because the target receiver is moved to r3 after rather than before resolution. A separate second-effect helper resolves the earlier r29/r30 lifetime allocation swap. Full source variants and original assembly are preserved under `scratch/game_early_related_resource_deactivate`.

The frozen isolated handoff is `scratch/game_engine_batch148/HANDOFF.md`. Central original-placement linking, original DOL hash, no-regression checks and final native weak discard remain mandatory acceptance steps.
