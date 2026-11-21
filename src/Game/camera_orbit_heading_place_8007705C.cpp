/* Camera yaw/orbit placement (fn_8007705C). In mode 4 (and modes 1/2 after the
   heading update) the camera target (0x118) is reset to the home position
   (0x1A8) and copied to the current position (0xF4). Otherwise the view node is
   resolved from the scene record selected by the view index (0x20) and its
   child camera through a counted handle copy (extab cleanup
   __dt__15Handle_80027614Fv, same shapes as fn_80077330). The planar heading
   from the current position to the child camera position (atan2 fn_80285124,
   0 when both deltas are zero) is scaled to degrees and wrapped into
   (0, 180]; modes 2/3 report it (event 0x91, fn_802073E8). Modes other than
   1/2 then place the target on a circle (radius lbl_803789F0) around the view
   node's translation row at heading + 180, raise the position by lbl_803789A8
   and copy the target to the position. Always finishes with
   fn_8007626C(self, 0).

   Register-allocation notes: the view node resolve sits in an inline helper
   (otherwise self loses r31); the delta vector starts as a copy of the
   current position (d.x = camera.x - d.x) so the subtraction result reuses
   the subtrahend register; the translation Vec3 is assigned before the orbit
   angle is computed; the 360 constant (lbl_80378998) is reread through a
   pointer for every use except the first comparison, as in
   early_motion_angle_gate_800768C0. */
struct CameraIndex{int value;CameraIndex(int v):value(v){}operator const int&()const{return value;}};
typedef unsigned long Word;
struct Vec3{
 float x,y,z;
 Vec3(){}
 Vec3(float ax,float ay,float az):x(ax),y(ay),z(az){}
 Vec3(const Vec3&o):x(o.x),y(o.y),z(o.z){}
 Vec3&operator=(const Vec3&o){x=o.x;y=o.y;z=o.z;return *this;}
};
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Geometry{float m[4][4];};
struct Node{char unknown00[0x1C];Handle_801F7F10 child;char unknown20[0x104];Geometry*geometry;};
struct Camera{char unknown00[0x124];Vec3 position;};
struct Entry{void*object;Word unknown04,unknown08;signed char tag;char unknown0D[3];signed char getTag()const{return tag;}bool matchesTag(signed char t)const{return tag==t;}};
struct EntryArray{Entry*p;Entry&operator[](int i)const{return p[i];}};struct Manager{int count,capacity;EntryArray entries;};
struct SceneRecord{char unknown00[0x14];Handle_801F7F10 handle;char unknown18[0x34];};
extern "C" struct Globals{char unknown00[0x114];SceneRecord*records;Manager*manager;}lbl_801E9D24;
extern "C"{void fn_801F86C8(Manager*,const Handle_801F7F10*,short);void fn_801EF610(void*,void*);extern char lbl_801EF5C8[];}
struct HandleZero:Handle_801F7F10{HandleZero(){word=0;}~HandleZero(){}};
struct Handle_80027614:HandleZero{Handle_80027614(){word=0;}~Handle_80027614(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct CameraHandle:Handle_80027614{CameraHandle(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~CameraHandle(){}};
inline void*resolve(const Handle_801F7F10&h){Manager*m=lbl_801E9D24.manager;const CameraIndex index(h.bits.index);const signed char tag=h.bits.tag;if(m->entries[index].matchesTag(tag))return m->entries[index].object;return 0;}
inline Camera*copyResolve(const Handle_801F7F10&h){CameraHandle held(h);return (Camera*)resolve(held);}
struct Owner{
 char unknown00[0x20];
 int viewIndex;
 char unknown24[0xD0-0x24];
 int mode;
 char unknownD4[0xF4-0xD4];
 Vec3 position;
 char unknown100[0x118-0x100];
 Vec3 target;
 char unknown124[0x1A8-0x124];
 Vec3 home;
};
extern "C"{
float fn_80285124(float,float);float fn_8028506C(float);float fn_80284FA8(float);
void*fn_8005E9A0();void fn_802073E8(Owner*,int,void*,float);void fn_8007626C(Owner*,int);
extern const float lbl_80378998,lbl_8037899C,lbl_803789A0,lbl_803789A8,lbl_803789E8,lbl_803789EC,lbl_803789F0;
}
inline float heading(float x,float z){float r=lbl_8037899C;if(r!=z||r!=x)r=fn_80285124(x,z);return r;}
inline Node*viewNode(Owner*o){return (Node*)resolve(lbl_801E9D24.records[o->viewIndex].handle);}
extern "C" void fn_8007705C(Owner*self){
 if(self->mode==4){
  self->target=self->home;
  self->position=self->target;
 }else{
  Node*node=viewNode(self);
  const Handle_801F7F10&input=node->child;
  Camera*camera=copyResolve(input);
  Vec3 d=self->position;
  d.x=camera->position.x-d.x;
  d.z=camera->position.z-d.z;
  float yaw=lbl_803789EC*heading(d.x,d.z);
  if(yaw>=lbl_80378998)yaw-=*(const float*)&lbl_80378998;
  if(yaw<=lbl_8037899C)yaw+=*(const float*)&lbl_80378998;
  if(yaw>lbl_803789A0)yaw-=*(const float*)&lbl_80378998;
  if(self->mode==2||self->mode==3)fn_802073E8(self,0x91,fn_8005E9A0(),lbl_803789E8*yaw);
  if(self->mode==1||self->mode==2){
   self->target=self->home;
   self->position=self->target;
  }else{
   self->target=Vec3(node->geometry->m[3][0],node->geometry->m[3][1],node->geometry->m[3][2]);
   float a=lbl_803789E8*(lbl_803789A0+yaw);
   float s=fn_80284FA8(a);
   self->target.x=lbl_803789F0*s+self->target.x;
   float c=fn_8028506C(a);
   self->target.z=lbl_803789F0*c+self->target.z;
   self->position.y+=lbl_803789A8;
   self->position=self->target;
  }
 }
 fn_8007626C(self,0);
}
