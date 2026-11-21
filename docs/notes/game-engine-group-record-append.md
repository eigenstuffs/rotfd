# Group record append

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/engine_group_record_append.cpp` reconstructs the complete entry
`fn_8021AFE0`, `.text:8021AFE0..8021B230` (592 bytes), using ordinary C++.
It appends a 156-byte record to the owner array at +0x4C (growth 24), then
appends its address to the pointer array at +0x38 (growth 32), returning the
pointer-array index. Both arrays retain the original allocation, reallocation,
and zero-capacity free paths.

The implicit record copy reproduces the original 16-iteration paired-word
loop for the first 128 bytes, three scalar words, an unsigned halfword, and
two independently retained handles. The first handle has a zero-initializing
base stage and the second zeroes in its copy body. This distinction preserves
the two original destination-pointer lifetimes. Natural alignment padding at
+0x8E remains uncopied. Passing the newly formed record pointer directly to
the second inline append reproduces the original temporary lifetime; naming
that pointer changed exactly two register operands.

GC/1.3.2 with standard Game flags plus `-use_lmw_stmw on` emits 592 exact
retained bytes and 24 actual relocations. Three normal trailing weak
destructors occupy 256 further emitted bytes and have six relocations. Their
symbol extents, weak bindings, raw hashes, and relocations are inventoried;
no retained instruction references them. The compiler emits no allocated
data, BSS, exception records, constructor or destructor sections.

The strict verifier and frozen integration manifest are in
`scratch/engine_group_record_append_20261010bk/`. Verification recompiles the
production source, checks every allocated emission and actual relocation,
and scans complete original `extabindex:80015F60..8001F2C0` (including its
descriptor/trailing zeros), `ctors:80299920..80299980`, and
`dtors:80299980..802999A0`. None references the retained entry. Existing
external identities remain unchanged. This is a partial text-only original
translation-unit split; adjacent functions and original data remain outside
it. Central registration and full DOL acceptance remain the integrator's steps.
