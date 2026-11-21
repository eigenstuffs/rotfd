/* fn_8023C31C: forward a float to virtual slot 0x28 of the objects behind a
   scene node's two typed handles (+0x1C, +0x20) and, when recursive, of every
   node in its child tree (first child handle +0x10, next sibling +0x18).
   CodeWarrior self-inlines the recursion; the extern "C" inline helpers
   reproduce the original out-of-line copies (fn_8023C1C0 .. fn_8023C7B4,
   owned by their own units; weak copies are discarded at link).
   Matching detail: the resolver fn_8023C2DC reads the generation as
   `int generation=(signed char)fn_8023C798(h);` (explicit cast on an
   already signed char value; it fixes all three partially inlined resolve
   blocks and the stmw r25 range), the same helper chain as
   tree_node_matrix_refresh_8023DEF8.cpp.
   Flags: -O4,p, -Cpp_exceptions off, -use_lmw_stmw on (GC/1.3.2). */
typedef unsigned long Word;
struct Handle{signed int generation:8,index:24;};
struct Object{};
struct TargetPrefix{Word unknown00,unknown04;};
struct Target:TargetPrefix{
    virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();
    virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();
    virtual void slot28(float);
};
struct TargetA:Object,Target{};
struct TargetB:Object,Target{};
struct Node:Object{char unknown00[0x10];Handle first;char unknown14[4];Handle next;Handle a;Handle b;};
struct Entry{void*object;Word unknown04[2];signed char generation;char unknown0D[3];};
struct Manager{int count,capacity;Entry*entries;};
struct Globals{char unknown00[0x118];Manager*manager;};
extern "C"{extern Globals lbl_801E9D24;Word fn_801F7EB8(const Handle*);}
extern "C"{
inline signed char fn_8023C798(const Handle*h){return h->generation;}
inline int fn_8023C7B4(const Handle*h){return h->index;}
inline Entry*fn_8023C7A4(Manager*m,unsigned int index){return m->entries+index;}
inline void*fn_8023C2DC(Manager*m,const Handle*h){int index=fn_8023C7B4(h);int generation=(signed char)fn_8023C798(h);int actual=fn_8023C7A4(m,index)->generation;if(actual==generation)return fn_8023C7A4(m,index)->object;return 0;}
inline Node*fn_8023C1C8(const Handle*h){return (Node*)fn_8023C2DC(lbl_801E9D24.manager,h);}
inline TargetB*fn_8023C214(const Handle*h){return (TargetB*)fn_8023C2DC(lbl_801E9D24.manager,h);}
inline TargetA*fn_8023C260(const Handle*h){return (TargetA*)fn_8023C2DC(lbl_801E9D24.manager,h);}
inline signed char fn_8023C2AC(const Handle*h){return fn_801F7EB8(h)!=0;}
inline Handle*fn_8023C1C0(Node*n){return &n->next;}
void fn_8023C31C(Node*self,signed char recursive,float value){
 if(fn_8023C2AC(&self->a))fn_8023C260(&self->a)->slot28(value);
 if(fn_8023C2AC(&self->b))fn_8023C214(&self->b)->slot28(value);
 if(recursive){
  for(Node*child=fn_8023C1C8(&self->first);child;child=fn_8023C1C8(fn_8023C1C0(child)))fn_8023C31C(child,recursive,value);
 }
}
}
