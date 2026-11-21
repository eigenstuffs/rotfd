# Python system module

`src/Python/sysmodule.c` reconstructs the complete linked CPython 2.1 system module. Its 18 emitted functions match all 4,564 original text bytes after relocation. The original module initialization explicitly reports Python 2.1.0 final (`0x020100F0`) and API version 1010.

The implementation derives from the retained official `reference/cpython-2.1/Python/sysmodule.c`, with its license retained in `reference/cpython-2.1/LICENSE`. The recovered ABI declarations are self-contained. The source preserves system dictionary access, display and exception hooks, tracing and profiling state, encoding and recursion settings, frame inspection, module initialization, path splitting, and variadic standard-error output.

| Section | Original range | Verified content |
| --- | --- | --- |
| `.text` | `0x801A26A8..0x801A387C` | 4,564 bytes, 18 functions |
| `.data` | `0x802E3840..0x802E51D8` | 6,548 bytes plus 4 zero padding bytes |
| `.sdata` | `0x80377068..0x803770E8` | 122 bytes plus 6 zero padding bytes |
| `.sbss` | `0x80377F58..0x80377F5C` | 4 zero-initialized bytes for `warnoptions` |

`list_builtin_module_names`, `makepathobject`, and `mywrite` are inline-only helpers. The original linked TU has no emitted `PySys_GetFile`, warning-option reset/add APIs, `PySys_SetArgv`, or `PySys_WriteStdout`; those unused API bodies are omitted. Ten named small character arrays preserve the original reused literal order, including the `stdout` string originally encountered while compiling the unlinked stdout writer. The remainder of the compiler's string emission remains unchanged.

The frame structure uses the fixed object header: `f_back` is at offset 8. The interpreter and thread fields follow the independently matched `pystate.c` ABI. Path splitting uses `:`. Variadic output uses the confirmed 12-byte Metrowerks `va_list`, 80-byte MSL `FILE`, and a 1,001-byte local formatting buffer.

Run the independent check from the repository root:

```sh
python3 scratch/sysmodule/verify.py
```

The check compiles with GC/2.0 and the manifest's recovered flags, applies all 306 relocations, and compares every allocated initialized section against the SHA-verified original DOL. It also verifies section extents, explicit zero padding, and the SBSS range. No branch or immediate differences are masked. Source and object hashes, function mappings, data mappings, and newly identified imports are recorded in `config/GSQE78/candidates/sysmodule.json`.

Integration must shrink the original eight-byte `lbl_80377F58` symbol to the four-byte `warnoptions` object and preserve the following four bytes separately. The isolated candidate is ready; the normal project build and full-DOL SHA check remain the integration gate. Current project totals belong in the generated `PROGRESS.md` rather than this reconstruction note.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `Python/sysmodule.c` | `.data` | `0x802E3840..0x802E51D4` (6,548 bytes) | `0x802E51D4..0x802E51D8` (4 bytes) |
| `Python/sysmodule.c` | `.sdata` | `0x80377068..0x803770E2` (122 bytes) | `0x803770E2..0x803770E8` (6 bytes) |

Current native objdiff credits `Python/sysmodule.c`: 6,674 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
