typedef unsigned long u32;typedef unsigned long long u64;
union Handle{u32 word;struct{signed int generation:8,index:24;}bits;};
struct Prefix{u32 unknown00,unknown04;};
struct Object:Prefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28(int);virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84(); char opaque0C[0x28-0xC];Handle handle28;char opaque2C[0x38-0x2C];u64 flags38;char opaque40[0x60-0x40];unsigned char value60;char opaque61[3];int mode64;signed char active68;};
struct Node{char opaque00[0x38];u64 flags38;};
struct Entry{Node*object;u32 unknown04,unknown08;signed char generation;char opaque0D[3];};struct Manager{char opaque00[8];Entry*entries;};
extern "C"{extern struct Context{char opaque00[0x118];Manager*manager118;}lbl_801E9D24;}
inline Node*resolve(const Handle&h){Entry*e=&lbl_801E9D24.manager118->entries[h.bits.index];return e->generation==h.bits.generation?e->object:0;}
struct ObserverPrefix{u32 unknown00;};struct Observer:ObserverPrefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void*slot14();};
extern "C"{extern Observer*lbl_803776B8;extern const float lbl_80378560;float fn_8025E268(Object*,int);signed char fn_8025E9FC(Object*,int);void fn_802073E8(Object*,int,void*,float);}
inline bool validMode(int mode){if(mode<0||mode>2)return false;return true;}
extern "C" void fn_800443B4(Object*self){self->flags38|=0x40000000ULL;self->value60=(unsigned char)fn_8025E268(self,0);self->mode64=(unsigned char)fn_8025E268(self,1);}
