# Hierarchy camera and list setup

The candidate for `fn_80202A18` spans `0x80202A18..0x802030C4` (1,708 bytes). It is **not registered or credited as matching source**. A strict relocation-aware comparison finds 11 differing bytes in six instructions; the other retained bytes match. The function's original translation-unit boundary remains unknown.

The source is `src/Game/hierarchy_camera_setup.cpp`, with a private layout header. It reuses the proven native handle and resize model without changing the accepted shared header. The function initializes three lists when its count is zero, chooses or finds a camera agent for each element, creates named node/camera objects, assigns references, and attaches each node to the resolved owner parent. The mode byte selects one shared width or the full count.

## Verification and remaining difference

Run `python3 scratch/game_hierarchy_setup/verify.py`. It deliberately exits with failure until the remaining instruction bytes match. The script applies all 71 retained ELF relocations at the original addresses and compares against the protected DOL SHA-1 `5da8295a79bf297ab62c620e6ac66210be1c6ef5`; no branch/immediate masks or object patches are used. `verification.json` records exact byte addresses, original/candidate byte values, source/header/object hashes, and the result.

The remaining instructions are at `0x80202B0C`, `0x80202B18`, `0x80202B20`, `0x80202B28`, `0x80202B2C`, and `0x80202B30`. The original uses r21 for the scaled array index and r24 for placement-new's construction address. The candidate exchanges those two registers. All stack offsets, constructor/destructor calls, list branches, nested handle resolutions, and loop calls are otherwise exact after relocation.

GC/1.3.2 with `-O4,p -inline auto -Cpp_exceptions off -use_lmw_stmw on` produces the best candidate. A bounded GC/1.3 check gives the same remaining difference; `-O4,s` changes additional instructions. Pointer/reference element accessors, manager and entry accessors, free/member resize helpers, and ordinary loop/placement-new expression variants did not solve the exchange. The diagnostic variants remain under `scratch/game_hierarchy_setup`; they do not establish source matching.

## Recovered compiler-sensitive structure

- A const reference to the external string-pool view, established before the early return, retains the original base address and uses offsets `0x24`, `0x30`, and `0x40`. Direct field expressions hoist three separate pointers and change register allocation.
- The raw list element has two zero-initializing handle layers. Copy temporaries add a reference to the supplied native handle. An extra class layer on the actual list element adds an unwanted destructor null branch.
- `fn_80260868` returns a derived native handle and receives destructor flag 0. `fn_801B550C` returns the native handle itself and its returned temporary receives flag -1. Both preserve the observed hidden return pointer ABI.
- A distinct typed manager view for the owner lookup prevents incorrect reuse of the entry-vector load across the nested resolution. Explicit `if`/return structure in the ordinary resolver gives the closest register allocation; a ternary changes allocation across the routine.

## Allocated sections and weak helpers

The compiler emits one allocated section: `.text`, 2,144 bytes. The candidate retained function owns the first 1,708 bytes. The remaining 436 bytes are five explicitly enumerated weak destructor bodies, with ten relocations owned only by those bodies. No retained relocation targets them. The verifier checks their names, weak binding, exact offsets/sizes, and complete contiguous section coverage. They would be removed by ordinary linker dead stripping; they are not source progress.

No data, BSS, alignment tail, exception table, or other allocated section is claimed. All constants remain external original storage. The observed string prefix at `0x802AD8F8..0x802AD948` is an 80-byte view only; it is not presented as a recovered complete string pool or TU. The exact bytes and small-data constants are recorded in `scratch/game_hierarchy_setup/external_constants.json`.
