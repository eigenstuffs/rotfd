typedef unsigned long Word;
struct Handle_8002A900{signed int generation:8,index:24;};
struct SetupIntermediate_8002A900{char unknown00[0x20];Handle_8002A900 child;};
struct SetupChildPrefix_8002A900{char unknown00[8];};
struct SetupChild_8002A900:SetupChildPrefix_8002A900{
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual void slot8();
virtual void slot9();
virtual void slot10();
virtual void slot11();
virtual void slot12();
virtual void slot13();
virtual void reset(int);};
struct SetupActor_8002A900{char unknown00[0x168];char component[0x3C];float timer;};
struct SetupIntermediateEntry_8002A900{SetupIntermediate_8002A900*object;char unknown04[8];signed char generation;char unknown0D[3];};
struct SetupChildEntry_8002A900{SetupChild_8002A900*object;char unknown04[8];signed char generation;char unknown0D[3];};
struct SetupActorEntry_8002A900{SetupActor_8002A900*object;char unknown04[8];signed char generation;char unknown0D[3];};
struct SetupIntermediateManager_8002A900{int count,capacity;SetupIntermediateEntry_8002A900*entries;};
struct SetupChildManager_8002A900{int count,capacity;SetupChildEntry_8002A900*entries;};
struct SetupActorManager_8002A900{int count,capacity;SetupActorEntry_8002A900*entries;};
struct SetupScene_8002A900{char unknown00[0x15058];void*active;};
struct SetupGlobals_8002A900{char unknown00[0x110];void*logger;char unknown114[4];SetupIntermediateManager_8002A900*manager;char unknown11C[8];SetupScene_8002A900*scene;};
extern "C" SetupGlobals_8002A900 lbl_801E9D24;
struct SetupOwnerPrefix_8002A900{char unknown00[8];};
struct SetupOwner_8002A900:SetupOwnerPrefix_8002A900{
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual void slot8();
virtual void slot9();
virtual void reset();char unknown0C[0x2C];unsigned long long flags;char unknown40[0x18];Handle_8002A900 owner;char unknown5C[0x14];Handle_8002A900 actor;char unknown74[8];int state;float first,second,third;int index;};
extern "C" {void fn_801FA014(void*,const char*,...);void fn_8002AF3C(SetupOwner_8002A900*,int);signed char fn_80056570(void*,int*);void fn_802139D8(SetupActor_8002A900*);void fn_8007D6A0(void*,int);extern const char lbl_80299ED8[];extern const float lbl_80378308,lbl_8037830C,lbl_80378310;}
inline SetupIntermediate_8002A900*resolveIntermediate_8002A900(const Handle_8002A900&h){SetupIntermediateEntry_8002A900*e=lbl_801E9D24.manager->entries+h.index;if(e->generation==h.generation)return e->object;return 0;}
inline SetupChild_8002A900*resolveChild_8002A900(const Handle_8002A900&h){SetupChildManager_8002A900*m=(SetupChildManager_8002A900*)lbl_801E9D24.manager;SetupChildEntry_8002A900*e=m->entries+h.index;if(e->generation==h.generation)return e->object;return 0;}
inline SetupActor_8002A900*resolveActor_8002A900(const Handle_8002A900&h){SetupActorManager_8002A900*m=(SetupActorManager_8002A900*)lbl_801E9D24.manager;SetupActorEntry_8002A900*e=m->entries+h.index;if(e->generation==h.generation)return e->object;return 0;}
extern "C" void fn_8002A900(SetupOwner_8002A900*self,int argument){
fn_801FA014(lbl_801E9D24.logger,lbl_80299ED8);fn_8002AF3C(self,argument);int index;void*active=lbl_801E9D24.scene->active;index=-1;
if(!fn_80056570(active,&index)){
resolveChild_8002A900(resolveIntermediate_8002A900(self->owner)->child)->reset(-1);self->flags|=0x40000ULL;fn_802139D8(resolveActor_8002A900(self->actor));self->reset();}
self->index=index;SetupActor_8002A900*actor=resolveActor_8002A900(self->actor);actor->timer=lbl_80378308;fn_8007D6A0(actor->component,0);self->state=2;self->first=lbl_8037830C;self->second=lbl_80378310;self->third=lbl_8037830C;
}
