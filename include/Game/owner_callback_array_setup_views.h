#ifndef GAME_OWNER_CALLBACK_ARRAY_SETUP_VIEWS_H
#define GAME_OWNER_CALLBACK_ARRAY_SETUP_VIEWS_H
struct CallbackArrayEntry{char unknown00[12];};
struct CallbackArrayController{virtual void slot0();virtual void slot1();virtual void configure(int);char unknown04[0x28];};
struct CallbackArrayOwner{char unknown00[0x318];CallbackArrayController controller;CallbackArrayEntry**callbacks;};
extern "C" {
extern unsigned char lbl_801EF5C8[];
void*fn_801EFA1C(void*,unsigned int,const char*,const char*,int,int);
void slot1A4__14CJellyfishMoveFv(CallbackArrayOwner*,void*);
extern const char lbl_8029DE20[],lbl_8029DE30[];
CallbackArrayEntry*fn_80094AB4(CallbackArrayEntry*,CallbackArrayOwner*,void*);
CallbackArrayEntry*fn_80094DDC(CallbackArrayEntry*,CallbackArrayOwner*,void*);
CallbackArrayEntry*fn_80096694(CallbackArrayEntry*,CallbackArrayOwner*,void*);
CallbackArrayEntry*fn_8009652C(CallbackArrayEntry*,CallbackArrayOwner*,void*);
extern const char lbl_8029DF18[],lbl_8029DF28[];
CallbackArrayEntry*fn_800957B0(CallbackArrayEntry*,CallbackArrayOwner*,void*);
CallbackArrayEntry*fn_8009587C(CallbackArrayEntry*,CallbackArrayOwner*,void*);
CallbackArrayEntry*fn_80095BB4(CallbackArrayEntry*,CallbackArrayOwner*,void*);
extern const char lbl_8029E0E8[],lbl_8029E0F8[];
CallbackArrayEntry*fn_80098048(CallbackArrayEntry*,CallbackArrayOwner*,void*);
CallbackArrayEntry*fn_800981B0(CallbackArrayEntry*,CallbackArrayOwner*,void*);
extern const char lbl_8029E1D8[],lbl_8029E1E8[];
CallbackArrayEntry*fn_80097560(CallbackArrayEntry*,CallbackArrayOwner*,void*);
CallbackArrayEntry*fn_800976C8(CallbackArrayEntry*,CallbackArrayOwner*,void*);
extern const char lbl_8029E290[],lbl_8029E2A0[];
CallbackArrayEntry*fn_80094BAC(CallbackArrayEntry*,CallbackArrayOwner*,void*);
CallbackArrayEntry*fn_80094C68(CallbackArrayEntry*,CallbackArrayOwner*,void*);
CallbackArrayEntry*fn_80094D24(CallbackArrayEntry*,CallbackArrayOwner*,void*);
CallbackArrayEntry*fn_80094E90(CallbackArrayEntry*,CallbackArrayOwner*,void*);
CallbackArrayEntry*fn_80094F88(CallbackArrayEntry*,CallbackArrayOwner*,void*);
extern const char lbl_8029E480[],lbl_8029E490[];
CallbackArrayEntry*fn_8009C230(CallbackArrayEntry*,CallbackArrayOwner*);
CallbackArrayEntry*fn_8009C63C(CallbackArrayEntry*,CallbackArrayOwner*);
CallbackArrayEntry*fn_8009C758(CallbackArrayEntry*,CallbackArrayOwner*);
CallbackArrayEntry*fn_8009CB78(CallbackArrayEntry*,CallbackArrayOwner*);
}
#endif
