# Message text-file loader and bounded literal-pool proposal

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/scene_message_file_loader_800C1B58.cpp` is an isolated proposal for the
original C entry at `800C1B58..800C1D70`. It loads a retained resource Handle,
checks the `BOX_TEXT_STRINGS` signature, counts matching records, constructs the
record array, rewinds the reader, and fills the records. Only the observed owner
fields at `+0xC/+0x10` and the `0x104` record stride are declared. The established
Handle hierarchy is included unchanged from
`include/Game/early_resource_token_loop_views.h`.

The original entry name and existing caller declarations remain unchanged.
`scene_message_allocator.cpp` is a preserved private, unregistered source;
its current active caller remains `auto_fn_800C2474_text.o`. The caller ignores
the signed-char result. No accepted caller or shared header was changed.

The root's `scratch/game_scene_message_file_loader/initial.cpp/.o` are preserved
untouched. Their expected extents were correct but the primary body had 14
reader/count/index register-operand differences. Declaring `int count; int
index;` before Handle construction, then assigning each at its original use,
recovers the original register allocation without changing the operations.
The corrected private variant and separate production source both pass strict
actual-relocation comparison.

The frozen handoff is
`scratch/game_message_loader_rodata_adoption_continuation/final_integration.json`.
GC1.3.2 uses the complete recorded flags, including `-proc 750 -O4,s -inline
auto -Cpp_exceptions on -use_lmw_stmw on -rostr`. Retained allocations are:

| Section | Original range | Bytes |
| --- | --- | ---: |
| .text | 800C1B58..800C1D70 | 536 |
| extab | 800127C4..80012810 | 76 |
| extabindex | 8001CC14..8001CC20 | 12 |
| .rodata | 802A19C0..802A19F6 | 54 |

All 34 retained actual relocations resolve exactly. The full original exception
index table (`80015F60..8001F2C0`) contains the one corresponding index record;
complete original ctor/dtor tables contain no pointer into this function.
`callable_ownership_audit.json` preserves the original extent and callable/table
identity evidence.

The original global `lbl_802A19C0` spans 56 bytes. The compiler emits three real
local string objects: `@88` at offset0,size17; `@89` at20,size14; `@90` at36,size18.
The only internal alignment gaps are zero bytes `[17,20)` and `[34,36)`. The
input section alignment is8 and the original start is8-aligned. These five
alignment bytes are explicit coverage records in the private adapter; no source
objects, ELF symbols, aliases or synthetic words are introduced for them.

The last two original bytes at `802A19F6..802A19F8` remain outside source
ownership. Adoption must create the original external `lbl_802A19F6`, size2,
global, `.rodata`, `data:2byte`, **align2**, and preserve the next original
`lbl_802A19F8` object and all of its 0x800 bytes. The proposed compiler source
emits no alias for retired `lbl_802A19C0`. Root must repeat pool exclusivity
against the then-current original assembly, live link edge and active inputs
before retiring that old global and changing the split.

The independent pool audit examines all 5,514 active native inputs and 130,137
actual relocations. Only two target the 56-byte pool: the HA/LO pair in original
C1B58. It also finds no interior alias symbols, source/header address consumers,
existing explicit source owner, unresolved local rodata targets, or absolute
pointers into the pool anywhere in initialized original data, including
unaligned pointer positions. The original assembly pool and function snapshots
are frozen. Current live-input hashes are historical adoption evidence, not a
permanent pin on unrelated future compilation. `audit_pool.py NEW_REPORT.json`
repeats the audit without overwriting its frozen report or snapshots.

The compiler also emits weak backups for native `Handle_8001FF04` (116 bytes)
and `Handle_8001FF78` (112 bytes), plus two 40-byte extabs and two 12-byte indices.
These 228 text/104 metadata bytes earn no credit. All 14 backup relocations and
all raw extents/bindings are inventoried. The already accepted strong owners
are independently recompiled from their frozen canonical manifests, with exact
production raw object SHA256, all original section bytes, actual relocations,
source/header hashes and GLOBAL/FUNC/native extent checks.

The private actual MWLD proof uses the unchanged adopted native checker. It
proves both strong definitions selected, all six backup text/EH/index
allocations discarded, and every retained string and alignment byte exact.
The wrong input basename is rejected. This private discard link is not a
full-game original-placement proof; the source-bound gate deliberately rejects
it as such. Full-game adoption must run `check_native_pool` against the actual
native ELF/map, proving primary and all three local string addresses, original
pool/tail/neighbor bytes, retired old global absence, the original strong owners
and all backup discards, then pass the original DOL SHA and regression checks.

`weak_override_rodata.py` is a new private copy of the frozen weak/EH core, with
its complete minimal diff in `strict_adapter.diff`. It adds only the exact
fourth-section schema, two literal-pool pointer relocations, and five gap bytes
to coverage. Actual relocation resolution, retained byte equality, symbol and
exception pairing, compiler categories, and strong-override authorization run
unchanged. All four original core hashes are pinned and unchanged.
`rodata_owner_gate.py` binds the proposal to this exact source, full manifest,
headers, object, flags, literal pool and accepted strong identities. It exposes
`validate`, `verify`, `select_owner`, `validate_pool_evidence`, `native_proposal`
and `check_native_pool` for a separately reviewed root outer route.

Final independent guards pass 12 test groups: 9 positive and183 negative cases.
They cover literal lengths, zero terminators, each alignment byte, all object
bounds/bindings/types, section flags/alignment, aliases and section-anchor
bypasses, relocation kinds/addends/offsets, full allocated coverage, original
retained code/EH, backup raw bytes, exact source authorization, shared/interior
pool consumers, external tail ownership and strong-owner identities. Accepted
unit-note refreshes are explicitly historical and do not relax compiler pins.
Root has not yet adopted this proposal or awarded matching source credit.

Root acceptance uses `load_message_pool_verifier.py` around unchanged prior gates. The exclusive old global pool label was retired only after a fresh current audit; `padding/message_loader_literals.s` keeps the original two-byte tail at `802A19F6..802A19F8` with explicit alignment2 and zero source credit. Both mapped and ordinary full-target ELFs pass original pool/tail/neighbor placement and all6 duplicate allocation discard checks. Full original hash and all26 tests pass.
