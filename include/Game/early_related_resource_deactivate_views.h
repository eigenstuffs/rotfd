#ifndef GAME_EARLY_RELATED_RESOURCE_DEACTIVATE_VIEWS_H
#define GAME_EARLY_RELATED_RESOURCE_DEACTIVATE_VIEWS_H
struct Handle_801F7F10{union{unsigned long word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct DeactivatePrefix{char unknown00[8];};
struct DeactivateObject:DeactivatePrefix{virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();virtual void slot8();virtual void slot9();virtual void slot10();virtual void slot11();virtual void reset();virtual void slot13();virtual void destroy(int);virtual void slot15();virtual void slot16();char unknown0C[0x14];Handle_801F7F10 related20;char unknown24[0x14];unsigned long long flags;char unknown40[0x18];Handle_801F7F10 related58;char unknown5C[0x2C];DeactivateObject*effect;void addFlags(unsigned long long mask){flags|=mask;}void clearFlags(unsigned long long mask){flags&=~mask;}};
struct DeactivateActor{char unknown00[0x24];Handle_801F7F10 handle;char unknown28[0x2A0];signed char active;};struct DeactivateOwner{char unknown00[8];DeactivateActor*actor;};
struct DeactivateEntry{DeactivateObject*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};struct DeactivateManager{int count,capacity;DeactivateEntry*entries;};struct DeactivateScene{char unknown00[0x15058];void*mode;};struct DeactivateContext{char unknown00[0x118];DeactivateManager*manager;char unknown11C[8];DeactivateScene*scene;};
extern "C"{extern DeactivateContext lbl_801E9D24;unsigned long fn_801F948C(void*,const char*);extern const char lbl_802A0178[];void fn_80255678(DeactivateObject*);}
struct DeactivateName{unsigned long word;DeactivateName(const char*s){word=fn_801F948C(this,s);}};
struct DeactivateReturn_AE4A0:Handle_801F7F10{~DeactivateReturn_AE4A0(){}};
extern "C" DeactivateReturn_AE4A0 fn_80058778(void*,const DeactivateName&,signed char);
inline DeactivateObject*resolveDeactivate(const Handle_801F7F10&h){int index=h.bits.index;DeactivateManager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
inline void deactivateEffect(DeactivateObject*object){if(object){object->reset();object->addFlags(0x40000ULL);fn_80255678(object);object->clearFlags(0x20000ULL);}}
#endif
