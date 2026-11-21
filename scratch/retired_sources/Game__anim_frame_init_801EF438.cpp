/* Native animation frame construction; see docs/notes/game-anim-frame-init.md. */
typedef unsigned long Word;
extern "C" {extern char lbl_802E9D98[];extern const float lbl_8037A648;}
struct Manipulator_Z {Word unknown00[2];void*table;char unknown0C[0x20-0xC];Manipulator_Z();~Manipulator_Z();};
struct Handle_801F7F10 {Word word;Handle_801F7F10();~Handle_801F7F10();};
struct FrameInit1_EF438:Handle_801F7F10 {FrameInit1_EF438(){word=0;}~FrameInit1_EF438(){}};
struct FrameInit2_EF438:FrameInit1_EF438 {FrameInit2_EF438(int=0){word=0;}~FrameInit2_EF438(){}};
struct CurveBase_801B1088 {unsigned short flags,unknown;CurveBase_801B1088();~CurveBase_801B1088();};
struct FrameArray_EF438 {int count,capacity;void*data;FrameArray_EF438(){count=0;capacity=0;data=0;}};
struct FrameCurve_EF438:CurveBase_801B1088 {FrameArray_EF438 rows;FrameCurve_EF438(){}~FrameCurve_EF438(){}};
struct FrameCurve2_EF438:FrameCurve_EF438 {FrameCurve2_EF438(){flags=2;}~FrameCurve2_EF438(){}};
struct EmptyFrameArray_EF438 {int count,capacity;void*data;EmptyFrameArray_EF438(){}};
struct WorldActionCurve_801F7560:CurveBase_801B1088 {EmptyFrameArray_EF438 rows;WorldActionCurve_801F7560(){rows.count=0;rows.capacity=0;rows.data=0;}virtual~WorldActionCurve_801F7560();};
struct AnimFrame_801EF438:Manipulator_Z {FrameInit2_EF438 handle;Word unknown24;FrameCurve_EF438 a,b,c,d,e,f;FrameCurve2_EF438 g,h;WorldActionCurve_801F7560 action;short fieldBC;short unknownBE;float x,y,z;AnimFrame_801EF438();~AnimFrame_801EF438();};
AnimFrame_801EF438::AnimFrame_801EF438():handle((table=lbl_802E9D98,0)){fieldBC=0;x=lbl_8037A648;y=lbl_8037A648;z=lbl_8037A648;}
