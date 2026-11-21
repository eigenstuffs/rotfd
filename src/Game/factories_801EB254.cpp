// Recovered engine allocation-and-construction factory fragment.
// Header strings identify registrations, not complete original translation units.
extern "C" {
extern char lbl_801EF5C8[];
void *fn_801EFA1C(void *, unsigned long, const char *, const char *, int, int);
extern const char lbl_802ACF20[];
extern const char lbl_802AD060[];
extern const char lbl_802AD074[];
extern const char lbl_802AD080[];
extern const char lbl_802AD090[];
void *fn_801F04DC(void *);
void *fn_80252B54(void *);
void *fn_8026E8D4(void *);
void *fn_80271B04(void *);

// InGameObjectsGC_Z.h:21; allocation size 0x64.
void *fn_801EB254()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x64, lbl_802ACF20,
                              lbl_802AD060, 21, 4);
    if (object)
        object = fn_801F04DC(object);
    return object;
}

// WarpGC_Z.h:34; allocation size 0xF4.
void *fn_801EB2AC()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0xF4, lbl_802ACF20,
                              lbl_802AD074, 34, 4);
    if (object)
        object = fn_80271B04(object);
    return object;
}

// ParticlesGC_Z.h:22; allocation size 0x38.
void *fn_801EB304()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x38, lbl_802ACF20,
                              lbl_802AD080, 22, 4);
    if (object)
        object = fn_8026E8D4(object);
    return object;
}

// Particles_Z.h:109; allocation size 0x18C.
void *fn_801EB35C()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x18C, lbl_802ACF20,
                              lbl_802AD090, 109, 4);
    if (object)
        object = fn_80252B54(object);
    return object;
}
}
