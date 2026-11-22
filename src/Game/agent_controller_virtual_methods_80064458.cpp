/* Inferred partial virtual view; original full tables remain external. */
// Inferred partial observed interface only; complete inheritance/type/key provenance unknown.
struct Handle_80062E18;struct OpaqueHandle;
struct PrimaryPrefix_80062E18 {unsigned long unknown00[2];};
struct PrimaryView_80062E18:PrimaryPrefix_80062E18 {
 virtual ~PrimaryView_80062E18();
 virtual void slot_00C();
 virtual void slot_010();
 virtual void slot_014();
 virtual void slot_018();
 virtual void slot_01C();
 virtual void slot_020();
 virtual void slot_024();
 virtual void slot_028();
 virtual void slot_02C();
 virtual void slot_030();
 virtual void slot_034();
 virtual void slot_038();
 virtual void slot_03C();
 virtual void slot_040();
 virtual void slot_044();
 virtual void slot_048();
 virtual void slot_04C();
 virtual void slot_050();
 virtual void slot_054();
 virtual void slot_058();
 virtual void slot_05C();
 virtual void slot_060();
 virtual void slot_064();
 virtual void slot_068();
 virtual void slot_06C();
 virtual void slot_070();
 virtual void slot_074();
 virtual void slot_078();
 virtual void slot_07C();
 virtual void slot_080();
 virtual void slot_084();
 virtual void slot_088();
 virtual void slot_08C();
 virtual void slot_090();
 virtual void slot_094();
 virtual void slot_098();
 virtual void slot_09C();
 virtual void slot_0A0();
 virtual void slot_0A4();
 virtual void slot_0A8();
 virtual void slot_0AC();
 virtual void slot_0B0();
 virtual void slot_0B4();
 virtual void slot_0B8();
 virtual void slot_0BC();
 virtual void slot_0C0();
 virtual void slot_0C4();
 virtual void slot_0C8();
 virtual void slot_0CC();
 virtual void slot_0D0();
 virtual void slot_0D4();
 virtual void slot_0D8();
 virtual void slot_0DC();
 virtual void slot_0E0();
 virtual void slot_0E4();
 virtual void slot_0E8();
 virtual void slot_0EC();
 virtual void slot_0F0();
 virtual void slot_0F4();
 virtual void slot_0F8();
 virtual void slot_0FC();
 virtual void slot_100();
 virtual void slot_104();
 virtual void slot_108();
 virtual void slot_10C();
 virtual void slot_110();
 virtual void slot_114();
 virtual void slot_118();
 virtual void slot_11C();
 virtual void slot_120();
 virtual void slot_124();
 virtual void slot_128();
 virtual void slot_12C();
 virtual const Handle_80062E18*getControllerHandle();
 char unknown0C[0x28-0xC];unsigned long actor28;float scalar2C;
 char unknown30[0x84-0x30];unsigned long value84;unsigned char value88;char unknown89;unsigned short value8A;char unknown8C[4];
};
struct SecondaryPrefix_80062E18 {unsigned long unknown00;};
struct SecondaryView_80062E18:SecondaryPrefix_80062E18 {
 virtual ~SecondaryView_80062E18();
 virtual void method_80063074();
 virtual void method_8006311C();
 virtual void method_80064638();
 virtual void*method_800645EC();
 virtual float method_800645E4();
 virtual void method_800645C4();
 virtual int method_800645A4(int);
 virtual void*method_80024DAC();
 virtual unsigned long method_8006459C();
 virtual unsigned char method_80064594();
 virtual unsigned short method_8006458C();
 virtual void method_80064560();
 virtual void method_80064540(const OpaqueHandle&);
 virtual void method_8006451C(int,int);
 virtual void method_800644FC(int,void*);
 virtual void method_80064470(int);
 virtual void method_80064468(unsigned long);
 virtual void method_80064460(unsigned char);
 virtual void method_80064458(unsigned short);
 char unknown08[0x160-8];
};
struct CActorScriptAgent:PrimaryView_80062E18,SecondaryView_80062E18 {
 virtual void method_80064458(unsigned short);
 virtual void method_80064460(unsigned char);
 virtual void method_80064468(unsigned long);
 virtual void method_80064470(int);
 virtual void method_800644FC(int,void*);
 virtual void method_8006451C(int,int);
 virtual void method_80064540(const OpaqueHandle&);
 virtual void method_80064560();
 virtual unsigned short method_8006458C();
 virtual unsigned char method_80064594();
 virtual unsigned long method_8006459C();
 virtual void*method_80024DAC();
 virtual int method_800645A4(int);
 virtual void method_800645C4();
 virtual float method_800645E4();
 virtual void*method_800645EC();
 virtual void method_80064638();
 virtual void method_8006311C();
 virtual void method_80063074();
 virtual ~CActorScriptAgent();
};

struct Handle_80062E18 {signed int tag:8;signed int index:24;};
struct HandleEntry_80062E18 {void*object;char pad[8];signed char tag;char tail[3];};
struct Manager_80062E18 {char pad[8];HandleEntry_80062E18*entries;};
struct Context_80062E18 {char pad[0x118];Manager_80062E18*manager;};
extern "C" {extern Context_80062E18 lbl_801E9D24;void fn_8007D6A0(void*,int);void fn_8025795C(void*,int,void*);void fn_80257828(void*,int,int,int);void fn_8025A3C8(void*,const OpaqueHandle&);int fn_8025E9FC(void*,int);void fn_8025E50C(void*);}
static inline void*resolve(const Handle_80062E18*h){HandleEntry_80062E18*entry=&lbl_801E9D24.manager->entries[h->index];if(entry->tag==h->tag)return entry->object;return 0;}
void CActorScriptAgent::method_80064458(unsigned short value){value8A=value;}
void CActorScriptAgent::method_80064460(unsigned char value){value88=value;}
void CActorScriptAgent::method_80064468(unsigned long value){value84=value;}
void CActorScriptAgent::method_80064470(int index){fn_8007D6A0((char*)resolve(getControllerHandle())+0x318,index);}
void CActorScriptAgent::method_800644FC(int index,void*argument){fn_8025795C(this,index,argument);}
void CActorScriptAgent::method_8006451C(int first,int second){fn_80257828(this,first,second,0);}
void CActorScriptAgent::method_80064540(const OpaqueHandle&value){fn_8025A3C8(this,value);}
void CActorScriptAgent::method_80064560(){slot_068();}
unsigned short CActorScriptAgent::method_8006458C(){return value8A;}
unsigned char CActorScriptAgent::method_80064594(){return value88;}
unsigned long CActorScriptAgent::method_8006459C(){return value84;}
int CActorScriptAgent::method_800645A4(int index){return fn_8025E9FC(this,index);}
void CActorScriptAgent::method_800645C4(){fn_8025E50C(this);}
float CActorScriptAgent::method_800645E4(){return scalar2C;}
void*CActorScriptAgent::method_800645EC(){return resolve((const Handle_80062E18*)&actor28);}
void CActorScriptAgent::method_80064638(){}

typedef char CheckPrimarySize[(sizeof(PrimaryView_80062E18)==0x90)?1:-1];
typedef char CheckSecondarySize[(sizeof(SecondaryView_80062E18)==0x160)?1:-1];
