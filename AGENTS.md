# Working on this decompilation

Read `README.md`, `PROGRESS.md`, and `docs/CONTRIBUTING.md` before changing
matching source. `docs/ROADMAP.md` tracks remaining work; `docs/notes/` holds
verified unit findings. `docs/research-notes.md` is a preserved historical
notebook and may be superseded by newer unit notes.

## Build and acceptance

- Target: normalized GSQE78 DOL, expected hash in `config/GSQE78/build.sha1`.
- Configure with `python3 configure.py`; use `--dtk tools/dtk --objdiff
  tools/objdiff-cli` when using the native binaries already in this workspace.
- Run `ninja baseline` before a matching change. Keep new work NonMatching
  until code and owned data match. After integration, `ninja` must pass the
  original DOL hash check; `ninja changes` must show no match regressions.
- Changes to progress or input preparation also require
  `python3 -m unittest discover -s tests -v`.
- Do not change the expected hash, original executable, or original disc to
  make source pass. `tools/prepare.py` verifies a supported local input.
- Do not count Ghidra pseudocode, extracted Python scripts, disassembly, or
  relocation-masked probe scores as matching source.

## Ownership and reporting

- Put reconstructed source in `src/`, shared declarations in `include/`,
  versioned addresses and splits in `config/GSQE78/`.
- Coordinate edits to shared symbols, splits, and configure.py when agents
  work in parallel. Compile isolated probes before one integrator relinks.
- A partial text-only split is allowed when all references resolve and the
  full DOL matches. Document the original data and functions still outside it;
  a matching build unit is not necessarily a complete original translation unit.
- Let `ninja` generate `PROGRESS.md` and `progress/GSQE78*`. Preserve the native
  objdiff report for decomp.dev; never remove unknown units from the denominator.
- Preserve unrelated and pre-existing local changes and research artifacts.
  This workspace's existing Git history includes original disc/extraction
  material; a `.gitignore` entry alone does not make that history source-only.
