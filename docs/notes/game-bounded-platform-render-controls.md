# Platform record release and render cache zero

Two independently owned original C entries have isolated ordinary-source matches:

| Entry | Extent | Operation |
| --- | --- | --- |
| fn_8028BFA4 | 8028BFA4..8028BFC8, 36 bytes | Release the record's handle at offset 0x3C through fn_801F6AF8. |
| fn_80280158 | 80280158..80280174, 28 bytes | Zero consecutive 32-byte cache lines for a position buffer with three floats per element. |

The cache loop intentionally executes once before testing the remaining count and processes a whole final cache line. The source uses the compiler's ordinary `__dcbz(void*, int)` builtin. GC1.3.2 with `-opt nopeephole -schedule off` preserves the original separate decrement, pointer advance and comparison. The normal optimizer merges the decrement and comparison, producing 24 bytes; disabling only peephole optimization leaves two scheduling words different. Those failed probes remain preserved.

The record wrapper uses the normal GC1.3.2 -O4,p configuration. Both complete objects allocate only their exact text section, with one real relocation in total and no data, BSS, weak helpers or retained exception metadata. Complete original exception-index, constructor and destructor tables contain no references to either retained range.

These are partial text-only recoveries. Neighboring matrix/renderer and collision-dispatcher functions, data and literal pools remain outside ownership. The independent 52-byte global initializer at 80269A30 has a separate startup/BSS investigation and is not included here. Existing callers and declarations remain unchanged.

Frozen handoff: `scratch/engine_bounded_controls_20261011jo/final_integration.json`; `verify.py` repeats whole-object, actual-relocation, complete table and frozen-file checks. Production integration and the original DOL hash check remain with the root integrator.
