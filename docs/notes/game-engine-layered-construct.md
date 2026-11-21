# Layered object and secondary-base construction

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Two isolated ordinary native constructors match 328 original code bytes,
96 extab bytes, 24 extabindex bytes and all 22 real relocations. Production
recompilation accounts for every emitted allocation and symbol extent. No weak
backup, helper, literal or padding is emitted. Full central original DOL
acceptance remains required.

27268 constructs the existing Objects802EB7C0, installs table802EB518,
constructs three-store Handle1F8 and two-store Handle230, then initializes its
observed word fields2F8..308 and byte30C. The native class identity
Objects_802EB518 is already established by its accepted destructor at80026CF8.
The proposal therefore uses __ct__16Objects_802EB518Fv at the original address.
Its inline base wrapper calls the already accepted native constructor
__ct__15Object_800272F0Fv with the same original ABI. The compiler emits exact
DESTROYBASE to existing Objects802EB7C0 and member cleanup to Handle80021B54.

The full Objects802EB7C0 extent is0x1F8, established by the first derived member
at1F8 and the accepted original factory allocation. Its older isolated
construction/destruction views only observed fields through1B0 and therefore
establish a minimum0x1B4 view; those frozen files remain unchanged. The full
Objects802EB518 extent is0x318, established by its original factory allocation
and the following constructor's secondary-base call at318. Unknown tails are
explicitly opaque in these new private declarations.

9A9D8 constructs Objects802EB518 and secondary Object8007D594 at318, installs
its two original tables, and constructs four-store Handle348 before its scalar
and vector initialization. The native secondary base extent remains0x2C; an
explicit derived opaque344..348 gap precedes the Handle. Native base and
member destructor identities remain unchanged. Mutable vectors and external
small-data constants retain their original owners. Only actual undefined ELF
symbols are dependency entries. The in-batch native base dependency carries
its own original_symbol=fn80027268 guard.

Both proposed native constructor names have original_symbol guards. The complete
compiled consumer inventory includes two factory sources plus four accepted
setup sources. Each old identifier occurs exactly once as a declaration and
once as a call in its source. Current source and canonical manifest hashes are
frozen per consumer, including aggregate setup manifests. Root's accepted
identifier-only migration gate must preserve original/current snapshots and
prove unchanged allocated bytes, symbol extents and resolved relocation targets
for every consumer before central staging. This handoff changes no consumer or
shared metadata. The existing void-returning setup declarations may ignore the
native constructor's return pointer without changing the observed call ABI.

The ownership audit confirms each true function extent, complete EH/index
ownership, full original startup-table scans and initialized-data pointer
inventory. No startup table references exist; only each owned extabindex
function pointer appears in initialized original data. All external data and
base bodies remain outside these partial units. Source, verifier, manifest and
ownership hashes are frozen; recursive quoted-header inventories are empty.
