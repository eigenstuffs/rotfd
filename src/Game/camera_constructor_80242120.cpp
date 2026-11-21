/* Camera allocation is identified by the existing Camera_Z.h factory.
 * This bounded constructor uses the observed resource-base, eight-vector array,
 * two-layer handle, and scalar member layouts. External tables/constants remain
 * with their existing owners. */
typedef unsigned long Word;
struct CameraManager_80242120;
extern "C" {
 void*fn_80243F28(void*);
 extern const unsigned char lbl_802EC0C0[];
 extern const float lbl_8037B344,lbl_8037B348,lbl_8037B34C,lbl_8037B350,lbl_8037B354;
 struct CameraContext_80242120{char unknown00[0x118];CameraManager_80242120*manager;};
 extern CameraContext_80242120 lbl_801E9D24;
 void fn_801F86C8(CameraManager_80242120*,const void*,int);
}
struct Vector3_801D5330{float x,y,z;Vector3_801D5330();};
struct Handle_801F7F10{Word word;Handle_801F7F10();~Handle_801F7F10();};
struct HandleLayer1_80242120:Handle_801F7F10{HandleLayer1_80242120(){word=0;}~HandleLayer1_80242120(){}};
struct CameraHandle_80242120:HandleLayer1_80242120{
 CameraHandle_80242120(){word=0;}~CameraHandle_80242120(){}
 CameraHandle_80242120&operator=(const CameraHandle_80242120&other){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=other.word;fn_801F86C8(lbl_801E9D24.manager,&other,1);return*this;}
};
struct CameraBase_80242120{
 char unknown00[8];const void*table;char unknown0C[0x60];unsigned short type,flags;Word field70;
 CameraBase_80242120(const void*vt){fn_80243F28(this);table=vt;}
};
struct Camera_80242120:CameraBase_80242120{
 char unknown74[0x40];float fieldB4,fieldB8;Vector3_801D5330 corners[8];float field11C,field120,field124,field128,field12C;CameraHandle_80242120 target;
 Camera_80242120();
};
Camera_80242120::Camera_80242120():CameraBase_80242120(lbl_802EC0C0){
 type=7;field120=lbl_8037B344;field11C=lbl_8037B348;fieldB4=lbl_8037B34C;fieldB8=lbl_8037B350;
 field124=lbl_8037B344;field128=lbl_8037B344;field12C=lbl_8037B354;
 target=CameraHandle_80242120();unsigned short enabledFlags=flags;enabledFlags|=0x20;flags=enabledFlags;
}
