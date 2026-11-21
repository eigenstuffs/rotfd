# Python file objects

This complete unit follows CPython 2.1 `Objects/fileobject.c`, preserving
its APIs, methods, and I/O algorithms. The upstream license is in
`reference/cpython-2.1/LICENSE`.

| Section | Range | Bytes |
| --- | --- | ---: |
| `.text` | 0x801412C8–0x80143500 | 8,760 |
| `.data` | 0x802D28D0–0x802D2C98 | 968 |
| `.sdata` | 0x803760B8–0x80376144 | 140 |
| `.sbss` | 0x80377DE0–0x80377DE4 | 4 |

The isolated compile verifies all 28 functions, 8,760 instruction bytes,
and 1,108 initialized data bytes against the original DOL, applying every
relocation. `config/GSQE78/candidates/fileobject.json` records the ranges,
function sizes, symbol visibility, and external identities. The complete
linked executable must pass its original SHA-1 before acceptance.

The compiler is CodeWarrior GC/2.0 with `-proc gekko -fp hardware -enum int
-str reuse -common off -opt level=4,nopeephole,speed -inline auto,deferred
-pool off -Cpp_exceptions off`. The portable seek/tell wrappers, buffer-size
helper, and closed-file error helper are declared `static inline`. The
unused `PyObject_AsFileDescriptor` entry point remains as inline source
and has no body in this executable.

The reconstructed platform configuration has `HAVE_SETVBUF`, a 4,096-byte
stdio buffer size, and 32-bit file offsets. It lacks large-file support,
truncation, `fstat`, and unlocked character I/O. CPython's thread-release
macros reduce to braces. Its `__MWERKS__` path retains the check for
`fopen` failing without setting `errno`.

The local `FILE` layout models the MSL fields the source uses: the error
byte at offset 0xA, byte-buffer pointer at 0x24, and unsigned remaining-byte
count at 0x28. The `getc` macro first selects byte orientation through
`fwide`, then reads directly from the stream buffer when available and
calls `__getc` to refill it otherwise. The C library buffering constants
are `_IONBF = 0`, `_IOLBF = 1`, and `_IOFBF = 2`.

The original `PyFile_GetLine` diagnostic records filename `fileobject.c`
and line 895, while the corresponding official CPython 2.1 statement is
on line 888. The source retains the original diagnostic explicitly; no
algorithm change is needed. The static cached xreadlines callable appears
as compiler-local `xreadlines_function$345` and occupies four BSS bytes.

The small-data and BSS ends include only their own four-byte-aligned
contents. The following float unit starts four bytes later in both cases,
at 0x80376148 and 0x80377DE8, respectively.

## Source ownership correction (2026-09-08)

The section-extent audit supersedes any larger source extents or padding-inclusive totals above. Current boundaries are end-exclusive:

| Source | Section | Emitted source | Uncredited original tail |
| --- | --- | --- | --- |
| `Objects/fileobject.c` | `.data` | `0x802D28D0..0x802D2C95` (965 bytes) | `0x802D2C95..0x802D2C98` (3 bytes) |
| `Objects/fileobject.c` | `.sdata` | `0x803760B8..0x80376141` (137 bytes) | `0x80376141..0x80376144` (3 bytes) |

Current native objdiff credits `Objects/fileobject.c`: 1,106 data bytes. The listed tails now belong to separate `NonMatching` original units under `padding/source_extents/`. They remain in the original denominator; compiler-emitted internal alignment remains source-owned. See the [audit correction](source-section-padding.md) and [exact ownership inventory](../../config/GSQE78/source_padding.json).
