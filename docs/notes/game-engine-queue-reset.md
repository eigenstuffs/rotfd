# Queue reset

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/engine_queue_reset.cpp` recovers `fn_80230DF8`, the complete
388-byte original extent 80230DF8..80230F7C. It clears the queue state/flags,
replaces each active array handle with an empty handle, clears the count,
resets a resolved parent's scalar, and optionally replaces one indexed handle
or every handle through virtual slots 0x2C and 0x38.

The loop requires a full-expression `Handle_801F7F10()` temporary. A named
scoped local produces the same operations with the loop and later conditional
handle stack slots swapped. The inline native Handle constructor initializes
the index and generation bitfields; its external destructor naturally emits
mode -1 for both stack lifetimes. No manual destructor wrapper is needed.
The manager lookup compares the stored generation and returns null on mismatch,
as observed; there is no additional bounds check.

GC/1.3.2 with standard O4,p/auto inline, exceptions off and
`-use_lmw_stmw on` emits exactly 388 text bytes and seven actual relocations.
There are no other allocated sections, weak function backups, source objects,
initialized data, BSS or padding. The full original extabindex allocation
80015F60..8001F2C0, including descriptor/padding/trailing zeros, and full
.ctors/.dtors allocations 80299920..80299980 / 80299980..802999A0 contain no
references to the function.

This is a partial text split. All neighboring functions/data remain under their
current ownership. The original global function spelling is retained, and no
central configuration is edited by the worker. Strict source/header hash,
allocated section, sized symbol and relocation checks are frozen under
`scratch/engine_queue_reset_20261010bq`; rerun `verify.py` there. The manifest,
NonMatching registration, split snippet and complete table audit accompany it.
Final original-DOL hash and regression acceptance remain the integrator's step.
