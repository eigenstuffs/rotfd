# Python three-object bindings

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Fourteen ordinary C++ bindings match 3,544 original code bytes, 280 exception
metadata/index bytes and 214 actual relocations in isolated production
objects. Full executable acceptance is pending central integration.

Each wrapper parses three Python objects and converts them through their
original type entries, preserving conversion order and null returns after
any failure. Three native methods return signed-byte integers, six return
floating-point values and five return `None` after incrementing its reference
count. All first private probes matched. Ordinary compiler optimization also
reproduces the retained type-table pointer across adjacent conversions when
the original uses it.

All production sources, unchanged shared headers, allocated sections, symbol
extents and actual relocations are frozen in the final manifest. Each
original exception-index row and both startup tables are audited. There are
no additional allocations, local data, BSS, padding, weak helpers or symbol
identity changes. Surrounding functions and original data remain outside
these partial source splits.
