# Four-row queue reset

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/engine_queue_grid_reset.cpp` recovers `fn_80231330`, the complete
508-byte extent 80231330..8023152C. It resets the resolved parent's scalar,
constructs one empty handle for virtual replacement, and clears either one row
or all four rows of the 4x8 handle array. Each row's state and flags are cleared,
its active handles are assigned empty full-expression temporaries, optional
virtual replacement receives the row index, and the count is cleared.

The exact source applies the native inline Handle bitfield construction and
external destructor behavior established by the adjacent queue reset. The
loop temporaries have distinct stack slots in the two branches, while the
shared named empty handle remains live through both branches. All three stack
lifetimes call the native destructor with mode -1 naturally.

GC/1.3.2 with standard O4,p/auto inline, exceptions off and
`-use_lmw_stmw on` emits exactly 508 text bytes and nine actual relocations.
Every allocated section and sized symbol is checked. There are no additional
weak bodies, initialized data, BSS, source objects, metadata or owned padding.
The full original extabindex allocation 80015F60..8001F2C0, including descriptor
and trailing zeros, and full .ctors/.dtors allocations
80299920..80299980 / 80299980..802999A0 contain no references to this extent.

The global original function name is retained. This partial text split leaves
all neighboring functions and data under existing ownership. No central
configuration was edited by the worker. The complete manifest, source/header
hashes, strict verifier, table audit and NonMatching/split snippets are frozen
under `scratch/engine_queue_grid_reset_20261010bs`. Run its `verify.py` to
reproduce the isolated proof. Final original-DOL hash and regression acceptance
remain the central integrator's step.
