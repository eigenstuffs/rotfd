# Agent startup sequence

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Five ordinary C++ sources reconstruct original startup functions `80061404`,
`8006F8A4`, `8006FC40`, `8006FFDC` and `80070378`: 588 code bytes and each
complete eight-byte exception record and twelve-byte exception index. They
reset both original globals, invoke the existing agent setup operation,
initialize and destroy the first temporary, then invoke the original setup
and destruction entries for the second temporary.

The first temporary uses the observed `0x90` Agent prefix with native eight-byte
alignment. The first variant initializes its `90` word to -1; the four others
clear its flag and both floating values. Ordinary construction and destruction
restore the original vtable before base destruction with flag 0. A small inline
helper gives this lifetime its original stack position before the later
temporary. Directly declaring both objects in the outer function reverses
their stack slots; those earlier probes are preserved without credit.

The second object views preserve the original `0x98`, `0xA0` and `0xB0` extents
and call their existing original C setup/destruction entries. Destruction uses
the observed -1 argument; no native identity changes or aliases are introduced.
Opaque fields do not claim the original derived class names.

All 59 retained actual relocations, allocated bytes and symbol extents match.
The compiler emits no extra helpers, data, BSS, metadata or padding. Complete
original exception/startup tables, initialized pointer references and source
consumers are inventoried in `scratch/game_agent_startup_sequence/`. Borrowed
globals, constants, vtables and existing operations retain their original
owners. These are partial original translation units; full native production
acceptance passed.
