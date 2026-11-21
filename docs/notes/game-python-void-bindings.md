# Python void virtual method bindings

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Thirty-five bindings match 5,600 original text bytes and 700 exception
metadata/index bytes in isolated production builds. All 385 actual
relocations and all emitted allocated bytes are exact; full executable
acceptance is pending central integration.

Each binding parses the existing object argument, converts its native self
pointer with the original type-table entry, invokes a void virtual method,
increments the original `None` object's reference count and returns it.
Parsing and conversion failures return null. Ordinary C++ inheritance places
the vptr after the verified eight-byte prefix; declared virtual slots
reproduce the original indirect dispatch without function-pointer casts.

Every first private probe matched, including the complete exception record
and index. The final manifest freezes production source and unchanged shared
headers and audits every exception-index row and both startup tables.
External strings, type entries and `None` retain their original ownership;
there are no local literals, BSS, padding or discarded helper functions.
