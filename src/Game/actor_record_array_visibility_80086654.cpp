#include "Game/early_actor_array_copy_views.h"
struct ArrayIndex{int value;ArrayIndex(int v):value(v){}operator const int&()const{return value;}};
struct Entry_80086654{ArrayResource*object;char unknown04[8];signed char tag;char unknown0D[3];bool matchesTag(signed char t)const{return tag==t;}};
struct Entries_80086654{Entry_80086654*p;Entry_80086654&operator[](int i)const{return p[i];}};
struct Manager_80086654{int count,capacity;Entries_80086654 entries;};
struct Context_80086654{char unknown00[0x118];Manager_80086654*manager;};
inline ArrayResource*resolve_80086654(const Handle_801F7F10&h){Manager_80086654*m=reinterpret_cast<Context_80086654*>(&lbl_801E9D24)->manager;ArrayIndex index(h.bits.index);signed char tag=h.bits.tag;if(m->entries[index].matchesTag(tag))return m->entries[index].object;return 0;}
inline const Handle_801F7F10&recordHandle_80086654(const Array_80025634&a,int i){return a.data[i].handle;}
struct Actor_80086654{char unknown00[0x30];unsigned long long flags;char unknown38[0x134];Handle_801F7F10 handle;char unknown170[0x1A8];ArrayActorRecord record;char unknown324[0xE2];signed char enabled406,enabled407;};struct VisibilityController;struct Owner_80086654{char unknown00[8];Actor_80086654*actor;VisibilityController*controller;};struct VisibilityPrefix{char unknown00[8];};
struct VisibilityController:VisibilityPrefix{virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();virtual void slot8();virtual void slot9();virtual void slot10();virtual void slot11();virtual void slot12();virtual void slot13();virtual void slot14();virtual void slot15();virtual void slot16();virtual void slot17();virtual void slot18();virtual void slot19();virtual void slot20();virtual void slot21();virtual void slot22();virtual void slot23();virtual void control(int);};
struct VisibilityServicePrefix{char unknown00[0x1C];};struct VisibilityService:VisibilityServicePrefix{virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();virtual void slot8();virtual void slot9();virtual void slot10();virtual void slot11();virtual void control(int,int,int);};
struct VisibilityContext{char unknown00[0x154];VisibilityService*service;};
extern "C"void fn_80086654(Owner_80086654*self){
 Array_80025634 records(resolve_80086654(self->actor->handle)->array);
 for(short i=0;i<records.count;++i)resolve_80086654(recordHandle_80086654(records,i))->flags&=~0x40000;
 self->controller->control(0);
 ((VisibilityContext*)&lbl_801E9D24)->service->control(0,0,0);
 self->actor->flags&=~0x80000000ULL;
 if(lbl_803776B8&&lbl_803776B8->second)fn_80068158(lbl_803776B8,self->actor->record.key);
}
