# Copied queue handle transfer

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/engine_queue_transfer.cpp` recovers the complete 324-byte
`fn_802316F8` extent 802316F8..8023183C. It retains and resolves a copied owner
handle, constructs a temporary copy of the supplied handle, copies that into a
local handle, destroys the temporary, calls `fn_8023297C` with the resolved
object/index/dispatch flag, sets the flag, and destroys the local.

The exact ordinary source follows the previously accepted `fn_80230A34`
three-lifetime pattern. Passing the copied owner handle as a full-expression
temporary to the resolver fixes the exchanged stack slots from the earlier
released `scratch/game_queue_owner_dispatch` probe. That research and the
accepted earlier source remain untouched. The third argument is an integer
index: the callee multiplies it by 0x74 to select a record.

GC/1.3.2 with standard O4,p/auto inline, exceptions off and
`-use_lmw_stmw on` emits 324 matching retained bytes with 12 actual relocations.
Five unused weak destructor backups occupy another 440 bytes with ten actual
relocations. Their contiguous extents, bindings and raw hashes are fully
inventoried; no retained relocation references them, and they must be discarded.
They earn no progress credit. No allocated data, BSS, metadata or padding is owned.

The complete original extabindex allocation 80015F60..8001F2C0, including its
trailing descriptor/zeros, and full .ctors/.dtors allocations
80299920..80299980 / 80299980..802999A0 have no references to this extent.
Neighboring original functions/data remain outside this partial text split.
The original global function spelling is retained; no aliases or central edits
are needed.

Strict source/header hash, allocated section, symbol, real relocation and raw
original table checks are frozen under `scratch/engine_queue_transfer_20261010br`.
Run its `verify.py`; the complete manifest and NonMatching/split snippets are
included. Final original-DOL hash and regression acceptance remain with the
central integrator.
