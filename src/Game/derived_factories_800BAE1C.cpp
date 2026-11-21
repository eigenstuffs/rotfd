// Reconstructed allocation, base construction and virtual-table installation.
// The opaque prefix records the verified vptr offset; full class layout is unresolved.
extern "C" {
struct FactoryObject { unsigned char prefix[8]; const void *vtable; };
extern char lbl_801EF5C8[];
void *fn_801EFA1C(void *, unsigned long, const char *, const char *, int, int);
extern const char lbl_802A0E78[];
extern const char lbl_802A1050[];
extern const char lbl_802B0A18[];
extern const char lbl_802B0AE0[];
extern const char lbl_802B0BA8[];
extern const char lbl_802B0C70[];
extern const char lbl_802B0D38[];
extern const char lbl_802B0E00[];
extern const char lbl_802B0EC8[];
extern const char lbl_802B0F90[];
extern const char lbl_802B1058[];
void fn_80028184(void *);

// LetterTileBaseAgent.h:232; allocation size 0x98.
FactoryObject *fn_800BAE1C()
{
    FactoryObject *object = (FactoryObject *)fn_801EFA1C(
        lbl_801EF5C8, 0x98, lbl_802A0E78, lbl_802A1050, 232, 4);
    if (object) {
        fn_80028184(object);
        object->vtable = lbl_802B0A18;
    }
    return object;
}

// LetterTileBaseAgent.h:213; allocation size 0x98.
FactoryObject *fn_800BAE84()
{
    FactoryObject *object = (FactoryObject *)fn_801EFA1C(
        lbl_801EF5C8, 0x98, lbl_802A0E78, lbl_802A1050, 213, 4);
    if (object) {
        fn_80028184(object);
        object->vtable = lbl_802B0AE0;
    }
    return object;
}

// LetterTileBaseAgent.h:194; allocation size 0x98.
FactoryObject *fn_800BAEEC()
{
    FactoryObject *object = (FactoryObject *)fn_801EFA1C(
        lbl_801EF5C8, 0x98, lbl_802A0E78, lbl_802A1050, 194, 4);
    if (object) {
        fn_80028184(object);
        object->vtable = lbl_802B0BA8;
    }
    return object;
}

// LetterTileBaseAgent.h:175; allocation size 0x98.
FactoryObject *fn_800BAF54()
{
    FactoryObject *object = (FactoryObject *)fn_801EFA1C(
        lbl_801EF5C8, 0x98, lbl_802A0E78, lbl_802A1050, 175, 4);
    if (object) {
        fn_80028184(object);
        object->vtable = lbl_802B0C70;
    }
    return object;
}

// LetterTileBaseAgent.h:156; allocation size 0x98.
FactoryObject *fn_800BAFBC()
{
    FactoryObject *object = (FactoryObject *)fn_801EFA1C(
        lbl_801EF5C8, 0x98, lbl_802A0E78, lbl_802A1050, 156, 4);
    if (object) {
        fn_80028184(object);
        object->vtable = lbl_802B0D38;
    }
    return object;
}

// LetterTileBaseAgent.h:137; allocation size 0x98.
FactoryObject *fn_800BB024()
{
    FactoryObject *object = (FactoryObject *)fn_801EFA1C(
        lbl_801EF5C8, 0x98, lbl_802A0E78, lbl_802A1050, 137, 4);
    if (object) {
        fn_80028184(object);
        object->vtable = lbl_802B0E00;
    }
    return object;
}

// LetterTileBaseAgent.h:118; allocation size 0x98.
FactoryObject *fn_800BB08C()
{
    FactoryObject *object = (FactoryObject *)fn_801EFA1C(
        lbl_801EF5C8, 0x98, lbl_802A0E78, lbl_802A1050, 118, 4);
    if (object) {
        fn_80028184(object);
        object->vtable = lbl_802B0EC8;
    }
    return object;
}

// LetterTileBaseAgent.h:99; allocation size 0x98.
FactoryObject *fn_800BB0F4()
{
    FactoryObject *object = (FactoryObject *)fn_801EFA1C(
        lbl_801EF5C8, 0x98, lbl_802A0E78, lbl_802A1050, 99, 4);
    if (object) {
        fn_80028184(object);
        object->vtable = lbl_802B0F90;
    }
    return object;
}

// LetterTileBaseAgent.h:80; allocation size 0x98.
FactoryObject *fn_800BB15C()
{
    FactoryObject *object = (FactoryObject *)fn_801EFA1C(
        lbl_801EF5C8, 0x98, lbl_802A0E78, lbl_802A1050, 80, 4);
    if (object) {
        fn_80028184(object);
        object->vtable = lbl_802B1058;
    }
    return object;
}
}
