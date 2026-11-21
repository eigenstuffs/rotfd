# Platform owner completion

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/platform_owner_completion.cpp` reconstructs `fn_8028DD18`, 440 bytes at `8028DD18..8028DED0`, as ordinary C++ with the original GC1.3.2 flags and LMW/STMW enabled. Frozen isolated handoff: `scratch/game_platform_owner_completion/final_integration.json`.

The function resolves the owner's generation-checked handle and tests flag8. It sends a genuine three-layer zero Handle temporary to `fn_8023D66C` with the resource manager's +0x28C state, clears flag8, then visits the original array count. Entries whose resolved class has type5 pass their related object and the array entry itself to `fn_801CBC64`.

The second argument is verified against the already matching `engine_handle_transfers_801CBC64.cpp`: that callee writes the supplied target's +0x28 Handle. Preserving the entry as this argument accounts for the original final resolver's register lifetime; an initial one-argument declaration was incorrect.

Strict allocated-section, actual-relocation and symbol-extent checks pass: 440 retained text bytes and eight original relocations, plus three unused compiler-generated weak destructors totaling264 text bytes and six relocations. The unused code receives no credit and must be absent from the final native link. No initialized data, BSS, padding or exception/startup allocations are owned. The full original EH/index/startup tables were audited, including descriptors and trailing slots. This is a partial text-only original translation unit.

Status: frozen isolated match, pending full integration checkpoint.
