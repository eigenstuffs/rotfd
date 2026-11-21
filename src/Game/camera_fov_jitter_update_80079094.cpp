struct CameraIndex{int value;CameraIndex(int v):value(v){}operator const int&()const{return value;}};
/* Camera field-of-view jitter and decay, reconstructed from GSQE78. */
typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Node{char unknown00[0x1C];Handle_801F7F10 child;char unknown20[0xFC];float fov;};
struct Entry{Node*object;Word unknown04,unknown08;signed char tag;char unknown0D[3];signed char getTag()const{return tag;}bool matchesTag(signed char t)const{return tag==t;}};
struct EntryArray{Entry*p;Entry&operator[](int i)const{return p[i];}};struct Manager{int count,capacity;EntryArray entries;};
struct SceneRecord{char unknown00[0x14];Handle_801F7F10 handle;char unknown18[0x34];};
extern "C" struct Globals{char unknown00[0x114];SceneRecord*records;Manager*manager;}lbl_801E9D24;
extern "C"{void fn_801F86C8(Manager*,const Handle_801F7F10*,short);void fn_801EF610(void*,void*);extern char lbl_801EF5C8[];float fn_801F1200();int fn_801F1224(int,int);extern const float lbl_803789C4,lbl_803789C8,lbl_8037899C,lbl_803789E8;}
struct JitterZero:Handle_801F7F10{JitterZero(){word=0;}~JitterZero(){}};
struct Handle_80027614:JitterZero{Handle_80027614(){word=0;}~Handle_80027614(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct JitterCameraHandle:Handle_80027614{JitterCameraHandle(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~JitterCameraHandle(){}};
inline Node*resolve(const Handle_801F7F10&h){Manager*m=lbl_801E9D24.manager;const CameraIndex index(h.bits.index);const signed char tag=h.bits.tag;if(m->entries[index].matchesTag(tag))return m->entries[index].object;return 0;}
inline Node*copyResolve(const Handle_801F7F10&h){JitterCameraHandle held(h);return resolve(held);}
struct Owner{char unknown00[0x20];int viewIndex;char unknown24[0xA4];int baseFov;char unknownCC[4];int mode;char unknownD4[0xAC];signed char active;char unknown181[3];float duration,amplitude,jitter;};
inline float scaledJitter(float value,const float&amplitude){return value*amplitude;}
extern "C" void fn_80079094(Owner*self,float delta){
 if(self->mode==0)self->baseFov=70;
 else if(self->mode==1&&self->baseFov>10){self->baseFov-=5;if(self->baseFov<10)self->baseFov=10;}
 self->jitter=scaledJitter(fn_801F1200()-lbl_803789C4,self->amplitude);
 int range=lbl_803789C8*self->amplitude;
 int random=fn_801F1224((short)-range,(short)range);
 if(self->duration>=lbl_8037899C){self->duration-=delta;if(self->duration<=lbl_8037899C){self->active=0;self->duration=lbl_8037899C;self->amplitude=lbl_8037899C;self->jitter=lbl_8037899C;}}
 int fov=self->baseFov+random;
 const Handle_801F7F10&input=resolve(lbl_801E9D24.records[self->viewIndex].handle)->child;
 Node*camera=copyResolve(input);
 camera->fov=lbl_803789E8*(float)fov;
}
