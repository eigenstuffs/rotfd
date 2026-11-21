// Recovered engine allocation-and-construction factory fragment.
// Header strings identify registrations, not complete original translation units.
extern "C" {
extern char lbl_801EF5C8[];
void *fn_801EFA1C(void *, unsigned long, const char *, const char *, int, int);
extern const char lbl_802AEE28[];
extern const char lbl_802AEE38[];
void *__ct__23ContainerLayer_802EC6A0Fv(void *);

// ParticlesAgent_Z.h:10; allocation size 0x70.
void *fn_802612C8()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x70, lbl_802AEE28,
                              lbl_802AEE38, 10, 4);
    if (object)
        object = __ct__23ContainerLayer_802EC6A0Fv(object);
    return object;
}
}
