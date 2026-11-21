# Neighboring state flag refresh

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/engine_basis_flag_refresh.cpp` reconstructs the complete 72-byte
`fn_802397E0` extent at `802397E0..80239828`. It retains the original C entry
identity and owns no data. This neighboring state view is independent of the
resource constructor at `802396D0`; its unknown prefix, flag byte at `0C` and
float at `B0` do not assert a complete class layout.

The function enters its update when bit one is clear and bits six are not both
set, or when the low status mask `0E` equals six. It sets bit one, clears bit two
and writes the original external float `lbl_8037B300` to offset `B0`. The combined
ordinary condition reproduces the original short-circuit branches and early
return on the first source probe.

`scratch/engine_basis_flag_refresh_20261010cc/verify.py` recompiles with standard
GC/1.3.2 engine flags and checks all 72 allocated bytes, the sole global function
extent and its one actual SDA21 relocation. The object emits no other text,
weak helpers, initialized data, BSS, padding or exception/startup metadata.
The complete original extabindex, ctors and dtors allocations were audited,
including descriptor and zero-tail words; none references this extent.

The frozen isolated manifest, split and configuration proposal remain in that
scratch directory. Register NonMatching first and retain the original literal
owner. Central original-DOL hash, regression and production allocation checks
remain the final acceptance gate.
