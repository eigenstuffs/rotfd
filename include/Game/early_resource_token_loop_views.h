#ifndef GAME_EARLY_RESOURCE_TOKEN_LOOP_VIEWS_H
#define GAME_EARLY_RESOURCE_TOKEN_LOOP_VIEWS_H
typedef unsigned long ResourceTokenWord;
struct ResourceTokenReader{char unknown00[4];};
struct ResourceTokenObject{char unknown00[0xC];ResourceTokenReader reader;};
struct ResourceTokenEntry{ResourceTokenObject*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Handle_801F7F10{union{ResourceTokenWord word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct ResourceTokenManagerPrefix{char unknown00[8];ResourceTokenEntry*entries;char unknown0C[0x18];};
struct ResourceTokenManager:ResourceTokenManagerPrefix{virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();virtual Handle_801F7F10 load(const char*);};
struct ResourceTokenContext{char unknown00[0x118];ResourceTokenManager*manager;};
extern "C"{extern ResourceTokenContext lbl_801E9D24;extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(ResourceTokenManager*,const void*,short);ResourceTokenWord fn_801F7EB8(const Handle_801F7F10*);void fn_801F372C(ResourceTokenReader*,char*);void fn_801F3168(ResourceTokenReader*,char*,signed char);signed char fn_801F2E04(ResourceTokenReader*);int strcmp(const char*,const char*);int strncmp(const char*,const char*,unsigned long);char*strcpy(char*,const char*);char*strncpy(char*,const char*,unsigned long);void fn_800A5080(void*,ResourceTokenReader*);void fn_800A6504(void*,int);extern const char lbl_80378EA8[5],lbl_80379188[3],lbl_803791E0[7],lbl_803791E8[8],lbl_803791C8[2];}
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){word=0;}~Handle_8001FF78(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_8001FF04:Handle_8001FF78{Handle_8001FF04(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_8001FF04(){} };
inline ResourceTokenObject*resolveResourceToken(const Handle_801F7F10&h){int index=h.bits.index;ResourceTokenManager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
struct ResourceTokenRecord{char text[128];ResourceTokenWord flags;};extern "C" ResourceTokenRecord lbl_802F9FC8[400];
#endif
