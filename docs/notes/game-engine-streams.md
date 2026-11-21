# Engine stream readers and viewport setup

Production integration is accepted. The canonical manifest is
`config/GSQE78/candidates/game-engine-streams.json`. The complete DOL passes its original SHA-1,
`ninja changes` shows no regressions, source extent and progress checks pass,
and all 26 unit tests pass.

This tranche reconstructs seven ordinary engine functions (1,844 text bytes)
under `src/Game/engine_streams_*`. These are provisional partial text units;
they do not establish original translation-unit boundaries. The source preserves
the original global entry points and calls the existing versioned dependencies.

The frozen handoff is
`scratch/game_engine_streams_continuation/final_integration.json`, with exact
split and configure snippets in `final_splits.txt` and `final_config.txt`.
The source compiles with GC/1.3.2 and the standard game flags. Only
`fn_801B4B38` additionally requires `-opt nocse`.

| Entry point | Text bytes | Recovered behavior |
| --- | ---: | --- |
| `fn_801B311C` | 364 | Read scalar headers and three counted curve arrays, resizing each before reading its records. Observed record strides are 28, 80, and 140 bytes. |
| `fn_801B4B38` | 128 | Read a buffer element count, set up its storage, and copy the byte count returned by the existing size query. |
| `fn_801C98BC` | 240 | Read scalar fields, a family of embedded curve records, and one resource handle. |
| `fn_801C9A2C` | 116 | Require at least two entries in the observed state, then invoke service slots 0x14 and 0x18 with its selected value. |
| `fn_801CA3A4` | 284 | Read nine handle fields, a contiguous scalar block, and two 64-byte payloads. |
| `fn_801DC4E0` | 264 | Read a scalar block, thirteen embedded curve records, and a resource handle after the existing base reader. |
| `fn_801E1658` | 448 | Set up one through four viewport records and assign their owner. The three-view layout places its lower viewport centrally. |

The stream routines retain the cursor returned by `fn_801E9F40` after every
copy. The contiguous block lengths use the observed first/last field addresses;
ordinary unsigned address subtraction retains the original instructions. This
tranche does not claim the separately owned cache-helper implementation called
by these readers.

`fn_801C9A2C` uses a private C++ declaration with the observed eight-byte prefix
before its virtual pointer. Its declarations generate the original indirect-call
sequence without defining or taking ownership of a vtable. All other units are
ordinary C. Uncertain object fields retain observed offsets; class names and
behavior labels are provisional.

## Verification and ownership

`python3 scratch/game_engine_streams_continuation/verify.py` recompiles all seven
production sources and strictly verifies their complete allocated sections,
function names/bindings/offsets/sizes, and **78 actual relocations** against the
normalized reference DOL. No relocation bits are masked and no unexpected
allocated section is accepted. The finalizer repeated this verification after
formatting the production sources.

`ownership_audit.json` independently records every original unit section range
and verifies the original assembly function extents. A complete scan of the
original `.extabindex` and `.ctors` found **no exception records or startup
references for these seven functions**. Each new unit owns exactly its emitted
`.text`; original neighboring functions and data retain their existing assembly
ownership. This handoff changes no shared symbols, splits, build registration,
progress totals, or expected executable hash. The integrator must perform the
whole-DOL hash and regression checks before crediting the new sources.

## Preserved research

The scratch directory retains unsuccessful hierarchy flag-transfer, pool-slot
replacement, and array-cleanup probes. They are not part of the handoff and earn
no matching credit. The flag-transfer family needs different mask/load emission;
the pool family reaches the original operations but retains different register
assignments; inlined array destructors retain a subobject pointer across a free
call. Their bounded failures are preserved for later compiler/layout research.
