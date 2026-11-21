# decomp.dev integration

The project uses objdiff's native report format so its measurements can feed
[decomp.dev](https://decomp.dev/). A local report and compatible workflow are
preparation for integration; they do not register or publish this project.

## Report contract

Generate a verified report with the standard build:

```sh
python3 configure.py --dtk tools/dtk --objdiff tools/objdiff-cli
ninja
```

Upload `build/GSQE78/report.json` in a GitHub Actions artifact named
**`GSQE78_report`**. Keep the filename `report.json` inside the artifact and
preserve its native objdiff schema, including all units and their measures.
The readable `PROGRESS.md` and function CSV are companion views and cannot
substitute for this report. The artifact convention is documented in the
[official integration guide](https://decomp.wiki/tools/decomp-dev).

The generated `objdiff.json` must include every linked target object, including
ones with no reconstructed source. Omitting those units shrinks the denominator
and overstates progress. Such units have no source-built base object. The
current configure/Ninja tooling supplies this inventory; do not replace it
with a hand-selected list of completed files. This is also required by the
[integration guide](https://decomp.wiki/tools/decomp-dev).

## Workflow and registration

The [build workflow](../.github/workflows/build.yml) prepares this artifact on a
self-hosted runner labeled `rotfd`. Configure repository variable
`ROTFD_ORIGINAL_DOL` with the runner-local path to the original `GSQE78` DOL.
The runner also needs the build dependencies. When it is ready, set repository
variable `ROTFD_BUILD_ENABLED` to the string `true`. Both push and manual
dispatch builds require this setting and the repository's default branch.
A manual dispatch can exercise the setup. These files do not provision a
runner or register a decomp.dev project.

Build and verify locally before publishing the JSON artifact. Game
executables, extracted disc files, compiler binaries, and assembly do not
belong in that report artifact.

The existing local Git history already contains the supplied disc image and
extracted game assets. Adding ignore rules does not remove tracked files or
earlier commits. This workspace has no configured remote, and its history has
been preserved. Prepare a source-only publication history before creating a
public repository; the current workspace is not ready to publish as-is.

There is an important trigger requirement: as checked on 2026-09-07,
decomp.dev's onboarding and historical refresh code query completed **push**
workflow runs. A workflow run triggered only by `workflow_dispatch` can test
the build and artifact, but is insufficient for that discovery path. Enable
the repository's configured default-branch push build when remote integration
is intended. This is visible in the service's
[`check_for_reports` and `refresh_project` implementation](https://github.com/encounter/decomp.dev/blob/main/crates/github/src/lib.rs).

After a default-branch push produces the report artifact, a repository admin
can add the project through [decomp.dev's management page](https://decomp.dev/manage/new).
The optional [GitHub app](https://decomp.wiki/tools/decomp-dev) supplies workflow
notifications and can post PR progress comments; installing or configuring it
is separate from generating a report. Confirm the imported version, full code
denominator, and known-subset category labels against the local snapshot.

## Interpreting the dashboard

Use the definitions in [PROGRESS_POLICY.md](PROGRESS_POLICY.md). Matching code,
linked source coverage, fuzzy similarity, and a SHA-verified reconstruction
answer different questions. Keep unknown units in the report, and label
library categories according to the units actually assigned. Script
decompilation and Ghidra exports remain research milestones rather than native
source-match credit.
