/* Original record resource lifecycle; see docs/notes/game-engine-record-lifecycle.md. */
typedef unsigned long u32;typedef unsigned long long u64;
struct Prefix{u32 unknown00,unknown04;};
struct Object:Prefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74(int,int);char opaque0C[0x38-0xC];u64 flags38;char opaque40[0x60-0x40];};
struct ServicePrefix{char opaque00[0x30];};
struct Service:ServicePrefix{virtual void slot08();virtual void slot0C(const char*);virtual void slot10(const char*);virtual void slot14(int);virtual void slot18(const char*);virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28(int);virtual void slot2C(int,u32);};
struct Entry{Object*object;char opaque04[8];signed char generation;char opaque0D[3];};struct Manager{u32 field0,field4;Entry*entries;};
extern "C"{extern struct{char opaque00[0x118];Manager*manager;char opaque11C[0x4C];Service*service168;}lbl_801E9D24;extern const char lbl_802AB298[];void fn_80276F58(Service*,const char*);}
struct Handle_801F7F10{union{u32 word;struct{signed int generation:8;signed int index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
extern "C" Handle_801F7F10 fn_801B52EC(Manager*,const char*);
struct View:Object{char name60[32],name80[32],nameA0[32],nameC0[6];char opaqueC6[0xB2E8-0xC6];Service*serviceB2E8;Object*objectB2EC;u32 bytesB2F0;};
inline Object*resolve(const Handle_801F7F10&h){Entry*entry=&lbl_801E9D24.manager->entries[h.bits.index];return entry->generation==h.bits.generation?entry->object:0;}
extern "C" void fn_800E8418(View*self){self->flags38|=0x20000ULL;self->slot34();self->slot74(0,0);self->serviceB2E8=lbl_801E9D24.service168;self->serviceB2E8->slot14(2);self->serviceB2E8->slot28(1);self->serviceB2E8->slot10(self->name80);self->serviceB2E8->slot18(self->nameC0);self->serviceB2E8->slot0C(self->name60);fn_80276F58(self->serviceB2E8,self->nameA0);self->bytesB2F0=0xB220;self->serviceB2E8->slot2C(0,self->bytesB2F0);self->objectB2EC=resolve(fn_801B52EC(lbl_801E9D24.manager,lbl_802AB298));}
