typedef unsigned long Word;
extern "C" {extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(void*,const void*,int);}
struct Globals_8002D2F8{char unknown00[0x118];void*manager;char unknown11C[0x48];void*service;};extern "C" Globals_8002D2F8 lbl_801E9D24;
struct Handle_801F7F10{Word value;Word&word(){return value;}Handle_801F7F10();~Handle_801F7F10();};
struct ResourceZero_8002D2F8:Handle_801F7F10{ResourceZero_8002D2F8(){value=0;}~ResourceZero_8002D2F8(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80021BCC:ResourceZero_8002D2F8{Handle_80021BCC(){value=0;}~Handle_80021BCC(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_8002D590:Handle_80021BCC{Handle_8002D590(const Handle_801F7F10&v){value=v.value;fn_801F86C8(lbl_801E9D24.manager,&v,1);}~Handle_8002D590(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}Handle_8002D590&operator=(const Handle_8002D590&v){fn_801F86C8(lbl_801E9D24.manager,this,-1);value=v.value;fn_801F86C8(lbl_801E9D24.manager,&v,1);return *this;}};
struct SceneZero_8002D2F8:Handle_801F7F10{SceneZero_8002D2F8(){word()=0;}~SceneZero_8002D2F8(){}};
struct SceneBase_8002D2F8:SceneZero_8002D2F8{SceneBase_8002D2F8(){value=0;}~SceneBase_8002D2F8(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_8002D518:SceneBase_8002D2F8{Handle_8002D518(){value=0;}};
struct Handle_8002D49C:Handle_8002D518{Handle_8002D49C(const Handle_801F7F10&v){value=v.value;fn_801F86C8(lbl_801E9D24.manager,&v,1);}Handle_8002D49C(const Handle_8002D49C&v){value=v.value;fn_801F86C8(lbl_801E9D24.manager,&v,1);}~Handle_8002D49C(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020478:Handle_801F7F10{Handle_80020478(const Handle_801F7F10&v){value=v.value;fn_801F86C8(lbl_801E9D24.manager,&v,1);}~Handle_80020478(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct OwnerPrefix_8002D2F8{Word unknown00;Handle_801F7F10 member;};
struct Owner_8002D2F8:OwnerPrefix_8002D2F8{
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
virtual void slot14();
virtual void slot15();
virtual void slot16();
virtual void slot17();
virtual void slot18();
virtual void slot19();
virtual void slot20();
virtual void slot21();
virtual void slot22();
virtual void slot23();
virtual void slot24();
virtual void slot25();
virtual void slot26();
virtual void slot27();
virtual void slot28();
virtual void slot29();
virtual void slot30();
virtual void slot31();
virtual void slot32();
virtual void reset(int,int);char unknown0C[0x54];Handle_8002D590 resource;
};
extern "C" {void fn_8025C3B4(Owner_8002D2F8*);Handle_801F7F10 fn_801B52EC(void*,const char*);void fn_800B6DA8(void*,Word,int,Handle_80020478);extern const char lbl_80378358[8];extern Word lbl_803777B0;}
extern "C" void fn_8002D2F8(Owner_8002D2F8*self){
fn_8025C3B4(self);self->resource=Handle_8002D590(fn_801B52EC(lbl_801E9D24.manager,lbl_80378358));
const Handle_801F7F10&original=self->member;Handle_8002D49C handle=Handle_8002D49C(original);void*service=lbl_801E9D24.service;fn_800B6DA8(service,lbl_803777B0,0,Handle_80020478(handle));self->reset(0,0);
}
