# Python/compile.c

The linked source compiler and code-object unit is reconstructed from CPython 2.1. All 100 retained functions, totaling 75,896 bytes, and all initialized data match the original GSQE78 executable in an isolated relocation-aware comparison. Central integration passed the full DOL SHA-1 check (`5da8295a79bf297ab62c620e6ac66210be1c6ef5`), and objdiff reports all retained code and data matching.

| Section | Start | End, exclusive | Emitted retained bytes | Owned bytes |
| --- | --- | --- | ---: | ---: |
| `.text` | `0x8017C5F8` | `0x8018EE70` | 75,896 | 75,896 |
| `.data` | `0x802DC0D0` | `0x802DCFA0` | 3,787 | 3,792 |
| `.sdata` | `0x80376678` | `0x803766F0` | 116 | 120 |
| `.sdata2` | `0x8037A188` | `0x8037A190` | 8 | 8 |
| `.bss` | `0x8033E280` | `0x8033E380` | 256 | 256 |
| `.sbss` | `0x80377E78` | `0x80377E80` | 8 | 8 |

The data and small-data tails contain verified zero-filled linker padding. BSS contains the 256-byte identifier-character table. Small BSS contains `Py_OptimizeFlag` and the symbol-table implicit-name cache. Their addresses are proven by access instructions; uninitialized storage has no original file bytes to compare.

## Recovered behavior and compiler settings

The source retains the Python parser-tree compiler, nested-scope symbol analysis, bytecode and line-number emission, literal parsing, name mangling, and code-object operations. The code-object type, member table, compiler jump tables, diagnostic messages, and caches belong to this unit.

This unit requires `-enum min`, overriding the shared `-enum int` setting. The `enum cmp_op` value in `com_comparison` uses the target's minimum-size representation. Compiling the otherwise identical source with `-enum int` changes 31 instruction bytes; `-enum min` matches all retained code.

The target allocator adds one byte to `PyMem_NEW` requests. Character classification uses the target MSL character map, including its `0x20` hexadecimal-digit mask. The source retains CPython's disabled assertion and floating-point-protection configuration. The six internal-error source-line constants are explicit: 236, 265, 274, 1093, 1103, and 1110.

The retained object contains four ordinary helper bodies with no incoming relocation from any retained function or data: `symtable_import`, `symtable_list_comprehension`, `get_ref_type`, and `com_set_lineno`. The normal linker must discard those bodies. Keeping their definitions preserves the original literal-pool order. Other helpers that the original fully inlines use `static inline`; their full C algorithms remain present. No bytecode-emission specialization or binary patch is used.

This distinction matters for verification: the raw compiler object includes those four surplus bodies, whereas the original DOL contains 100 retained functions. `scratch/compile/retained.json` records the explicit retained roster and original addresses. The verifier translates code addresses through that roster, rejects any retained reference to an omitted body, and compares every retained instruction and initialized data byte. The successful full-image link confirms natural stripping of the four unused bodies and exact placement of retained text and data.

The source contains local recovered ABI declarations and constants. It builds without including the reference checkout. Reconstruction names and inline annotations do not claim original debug-symbol provenance.

## Reproduce

```sh
build/tools/wibo build/compilers/GC/2.0/mwcceppc.exe -c -proc gekko -fp hardware -enum min -str reuse -common off -opt level=4,nopeephole,speed -inline auto,deferred -Cpp_exceptions off -pool off -i include -o scratch/compile/final.o src/Python/compile.c
python3 scratch/compile/check_object.py
```

The verifier resolves 2,479 relocations and reports zero mismatching initialized bytes. It checks the original `orig/GSQE78/main.dol`; neither original nor generated machine-code bytes are modified.

`config/GSQE78/candidates/compile.json` supplies the retained function names, section ranges, data/state symbols, scopes, sizes, additional external names, source hash, and the explicit linker-stripping requirement. `scratch/compile/verification.txt` records the successful comparison. `src/Python/compile.c` is authoritative; durable scratch files retain the recovery experiments.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `Python/compile.c` | `.data` | `0x802DC0D0..0x802DCF9B` (3,787 bytes) | `0x802DCF9B..0x802DCFA0` (5 bytes) |
| `Python/compile.c` | `.sdata` | `0x80376678..0x803766EC` (116 bytes) | `0x803766EC..0x803766F0` (4 bytes) |

Current native objdiff credits `Python/compile.c`: 4,175 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
