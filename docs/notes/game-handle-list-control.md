# Handle list control passes

`src/Game/handle_list_control.cpp` reconstructs `fn_80268364`, the 280-byte
function at `80268364..8026847C`. It performs two passes over the handle list
at object offset `C100`: the first resolves each handle and invokes
`fn_801EDB54` with the incoming float; the second resolves every handle and
invokes `fn_801EDD8C`. These are ordinary calls with the observed argument
layouts; their higher-level purpose remains inferred.

The source reuses the read-only layout and inline handle-resolution definitions
from `handle_list_operations_internal.h`. Isolating the second pass in an
inline helper reproduces its independent loop-counter initialization and
register allocation. Both passes preserve the original unchecked inline
resolution behavior, including forwarding a null result to the callee.

GC/1.3.2 with standard optimized Game flags emits exactly 280 text bytes, one
global function and four real relocations (two calls and the manager global's
address halves). The verifier applies every relocation, compares the complete
text to the verified original DOL and rejects any other allocated bytes:

```
python3 scratch/game_handle_list_operations/verify_control.py
```

There are no weak functions, constants, data, BSS, constructor/destructor
entries, exception tables or alignment padding. Generated original assembly
references are calls and definitions, with no constructor-table ownership to
transfer. `control_candidate.json` and `control_actual_relocations.json` in
the same scratch directory record the isolated acceptance evidence.

This source is integrated and accepted by the full executable build. It is a partial
text split; neighboring functions and all original data remain outside it.

Accepted continuation checkpoint: the native build reproduces the original
DOL SHA-1 `5da8295a79bf297ab62c620e6ac66210be1c6ef5`; `ninja changes` reports
no regressions, the source-extent audit passes, and generated progress checks
pass. The original denominators remain unchanged.
