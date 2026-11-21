# Animation-frame destructor at 801AC9B8

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The ordinary C entry fn_801AC9B8 now matches all1,540 original text bytes and47 actual relocations with GC1.3.2/Gekko/O4,p/exceptions off/lmw-stmw on. Explicit member cleanup uses real C++ destructors and concrete array element types. The virtual WorldActionCurve member call must be explicitly qualified to call its native destructor directly; unqualified cleanup emitted a virtual dispatch and12 extra bytes. The final production object has only the primary .text, no weak backups or other allocated sections.

AnimFrame member offsets agree with frozen constructor269: Handle20, eight16-byte curve objects28..98, and virtual WorldActionCurveA8. Curves28/38/48 hold20-byte records; curve58 holds16-byte records; curve68 holds28-byte records with a two-layer retained Handle at+4; curve78 holds16-byte rows containing an8-byte retained-record array at+4; curves88/98 hold16-byte records. Empty record destructors naturally emit the original unrolled induction loops. The nested records use real wrapped Handle destruction, preserving every original null check and loop register.

No original exception-index extent overlaps801AC9B8..801ACFBC; complete ctors/dtors tables contain no entry. All original dependency identities/data remain external. The sole data pointer to this destructor is lbl802E9D98+8 at802E9DA0, retained under the existing C identity; no source caller or identifier migration is required. Stable active-input audit covers5,622 objects,119,086 actual relocs and777,360 initialized DOL words. No aliases/overlapping function ownership or new nontext allocation.

Strict production comparison and fresh recompilation both pass all allocated sections, function extents and actual relocation targets. Root owns final native placement/full-DOL hash/regression/test acceptance. Constructor269 and every predecessor remain unchanged.

Evidence: scratch/game_anim_frame_destroy_801ac9b8/{final_integration.json,strict_report.json,ownership_audit.json,active-original-audit.json,fresh-verification/report.json}. Frozen batch270; central acceptance pending.
