# Single collected record event: 8003F5F4

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The ordinary C++ production source strictly matches 684 original code bytes, 32 bytes of exception metadata and its 12-byte index, including sixteen retained actual relocations. The compiler also emits an uncredited weak Array destructor: 220 code bytes, 40 bytes of exception metadata, a 12-byte index and ten actual relocations. All six retained/backup allocations and every relocation are inventoried. The existing strong destructor remains at its original address; no new source credit is claimed for that body or the backup.

The routine returns zero when the service count at +0x860 is less than one. Otherwise it constructs an empty three-word Handle array and collects type14 from the context's resolved Handle pointer at +0x08. It requires exactly one result. On success, it resolves that result's Handle at +0x130 twice and dispatches event0x8F with the unchanged external float at 80378514. The array is destroyed on both result paths, releasing each four-byte Handle and freeing capacity-sized storage through the existing allocator. It returns one after dispatch.

A staged integer-return resolver cast to a pointer at the call or target boundary preserves the original conditional-zero instructions, scratch-register lifetimes and repeated entry reloads. Returning a pointer from every helper emitted 672–676 bytes and different operands; the bounded genuine Word-return view closes every difference without assembly or register forcing. The array and its two Handle destruction layers reuse the established accepted Array_80039AEC view. Other observed storage ends at context+0x0B, service+0x863 and node+0x133; these are minimum private views.

| Section | Original range | Bytes |
| --- | --- | ---: |
| `.text` | 8003F5F4..8003F8A0 | 684 |
| `extab` | 8000865C..8000867C | 32 |
| `extabindex` | 800174CC..800174D8 | 12 |

The existing strong `__dt__14Array_80039AECFv` at 80039AEC is selected from the accepted legacy aggregate `game-nested-lifetime-destructors.json`. Its complete production object and fresh independent recompile match original bytes, all ten actual relocations and GLOBAL FUNC identity. A new exact-source outer selector in this scratch namespace selects only that source/native identity, preserving every old ELF/EH/native core and loader. The gate pins compiler/source/owner evidence while excluding the mutable accepted note from persistent authorization.

An actual MWLD fixture selects the accepted production strong owner and discards all three backup code/EH/index allocations. Retained exception relocations resolve exactly to that strong function. The wrong fixture basename rejects, and the isolated ELF explicitly rejects as a full original-placement proof. Nine guard tests pass eight positive and 1,495 negative cases covering every manifest/owner scalar, accepted canonical selection, actual ELF mutations, native identities and persistent compiler hashes.

The full original exception-index/startup tables and initialized-data pointer words were audited. Only the owned index references this body, and no startup entry transfers. The current original callback registration at 8007F028 has two actual relocations constructing the preserved C entry pointer at 8007F298/8007F2A0; its current-input evidence and original assembly snapshot are preserved. External float, allocator, tables and all unrelated function/data ownership remain unchanged. No shared declaration or identifier migration is required.

Frozen evidence is under `scratch/game_early_single_record_event_continuation`. The exact source-bound aggregate/legacy gate must be reviewed and routed by the integrator; full-game native backup discard and original GLOBAL placement, the original DOL hash, regression checks and tests remain final acceptance requirements. `verify.py NEW_DIRECTORY` recompiles all original bytes and actual relocations; `native.py NEW_DIRECTORY` repeats the bounded real-link proof. Established GC 1.3.2 space optimization, exceptions and lmw/stmw are used.
