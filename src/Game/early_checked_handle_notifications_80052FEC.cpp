typedef unsigned long Word;
struct HandleBits{union{Word word;struct{signed int tag:8,index:24;}bits;};};
struct NodePrefix{Word unknown00,unknown04;};
struct NotifyNode:NodePrefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();};
struct Entry{NotifyNode*object;Word unknown04,unknown08;signed char tag;char unknown0D[3];};
struct Manager{int count,capacity;Entry*entries;};
struct Owner{char unknown00[0x60];HandleBits h60,h64,h68,h6C,h70,h74,h78,h7C,h80,h84,h88,h8C,h90;char unknown94[0x260];signed char enabled;char unknown2F5[3];HandleBits h2F8,h2FC,h300,h304,h308,h30C,h310;};
struct Scene{char unknown00[0x15058];Owner*owner;};
extern "C"struct Globals{char unknown00[0x118];Manager*manager;char unknown11C[8];Scene*scene;}lbl_801E9D24;
extern "C"{signed char slot1C__12BaseObject_ZFv(Owner*);void*fn_801F7EB8(const HandleBits*);}
inline NotifyNode*resolve(const HandleBits&h){int index=h.bits.index;signed char tag=h.bits.tag;Entry*e=lbl_801E9D24.manager->entries+index;return e->tag==tag?e->object:0;}
inline void notify(const HandleBits&h){if(fn_801F7EB8(&h))resolve(h)->slot1C();}
extern "C" signed char fn_80052FEC(Owner*self){if(!slot1C__12BaseObject_ZFv(self))return 0;if(self->enabled){notify(self->h60);notify(self->h68);notify(self->h2F8);notify(self->h2FC);notify(self->h300);notify(self->h304);notify(self->h308);notify(self->h30C);notify(self->h310);notify(self->h64);return 1;}return 0;}
