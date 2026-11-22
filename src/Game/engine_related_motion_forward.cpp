#include "Game/engine_related_motion_forward.h"

typedef unsigned long Word;
struct Handle_801F7F10 {union{Word value;struct{signed int generation:8;signed int index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Point {float x,y,z;Point(){}Point(float a,float b,float c):x(a),y(b),z(c){}Point operator+(const Point&o)const{return Point(x+o.x,y+o.y,z+o.z);}Point operator-(const Point&o)const{return Point(x-o.x,y-o.y,z-o.z);}};
struct Matrix {char unknown00[0x30];Point position;};
struct ForwardOwner {char unknown00[0x28];Handle_801F7F10*handles;char unknown2C[4];unsigned long long flags;char unknown38[0xEC];Matrix*matrix;char unknown128[0x44];Handle_801F7F10 handle16C;char unknown170[0x3C];Handle_801F7F10 related;};
struct Entry {ForwardOwner*owner;Word unknown04[2];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};
struct Manager {Word unknown00[2];Entry*entries;};
struct Property {char unknown00[0x24];Word index;};
struct PropertyContext {char unknown00[0x94];Property*property;};
struct Globals {char unknown00[0x118];Manager*manager;char unknown11C[0x28];PropertyContext*propertyContext;};
extern "C" {extern Globals lbl_801E9D24;void fn_801F86C8(Manager*,const Handle_801F7F10*,short);void slot108__12ObjectMove_ZFv(ForwardOwner*,void*,const Point*,const Point*,void*,int);}
static inline ForwardOwner*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int generation=m->entries[index].getGeneration();return generation==h.bits.generation?m->entries[index].owner:0;}
struct ForwardZeroHandle:Handle_801F7F10{ForwardZeroHandle(){value=0;}};
struct ForwardCopiedHandle:ForwardZeroHandle{ForwardCopiedHandle(const Handle_801F7F10&h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~ForwardCopiedHandle(){}};
static inline const Handle_801F7F10&getSource(ForwardOwner*self){Word index=lbl_801E9D24.propertyContext->property->index;return resolve(self->handle16C)->handles[index];}
extern "C" void slot108__9LodMove_ZFv(ForwardOwner*self,void*first,const Point*point,const Point*offset,void*fourth,int fifth){
 ForwardOwner*related=resolve(self->related);
 if(related && (related->flags&32ULL)){
  const Handle_801F7F10&source=getSource(self);
  ForwardCopiedHandle local(source);
  Matrix*matrix=resolve(local)->matrix;
  Point position(matrix->position.x,matrix->position.y,matrix->position.z);
  Point delta=position+*offset-*point;
  related->flags|=0x1000ULL;
  slot108__12ObjectMove_ZFv(related,first,&position,&delta,fourth,0);
  related->flags&=~0x1000ULL;
 }
 slot108__12ObjectMove_ZFv(self,first,point,offset,fourth,fifth);
}
