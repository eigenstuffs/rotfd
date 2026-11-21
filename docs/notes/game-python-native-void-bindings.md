# Python native void method bindings

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Forty-six ordinary C++ wrappers match 7,204 original text bytes, 920 original
exception metadata/index bytes and 552 actual relocations in isolated
production objects. Full executable acceptance is pending.

Each wrapper parses its existing object/scalar arguments, converts the native
self pointer, calls the existing native method, increments `None`'s reference
count and returns it. The wrappers preserve zero, one or two native scalar
parameters, including mixed byte/halfword and float/halfword forms. Their
original tuple argument order is preserved independently of stack layout.
All parsing/conversion failure paths return null.

Forty-five initial private probes were exact. The remaining wrapper,
`fn_800D1024`, requires its optional integer argument to be initialized to
zero, reproducing the original extra store and instruction scheduling.
Initial evidence remains in
`scratch/game_python_native_void_bindings/initial-probe-results.json`.

The final manifest freezes every production source/header and accounts for
all allocated bytes, symbol extents and actual relocations. Every original
exception-index row and both startup tables were audited. There is no local
data, BSS, padding or discarded helper code. Existing entry names, native
dependency identities and read-only external formats/type data are preserved.
