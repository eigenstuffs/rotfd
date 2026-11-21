# Callback control state

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Six ordinary C++ production sources match isolated compiler objects:
`fn_800443B4` (116), `fn_80045CB4` (116), `fn_80044578` (160),
`fn_80044618` (160), `fn_800446B8` (240), and `fn_800447A8` (348).
All 1,140 code bytes, 48 exception-header bytes, 72 exception-index bytes,
and 32 actual relocations match. Each object emits exactly its retained
text, eight-byte exception header, and twelve-byte index; there are no
additional allocations, weak functions, tables, or data definitions.
Full native target acceptance remains the integrator's check.

The two 116-byte setups set flag `0x40000000` in the observed 64-bit field
at offset `38`, then query the existing float accessor and convert its
results to byte-valued fields at `60` and `64`. The first uses accessor
indices zero and one; the second uses one and two. `80044578` clears/sets
flags `0x20000` and `0x40000` according to a signed byte argument and calls
virtual slot `30` or `34`. `80044618` queries existing controls `8A` then
`8B` and, when either succeeds, calls virtual slots `84` and `7C`.

The 240-byte function accepts modes zero through two, resolves the original
signed 24-bit index/eight-bit generation Handle at offset `28`, and checks
bit `0x10000000` in the resolved node's 64-bit field at `38`. If the bit is
clear and the original observer global is present, it sends the supplied
event through `fn_802073E8` using observer virtual slot `14` and the existing
constant at `80378560`. The 348-byte function applies the same gate,
obtains the observer target once, and sends event `8A` or `8B` when that
query succeeds and the current mode is zero or one. Its short-circuit
second query also runs when the first query succeeds but the mode fails;
this ordering is established directly by the original branches.

Private declarations establish only observed offsets, virtual slots, and
Handle representation. Existing C entry names, global identities, constant
data, and table references remain unchanged. `extern const float` reflects
the observed original read-only constant. No shared header or complete
object layout is proposed.

`80044494` is preserved as an uncredited near-match in the scratch directory.
Ordinary nested/combined conditions, an empty branch, ternary and inline
helper forms emit 140 code bytes versus the original 144: the compiler
combines the native conditional-to-body plus unconditional epilogue branch.
No instruction forcing or relocation masking is used, and it is absent
from the production manifest.

The ownership audit scans the full original exception-index table
`80015F60..8001F2C0`, startup pointers `80299920..80299980`, and shutdown
pointers `80299980..802999A0`. Each recovered function owns exactly one
corresponding exception record and no startup/shutdown pointer. Original
initialized-data references and current compiled source consumers are
inventoried. All neighboring original functions and data remain outside
these partial units. No symbol rename, alias, identifier migration, pool
partition, or data-retention rule is requested.

`scratch/game_engine_callback_control_state_continuation/handoff.json`
freezes the production sources, raw compiler objects, full section/symbol
inventory, ownership audit, actual relocations, split/config proposals,
strict verifier, and source/header hashes. `verify.py` recompiles all six
production sources and verifies every emitted allocation and relocation.
Central metadata and all earlier frozen handoffs remain unchanged.
