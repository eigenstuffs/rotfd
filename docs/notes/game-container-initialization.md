# Container initialization and cleanup at 80256448

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The ordinary C++ initialization routine reconstructs all 312 original text
bytes. It clears the observed word at `80378028`, constructs a local Object,
installs `802EC720`, initializes the pool and layered handle, clears flag
words and sets the index to minus one, then performs automatic cleanup.
The native empty element destructor loops and duplicate pointer clears are
preserved. The original function has no direct ownership in the complete
exception index, constructor table or destructor table.

`ContainerInitializationView` is a private partial layout through the handle
at offset `58`, with four trailing opaque bytes. Its declaration expresses
only the automatic object operations observed here and the original stack
allocation. It does not assert the complete original class size or change
the previously matched ContainerBase destructor/factory declarations.
The pool initialization helper installs the owner table before pool and
handle construction; it adds no runtime call or assembly.

The compiler emits 380 trailing weak bytes in three unreferenced destructors.
The frozen manifest accounts for every emitted byte, function binding and
actual relocation; these helpers receive no source credit and must remain
absent from the final linked ELF. Global storage, original tables and
neighboring functions remain outside this partial text-only source unit.

Reproduce with
`python3 scratch/game_container_initialization/verify.py`.
