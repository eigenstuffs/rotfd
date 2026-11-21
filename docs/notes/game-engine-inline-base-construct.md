# Inline container base construction

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Two existing native constructor entries are recovered without renaming:
__ct__14Agent_8004E90CFv and __ct__14Agent_8004FAE8Fv. The isolated production
objects match144 and108 original code bytes,40 EH/index bytes each, and all22
actual relocations in aggregate. GC1.3.2 uses the established space optimization,
automatic inlining, exceptions enabled and lmw/stmw flags. No additional
allocated sections or functions are emitted. Central original DOL acceptance
is required.

The inherited private view has a table at8 and observed extent60. The native
ContainerLayer80044168 destructor identity is unchanged. A separate private
RootContainer constructor directly references the existing original
__ct__22ContainerBase_802563CCFv through an extern-C declaration with the actual
one-pointer ABI. This is a reference to the existing native entry, with no alias,
new definition, adapter, assembly or emitted helper. The private root constructor
is inlined; the next inline native layer installs table802ECF88. This additional
ordinary root lifetime reproduces the original separate complete/base pointer
registers, mr-r0 step and r29-r31 save range. The earlier direct external C++
base construction probe omitted that distinction and remains preserved,
uncredited research in the older member setup scratch directory.

The derived constructors install tables802B435C/802B4200 before constructing the
Handle at60. E90C has two zeroing layers, initializes float64 from the original
SDA constant and vector68 from the original mutable zero vector. FAE8 has one
zeroing layer and clears word64 plus original global8037767C. Their observed
private views make no claims about the opaque inherited fields. Genuine
compiler cleanup references the current native layer destructor with its exact
original exception PC/member/register values.

Full extabindex80015F60..8001F2C0 scans establish one record per function at
80017C34/80017CDC with extab80009784/800098DC. Full ctor80299920..80299980 and
dtor80299980..802999A0 scans have no references. True original text extents,
owned local metadata symbols, original unit ownership and actual undefined ELF
dependencies are frozen. Source and recursive quoted header hashes are recorded
in final_integration.json and handoff.json. Existing accepted source, shared
metadata and old frozen artifacts remain untouched.
