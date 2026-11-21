# Python two-object bindings

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Sixty-eight ordinary C++ wrappers match 13,876 original text bytes, 1,360
exception metadata/index bytes and 935 actual relocations in isolated
production builds. Full executable acceptance is pending integration.

The wrappers parse their two original Python-object arguments and convert
both native pointers through the original type entries, in their original
order. Every parsing/conversion failure returns null. Nineteen native methods
return integers, four return floating-point values, twenty-two native methods
return `None`, and twenty-three wrappers use ordinary C++ virtual dispatch.
Signed-byte declarations retain the original scalar sign extension. Opaque
pointer declarations cover only the verified calling ABI, while explicit
eight-byte prefix classes place the virtual pointer correctly.

All first private probes matched. Production sources preserve existing
function identities and external read-only data. There are no locally emitted
strings, data, BSS, padding, or weak helper functions. The final manifest
freezes source/header hashes, accounts for every allocated byte and symbol
extent, records every actual relocation and independently audits each
original exception-index row and both startup tables. The complete original
translation units and their surrounding data remain outside these partial
source splits.
