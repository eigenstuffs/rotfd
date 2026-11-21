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
extern "C" const char lbl_802AB880[] = "Anonymous New";
extern "C" const char lbl_802AB890[] = "GCMemCardManipulator.cpp";

void CGCMemCardManipulator::slot18() {fn_80213920(this,8);fn_80213A18(this);configureCallbacks();}
void CGCMemCardManipulator::slot34() {}
void CGCMemCardManipulator::configureCallbacks() {
    CGCMemCardManipulator*self=this;
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 51, 4);
        if (callback) callback = fn_800E9560(callback,self);
        self->callbacks[0] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 20, lbl_802AB880, lbl_802AB890, 52, 4);
        if (callback) callback = fn_800E9F38(callback,self);
        self->callbacks[5] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 53, 4);
        if (callback) callback = fn_800EA5DC(callback,self);
        self->callbacks[6] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 54, 4);
        if (callback) callback = fn_800EAAC8(callback,self);
        self->callbacks[7] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 55, 4);
        if (callback) callback = fn_800EADEC(callback,self);
        self->callbacks[8] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 56, 4);
        if (callback) callback = fn_800EB294(callback,self);
        self->callbacks[9] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 57, 4);
        if (callback) callback = fn_800EBA08(callback,self);
        self->callbacks[10] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 20, lbl_802AB880, lbl_802AB890, 58, 4);
        if (callback) callback = fn_800EBD7C(callback,self);
        self->callbacks[1] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 32, lbl_802AB880, lbl_802AB890, 59, 4);
        if (callback) callback = fn_800EC2B8(callback,self);
        self->callbacks[2] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 60, 4);
        if (callback) callback = fn_800EC054(callback,self);
        self->callbacks[3] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 61, 4);
        if (callback) callback = fn_800EC8D8(callback,self);
        self->callbacks[11] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 62, 4);
        if (callback) callback = fn_800ECDD8(callback,self);
        self->callbacks[12] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 24, lbl_802AB880, lbl_802AB890, 63, 4);
        if (callback) callback = fn_800EDC38(callback,self);
        self->callbacks[13] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 64, 4);
        if (callback) callback = fn_800ED75C(callback,self);
        self->callbacks[14] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 65, 4);
        if (callback) callback = fn_800ED2B4(callback,self);
        self->callbacks[15] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 20, lbl_802AB880, lbl_802AB890, 66, 4);
        if (callback) callback = fn_800EE1A4(callback,self);
        self->callbacks[16] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 67, 4);
        if (callback) callback = fn_800EE620(callback,self);
        self->callbacks[19] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 24, lbl_802AB880, lbl_802AB890, 68, 4);
        if (callback) callback = fn_800EEAFC(callback,self);
        self->callbacks[17] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 69, 4);
        if (callback) callback = fn_800EEFFC(callback,self);
        self->callbacks[18] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 70, 4);
        if (callback) callback = fn_800EF4B0(callback,self);
        self->callbacks[20] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 20, lbl_802AB880, lbl_802AB890, 71, 4);
        if (callback) callback = fn_800EB75C(callback,self);
        self->callbacks[21] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 74, 4);
        if (callback) callback = fn_800E9648(callback,self);
        self->callbacks[22] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 75, 4);
        if (callback) callback = fn_800E9B14(callback,self);
        self->callbacks[23] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 76, 4);
        if (callback) callback = fn_800EC674(callback,self);
        self->callbacks[4] = callback;
    }
    fn_8007D8EC(&static_cast<CFSM&>(*self),self->callbacks);
    static_cast<CFSM&>(*self).configure(24);
    fn_8007D6A0(&static_cast<CFSM&>(*self),0);
}

void CGCMemCardManipulator::slot38(float delta){fn_8007DA74(&static_cast<CFSM&>(*this),delta);}

typedef char CheckBaseIdentity[(unsigned long)&((BaseObject_Z*)0)->identity==4?1:-1];
typedef char CheckCallbacks[(unsigned long)&((CGCMemCardManipulator*)0)->callbacks==0x4C?1:-1];
typedef char CheckCFSMEnabled[(unsigned long)&((CFSM*)0)->enabled==4?1:-1];
