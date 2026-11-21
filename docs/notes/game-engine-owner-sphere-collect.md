# Owner sphere collection

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/engine_owner_sphere_collect.cpp` reconstructs the complete ordinary
C++ entry `fn_8024890C`, at `8024890C..80248C58` (844 text bytes).

The entry returns zero unless its 64-bit flags include `0x1000000000`. It
transforms the incoming sphere through the object's cached inverse matrix and
resolves the associated resource handle. It visits owner points until the
point count or output capacity is reached, skips resource status bit `8`, and
resolves each indexed material handle. For material flag `0x200`, it constructs
three points from the owner point and the next pair of bounds vectors, updates
a temporary sphere, and tests strict sphere overlap using squared distance.
The bounds cursor advances for each eligible material, as in the original.

Each overlap appends a 72-byte partial result containing its point, index,
owner/resource pointers, material flags/type and enabled byte. A nonempty result
array is passed to `fn_801DC784`; the entry returns the collected count. Field
names describe observed operations, without assigning a complete gameplay role.
The fourth pointer parameter is unused in the original entry.

The source retains ordinary declaration and lifetime structure. In particular,
the full-expression vector subtraction produces the original 12-byte temporary
and interleaved arithmetic/stores. A named vector local allowed the compiler to
remove those stores and shrink the frame. Ordered locals and the byte offset
cursor over the four-byte index storage reproduce saved-pointer allocation.
The cursor increments before the logical point index, matching the original
loop scheduling. No assembly, register directives or artificial source work
is used.

## Verification and ownership

`scratch/engine_owner_sphere_collect_20261011dr/final_integration.json` is the
frozen isolated handoff. `GC/1.3.2`, standard Game flags and
`-use_lmw_stmw on` reproduce all 844 retained bytes and all 11 real relocation
targets. The verifier accounts for every allocated section and symbol; the
object emits only the retained text. There are no weak backups, initialized
data, BSS, padding, exception tables or compiler startup allocations.
Compile-time checks establish handle/vector/sphere/bounds/result sizes
4/12/16/24/72.

The complete original exception-index, constructor and destructor table
allocations have no references to the entry. The shared context, `game_vec4_zero`
and `lbl_8037B410` remain external with their existing ownership and identities.
Adjacent entries and other original data remain outside this partial unit.
No consumer, shared header, symbol or metadata migration is needed.

Source variants, actual relocation comparisons, full original table audits,
strict scripts and frozen hashes are preserved in the dedicated scratch
namespace. Root performs central registration, promotion, executable hash and
regression acceptance before this handoff contributes progress.
