typedef unsigned long Word;
struct SlotHandle{union{Word word;struct{signed int tag:8,index:24;}bits;};};
struct SlotActor{char unknown00[0x390];signed char active;char unknown391[0x33];Word state;};
struct SlotEntry{SlotActor*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct SlotManager{int count,capacity;SlotEntry*entries;};
extern "C" struct SlotGlobals{char unknown00[0x118];SlotManager*manager;}lbl_801E9D24;
struct SlotOwner{char unknown00[0x38];unsigned long long flags;char unknown40[0x30];SlotHandle handle;};
extern "C"{extern SlotOwner*lbl_803775C8;extern SlotOwner*lbl_803775CC;void*fn_8005EE10(SlotOwner*);void fn_80069654(void*,int);}
inline SlotActor*resolveSlot(const SlotHandle&h){int index=h.bits.index;SlotManager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
extern "C" void fn_8002C130(){
if(lbl_803775C8==(SlotOwner*)-1){lbl_803775C8=0;if(lbl_803775CC&&lbl_803775CC!=(SlotOwner*)-1&&!(lbl_803775CC->flags&0x2000000ULL)){SlotActor*actor=resolveSlot(lbl_803775CC->handle);actor->state=0;actor->active=0;}}
if(lbl_803775CC==(SlotOwner*)-1){lbl_803775CC=0;if(lbl_803775C8&&lbl_803775C8!=(SlotOwner*)-1&&!(lbl_803775C8->flags&0x2000000ULL)){SlotActor*actor=resolveSlot(lbl_803775C8->handle);actor->state=0;actor->active=0;}}
if(lbl_803775C8){if(!(lbl_803775C8->flags&0x2000000ULL))fn_80069654(fn_8005EE10(lbl_803775C8),0);lbl_803775C8=0;}
if(lbl_803775CC){if(!(lbl_803775CC->flags&0x2000000ULL))fn_80069654(fn_8005EE10(lbl_803775CC),0);lbl_803775CC=0;}
}
