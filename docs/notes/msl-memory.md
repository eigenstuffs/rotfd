# MSL and startup memory routines

Three complete memory-runtime units reproduce the original GSQE78 executable in isolated relocation-aware comparisons: eleven functions and 1,420 code bytes. They own no data or BSS. Central full-image integration is pending.

| Source | Section | Start | End, exclusive | Functions | Bytes |
| --- | --- | --- | --- | ---: | ---: |
| `MSL/mem.c` | `.text` | `0x801256A0` | `0x80125810` | 4 | 368 |
| `MSL/mem_funcs.c` | `.text` | `0x80125810` | `0x80125AF0` | 4 | 736 |
| `Runtime/__mem.c` | `.init` | `0x80005434` | `0x80005570` | 3 | 316 |

The MSL unit implements `memcmp`, `__memrchr`, `memchr`, and overlap-safe `memmove`. Four helpers copy aligned or unaligned words in either direction. The startup unit provides `memset`, its internal `__fill_mem`, and `memcpy`, which preserves the original direction selection even for overlapping regions.

## Compiler evidence

All eleven functions match with **GC/1.3** and `-O4,p`. No source change was needed to force the compiler's bit-mask instructions. GC/1.3.2 and GC/2.0 shorten each final `n &= 3` operation to one rotate-and-mask instruction; the original uses a loaded constant and an AND instruction. GC/1.2.5 differs in additional register choices and code generation. GC/1.3 reproduces every byte of all three units.

The two MSL units require deferred code generation, matching their reversed function order. The startup unit must omit `-inline deferred`; its `.init` functions follow source order. The `SECTION_INIT` annotation places the startup routines in the original section. `__fill_mem` is internal to that unit and has only the retained `memset` caller. Cast-lvalue increments retain the historical CodeWarrior extension with ANSI strict mode disabled.

## Source provenance

The reconstruction uses pinned community sources from [Melee mem.c](https://github.com/doldecomp/melee/blob/ae5898ee0dfda41b34fdf846f7d680a33e14779d/src/MSL/mem.c), [mem_funcs.c](https://github.com/doldecomp/melee/blob/ae5898ee0dfda41b34fdf846f7d680a33e14779d/src/MSL/mem_funcs.c), and [Runtime/__mem.c](https://github.com/doldecomp/melee/blob/ae5898ee0dfda41b34fdf846f7d680a33e14779d/src/Runtime/__mem.c). These are decompilation references, not an official SDK source release. The reverse-byte search is reconstructed directly from the target and added in the verified function order.

Unmodified reference files are retained under `reference/melee-msl/`; `MEMORY_PROVENANCE.md` records their hashes and attribution. Source includes are replaced with local target declarations, and no reference checkout is needed at build time.

## Reproduce

```sh
build/tools/wibo build/compilers/GC/1.3/mwcceppc.exe -c -proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline deferred -pool off -Cpp_exceptions off -i include -o scratch/msl_mem/final.o src/MSL/mem.c
python3 scratch/msl_mem/check_object.py
build/tools/wibo build/compilers/GC/1.3/mwcceppc.exe -c -proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline deferred -pool off -Cpp_exceptions off -i include -o scratch/msl_mem_funcs/final.o src/MSL/mem_funcs.c
python3 scratch/msl_mem_funcs/check_object.py
build/tools/wibo build/compilers/GC/1.3/mwcceppc.exe -c -proc gekko -fp hardware -enum int -str reuse -common off -O4,p -pool off -Cpp_exceptions off -i include -o scratch/runtime_mem/final.o src/Runtime/__mem.c
python3 scratch/runtime_mem/check_object.py
```

The verifiers compare all 1,420 code bytes directly against the original DOL, resolving four MSL helper calls and the internal startup fill call. They report zero mismatches. Original and generated machine-code bytes remain unmodified.

Separate manifests `msl_mem.json`, `msl_mem_funcs.json`, and `runtime_mem.json` contain compiler flags, ranges, names, sizes, linkage scopes, source hashes, and validation counts. Each scratch directory records its successful comparison and compiler experiments.
