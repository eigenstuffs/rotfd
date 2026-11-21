// Reconstructed allocation, base construction and virtual-table installation.
// The opaque prefix records the verified vptr offset; full class layout is unresolved.
extern "C" {
struct FactoryObject { unsigned char prefix[8]; const void *vtable; };
extern char lbl_801EF5C8[];
void *fn_801EFA1C(void *, unsigned long, const char *, const char *, int, int);
extern const char lbl_802AE024[];
extern const char lbl_802AE1C0[];
extern const char lbl_802EBD20[];
void __ct__19QueueArray_802EBD60Fv(void *);

// SequenceAnim_Z.h:15; allocation size 0x60.
FactoryObject *fn_8020A43C()
{
    FactoryObject *object = (FactoryObject *)fn_801EFA1C(
        lbl_801EF5C8, 0x60, lbl_802AE024, lbl_802AE1C0, 15, 4);
    if (object) {
        __ct__19QueueArray_802EBD60Fv(object);
        object->vtable = lbl_802EBD20;
    }
    return object;
}
}
