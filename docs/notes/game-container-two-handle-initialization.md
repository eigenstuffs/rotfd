# Two-handle container initialization at 80258948

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_80258948` reconstructs all 436 native text bytes in ordinary C++.
It clears the observed global word, calls the resource initialization routine,
constructs a local base and two handles, sets flags and the minus-one index,
and automatically destroys the handles, pool and Object. The table phases
are `802ED000`, `802EC798`, `802ED000` and `802EC720` around the base lifetime.

The first handle constructor argument installs the derived owner table before
native handle construction. This ordinary initialization expression preserves
the original owner/handle aliases and the direct stack store. The private
layout is limited to the observed base and fields at `60`, `64` and `68`.
It does not establish a complete original class hierarchy. Shared data and
neighboring functions retain their original ownership.

Every allocated byte, function extent and actual relocation is verified.
Trailing weak destructors are inventoried without source credit. The native
ContainerBase weak duplicate is discarded in favor of the existing matching
strong destructor at `8002DF20`; acceptance checks that owner's frozen source,
canonical manifest, complete production allocations and final linked bytes.
Other private weak helpers must be absent from the final ELF. The complete
original exception/startup table audit remains part of central integration.

Reproduce with
`python3 scratch/game_container_two_handle_initialization/verify.py`.
