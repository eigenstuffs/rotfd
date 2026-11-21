# Native handle copy constructor pair

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The isolated C++ sources recover `fn_8023F578` (8023F578..8023F5EC) and
`fn_8023F5EC` (8023F5EC..8023F660), 116 bytes each. Both construct a native
Handle, clear its zero-base word, copy the supplied four-byte value, and retain
the supplied handle in the context manager. The zero-base constructor and
separate derived copy body reproduce the two destination aliases in the
original. These are genuine C++ copy constructors with native identities:

- `fn_8023F578` → `__ct__19HandleCopy_8023F578FRC19HandleCopy_8023F578`
- `fn_8023F5EC` → `__ct__19HandleCopy_8023F5ECFRC19HandleCopy_8023F5EC`

The exact emitted names are recorded in the frozen manifest and take precedence
if the readable spelling above is changed during research. No aliases, thunks,
fixed-address objects, or central configuration changes are used here. Neither
old spelling appears in current compiled source or headers; original active
split-assembly references are inventoried for central migration.

Both source units use GC/1.3.2 with standard O4,p/auto inline flags and C++
exceptions disabled. Each retains 116 original text bytes with four actual
relocations and emits an unreferenced 84-byte weak zero-base destructor with
two additional relocations. Every allocated section and sized symbol is
inventoried. The weak backups must be discarded, and earn no credit.

The complete original extabindex allocation 80015F60..8001F2C0, including its
trailing descriptor and zeros, and full .ctors/.dtors allocations
80299920..80299980 / 80299980..802999A0 contain no references to these extents.
There is no owned initialized data, BSS, metadata or padding. This is a partial
text split; neighboring original functions and data retain their current owners.

Reproduce the strict checks with
`python3 scratch/engine_handle_copy_pair_20261010bp/verify.py`.
The manifest, original reference inventory, source/header hashes, relocation
records and table audit are in that scratch directory. Central integration and
the final original-DOL hash check remain the integrator's acceptance step.
