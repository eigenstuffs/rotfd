#ifndef GAME_EARLY_CAMERA_STATE_VIEWS_H
#define GAME_EARLY_CAMERA_STATE_VIEWS_H

struct CameraManager;
struct CameraHandle{union{unsigned long value;struct{signed int tag:8;signed int index:24;}bits;};CameraHandle&operator=(const CameraHandle&);};
struct CameraEntry{void*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct CameraManager{int count,capacity;CameraEntry*entries;};
struct CameraContext{char unknown00[0x118];CameraManager*manager;};
extern "C" CameraContext lbl_801E9D24;
extern "C" void fn_801F86C8(CameraManager*,const CameraHandle*,int);
inline CameraHandle&CameraHandle::operator=(const CameraHandle&other){fn_801F86C8(lbl_801E9D24.manager,this,-1);value=other.value;fn_801F86C8(lbl_801E9D24.manager,&other,1);return *this;}
template<class T> inline T*resolveCamera(const CameraHandle&h){CameraEntry*entry=&lbl_801E9D24.manager->entries[h.bits.index];if(entry->tag==h.bits.tag)return (T*)entry->object;return 0;}
struct CameraObjectPrefix{char unknown00[8];};
struct CameraObject:CameraObjectPrefix{
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
virtual void slot15(int);
char unknown0C[0x4C];CameraHandle owner;};
struct CameraResource{char unknown00[0x10];CameraHandle child;};
struct CameraChild{char unknown00[0x20];CameraHandle target;};
struct CameraWrapperNode{char unknown00[0x24];CameraHandle agent;};
struct CameraWrapper{char unknown00[8];CameraWrapperNode*node;};
struct CameraPairOwner{char unknown00[0x230];CameraHandle first,second;signed char ready;};
struct CameraVector{float x,y,z;CameraVector(){} CameraVector(float a,float b,float c,float offset){b+=offset;x=a;y=b;z=c;} CameraVector(const CameraVector&v,float offset){float height=v.y;height+=offset;x=v.x;y=height;z=v.z;} CameraVector(float a,float b,float c):x(a),y(b),z(c){} CameraVector&operator=(const CameraVector&other){x=other.x;y=other.y;z=other.z;return *this;} CameraVector&operator*=(float scale){x*=scale;y*=scale;z*=scale;return *this;}};
struct CameraState{char unknown00[0xC0];float elevation;char unknownC4[4];union{int timer;float azimuth;};char unknownCC[4];int state;char unknownD4[0x20];CameraVector current,direction;char unknown10C[0xC];CameraVector desired;char unknown124[0x9C];float elevation1C0;char unknown1C4[4];float azimuth1C8;};
extern "C"{signed char fn_8025E9FC(CameraObject*,int);void fn_8025795C(CameraObject*,int,int);unsigned long fn_801F7EB8(const CameraHandle*);void fn_8007626C(CameraState*,int);void fn_80076D98(CameraState*,CameraVector*);void fn_80077D28(CameraState*,CameraVector*);float fn_8028506C(float);float fn_80284FA8(float);extern const float lbl_803789CC,lbl_803789D0,lbl_803789E8;}

#endif
