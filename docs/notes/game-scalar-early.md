# Additional early scalar operations

This continuation adds **92 complete original functions, 4,228 text bytes,
and 12 startup-table bytes in 69 bounded fragments** under
`src/Game/scalar_early_*.c`. It supplements the previously accepted leaf
batches without changing their sources or manifests. Each new source owns
one physically contiguous recovered range and retains the original
versioned function entry names.

Recovered behavior includes ordered vector copies, scalar vector scaling
and accumulation, nested record byte iteration, selected record access,
global equality predicates, signed halfword updates and clamping, fixed
record loops, validated handles, word-pair flag updates, object scalar
initialization, and global state transitions. Private record declarations
expose only demonstrated offsets, strides, and argument widths. Unknown
regions remain padding; names are provisional.

The related global halfword accessors follow the observed global pointer at
`lbl_801E9D24 + 0x124`, its pointer field at offset `0x15058`, and halfword
arrays at offsets `0x148` and `0x1AC`. Selected nested records additionally
use the signed index at offset `0xF0`, the pointer at offset `0x138`, and a
`0x94`-byte record stride. The next-byte functions preserve the bounded
counter, caller output write, counter increment, nested 32-byte record
selection, and final byte load, including repeated reads required when
output aliases the object.

The global record flag functions at `0x800B41A0..0x800B423C` retain the
bounded 300-record key search, 80-byte stride, and independent enabled,
previous, and changed bytes at offsets `0x4C..0x4E`. The timer update at
`0x800CB5A4` retains the ordered comparison selecting which timer field
is decremented. Vector arithmetic keeps the original separate single-
precision operations and demonstrated load/store ordering.

The original isolated startup units `fn_80024DB4`, `fn_8005BF6C`, and
`fn_80090060` own `.ctors` entries at `0x80299928`, `0x8029992C`, and
`0x80299930`. Each source preserves its entry using an ordinary C function-
pointer initializer. Their initialized arrays and referenced constants
remain external original objects. `ownership_audit.json` records the
original active fallback unit and all section ranges for every recovered
function. All other selected original units own zero non-text bytes;
exception data and surrounding original objects remain untouched.

All objects use Game GC/1.3.2 flags. Seven fragments add `-opt space` to
preserve the original counted fixed loops instead of the compiler's speed
unrolling. This override is recorded in each affected manifest entry and
in `final_config.txt` as `extra_cflags=["-opt space"]`. The whole recovered
fragment, including every instruction and owned startup byte, is verified
with those exact flags.

Canonical handoff files are
`scratch/game_scalar_early_continuation/final_integration.json`,
`final_splits.txt`, and `final_config.txt`. No new symbol edits are needed.
Earlier probe manifests are superseded by the final grouped manifest.
`python3 scratch/game_scalar_early_continuation/verify.py` recompiles all
current production sources with their recorded flags and verifies complete
function extents/bindings, all allocated sections, and all **123 actual
relocations** against the supported DOL. SDA21 and address-half text
references and absolute startup function pointers are resolved to their
versioned targets. No relocation bits are masked, and extra functions or
allocated sections are rejected. Result: 69 units, 92 functions, 4,228 text
bytes, and 12 `.ctors` bytes exact. The native full-link hash and objdiff regression checks also pass.

The remaining 21 initially inventoried candidates are not in the final
manifest. Failed and exploratory forms remain scratch-only. This batch
does not claim native ABI thunks, cache operations, pseudocode, or differing
probes as matching source. Shared headers, symbols, splits, configuration,
original input, and generated progress were not edited by this recovery
work.

Accepted continuation checkpoint: the native build reproduces the original
DOL SHA-1 `5da8295a79bf297ab62c620e6ac66210be1c6ef5`; `ninja changes` reports
no regressions, the source-extent audit passes, and generated progress checks
pass. The original denominators remain unchanged.
