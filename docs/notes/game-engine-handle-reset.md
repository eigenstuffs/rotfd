# Engine handle array reset

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Two ordinary C++ routines are recovered as partial text-only splits:

| Function | Text range | Bytes |
| --- | --- | ---: |
| `fn_801B4230` | `0x801B4230..0x801B4350` | 288 |
| `fn_801B4350` | `0x801B4350..0x801B4494` | 324 |

Strict production recompilation verifies all 612 retained text bytes and 17
actual relocations. No additional functions, weak cleanup functions, data,
BSS, exception records or constructor references are emitted or owned.
CodeWarrior GC/1.3.2 uses standard game flags. All external entry-point names
are preserved; private type names carry their entry-point addresses.

Both routines resize the dynamic native handle array at owner `+0xB8` to zero.
Its count is at `+0xB8`, capacity at `+0xBC`, and storage pointer at `+0xC0`.
The generic resize preserves the signed growth path for negative counts, the
conditional capacity release through `fn_8028FD50`, forward placement
construction, reverse destruction, and the original count stores. Declaring
the established `Handle_801F7F10` constructor and destructor directly emits
the original native ABI calls at `0x801F7F04` and `0x801F7F10`. Wrapping the
native destructor in another inline C++ destructor introduces an extra null
check and does not match.

`fn_801B4230` resets the array first. When owner `+0xC4` is nonnull, it calls
`fn_802086C8(control,1)` and `fn_80208768(control,1)`, then clears the pointer.
It finally calls `fn_801E9F8C` and writes one to `lbl_80377F90`.

`fn_801B4350` calls `fn_802086C8(control,1)` before iterating the handles. It
resolves each through `fn_801F7EB8` and calls virtual slot `+0x10` through the
resolved object's vtable at `+8`. It then resets the array, calls
`fn_80208768(control,1)` and clears the control pointer. The private virtual
layout defines only the observed slot order.

Both functions originally belong to the 2,172-byte assembly fragment starting
at `0x801B4230`. Its remaining functions keep original text ownership. The
fragment has no data. `ownership_audit.json` records all original section
ranges, complete retained function extents, and exhaustive exception-index
and constructor-pointer checks.

Frozen handoff files are under
`scratch/game_engine_handle_reset_continuation/`: `final_integration.json`,
`final_splits.txt`, `final_config.txt`, and `ownership_audit.json`. The manifest
freezes production source SHA256 and recursive quoted-header hashes (empty).
`verify.py` recompiles the production files and verifies every allocated byte
with applied real relocations. Full DOL hash and regression acceptance remain
the central integrator's job.
