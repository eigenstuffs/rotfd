#pragma fp_contract on
#include "Game/engine_owner_position_apply.h"

typedef unsigned long OwnerPositionWord;
struct OwnerPositionHandle {signed int generation:8,index:24;};
struct OwnerPositionPoint {float x,y,z;OwnerPositionPoint(){}const OwnerPositionPoint&get()const{return *this;}OwnerPositionPoint(float a,float b,float c):x(a),y(b),z(c){}};
struct OwnerPositionRow {float x,y,z,w;};
struct OwnerPositionMatrix {OwnerPositionRow rows[4];};
struct OwnerPositionApplyNode {OwnerPositionWord unknown00[3];OwnerPositionHandle parent;char unknown10[0xA8];OwnerPositionPoint position;char unknownC4[0x5C];OwnerPositionWord flags;OwnerPositionMatrix*local,*world;short localIndex,worldIndex;};
struct OwnerPositionEntry {OwnerPositionApplyNode*object;OwnerPositionWord unknown04[2];signed char generation;char unknown0D[3];};
struct OwnerPositionManager {int count,capacity;OwnerPositionEntry*entries;};
struct OwnerPositionMatrixPage {float words[16];};
struct OwnerPositionPool {OwnerPositionMatrixPage*buffers[6];unsigned char active;};
struct OwnerPositionGlobals {char unknown00[0x118];OwnerPositionManager*manager;char unknown11C[0x18];OwnerPositionPool*pool;};
extern "C" {extern OwnerPositionGlobals lbl_801E9D24;extern const float lbl_8037B334;void fn_801F230C(OwnerPositionMatrix*,OwnerPositionMatrix*);void fn_8023D648(OwnerPositionApplyNode*);}
static inline OwnerPositionApplyNode*resolve(const OwnerPositionHandle&h){OwnerPositionEntry*entry=&lbl_801E9D24.manager->entries[h.index];if(entry->generation==h.generation)return entry->object;return 0;}
static inline OwnerPositionPoint difference(const OwnerPositionRow&row,const OwnerPositionPoint&p){OwnerPositionPoint result(row.x-p.x,row.y-p.y,row.z-p.z);return result.get();}
static inline OwnerPositionPoint transform(const OwnerPositionMatrix&m,const OwnerPositionPoint&v){float X=m.rows[0].x*v.x+m.rows[1].x*v.y+m.rows[2].x*v.z+m.rows[3].x;float Y=m.rows[0].y*v.x+m.rows[1].y*v.y+m.rows[2].y*v.z+m.rows[3].y;float Z=m.rows[0].z*v.x+m.rows[1].z*v.y+m.rows[2].z*v.z+m.rows[3].z;return OwnerPositionPoint(X,Y,Z);}
extern "C" void fn_8023D258(OwnerPositionApplyNode*self,const OwnerPositionPoint*input){
 OwnerPositionPoint delta=difference(self->local->rows[3],*input);
 float xx=delta.x*delta.x;float yy=delta.y*delta.y;float zz=delta.z*delta.z;
 if(xx+yy+zz>lbl_8037B334){
  OwnerPositionApplyNode*parent=resolve(self->parent);
  if(parent->flags&0x20){parent->world=(OwnerPositionMatrix*)(lbl_801E9D24.pool->buffers[lbl_801E9D24.pool->active]+parent->worldIndex);fn_801F230C(parent->local,parent->world);parent->flags&=~0x20;}
  self->position=transform(*parent->world,*input);
 }
 fn_8023D648(self);
}
