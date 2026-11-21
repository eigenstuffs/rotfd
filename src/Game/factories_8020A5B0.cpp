// Recovered engine allocation-and-construction factory fragment.
// Header strings identify registrations, not complete original translation units.
extern "C" {
extern char lbl_801EF5C8[];
void *fn_801EFA1C(void *, unsigned long, const char *, const char *, int, int);
extern const char lbl_802AE024[];
extern const char lbl_802AE1FC[];
void *fn_8023576C(void *);

// PlayAnim_Z.h:124; allocation size 0x200.
void *fn_8020A5B0()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x200, lbl_802AE024,
                              lbl_802AE1FC, 124, 4);
    if (object)
        object = fn_8023576C(object);
    return object;
}
}
