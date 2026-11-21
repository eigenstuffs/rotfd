# Early owner distance — fn_8005EB88

Frozen isolated ordinary C++ reconstruction, 2026-10-11; central integration pending.

The function resolves the generation-tagged owner handle at argument-one offset 0x58, then queries fn_80058350 through the distance service at context->subsystem[0x15058], passing the caller's second resource unchanged. It scales the result by the existing SDA constant lbl_803786A4. The distance service is captured before resolution; this ordinary source ordering reproduces the native register scheduling exactly.

Source `src/Game/early_owner_distance_8005eb88.cpp`; header `include/Game/early_owner_distance_views.h` has one consumer. Compile with standard GC1.3.2 plus `-O4,s` and `-Cpp_exceptions on`.

| Section | Original extent | Bytes |
| --- | --- | ---: |
| .text | 8005EB88..8005EC08 | 128 |
| extab | 8000AFCC..8000AFD4 | 8 |
| extabindex | 80018330..8001833C | 12 |

`python3 scratch/game_early_owner_queries/early_owner_distance_8005eb88/verify.py` verifies all 148 allocated bytes with actual relocations, actual ELF local EH names, one function extent, and complete original extabindex/ctors/dtors ownership tables. Four text and two EH/index relocations are retained; one nonallocated compiler metadata reference is accounted. No owned data, BSS, helper functions or padding.

The adjacent two-owner distance fn_8005EAC8 remains private: ordinary direct/member/capture order variants produce 184..192 bytes with persistent scheduling/register differences. The 296-byte current-owner getter fn_8005E9A0 now has a genuine Handle_8002B67C copy lifetime derived from Handle_801F7F10, with matching initialization/retain and successful resolution shape. Its best `getter_void.cpp`/`getter_castvoid.cpp` retain eight control-flow/result-move differences, plus an unused weak derived destructor; no credit is claimed. Both bounded investigations and all probe artifacts remain in `scratch/game_early_owner_queries`.
