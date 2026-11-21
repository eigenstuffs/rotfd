# Progress policy

Progress measures source reconstruction against the normalized `GSQE78` DOL.
It does not measure recovery of disc assets, Python scripts, or a native PC
port. The target's hash and section configuration live in
[`config/GSQE78/`](../config/GSQE78/).

## Evidence and regeneration

Run the standard build from the repository root:

```sh
python3 configure.py --dtk tools/dtk --objdiff tools/objdiff-cli
ninja
```

The build produces `build/GSQE78/report.json` through objdiff and checks
`build/GSQE78/main.dol` against `config/GSQE78/build.sha1`. Its progress step
generates these reviewable outputs:

| Output | Purpose |
| --- | --- |
| [`PROGRESS.md`](../PROGRESS.md) | Readable current totals and unit status |
| [`progress/GSQE78.json`](../progress/GSQE78.json) | Machine-readable progress snapshot |
| [`progress/GSQE78-functions.csv`](../progress/GSQE78-functions.csv) | Function inventory for selecting and reviewing work |
| `build/GSQE78/report.json` | Full generated objdiff measurements |

`python3 configure.py progress` reads an existing report; it does not rebuild
source or rerun the link. Use `ninja` before presenting fresh results. Never
hand-edit generated measurements to reflect a planned or unverified match.

## What each measure means

| Measure or status | Interpretation |
| --- | --- |
| SHA-1 verified rebuild | Source objects and original fallback objects reconstruct the target executable exactly |
| Matched code bytes/functions | Compiled source matches the corresponding target according to objdiff's configured comparison rules |
| Complete/linked source units | `Matching` objects included in the standard link; the declaration must be supported by a passing build |
| Matched data bytes | Data coverage reported by objdiff, displayed separately from code |
| Fuzzy match | Similarity useful for iteration; never a completion percentage |
| NonMatching source | Compiled for comparison but the original fallback object is linked |
| Unregistered source or probe | Research only; excluded from matching progress |
| Automatically split object | Provisional binary partition that has not been assigned to a reconstructed TU |
| Ghidra or script decompiler output | An analysis aid; no source-match credit without the corresponding build validation |

A matching rebuild can pass while most code still comes from original objects.
Conversely, a function in a NonMatching TU may compare exactly while its other
functions or data still prevent promotion of the TU. Report these facts
separately. The function inventory's `unit_status` describes the owning unit's
link status; its objdiff fuzzy score is a separate field. A configured split
can also cover just part of an original TU, so completing the split does not
prove the entire original source file and its data have been reconstructed.

Objdiff may relax relocation comparisons. That can make a function comparison
look complete before its references are correct. The final linked DOL hash is
the decisive integration check; source completion also requires the unit to be
registered and linked from C/C++.

Some compiler versions leave nonsemantic alignment bytes in exception records
uninitialized. A unit may use the build toolkit's supported exception-padding
cleanup when its manifest identifies the exact bytes, records raw and cleaned
object hashes, and proves that all instructions and semantic fields remain
unchanged. The protected reference and expected DOL hash stay unchanged.
[The Gecko unwinder](notes/runtime-gecko-exception.md) records the current
two-byte case; the complete build still has to match the original executable.

## Denominators and categories

Use the full report's code-byte total for overall coverage. Show byte and
function numerators alongside denominators. Object and function counts can
change as boundaries and symbols are corrected; generated object counts are
not counts of original source files. Explain such changes in the handoff.

Library categories cover the units assigned to them in `configure.py`.
An SDK category containing only identified runtime files can show 100% while
much of the game's SDK code remains unclassified. Label such categories as
known subsets. Keep embedded Python separate from game code and show
unclassified coverage explicitly when deriving a category breakdown. Do not
infer all engine/game/SDK boundaries from address ranges alone.

Store raw counts in the snapshot and round only for presentation. Keep one
generated current snapshot in version control; Git history supplies the
historical record. Research accomplishments belong in the roadmap and notes,
not in the matched-code numerator.

## Regression comparison

Run `ninja baseline` on the verified starting state. After changes, run `ninja`
and `ninja changes` (or `ninja changes_all` for every delta). The baseline lives
in `build/GSQE78/baseline.json`; the comparison is
`build/GSQE78/report_changes.json`. Do not regenerate the baseline until its
comparison is no longer needed.

The retained initial baseline includes one subsequently corrected attribution:
the exception initializer had counted an eight-byte native accessor and four
bytes of linker alignment as recovered source. The baseline stays unchanged,
so the comparison exposes that decrease. The [initializer audit](notes/runtime-init-cpp-exceptions.md)
records the exact ranges and source-only counts; the registration instructions
still match completely. Accounting corrections must retain the original bytes
and denominators and must not relax byte comparison for any recovered code.

A later audit of all 555 linked source units removed another 366 bytes of
trailing data/BSS alignment from source credit. These bytes now have explicit
original-padding owners. The only additional decrease against the retained
initial baseline is moduleobject's final data byte at `0x802D4403`: its data
credit changes from 408 to 407 bytes, with all code and data objects unchanged.
The [section-extent audit](notes/source-section-padding.md) records all ranges.
Compiler-emitted internal alignment remains part of its source section;
padding beyond that section must not be credited as reconstructed data.

This follows Melee's separation of linking, object comparison, and generated
progress in its [build workflow](https://github.com/doldecomp/melee/blob/master/.github/workflows/build.yml).
The local progress files are the reporting surface here; they do not imply
that a remote dashboard or CI service has been published.
