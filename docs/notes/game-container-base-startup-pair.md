# Container base startup pair

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`container_base_startup_8025E31C.cpp` and `container_base_startup_8025E5FC.cpp`
reconstruct two original 252-byte startup functions. The original library
code uses speed optimization and disables C++ exceptions. Those native
compiler settings reproduce the complete empty-element loop, including its
ordinary compiler unrolling, without generating exception allocations.

Each routine clears its original global, invokes the existing setup operation,
then constructs and destroys a temporary derived ContainerBase. Ordinary
inheritance and member destructors preserve both derived vtable stores,
base vtable restoration, two-layer Handle cleanup, array release and Object
base destruction. All 24 retained actual relocations and all 504 retained
allocated code bytes match exactly. No data, BSS or padding is owned.

Each object also emits an unused 276-byte weak ContainerBase destructor with
ten relocations. The original strong destructor remains its already accepted
244-byte source owner at `8002DF20`; fresh compilation, production object
equality, complete allocated bytes and actual relocations are independently
verified and pinned. The two backups receive no credit and no retained
reference targets either copy. The existing generic weak-backup verification
and strong-owner acceptance route are used unchanged; full native acceptance
passed.

Complete original exception/startup table scans find no references to either
function. Original initialized pointer references and every current source
consumer are inventoried in `scratch/game_container_base_startup_pair/`.
Borrowed globals, vtables, constructors, allocators and base operations retain
their original owners and identities. These are partial original translation
units.
