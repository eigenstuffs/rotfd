# Fifty-three small native neighbor record groups

Fifty-three existing matching `native_rtti_base_lists_*.cpp` sources now own
their immediately following small native records. The added ranges are 24 to
32 bytes each and total 1,492 data bytes. Their exact addresses and preceding
source owners are recorded in
`scratch/native_neighbor_small_20261020/prepare.py` and the versioned
`config/GSQE78/splits.txt`.

The source expresses the observed pointer slots, null entries, and zero
runtime-base adjustments as bounded ABI views. Isolated GC/1.3.2 compiles
reproduce every enlarged `.data` byte and every new original symbol extent,
while preserving the old symbol sets. All 53 native objdiff reports show
100% `.data` matches and 466 matching relocations across the enlarged units.
Private probes and reports are retained in
`scratch/native_neighbor_small_20261020/`.

The standard build retains the expected full-DOL SHA1. `ninja changes`, the
generated progress check, and all 66 tests pass. Referenced methods and
runtime type descriptors retain their existing owners; the surrounding
functions and data of each original translation unit remain outside these
partial source splits. The original unknown-unit denominator is preserved.
