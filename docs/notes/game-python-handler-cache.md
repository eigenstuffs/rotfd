# Python handler cache — fn_8005E674

Verified isolated ordinary C++ reconstruction, frozen on 2026-10-11. Central integration remains pending.

The function stores the script object at offset 0x40 and populates seventeen cached method pointers at 0x10C..0x14C only when each Python attribute exists. The native order visits slot seven before slot six. Missing attributes leave the previous slot contents unchanged. The existing void binding at 800D1024 remains unchanged; its integer argument occupies the same 32-bit ABI location as this pointer view.

Production source: `src/Game/python_handler_cache_8005e674.cpp`; sole header consumer: `include/Game/python_handler_cache_views.h`. Build with standard GC1.3.2 plus `-O4,s`, `-Cpp_exceptions on`, and `-rostr`. No weak helpers or BSS are emitted.

| Section | Original extent | Allocated bytes | Object alignment |
| --- | --- | ---: | ---: |
| .text | 8005E674..8005E90C | 664 | 4 |
| extab | 8000AF90..8000AF98 | 8 | 4 |
| extabindex | 8001830C..80018318 | 12 | 4 |
| .rodata | 8029B7E0..8029B837 | 87 | 8 |

The compiler owns seven string objects, with their actual ELF local names:

| Local | Original address | Size | Value |
| --- | --- | ---: | --- |
| @39 | 8029B7E0 | 9 | Activate |
| @40 | 8029B7EC | 9 | RTCStart |
| @41 | 8029B7F8 | 13 | DamagedAgent |
| @42 | 8029B808 | 11 | EnterState |
| @43 | 8029B814 | 10 | ExitState |
| @44 | 8029B820 | 12 | EnterVolume |
| @45 | 8029B82C | 11 | ExitVolume |

Sizes include terminating zeroes. Twelve internal zero alignment bytes belong to the emitted pool and are verified. The original aggregate `lbl_8029B7E0` spans 88 bytes, ending at 8029B838. Its final zero byte at **8029B837..8029B838 is not emitted or claimed by this source** and must retain an explicit original one-byte split and symbol with alignment one. Root will retire the aggregate global label; no data alias is needed. The remaining ten short method names stay external in SDA.

`original_pool_consumers.json` records a scan of every object in the active generated config: 5,428 units, including 1,851 assembly units and 119,086 actual ELF relocations, with no missing objects. Only the retiring function references the original aggregate (two HA/LO relocations). No outside active consumer and no aligned absolute pointer anywhere in the file-backed DOL sections targets the pool. The inventory preserves its active-config hash and original DOL SHA1.

`python3 scratch/game_python_handler_cache/verify.py` recompiles production source and verifies all 771 allocated bytes, every actual relocation, all local objects/extents, twelve internal padding bytes, and the unclaimed original final byte. It checks 56 text relocations, two EH/index relocations, and one nonallocated compiler metadata reference. Complete original extabindex/ctors/dtors tables are audited: only this function's retained EH entry is owned and no constructor/destructor entry targets the source. Expected normalized original DOL SHA1 remains `5da8295a79bf297ab62c620e6ac66210be1c6ef5`.

The former external-pool probes are preserved privately: they produced an extra register move or wrong zero-offset addressing. Genuine string literals under `-rostr` produce the exact original text and pool without special code generation.
