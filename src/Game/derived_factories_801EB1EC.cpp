// Reconstructed allocation, base construction and virtual-table installation.
// The opaque prefix records the verified vptr offset; full class layout is unresolved.
extern "C" {
struct FactoryObject { unsigned char prefix[8]; const void *vtable; };
extern char lbl_801EF5C8[];
void *fn_801EFA1C(void *, unsigned long, const char *, const char *, int, int);
extern const char lbl_802ACF20[];
extern const char lbl_802AD054[];
extern const char lbl_802EDCA8[];
void fn_801C9CC8(void *);

// GCSound_Z.h:11; allocation size 0x24.
FactoryObject *fn_801EB1EC()
{
    FactoryObject *object = (FactoryObject *)fn_801EFA1C(
        lbl_801EF5C8, 0x24, lbl_802ACF20, lbl_802AD054, 11, 4);
    if (object) {
        fn_801C9CC8(object);
        object->vtable = lbl_802EDCA8;
    }
    return object;
}
}
