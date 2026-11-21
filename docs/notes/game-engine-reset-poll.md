# Engine reset polling and retained region

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Frozen isolated handoff: four ordinary C++ units, four original functions,
1,292 text bytes, zero owned data and 113 real relocations. There are no extra
functions, weak destructors, emitted data or padding. Existing external names
are preserved. Sources are `src/Game/engine_reset_poll_*.cpp`.

Exact integration, frozen production source SHA-256, recursive quoted-header
hashes (none), complete emitted allocations and actual relocation lists are in
`scratch/game_engine_reset_poll_continuation/final_integration.json`. Adjacent
`final_splits.txt`, `final_config.txt` and `ownership_audit.json` document the
proposed integration and original section ownership.

| Function | Text bytes | Real relocations | Observed behavior |
| --- | ---: | ---: | --- |
| fn_801EBB9C | 300 | 28 | Poll reset switch and flags, dispatch reset sequence, consume one-shot byte |
| fn_801EBCC8 | 332 | 31 | Same reset processing after waiting for the original retrace flag to clear |
| fn_801EBE64 | 432 | 38 | Save a buffer in the retained arena region and perform the original restart sequence |
| fn_801EC044 | 228 | 16 | Validate retained length and copy its payload into a caller buffer |

Both polling routines interpret the reset-switch result and original state
bytes as signed chars. The branch structure preserves the original repeated
checks of `lbl_803780C0`, updates `lbl_80377FC9` only on the observed path, and
sets `lbl_80377FC0` for the observed release condition. Reset dispatch logs using
the original logger at global offset +110, makes the display black, flushes and
waits for retrace, finishes and aborts GX drawing, disables the locked cache and
PAD recalibration, then selects the original reset type from the disc check.
The original one-shot byte `lbl_80377FC8` is returned and cleared. The second
routine additionally waits while `lbl_80377FC1` remains set.

The retained region starts at arena high minus 0xFA00. Its first word stores the
payload length; payload begins at +4. Zero and 0xDEADBEEF lengths select the
original empty/invalid path. Saving copies the requested payload or clears the
remaining 0xF9FC bytes, logs the request, opens the original path in a local
32-byte name buffer, and invokes the existing disc-read routine using the
observed 60-byte file-info storage and four-byte request. It releases the owned
global pointer at +158, sets the one-shot byte, blackens the display and finishes
drawing, registers the original save interval, then performs the original reset
calls. The two identical disc-dependent reset branches are preserved.

The restore routine rejects either invalid header value, logs the requested and
stored lengths, and copies the smaller signed length using the original branch
structure. It returns the original zero/one success value. Existing allocator,
logger, SDK functions, strings, arena globals and disc buffer retain ownership
outside these partial text splits.

## Verification

GC/1.3.2 uses the ordinary `-O4,p` flags with C++ exceptions off. No additional
optimization or register-save flags are required. An explicit local pointer to
the original shared string region reproduces the save routine's address reuse
and stack layout. All production sources were recompiled after private naming
and formatting. The copied strict verifier applies every actual relocation and
compares all original bytes, symbol extents and allocated sections. No masking
or extracted assembly is used as matching source.

The full original exception index and constructor table were audited. None of
the four functions owns an exception record or startup constructor entry.
Original split units own only text. Other original functions remain outside
these proposed splits. `verify.py` passes all four production units; root must
perform the complete DOL hash, native match regression and extent checks before
promotion. No shared metadata or full link was changed by this agent.
