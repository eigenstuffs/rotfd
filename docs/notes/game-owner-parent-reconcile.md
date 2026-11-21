# Owner parent handle reconciliation

Ordinary C++ `fn_802203A8` matches all 372 bytes at `802203A8..8022051C`, including seven actual relocations. Source: `src/Game/owner_parent_reconcile.cpp`. Isolated verifier: `python3 scratch/game_owner_parent_reconcile/verify.py`; standard GC/1.3.2 Game flags, no new header/symbol/flag requirements.

The routine obtains an indexed handle through owner virtual slot 9C, resolves its object, and resolves the stored parent handle from owner array at 64[index]. If this differs from the object's current handle at C, it detaches the object with fn_80240120(object,0), retains a temporary copy of the indexed handle, calls fn_802408BC(parent,&copy,1), and releases that temporary. The concrete one-zero base handle layer reproduces native temporary lifetime and alias allocation.

The entry generation accessor is material to ordinary compiler behavior: keeping the manager/index and inlining `getGeneration()` preserves the original entries reload and base-plus-displacement loads across all three resolutions. A direct entry pointer emits 368 bytes; a direct generation field with separate index emits 372 but differs in 13 register/address instructions. The accessor closes the full original extent.

All 544 allocated text bytes are accounted: 372 retained plus two unreferenced weak destructor backups totaling 172. The verifier checks their raw bytes and complete relocation identities, verifies no retained references to these helpers, and requires their final ELF absence. No data/BSS/padding is emitted. Original extabindex/ctors/dtors ownership audits pass. The frozen manifest/evidence are in `scratch/game_owner_parent_reconcile/`. Final acceptance requires central full DOL hash/native objdiff, extent/regression and weak helper absence checks.
