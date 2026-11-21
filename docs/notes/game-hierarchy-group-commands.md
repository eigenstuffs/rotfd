# Named-object group commands

Three adjacent commands at `0x802055A8..0x80205964` are reconstructed as C++ in `src/Game/hierarchy_group_commands.cpp`. Isolated verification passes for all 956 retained text bytes and 57 real relocations. Complete DOL comparison and native objdiff also pass. The earlier hierarchy setup near-match remains separate and receives no credit from this candidate.

| Original function | Retained bytes | Registered command | Behavior |
| --- | ---: | --- | --- |
| `fn_802055A8` | 308 | `DeactivateGame` | Requires `argc == 2` (command plus world name), resolves `argv[1]` as the named WORLD object, finds its group, and calls `fn_801FEE10`. |
| `fn_802056DC` | 308 | `ActivateGame` | Same lookup and checks, then calls `fn_801FEF6C`. |
| `fn_80205810` | 340 | `SwitchGameToMUlti` | Requires `argc == 3`, performs the same lookup, and passes integer-converted `values[2]` at console offset `0x8BC` to `fn_801FEC4C`. |

The command spellings come from the original registration routine at `0x80206524` and original strings at `0x802AD9FC`, `0x802AD9E0`, and `0x802ADA44`. They are evidence for function purpose, not new data ownership. Each command returns 0 for a wrong argument count, invalid resolved handle, or negative group index, and returns 1 after the operation. Counts include the command token. `SwitchGameToMUlti` performs no numeric-validity check before converting its second argument; this original guard is preserved.

The existing `hierarchy_commands_internal.h` supplies the established [console argument layout](console-argument-layout.md), native returned-handle ABI, one zero-initializing base, reference-counted copy constructor, and distinct name/hash wrapper. The later console-field naming refinement preserves its layout and the complete compiled objects. The normal native destructor releases both successful and early-return temporaries; no manual destructor call or assembly substitute is used. GC/1.3.2 with `-O4,p -inline auto -Cpp_exceptions off -use_lmw_stmw on` reproduces the instructions.

## Complete emitted-section accounting

Run `python3 scratch/game_hierarchy_group_commands/verify.py`. The verifier applies all retained relocations against the protected original DOL SHA-1 `5da8295a79bf297ab62c620e6ac66210be1c6ef5` and compares every retained byte without masks or object modification.

The compiler emits only `.text`, totaling 1,128 allocated bytes. Two unused weak destructor bodies occur **between the first and second retained functions**: `CommandOwnedHandle::~CommandOwnedHandle` at object offset `0x134` (88 bytes), and `CommandZeroHandle::~CommandZeroHandle` at `0x18C` (84 bytes). Their four relocations belong only to the excluded bodies, and no retained relocation targets them. The verifier enumerates all function extents, checks contiguous coverage of the entire compiled section and weak binding, then maps retained functions to their original addresses under ordinary dead stripping. The 172 unused bytes are not credited.

The resulting retained mappings are `0x802055A8`/308, `0x802056DC`/308, and `0x80205810`/340. No data, BSS, exception table, alignment tail, or other allocated section is claimed. The six-byte `WORLD` literal at `0x8037A918` remains external original storage; the shared pool at `0x8037A928..0x8037A938` is untouched.

`config/GSQE78/candidates/game-hierarchy-group-commands.json` records the mappings, dependencies, compiler settings, weak bodies, and source/header/object hashes. `scratch/game_hierarchy_group_commands/verification.json` holds the strict result. The wider original translation-unit boundary remains unknown.

Central integration passes the original DOL hash and direct whole-file byte
comparison. Native objdiff records all 956 code bytes and 3 functions as
matching, with zero owned data. The source-section extent guard and generated
progress checks pass. Original baseline source remains exact after the
documented native-accessor and padding accounting corrections.
