# Callback retained Handle dispatch

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_80040758` is recovered as a separate unchanged C entry: 244 text bytes,
132 original exception bytes, a 12-byte exception index, and 24 actual retained
relocations. Its frozen production proposal is in
`scratch/game_engine_callback_handle_followup_continuation/handoff.json`.

The routine invokes the original base callback, copies the owner's four-byte
Handle at offset four through two scoped copy layers, destroys the first copy,
then passes a third scoped copy to the original record service with the result
of virtual query B8. The final third and retained second copies are destroyed
in their original order. A named const reference to the owner member preserves
the observed source-address lifetime. Explicit conversion to the trivial
native Handle base view prevents elision of the second copy and selects the
actual retaining constructor for the third copy. The vptr is observed at
offset eight. Names are unchanged and all opaque fields are private views.

Genuine Handle_80020478 inheritance and scoped temporaries reproduce every
instruction, exception action and actual relocation. The compiler emits a
112-byte weak destructor plus its 40-byte exception record and 12-byte index,
with seven backup relocations. These receive zero credit and require complete
final discard. Retained cleanup resolves to the existing accepted strong
Handle destructor at 80020478 under the unchanged
production-defined-weak-eh-override-v1 schema. Its canonical source, recursive
headers, complete production object, fresh compiler object, all original owned
bytes and actual relocations are independently checked. No gate extension is
required. An isolated native MWLD link selects that strong owner and discards
all three backup allocations; all retained metadata relocations match and a
wrong fixture basename rejects. Full original-placement game acceptance is
the integrator's remaining requirement.

Full original exception-index, constructor-table and destructor-table scans
find exactly the original exception entry and no constructor/destructor table
pointer. Original initialized data references and compiled consumers are
inventoried in ownership_audit.json. All original data and external function
ownership remains unchanged.

The separate `fn_80042260` investigation is uncredited. The established
signed 24-bit Handle index, signed generation byte, 16-byte manager entries,
scene/settings pointers and three zeroing inheritance layers recover the
observed operation. Ordinary inline helper forms reach the native 224-byte
extent and correct saved registers; the early independent manager/scene loads
still have different scheduling and volatile register assignments. The
original cleanup pointers identify native Handle_80021B54 and Handle_80025BF4,
but no source proposal or identity change is made for this near-match. All
variants remain preserved privately.
