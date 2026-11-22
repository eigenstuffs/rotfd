typedef unsigned long Word;
struct Mode{char opaque00[0xF0];int selected;};
struct World{char opaque00[0x15058];Mode*mode;};
struct Context{char opaque00[0x124];World*world;};
extern "C"{extern Context lbl_801E9D24;Word fn_80055DA8(const Mode*);Word fn_80055CD0(const Mode*,int);Word fn_80055DB0(const Mode*);Word fn_80055DB8(const Mode*);Word fn_80055CF0(const Mode*,int);Word fn_80055D10(const Mode*,int);Word fn_80055D90(const Mode*);unsigned char fn_80056828(const Mode*);}
extern "C" Word fn_80066250(void*ignoredSelf){return fn_80055DA8(lbl_801E9D24.world->mode);}
extern "C" Word fn_80066284(void*ignoredSelf){return fn_80055CD0(lbl_801E9D24.world->mode,-1);}
extern "C" Word fn_800662BC(void*ignoredSelf){return fn_80055DB0(lbl_801E9D24.world->mode);}
extern "C" Word fn_800662F0(void*ignoredSelf){return fn_80055DB8(lbl_801E9D24.world->mode);}
extern "C" Word fn_80066324(void*ignoredSelf){return fn_80055CF0(lbl_801E9D24.world->mode,lbl_801E9D24.world->mode->selected);}
extern "C" Word fn_8006635C(void*ignoredSelf){return fn_80055D10(lbl_801E9D24.world->mode,lbl_801E9D24.world->mode->selected);}
extern "C" Word fn_80066394(void*ignoredSelf){return fn_80055D90(lbl_801E9D24.world->mode);}
extern "C" unsigned char fn_800663C8(void*ignoredSelf){return fn_80056828(lbl_801E9D24.world->mode);}
