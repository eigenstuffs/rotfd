# Record array owner destruction

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_801CFE40` reconstructs `801CFE40..801D020C` as972 bytes of ordinary C++ source. It destroys the wrapped Handle array atB0 and five trivial element arrays, restores the two original virtual tables, invokes the existing base destructor, and conditionally releases the owner. Array elements have widths12,4,4,12,8 and4 bytes; empty destructors preserve the original counted cleanup loops. Two genuine empty derived Handle layers generate both original nested null checks before the external Handle destructor.

GC1.3.2 Gekko O4,p with C++ exceptions disabled matches every emitted allocated byte and all27 actual relocation targets. The source emits only its972-byte primary text, with no helper, metadata, literal, data, BSS or padding allocations. The initial one-layer Handle probe was eight bytes short; the second derived layer closes it without instruction or register control.

The full original exception/startup table audit finds no owned entry. The active object/real relocation census and all777360 initialized DOL words were scanned; instruction words are distinguished from initialized data pointers. The sole data pointer802EA500 remains in external original table `lbl_802EA4F8` (802EA4F8..802EA558,96 bytes). Both original virtual tables, existing Handle/base destructors and allocator objects remain external. Existing source consumer `src/Game/byte_buffer_destroy.cpp` retains the C entry spelling and ABI unchanged.

The frozen candidate, production compiler proof, ownership audit, active object snapshot, proposed split/configuration and independent verifier are in `scratch/game_record_arrays_owner_destroy_801cfe40`. Root integration, full native placement, original DOL hash and regression acceptance remain pending.
