# Scene message record initialization and lookup

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Two partial text splits reconstruct `800C2378` (128 bytes) and `800C1B0C` (76 bytes), with 20 bytes of original EH/index for the initializer. Both use ordinary C++ with the established GC1.3.2 flags.

The initializer calls the native ObjectsOwner reset/flag operations, sets the observed type, ready byte, service and index fields, and copies six externally owned small-data constants into its position and size vectors. The lookup scans 260-byte records, compares the unsigned 32-bit key, returns the inline 256-byte text after the original pointer check, and returns the owner's fallback buffer when no usable record is found.

All compiler allocations, actual relocations, symbol extents and full original exception/startup table ownership are checked. The source borrows the original constants and owns no additional data or weak helpers. The surrounding message-box implementation and original data remain outside these partial splits.

The independent registration probes for `800C7534` and `800C9EC8` remain uncredited: natural borrowed callback pools with `-opt noprop` reproduce the full extents and EH but leave six argument-scheduling words different in each function. Their evidence is preserved separately; no aliases or owned pool bytes were introduced.
