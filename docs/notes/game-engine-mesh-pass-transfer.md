# Mesh pass transfer

`fn_80280174` (`80280174..802802C8`) is an isolated ordinary C++ reconstruction
of a 340-byte mesh-part transfer loop. All allocated bytes, function extents
and nine actual ELF relocations match the original. The source is ready for
root integration; this isolated proof does not claim final DOL acceptance.

The routine snapshots the part count, visits matching part and pass handles,
and processes type-six parts unless the resolved pass sets flag `1` or
`0x40`. It installs the existing 48 KiB scratch buffer in the renderer state,
prepares the indexed part, flushes that buffer and submits the part/pass pair.
The original two nullable-pass checks remain separate in source.

Distinct concrete `PartEntry::object` and `PassEntry::object` pointer types
preserve the native entries-array reload between the two adjacent resolves.
The loop retains both an element index and a byte offset. Declaring the count,
offset and index before initializing the latter two in the `for` expression
preserves their native register lifetimes and initialization order.
The dedicated header contains offset-based partial object/manager views.

The compiler is Game `GC/1.3.2 -O4,p` with `-use_lmw_stmw on`. It emits only
the single global C entry: no extra helpers, data, BSS, exception tables or
static initializer/destructor records. The full original extabindex, ctor and
dtor audits find no ownership for this entry. Complete active-object and
original branch/data scans find one original direct call to its entry and
no external interior reference. Existing source callers and declarations
require no migration. The original function identity stays unchanged.

This text-only split owns no shared storage. In particular, scratch buffer
`lbl_80341360` (`80341360..8034D360`) remains wholly original and uncredited.
All adjacent functions and original data remain outside the unit.

Frozen source/header/object digests, all-section allocation/symbol inventory,
actual relocations, consumer census, complete original tables and bytewise
original-data/branch audits are in
`scratch/engine_mesh_pass_transfer_20261011gz`. Its `verify.py` recompiles the
production source and checks all allocated bytes/targets and frozen hashes.
Earlier private variants are preserved without credit.
