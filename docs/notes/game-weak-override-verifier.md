# Standalone strong-over-weak destructor verifier proposal

This is a bounded verifier investigation, not a production source promotion.
Root owns the three destructor sources and central integration. No shared
verifier, symbols, splits, configure settings, or generated progress were edited.

Ordinary inline C++ temporary destruction emits weak backup native destructors
and their exception/index records. Retained exception records really reference
these *defined weak* symbols. The original native destructor is already provided
by an accepted strong source object. CodeWarrior's native linker selects that
strong function, resolves the retained EH pointer to it, and discards each weak
backup body and its own EH/index pair. Treating every defined ELF symbol as local
is incorrect in this specific, explicitly proved case.

| Fixture | Retained text | Retained EH/index | Retained relocs | Uncredited backup text | Uncredited backup EH/index | Backup relocs | Retained weak pointers |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| 8004ACA4 | 680 | 100 | 43 | 304 | 124 | 18 | 3 |
| 8004FB54 | 424 | 88 | 31 | 112 | 52 | 7 | 1 |
| 8002D0F8 | 512 | 176 | 39 | 112 | 52 | 7 | 4 |

All 1,616 retained code bytes and 364 retained exception/index bytes match the
original DOL after applying actual relocations. None of the 528 backup code or
228 backup metadata bytes earns credit. Every allocated input byte belongs to
an exact symbol extent with a raw SHA-256. Extabindex relationships are derived
from actual ELF symbol references rather than repeated compiler-local names.
Full original extabindex/ctors/dtors scans found precisely the expected exception
ownership and no constructor/destructor-table pointers for these three bodies.

The strong owners are accepted `Handle_8002B67C`, `Handle_80020B90`, and
`Handle_80020478` destructors. Each canonical manifest, source, recursive quoted
header, production object, and freshly recompiled object has a recorded digest.
Each owner is STB_GLOBAL/STT_FUNC at its original address and exact size; its
complete original text and exception records independently verify. The freshly
compiled object is byte-identical to its accepted production object.

## Standalone interface

Files live in `scratch/game_weak_override_verifier_continuation`.
`weak_override.inspect_object(obj, retained, primary, strong, original, external)`
accepts explicit original section `(address, size)` pairs, the primary native
symbol, and a map of **independently proved** strong owners. The caller must
perform the canonical/source/production-object proof first; an arbitrary address
map is not authorization. `verify_cases.strong_proof` implements that gate for
the three accepted owners. `inspect_object` returns all emitted symbol extents,
raw hashes, actual relocations, overridden retained pointers, exception groups,
and retained/uncredited byte totals. `verify_frozen_object` requires the exact
frozen inventory and whole input object hash.

The opt-in scope is intentionally bounded: exactly `.text`, `extab`, and
`extabindex`; one strong retained primary at input text offset zero; all retained
sections start at input offset zero; contiguous trailing weak function backups
with local exception/index objects; every emitted function has precisely one
real exception index and one compiler category record. Only zero-addend absolute
function pointers from retained EH may use the approved strong override.
Retained references to any other backup are rejected. Retained local relocation
targets plus addends must remain inside the retained section. Index pointers
must reference the exact STT_FUNC in `.text` and STT_OBJECT in `extab`, with zero
addends, and the stored function size must match. Unsupported allocated sections,
bindings, gaps, overlaps, relocation kinds, and changed raw backup bytes fail.

Each `<address>/proposal.json` is a frozen standalone proof. The generated
`<address>/manifest_extension.json` shows corresponding optional integration
fields: `weak_overrides`, `unlinked_functions`, `unlinked_objects`,
`unlinked_exception_groups`, full `emitted_sections`, and relocation totals.
The extension is a proposal for root to review, not a central manifest change.
Root's production copies have different filenames and therefore different ELF
file/debug metadata; root must freeze its freshly compiled production objects
with the same strict inventory, rather than copy a private whole-object digest.

## Actual native link proof

`link_cases.py` links each real fixture object and its recompiled accepted strong
owners with GC 1.3.2 `mwldeppc.exe`. It also uses the existing real startup,
runtime-initializer, exit, and original small-BSS objects. Other external symbols
are linker address definitions. The small-BSS object is required for native
SDA21 section typing; absolute aliases cannot stand in for these variables.
These private probes use independent LCF/ELF/map files and do not rebuild or
change the standard target.

All three native links succeed. The native maps explicitly mark all 15 backup
allocations unused or unreferenced weak duplicates. Linked ELF file-scoped
local symbol inventories contain only the original retained fixture metadata;
backup EH/index symbols are absent. The final functions are single strong
GLOBAL definitions selected from the intended accepted owner objects. The
entire retained EH/index payload is reconstructed using native linked addresses
and compared byte-for-byte, including all eight overridden function pointers.
Input object hashes, linker hash, command, LCF hash, native ELF/map hashes, and
per-allocation discard results are recorded in `<address>/native_proof.json`.

These links prove native selection and discard semantics at private placements.
Central acceptance must still verify original placements, selected strong
owners, each fixture's full backup text/EH/index discard, source extents, match
regressions, and the unchanged original DOL hash. For an overridden name, final
absence means the weak definition is absent while the original strong definition
remains; deleting the name entirely would be incorrect.

## Repeatable checks

From the repository root:

```
python3 scratch/game_weak_override_verifier_continuation/verify_cases.py
python3 scratch/game_weak_override_verifier_continuation/link_cases.py
python3 scratch/game_weak_override_verifier_continuation/test_rejections.py
```

The 13 negative cases reject missing/wrong strong owner authorization, a retained
reference to an unproved backup, a local target addend escaping retained bytes,
section symbols substituted for real index targets, changed backup code, a
nonweak backup, extra allocated output, missing native discard evidence, changed
linked retained EH pointers, and a final owner whose binding is weak.

The initial single-case scripts and native link attempts remain preserved.
Early private link attempts lacked real runtime inputs or gave small-data
variables absolute aliases; those failures did not alter production and are
not acceptance evidence. Only the three successful case directories and their
automated proofs support the proposal. `handoff.json` records the frozen files
and their hashes.
