# Python scalar field and method bindings

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Thirty-seven Python bindings have exact isolated production C++ matches,
totalling 5,240 text bytes and 740 bytes of original exception metadata and
index entries. Full executable acceptance is pending central integration.

Each wrapper parses its existing tuple format, converts its Python object
through `fn_800CD864` with the original type-table entry and error flag, and
returns a Python integer. Failed tuple parsing and conversion return null.
Five wrappers read an integer field; twenty-two call a native scalar method;
ten use ordinary C++ virtual dispatch through the original vptr at offset
eight. Signed and unsigned narrow return declarations reproduce the original
sign-extension and masking instructions. Unknown class members and unused
virtual slots remain explicitly unspecified views rather than full class
reconstructions.

The first five private field probes differed only in stack-slot ordering.
Declaring the output native pointer before the parsed Python pointer restores
the original two local slots. All subsequent scalar method and virtual probes
matched their first bounded source forms. No assembly, injected words,
relocation masking, local data, BSS or discarded helpers are involved.

`scratch/game_python_scalar_bindings/final_integration.json` freezes all
production source/header hashes, exact allocated sections, symbol extents,
and 355 actual relocations. Every original exception-index row and both
startup tables were independently audited for references to each retained
range. Existing C entry names and read-only format/type-table ownership are
preserved. The existing Python factory header is included unchanged.
