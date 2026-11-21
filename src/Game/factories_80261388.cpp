// Recovered engine allocation-and-construction factory fragment.
// Header strings identify registrations, not complete original translation units.
extern "C" {
extern char lbl_801EF5C8[];
void *fn_801EFA1C(void *, unsigned long, const char *, const char *, int, int);
extern const char lbl_802AEE28[];
extern const char lbl_802AEE5C[];
extern const char lbl_802AEE6C[];
extern const char lbl_802AEE7C[];
extern const char lbl_802AEE8C[];
extern const char lbl_802AEE9C[];
extern const char lbl_802AEEAC[];
extern const char lbl_802AEEBC[];
extern const char lbl_802AEECC[];
extern const char lbl_802AEEDC[];
void *__ct__21CallbackPair_802EC798Fv(void *);
void *__ct__18Breakable_802EC810Fv(void *);
void *__ct__17LodAgent_802EC8A8Fv(void *);
void *__ct__24LodDynamicAgent_802EC958Fv(void *);
void *__ct__23CallbackSingle_802ECA18Fv(void *);
void *__ct__18SkinAgent_802ECAF8Fv(void *);
void *__ct__24CallbackControl_802ECC00Fv(void *);
void *__ct__21CallbackFlag_802ECD68Fv(void *);
void *__ct__22CallbackClock_802ECEC0Fv(void *);

// RtcAgent_Z.h:12; allocation size 0x70.
void *fn_80261388()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x70, lbl_802AEE28,
                              lbl_802AEE5C, 12, 4);
    if (object)
        object = __ct__22CallbackClock_802ECEC0Fv(object);
    return object;
}

// CameraAgent_Z.h:10; allocation size 0x68.
void *fn_802613E0()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x68, lbl_802AEE28,
                              lbl_802AEE6C, 10, 4);
    if (object)
        object = __ct__21CallbackFlag_802ECD68Fv(object);
    return object;
}

// Breakable_Z.h:9; allocation size 0x88.
void *fn_80261438()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x88, lbl_802AEE28,
                              lbl_802AEE7C, 9, 4);
    if (object)
        object = __ct__18Breakable_802EC810Fv(object);
    return object;
}

// LodAgent_Z.h:7; allocation size 0x80.
void *fn_80261490()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x80, lbl_802AEE28,
                              lbl_802AEE8C, 7, 4);
    if (object)
        object = __ct__17LodAgent_802EC8A8Fv(object);
    return object;
}

// Throwable_Z.h:9; allocation size 0x80.
void *fn_802614E8()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x80, lbl_802AEE28,
                              lbl_802AEE9C, 9, 4);
    if (object)
        object = __ct__24CallbackControl_802ECC00Fv(object);
    return object;
}

// MovingAgent_Z.h:8; allocation size 0x78.
void *fn_80261540()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x78, lbl_802AEE28,
                              lbl_802AEEAC, 8, 4);
    if (object)
        object = __ct__23CallbackSingle_802ECA18Fv(object);
    return object;
}

// SkinAgent_Z.h:7; allocation size 0x70.
void *fn_80261598()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x70, lbl_802AEE28,
                              lbl_802AEEBC, 7, 4);
    if (object)
        object = __ct__18SkinAgent_802ECAF8Fv(object);
    return object;
}

// LodDynAgent_Z.h:7; allocation size 0x70.
void *fn_802615F0()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x70, lbl_802AEE28,
                              lbl_802AEECC, 7, 4);
    if (object)
        object = __ct__24LodDynamicAgent_802EC958Fv(object);
    return object;
}

// AnimatedAgent_Z.h:14; allocation size 0x70.
void *fn_80261648()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x70, lbl_802AEE28,
                              lbl_802AEEDC, 14, 4);
    if (object)
        object = __ct__21CallbackPair_802EC798Fv(object);
    return object;
}
}
