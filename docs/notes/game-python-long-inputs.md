# Python integer-object argument bindings

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Twenty-five ordinary C++ wrappers match 4,124 original code bytes and 500
exception metadata/index bytes in isolated production objects. Full
executable acceptance is pending central integration.

The wrappers parse their original native-self and Python-integer arguments,
convert self, call `PyInt_AsLong`, then pass either the full integer or its
signed-byte conversion to an existing native method. Eleven return Python
integers, one returns a Python float, and thirteen return `None` after
incrementing its reference count. Both parsed pointers retain their original
zero initialization; parsing and native conversion failures return null.

All first private probes matched. The frozen production manifest records
source/header hashes, every allocated byte, symbol extent and actual
relocation. Each original exception-index row and both startup tables were
audited. There is no local data, BSS, padding, weak helper or entry-name
change; external format/type-table data retain their original ownership.
