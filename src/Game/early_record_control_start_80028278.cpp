/* Record control startup; see docs/notes/game-early-record-control-start.md. */
struct Handle_801F7F10{union{unsigned long value;struct{signed int tag:8,index:24;}bits;};};
struct ControlResource;
struct ControlPrefix{char unknown00[8];};
struct ControlResource:ControlPrefix{virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();virtual void slot8();virtual void slot9();virtual void slot10();virtual void slot11();virtual void slot12();virtual void slot13();virtual void stop(int);char unknown0C[0x14];Handle_801F7F10 related;char unknown24[0x144];char controller[0x3C];float parameter;};
struct ControlEntry{ControlResource*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct ControlManager{int count,capacity;ControlEntry*entries;};
struct ControlService{char unknown00[0x15058];void*mode;};
extern "C" struct ControlContext{char unknown00[0x110];void*logger;char unknown114[4];ControlManager*manager;char unknown11C[8];ControlService*service;}lbl_801E9D24;
inline ControlResource*resolve(const Handle_801F7F10&h){int index=h.bits.index;ControlManager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
struct ControlOwner{char unknown00[0x58];Handle_801F7F10 resource;char unknown5C[0x14];Handle_801F7F10 actor;char unknown74[8];int state;char unknown80[0x10];int mode;};
extern "C"{void fn_801FA014(void*,const char*,...);void fn_8002AF3C(ControlOwner*,int);signed char fn_80056620(void*,int);void fn_8007D6A0(void*,int);extern const char lbl_80299DC0[];extern const float lbl_80378290;}

extern "C" void fn_80028278(ControlOwner*self,int value){
 fn_801FA014(lbl_801E9D24.logger,lbl_80299DC0);
 fn_8002AF3C(self,value);
 if(!fn_80056620(lbl_801E9D24.service->mode,self->mode)){
  ControlResource*related=resolve(resolve(self->resource)->related);
  related->stop(-1);
 }
 ControlResource*actor=resolve(self->actor);
 self->state=2;
 actor->parameter=lbl_80378290;
 fn_8007D6A0(actor->controller,0);
}
