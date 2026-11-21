# Callback dispatch through returned handles

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Three complete functions reconstruct 912 text bytes: `fn_802575CC` (308),
`fn_80257700` (296), and `fn_80257828` (308), covering
`0x802575CC..0x8025795C`. Each checks owner handle `0x60`, obtains a handle
by value from the original indexed accessor, creates a typed copy, and
checks that copy before resolving the receiver and dispatching it. The
first and second invoke target virtual slot `0x34`; the third invokes slot
`0x30`. The second supplies zero for the first forwarded value.

The accessor uses the native hidden return pointer. C++ temporary cleanup
passes native destructor flag 0 after the full initialization expression;
the surviving typed copy has the same cleanup flag on both early return
and normal dispatch. These are actual C++ constructors/destructors. Private
prefixes describe only observed fields and virtual signatures; original
complete class identities and data remain external.

The final sources use three separate text units. Combining these functions
causes this compiler to reverse strong-function order and interleave unused
weak code; the failed grouped object and exact differences are preserved in
scratch. Each final object contains its exact strong entry followed by four
unused weak destructors totaling 348 bytes. Their full extents, bindings and
raw hashes are inventoried, excluded from credit, and required absent from
the linked executable. Retained relocations never refer to them.

`scratch/game_callback_return_dispatch/verify.py` recompiles the frozen
sources and accounts for every allocated byte, all complete function extents
and actual relocations without masking. The central integrator audits the
complete original exception/startup tables and requires the original DOL
hash, source extents, no baseline regressions, progress exports and tests.
