// CurveRecordBase_802E9E08's inherited virtual reset hook has no observed state
// transition. The unit also owns the class's vtable and the following 12-byte
// table that reuses the same reset slot (installed by the record constructors
// at 801B2AC8 and 801B3288). MWCC emits implicit vtables after all explicit
// data, so both tables are spelled out to keep their original order.
extern "C" {
void reset__24CurveRecordBase_802E9E08Fv() {}

extern __declspec(section ".data") const void* const __vt__24CurveRecordBase_802E9E08[3] = {
    0,
    0,
    (const void*)reset__24CurveRecordBase_802E9E08Fv,
};

extern __declspec(section ".data") const void* const lbl_802E9E14[3] = {
    0,
    0,
    (const void*)reset__24CurveRecordBase_802E9E08Fv,
};
}
