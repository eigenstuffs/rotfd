// Reconstructed allocation, base construction and virtual-table installation.
// The opaque prefix records the verified vptr offset; full class layout is unresolved.
extern "C" {
struct FactoryObject { unsigned char prefix[8]; const void *vtable; };
extern char lbl_801EF5C8[];
void *fn_801EFA1C(void *, unsigned long, const char *, const char *, int, int);
extern const char lbl_802A0E78[];
extern const char lbl_802A103C[];
extern const char lbl_802BDB24[];
extern const char lbl_802BDBEC[];
extern const char lbl_802BDCB4[];
extern const char lbl_802BDD7C[];
void fn_800C5354(void *);

// BusTicketAgent.h:49; allocation size 0x98.
FactoryObject *fn_800BAC24()
{
    FactoryObject *object = (FactoryObject *)fn_801EFA1C(
        lbl_801EF5C8, 0x98, lbl_802A0E78, lbl_802A103C, 49, 4);
    if (object) {
        fn_800C5354(object);
        object->vtable = lbl_802BDD7C;
    }
    return object;
}

// BusTicketAgent.h:43; allocation size 0x98.
FactoryObject *fn_800BAC8C()
{
    FactoryObject *object = (FactoryObject *)fn_801EFA1C(
        lbl_801EF5C8, 0x98, lbl_802A0E78, lbl_802A103C, 43, 4);
    if (object) {
        fn_800C5354(object);
        object->vtable = lbl_802BDCB4;
    }
    return object;
}

// BusTicketAgent.h:37; allocation size 0x98.
FactoryObject *fn_800BACF4()
{
    FactoryObject *object = (FactoryObject *)fn_801EFA1C(
        lbl_801EF5C8, 0x98, lbl_802A0E78, lbl_802A103C, 37, 4);
    if (object) {
        fn_800C5354(object);
        object->vtable = lbl_802BDBEC;
    }
    return object;
}

// BusTicketAgent.h:31; allocation size 0x98.
FactoryObject *fn_800BAD5C()
{
    FactoryObject *object = (FactoryObject *)fn_801EFA1C(
        lbl_801EF5C8, 0x98, lbl_802A0E78, lbl_802A103C, 31, 4);
    if (object) {
        fn_800C5354(object);
        object->vtable = lbl_802BDB24;
    }
    return object;
}
}
