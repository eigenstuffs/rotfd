# Primary callback reset at 80258654

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Ordinary C++ reconstructs the complete 520-byte callback routine. It calls
base reset, dispatches self slot `68` with zero, clears the resolved primary
object through slot `20`, acquires the index-zero returned handle and copies
it with reference retention. A valid copied handle is dispatched through the
primary object's slot `30` or the secondary fallback, then destroyed.
The validity test is separate from generation-checked resolution, preserving
the original repeated loads and fallback behavior.

Existing frozen handle/manager declarations express the observed bitfields,
16-byte entries, and global manager at `118`. The private virtual interface
establishes only the called self slot. An inline body helper preserves the
native two-temporary order: returned value at stack `0C`, retained copy at
`08`, immediate return-temporary cleanup and final copied-handle cleanup.
No padding, instruction substitution or assembly is used.

All retained allocated bytes, exact function extent and actual relocations
are verified. The compiler's trailing weak handle destructors are inventoried
without matching credit and must be absent from the final ELF. Shared data,
original tables and neighboring functions retain their existing ownership.
Reproduce with `python3 scratch/game_callback_primary_reset/verify.py`.
