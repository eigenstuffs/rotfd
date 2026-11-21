# Scalar and record vector copy assignment

The isolated ordinary C++ reconstruction in `src/Game/engine_record_vector_copy.cpp`
retains both complete original entries:

| Original entry | Range | Text bytes |
| --- | --- | ---: |
| `fn_80249250` | `80249250..802495A0` | 848 |
| `fn_802495A0` | `802495A0..80249924` | 900 |

Each entry clears its destination count while retaining storage, sets capacity
from the source count, then appends every source element and returns the
destination pointer. The vectors contain a signed count, signed capacity and
data pointer. The first element type is a two-byte scalar; the second is a
28-byte record copied as seven interleaved float loads and stores. The semantic
meaning of those fields is not established.

The ordinary template follows the already verified native-handle array template
in `engine_handle_arraycopy_801D1D6C.cpp`, specialized for these two trivial
element types. It preserves the original empty construction/destruction loops,
allocator paths, postincrement placement construction and capacity growth by
32 elements. Both source definitions must appear in reverse original address
order: this compiler emits the second entry first. No explicit code ordering,
assembly, register directives or synthesized padding is used.

`GC/1.3.2`, the standard Game flags and `-use_lmw_stmw on` reproduce the original
prologues. Compile-time checks establish element sizes 2/28 and vector size 12.

## Isolated verification

`scratch/engine_record_vector_copy_20261011do/final_integration.json` inventories
all allocations and symbols. `verify.py` recompiles the production source,
resolves every actual relocation and compares the complete retained bytes with
the verified original DOL. All 1,748 text bytes and 78 actual relocations match.
There are no weak backup functions or other allocated sections, data, BSS,
padding or compiler startup entries. Full original exception-index, constructor
and destructor table allocations have no references to either function.

The allocator context `lbl_8028F698` and allocator functions keep their existing
identities and owners. No consumer migration or shared metadata edits are
required. Adjacent functions and all original data remain outside this partial
translation unit.

Research probes, the original table audit, strict verifier, section/relocation
inventory and frozen content hashes are retained in the dedicated scratch
directory. This handoff establishes isolated source equivalence; root performs
central NonMatching registration, promotion and full executable acceptance.
