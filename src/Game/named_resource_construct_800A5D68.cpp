/* Native Object_800A6090 construction; see docs/notes/game-named-resource-construction.md. */
typedef unsigned long Word;
struct Manager;extern "C"{extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);extern char __vt__24ManipulatorDraw_802BC9D0[];extern const float lbl_80378F78,lbl_80378F7C,lbl_80378F80;extern Word lbl_803776BC;void __ct__13Manipulator_ZFv(void*);void fn_800A5F20(void*);void __construct_array(void*,void(*)(void*),void(*)(void*),unsigned long,unsigned long);void fn_800A8520(void*,int,int);void fn_801F86C8(Manager*,const void*,int);}
extern "C"struct Globals{char unknown00[0x118];Manager*manager;}lbl_801E9D24;
struct Handle_801F7F10{Word word;Handle_801F7F10();~Handle_801F7F10();};
struct Handle_80020478:Handle_801F7F10{Handle_80020478(){word=0;}~Handle_80020478(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020834:Handle_80020478{
 Handle_80020834(){word=0;}Handle_80020834(const Handle_80020478&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80020834(){}
 Handle_80020834&operator=(const Handle_80020834&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);return*this;}
};
struct Handle_800723F4:Handle_80020478{Handle_800723F4(int){word=0;}~Handle_800723F4();};
struct RootPrefix{Word unknown00[2];};
struct Manipulator_Z:RootPrefix{Manipulator_Z();virtual ~Manipulator_Z();char unknown0C[0x14];};
struct ManipulatorDraw_802BC9D0:Manipulator_Z{ManipulatorDraw_802BC9D0(){}virtual ~ManipulatorDraw_802BC9D0();};
struct Object_800A5F24{int count,capacity;void*data;Object_800A5F24(int){count=0;capacity=0;data=0;}~Object_800A5F24();};
struct Object_800A6090:ManipulatorDraw_802BC9D0{
 Object_800A5F24 pool20;Word field2C;Handle_80020834 handle30,handle34;float field38;unsigned char field3C,field3D;char unknown3E[6];unsigned char field44;char unknown45[3];Word field48;float field4C,field50,field54,field58,field5C,field60;unsigned char field64,field65;char unknown66[2];Word field68;char unknown6C[4];float field70;char unknown74[4];char records78[400*16];char unknown1978[8];Handle_800723F4 handle1980;unsigned char field1984;char unknown1985[3];Object_800A6090();virtual ~Object_800A6090();
};
Object_800A6090::Object_800A6090():pool20(0),handle1980((__construct_array(records78,fn_800A5F20,0,16,400),0)){
 field2C=6;field70=lbl_80378F78;field64=0;field65=0;field68=0;field3C=1;field3D=0;field44=0;field38=lbl_80378F78;field60=lbl_80378F78;field48=0;field4C=lbl_80378F78;field1984=0;field50=lbl_80378F7C;field54=lbl_80378F7C;field58=lbl_80378F7C;field5C=lbl_80378F80;
 fn_800A8520(this,0,2);handle34=Handle_80020834(Handle_80020478());lbl_803776BC=0;
}
typedef char Object_extent[(sizeof(Object_800A6090)==0x1988)?1:-1];
