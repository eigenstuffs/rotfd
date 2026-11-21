# Python interpreter startup and execution

`src/Python/pythonrun.c` reconstructs the complete linked CPython 2.1 interpreter startup and execution unit. All 22 retained functions match 8,520 original text bytes after relocation. They include interpreter initialization and finalization, parser/compiler and execution wrappers, syntax-error reporting, exception display, fatal errors, and signal-handler wrappers.

The implementation derives from the official source retained at `reference/cpython-2.1/Python/pythonrun.c`, under `reference/cpython-2.1/LICENSE`. It uses the recovered object, thread, interpreter, parser-error, grammar, and MSL file ABIs. Native Python thread support and platform-specific Windows/Mac branches are disabled, as in the original compiled instructions.

| Section | Original range | Verified retained content |
| --- | --- | --- |
| `.text` | `0x801A01C8..0x801A2310` | 8,520 bytes, 22 functions |
| `.data` | `0x802E3270..0x802E36D8` | 1,124 bytes plus 4 zero padding bytes |
| `.sdata` | `0x80376FC0..0x80377038` | 120 bytes |
| `.bss` | `0x8033E480..0x8033E500` | 128 bytes for exit callbacks |
| `.sbss` | `0x80377F40..0x80377F58` | Six 4-byte globals |

The next four functions at `0x801A2310..0x801A26A8` belong to the symbol-table object unit. They are outside this reconstruction.

The source retains four ordinary C bodies that the original linker discarded: `call_sys_exitfunc`, `initsite`, `initmain`, and `PyRun_SimpleString`. Their emitted text totals 972 bytes. Compiling them preserves the original order of shared literals used by retained functions. The existing linker configuration can discard unused functions normally; no object patching, raw instruction arrays, or assembly substitutes are involved. These four unused bodies are excluded from the matching function count.

`Py_Exit`, the parser-string helper, node execution helpers, interrupt initialization, and low-level exit callback iteration are inline-only where no standalone body exists in the original. Other absent public APIs and three unlinked flag globals are omitted. The retained SBSS order is `Py_UnicodeFlag`, `initialized`, `nexitfuncs`, `Py_NoSiteFlag`, `Py_VerboseFlag`, and `Py_DebugFlag`.

Run the independent check from the repository root:

```sh
python3 scratch/pythonrun/verify.py
```

The verifier compiles with the manifest's GC/2.0 flags, accounts for every emitted function, maps the 22 retained functions to their recovered addresses, and applies all 665 retained relocations. It compares every retained instruction and initialized-data byte against the SHA-verified original DOL, verifies explicit padding, and checks the zero-initialized ranges. It also rejects any retained relocation targeting one of the four discarded functions; the 73 relocations owned exclusively by those discarded bodies are reported separately. No instruction differences are masked.

The generated 11-entry `err_input` jump table is verified along with the rest of `.data`. Source/object hashes, imported symbol discoveries, exact section splits, retained function mappings, and the explicit discarded-function list are recorded in `config/GSQE78/candidates/pythonrun.json`.

Integration passed the normal project build, full-DOL SHA-1 comparison, and objdiff code/data checks. The actual linker discarded all four unused bodies; only the 22 retained functions contribute to matching progress. Use the generated `PROGRESS.md` for current totals.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `Python/pythonrun.c` | `.data` | `0x802E3270..0x802E36D4` (1,124 bytes) | `0x802E36D4..0x802E36D8` (4 bytes) |

Current native objdiff credits `Python/pythonrun.c`: 1,396 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
