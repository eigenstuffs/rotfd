/* Camera follow-position sync (fn_8007B468), reconstructed from GSQE78. The view
 * camera (scene record of viewIndex, child handle 0x1C, counted handle copy with
 * extab cleanup __dt__15Handle_80027614Fv) position at 0x124 is stored into the
 * camera follow position (0x190), then set back to it plus (0, jitter, 0). Handle
 * helpers copied from camera_offset_update_800788C4.cpp (CameraIndex/matchesTag
 * resolve shape fixes the self/global register order); the zero is the shared
 * lbl_8037899C, z read through a pointer as in camera_frame_update_8007B5AC. */
typedef unsigned long Word;
struct CameraIndex{int value;CameraIndex(int v):value(v){}operator const int&()const{return value;}};
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Entry{void*object;Word unknown04,unknown08;signed char tag;char unknown0D[3];bool matchesTag(signed char t)const{return tag==t;}};
struct EntryArray{Entry*p;Entry&operator[](int i)const{return p[i];}};
struct Manager{int count,capacity;EntryArray entries;};
struct SceneRecord{char unknown00[0x14];Handle_801F7F10 handle;char unknown18[0x34];};
extern "C" struct Globals{char unknown00[0x114];SceneRecord*records;Manager*manager;}lbl_801E9D24;
extern "C"{void fn_801F86C8(Manager*,const Handle_801F7F10*,short);void fn_801EF610(void*,void*);extern char lbl_801EF5C8[];extern const float lbl_8037899C;}
struct HandleZero:Handle_801F7F10{HandleZero(){word=0;}~HandleZero(){}};
struct Handle_80027614:HandleZero{Handle_80027614(){word=0;}~Handle_80027614(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct CameraHandle:Handle_80027614{CameraHandle(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~CameraHandle(){}};
inline void*resolve(const Handle_801F7F10&h){Manager*m=lbl_801E9D24.manager;const CameraIndex index(h.bits.index);const signed char tag=h.bits.tag;if(m->entries[index].matchesTag(tag))return m->entries[index].object;return 0;}
struct Vec{float x,y,z;Vec(){}Vec(float a,float b,float c):x(a),y(b),z(c){}Vec(const Vec&v):x(v.x),y(v.y),z(v.z){}Vec&operator=(const Vec&v){x=v.x;y=v.y;z=v.z;return*this;}Vec operator+(const Vec&v)const{return Vec(x+v.x,y+v.y,z+v.z);}};
struct ViewCamera{char unknown00[0x124];Vec position;};
struct ViewNode{char unknown00[0x1C];Handle_801F7F10 child;};
inline ViewCamera*copyResolve(const Handle_801F7F10&h){CameraHandle held(h);return (ViewCamera*)resolve(held);}
struct Camera{char unknown00[0x20];int viewIndex;char unknown24[0x168];float jitter;Vec followPosition;};
extern "C" void fn_8007B468(Camera*self,float delta){
 ViewNode*view=(ViewNode*)resolve(lbl_801E9D24.records[self->viewIndex].handle);
 const Handle_801F7F10&input=view->child;
 ViewCamera*camera=copyResolve(input);
 self->followPosition=camera->position;
 camera->position=self->followPosition+Vec(lbl_8037899C,self->jitter,*(const float*)&lbl_8037899C);
}
