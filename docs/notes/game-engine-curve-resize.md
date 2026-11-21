# Engine curve-record array continuation

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Frozen isolated handoff: three ordinary C++ units, three original functions,
2,660 retained text bytes, zero owned data bytes and 97 retained real
relocations. Constructor cleanup also emits eleven unused weak destructors,
1,864 text bytes with 38 relocations. Those bytes receive no source credit;
all eleven weak symbols must be absent from the final linked ELF.

Sources are `src/Game/engine_curve_resize_*.cpp`. Exact integration is in
`scratch/game_engine_curve_resize_continuation/final_integration.json`, alongside
`final_splits.txt`, `final_config.txt` and `ownership_audit.json`. The manifest
freezes production source SHA-256, recursive quoted-header hashes (none), every
emitted function allocation, raw weak function SHA-256, weak binding and extent,
and both retained and unused real relocations. Existing external function names
are preserved, including destructor `fn_801B2AC8` and dependency `fn_801B27AC`.

| Function | Retained bytes | Real relocations | Unused weak bytes | Behavior |
| --- | ---: | ---: | ---: | --- |
| fn_801B2AC8 | 1,376 | 37 | 0 | Reverse destruction of eight curve members, followed by optional owner free |
| fn_801B3288 | 692 | 31 | 992 | Resize array of 140-byte records with eight curve members |
| fn_801B353C | 592 | 29 | 872 | Resize array of 80-byte records with three curves and a world-action curve |

The record prefix is twelve bytes: word +0, signed halfword +4, opaque halfword
+6 and table pointer +8. Construction installs
`__vt__24CurveRecordBase_802E9E08`, initializes word +0 to zero and halfword +4
to -1, then installs the derived record table before member construction. Two
inline base layers reproduce this observed order. The eight-member record uses
`lbl_802E9E14`; the three-member/action record uses `lbl_802E9DD8`.

Each ordinary curve contains the native four-byte `CurveBase_801B1088` and a
12-byte count/capacity/pointer pool. The eight-member record has five pools of
16-byte entries, two of 20-byte entries, and a final pool of 16-byte entries.
Its destructor restores the record table, destroys the members in reverse order,
and frees the record only for a positive signed-short release flag. The pool
cleanup walks live elements, releases capacity times the verified element
stride and reproduces the original repeated pointer clears.

The 80-byte record contains three pools of 20-byte elements, followed by the
native `WorldActionCurve_801F7560`. The world-action curve contains a four-byte
native curve base, a 12-byte action-row array and its virtual table at +10.
Rows have an opaque word and a 12-byte array of 12-byte action entries. Its
constructor assigns the three row-array words after installing its virtual
table. Its existing native destructor, vtable and curve-base methods remain
external dependencies.

Both outer arrays use count/capacity/pointer at +0/+4/+8. Growing optionally
reserves exactly the requested capacity and placement-constructs new records.
Shrinking destroys records in reverse order using the existing external record
destructor. A signed-byte keep flag selects whether capacity is retained or
resized. The three-member specialization declares its shrink index separately
from its grow index; this reproduces the original register allocation.

## Verification and ownership

All production sources were recompiled after formatting and private type naming.
GC/1.3.2 uses the ordinary `-O4,p` flags with C++ exceptions off. Both resize
functions additionally use `-use_lmw_stmw on`; the eight-member destructor does
not. The copied strict verifier applies actual relocation targets and compares
every retained byte and exact symbol extent. Every emitted allocated section is
accounted. No retained relocation references an unused weak destructor. There is
no relocation masking or credit outside the original function extents.

The full original exception index and constructor table were audited. These
functions have no exception records or startup constructor references. Their
original units own only text; neighboring original functions remain outside the
partial text splits. All original allocator globals, tables, native curve-base
and world-action methods retain their current ownership.

`python3 scratch/game_engine_curve_resize_continuation/verify.py` passes all
three units. Root integration must publish the proposed exact ranges, confirm
all eleven `unlinked_functions` symbols are absent from the linked ELF, and pass
the full original DOL hash and native match regression checks before promotion.
No shared metadata edits or full build were performed by this agent.
