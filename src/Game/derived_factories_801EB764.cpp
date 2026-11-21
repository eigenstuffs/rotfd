// Reconstructed allocation, base construction and virtual-table installation.
// The opaque prefix records the verified vptr offset; full class layout is unresolved.
extern "C" {
struct FactoryObject { unsigned char prefix[8]; const void *vtable; };
extern char lbl_801EF5C8[];
void *fn_801EFA1C(void *, unsigned long, const char *, const char *, int, int);
extern const char lbl_802ACF20[];
extern const char lbl_802AD0CC[];
extern const char lbl_802ED1C4[];
void fn_80247458(void *);

// LodGC_Z.h:16; allocation size 0xCC.
FactoryObject *fn_801EB764()
{
    FactoryObject *object = (FactoryObject *)fn_801EFA1C(
        lbl_801EF5C8, 0xCC, lbl_802ACF20, lbl_802AD0CC, 16, 4);
    if (object) {
        fn_80247458(object);
        object->vtable = lbl_802ED1C4;
    }
    return object;
}
}
