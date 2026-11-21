# Thirteen-curve owner destructor at 801DBAF8

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

fn_801DBAF8 at801DBAF8..801DC3A0 is exact on the first ordinary source probe:2,216 text bytes/59 actual relocations, GC1.3.2/Gekko/O4,p/exceptionsoff/lmw-stmw on. Its production object allocates only the primary .text; no helpers, data, BSS, EH/index, startup or padding are emitted.

The owner has an existing table at+8, thirteen16-byte curve members atB8..178 and a two-layer retained Handle at188. Curves108 and158 contain16-byte records; the other eleven curves contain8-byte records. Each genuine array destructor loops over typed empty element destructors, frees capacity*sizeof(record), and clears its pointer. CodeWarrior naturally emits the original unrolled induction loops. Curve destruction then calls existing native CurveBase_801B1088 cleanup. The final base cleanup remains fn80243E90(self,0); signed-short positive deletion invokes the original arena free. All borrowed native identities and tables are unchanged.

Strict production comparison and independent fresh recompilation match every allocation, function extent and actual relocation. Full original exception-index scan80015F60..8001F2C0 and complete ctors/dtors tables show no owned record. Stable5,625 active objects/119,086 actual relocations/777,360 initialized DOL words show a sole original GLOBAL2216 definition and only the existing vtable pointer lbl802EA6C0+8. The pointer-containing data remains external under its original global identity. No aliases, overlap or compiled source/header consumers; no migration/new gate is needed. Root owns final full-DOL/native/hash/regression/test acceptance.

Frozen batch271; isolated exact proof in scratch/game_curve_owner_destroy_801dbaf8. Central acceptance pending.
