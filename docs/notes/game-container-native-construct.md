# Native container-base construction at 802563CC

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The isolated native C++ constructor `__ct__22ContainerBase_802563CCFv`
reconstructs all 124 original text bytes with four actual relocations.
Its existing native symbol spelling is preserved. The function calls the
Object constructor, installs the original `802EC720` table, initializes the
three-word pool, constructs the two zeroing handle layers, clears the two
observed flag words and initializes the index at offset `54` to minus one.

The private declaration follows the existing destructor evidence: Object
through offset `48`, pool at `48`, index at `54`, handle at `58`, and opaque
trailing storage. The pool initialization helper accepts its owner so that
table installation precedes pool and handle construction. This helper is an
ordinary C++ implementation detail; it does not establish the original class
hierarchy or complete source-file boundary. The untouched destructor and
factory declarations retain their existing layouts.

The compiler emits two unreferenced weak handle destructors after the complete
native constructor. Their allocated bytes, bindings, extents, hashes and real
relocations are inventoried separately and receive no matching credit. They
must be absent from the final linked ELF. Original tables, shared data,
startup and neighboring functions remain outside this text-only split.

Reproduce the isolated verification with
`python3 scratch/game_container_native_construct/verify.py`.
