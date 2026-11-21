# Native typed-handle list destructor

`src/Game/handle_list_destructor.cpp` reconstructs the 240-byte native C++ destructor at `0x802007D8..0x802008C8`. Its compiler symbol is `__dt__19HandleList_802007D8Fv`, replacing the original address label `fn_802007D8`. The strict verifier `scratch/game_handle_list/verify.py` checks every allocated byte and emitted alignment after applying all seven ELF relocations. GC/1.3.2 with `-O4,p -inline deferred -use_lmw_stmw on` matches exactly. No extra helper bodies or data are emitted. Whole-DOL byte equality, native objdiff checks and the original-source regression audit pass.

The object stores count, capacity and data at offsets `0`, `4` and `8`. When data is present, it destroys each four-byte element, releases the buffer using capacity times four through `0x8028FD50`, and clears its data pointer. The native deleting-destructor ABI releases the list object through `0x801EF610` only when its signed destruction flag is positive.

Each element's destruction retains seven null-test branches before calling the recovered base handle destructor. Seven inline C++ type layers reproduce this sequence directly. The source layer names and genealogy are inferred from the retained destructor structure; they do not claim original class declarations. This agrees with the seven-store typed-handle initialization pattern observed in the earlier hierarchy list at `+0xA8`. Ordinary C++ destructor inlining and a class `operator delete` generate all ABI handling; there is no embedded assembly, volatile workaround, object patching or masked comparison.

The larger preceding object destructor remains a separate candidate. The protected DOL SHA-1 is unchanged at `5da8295a79bf297ab62c620e6ac66210be1c6ef5`.
