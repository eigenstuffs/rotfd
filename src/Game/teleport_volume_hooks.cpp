// TeleportVolume reconstructed methods; unknown names describe observed ABI offsets.
typedef unsigned long u32;
typedef unsigned long long u64;
struct Handle{u32 value;};
struct Registry;
struct Globals{char unknown[0x118];Registry*registry;};
extern "C" Globals lbl_801E9D24;
struct Prefix {u32 unknown[2];};
struct Agent:Prefix {
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
 virtual void slot84();
 virtual void slot88();
 virtual void slot8C();
 virtual void slot90();
 virtual void slot94(int,int);
 virtual void slot98(int,int);
 virtual void slot9C();
 virtual void slotA0();
 virtual void slotA4();
 virtual void slotA8();
 virtual void slotAC();
 virtual void slotB0();
 char unknownC[0x38-0xC];u64 flags;char unknown40[0x30];Handle reference;
 void setFlags(u64 mask){flags|=mask;}
};
extern "C" {
void fn_80044380(Agent*);void fn_80044428(Agent*);
void fn_801F86C8(Registry*,const Handle*,int);
void fn_800C7924(Agent*self){fn_80044380(self);self->slot98(0,0);}
void fn_800C796C(Agent*self){fn_80044428(self);self->slot98(0,0);}
void fn_800C79B4(Agent*self,const Handle*other){self->setFlags(0x40000000ULL);fn_801F86C8(lbl_801E9D24.registry,&self->reference,-1);self->reference=*other;fn_801F86C8(lbl_801E9D24.registry,other,1);}
}
