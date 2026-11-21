typedef unsigned long u32;
struct Handle_801F7F10 { u32 word; };
struct BaseObject_Z {
 u32 unknown0; Handle_801F7F10 identity;
 BaseObject_Z(); virtual ~BaseObject_Z();
 virtual void slot0C(u32); virtual void slot10(); virtual void slot14(); virtual void slot18(); virtual signed char slot1C();
};
struct Activable_Z:BaseObject_Z {
 u32 prev,next,field14; signed char field18; char pad19[3];
 Activable_Z(); virtual ~Activable_Z(); virtual void slot18(); virtual void slot20(); virtual void slot24(); virtual void slot28();
};
struct Manipulator_Z:Activable_Z {
 float accumulated;
 Manipulator_Z(); virtual ~Manipulator_Z(); virtual void slot2C(float); virtual void slot30(); virtual void slot34(); virtual void slot38(float)=0; virtual void slot3C();
};
struct FactoryCallback{virtual~FactoryCallback();};
struct CFSM {
 virtual ~CFSM();
 virtual void configureCallbacks();
 virtual void configure(int);
 virtual void reset();
 signed char enabled,changing;char unknown06[2];int current,previous,pending,unknown14;unsigned long long active,activeCount;int count;FactoryCallback**callbacks;
 CFSM();
};
struct CGCMemCardManipulator:Manipulator_Z,CFSM {
 virtual void configureCallbacks();
 virtual void slot18();
 virtual void slot34();
 virtual void slot38(float);
 CGCMemCardManipulator(); virtual ~CGCMemCardManipulator();
};
typedef char CheckPrimary[(sizeof(Manipulator_Z)==0x20)?1:-1];
typedef char CheckSecondary[(sizeof(CFSM)==0x30)?1:-1];
typedef char CheckOwner[(sizeof(CGCMemCardManipulator)==0x50)?1:-1];
extern "C" void fn_80213920(Activable_Z*,int);
extern "C" void fn_80213A18(Activable_Z*);
extern "C" signed char fn_8007DA74(CFSM*,float);
extern "C" {
extern char lbl_801EF5C8[];extern const char lbl_802AB880[],lbl_802AB890[];

void* fn_801EFA1C(void*,unsigned int,const char*,const char*,int,int);
void fn_8007D8EC(CFSM*,FactoryCallback**);
void fn_8007D6A0(CFSM*,int);
FactoryCallback* fn_800E9560(FactoryCallback*,CGCMemCardManipulator*);
FactoryCallback* fn_800E9F38(FactoryCallback*,CGCMemCardManipulator*);
FactoryCallback* fn_800EA5DC(FactoryCallback*,CGCMemCardManipulator*);
FactoryCallback* fn_800EAAC8(FactoryCallback*,CGCMemCardManipulator*);
FactoryCallback* fn_800EADEC(FactoryCallback*,CGCMemCardManipulator*);
FactoryCallback* fn_800EB294(FactoryCallback*,CGCMemCardManipulator*);
FactoryCallback* fn_800EBA08(FactoryCallback*,CGCMemCardManipulator*);
FactoryCallback* fn_800EBD7C(FactoryCallback*,CGCMemCardManipulator*);
FactoryCallback* fn_800EC2B8(FactoryCallback*,CGCMemCardManipulator*);
FactoryCallback* fn_800EC054(FactoryCallback*,CGCMemCardManipulator*);
FactoryCallback* fn_800EC8D8(FactoryCallback*,CGCMemCardManipulator*);
FactoryCallback* fn_800ECDD8(FactoryCallback*,CGCMemCardManipulator*);
FactoryCallback* fn_800EDC38(FactoryCallback*,CGCMemCardManipulator*);
FactoryCallback* fn_800ED75C(FactoryCallback*,CGCMemCardManipulator*);
FactoryCallback* fn_800ED2B4(FactoryCallback*,CGCMemCardManipulator*);
FactoryCallback* fn_800EE1A4(FactoryCallback*,CGCMemCardManipulator*);
FactoryCallback* fn_800EE620(FactoryCallback*,CGCMemCardManipulator*);
FactoryCallback* fn_800EEAFC(FactoryCallback*,CGCMemCardManipulator*);
FactoryCallback* fn_800EEFFC(FactoryCallback*,CGCMemCardManipulator*);
FactoryCallback* fn_800EF4B0(FactoryCallback*,CGCMemCardManipulator*);
FactoryCallback* fn_800EB75C(FactoryCallback*,CGCMemCardManipulator*);
FactoryCallback* fn_800E9648(FactoryCallback*,CGCMemCardManipulator*);
FactoryCallback* fn_800E9B14(FactoryCallback*,CGCMemCardManipulator*);
FactoryCallback* fn_800EC674(FactoryCallback*,CGCMemCardManipulator*);
}


extern "C" void fn_801EF610(void*,void*);
inline void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
CGCMemCardManipulator::CGCMemCardManipulator() {
 callbacks=(FactoryCallback**)fn_801EFA1C(lbl_801EF5C8,96,lbl_802AB880,lbl_802AB890,8,4);
}
