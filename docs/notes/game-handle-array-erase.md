# Compact handle-array erase

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

`src/Game/handle_array_erase.cpp` reconstructs `fn_80260744`, the 292 bytes at
`80260744..80260868`. The receiver's array descriptor begins at `34`. It
compares resolved handles, destroys the first matching element, decrements
the count, and shifts the remaining words through the original `memcpy` call.
The target and each element are resolved in the original order.

The source uses the verified external handle base and an empty derived element
type. Its implicit destructor invokes the base with the native nondeleting
flag and preserves the null check. Keeping the decrement in the `memcpy`
length argument also preserves the native evaluation and load order.

GC/1.3.2 with standard optimized Game flags reproduces all 292 emitted bytes
after four actual relocations are applied. Run:

```
python3 scratch/game_handle_array_erase/verify.py
```

The verifier requires one global function and only `.text`; it checks every
allocated byte and relocation. There are no extra weak functions, constants,
data, BSS, constructor/destructor tables, exception tables, or padding.
`candidate.json` and `actual_relocations.json` preserve the evidence.

`original_metadata_audit.json` additionally records hashes of the protected
DOL's complete original `extabindex` (`80015F60..8001F2BC`, 3,141 function
entries), `.ctors` (`80299920..80299970`, 19 nonterminator entries), and `.dtors`
(`80299980..80299990`, three nonterminator entries). No original exception
range overlaps this function and no startup/shutdown entry points into it.
The metadata descriptor and table bounds are validated directly from the DOL.
The partial text split leaves the other functions, manager storage, startup
metadata, and exception metadata under existing original ownership; it does
not claim the boundary of the original translation unit.

Full DOL linking, native objdiff, source-extent auditing, and regression checks
remain the integrator's acceptance step.

## Accepted integration

The production units were strictly verified before Matching promotion. The
full DOL passes the original SHA-1, `ninja changes` reports no regressions,
source-extent/progress audits pass, and all 26 unit tests pass. Referenced
external data and adjacent original functions remain with their existing owners.
