# Hierarchy commands at 80204000 and 80204184

Status: both C++ fragments are integrated and verified by the complete DOL comparison and native objdiff. Recovered from the original GSQE78 instructions and the already verified hierarchy name-hash, manager lookup, and scoped-handle ABI. No external source implementation was copied.

| Source | Original range | Retained code | Relocations |
| --- | --- | ---: | ---: |
| `src/Game/hierarchy_command_parameter.cpp` | `80204000..80204184` | 388 bytes | 20 |
| `src/Game/hierarchy_command_enabled.cpp` | `80204184..802042EC` | 360 bytes | 19 |

Both original identities remain strong global C symbols, `fn_80204000` and `fn_80204184`. The private layout header is `src/Game/hierarchy_commands_internal.h`. The later console-field naming refinement preserves its layout and the complete compiled objects.

The registered `PlayRTC` command requires console `argc >= 3`, including the command token. It resolves `argv[1]` as the named `WORLD` resource and locates its group. It converts `values[2]` at `+8BC` to an integer and forwards that value minus one. When `argc == 4`, it also converts and forwards `values[3]` at `+8C0`; otherwise it forwards minus one as the optional parameter. No numeric-validity check is added. The registered `SetRTC` command requires `argc == 3` and nonzero `numeric[2]` at `+8A6`, performs the same resource/group lookup, and forwards integer-converted `values[2]` without subtracting one. This numeric flag records parse validity, including boolean aliases, rather than whether the value is nonzero. The private view now uses `ConsoleArguments`, `argc`, `arg1`, `arg2IsNumeric`, `arg2Value` and `arg3Value`; see [console argument layout](console-argument-layout.md).

The signed-byte test compiles to the original `extsb.`. Both commands preserve the hidden return pointer for the native handle result, zero-initialized derived owned handles, the retain call, and native destructor flags: minus one for the original temporary and zero for derived/base cleanup. Return values are signed bytes. Failed lookups return zero after the appropriate cleanup; success returns one.

Each compilation emits two unused weak wrapper destructors: `__dt__17CommandZeroHandleFv` (84 bytes) and `__dt__18CommandOwnedHandleFv` (88 bytes). The verifier checks their weak binding, contiguous tail extents, all four native destructor/operator-delete relocations, and absence of retained references. Their 172 bytes per object are excluded from source credit and left to ordinary linker dead stripping.

No initialized data, BSS, metadata, or padding is emitted or owned by either fragment. The existing six-byte `WORLD` literal at `lbl_8037A918` remains external original storage. Both integrated units contribute 748 code bytes and zero data bytes.

Verification uses GC/1.3.2 with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -Cpp_exceptions off -use_lmw_stmw on`. Run `python3 scratch/game_hierarchy_commands/verify.py`. It checks the original DOL SHA-1, every retained allocated byte and real ELF relocation, retained function identities/sizes/strong bindings, and excluded weak tails. Both production-source probes pass with zero differences. The candidates are `game_hierarchy_command_parameter.json` and `game_hierarchy_command_enabled.json`; each records the private header hash. Central integration is verified below.

Central integration passes the original DOL hash and direct whole-file byte
comparison. Native objdiff records all 748 code bytes and 2 functions as
matching, with zero owned data. The source-section extent guard and generated
progress checks pass. Original baseline source remains exact after the
documented native-accessor and padding accounting corrections.
