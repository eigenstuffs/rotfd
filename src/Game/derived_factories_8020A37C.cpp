// Reconstructed allocation, base construction and virtual-table installation.
// The opaque prefix records the verified vptr offset; full class layout is unresolved.
extern "C" {
struct FactoryObject { unsigned char prefix[8]; const void *vtable; };
extern char lbl_801EF5C8[];
void *fn_801EFA1C(void *, unsigned long, const char *, const char *, int, int);
extern const char lbl_802AE024[];
extern const char lbl_802AE19C[];
extern const char lbl_802EB000[];
void __ct__13Manipulator_ZFv(void *);

// CameraUser_Z.h:18; allocation size 0x30.
FactoryObject *fn_8020A37C()
{
    FactoryObject *object = (FactoryObject *)fn_801EFA1C(
        lbl_801EF5C8, 0x30, lbl_802AE024, lbl_802AE19C, 18, 4);
    if (object) {
        __ct__13Manipulator_ZFv(object);
        object->vtable = lbl_802EB000;
    }
    return object;
}
}
