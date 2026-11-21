/* Linked-node activation: copies the source links into the owner's handles,
 * refreshes cached node transforms and places the target 0.5 above the
 * source transform position. Private layout views; first lookups in a chain
 * read the manager through an indexed entry view.
 * The original added Vec3(0.0f,0.5f,0.0f) with pooled literals, which load
 * at each sum and are merged by the backend; raisedBy emulates that with the
 * shared .sdata2 labels, the z-sum zero using a second read form. */
typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};};
struct ActivationEntry{void*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct ActivationManager{int count,capacity;ActivationEntry*entries;};
struct ActivationIndexedEntries{ActivationEntry*p;ActivationEntry&operator[](int i)const{return p[i];}};
struct ActivationIndexedManager{int count,capacity;ActivationIndexedEntries entries;};
struct ActivationGlobals{char unknown00[0x118];ActivationManager*manager;};
extern "C"{extern ActivationGlobals lbl_801E9D24;void fn_801F86C8(ActivationManager*,const Handle_801F7F10*,short);void*fn_801F7EB8(const Handle_801F7F10*);}
struct ActivationHandle:Handle_801F7F10{void operator=(const Handle_801F7F10&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}};
template<class T>inline T*resolve(const Handle_801F7F10&h){ActivationEntry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)return (T*)e->object;return 0;}
template<class T>inline T*resolveLocal(const Handle_801F7F10&h){int index=h.bits.index;signed char tag=h.bits.tag;ActivationEntry*e=lbl_801E9D24.manager->entries+index;return e->tag==tag?(T*)e->object:0;}
template<class T>inline T*resolveIndexed(const Handle_801F7F10&h){int index=h.bits.index;signed char tag=h.bits.tag;ActivationEntry*e=&((ActivationIndexedManager*)lbl_801E9D24.manager)->entries[index];return e->tag==tag?(T*)e->object:0;}
extern "C"{extern const float lbl_80378218;extern const float lbl_80378224;}
struct Vec3{float x,y,z;Vec3 raisedBy(float height)const{return Vec3(x+lbl_80378218,y+height,z+*(const float*)&lbl_80378218);}Vec3(float a,float b,float c){x=a;y=b;z=c;}Vec3(const Vec3&v){x=v.x;y=v.y;z=v.z;}void set(float a,float b,float c){x=a;y=b;z=c;}Vec3&operator=(const Vec3&v){set(v.x,v.y,v.z);return *this;}};
struct ActivationTransform{char unknown00[0x30];Vec3 position;};
struct ActivationPrefix{char unknown00[8];};
struct ActivationTarget:ActivationPrefix{
virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();
virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40(int);
};
struct ActivationKind{char unknown00[0x6C];unsigned short kind;};
struct ActivationLink{char unknown00[0x1C];Handle_801F7F10 kind;};
struct ActivationSource{char unknown00[0xC];Handle_801F7F10 node,link;char unknown14[0x110];ActivationTransform*transform;};
struct ActivationNode{char unknown00[0xC];Handle_801F7F10 parent;char unknown10[0xC];Handle_801F7F10 kind;Handle_801F7F10 target;char unknown24[0x94];float b8,bc,c0;char unknownC4[4];float c8,cc,d0,d4;};
struct ActivationActor{char unknown00[0x30];unsigned long long flags;};
struct ActivationOwner{char unknown00[0x58];Handle_801F7F10 source;char unknown5C[0x14];Handle_801F7F10 actor;char unknown74[0x14];ActivationHandle node,parent;float f90,f94,f98,f9C,fA0,fA4,fA8;Vec3 target;char unknownB8[4];ActivationHandle link;};
extern "C" void fn_80259008(ActivationOwner*);
extern "C" void fn_80021CB4(ActivationOwner*self){
fn_80259008(self);
if(fn_801F7EB8(&resolve<ActivationSource>(self->source)->link)){
if(fn_801F7EB8(&resolve<ActivationLink>(resolveIndexed<ActivationSource>(self->source)->link)->kind)){
self->link=resolve<ActivationSource>(self->source)->node;
self->node=resolve<ActivationSource>(self->source)->link;
if(fn_801F7EB8(&resolve<ActivationNode>(self->node)->target)){
resolve<ActivationTarget>(resolveIndexed<ActivationNode>(self->node)->target)->slot40(-1);
if(resolve<ActivationKind>(resolveIndexed<ActivationNode>(self->node)->kind)->kind==4){
ActivationNode*n=resolveLocal<ActivationNode>(self->node);
self->f90=n->c8;self->f94=n->cc;self->f98=n->d0;self->f9C=n->d4;
n=resolve<ActivationNode>(self->node);
self->fA0=n->b8;self->fA4=n->bc;self->fA8=n->c0;
self->parent=resolve<ActivationNode>(self->node)->parent;
}
Vec3 p=resolve<ActivationSource>(self->source)->transform->position;
self->target=Vec3(p).raisedBy(lbl_80378224);
}}}
resolve<ActivationActor>(self->actor)->flags&=~0x200ULL;
}
