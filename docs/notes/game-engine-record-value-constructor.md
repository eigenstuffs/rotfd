# Native record value constructor

`src/Game/engine_record_value_constructor.cpp` reconstructs the genuine C++
`Record_80209EA0` constructor at `80226134..8022621C` (232 bytes). The incoming
borrowed handle is followed by one `unsigned long long` value, stored at
`+0x38`; its domain meaning remains unknown. The native identity is
`__ct__15Record_80209EA0FRC15Handle_801F7F10Ux`, replacing `fn_80226134` at the
same original address and extent without an alias or thunk.

This corrects the private, unregistered two-word approximation in
`src/Game/record_constructor.cpp`. Treating the argument as a single 64-bit
value reproduces the original r30/r29 allocation and low-word/high-word store
order. The old source, private header, candidate manifest and research probes
remain untouched and uncredited. The accepted record lifecycle's partial
layout still has the same size, field offsets and destructor identity; it
requires no edit.

The constructor builds the two-layer handle at `+0x40` and three-layer handles
at `+0x44/+0x48/+0x4C`, clears `+0x50`, calls reset `fn_80209F80`, then assigns
the borrowed handle with release/copy/retain and stores the complete value.
The native object remains `0xA8` bytes. Its explicit 64-bit member also explains
the caller's eight-byte aligned record temporary.

The only original call site is `8022F784` in `fn_8022F624`, now source-owned by `src/Game/owner_record_population_8022F624.cpp` in the 2026-10-15 continuation.
`consumer_inventory.json` distinguishes the active split from its stale
surviving assembly copy. No compiled source or header refers to the old
`fn_80226134` identity, so no existing consumer migration is proposed. The
larger DL caller remains private research.

Compile with GC/1.3.2, standard game `-O4,p -inline auto -Cpp_exceptions off`
flags and `-use_lmw_stmw on`. Strict verification matches every retained byte,
function extent and all nine retained real relocations. The complete object
emits only `.text`: 232 retained bytes plus three inventoried, unreferenced
weak handle destructors totaling 264 bytes with six relocations. Those weak
backups are unowned, must be discarded, and receive no credit. There is no
owned initialized data, BSS, padding, exception metadata, constructor table
or destructor table. Full original table allocations, including descriptors
and trailing zeros, were audited with no reference to this range.

Frozen handoff: `scratch/engine_owner_binding_records_20261011dl/constructor/final_integration.json`.
Run `python3 scratch/engine_owner_binding_records_20261011dl/constructor/verify.py`.
This is an isolated retained-byte proof; production acceptance remains with
the integrator's original DOL hash, regression and native discard checks.

The standard build now links this constructor from Matching source. Its native
hash and regression acceptance are preserved by the continuation's current
`build-record-child-promote.log` and `changes-record-child-promote.log`; full
source extents and all 66 tests pass. The old two-word candidate remains
historical and does not add a second source allocation.
