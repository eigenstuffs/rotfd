/* Recursive tree matrix refresh (fn_8023DEF8): bind the node's local matrix
   page from the active pool bank, bump the global refresh counter, combine
   with the parent (fn_8027B508), then recurse over the child/sibling list.
   CodeWarrior's automatic inlining expands the recursion three levels deep,
   which reproduces the original's out-of-line helper calls at each level:
   level 1 calls the handle leaves (C7B4/C798/C7A4), level 2 the resolver
   C2DC and pool getter E198, level 3 the handle getter C1C8 and the
   function itself.  The helpers are the extern "C" inline views already used
   by engine_owner_matrix_sync.cpp (weak copies are discarded at link).
   Needed details: E198 takes a short index (an int parameter with a short
   cast makes the pool/manager field addresses CSE into the struct base);
   the resolver returns void* and the getter casts (a Node* return keeps an
   extra temporary before the level-0 loop variable); the resolver reads the
   generation with an explicit (signed char) cast, as in
   node_hierarchy_scene_link_8023FBE4.cpp, and the sibling loop is a plain
   for loop over child->next; together they colour the level-1 sibling
   resolve like the original.
   Flags: neighbour -O4,p, -Cpp_exceptions off, -use_lmw_stmw on. */
typedef unsigned long Word;
struct Handle{signed int generation:8,index:24;};
struct Matrix{Word words[16];};
struct Node{Word unknown00[3];Handle parent,child,unknown14,next;char unknown1C[0x104];Word flags;Matrix*local,*world;short localIndex,worldIndex;};
struct Entry{void*object;Word unknown04[2];signed char generation;char unknown0D[3];};
struct Manager{int count,capacity;Entry*entries;};
struct Pool{Matrix*buffers[6];unsigned char active;};
struct Globals{char unknown00[0x118];Manager*manager;char unknown11C[0x18];Pool*pool;};
extern "C"{extern Globals lbl_801E9D24;extern int lbl_80378010;void fn_8027B508(Node*,Node*);}
extern "C"{
inline signed char fn_8023C798(const Handle*h){return h->generation;}
inline int fn_8023C7B4(const Handle*h){return h->index;}
inline Entry*fn_8023C7A4(Manager*m,unsigned int index){return m->entries+index;}
inline void*fn_8023C2DC(Manager*m,const Handle*h){int index=fn_8023C7B4(h);int generation=(signed char)fn_8023C798(h);int actual=fn_8023C7A4(m,index)->generation;if(actual==generation)return fn_8023C7A4(m,index)->object;return 0;}
inline Node*fn_8023C1C8(const Handle*h){return (Node*)fn_8023C2DC(lbl_801E9D24.manager,h);}
inline Matrix*fn_8023E198(Pool*p,short index){return p->buffers[p->active]+index;}
void fn_8023DEF8(Node*self,Node*parent){
 self->local=fn_8023E198(lbl_801E9D24.pool,self->localIndex);
 lbl_80378010++;
 fn_8027B508(self,parent);
 for(Node*child=fn_8023C1C8(&self->child);child;child=fn_8023C1C8(&child->next))fn_8023DEF8(child,self);
}
}
