// Reconstructed allocation, base construction and virtual-table installation.
// The opaque prefix records the verified vptr offset; full class layout is unresolved.
extern "C" {
struct FactoryObject { unsigned char prefix[8]; const void *vtable; };
extern char lbl_801EF5C8[];
void *fn_801EFA1C(void *, unsigned long, const char *, const char *, int, int);
extern const char lbl_802A0E78[];
extern const char lbl_802A0EE4[];
extern const char lbl_802AFDF4[];
extern const char lbl_802AFEE0[];
extern const char lbl_802AFFCC[];
extern const char lbl_802B00B8[];
extern const char lbl_802B01A4[];
extern const char lbl_802B0290[];
void __ct__14Agent_80021260Fv(void *);

// Game_Breakable_Agents.h:120; allocation size 0xC0.
FactoryObject *fn_800B96C4()
{
    FactoryObject *object = (FactoryObject *)fn_801EFA1C(
        lbl_801EF5C8, 0xC0, lbl_802A0E78, lbl_802A0EE4, 120, 4);
    if (object) {
        __ct__14Agent_80021260Fv(object);
        object->vtable = lbl_802AFDF4;
    }
    return object;
}

// Game_Breakable_Agents.h:110; allocation size 0xC0.
FactoryObject *fn_800B972C()
{
    FactoryObject *object = (FactoryObject *)fn_801EFA1C(
        lbl_801EF5C8, 0xC0, lbl_802A0E78, lbl_802A0EE4, 110, 4);
    if (object) {
        __ct__14Agent_80021260Fv(object);
        object->vtable = lbl_802AFEE0;
    }
    return object;
}

// Game_Breakable_Agents.h:100; allocation size 0xC0.
FactoryObject *fn_800B9794()
{
    FactoryObject *object = (FactoryObject *)fn_801EFA1C(
        lbl_801EF5C8, 0xC0, lbl_802A0E78, lbl_802A0EE4, 100, 4);
    if (object) {
        __ct__14Agent_80021260Fv(object);
        object->vtable = lbl_802AFFCC;
    }
    return object;
}

// Game_Breakable_Agents.h:90; allocation size 0xC0.
FactoryObject *fn_800B97FC()
{
    FactoryObject *object = (FactoryObject *)fn_801EFA1C(
        lbl_801EF5C8, 0xC0, lbl_802A0E78, lbl_802A0EE4, 90, 4);
    if (object) {
        __ct__14Agent_80021260Fv(object);
        object->vtable = lbl_802B00B8;
    }
    return object;
}

// Game_Breakable_Agents.h:80; allocation size 0xC0.
FactoryObject *fn_800B9864()
{
    FactoryObject *object = (FactoryObject *)fn_801EFA1C(
        lbl_801EF5C8, 0xC0, lbl_802A0E78, lbl_802A0EE4, 80, 4);
    if (object) {
        __ct__14Agent_80021260Fv(object);
        object->vtable = lbl_802B01A4;
    }
    return object;
}

// Game_Breakable_Agents.h:70; allocation size 0xC0.
FactoryObject *fn_800B98CC()
{
    FactoryObject *object = (FactoryObject *)fn_801EFA1C(
        lbl_801EF5C8, 0xC0, lbl_802A0E78, lbl_802A0EE4, 70, 4);
    if (object) {
        __ct__14Agent_80021260Fv(object);
        object->vtable = lbl_802B0290;
    }
    return object;
}
}
