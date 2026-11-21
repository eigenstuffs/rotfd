// Recovered engine allocation-and-construction factory fragment.
// Header strings identify registrations, not complete original translation units.
extern "C" {
extern char lbl_801EF5C8[];
void *fn_801EFA1C(void *, unsigned long, const char *, const char *, int, int);
extern const char lbl_802AE024[];
extern const char lbl_802AE088[];
extern const char lbl_802AE098[];
extern const char lbl_802AE0A8[];
extern const char lbl_802AE0B4[];
extern const char lbl_802AE0C4[];
extern const char lbl_802AE0D4[];
extern const char lbl_802AE0E4[];
extern const char lbl_802AE0F0[];
void *__ct__17DrawPair_801C2F70Fv(void *);
void *__ct__19HandleDraw_801C426CFv(void *);
void *fn_801C8614(void *);
void *__ct__19DrawRecord_802EB0E0Fv(void *);
void *__ct__15Menu2D_80216C9CFv(void *);
void *__ct__15Menu3D_802193C0Fv(void *);
void *__ct__17MenuPair_802EB2F0Fv(void *);
void *__ct__18MenuArray_802EB348Fv(void *);

// InGameDatas_Z.h:121; allocation size 0x34.
void *fn_80209554()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x34, lbl_802AE024,
                              lbl_802AE088, 121, 4);
    if (object)
        object = __ct__19DrawRecord_802EB0E0Fv(object);
    return object;
}

// SelfRunning_Z.h:60; allocation size 0x38.
void *fn_802095AC()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x38, lbl_802AE024,
                              lbl_802AE098, 60, 4);
    if (object)
        object = fn_801C8614(object);
    return object;
}

// Ghost_Z.h:99; allocation size 0x4C.
void *fn_80209604()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x4C, lbl_802AE024,
                              lbl_802AE0A8, 99, 4);
    if (object)
        object = __ct__17DrawPair_801C2F70Fv(object);
    return object;
}

// RtcPlayer_Z.h:102; allocation size 0x80.
void *fn_8020965C()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x80, lbl_802AE024,
                              lbl_802AE0B4, 102, 4);
    if (object)
        object = __ct__19HandleDraw_801C426CFv(object);
    return object;
}

// MenuSkin_Z.h:55; allocation size 0x60.
void *fn_802096B4()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x60, lbl_802AE024,
                              lbl_802AE0C4, 55, 4);
    if (object)
        object = __ct__17MenuPair_802EB2F0Fv(object);
    return object;
}

// MenuObject_Z.h:57; allocation size 0x84.
void *fn_8020970C()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x84, lbl_802AE024,
                              lbl_802AE0D4, 57, 4);
    if (object)
        object = __ct__18MenuArray_802EB348Fv(object);
    return object;
}

// Menu2D_Z.h:84; allocation size 0xCC.
void *fn_80209764()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0xCC, lbl_802AE024,
                              lbl_802AE0E4, 84, 4);
    if (object)
        object = __ct__15Menu2D_80216C9CFv(object);
    return object;
}

// Menu3D_Z.h:80; allocation size 0xC0.
void *fn_802097BC()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0xC0, lbl_802AE024,
                              lbl_802AE0F0, 80, 4);
    if (object)
        object = __ct__15Menu3D_802193C0Fv(object);
    return object;
}
}
