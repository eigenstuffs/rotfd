/* Scene command formatting and scoped native handles.
 * See docs/notes/game-early-formatted-scene-command.md. */
typedef unsigned long Word;
struct Handle_801F7F10 {Word word;Handle_801F7F10();~Handle_801F7F10();};
extern "C"{extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);}
struct FormattedZero_6910C:Handle_801F7F10 {FormattedZero_6910C(){word=0;}};
struct Handle_80020B90:FormattedZero_6910C {Handle_80020B90(){word=0;}~Handle_80020B90(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct ServicePrefix {char unknown00[0x7C];};
struct Service:ServicePrefix {
 virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();virtual void slot8();virtual void slot9();virtual void slot10();virtual void slot11();virtual void slot12();virtual void slot13();virtual void slot14();virtual void slot15();virtual void play(const char*,int,const Handle_80020B90&,const Handle_80020B90&);
};
struct Actor {char unknown00[0xF4];int valueF4;};
struct Scene {char unknown00[0x15058];Actor* current15058;};
struct Globals {char unknown00[0x124];Scene* scene124;char unknown128[0x158-0x128];Service* service158;};
extern "C" {extern Globals lbl_801E9D24;extern char lbl_8029C788[17];extern char lbl_803787DC[3],lbl_803787E0[2],lbl_803787E4[5];char*strcpy(char*,const char*);char*strcat(char*,const char*);int sprintf(char*,const char*,...);}
extern "C" int fn_8006910C(void*,const char* text){char buffer[128];char number[12];buffer[0]=0;strcpy(buffer,lbl_8029C788);sprintf(number,lbl_803787DC,lbl_801E9D24.scene124->current15058->valueF4);strcat(buffer,number);strcat(buffer,lbl_803787E0);strcat(buffer,text);strcat(buffer,lbl_803787E4);{Handle_80020B90 first,second;Service*s=lbl_801E9D24.service158;s->play(buffer,0,first,second);}return 1;}
