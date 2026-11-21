/* Unit direction from the view node's geometry translation (row 3 of the
   4x4 matrix at node+0x124) to its child camera position (0x124),
   reconstructed from GSQE78 (fn_80077330). The view node is resolved from
   the scene record selected by the owner's view index (0x20); its child
   handle (0x1C) is resolved through a counted handle copy (extab cleanup
   __dt__15Handle_80027614Fv). The translation is built as a temporary
   Vec3 from the three matrix elements; subtracting the member Vec3 directly
   swaps the z-component register allocation. The fast normalize uses a
   minimal inline asm frsqrte (no Newton step, no frsp), which no compiler
   built-in emits. */
struct CameraIndex{int value;CameraIndex(int v):value(v){}operator const int&()const{return value;}};
typedef unsigned long Word;
inline float reciprocalSqrt(register float value){register float result;asm{frsqrte result,value}return result;}
struct Vec3{
 float x,y,z;
 Vec3(){}
 Vec3(float ax,float ay,float az):x(ax),y(ay),z(az){}
 Vec3 operator-(const Vec3&o)const{return Vec3(x-o.x,y-o.y,z-o.z);}
 Vec3&operator=(const Vec3&o){x=o.x;y=o.y;z=o.z;return *this;}
 float lengthSquared()const{return x*x+y*y+z*z;}
 Vec3&normalize(){float inv=reciprocalSqrt(lengthSquared());x*=inv;y*=inv;z*=inv;return *this;}
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
struct Owner{char unknown00[0x20];int viewIndex;};
extern "C" void fn_80077330(Owner*self,Vec3*out){
 Node*node=(Node*)resolve(lbl_801E9D24.records[self->viewIndex].handle);
 const Handle_801F7F10&input=node->child;
 Camera*camera=copyResolve(input);
 *out=camera->position-Vec3(node->geometry->m[3][0],node->geometry->m[3][1],node->geometry->m[3][2]);
 out->normalize();
}
