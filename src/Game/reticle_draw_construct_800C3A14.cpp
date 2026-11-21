/* Reticle draw construction; exact literal and weak callback ownership is audited separately. */
typedef unsigned long Word;
extern "C"{extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);}
struct RootPrefix{Word unknown00[2];};
struct Manipulator_Z:RootPrefix{Manipulator_Z();virtual ~Manipulator_Z();char unknown0C[0x14];};
struct ManipulatorDraw_802BC9D0:Manipulator_Z{ManipulatorDraw_802BC9D0(){}virtual ~ManipulatorDraw_802BC9D0();};
struct Handle_801F7F10{Word word;Handle_801F7F10();~Handle_801F7F10();};
struct ReticleZero:Handle_801F7F10{~ReticleZero(){}};
struct Manager;
extern "C"{struct Globals{char unknown00[0x110];void*logger;char unknown114[4];Manager*manager;char unknown11C[0x30];void*scene;};extern Globals lbl_801E9D24;void fn_801F86C8(Manager*,const void*,int);void fn_801FA014(void*,const char*,...);Word fn_801F948C(void*,const char*);extern const float lbl_80379590,lbl_80379594;}
struct Handle_800723F4:ReticleZero{Handle_800723F4();~Handle_800723F4(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}Handle_800723F4&operator=(const Handle_800723F4&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);return*this;}};
struct Name{Word word;Name(const char*s){word=fn_801F948C(this,s);}};
extern "C" Handle_800723F4 fn_802631B0(void*,const Name&);
struct Vector2_800C3BC4{float x,y;Vector2_800C3BC4();};
struct Object_800C421C:ManipulatorDraw_802BC9D0{char unknown20[8];float field28,field2C;Vector2_800C3BC4 points30[2];Handle_800723F4 handles40[3];Object_800C421C();virtual ~Object_800C421C();};
Object_800C421C::Object_800C421C(){
 fn_801FA014(lbl_801E9D24.logger,"CREATING RETICLE DRAW MANIPULATOR");
 handles40[0]=fn_802631B0(lbl_801E9D24.scene,Name("ReticleBottom"));
 handles40[1]=fn_802631B0(lbl_801E9D24.scene,Name("ReticleTop"));
 field28=lbl_80379590;field2C=lbl_80379594;
}
typedef char Object_size[(sizeof(Object_800C421C)==0x4C)?1:-1];
