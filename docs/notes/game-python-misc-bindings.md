# Additional Python field, scalar and virtual bindings

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Twenty-two ordinary C++ wrappers match 3,860 original code bytes, 440
exception metadata/index bytes and 261 actual relocations in isolated
production objects. Full executable acceptance is pending integration.

The wrappers cover native-object global assignment, a validation-only call,
an inline string field, a signed-field predicate, an integer field setter,
twelve integer-argument virtual setters and five mixed-argument methods.
Mixed forms retain string/halfword/signed-byte arguments, short/byte options
and two optional float defaults. The two float defaults read their original
external SDA constants; the wrappers emit no new literal data. Python
integer conversion occurs before the native call, and `None` results retain
the original reference increment. Every parsing/native conversion failure
returns null.

Every successfully compiled first source form matched all original bytes.
A temporary missing declaration in the optional-float virtual probe was
corrected before compilation; no near-match was promoted. The final manifest
freezes all production sources and unchanged shared headers, accounts for
every allocated byte, symbol extent and actual relocation, and audits each
original exception-index row and both startup tables. Existing entry names
and global/data ownership are preserved, with no BSS, padding or weak helpers.
