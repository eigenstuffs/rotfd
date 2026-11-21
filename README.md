# SpongeBob SquarePants: Revenge of the Flying Dutchman

A work-in-progress matching decompilation of the USA GameCube executable,
**GSQE78**. The goal is C/C++ that rebuilds the original executable byte for
byte. The complete executable rebuilds today, using original objects for code
that has not yet been reconstructed.

The repository follows [doldecomp/melee](https://github.com/doldecomp/melee)'s
versioned build, source-unit, and objdiff workflow. Progress reports use the
native objdiff format consumed by [decomp.dev](https://decomp.dev/).

## Progress

See [the current verified progress](PROGRESS.md), the
[function inventory](progress/GSQE78-functions.csv), and the
[work roadmap](docs/ROADMAP.md). These distinguish byte-matched code, source
linked into the build, and code still supplied by original objects. Extracted
Python scripts and Ghidra pseudocode are research material and do not count
as native source completion.

`ninja` regenerates the progress exports after a successful executable hash
check. [decomp.dev integration](docs/DECOMP_DEV.md) is prepared; this local
project has not been registered or published there.

## Supported executable

| Version | Game ID | Normalized main.dol SHA-1 |
| --- | --- | --- |
| USA | GSQE78 | `5da8295a79bf297ab62c620e6ac66210be1c6ef5` |

The build targets the normalized DOL extracted from the supplied disc. It does
not rebuild the entire disc image or provide a native PC port.

## Build

Python 3.10+ and Ninja are required. The build helper fetches the pinned
CodeWarrior compiler, decomp-toolkit, objdiff, and supporting tools as needed.
The compiler runs through WiBo on supported hosts, or Wine. See
[the contributor guide](docs/CONTRIBUTING.md) for platform and matching details.

Prepare the reference from your local disc image or an already normalized DOL:

```sh
python3 tools/prepare.py "/path/to/game.iso"
```

This verifies the supported hash and writes `orig/GSQE78/main.dol`. It refuses
to replace a different reference file. Existing workspace users can verify
their reference by passing `orig/GSQE78/main.dol` itself.

Configure and build:

```sh
python3 configure.py
ninja
```

To use the native tools already present in this workspace:

```sh
python3 configure.py --dtk tools/dtk --objdiff tools/objdiff-cli
ninja
```

The final `CHECK` must report `main.dol: OK`. Build outputs, generated assembly,
and the native `report.json` live in `build/GSQE78/`.

## Match a unit

1. Select work from the roadmap and inspect its original assembly, symbols,
   and section ownership.
2. Save an objdiff baseline with `ninja baseline` before changing source.
3. Add or refine C/C++ in `src/`, split ranges in `config/GSQE78/splits.txt`,
   and confirmed symbol names in `config/GSQE78/symbols.txt`.
4. Open this directory in objdiff using the generated `objdiff.json`.
5. Keep work `NonMatching` in `configure.py` until its code and owned data
   match. Promote verified source, then run `ninja` and `ninja changes`.

The [contributor guide](docs/CONTRIBUTING.md) explains relocations, partial text
splits, compiler settings, and what evidence a contribution needs. The
[progress policy](docs/PROGRESS_POLICY.md) defines each metric.

## Layout

| Path | Purpose |
| --- | --- |
| `src/` | Reconstructed native C/C++ and runtime source |
| `include/` | Shared reconstructed declarations |
| `config/GSQE78/` | Symbols, splits, linker template, expected hash, filename evidence |
| `orig/GSQE78/` | Local reference executable |
| `tools/` | Build generation, matching probes, extraction preparation, progress export |
| `build/GSQE78/` | Generated objects, assembly, executable, objdiff report |
| `progress/` | Reviewable JSON summary and complete function inventory |
| `docs/` | Contributing, roadmap, progress policy, integration, research notes |
| `reference/` | Historical library sources used as research references |

See [project structure](docs/PROJECT_STRUCTURE.md) for the relationship between
native source, provisional splits, scripts, and analysis artifacts.

## Research and provenance

The previous README is preserved in full as
[research notes](docs/research-notes.md), including disc layout, Ghidra setup,
embedded Python, Dolphin memory tools, DGC files, and gameplay investigations.
It is a historical notebook; newer verified findings live in
[unit notes](docs/notes/). The existing extraction and memory tools remain
available in their original locations.

Complete matching units establish CPython v2.1 as the embedded interpreter's
strongest source reference. The [unit notes](docs/notes/) record recovered
layouts, compiler settings, omitted unlinked APIs, and integration evidence.
[Reference provenance](reference/README.md) distinguishes these results from
earlier version guesses. Adapted historical CPython files retain their
upstream copyright and permission notices.

## Validation and automation

```sh
python3 -m unittest discover -s tests -v
ninja
python3 tools/progress.py --check
ninja changes
```

Tooling tests run independently of the game input. The optional
[matching-build workflow](.github/workflows/build.yml) requires a configured
runner and external reference DOL; it exports only reports. See
[decomp.dev setup](docs/DECOMP_DEV.md) for the runner settings and registration
steps. No hosting, repository publication, or service registration is performed
by the local build.
