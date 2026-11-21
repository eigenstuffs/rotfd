# Local agent construction in registry setup wrappers

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Six ordinary C++ setup wrappers reproduce 1,536 original code bytes, 408 extab
bytes, 72 extabindex bytes and all 120 real relocations. Production recompilation
checks every emitted allocated byte and symbol extent. No helper, weak backup,
literal or padding is emitted. The original C entry names remain unchanged.

Each wrapper clears its original global word, calls its original setup helper,
constructs a named local agent, and invokes the existing native destructor when
the local leaves scope. The local's 0x88-byte base calls fn80259354. Its inline
Agent80021260 view installs table802B0330, constructs two-store Handles88/8C,
copies the original mutable identity quaternion and zero vectors into90/A0/AC,
clears wordB8 and constructs two-store HandleBC. The derived local installs its
own original table and uses its already accepted native destructor. The
observed derived/base lifetime produces the exact original register allocation,
stack extent and cleanup actions; no placement-new null branch or ABI wrapper
is introduced. All unknown base bytes remain opaque.

| Entry | Cleared global | Setup helper | Existing local destructor |
| --- | --- | --- | --- |
| 80022A8C | 8037755C | 80022C08 | Object80022B8C |
| 80022CAC | 80377560 | 80022E28 | Object80022DAC |
| 80022ECC | 80377564 | 80023048 | Object80022FCC |
| 800230EC | 80377568 | 80023268 | Object800231EC |
| 8002330C | 8037756C | 80023488 | Object8002340C |
| 8002352C | 80377570 | 800236A8 | Object8002362C |

All entries have exactly one declaration and one call in the accepted
agent_type_registry.cpp. Its current source and canonical manifest hashes are
preserved in callable-source provenance; no caller migration or source change
is needed. Every external table, global, setup helper, base body and destructor
retains its existing identity and original ownership. Only actual undefined ELF
symbols become dependencies; local EH object names stay local.

The full original extabindex, constructor and destructor tables are scanned.
Each true 256-byte function extent owns one complete 68-byte extab and 12-byte
index record. No entry appears in a startup table. Every initialized original
data section is scanned for callable word pointers; only the owned extabindex
function pointer is present. These are explicit registry setup calls, rather
than compiler startup entries. Source, verifier, manifest and ownership hashes
are frozen, with empty quoted-header inventories because the private sources
have no includes. The partial units require full central original DOL and
regression acceptance before progress credit.
