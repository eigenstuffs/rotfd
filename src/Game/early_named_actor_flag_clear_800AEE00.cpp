typedef unsigned long Word;
extern "C" {Word fn_801F948C(void*,const char*);extern const char lbl_802A0178[];}
struct FlagName {Word word;FlagName(const char*s){word=fn_801F948C(this,s);}};
struct Handle_801F7F10 {union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct FlagReturn_800AEE00:Handle_801F7F10 {FlagReturn_800AEE00();~FlagReturn_800AEE00(){}};
struct FlagResource {char unknown00[0x38];unsigned long long flags;};
struct FlagEntry {FlagResource*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct FlagManager {int count,capacity;FlagEntry*entries;};
struct FlagScene {char unknown00[0x15058];void*screen;};
extern "C" struct FlagContext {char unknown00[0x118];FlagManager*manager;char unknown11C[8];FlagScene*scene;}lbl_801E9D24;
extern "C" {FlagReturn_800AEE00 fn_80058778(void*,const FlagName&,signed char);void fn_80255678(FlagResource*);}
inline FlagResource*resolve(const Handle_801F7F10&h){int index=h.bits.index;FlagManager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
extern "C" void fn_800AEE00(void*) {
    FlagResource* resource;
    {
        FlagName name(lbl_802A0178);
        resource = resolve(fn_80058778(lbl_801E9D24.scene->screen, name, 0));
    }
    if (resource) {
        fn_80255678(resource);
        resource->flags |= 0x40000ULL;
        resource->flags &= ~0x20000ULL;
    }
}
