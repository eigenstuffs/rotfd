// Recovered engine allocation-and-construction factory fragment.
// Header strings identify registrations, not complete original translation units.
extern "C" {
extern char lbl_801EF5C8[];
void *fn_801EFA1C(void *, unsigned long, const char *, const char *, int, int);
extern const char lbl_802AE024[];
extern const char lbl_802AE10C[];
extern const char lbl_802AE120[];
extern const char lbl_802AE12C[];
extern const char lbl_802AE13C[];
void *fn_8002722C(void *);
void *__ct__9LodMove_ZFv(void *);
void *__ct__15Object_800272F0Fv(void *);
void *__ct__12ObjectsBreakFv(void *);

// VehiculeMove_Z.h:17; allocation size 0x318.
void *fn_80209910()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x318, lbl_802AE024,
                              lbl_802AE10C, 17, 4);
    if (object)
        object = fn_8002722C(object);
    return object;
}

// LodMove_Z.h:124; allocation size 0x318.
void *fn_80209968()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x318, lbl_802AE024,
                              lbl_802AE120, 124, 4);
    if (object)
        object = __ct__9LodMove_ZFv(object);
    return object;
}

// ObjectThrow_Z.h:116; allocation size 0x1F8.
void *fn_802099C0()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x1F8, lbl_802AE024,
                              lbl_802AE12C, 116, 4);
    if (object)
        object = __ct__15Object_800272F0Fv(object);
    return object;
}

// ObjectsBreak_Z.h:74; allocation size 0x1F0.
void *fn_80209A18()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x1F0, lbl_802AE024,
                              lbl_802AE13C, 74, 4);
    if (object)
        object = __ct__12ObjectsBreakFv(object);
    return object;
}
}
