#ifndef GAME_EARLY_ACTOR_TOKEN_CONTROL_VIEWS_H
#define GAME_EARLY_ACTOR_TOKEN_CONTROL_VIEWS_H
struct TokenControlHandle{signed int tag:8,index:24;};
struct TokenControlActorPrefix{char unknown00[8];};
struct TokenControlActor:TokenControlActorPrefix{
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual void slot8();
virtual void slot9();
virtual void slot10();
virtual void slot11();
virtual void slot12();
virtual void slot13();
virtual void slot14();
virtual void slot15();
virtual void slot16();
virtual void slot17();
virtual void slot18();
virtual void slot19();
virtual void slot20();
virtual void slot21();
virtual void slot22();
virtual void slot23();
virtual void slot24();
virtual void slot25();
virtual void slot26();
virtual void slot27();
virtual void slot28();
virtual void slot29();
virtual void slot30();
virtual void slot31();
virtual void slot32();
virtual void slot33();
virtual void slot34();
virtual void slot35();
virtual void slot36();
virtual const TokenControlHandle&related(int);
char unknown0C[0x18];TokenControlHandle handle;char unknown28[8];unsigned long long flags;char unknown38[0xE8];unsigned long relatedFlags;
};
struct TokenControlOwner{char unknown00[8];TokenControlActor*actor;TokenControlActor*resolved;char unknown10[8];float value;};
struct TokenControlEntry{TokenControlActor*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct TokenControlManager{char unknown00[8];TokenControlEntry*entries;};
struct TokenControlContext{char unknown00[0x118];TokenControlManager*manager;};
extern "C" TokenControlContext lbl_801E9D24;
inline TokenControlActor*resolveToken(const TokenControlHandle&h){int index=h.index;TokenControlManager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
extern "C"{int sprintf(char*,const char*,...);char*strcpy(char*,const char*);char*strcat(char*,const char*);int strcmp(const char*,const char*);void fn_801F372C(void*,char*);float fn_801F1200();unsigned long fn_801F948C(void*,const char*);extern const char lbl_80378F74[3],lbl_80378F70[2],lbl_803791B4[3],lbl_803791C8[2],lbl_802A0338[],lbl_802A0344[],lbl_80379238[7],lbl_80378F90[4];extern const float lbl_80379088,lbl_80378F78,lbl_80378F80;}
struct TokenControlName{unsigned long value;TokenControlName(const char*s){value=fn_801F948C(this,s);}TokenControlName(const TokenControlName&n){value=n.value;}};
struct TokenControlSetup{char unknown00[0x48];int count;char unknown4C[0x18];signed char enabled,variant;char unknown66[2];int kind;float value;};
struct TokenControlSelection{char unknown00[0x30];int kind;};
extern "C"{void fn_800A6234(TokenControlSetup*,signed char,const TokenControlName&);void fn_800A85AC(TokenControlSetup*);}
#endif
