// Reconstructed allocation, base construction and virtual-table installation.
// The opaque prefix records the verified vptr offset; full class layout is unresolved.
extern "C" {
struct FactoryObject { unsigned char prefix[8]; const void *vtable; };
extern char lbl_801EF5C8[];
void *fn_801EFA1C(void *, unsigned long, const char *, const char *, int, int);
extern const char lbl_802A0E78[];
extern const char lbl_802A0FA8[];
extern const char lbl_802B4924[];
extern const char lbl_802B49EC[];
void __ct__14Agent_80044118Fv(void *);

// VolumeAgents.h:199; allocation size 0x70.
FactoryObject *fn_800BA8EC()
{
    FactoryObject *object = (FactoryObject *)fn_801EFA1C(
        lbl_801EF5C8, 0x70, lbl_802A0E78, lbl_802A0FA8, 199, 4);
    if (object) {
        __ct__14Agent_80044118Fv(object);
        object->vtable = lbl_802B49EC;
    }
    return object;
}

// VolumeAgents.h:168; allocation size 0x78.
FactoryObject *fn_800BA954()
{
    FactoryObject *object = (FactoryObject *)fn_801EFA1C(
        lbl_801EF5C8, 0x78, lbl_802A0E78, lbl_802A0FA8, 168, 4);
    if (object) {
        __ct__14Agent_80044118Fv(object);
        object->vtable = lbl_802B4924;
    }
    return object;
}
}
