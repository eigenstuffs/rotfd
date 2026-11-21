# Group record update

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/engine_group_record_update.cpp` reconstructs the complete entry
`fn_8021B230`, `.text:8021B230..8021B47C` (588 bytes), as ordinary C++.
It refreshes each 156-byte record through the manager at context +0x150,
calls the owner update, then conditionally obtains a temporary handle from
the selected record. On success it replaces two handles on the object
resolved from owner +0x58 and calls its update callback after each assignment.
Finally it resolves owner +0x20 and that object's child handle at +0x30 for
`fn_8023DE28`. Handle replacement releases the old handle and retains the new
one; the function destroys its two-stage zero-initialized temporary on exit.

Inline object operations preserve the destination/source handle lifetimes.
The final child lookup uses the manager's byte-backed storage view; the
previous lookup uses a typed entry view. This reproduces both original loads
of the backing-store pointer instead of merging them through CSE. A direct
byte-offset read of selected-record +0x94 reproduces its indexed load.
The first loop's offset, record pointer, and counter declarations retain the
original register allocation. These are ordinary source/type distinctions;
no assembly, fixed registers, object patching, or aliases are used.

GC/1.3.2 with standard Game flags plus `-use_lmw_stmw on` emits 588 exact
retained bytes and 17 actual relocations. Two normal trailing weak destructors
occupy 172 more emitted bytes with four relocations. All allocated emissions,
symbol extents/bindings, raw weak hashes, and relocations are inventoried.
No retained instruction references discarded weak code. No allocated data,
BSS, exception, constructor, or destructor sections are emitted.

`scratch/engine_group_record_update_20261010bl/verify.py` recompiles production
source and verifies every allocated byte and actual relocation. Full raw
original `extabindex:80015F60..8001F2C0`, including descriptor/trailing zeros,
`ctors:80299920..80299980`, and `dtors:80299980..802999A0` contain no reference
to this entry. The frozen manifest, hashes, ownership audit and all private
probe variants accompany the verifier. Existing external identities are
unchanged. This text-only split does not claim the complete original
translation unit. Central registration and full DOL acceptance remain the
integrator's steps.
