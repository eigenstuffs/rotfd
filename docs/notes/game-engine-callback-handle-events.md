# Handle collection setup and event callbacks

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The fresh proposal in `scratch/game_engine_callback_handle_events_continuation/`
recovers three ordinary callback dispatchers, pending central production and
full original-placement DOL acceptance. It reuses the separately frozen
seven-entry jump-table verifier without modifying that proposal or any old
strict verifier core.

| Entry | Text | extab | extabindex | Compiler table |
| --- | ---: | --- | --- | --- |
| `fn_800CA254` | 1,008 | `80013410..80013428` | `8001D1B4..8001D1C0` | `802C15F0..802C160C` |
| `fn_80045030` | 1,044 | `80008CF0..80008D40` | `8001785C..80017868` | `802B3818..802B3834` |
| `fn_80045444` | 1,044 | `80008D40..80008D90` | `80017868..80017874` | `802B3870..802B388C` |

All three table addresses satisfy the compiler's eight-byte alignment. Each
source owns only its original text, exception record/index and 28-byte
compiler table. The original member-pointer records and external callback
tables remain original. `ownership_audit.json` records all initialized-data
references to each function, its unchanged compiled-source consumers and the
complete extabindex/constructor/destructor table scans. There are no native
identifier migrations or new retained globals.

The common event prefix registers, unregisters and queries five observed
three-word member-pointer callbacks. Their address/offset views are based at
external `lbl_802C1590` or `lbl_802B3708`; they do not enlarge the current
symbol's ownership. The complete five-record ranges read are
`802C15B4..802C15F0`, `802B37DC..802B3818` and `802B3834..802B3870`.

Action fifteen of `fn_800CA254` converts two queried floats through signed
integer conversion and stores their low bytes at object `60` and `61`.
A genuine two-layer default Handle remains at stack offset `8`. For unsigned
byte indices zero through nine, the function obtains a borrowed Handle from
`fn_8025E1D4`, releases the previous temporary reference, copies and retains
the new reference, then increments object byte `62` for successful resolution.
The source preserves the original accumulated count; this body does not
initialize it. Mode one calls virtual slots `7C(0,0)` and `80(1,0)`; mode two
copies byte `62` to `63` and calls `80(0,0)` then `7C(1,0)`; other modes call
both slots with zero arguments. The callback flags clear bit two.

The first probe matched everything except the mask instruction: an unbounded
`~4` emitted rotate/mask, while the observed unsigned-short mask `0xFFFB`
emits the original `andi.`. That original one-instruction near and its exact
correction are both preserved.

The adjacent pair uses selector `8A` or `8B`. Its action fifteen constructs a
retained typed copy of the owner's Handle at `28`, then copy-constructs a
second scoped typed Handle before destroying the first. A direct C++
full-expression reproduces stack offsets `8` and `C`. Both copy constructors
must explicitly copy and retain; the implicit language copy omits the original
reference operation and shortens the function. The preserved initial probe
documents that difference. The explicit ordinary copy constructor produces
the exact original 1,044-byte body and its 80-byte exception record, including
both separate base-destruction actions and the original Elf-vector flag.

Each pair member resolves the scoped Handle and sends an event through
`fn_802073E8` with the borrowed original float `lbl_80378560`. It resolves
again, tests the observed 64-bit flags at target `38` against `0x02000000`,
and conditionally sends another event using observer virtual slot `14`.
The first then calls owner virtual slot `94(0,0)`; the second uses `90(0,0)`.
Both clear callback flag bit two before the scoped Handle is destroyed.

The setup object emits 192 uncredited weak text bytes and 72 uncredited
exception/index bytes: native `Handle_80020B90` (116) and source-private
`ZeroHandle_CA254` (76). The adjacent objects each emit native
`Handle_80020478` (112) and `Handle_80020834` (116), with 104 uncredited
exception/index bytes. Every emitted allocation and raw digest is recorded.
Retained EH resolves only to independently recompiled, accepted strong native
owners. Canonical/source/recursive-header/production-object hashes and actual
relocations are frozen in `strong_owners.json`; no private destructor receives
source credit.

All retained sections pass the unchanged separately frozen jump-table gate:
3,096 original text bytes, 304 retained EH/index/table bytes, 133 retained
actual relocations and 39 backup relocations. The existing native map/ELF
checker passes all three isolated real links, proving six backup allocations
discarded per object, exact strong-owner selection and exact resolved table
and exception pointers. Wrong fixture basenames reject in all three cases.
An initial private link lacked the actual small-data float owner; its failure
and corrected link using original `.sdata2` definitions remain preserved.

The new source-specific adoption manifest pins these three sources and
objects to the already frozen adapter/gate. No amendments to the prior
Handle pair are needed. Run
`python3 scratch/game_engine_callback_handle_events_continuation/verify.py`
for fresh compiler and complete strict checks. The parent integrator remains
responsible for production objects, full-game native discard audits and the
original DOL hash before acceptance.
