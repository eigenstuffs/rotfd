# Container layer initialization at 802558B8

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Ordinary C++ reconstructs all 364 original text bytes of `fn_802558B8`.
The routine clears the word at `80378020`, calls the base initialization
routine, constructs a local container layer, sets the observed flag and
scalar fields, then performs automatic handle, pool and Object cleanup.
The table transition and empty destructor loops retain their native order.

The private initialization view covers the observed base through offset `60`,
then the scalar at `60`, three-layer handle at `64` and words at `68`/`6C`.
Its helper installs the owner table before scalar and handle construction.
These partial declarations do not establish a complete original class
hierarchy or modify existing destructor/factory layouts.

The compiler emits 532 trailing weak bytes. Three private handle destructors
must be absent from the final ELF. The 268-byte weak ContainerBase destructor
shares its native name with the already matching 244-byte strong destructor
at `8002DF20`. The duplicate receives no matching credit. Acceptance verifies
the frozen strong owner's source and canonical manifest, all 296 allocated
code/exception bytes of its production object, and the exact strong function's
binding, address, size and original bytes in the final ELF. This proves that
the new duplicate is discarded while the earlier original definition remains.
Every weak extent, raw hash and actual relocation is inventoried separately;
retained code references none of the trailing weak definitions.

Reproduce isolated verification with
`python3 scratch/game_container_layer_initialization/verify.py`.
Original data, tables and neighboring functions remain outside this text split.
