# Python native pointer-return bindings

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Three ordinary C++ bindings match 936 original code bytes, 60 exception
metadata/index bytes and 60 actual relocations in isolated production
objects. Full executable acceptance is pending.

`fn_800D9668`, `fn_800DAD70` and `fn_800DAEA8` parse and convert their object
argument, call an existing native pointer getter and return either `None`
with an incremented reference count or the original encoded pointer string.
The exact inline formatter receives the type entry before the pointer. This
parameter order lets the compiler retain the native call result in its
original volatile register without a saved-register frame. The shared
factory header and its pointer-string routine remain unchanged.

Initial and reversed-parameter private forms are preserved under
`scratch/game_python_pointer_bindings`. Five direct member-address forms
remain bounded private near-matches, uncredited. The frozen three production
sources account for every allocated byte, symbol extent and actual relocation
and audit every original exception-index row and both startup tables. No
local data, BSS, padding or discarded helper is emitted; existing entry names
and external ownership are preserved.
