# Early owner pointer assignment

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The routine at`8006BA70..8006BB44` resolves its native virtual Handle, stores the supplied owner at actor offset`3C4`, sets the selected byte`390` from the owner Name comparison, and marks byte`3D2` when an owner is supplied. It returns signed byte1. Existing caller declarations and compiled consumers are preserved.

GC1.3.2 O4,s with exceptions owns212 exact text bytes and the complete8-byte exception record plus12-byte index. The verified existing partial pointer/Handle/Name header is reused unchanged. Context and selected-name literals remain original external data. There are no extra weak allocations, owned literals, BSS or padding. Full original exception/startup descriptor and padding scans, every initialized byte offset for function pointers, exact symbol/instruction extents and all actual relocations pass. This is a partial text split; surrounding functions and original tables remain outside it.

Isolated evidence is in`scratch/game_early_owner_pointer_assign/`. Complete production hash, regression and native checkpoint acceptance remain required.
