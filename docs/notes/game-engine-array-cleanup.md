# Engine array cleanup

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Two complete ordinary C routines contribute 596 text bytes in independent
partial text splits, using standard Game GC/1.3.2 flags without additions:

| Source | Function | Original text |
| --- | --- | --- |
| `src/Game/engine_array_cleanup_records.c` | `fn_8024D3AC` (208 bytes) | `8024D3AC..8024D47C` |
| `src/Game/engine_array_cleanup_owner.c` | `fn_802499CC` (388 bytes) | `802499CC..80249B50` |

Both symbols require global scope. The dedicated new header is
`include/Game/engine_array_cleanup.h`; no shared existing declarations change.

The first routine destroys each occupied 16-byte element through existing
`fn_801D4BDC(element, -1)`, then frees the storage through the original allocator
`lbl_8028F698`, using capacity times 16 for the allocation size. It clears the
items pointer and conditionally deletes the array object through existing
`fn_801EF610` when the signed short deleting argument is positive.

The second routine restores the external original vtable `lbl_802EC268` at
owner offset 8, destroys its array of 28-byte records at offset 0x30, then its
array of two-byte records at offset 0x24. It calls existing base cleanup
`fn_801CF8D4(self, 0)` before optional deletion. Both arrays use signed counts
and capacities with a pointer at offset 8. Their element types have trivial
cleanup; ordinary empty element loops reproduce the compiler's original
unrolled count loops. The logical inline cleanup helpers emit no extra
functions. Array pointer resets, including the repeated reset after conditional
storage release, follow the original destructor behavior.

`scratch/engine_array_cleanup_20261010o/final_integration.json` records exact
extents, bindings, flags, and all 19 actual address relocations. Fresh production
compilation and strict verification pass: every byte with actual REL24, HA, LO,
and SDA21 relocations equals the protected original DOL, without masking. The
verifier rejects additional functions and unexpected allocated sections. The
original whole-function audit and complete 3,141-entry extabindex, 24-entry ctor,
and 8-entry dtor scans pass with no references to either selected function.
Source data, BSS, exception, and startup ownership are zero. Vtable data,
allocator data, callees, neighboring text, and other original sections retain
their current owners. Central NonMatching registration and final DOL/native
regression acceptance remain the integrator's promotion steps. All probes and
verification artifacts are preserved.
