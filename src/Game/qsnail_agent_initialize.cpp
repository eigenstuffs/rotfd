// QSnail resource creation, handle lifetime, flags and behavior defaults.
// Reconstructed from GSQE78; names for unknown fields and virtual slots describe offsets.
typedef unsigned long u32;
typedef unsigned long long u64;
struct Handle_801F7F10 {signed long generation:8;signed long index:24;Handle_801F7F10();~Handle_801F7F10();};
struct Resource {
 char unknown[0x354];float field354;char unknown358[0xC];float field364,field368;char unknown36C[4];float field370;char unknown374[0x2C];float field3A0;
};
struct Entry {Resource*object;u32 unknown[2];signed char generation;char padding[3];};
struct Registry {int size,capacity;Entry*entries;};
struct Globals {char unknown[0x118];Registry*registry;};
extern "C" Globals lbl_801E9D24;
struct Prefix {u32 unknown[2];};
struct Agent:Prefix {
 virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();
 virtual void slot5C(int);virtual void slot60(int);
 char unknown0C[0x38-0xC];u64 flags;char unknown40[0x70-0x40];Handle_801F7F10 reference;char unknown74[0xA0-0x74];Resource*resource;
 Resource*resolve() const {Entry*entry=&lbl_801E9D24.registry->entries[reference.index];return entry->generation==reference.generation?entry->object:0;}
 void setFlags(u64 mask){flags|=mask;}
 void clearFlags(u64 mask){flags&=~mask;}
};
extern "C" {
Handle_801F7F10 fn_801B52EC(Registry*,const char*);
extern const char lbl_802A2708[];
extern const float lbl_80379608,lbl_8037960C,lbl_80379610,lbl_80379614,lbl_80379618;
void fn_8025A3C8(Agent*,const Handle_801F7F10&);
void fn_8002B780(Agent*);
void fn_800C6280(Agent*self){
 fn_8025A3C8(self,fn_801B52EC(lbl_801E9D24.registry,lbl_802A2708));
 self->resource=self->resolve();
 self->clearFlags(8);
 fn_8002B780(self);
 self->slot5C(0x85);self->slot60(0x85);
 self->setFlags(0x0000100000000000ULL);
 self->setFlags(0x0001000000000000ULL);
 self->resource->field354=lbl_80379608;
 self->resource->field364=lbl_8037960C;
 self->resource->field368=lbl_80379610;
 self->resource->field3A0=lbl_80379614;
 self->resource->field370=lbl_80379618;
}
}
