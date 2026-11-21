# Owner-list mode change and reordering — integrated

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

`fn_80212FC4`, at `0x80212FC4..0x80213824`, is preserved as an **uncredited near-match** in `scratch/game_owner_list_reorder/initial.cpp`. Its ordinary C++ reconstruction emits the original 2,144-byte function size, but 11 bytes in ten instructions still differ. It is not registered as a matching source unit, and no source progress is claimed.

The accepted `src/Game/objects_owner_mode.cpp` reaches this function after changing the object's word at offset `0x14`. The private reconstruction calls that word `mode`; this is a working interpretation of the observed comparisons, not a recovered original field name. The list contains head and tail handles at offsets `0` and `4`. The object contains previous and next handles at `0xC` and `0x10`. Handle lookup compares the signed generation byte with the signed generation in a 16-byte manager entry, using the signed 24-bit index.

The original control flow is preserved:

- Read the incoming object's mode. For mode 9, return if its resolved object equals the resolved tail. Otherwise unlink and append it, **then fall through to the general unlink/reinsert path**. The source deliberately retains that second unlink.
- Unlink the incoming object. Append if the head resolver returns null, or if the tail object's signed mode is less than or equal to the incoming mode.
- Otherwise make an owned cursor copy from the head and advance while the cursor's mode is strictly less than the incoming mode. Each cursor assignment releases the old cursor and retains the next handle.
- Insert before the cursor. When it resolves to the head, update the head; otherwise update the incoming previous link and its predecessor's next link. Finally update incoming next and cursor previous, then destroy the cursor.

The comparisons use resolved object identity. Null resolution can include a stale generation; it does not prove that the packed handle is zero. No bounds checks, validity guards, or corrective edge behavior were added.

## Verification and remaining difference

Run:

```sh
python3 scratch/game_owner_list_reorder/verify.py
```

The verifier intentionally exits nonzero while the retained bytes differ. It recompiles with GC/1.3.2 and the existing game flags, pins the source and object hashes, applies all actual ELF relocations at the original addresses, and compares with the protected original DOL. It accounts for every allocated section and emitted function and rejects retained references into an excluded weak body.

Recorded in `scratch/game_owner_list_reorder/strict_result.json`:

| Item | Result |
| --- | --- |
| Retained function | 2,144 bytes |
| Actual retained relocations | 47 |
| Differences after relocation | 11 bytes across 10 instructions |
| Excluded weak destructor | 84 bytes, 2 relocations |
| Emitted data, BSS, exception metadata, padding | 0 bytes |
| Credited source | 0 bytes |

All differences lie in the initial handle resolution and its cached reuse, at instruction addresses `0x80212FEC`, `0x80212FF0`, `0x80212FF4`, `0x80212FF8`, `0x80212FFC`, `0x80213000`, `0x80213004`, `0x80213010`, `0x80213034`, and `0x80213044`. The original caches the input index and generation in r6/r7; the reconstruction uses r4/r6, with corresponding temporary-register changes. Later instructions are exact after relocation. The matching suffix is not a separate original function and receives no partial credit.

Thirty-nine bounded source variants cover mode/index/generation accessors, declaration order, manager and entry views, byte-table lookup, comparison helpers/operators, intermediate object references, and native base lookup placement. None improves the initial ordinary source. Fixed compiler flags were used throughout; no assembly, register variables, barriers, forced stores, literal substitution, or address patching were introduced. The durable scripts and diagnostic outputs remain under `scratch/game_owner_list_reorder/`; the separate `inventory.json` is explicitly nonmatching and `do_not_integrate`.

The protected original SHA-1 remains `5da8295a79bf297ab62c620e6ac66210be1c6ef5`. No original file, accepted source/header, central configuration, baseline, or global build was changed for this recovery.
