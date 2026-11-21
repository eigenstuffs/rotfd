# Twenty-three medium native neighbor record groups

Twenty-three existing matching `native_rtti_base_lists_*.cpp` sources now own
their immediately following method and runtime-base records. The added ranges
begin at `0x802B8184`, `0x802B84BC`, `0x802B8514`, `0x802B9B28`,
`0x802BA288`, `0x802BA650`, `0x802BB25C`, `0x802BB2B4`, `0x802BD4D4`,
`0x802BF6B0`, `0x802BF758`, `0x802BF7DC`, `0x802C9294`, `0x802C92EC`,
`0x802C9344`, `0x802C939C`, `0x802C93F4`, `0x802C944C`, `0x802C94A4`,
`0x802C94FC`, `0x802C959C`, `0x802C960C`, and `0x802C9664`.

The source describes the observed pointer slots, null entries, and zero
adjustments without claiming complete class declarations. Isolated GC/1.3.2
compiles match every enlarged `.data` byte and original new-symbol extent,
and preserve the existing symbol sets. All 23 native objdiff reports show
100% `.data` matches with 367 matching relocations across the enlarged units.
Private probes and reports are in `scratch/native_neighbor_medium_20261020/`.

The integration adds 1,600 verified data bytes. The standard build retains
the expected full-DOL SHA1; `ninja changes`, the generated progress check,
and all 66 tests pass. Referenced methods and runtime type descriptors retain
their existing owners, and these remain partial original translation units.
The unknown-unit denominator is preserved.
