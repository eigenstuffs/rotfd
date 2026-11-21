# Python/ceval.c

The complete linked bytecode-evaluation unit is reconstructed from CPython 2.1. All 41 functions, including the 18,552-byte interpreter loop, match the original GSQE78 executable in an isolated relocation-aware comparison. Central integration passed the full DOL SHA-1 check (`5da8295a79bf297ab62c620e6ac66210be1c6ef5`), and objdiff reports all retained code and data matching.

| Section | Start | End, exclusive | Emitted bytes | Owned bytes |
| --- | --- | --- | ---: | ---: |
| `.text` | `0x80173A28` | `0x8017BB98` | 33,136 | 33,136 |
| `.data` | `0x802DB450` | `0x802DBF70` | 2,848 | 2,848 |
| `.sdata` | `0x803765F8` | `0x80376678` | 123 | 128 |
| `.bss` | `0x8033E180` | `0x8033E280` | 256 | 256 |
| `.sbss` | `0x80377E50` | `0x80377E68` | 20 | 24 |

The initialized small-data tail is verified zero-filled linker padding. BSS contains 32 pending-call records; small BSS contains the queue positions, pending-work flag, and two reentrancy flags. Their locations are proven by instructions accessing them. Uninitialized storage has no original file bytes to compare.

## Recovered behavior and build details

The unit evaluates Python bytecode, binds function arguments, manages exceptions and trace callbacks, dispatches native/Python/method/instance calls, handles imports and execution statements, performs sequence unpacking and slicing, and services pending calls. Its recursion limit, diagnostic strings, and switch tables are owned by the reconstructed source.

This unit requires `-enum min`, overriding the shared `-enum int` setting. The original uses minimum-size storage for `enum why_code`; the conversion in the `END_FINALLY` case and unsigned comparisons make the distinction visible in machine code. The complete interpreter loop matches with that compiler setting.

`HAVE_SIGNAL_H` selects the original periodic-work path. Thread support is not enabled in the linked implementation. The otherwise unused `PyEval_SaveThread` and `PyEval_RestoreThread` bodies are omitted from this unit, as they have no retained addresses in its text range. The two following functions at `0x8017BB98` and `0x8017BC2C` initialize/finalize codec state and belong to the next translation unit.

The target's `PyMem_NEW` adds one byte to its allocation request. This reproduces the keyword-argument pointer allocation in `call_eval_code2`. `isspace` remains an external MSL function call in the interpreter, matching the original instructions. Four shared helpers (`load_args`, `update_star_args`, `get_func_desc`, and `PyEval_CallObject`) are emitted inline without surplus standalone bodies. Error-path filename and source-line constants are explicit.

The source preserves the CPython 2.1 interpreter, frame, code-object, thread-state, and object ABIs. Its declarations and opcode constants are local to the source, so the reference checkout is not a build dependency. The algorithms and historical behavior are retained without correctness changes.

## Reproduce

```sh
build/tools/wibo build/compilers/GC/2.0/mwcceppc.exe -c -proc gekko -fp hardware -enum min -str reuse -common off -opt level=4,nopeephole,speed -inline auto,deferred -Cpp_exceptions off -pool off -i include -o scratch/ceval/final.o src/Python/ceval.c
python3 scratch/ceval/check_object.py
```

The verifier resolves all 1,184 relocations and compares every initialized byte directly against the original DOL. It reports zero mismatches. Original and generated machine-code bytes remain unmodified.

`config/GSQE78/candidates/ceval.json` contains section ranges, the 41 function names, state symbols, sizes, linkage scopes, and 21 newly identified external API names. `scratch/ceval/verification.txt` preserves the isolated result. `src/Python/ceval.c` is authoritative; scratch candidates and scripts retain the recovery history.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `Python/ceval.c` | `.sdata` | `0x803765F8..0x80376673` (123 bytes) | `0x80376673..0x80376678` (5 bytes) |

Current native objdiff credits `Python/ceval.c`: 3,247 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
