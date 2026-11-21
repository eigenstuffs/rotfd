# Bitset find

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/engine_bitset_find.c` reconstructs the complete ordinary C extent `80207B94..80207DE4` (592 text bytes). `include/Game/engine_bitset_find.h` records the observed layout: word count at `00`, capacity at `04`, word pointer at `08`, and logical bit count at `0C`. The entry takes a signed byte selecting set or clear bits and an initial bit index. It searches at or after that index and returns the first matching logical bit index, or `-1` when no valid result remains.

The partial first word masks all lower bit positions. Subsequent words are scanned directly for set bits, or complemented for clear bits. A five-mask inline helper isolates the least set bit and obtains its index using the high halfword, alternating bytes, nibbles, pairs, and single bits. The result is checked against the logical bit count so padding bits in the last word are excluded.

A single signed scan temporary shared by the three paths reproduces the original register lifetimes and zero comparisons. Declaring the word count before the bit shift and the helper result before its isolated mask reproduces native allocation. The bound check returns `-1` first and then the result; this ordinary control flow also reproduces the original return blocks, including their redundant final branch-to-link instructions.

## Verification and ownership

Frozen evidence: `scratch/engine_bitset_find_20261010ai/`. GC/1.3.2 uses the standard Game flags with no extra per-unit flags. `freeze.py` and `verify.py` compile current production source, verify the single global ELF function extent, reject all additional functions and allocated sections, and compare all 592 bytes with the original normalized DOL. This leaf routine emits no relocations and owns no data, BSS, exceptions, constructors, or destructors. No comparison bits are masked.

`audit.py` checks the complete original function range, all 3,141 original exception index records, 24 constructor entries, and eight destructor entries; none references this text. The bitset allocation and all neighboring lifecycle/manipulation functions retain existing ownership. This is a text-only split, not a claim that a full original translation unit has been recovered.

`final_integration.json`, `final_splits.txt`, `final_config.txt`, `scope_edits.txt`, and `ownership_audit.json` contain central integration instructions. `fn_80207B94` requires global scope. The parent integrator performs NonMatching registration, full native DOL hash acceptance, and regression verification before project progress is credited.
