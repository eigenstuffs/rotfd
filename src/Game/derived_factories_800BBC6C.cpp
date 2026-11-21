// Reconstructed allocation, base construction and virtual-table installation.
// The opaque prefix records the verified vptr offset; full class layout is unresolved.
extern "C" {
struct FactoryObject { unsigned char prefix[8]; const void *vtable; };
extern char lbl_801EF5C8[];
void *fn_801EFA1C(void *, unsigned long, const char *, const char *, int, int);
extern const char lbl_802A0E78[];
extern const char lbl_802A119C[];
extern const char lbl_802B308C[];
extern const char lbl_802B3298[];
extern const char lbl_802B33C8[];
extern const char lbl_802B34F8[];
extern const char lbl_802B3628[];
void fn_80040064(void *);

// SpongeBobAgent.h:147; allocation size 0xA0.
FactoryObject *fn_800BBC6C()
{
    FactoryObject *object = (FactoryObject *)fn_801EFA1C(
        lbl_801EF5C8, 0xA0, lbl_802A0E78, lbl_802A119C, 147, 4);
    if (object) {
        fn_80040064(object);
        object->vtable = lbl_802B3298;
    }
    return object;
}

// SpongeBobAgent.h:138; allocation size 0xA0.
FactoryObject *fn_800BBCD4()
{
    FactoryObject *object = (FactoryObject *)fn_801EFA1C(
        lbl_801EF5C8, 0xA0, lbl_802A0E78, lbl_802A119C, 138, 4);
    if (object) {
        fn_80040064(object);
        object->vtable = lbl_802B308C;
    }
    return object;
}

// SpongeBobAgent.h:131; allocation size 0xA0.
FactoryObject *fn_800BBD3C()
{
    FactoryObject *object = (FactoryObject *)fn_801EFA1C(
        lbl_801EF5C8, 0xA0, lbl_802A0E78, lbl_802A119C, 131, 4);
    if (object) {
        fn_80040064(object);
        object->vtable = lbl_802B33C8;
    }
    return object;
}

// SpongeBobAgent.h:124; allocation size 0xA0.
FactoryObject *fn_800BBDA4()
{
    FactoryObject *object = (FactoryObject *)fn_801EFA1C(
        lbl_801EF5C8, 0xA0, lbl_802A0E78, lbl_802A119C, 124, 4);
    if (object) {
        fn_80040064(object);
        object->vtable = lbl_802B34F8;
    }
    return object;
}

// SpongeBobAgent.h:117; allocation size 0xA0.
FactoryObject *fn_800BBE0C()
{
    FactoryObject *object = (FactoryObject *)fn_801EFA1C(
        lbl_801EF5C8, 0xA0, lbl_802A0E78, lbl_802A119C, 117, 4);
    if (object) {
        fn_80040064(object);
        object->vtable = lbl_802B3628;
    }
    return object;
}
}
