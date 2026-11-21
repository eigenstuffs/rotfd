#include "Game/engine_owner_matrix_sync.h"

// Aggregate copy view; the native assignment owner uses the same 64-byte layout.
typedef unsigned long Word;
struct Handle {signed int generation:8,index:24;};
struct Matrix_8023E910 {Word words[16];};
struct Basis {Word words[9];};
struct Point {float x,y,z;};
struct Quaternion {float x,y,z,w;};
struct OwnerMatrixSyncNode {Word unknown00[3];Handle parent,child,unknown14,next;char unknown1C[0x14];Basis basis;char unknown54[0x24];Matrix_8023E910 matrix;Point position;float unknownC4;Quaternion rotation;Point scale;char unknownE4[0x3C];Word flags;Matrix_8023E910*local,*world;short localIndex,worldIndex;};
struct Entry {OwnerMatrixSyncNode*object;Word unknown04[2];signed char generation;char unknown0D[3];};
struct Manager {int count,capacity;Entry*entries;};
struct Pool {Matrix_8023E910*buffers[6];unsigned char active;};
struct Globals {char unknown00[0x118];Manager*manager;char unknown11C[0x18];Pool*pool;};
extern "C" {extern Globals lbl_801E9D24;void fn_8027B508(OwnerMatrixSyncNode*,OwnerMatrixSyncNode*);void fn_801F25E8(Matrix_8023E910*,const Point*,const Quaternion*,const Point*);void fn_801F1CD8(const Quaternion*,Basis*);}
extern "C" {
inline signed char fn_8023C798(const Handle*h){return h->generation;}
inline int fn_8023C7B4(const Handle*h){return h->index;}
inline Entry*fn_8023C7A4(Manager*m,unsigned int index){return m->entries+index;}
inline OwnerMatrixSyncNode*fn_8023C2DC(Manager*m,const Handle*h){int index=fn_8023C7B4(h);int generation=fn_8023C798(h);int actual=fn_8023C7A4(m,index)->generation;if(actual==generation)return fn_8023C7A4(m,index)->object;return 0;}
inline OwnerMatrixSyncNode*fn_8023C1C8(const Handle*h){return fn_8023C2DC(lbl_801E9D24.manager,h);}
inline Matrix_8023E910*fn_8023E198(Pool*p,int index){return p->buffers[p->active]+(short)index;}
inline void fn_8023CD28(OwnerMatrixSyncNode*n,Word flags){n->flags|=flags;}
inline void fn_8023CA70(OwnerMatrixSyncNode*n,Word flags){n->flags&=~flags;}
void fn_8023E1B4(OwnerMatrixSyncNode*self){
 self->local=fn_8023E198(lbl_801E9D24.pool,self->localIndex);
 self->world=fn_8023E198(lbl_801E9D24.pool,self->worldIndex);
 OwnerMatrixSyncNode*parent=fn_8023C1C8(&self->parent);
 if(parent)fn_8027B508(self,parent);
 else {fn_801F25E8(&self->matrix,&self->position,&self->rotation,&self->scale);*self->local=self->matrix;fn_801F1CD8(&self->rotation,&self->basis);}
 fn_8023CD28(self,0x60);
 OwnerMatrixSyncNode*child=fn_8023C1C8(&self->child);if(child)fn_8023E1B4(child);
 OwnerMatrixSyncNode*next=fn_8023C1C8(&self->next);if(next)fn_8023E1B4(next);
 fn_8023CA70(self,5);
}
}
