# Controller recalibration and polling

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Accepted production integration passes the original full-DOL SHA-1,
`ninja changes` with no regressions, source-extent/progress audits and all
26 unit tests. The final canonical manifest is `config/GSQE78/candidates/game-controller-poll.json`.

`src/Game/controller_poll.cpp` reconstructs two consecutive engine functions:

| Function | Original range | Bytes |
| --- | --- | ---: |
| `fn_802763D0` | `802763D0..802764B0` | 224 |
| `fn_802764B0` | `802764B0..8027658C` | 220 |

The first combines the original per-controller masks and requests
`PADRecalibrate` if the combined mask is nonzero. The second reads four raw
PAD statuses, resets each active 64-byte controller record and invokes the
existing update routine. Its signed-short index and reloaded signed count
preserve the native iteration behavior.

The record layout has six shorts at `10`, sixteen byte flags at `1C` and a
ready byte at `30`. Reset writes all sixteen flags, clears each three-short
group through chained assignment (third component first), and sets ready.
The receiver's record pointer is at `8` and raw status storage starts at `20`.
Static checks enforce both record and receiver sizes.

GC/1.3.2 with standard optimized Game flags reproduces all 444 emitted bytes
after seven actual relocations. Run:

```
python3 scratch/game_controller_poll_pair/verify.py
```

The verifier checks both global symbols, every allocated byte and relocation,
and requires `.text` only. There are no extra weak functions, constants,
data, BSS, constructor/destructor tables, exception tables or owned padding.
`original_metadata_audit.json` records protected-DOL original extabindex,
`.ctors` and `.dtors` hashes and bounds; no exception entry overlaps these
functions and no startup/shutdown entry points into them. `candidate.json`
and `actual_relocations.json` preserve the full isolated evidence.

This partial text split leaves the original mask array at `802ED6E8`, SDK
functions and neighboring engine routines in existing ownership. Full DOL
linking, native objdiff, source-extent auditing and regression checks remain
the integrator's acceptance step.
