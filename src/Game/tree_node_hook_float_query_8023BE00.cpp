/* fn_8023BE00: recursive hierarchy float query.  Asks the valid primary hook
   (+0x1C) and then the secondary hook (+0x20) for its virtual slot-0x2C
   float; while the result is still below 0 and includeChildren is set, walks
   the first-child (+0x10) / next-sibling (+0x18) list recursively and returns
   the first nonnegative child result, else 1.0 (lbl_8037B330).
   CodeWarrior self-inlines the recursion (three visible levels); the extern
   "C" inline helpers reproduce the original out-of-line copies (fn_8023C1C0 ..
   fn_8023C2DC, owned by their own units; weak copies are discarded at link).
   Matching detail: the resolver fn_8023C2DC uses the closed helper chain of
   tree_node_flags_clear_8023C7C4.cpp / tree_node_matrix_refresh_8023DEF8.cpp
   (`int generation=(signed char)fn_8023C798(h);`), which removes the two
   outer-level `mr r27,r0` copies; both `return lbl_8037B330` tails are kept
   separate as in the original.
   Flags: -O4,p, -Cpp_exceptions off, -use_lmw_stmw on (GC/1.3.2). */
typedef unsigned long Word;
struct Handle{signed int generation:8,index:24;};
struct Object{};
struct HookPrefix{Word unknown00,unknown04;};
struct Hook:HookPrefix{
 virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual float query();
};
struct HookA:Object,Hook{};
struct HookB:Object,Hook{};
struct Node:Object{char unknown00[0x10];Handle first;char unknown14[4];Handle next;Handle a;Handle b;};
struct Entry{void*object;Word unknown04[2];signed char generation;char unknown0D[3];};
struct Manager{int count,capacity;Entry*entries;};
struct Globals{char unknown00[0x118];Manager*manager;};
extern "C"{extern Globals lbl_801E9D24;Word fn_801F7EB8(const Handle*);extern const float lbl_8037B328,lbl_8037B32C,lbl_8037B330;}
extern "C"{
inline signed char fn_8023C798(const Handle*h){return h->generation;}
inline int fn_8023C7B4(const Handle*h){return h->index;}
inline Entry*fn_8023C7A4(Manager*m,unsigned int index){return m->entries+index;}
inline void*fn_8023C2DC(Manager*m,const Handle*h){int index=fn_8023C7B4(h);int generation=(signed char)fn_8023C798(h);int actual=fn_8023C7A4(m,index)->generation;if(actual==generation)return fn_8023C7A4(m,index)->object;return 0;}
inline Node*fn_8023C1C8(const Handle*h){return (Node*)fn_8023C2DC(lbl_801E9D24.manager,h);}
inline HookB*fn_8023C214(const Handle*h){return (HookB*)fn_8023C2DC(lbl_801E9D24.manager,h);}
inline HookA*fn_8023C260(const Handle*h){return (HookA*)fn_8023C2DC(lbl_801E9D24.manager,h);}
inline signed char fn_8023C2AC(const Handle*h){return fn_801F7EB8(h)!=0;}
inline Handle*fn_8023C1C0(Node*n){return &n->next;}
float fn_8023BE00(Node*self,signed char includeChildren){
 float result=lbl_8037B328;
 if(fn_8023C2AC(&self->a))result=fn_8023C260(&self->a)->query();
 if(result<lbl_8037B32C&&fn_8023C2AC(&self->b))result=fn_8023C214(&self->b)->query();
 if(result<lbl_8037B32C){
  if(includeChildren){
   Node*child=fn_8023C1C8(&self->first);
   while(child){
    result=fn_8023BE00(child,includeChildren);
    child=fn_8023C1C8(fn_8023C1C0(child));
    if(result>=lbl_8037B32C)return result;
   }
   return lbl_8037B330;
  }
  return lbl_8037B330;
 }
 return result;
}
}
