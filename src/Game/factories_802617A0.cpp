// Recovered engine allocation-and-construction factory fragment.
// Header strings identify registrations, not complete original translation units.
extern "C" {
extern char lbl_801EF5C8[];
void *fn_801EFA1C(void *, unsigned long, const char *, const char *, int, int);
extern const char lbl_802AEE28[];
extern const char lbl_802AEF18[];
void *__ct__22ContainerBase_802563CCFv(void *);

// Agent_Z.h:12; allocation size 0x60.
void *fn_802617A0()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x60, lbl_802AEE28,
                              lbl_802AEF18, 12, 4);
    if (object)
        object = __ct__22ContainerBase_802563CCFv(object);
    return object;
}
}
