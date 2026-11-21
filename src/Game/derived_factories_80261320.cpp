// Reconstructed allocation, base construction and virtual-table installation.
// The opaque prefix records the verified vptr offset; full class layout is unresolved.
extern "C" {
struct FactoryObject { unsigned char prefix[8]; const void *vtable; };
extern char lbl_801EF5C8[];
void *fn_801EFA1C(void *, unsigned long, const char *, const char *, int, int);
extern const char lbl_802AEE28[];
extern const char lbl_802AEE4C[];
extern const char __vt__23ContainerLayer_80044168[];
void __ct__22ContainerBase_802563CCFv(void *);

// VolumeAgent_Z.h:9; allocation size 0x60.
FactoryObject *fn_80261320()
{
    FactoryObject *object = (FactoryObject *)fn_801EFA1C(
        lbl_801EF5C8, 0x60, lbl_802AEE28, lbl_802AEE4C, 9, 4);
    if (object) {
        __ct__22ContainerBase_802563CCFv(object);
        object->vtable = __vt__23ContainerLayer_80044168;
    }
    return object;
}
}
