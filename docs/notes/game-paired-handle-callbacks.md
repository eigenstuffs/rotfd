# Paired handle callbacks

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Accepted production integration passes the original full-DOL SHA-1,
`ninja changes` with no regressions, source-extent/progress audits and all
26 unit tests. The final canonical manifest is `config/GSQE78/candidates/game-paired-handle-callbacks.json`.

`src/Game/paired_handle_callbacks.cpp` reconstructs `fn_8027224C`, the 272 bytes
at `8027224C..8027235C`. The receiver holds two handle-array pointers at `9F0`
and `9F4` and a signed count at `9F8`. Each iteration resolves the second
array's handle and invokes virtual slot `1C`, then does the same for the first
array's handle. It reloads the count after callbacks, preserving mutation
behavior.

The object interface preserves an eight-byte nonpolymorphic base followed by
the virtual pointer at `8`; five unnamed slots precede the observed callback.
The declarations emit no vtable or method bodies. Actual virtual dispatch is
needed to reproduce the native pair of `r12` loads; an explicit function-pointer
table was four register differences away and is preserved privately.

GC/1.3.2 with standard optimized Game flags reproduces all 272 emitted bytes
after both actual manager-address relocations. Run:

```
python3 scratch/game_paired_handle_callbacks/verify.py
```

The verifier requires exactly one global function and `.text` only. There are
no extra weak functions, data, BSS, constants, constructor/destructor tables,
exception tables or owned padding. The complete protected-DOL extabindex,
`.ctors` and `.dtors` audit finds no overlapping exception entry or startup /
shutdown reference. `candidate.json`, `actual_relocations.json` and
`original_metadata_audit.json` preserve that evidence.

The partial text split leaves neighboring functions, manager storage and
original virtual tables in existing ownership. Full DOL linking, native
objdiff, Source-extent and regression acceptance has passed.
