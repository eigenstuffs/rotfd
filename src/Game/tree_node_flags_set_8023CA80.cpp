/* fn_8023CA80: set flag bits (word +0x120) on a scene node and, when
   recursive, on its whole child tree (first child handle +0x10, next sibling
   handle +0x18).  CodeWarrior self-inlines the recursion; the extern "C"
   inline helpers reproduce the original out-of-line copies (fn_8023C1C0 ..
   fn_8023CD28, owned by their own units; weak copies are discarded at link).
   Matching detail: the resolver fn_8023C2DC reads the generation as
   `int generation=(signed char)fn_8023C798(h);` (explicit cast on an
   already signed char value fixes the deepest sibling resolve colouring),
   the same helper chain as tree_node_matrix_refresh_8023DEF8.cpp.
   Flags: -O4,p, -Cpp_exceptions off, -use_lmw_stmw on (GC/1.3.2). */
typedef unsigned long Word;
struct Handle{signed int generation:8,index:24;};
struct Node{char unknown00[0x10];Handle first;char unknown14[4];Handle next;char unknown1C[0x120-0x1C];Word flags;};
struct Entry{void*object;Word unknown04[2];signed char generation;char unknown0D[3];};
struct Manager{int count,capacity;Entry*entries;};
struct Globals{char unknown00[0x118];Manager*manager;};
extern "C"{extern Globals lbl_801E9D24;}
extern "C"{
inline signed char fn_8023C798(const Handle*h){return h->generation;}
inline int fn_8023C7B4(const Handle*h){return h->index;}
inline Entry*fn_8023C7A4(Manager*m,unsigned int index){return m->entries+index;}
inline void*fn_8023C2DC(Manager*m,const Handle*h){int index=fn_8023C7B4(h);int generation=(signed char)fn_8023C798(h);int actual=fn_8023C7A4(m,index)->generation;if(actual==generation)return fn_8023C7A4(m,index)->object;return 0;}
inline Node*fn_8023C1C8(const Handle*h){return (Node*)fn_8023C2DC(lbl_801E9D24.manager,h);}
inline Handle*fn_8023C1C0(Node*n){return &n->next;}
inline void fn_8023CD28(Node*n,Word flags){n->flags|=flags;}
void fn_8023CA80(Node*self,Word flags,signed char recursive){
 fn_8023CD28(self,flags);
 if(recursive){
  for(Node*child=fn_8023C1C8(&self->first);child;child=fn_8023C1C8(fn_8023C1C0(child)))fn_8023CA80(child,flags,1);
 }
}
}
