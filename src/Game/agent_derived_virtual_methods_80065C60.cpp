/* Inferred partial derived virtual view; original full tables retain ownership. */
// Inferred partial observed interface only; complete inheritance/type/key provenance unknown.
struct Handle;struct OpaqueHandle;
struct PrimaryPrefix_80065C60 {unsigned long unknown00[2];};
struct PrimaryView_80065C60:PrimaryPrefix_80065C60 {
 virtual ~PrimaryView_80065C60();
 virtual void slot_00C();
 virtual void slot_010();
 virtual void slot_014();
 virtual void method_80063074();
 virtual void slot_01C();
 virtual unsigned long slot_020();
 virtual void slot_024(unsigned long);
 virtual void slot_028(void*);
 virtual int slot_02C(void*);
 virtual void slot_030();
 virtual void slot_034();
 virtual void method_8006311C();
 virtual void slot_03C();
 virtual void slot_040(int);
 virtual void slot_044(const OpaqueHandle&);
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
 virtual const Handle*getControllerHandle();
 char unknown0C[0x28-0xC];unsigned long actor28;float scalar2C;
 char unknown30[0x84-0x30];unsigned long value84;unsigned char value88;char unknown89;unsigned short value8A;char unknown8C[4];
};
struct SecondaryPrefix_80065C60 {unsigned long unknown00;};
struct SecondaryView_80065C60:SecondaryPrefix_80065C60 {
 virtual ~SecondaryView_80065C60();
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
struct AgentVirtualBase_80065C60:PrimaryView_80065C60,SecondaryView_80065C60 {
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
 virtual ~AgentVirtualBase_80065C60();
 char unknown1F0[0x10];
};

// The accepted native CT/DT establishes ObjectVirtualView_80065C60 : AgentVirtualBase_80065C60 and secondary +0x90.
// Virtual names/signatures are address-qualified inferred observed interfaces, not recovered spelling.
struct ObjectVirtualView_80065C60:AgentVirtualBase_80065C60 {
 virtual void method_8006311C();
 virtual void slot_040(int);
 virtual void slot_044(const OpaqueHandle&);
 virtual void slot_0B0();
 virtual unsigned long slot_020();
 virtual void slot_024(unsigned long);
 virtual void slot_028(void*);
 virtual int slot_02C(void*);
 virtual void method_80063074();
 virtual ~ObjectVirtualView_80065C60();
 ObjectVirtualView_80065C60();
};
typedef char AgentSize[(sizeof(AgentVirtualBase_80065C60)==0x200)?1:-1];
typedef char ObjectSize[(sizeof(ObjectVirtualView_80065C60)==0x200)?1:-1];

extern "C" {
 extern void*lbl_80377728;
 void fn_8006311C(void*);void fn_80063290(void*,int);
 void fn_80063F98(void*,const OpaqueHandle&);void fn_80063FB8(void*);
 void fn_8025ED38(void*,void*,void*);void fn_800642A8(void*,void*);
 int fn_8025E70C(void*,void*,void*);int fn_8006434C(void*,void*);
}
void ObjectVirtualView_80065C60::method_8006311C(){fn_8006311C(this);}
void ObjectVirtualView_80065C60::slot_040(int argument){fn_80063290(this,argument);}
void ObjectVirtualView_80065C60::slot_044(const OpaqueHandle&value){fn_80063F98(this,value);}
void ObjectVirtualView_80065C60::slot_0B0(){fn_80063FB8(this);}
unsigned long ObjectVirtualView_80065C60::slot_020(){return reinterpret_cast<unsigned long>(lbl_80377728);}
void ObjectVirtualView_80065C60::slot_024(unsigned long value){lbl_80377728=reinterpret_cast<void*>(value);}
void ObjectVirtualView_80065C60::slot_028(void*value){fn_8025ED38(this,value,lbl_80377728);fn_800642A8(this,value);}
int ObjectVirtualView_80065C60::slot_02C(void*value){int result=fn_8025E70C(this,value,lbl_80377728);if(result!=-1)return result;return fn_8006434C(this,value);}
