# Masked sphere collision dispatch

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_80244710`, original GLOBAL `.text` range `80244710..80244C00`, has an
isolated ordinary C++ reconstruction in `src/Game/engine_sphere_mask_dispatch.cpp`.
This handoff verifies all 1,264 emitted bytes and all 18 actual relocations.
Production adoption and the full DOL hash check remain the integrator's work.

The entry rejects masks without a collision category and disabled records,
refreshes the object's inverse matrix when needed, and transforms the query
sphere. It rejects non-overlapping bounds before dispatching to the selected
geometry representations. The category and geometry tests are full 64-bit
operations. The final collector call supplies the function's return value.

The overlap helper is significant ordinary structure: it forms a radius sum,
binds a const reference to the vector difference temporary, and compares the
squared distance with the squared radius. That lifetime retains the original
three vector stores. The strict less-than success test preserves the native
NaN behavior. Keeping this as an inline sphere-overlap operation also reproduces
the original floating-point allocation, without register constraints. Arithmetic
uses separate multiply/add operations (`-fp_contract off`).

The dedicated header contains partial offset views, with uncertain members
named or grouped by their observed positions. The sphere and vector have genuine
copy constructors, reproducing the native hidden-return temporary and subsequent
copy. This is a text-only partial translation unit; it does not claim a recovered
complete original class or source-file boundary. Existing callers and external
C-entry identities remain unchanged.

Compiler: GC 1.3.2, `-O4,p`, exceptions off, RTTI off,
`-use_lmw_stmw on`, `-fp_contract off`. There are no emitted literals, initialized
data, BSS, exception tables, constructor slots, weak backups, or helper bodies.
The complete original extabindex, ctor and dtor allocations were audited; none
references this function. The unchanged strict ELF verifier checks the sole
allocated section, complete symbol inventory, every resolved relocation, and a
fresh production compilation identical to the frozen object.

`lbl_801E9D24` remains a borrowed original GLOBAL text-resident context label.
The active original assembly object owns its complete 616-byte allocation
`801E9D24..801E9F8C`; the new partial view reads only the pointer at `+134`.
The label has no asserted object size, and no storage bytes receive credit.
Both original external vtable pointers to `fn_80244710` remain unchanged. The
active ELF census excludes stale assembly and inventories all current defined,
undefined and relocation references. No accepted source, shared declaration,
central symbol or consumer migration is needed.

Evidence is frozen in `scratch/engine_sphere_mask_dispatch_20261011kf/`:
`final_integration.json`, `allocation_inventory.json`, `consumer_inventory.json`,
`borrowed_data_provenance.json`, the full original-table audit and the original
function fixture. `verify.py` recompiles and repeats the complete comparison.
All unsuccessful ordinary probes are preserved alongside the exact probe.
