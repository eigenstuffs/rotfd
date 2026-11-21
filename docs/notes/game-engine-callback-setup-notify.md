# Callback copy setup and Handle notification

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Two separate functions are proposed in the frozen
`scratch/game_engine_callback_setup_notify_continuation/handoff.json`.
They retain every existing callable and data identity and require no shared
header change, symbol rename, adapter extension, or additional data ownership.

`fn_8004086C` retains 180 text bytes, 40 exception bytes, its 12-byte exception
index, and 14 actual relocations. It constructs a four-byte Handle copy using
the existing 80040B14 constructor, constructs a second copy using 80040920,
destroys the first temporary, performs two original virtual queries at slot B8
and service notifications, and destroys the retained second copy. A private
trivial word base view expresses the observed const-Handle conversion between
the two copy layers. The constructor overloads call the unchanged original
native entries. The Object_80040AA4 destructor remains external and unchanged.
The first temporary is converted explicitly to its Handle base reference;
this prevents eliminating the distinct second copy construction. Genuine
virtual declarations at vptr offset eight reproduce the native dispatch.
No weak code or additional allocated sections are emitted.

`fn_8004FD30` retains 228 text bytes, 44 exception bytes, its 12-byte index, and
18 actual retained relocations. It releases/replaces/retains the Handle at
offset 60, converts the original floating query to integer mode at 64, and
for mode one resets a service and submits a scoped copy of the owner's Handle
at offset four. The established typed Handle_80020478 constructor/destructor
shape reproduces the saved temporary pointer and destructor flag zero. The
named const reference to the original owner member preserves its lifetime.

The latter object emits one weak Handle_80020478 destructor, 112 text bytes
plus 40 exception bytes and a 12-byte index, with seven backup relocations.
All are separately inventoried and earn zero credit. Retained exception
cleanup resolves to the already accepted original strong destructor at
80020478 using the existing production-defined-weak-eh-override-v1 schema.
Its frozen canonical source, recursive quoted headers, complete production
object and fresh compiler output are independently verified against all owned
original bytes and actual relocations. No new verifier gate is proposed.
An isolated actual MWLD link proves all three backup allocations discarded,
the original strong owner selected, and retained exception relocations exact;
the wrong fixture basename rejects. The integrator must repeat the complete
native map/ELF audit at original placement and full original DOL hash checks.

Full original exception-index, constructor-table and destructor-table scans
find exactly each retained exception record and no constructor/destructor
table entry. Initialized data pointers and compiled consumers are inventoried
in ownership_audit.json. Any remaining original tables retain their original
assembly ownership. These are partial original translation units.

Research at `fn_8004C8E8` remains uncredited: genuine full 0x70 object storage,
observed 64-bit flags at 38, and three original member-pointer records recover
the object stack offset and copy order, but the original hoists the data-anchor
address before two calls. Ordinary pointer/reference/view and inline-helper
variants remain different. A native constructor declaration did not close
the difference; no corresponding identity migration is proposed. All failed
probes, including the initial one-byte empty tag allocation at 8004086C, are
preserved as research only.
