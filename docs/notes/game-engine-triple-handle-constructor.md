# Triple-handle record constructor

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/engine_triple_handle_ctor.cpp` reconstructs the complete 136-byte
`fn_8023BD78` extent 8023BD78..8023BE00 as the genuine constructor
`TripleRecord_8023BD78::TripleRecord_8023BD78()`, emitted as
`__ct__21TripleRecord_8023BD78Fv`. It default constructs the three handles at
0/4/8, performs the two observed additional zero stores for each, and clears the
byte at 0x0C. The caller's array construction stride establishes a 0x1C-byte
record; the remaining bytes retain unknown names and remain uninitialized.

Two inline derived handle constructor stages recover the original aliases and
save/restore sequence automatically. The earlier manual-init private probe in
`scratch/engine_tree_records_20261010i` remains untouched. No assembly, aliases,
object patches or register forcing is used.

GC/1.3.2 with standard O4,p/auto inline and exceptions off emits 136 exact
retained bytes and three actual native constructor relocations. Two unused weak
destructor backups occupy another 172 bytes with four actual relocations; their
contiguous extents, weak bindings and raw hashes are inventoried. No retained
relocation refers to them, and they must be discarded without progress credit.
There are no allocated data/BSS objects, metadata or owned padding.

The full original extabindex allocation 80015F60..8001F2C0, including its trailing
descriptor/zeros, and complete .ctors/.dtors allocations
80299920..80299980 / 80299980..802999A0 contain no references to this constructor.
The original caller uses it as an array element constructor callback; that
ordinary text relocation remains inventoried separately. Neighboring functions
and data stay outside this partial text split.

`scratch/engine_triple_handle_ctor_20261010bx` contains the strict manifest,
source/header hashes, real relocation verification, full original table audit,
old-symbol reference inventories and NonMatching split/registration snippets.
No compiled source/header references the old function spelling. `verify.py`
checks every retained and unlinked emission. Central integration owns the
identity migration and full original-DOL hash/regression acceptance.
