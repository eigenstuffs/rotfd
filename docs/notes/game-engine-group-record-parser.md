# Group-record parser at 8021A340

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The isolated production source reconstructs `fn_8021A340` at
`8021A340..8021A7AC` (1,132 bytes). It reads a braced menu-item record, resolves
three name fields and a resource Handle, accumulates the original byte-wide
flags, and appends the completed record through `fn_8021AFE0`.

The match uses ordinary layered Record and Handle construction. A true returned
four-byte Handle and its derived zero-initializing view preserve temporary
construction, assignment, reference-count changes, and discriminator-zero
cleanup. The header is a partial layout view; the unique FQ wrapper classes do
not claim recovered original class names. `fn_80263308` retains its original C
identity and returned-object ABI. Other accepted declarations and consumers
remain untouched. The observed byte-wide `FOREVERACCESS` accumulation is
preserved, including its truncation.

## Source and compiler

- `src/Game/engine_group_record_parser.cpp`
- `include/Game/engine_group_record_parser.h`
- GC/1.3.2, normal Game `-O4,p -Cpp_exceptions off`, plus
  `-use_lmw_stmw on`.
- `#pragma readonly_strings on` naturally emits the five original literals in
  `.rodata`; no object rewriting, aliases, fixed registers, or extracted data
  arrays are involved.

## Complete allocation ownership

| Allocation | Original/source extent | Bytes |
| --- | --- | ---: |
| Retained parser | `8021A340..8021A7AC` | 1,132 |
| Five compiler-local readonly strings and four internal gaps | `802AE888..802AE8CA` | 66 |
| Three unused compiler-emitted weak destructors | Trailing private object text | 304 |
| External original zero alignment | `802AE8CA..802AE8CC` | 2, uncredited |

The five strings have offsets/sizes `0/10`, `12/13`, `28/10`, `40/10`, and
`52/14`. Their nine internal alignment bytes are verified individually and as
part of the complete 66-byte compiler allocation. The original global object
`lbl_802AE888` covers 68 bytes; its last two bytes must remain original assembly
with explicit unit and symbol alignment two. The following original ten-byte
`lbl_802AE8CC` is outside source ownership.

The required external unit proposal is `padding/group_record_literals.s`,
`Object(NonMatching)`, with `.rodata 802AE8CA..802AE8CC align:2`, symbol
`lbl_802AE8CA` (`size:0x2 scope:global align:2 data:2byte`). This is needed in
addition to the symbol's alignment, because DTK otherwise aligns the new auto
split to four. Root performs the metadata edits.

All retained code and data match after applying every actual ELF relocation:
74 retained relocations, seven discarded-backup relocations, and no retained
references to the three weak destructors. There are no other allocated
sections, BSS, exception tables, constructors, or destructors. The complete
original extabindex/ctor/dtor allocations, including descriptors and trailing
zeros, were audited.

## Pool reference and native proof

The frozen read-only audit scanned 5,521 active inputs from the current native
link edge and 130,183 actual relocations. Only the original parser's HA/LO pair
references the pool. No other current source/header reference, original stored
pointer (including unaligned pointers), unresolved local readonly target, or
explicit source owner was found. A stale generated readonly assembly file is
inventoried separately and excluded from active ownership.

A real private MWLD link retains the parser and all five local literals and
discards all three unused weak destructors. It uses the unchanged adopted
`weak_override_link.py::check_link`; its arbitrary private placement is not
claimed as original placement. The exact-source gate rejects that claim.

The dedicated gate in
`scratch/engine_group_record_parser_20261011fq/rodata_owner_gate.py` wraps the
unchanged strict verifier, pins the full source/header/compiler object/symbol
and relocation inventories, and accounts for every literal and gap byte.
Fifty-one adversarial source, field, actual-object, relocation, ownership, and
native-map guards pass. No existing gate/core/adoption file was edited.

Before source promotion, root must repeat the exclusive-pool audit, adopt only
this exact source-bound route, and run `check_native_pool` against both complete
native linked ELFs. That check requires the parser's original bytes/address,
all five original local literal placements, retired global absence, the
external two-byte tail and neighboring original object, and all three backup
discard proofs. The original DOL hash and ordinary acceptance checks remain
required. This frozen handoff is isolated matching evidence; it is not yet a
production acceptance claim.

All proposals, probes, full inventories, native proof, guards, and hashes are
preserved in `scratch/engine_group_record_parser_20261011fq/`. Other functions
from the original translation unit and the external small-data strings remain
outside this partial split.
