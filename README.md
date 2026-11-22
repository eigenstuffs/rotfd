# SpongeBob SquarePants: Revenge of the Flying Dutchman

A matching decompilation of the USA GameCube release (GSQE78). The C/C++ in
`src/` rebuilds `main.dol` byte for byte.

| | Matched |
| --- | ---: |
| Code | 100% (8,803 / 8,803 functions) |
| Data | 100% |

| Version | Game ID | `main.dol` SHA-1 |
| --- | --- | --- |
| USA | GSQE78 | `5da8295a79bf297ab62c620e6ac66210be1c6ef5` |

## Building

Requires Python 3.10+ and Ninja. The compiler, decomp-toolkit and objdiff are
downloaded on first build; the compiler runs through WiBo or Wine.

Extract the executable from your own disc image:

```sh
python3 tools/prepare.py "/path/to/game.iso"   # writes orig/GSQE78/main.dol
```

Then:

```sh
python3 configure.py
ninja
```

The build ends with `build/GSQE78/main.dol: OK` when the output matches.

## Layout

| Path | Contents |
| --- | --- |
| `src/`, `include/` | Game, Dolphin SDK, MSL, MetroTRK and embedded CPython 2.1 source |
| `config/GSQE78/` | Symbols, splits, linker script and expected hash |
| `tools/` | Build generation and progress export |
| `orig/GSQE78/` | Your `main.dol` (not included) |

The embedded CPython sources are adapted from CPython 2.1 and keep their
upstream copyright notices.
