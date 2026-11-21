# Two low-word flag leaves

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Existing C entries 8004B970 and 800E76F8 each set flag 0x40000000 in the low word of the ordinary 64-bit flags field at offset 0x38. Their twenty-byte frameless bodies are exact with an unsigned-long-long field and normal `|=` statement; the compiler allocates the low-word load in r5 as in the reference. Both names and caller identities remain unchanged.

The two fragments recover forty text bytes with no emitted or owned data, exception metadata, registration pointers, or actual relocations. Strict production verification inventories every function, allocation and byte. The full original extabindex/ctors/dtors table scan finds no ownership records. GC 1.3.2 uses the established container-base flags. Root integration and original DOL hash acceptance remain required for progress credit.
