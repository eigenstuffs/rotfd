# Cyclic record selection callbacks

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The independently frozen proposal in
`scratch/game_engine_callback_dispatch_handles_continuation/` recovers two
ordinary callback dispatchers. They are pending central integration and the
complete original-placement DOL hash check.

| Original entry | Text | extab | extabindex | Compiler jump table |
| --- | ---: | --- | --- | --- |
| `fn_80042C14` | 912 | `800089C8..80008A28` | `80017670..8001767C` | `802B2D88..802B2DA4` |
| `fn_80043018` | 916 | `80008A50..80008AB0` | `80017688..80017694` | `802B2DE0..802B2DFC` |

Each source retains 96 exception bytes, its 12-byte exception index and a
28-byte compiler jump table. Both original jump-table addresses satisfy the
compiler's eight-byte section alignment. Neither needs additional pool
ownership or force-active data.

Events zero through six register, unregister and inspect the same observed
three-word member-pointer callbacks used by the existing callback family.
The remaining dispatcher adjusts the action number using callback short
`2A`. Query action fourteen uses selector `68` or `69`. Action fifteen enables
that selector and changes global counter `lbl_80377640`: the first decrements
and wraps a negative value to 188; the second increments and wraps values
greater than or equal to 188 to zero.

The selected record index is object word `68`. For a nonnegative index,
`fn_801F5C04(context.records144, index, counter)` returns a nontrivial native
Handle through the hidden return pointer. A genuine inline typed copy
constructor and assignment retain the returned Handle before releasing the
temporary. The source declares the original native constructor/destructor,
models the observed two zeroing inheritance layers, and uses a full-expression
temporary. This reproduces the original stack objects at offsets `8`, `C`
and `10`, including their exception lifetimes. Successful resolution calls
`fn_8025795C(self, counter, 0)`.

The first probe differed only in two instructions at the callback-state
argument: event seven/eight calls an external setter before dispatch, so the
subsequent `fn_8025F658` argument must reload `lbl_80378090`. Correcting the
observed source argument makes all retained code and metadata exact. The
initial probe remains preserved beside the final source.

The private aggregate based at external `lbl_802B2BF0` is an address/offset
view, not a claim that its current 144-byte symbol owns the entire region.
The first body reads five complete member-pointer records from original
`lbl_802B2D4C` (`2D4C..2D88`, base offset `15C`); the second reads original
`lbl_802B2DA4` (`2DA4..2DE0`, base offset `1B4`). These original record arrays,
their identities and all broader callback tables remain outside these
partial source units. Six original external table references to each primary
entry remain unchanged. The full extabindex, constructor and destructor
tables were scanned at their established complete bounds; each body owns
exactly its listed index, with no startup or shutdown pointer.

Each object additionally emits two weak destructor backups: native
`Handle_80042FA4` (116 bytes) and `Handle_8001FF78` (112 bytes), with 80 exception
bytes and 24 index bytes. These 332 bytes per object receive no matching
credit. Retained EH has three pointers to these real weak symbols, resolved
to the already accepted strong original owners. Both strong owners were
independently recompiled with their unchanged recursive header, compared with
their production objects, and strictly verified against all original bytes
and actual relocations. Complete canonical/source/header/object provenance
is frozen in `strong_owners.json` and each manifest.

The old strict weak-EH core is preserved byte-for-byte. The separate
`weak_override_jump_table.py` proposal retains all its original checks and
adds only a bounded `.data` schema: one complete 28-byte local object, section
alignment eight, original address aligned eight, seven explicit ADDR32
relocations at offsets zero through 24 to the exact primary GLOBAL/FUNCTION
symbol at input offset zero, and aligned addends within that function. Raw
table storage must be zero before relocation, with no data backups or
additional allocations. `strict_adapter.diff` records the complete change.
`verify_jump_table_optin.py` preserves independent strong-owner recompilation,
all frozen allocation and relocation comparisons, and source/header hashing.
It requires the separately frozen adapter and unchanged core digests.

Both final objects pass strict verification of every emitted allocation and
every retained byte: 1,828 original text bytes, 272 retained EH/index/table
bytes, 112 retained actual relocations and 28 backup relocations. Sixty-two
independent table guard tests pass, including malformed binding, type,
extent, alignment, raw storage, duplicate symbols, implicit addends,
out-of-range/unaligned addends, alias targets and backup-function targets.
The unchanged native map/ELF checker passes private actual links for both
objects, proving six backup allocations discarded per object, both original
strong destructors selected and all retained table/EH pointers resolved
correctly. Wrong input basenames reject for both cases. The first private
link attempt lacked the original small-data definition object; its failure
and corrected link with actual original `.sbss` definitions are preserved.

Reproduce strict object verification with
`python3 scratch/game_engine_callback_dispatch_handles_continuation/verify.py`.
Rerun guard tests without changing frozen reports using
`python3 -m unittest discover -s scratch/game_engine_callback_dispatch_handles_continuation -p test_jump_table.py -v`.
The integrator must separately adopt the bounded gate, compile production
objects, repeat full-game native discard/strong-owner/table audits, and pass
the original DOL hash before reporting source credit.
