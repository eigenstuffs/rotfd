# Platform curve application and action reset

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_8028C058` applies three optional curves to an owner's position, rotation
and scale fields, forwards an optional action curve and then invokes the
existing owner update. The counts at curve offset 4 are signed. Position and
scale reuse one ordinary local three-float vector; rotation uses a separate
four-float local. This shared local lifetime reproduces the original stack
slots without assembly or artificial padding. The three scalar parameters and
two opaque action arguments retain their original ABI and order.

`fn_8028C1C4` forwards the curve at platform offset 0x3c to the existing reset
routine. These names describe observed field and call use; wider class
hierarchy and the action arguments remain unresolved.

The two separate source objects own 364 and 36 text bytes respectively, with
five and one real REL24 relocations. No data, literals, BSS, weak helpers,
exception records or startup entries are emitted or credited. Isolated
allocated-section bytes, symbols and relocations match at original addresses.
The full original exception-index, constructor and destructor tables are
scanned before integration. Other platform functions and original class data
remain outside these partial translation units.
