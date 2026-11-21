# Timed sparse callback update

`src/Game/sparse_callback_update.cpp` reconstructs `fn_8026847C`, the 448-byte
function at `8026847C..8026863C`. When the signed active flag at `C10C` is
nonzero, it visits occupied callback records. A record whose duration exceeds
the original threshold at `8037B648` accumulates the incoming float step.
When its elapsed value strictly exceeds the duration, the routine resolves
its object's related handle, invokes virtual slot `44` with the context
pointer and releases the occupied bit while decreasing the used count.

The source reuses the read-only layout definitions from
`sparse_callback_drain_internal.h`; its dedicated containing view adds the
observed active flag. Records and iteration state retain the same offsets as
the drain routine. The original threshold is the float represented by
`.float 0.000001`; it is referenced through its global symbol and retains
original data ownership. The following four bytes in that original object
also remain outside this unit.

GC/1.3.2 with the standard optimized Game flags emits exactly 448 text bytes,
one global function and five actual relocations. These are two bit-search
calls, the manager global's high/low address halves, and an SDA21 reference
to the original threshold. The verifier applies all five, using the target
r2 base `803801C0` for the actual SDA21 relocation, then compares every emitted
byte to the verified original DOL:

```
python3 scratch/game_sparse_callback_drain/verify_update.py
```

The complete object emits no weak function, constant, data, BSS, constructor/
destructor entry, exception table or alignment padding. Generated original
assembly references are ordinary calls and definitions, with no constructor
entry to transfer. `update_candidate.json` and
`update_actual_relocations.json` preserve the acceptance evidence.

This source is integrated and accepted by the full executable build. It owns only
this text function and leaves all original data and adjacent code outside
its partial split. No original translation-unit boundary is claimed.

Accepted continuation checkpoint: the native build reproduces the original
DOL SHA-1 `5da8295a79bf297ab62c620e6ac66210be1c6ef5`; `ninja changes` reports
no regressions, the source-extent audit passes, and generated progress checks
pass. The original denominators remain unchanged.
