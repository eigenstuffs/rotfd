# Late scalar and record continuation

This preserved handoff contains **38 source fragments, 48 complete original
functions, 2,304 text bytes, and four constructor-table bytes**. The canonical
manifest is `config/GSQE78/candidates/game-scalar-late.json`; its 38 units and
original production sources remain unchanged. The frozen handoff is restored in
`scratch/game_scalar_late_continuation/final_integration.json`, accompanied by
`final_splits.txt`, `final_config.txt`, and `ownership_audit.json`.

The recovered ordinary C routines cover validated signed 24-bit index / signed
8-bit generation handles, selected-record and bounded-array queries, ordered
vector copying, optional outputs, scalar state and flags, queue and record-slot
appends, record iteration, and double-buffer swapping. Physically adjacent
functions with identical flags share a fragment where their combined source
matches exactly. Original entry names and data references are retained.

## Verification and ownership

`python3 scratch/game_scalar_late_continuation/verify.py` recompiles all 38
current production sources with GC/1.3.2. It checks every allocated section,
function binding, offset and size, and all **27 real relocations**. SDA21,
ADDR16_LO, ADDR16_HA, REL24, and the constructor-table absolute reference are
resolved to their versioned targets before every text and owned data byte is
compared with the normalized original DOL. No relocation bits are masked.
The restored verifier currently passes **38 units, 48 functions, 2,304 text
bytes, and four data bytes**.

`fn_801E1AA8` owns its original four-byte `.ctors` entry at
`80299944..80299948`, preserving the reference to the original startup function.
The source fragments claim no additional tables, exception data, or neighboring
functions. Their original external data references retain their existing owners.
The restored ownership audit checks all 48 complete original function extents;
these matching build fragments need not be complete original translation units.

## Research artifact restoration

A later agent accidentally reused this scratch directory and overwrote the
original generator, verifier, intermediate candidate/failure lists, frozen
handoff files, ownership audit, and this note. The later tranche has been moved
to `scratch/game_record_setup_late_continuation` with distinct production names.
The canonical config candidate manifest, all original production sources, the
original probe sources/disassembly, and the retry artifacts were preserved.

The manifest and handoff files have been restored from the unchanged canonical
manifest. The verifier has been restored from the author's equivalent strict
middle-continuation verifier and rerun successfully. This note and the ownership
audit have been reconstructed from the canonical manifest, surviving assembly,
and the author's summary. The original generator text could not be recovered;
`recover.py` is explicitly labeled as a reconstructed helper that loads the
surviving original probes and supports the surviving retry scripts. Intermediate
candidate and failure lists have also been reconstructed and do not claim to be
the original lists. Preserved failed probes receive no matching-source credit.
