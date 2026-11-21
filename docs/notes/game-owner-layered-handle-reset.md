# Owner layered handle reset

`src/Game/owner_layered_handle_reset.cpp` reconstructs `fn_80228E0C`, `.text` range `80228E0C..80228ECC` (192 retained bytes), as ordinary C++.

Calls the base reset helper, default-constructs a four-layer native handle value, assigns it to the owner handle at 0x184, then assigns that handle to the one at 0x180. A separately bound input pointer in the second assignment preserves the native alias and register lifetime. Native handle construction/destruction and reference release/retain calls are genuine C++ lifetime behavior.

Run `python3 scratch/game_owner_layered_handle_reset/verify.py`. Standard GC/1.3.2 flags verify all 192 retained bytes and nine real relocations directly against the protected DOL, exact symbol extent and all emitted allocations/relocation identities. The original extabindex, `.ctors` and `.dtors` audit finds no ownership or references into this range. Source/evidence hashes and actual relocation tables are preserved.

Only `.text` is emitted: 192 retained bytes followed by four unreferenced weak inline destructor backups totaling 360 bytes (96/92/88/84). All are audited in the emission reference, including their actual relocations; retained code references none. They must be absent from the final ELF and earn no progress. No data, BSS or padding is emitted. This partial text split leaves neighboring functions and data original. Central integration must pass the original DOL hash, native objdiff, regression checks and weak helper absence check. No symbols, headers or special flags are required. Source and evidence are frozen after handoff.
