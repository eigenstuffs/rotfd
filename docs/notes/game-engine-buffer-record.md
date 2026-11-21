# Engine buffer and record lifetime fragments

Production integration is accepted. The canonical manifest is
`config/GSQE78/candidates/game-engine-buffer-record.json`. The complete DOL passes its original SHA-1,
`ninja changes` shows no regressions, source extent and progress checks pass,
and all 26 unit tests pass.

Four production units reconstruct five complete ordinary C/C++ functions,
1,100 bytes of `.text`, and no data. These are partial text splits; the original
translation-unit boundaries are not established.

| Source suffix | Owned text | Functions / bytes | Extra flags |
| --- | --- | ---: | --- |
| `engine_buffer_record_8023576C.c` | `8023576C..802358AC` | 1 / 320 | none |
| `engine_buffer_record_80235DC0.cpp` | `80235DC0..80235EBC` | 1 / 252 | none |
| `engine_buffer_record_80237C40.cpp` | `80237C40..80237CA0` | 1 / 96 | none |
| `engine_buffer_record_80238D28.cpp` | `80238D28..80238ED8` | 2 / 432 | `-use_lmw_stmw on` |

All use the standard Game GC/1.3.2 compiler configuration, with only the listed
bitmap save/restore flag. All five original function symbols need global scope.
Declarations are local to these dedicated sources; no existing header is changed.

## Behavior and source structure

`fn_8023576C` constructs an ObjectsRoot prefix, installs its original external
virtual table, constructs four 0x74-byte state records at 0x20 with the original
array-construction helper, and constructs handle members at 0x1F0 through 0x1FC.
The observed typed constructor layers clear the packed handle word three, two,
three, and one times respectively after calling the base constructor. Scoped
local member pointers preserve the original register allocation. It then clears
each state's active pointer and assigns flags 0 to the first and 0x400 to the
remaining states. This source emits one complete function and no constructor
helpers or tables.

`fn_80235DC0` clears the lock byte at 0x5D and word at 0x60, initializes an empty
temporary handle through five observed clearing layers, assigns it to the handle
at 0x7C using the original decrement/copy/increment calls, then destroys the
temporary. It initializes words at 0xA8/0xA4 and invokes virtual slot 0x50 for
three scalar defaults. The defaults are original external `const` small-data
floats; const qualification recovers the native load scheduling.

`fn_80237C40` calls the original owner reset and selects mode 7, then invokes
virtual slots 0x44 and 0x34.

`fn_80238D28` initializes the observed Bitmap fields: index/color pointers,
six level pointers, dimensions, resource identifier -1, counters and flags,
and format 3. It preserves the separate flag-byte updates. `fn_80238D98`
restores the original Bitmap table, releases a registered device resource when
present, frees index/color and level allocations, invokes virtual slot 0x18,
frees the extra allocation, and runs the Resource/Root destruction path. A
positive signed deletion argument also frees the object. Isolating the ordinary
level-release loop in an inline helper recovers the original counter/pointer
register choices; the helper generates no separate allocated code. Virtual
method declarations emit no virtual tables or method implementations.

## Ownership and verification

`scratch/engine_buffer_record_20261010e/final_integration.json` records all section
bounds, complete functions, bindings, flags, and 45 actual relocations. The strict
verifier recompiles the formatted production source, rejects extra allocated
sections and functions, applies every REL24/HA/LO/SDA21 relocation to its versioned
target, and compares every owned byte directly to the protected DOL. No bits are
masked and no assembly or instruction substitution is used.

The ownership audit checks each complete original function against generated
assembly and scans all 3,141 original `.extabindex` entries plus the complete
24-entry `.ctors` and 8-entry `.dtors` sections. No records reference any selected
function. The source owns zero exception, startup, data, and BSS bytes. All
external tables, manager/allocator globals, constants, original callees and
neighboring functions retain their owners. The saved ownership report lists
original fallback units and their remaining ranges; this split is text only.

`verify.py` and `audit.py` pass for these final sources. The integrator registers
the units NonMatching, verifies the full original DOL hash and native comparison,
and promotes only after acceptance. The final configuration snippet includes the
bitmap unit's required save/restore flag.

Private probes for `fn_80237BC8` remain uncredited: the best ordinary sources
retain seven instruction differences in address calculation. Failed constructor,
release-loop, and compiler-option probes are preserved in the scratch directory.
