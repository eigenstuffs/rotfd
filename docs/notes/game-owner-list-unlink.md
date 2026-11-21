# Activable list unlink — integrated

The complete pair at `80212AA0..80213824` is now accepted in
`src/Game/owner_list_unlink_reorder_80212AA0.cpp`: 1,316 unlink bytes plus 2,144
reorder bytes, 89 actual retained relocations and no owned data. Both complete
external callers remain unchanged. The 84-byte weak destructor remains UNUSED.
The original DOL hash, standard/mapped native proofs and full regression suite
pass; see the [continuation checkpoint](continuation-2026-10-12-native-source-checkpoint.md).
Ordinary typed const-index access and signed generation comparison resolve the
earlier register differences. The historical probes and their failed checks
below remain intact and earn no separate credit.

## Preserved historical investigation

The preserved source `scratch/game_activable_unlink/probe.cpp` reconstructs
`fn_80212AA0` at `0x80212AA0..0x80212FC4` (1,316 bytes). It remains an
**uncredited near-match**: ten instruction bytes differ across seven
instructions after all 42 retained relocations are applied. No source object
or new candidate is registered in the matching build.

The function borrows an incoming list handle and resolves its object. It first
returns when both previous and next handles resolve null. This guard is
preserved even if the list's head and tail could still name that object; no
extra membership test or singleton-list correction is introduced.

The remaining branches compare resolved objects, not packed handle words.
For the head, the list advances to the removed object's next handle and clears
the new head's previous link, or clears the tail when the new head resolves
null. For the tail, it clears the previous object's next link and moves the
tail backward, or clears both list endpoints when no previous object resolves.
For an internal object it reconnects the neighboring handles. The function
then assigns empty handles to both links of the removed object. All handle
assignments retain the original release/copy/retain calls and all empty
construction/destruction lifetimes.

No bounds, null, or ownership guards are added around borrowed object
resolution. Entry generation is read as a signed byte from the 16-byte manager
record and compared with the signed generation stored in the handle. The
initial object and the incoming handle retain their original lifetimes; no
new owned argument temporary is constructed.

## Remaining difference

The native-size source emits the same 329-instruction extent as the original.
All unmatched instructions fall in the repeated incoming-handle lookup before
the head comparison, at `0x80212B34..0x80212B4C`. They allocate different
scratch registers while preparing the index, raw generation, and entry-table
address. The common index and promoted generation are otherwise kept in the
original registers for the later tail comparison. Control flow, loads/stores
outside these register encodings, and all actual relocation operands match.

The strict result lists ten differing bytes at:

```text
80212B35 80212B38 80212B39 80212B3D 80212B41
80212B45 80212B48 80212B49 80212B4D 80212B4E
```

The original diagnostic output had 49 different instruction words: 42 were
unapplied relocation words, and seven were these register differences. The
actual retained ELF relocation count is **42**, not 49.

The original explicit `if`/`return` getter remains the best source. Bounded
follow-up probes tested index/generation and globals accessors, generation
local lifetimes, entry accessors, direct byte-table staging, a private input
subtype, void/object pointer return boundaries, named comparison locals,
const-reference endpoint accessors, and shared-manager equality scopes.
None improves the seven remaining instructions. All probes use the original
GC/1.3.2 flags; no compiler flag sweep, assembly, volatile barrier, artificial
dependency, or instruction patch is introduced. The earlier root probes and
the best source remain intact.

## Strict evidence

Run:

```sh
python3 scratch/game_activable_unlink/verify.py
```

The command intentionally exits nonzero until all retained bytes match. It
checks source/object hashes, the original DOL SHA-1
`5da8295a79bf297ab62c620e6ac66210be1c6ef5`, all function boundaries and bindings,
physical retained order, all allocated sections, alignment, and all 42 real
relocations. One unreferenced weak handle destructor (84 bytes, two
relocations) is fully enumerated and excluded. Only `.text` is emitted; there
is no owned data, BSS, metadata, or padding, and no retained reference to the
excluded body.

`scratch/game_activable_unlink/inventory.json` is explicitly `nonmatching` and
`do_not_integrate`, with zero source credit. `strict_result.json` and
`verification.txt` preserve the actual relocated-byte failure, and
`probe_summary.json` records the bounded comparisons. No accepted source,
shared header, central file, global build, original, or baseline was changed.
