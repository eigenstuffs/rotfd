# Callback record-owner destruction

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The genuine C++ destructor `CallbackRecordOwner::~CallbackRecordOwner()`
reconstructs the complete 336-byte function originally labeled
`fn_80252670` at `0x80252670..0x802527C0`. It installs the original table,
releases the registered index at `0x20` when the registry exists and the
index is valid, then resets the index to minus one.

Automatic member destruction runs the empty element-destructor loop for
the 20-byte records in the pool at `0x24`, frees its allocation and clears
its pointer twice. Two inlined base-destructor layers install the original
`802EC118` and Resource tables before calling the native Root destructor.
The compiler also generates the original entry null check, signed deletion
flag, optional allocator call and returned object pointer.

Names and surrounding class views remain provisional. The source establishes
only the destructor-accessed fields and the observed lifetime layers. The
original registry, tables, allocator storage and neighboring functions
retain external ownership. Its registered-key caller uses the genuine
compiler destructor spelling at the same address; the caller's allocated
bytes and relocations must be reverified when changing that spelling.

`scratch/game_callback_record_owner_destroy/verify.py` checks the exact
global destructor extent, every allocated byte and all actual relocations
without masks. No other allocation or weak helper is emitted. Full
executable and regression acceptance is required before credit.
