// ContainerInVolume callbacks and flag transitions; observed virtual slots retain their numeric names.
typedef unsigned long u32;
typedef unsigned long long u64;
struct Prefix{u32 unknown[2];};
struct ContainerView:Prefix{
 virtual void slot08();
 virtual void slot0C();
 virtual void slot10();
 virtual void slot14();
 virtual void slot18();
 virtual void slot1C();
 virtual void slot20();
 virtual void slot24();
 virtual void slot28();
 virtual void slot2C();
 virtual void slot30();
 virtual void slot34();
 virtual void slot38();
 virtual void slot3C();
 virtual void slot40();
 virtual void slot44();
 virtual void slot48();
 virtual void slot4C();
 virtual void slot50();
 virtual void slot54();
 virtual void slot58();
 virtual void slot5C();
 virtual void slot60();
 virtual void slot64();
 virtual void slot68();
 virtual void slot6C();
 virtual void slot70();
 virtual void slot74();
 virtual void slot78();
 virtual void slot7C();
 virtual void slot80();
 virtual void reset(int,int);
 char unknown0C[0x38-12];u64 flags;
 void setFlags(u64 mask){flags|=mask;}
 bool hasFlags(u64 mask)const{return (flags&mask)!=0;}
};
extern "C"{
extern const float lbl_80379650;
void fn_802073E8(ContainerView*,int,ContainerView*,float);
void fn_80256370(ContainerView*);
void fn_800CA0E8(ContainerView*self){self->reset(0,0);fn_802073E8(self,0,self,lbl_80379650);}
void fn_800CA13C(ContainerView*self){fn_80256370(self);self->reset(0,0);fn_802073E8(self,0,self,lbl_80379650);}
// The caller discards a result; this guarded void stub retains the original test.
void fn_800CA198(ContainerView*self){if(self->hasFlags(0x20000ULL))return;}
void fn_800CA1C0(ContainerView*self){if(!self->hasFlags(0x40000ULL))fn_802073E8(self,0,self,lbl_80379650);}
void fn_800CA214(ContainerView*self){self->setFlags(0x20000ULL);self->slot34();}
}
