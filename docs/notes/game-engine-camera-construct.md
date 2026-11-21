# Derived camera scalar and Handle construction

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The isolated ordinary C++ constructor800758B0 reproduces584 original code
bytes,108 extab bytes,12 extabindex bytes and all32 real relocation targets.
Production recompilation verifies every emitted allocated byte and symbol
extent. No helper, weak backup, literal or padding is emitted. Full central
original DOL acceptance is required before credit.

The private baseObject80075AF8 has the established0xC4 extent from the original
CameraEngineZone factory allocation and this constructor's first derived byteC4.
Its inline constructor calls the proposed native constructor at80075C2C through
its exact extern-C identity; its existing native destructor is unchanged. The
corrected75C2C full-extent handoff is a dependency of this unit. Unknown base
bytes remain opaque.

The derived view declares only observed scalar, flag, vector and Handle fields,
with explicit opaque gaps. Member initializer expressions preserve ordinary
initialization before the first Handle134, before Handle1EC and before
Handle230. Handles1F0/234 follow with their normal default initialization. The
first Handle uses existing native Handle80020C04; the other four use native
Handle80020B90. Every Handle has its original two-store zeroing sequence. The
constructor finishes by setting byte238/value23C, byteC4=1 and wordC8=70, then
copying the original D8/DC/E0 scalar triplet into vector100. The reconstructed
extent0x240 agrees with the original factory allocation.

All scalar constants are external original small-data objects and the zero
vector is the original mutable global. Actual relocation verification preserves
all loads, including the repeated vector address computations and update load.
The compiler emits the exact existing base and member cleanup actions and
original metadata bytes. Original external data and all base/destructor bodies
remain outside this partial unit. Only actual undefined ELF symbols become
external dependencies; local exception object names stay local.

The native constructor proposal carries original_symbol=fn800758B0. Its sole
accepted source consumer is factories8007E160.cpp, with one declaration and one
call. Current source/canonical hashes and the two occurrences are frozen for
root's accepted identifier-only migration gate. The native75C2C dependency
carries its original_symbol guard as well. No consumer, shared declaration or
central metadata is edited by this handoff.

Full original extabindex and constructor/destructor startup tables are scanned,
confirming true code extent and one complete owned EH/index record. No startup
reference exists. A scan of every initialized original data section finds only
the owned extabindex function pointer. Source, verifier, manifest and ownership
hashes are frozen; recursive quoted-header inventories are empty because the
private source has no includes.
