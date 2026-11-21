// Reconstructed allocation, base construction and virtual-table installation.
// The opaque prefix records the verified vptr offset; full class layout is unresolved.
extern "C" {
struct FactoryObject { unsigned char prefix[8]; const void *vtable; };
extern char lbl_801EF5C8[];
void *fn_801EFA1C(void *, unsigned long, const char *, const char *, int, int);
extern const char lbl_802A0E78[];
extern const char lbl_802A0EC0[];
extern const char lbl_802A0ED0[];
extern const char lbl_802BFA00[];
extern const char lbl_802C1DC4[];
void __ct__14Agent_8002B5F4Fv(void *);
void __ct__23ContainerLayer_802EC6A0Fv(void *);

// DamageAgent.h:36; allocation size 0x90.
FactoryObject *fn_800B94C8()
{
    FactoryObject *object = (FactoryObject *)fn_801EFA1C(
        lbl_801EF5C8, 0x90, lbl_802A0E78, lbl_802A0EC0, 36, 4);
    if (object) {
        __ct__14Agent_8002B5F4Fv(object);
        object->vtable = lbl_802C1DC4;
    }
    return object;
}

// ParticlesAlwaysOn.h:10; allocation size 0x70.
FactoryObject *fn_800B9530()
{
    FactoryObject *object = (FactoryObject *)fn_801EFA1C(
        lbl_801EF5C8, 0x70, lbl_802A0E78, lbl_802A0ED0, 10, 4);
    if (object) {
        __ct__23ContainerLayer_802EC6A0Fv(object);
        object->vtable = lbl_802BFA00;
    }
    return object;
}
}
