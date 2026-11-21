# Copied resource arrays and named flag updates

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Isolated matching source is ready for central integration. The two independent
ordinary C++ units reconstruct fn_80086958 (600 bytes) and fn_80086F00 (628
bytes), each with its original 24-byte extab and 12-byte index. GC1.3.2,
processor750, O4,s, C++ exceptions and lmw/stmw produce exact retained bytes and
actual relocation targets. No source progress is claimed before full native
placement and original-DOL acceptance.

Both routines copy the selected actor's retained record array, visit each record,
compare its resolved resource Name with a borrowed string, and set flag0x40000 on
matching resources. They then update controller/monitor state. The second also
clears the actor's wide flag0x1000000000 and saves/replaces the controller mode.
The borrowed strings, globals and callback records remain original data.

An ordinary signed entry-tag getter with a separate int local closes the array
resolver's five scratch-register differences. Distinct concrete entry object
types preserve the native reload in the Name/flag lookups. The second routine's
four-byte SDA string declaration preserves its original SDA relocation. A short
loop index assigned to a separate int retains the native narrowing operation.
Genuine array construction/destruction supplies the original cleanup timing.

Retained EH refers to the accepted GLOBAL240-byte Array_80025634 destructor. Its
canonical is a legacy aggregate, so the fresh source-bound outer gate selects
only that exact original owner for these two exact sources and preserves the
existing strict ELF, EH, opt-in and native checker cores unchanged. All strong
owner sections, actual relocations and deterministic production/recompile bytes
pass. Each source emits a weak240-byte destructor plus40-byte extab and12-byte
index; these292 bytes are uncredited backups. Both actual isolated MWLD links
select the existing strong owner and discard all three backup allocations.
Central dual native maps/ELFs must repeat discard and original-address checks.

The complete original EH records and descriptor, constructor/destructor tables,
and initialized pointer words were audited. Original GLOBAL callback records
lbl_802B8DE4[28] and lbl_802B8DB4[28] retain the unchanged function pointers at
802B8DF0 and802B8DC0. No callers or shared identifiers migrate. No owned data,
literals, BSS, padding, aliases or object payload changes are introduced.

Evidence is in scratch/game_early_resource_named_flag_controls and frozen
handoff scratch/game_engine_batch191. Ten guard tests accept11 exact cases and
reject2746 mutations of manifests, strong owner selection, production objects,
real relocations, retained/backup metadata, native identities and input hashes.
SDK independent read-only review found no gate blocker. Original placement,
full-DOL hash, baseline, extents, progress and repository tests remain central
acceptance requirements.
