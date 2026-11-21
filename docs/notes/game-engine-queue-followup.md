# Engine queue updates and record dispatch

Accepted production integration passes the original full-DOL SHA-1,
`ninja changes` with no regressions, source-extent/progress audits and all
26 unit tests. The final canonical manifest is `config/GSQE78/candidates/game-engine-queue-followup.json`.

This batch reconstructs **six complete original functions, 1,180 text bytes,
and zero data bytes** in three partial source fragments. The canonical handoff
is `scratch/engine_queue_followup_20261010b/final_integration.json`, accompanied
by `final_splits.txt`, `final_config.txt`, `scope_edits.txt`, and
`ownership_audit.json`. All new scratch, source, header, and note paths were
checked absent before creation. Earlier handoffs were not modified.

| Source fragment | Complete functions | Text extent | Bytes |
| --- | --- | --- | ---: |
| `engine_queue_followup_80230C18.cpp` | `fn_80230C18` | `80230C18..80230CE8` | 208 |
| `engine_queue_followup_80231D8C.cpp` | `fn_80231D8C`, `fn_80231E4C`, `fn_80231F34`, `fn_80231FB8` | `80231D8C..8023203C` | 688 |
| `engine_queue_followup_8023203C.cpp` | `fn_8023203C` | `8023203C..80232158` | 284 |

## Observed behavior

The queue update skips a dirty queue, an empty cursor, or a zero scalar value
at the preceding cursor position. When its target handle passes original
`fn_801F7EB8`, it resolves that handle through the original manager, calls
`fn_802073E8` with the preceding scalar value and original float constant, and
sets the dirty byte. A direct conditional expression at the call site retains
the native argument scheduling; an inline resolver call chose different
registers despite producing the same text extent.

The four adjacent dispatch functions test the handle at offset `1F8`, resolve
its signed 24-bit index and signed generation byte, then dispatch to virtual
slots `4C` and `48`, or original `fn_802139D8` and `fn_80213A18`. The five-float
wrapper preserves the native `_savefpr_27` and `_restfpr_27` helper calls.

The record loop constructs 64 local work records of size `2C` using the
original array helper and `fn_801C6968`. It caches the source count and record
pointer, walks `50`-byte records, checks each signed short index against the
handle list count, resolves the indexed handle, and calls `fn_801AED04` for
non-null targets. Each call receives the local work array, a reset output
integer, and all three float parameters. The original upper-bound-only index
check is preserved.

`include/Game/engine_queue_followup.h` declares observed prefixes and external
functions. It does not define virtual implementations, constructors,
destructors, or tables. Size checks cover the recovered handle, entry, queue,
and record layouts; these declarations do not claim complete original class
layouts or translation unit boundaries.

## Verification and integration

`python3 scratch/engine_queue_followup_20261010b/verify.py` recompiles all three
production sources with GC/1.3.2 and checks every allocated section, all six
function bindings, offsets and sizes, and **27 actual relocations**. REL24,
HA/LO, and SDA21 relocations resolve to their versioned original targets before
byte comparison; no instruction bits are masked. The objects emit only the
claimed text, with zero data, exception, startup, or compiler helper sections.
The physically adjacent four-function fragment uses identical standard flags.

The record loop alone needs `extra_cflags=["-use_lmw_stmw", "on"]`. The other
two fragments use standard engine flags. The manifest includes `-i include`
for isolated compilation; the normal project build already supplies it.
Register the three objects as `NonMatching`, set all six entry-point symbols
to global scope, and carve only the listed text ranges. Full DOL hash and
regression acceptance remain the central integrator's responsibility.

`audit.py` checks complete original `.fn` / `.endfn` extents and fallback
ownership, all **3,141 twelve-byte original extabindex records**, and complete
original `.ctors` and `.dtors` sections. No exception or startup record refers
to these six functions. The original global manager, float constants, virtual
tables, virtual functions, and neighboring code retain their prior owners.

## Private probes

Grouped queue update `80231600` remains sixteen instruction words away,
consisting of nonvolatile register allocation differences. The adjacent
record copy loop `80232158` is nine words away, swapping the resolved owner
and record-offset registers. Both retain ordinary C++ sources, original
assembly, and real relocation comparisons in this scratch directory. Neither
is submitted or credited as matching source.
