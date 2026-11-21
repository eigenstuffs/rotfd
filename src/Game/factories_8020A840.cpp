// Recovered engine allocation-and-construction factory fragment.
// Header strings identify registrations, not complete original translation units.
extern "C" {
extern char lbl_801EF5C8[];
void *fn_801EFA1C(void *, unsigned long, const char *, const char *, int, int);
extern const char lbl_802AE024[];
extern const char lbl_802AE238[];
extern const char lbl_802AE244[];
extern const char lbl_802AE250[];
extern const char lbl_802AE260[];
extern const char lbl_802AE270[];
extern const char lbl_802AE284[];
extern const char lbl_802AE290[];
extern const char lbl_802AE29C[];
extern const char lbl_802AE2A8[];
void *__ct__18AnimFrame_801EF438Fv(void *);
void *fn_801F0920(void *);
void *fn_801F6A7C(void *);
void *__ct__18Hierarchy_80200478Fv(void *);
void *__ct__15Camera_80242120Fv(void *);
void *fn_802435AC(void *);
void *fn_80243D84(void *);
void *__ct__14Light_8024405CFv(void *);
void *fn_802441F0(void *);

// Game_Z.h:121; allocation size 0xEC.
void *fn_8020A840()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0xEC, lbl_802AE024,
                              lbl_802AE238, 121, 4);
    if (object)
        object = __ct__18Hierarchy_80200478Fv(object);
    return object;
}

// Camera_Z.h:90; allocation size 0x134.
void *fn_8020A898()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x134, lbl_802AE024,
                              lbl_802AE244, 90, 4);
    if (object)
        object = __ct__15Camera_80242120Fv(object);
    return object;
}

// AnimFrame_Z.h:202; allocation size 0xCC.
void *fn_8020A8F0()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0xCC, lbl_802AE024,
                              lbl_802AE250, 202, 4);
    if (object)
        object = __ct__18AnimFrame_801EF438Fv(object);
    return object;
}

// Animation_Z.h:68; allocation size 0x38.
void *fn_8020A948()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x38, lbl_802AE024,
                              lbl_802AE260, 68, 4);
    if (object)
        object = fn_801F6A7C(object);
    return object;
}

// CollisionVol_Z.h:104; allocation size 0xF8.
void *fn_8020A9A0()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0xF8, lbl_802AE024,
                              lbl_802AE270, 104, 4);
    if (object)
        object = fn_802435AC(object);
    return object;
}

// Emiter_Z.h:26; allocation size 0x84.
void *fn_8020A9F8()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x84, lbl_802AE024,
                              lbl_802AE284, 26, 4);
    if (object)
        object = fn_80243D84(object);
    return object;
}

// Omni_Z.h:35; allocation size 0x8C.
void *fn_8020AA50()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x8C, lbl_802AE024,
                              lbl_802AE290, 35, 4);
    if (object)
        object = fn_802441F0(object);
    return object;
}

// HFog_Z.h:48; allocation size 0x12C.
void *fn_8020AAA8()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x12C, lbl_802AE024,
                              lbl_802AE29C, 48, 4);
    if (object)
        object = fn_801F0920(object);
    return object;
}

// Light_Z.h:48; allocation size 0xB8.
void *fn_8020AB00()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0xB8, lbl_802AE024,
                              lbl_802AE2A8, 48, 4);
    if (object)
        object = __ct__14Light_8024405CFv(object);
    return object;
}
}
