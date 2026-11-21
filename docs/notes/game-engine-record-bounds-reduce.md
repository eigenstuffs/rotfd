# Copied record bounds reduction

`src/Game/engine_record_bounds_reduce.cpp` reconstructs ordinary C++ at
`fn_80249D58`, `.text` range `80249D58..8024A040` (744 bytes). It starts with a
zero-centered sphere, selects the original empty radius or virtual sphere,
then reduces transformed copied records from the second and first arrays.
Each 24-byte record contains an identifier, retained handle, and sphere. The
resolved object's matrix at +0x124 transforms that sphere before combination.
The completed sphere is written back to self +0x10.

A genuine copied handle derived from a zero-initializing native handle layer
reproduces construction, retain and the original two duplicate null branches
on destruction. The enclosing record uses normal member copy construction and
automatic destruction. No explicit branch, barrier or assembly recreates the
compiler's destructor pattern. A single shared loop index reproduces the
original second-loop setup scheduling; separate scoped indices differed by
four instruction words. Normal aggregate sphere returns and member assignment
produce the exact original float loads, stores and temporary stack offsets.

Compile with GC/1.3.2 standard game `-O4,p -inline auto -Cpp_exceptions off`
flags plus `-use_lmw_stmw on`. Strict verification proves all 744 retained
bytes, the complete function extent and every one of sixteen retained actual
relocations. The object emits only `.text`: 744 retained bytes followed by
three fully inventoried, unreferenced weak destructors totaling 276 bytes and
six relocations. These weak backups must be discarded and earn no credit.
No retained relocation targets one of those backups.

The original external `game_vec4_zero` BSS object and four-byte constants
`lbl_8037B428`/`lbl_8037B42C` retain their existing owners and addresses. This
partial source split owns no data, BSS, padding, exception metadata or startup
table. The complete original extabindex, constructor and destructor tables,
including descriptors and trailing zeros, were audited with no reference to
the retained range. Adjacent original functions remain outside this unit.

Frozen handoff: `scratch/engine_record_bounds_reduce_20261011dn/final_integration.json`.
Run `python3 scratch/engine_record_bounds_reduce_20261011dn/verify.py`.
The handoff remains an isolated retained-byte proof until the integrator's
production original-hash, regression and native-discard checks accept it.
