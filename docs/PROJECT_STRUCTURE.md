# Project structure

The build follows the source/configuration/original-input separation used by
[doldecomp/melee](https://github.com/doldecomp/melee). Preserve the game's own
source identities as they are recovered; Melee's character and engine folder
names are specific to Melee.

| Path | Role |
| --- | --- |
| `src/Runtime.PPCEABI.H/` | Reconstructed Metrowerks runtime |
| `src/Objects/` | Reconstructed embedded Python object code |
| `include/` | Headers and recovered layouts used by reconstructed source |
| `config/GSQE78/config.yml` | Input hash, symbol/split files, and linker settings |
| `config/GSQE78/splits.txt` | Confirmed TU section ranges |
| `config/GSQE78/symbols.txt` | Symbol names, addresses, sizes, and attributes |
| `config/GSQE78/filemap.json` | Source-string cross-references for TU discovery |
| `config/GSQE78/ldscript.tpl` | Linker template, including the development-build stack reservation |
| `orig/GSQE78/` | Local original executable used as the comparison target |
| `configure.py` | Compiler/tool pins, source registration, matching status, and progress categories |
| `tools/` | Build/report infrastructure and matching probes |
| `build/GSQE78/` | Generated objects, assembly, linker script, executable, and objdiff report |
| `PROGRESS.md`, `progress/` | Generated, reviewable progress snapshots |
| `docs/` | Workflow, roadmap, and preserved research |

The existing research workspace remains useful:

| Path | Role |
| --- | --- |
| `decomp/`, `ghidra_project/`, `ghidra_scripts/` | Static analysis and decompiler exports |
| `reference/cpython-1.5.2/` | Upstream comparison source with its original attribution |
| `extracted/`, `pycs*/`, `python_src*/`, `nested/` | Disc extraction and script analysis outputs |
| `gcwatch.py`, `gdbstub.py`, `memserver.c`, `VARS.md` | Dolphin memory inspection and variable research |
| [`docs/research-notes.md`](research-notes.md) | Preserved earlier findings and experimental procedures |

Generated assembly and decompiler output are inputs to the matching process,
not reconstructed source. Register a real TU before counting its source.
Use confirmed original filenames when adding game, engine, SDK, or interpreter
directories; do not move research files merely to make the tree look complete.

For the configuration formats, see Melee's
[`splits.txt` guide](https://github.com/doldecomp/melee/blob/master/docs/splits.md)
and [`symbols.txt` guide](https://github.com/doldecomp/melee/blob/master/docs/symbols.md).
The installed decomp-toolkit version and local build remain authoritative for
features supported here.
