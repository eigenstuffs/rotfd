/* Native record-array traversal and actor control; shared accepted Handle/Array ABI. */
#include "Game/early_actor_array_copy_views.h"
struct RecordIndex{int value;RecordIndex(int v):value(v){}operator const int&()const{return value;}};
typedef unsigned long Word;
typedef ArrayResource Resource_80087394;
struct Entry_80087394{Resource_80087394*object;char unknown04[8];signed char tag;char unknown0D[3];bool matchesTag(signed char t)const{return tag==t;}};
struct EntryArray_80087394{Entry_80087394*p;Entry_80087394&operator[](int i)const{return p[i];}};struct Manager_80087394{int count,capacity;EntryArray_80087394 entries;};
struct ControllerPrefix_80087394{char unknown00[8];};
struct Controller_80087394:ControllerPrefix_80087394{virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();virtual void slot8();virtual void slot9();virtual void slot10();virtual void slot11();virtual void slot12();virtual void slot13();virtual void slot14();virtual void slot15();virtual void slot16();virtual void slot17();virtual void slot18();virtual void slot19();virtual void slot20();virtual void slot21();virtual void slot22();virtual void slot23(); virtual void apply(int);char unknown0C[0x7C];unsigned char flag88;};
struct ServicePrefix_80087394{char unknown00[0x1C];};
struct Service_80087394:ServicePrefix_80087394{virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();virtual void slot8();virtual void slot9();virtual void slot10();virtual void slot11(); virtual void reset(int,int,int);};
struct Context_80087394{char unknown00[0x110];void*diagnostic;char unknown114[4];Manager_80087394*manager;char unknown11C[0x38];Service_80087394*service;};
struct Actor_80087394{char unknown00[0x30];unsigned long long flags;char unknown38[0x134];Handle_801F7F10 related16C;char unknown170[0x1B0];Word token320;char unknown324[0xE1];unsigned char flag405,flag406;char unknown407[7];unsigned char flag40E;};
struct Owner_80087394{char unknown00[8];Actor_80087394*actor;Controller_80087394*controller;char unknown10[0x31];unsigned char flag41;};
struct Monitor_80087394{char unknown00[0x134];Word active;};
extern "C"{void fn_801FA014(void*,const char*,...);extern const char lbl_8029D6E0[];}
inline Context_80087394&context_80087394(){return *reinterpret_cast<Context_80087394*>(&lbl_801E9D24);}
inline Resource_80087394*resolve_80087394(const Handle_801F7F10&h){Manager_80087394*m=context_80087394().manager;RecordIndex index(h.bits.index);signed char generation=h.bits.tag;if(m->entries[index].matchesTag(generation))return m->entries[index].object;return 0;}
extern "C"void fn_80087394(Owner_80087394*self){fn_801FA014(context_80087394().diagnostic,lbl_8029D6E0);
 Array_80025634 records(resolve_80087394(self->actor->related16C)->array);
 int index;for(short i=0;(index=i)<records.count;++i)resolve_80087394(records.data[index].handle)->flags&=~Word(0x40000);
 self->actor->flags|=1ULL<<36;self->controller->apply(0);self->actor->flag40E=0;self->actor->flag405=1;self->actor->flag406=1;self->controller->flag88=self->flag41;
 if(lbl_803776B8&&reinterpret_cast<Monitor_80087394*>(lbl_803776B8)->active)fn_80068158(lbl_803776B8,self->actor->token320);
}
