// Recovered allocation-and-construction factory fragment.
// Original header strings identify each registration; full TU ownership is unknown.
// Constructors, diagnostic strings and allocator storage remain external.
extern "C" {
extern char lbl_801EF5C8[];
void *fn_801EFA1C(void *, unsigned long, const char *, const char *, int, int);
extern const char lbl_802A0E78[];
extern const char lbl_802A0FCC[];
extern const char lbl_802A0FE0[];
extern const char lbl_802A0FF4[];
extern const char lbl_802A1004[];
extern const char lbl_802A1014[];
extern const char lbl_802A1028[];
void *__ct__14Agent_8002CF70Fv(void *);
void *__ct__15Object_8002DC0CFv(void *);
void *__ct__14Agent_8003CD88Fv(void *);
void *__ct__14Agent_80064744Fv(void *);
void *fn_80064D90(void *);
void *fn_800C4F7C(void *);
void *__ct__14TeleportVolumeFv(void *);

// TeleportVolume.h:26; allocation size 0xC0.
void *fn_800BA9BC()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0xC0, lbl_802A0E78,
                              lbl_802A0FCC, 26, 4);
    if (object)
        object = __ct__14TeleportVolumeFv(object);
    return object;
}

// RtcInGameAgent_Z.h:10; allocation size 0x180.
void *fn_800BAA14()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x180, lbl_802A0E78,
                              lbl_802A0FE0, 10, 4);
    if (object)
        object = __ct__14Agent_8003CD88Fv(object);
    return object;
}

// MainMenuAgent.h:37; allocation size 0x98.
void *fn_800BAA6C()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x98, lbl_802A0E78,
                              lbl_802A0FF4, 37, 4);
    if (object)
        object = __ct__15Object_8002DC0CFv(object);
    return object;
}

// CameraAgent.h:29; allocation size 0x68.
void *fn_800BAAC4()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x68, lbl_802A0E78,
                              lbl_802A1004, 29, 4);
    if (object)
        object = __ct__14Agent_8002CF70Fv(object);
    return object;
}

// SpringboardAgent.h:54; allocation size 0x78.
void *fn_800BAB1C()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x78, lbl_802A0E78,
                              lbl_802A1014, 54, 4);
    if (object)
        object = fn_80064D90(object);
    return object;
}

// SpringboardAgent.h:28; allocation size 0x70.
void *fn_800BAB74()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x70, lbl_802A0E78,
                              lbl_802A1014, 28, 4);
    if (object)
        object = __ct__14Agent_80064744Fv(object);
    return object;
}

// SpellBookAgent.h:12; allocation size 0x98.
void *fn_800BABCC()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x98, lbl_802A0E78,
                              lbl_802A1028, 12, 4);
    if (object)
        object = fn_800C4F7C(object);
    return object;
}
}
