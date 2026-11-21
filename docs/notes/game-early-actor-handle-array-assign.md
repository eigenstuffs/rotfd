# Actor Handle-array copy assignment

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The ordinary typed array implementation matches fn_8008AC5C (536 bytes) plus its original28-byte extab and12-byte index with GC1.3.2 processor750/O4,s. It resets the destination, calls the adjacent capacity operation, then copies each retained four-byte Handle into newly constructed storage, growing capacity in blocks of eight. It returns the destination.

Genuine default/copy construction and empty destructor layers reproduce the original zero stores, nullable cleanup checks and retained base-destruction EH. An ordinary inline constructAt(element*) helper closes the five register operands left by direct placement in the growth loop. No register forcing or instruction payload edits are used.

Retained EH resolves the weak backup Handle_80020834 destructor to its accepted real GLOBAL116-byte owner, recompiled and strictly verified from its individual canonical. All backup code/EH/index and unused relocations are inventoried without credit; final native discard is mandatory. No data, literals, BSS or padding is owned. Original C entry and external identities remain unchanged; central original-DOL acceptance remains pending.
