/* Linked-node reparent update with a by-value typed handle argument.
 * Private layout views; the first owner lookup reads the manager through an
 * indexed entry view, the remaining lookups through the plain entry array. */
typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct ReparentPrefix{char unknown00[8];};
struct ReparentTarget:ReparentPrefix{
virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();
virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40(int);
};
struct ReparentNode{char unknown00[0xC];Handle_801F7F10 parent;char unknown10[0x10];Handle_801F7F10 target;char unknown24[0x94];float b8,bc,c0;char unknownC4[4];float c8,cc,d0,d4;};
struct ReparentEntry{void*object;char unknown04[8];signed char tag;char unknown0D[3];bool matchesTag(signed char t)const{return tag==t;}};
struct ReparentManager{int count,capacity;ReparentEntry*entries;};
struct ReparentIndexedEntries{ReparentEntry*p;ReparentEntry&operator[](int i)const{return p[i];}};
struct ReparentIndexedManager{int count,capacity;ReparentIndexedEntries entries;};
struct ReparentGlobals{char unknown00[0x118];ReparentManager*manager;};
extern "C"{extern ReparentGlobals lbl_801E9D24;extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(ReparentManager*,const Handle_801F7F10*,short);void*fn_801F7EB8(const Handle_801F7F10*);}
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){word=0;}~Handle_8001FF78(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020B90:Handle_8001FF78{Handle_80020B90(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80020B90(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct ReparentIndex{int value;ReparentIndex(int v):value(v){}operator const int&()const{return value;}};
template<class T>inline T*resolveIndexed(const Handle_801F7F10&h){int index=h.bits.index;signed char tag=h.bits.tag;ReparentEntry*e=&((ReparentIndexedManager*)lbl_801E9D24.manager)->entries[index];return e->tag==tag?(T*)e->object:0;}
template<class T>inline T*resolve(const Handle_801F7F10&h){int index=h.bits.index;signed char tag=h.bits.tag;ReparentEntry*e=lbl_801E9D24.manager->entries+index;return e->tag==tag?(T*)e->object:0;}
template<class T>inline T*resolveChecked(const Handle_801F7F10&h){ReparentManager*m=lbl_801E9D24.manager;const ReparentIndex index(h.bits.index);signed char tag=h.bits.tag;if(m->entries[index].matchesTag(tag))return (T*)m->entries[index].object;return 0;}
struct ReparentOwner{char unknown00[0x88];Handle_801F7F10 node,parent;float f90,f94,f98,f9C,fA0,fA4,fA8;};
extern "C"{void fn_80259164(ReparentOwner*);void fn_80021624(ReparentOwner*);void fn_80240120(ReparentNode*,int);void fn_802408BC(ReparentNode*,Handle_80020B90,int);void fn_8023DE28(ReparentNode*);}
extern "C" void fn_80021388(ReparentOwner*self){
fn_80259164(self);
if(fn_801F7EB8(&self->node))resolve<ReparentTarget>(resolveIndexed<ReparentNode>(self->node)->target)->slot40(-1);
if(fn_801F7EB8(&self->parent)){
if(resolve<ReparentNode>(resolveIndexed<ReparentNode>(self->node)->parent)!=resolve<ReparentNode>(self->parent)){
ReparentNode*node=resolveChecked<ReparentNode>(self->node);ReparentNode*parent=resolveChecked<ReparentNode>(self->parent);
fn_80240120(node,0);
fn_802408BC(parent,Handle_80020B90(self->node),1);
node->b8=self->fA0;node->bc=self->fA4;node->c0=self->fA8;
node->c8=self->f90;node->cc=self->f94;node->d0=self->f98;node->d4=self->f9C;
fn_8023DE28(node);
}}
fn_80021624(self);
}
