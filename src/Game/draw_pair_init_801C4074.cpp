/* Native DrawPair construction; see docs/notes/game-draw-pair-init.md. */
typedef unsigned long Word;
struct Manager;
extern "C"struct Context {char prefix[0x118];Manager*manager;}lbl_801E9D24;
struct Handle_801F7F10 {Word word;Handle_801F7F10();~Handle_801F7F10();};
extern "C" {
 void fn_801F86C8(Manager*,const Handle_801F7F10*,short);
 Word fn_801F948C(void*,const char*);
 extern char lbl_802E9F98[];extern const char lbl_802ACAB8[],lbl_802ACAC8[];
}
struct DrawInit1_C4074:Handle_801F7F10 {DrawInit1_C4074(){word=0;}~DrawInit1_C4074(){}};
struct DrawInit2_C4074:DrawInit1_C4074 {DrawInit2_C4074(int=0){word=0;}~DrawInit2_C4074(){}void operator=(const DrawInit2_C4074&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}};
struct DrawInit3_C4074:DrawInit2_C4074 {DrawInit3_C4074(){word=0;}~DrawInit3_C4074(){}};
struct DrawCopy_C4074:DrawInit2_C4074 {DrawCopy_C4074(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~DrawCopy_C4074(){}};
struct DrawName_C4074{Word word;DrawName_C4074(const char*s){word=fn_801F948C(this,s);}};
extern "C"Handle_801F7F10 fn_801B550C(Manager*,const DrawName_C4074&,const DrawName_C4074&);
struct DrawArray_C4074{int count,capacity;void*data;DrawArray_C4074(){count=0;capacity=0;data=0;}};
struct Manipulator_Z {Word unknown00[2];void*table;char unknown0C[0x20-0xC];Manipulator_Z();~Manipulator_Z();};
struct DrawPair_801C2F70:Manipulator_Z{Word unknown20;DrawInit2_C4074 first,second;char enabled;char pad2D[3];DrawInit3_C4074 third;DrawArray_C4074 a,b;DrawPair_801C2F70();~DrawPair_801C2F70();};
DrawPair_801C2F70::DrawPair_801C2F70():first((table=lbl_802E9F98,0)){
 enabled=0;
 second=DrawInit2_C4074();
 first=DrawInit2_C4074();
 static_cast<DrawInit2_C4074&>(third)=DrawCopy_C4074(fn_801B550C(lbl_801E9D24.manager,DrawName_C4074(lbl_802ACAC8),DrawName_C4074(lbl_802ACAB8)));
}
