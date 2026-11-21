/* fn_80211A10: builds an event context from the manipulator's camera/target
 * handles, then copies it per bound object and dispatches it.
 * The per-object copy goes through the implicit Context::operator= on a cast
 * lvalue (*(Context*)&copy = context): a plain copy=context mis-schedules the
 * copy ctor's __construct_array arguments, dst=src (references) moves the
 * loop-invariant flags spill, and member-wise copies swap memmove args. */
typedef unsigned long Word;
struct Vec3 {float x,y,z;Vec3(const Vec3&p):x(p.x),y(p.y),z(p.z){}Vec3&operator=(const Vec3&p){x=p.x;y=p.y;z=p.z;return *this;}};
extern "C" {
extern const Vec3 game_vec4_zero;
extern const float lbl_8037AC18;
void fn_801E15A0(void*);
void __construct_array(void*,void(*)(void*),void(*)(void*),unsigned int,unsigned int);
Word fn_801F7EB8(const void*);
void fn_801F86C8(void*,const void*,int);
void fn_801F7914(void*,const void*);
void fn_8023DE28(void*);
void*memmove(void*,const void*,unsigned long);
}

struct Handle {union{Word word;struct{signed int tag:8,index:24;}bits;};};
struct Entry {void*object;char unknown04[8];signed char tag;char pad[3];signed char getTag()const{return tag;}};
struct Manager {char unknown00[8];Entry*entries;};
struct Global14C {char unknown00[0x28C];Handle handle;};
extern "C" struct Global {char unknown00[0x118];Manager*manager;char unknown11C[0x30];Global14C*owner;} lbl_801E9D24;
inline void*resolve(const Handle&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;
    int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}

template<class T>inline T*resolveT(const Handle&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;
    int tag=m->entries[index].getTag();if(tag==h.bits.tag)return (T*)m->entries[index].object;return 0;}
struct Handle_801F7F10 {Word word;Handle_801F7F10();~Handle_801F7F10();
    Handle_801F7F10&operator=(const Handle_801F7F10&o){fn_801F7914(this,&o);return *this;}};

struct Sphere {Vec3 center;float radius;Sphere(const Vec3&p=game_vec4_zero,float r=lbl_8037AC18):center(p),radius(r){}};
struct PtrArray {void*items[64];int count;PtrArray():count(0){}
    PtrArray&operator=(const PtrArray&o){int n=o.count;count=n;memmove(items,o.items,n*sizeof(void*));return *this;}
    void push(void*p){if((unsigned int)count<64){items[count]=p;count++;}}};
struct Element {char unknown00[0x24];};
struct ElementArray {Element items[64];int count;
    ElementArray(){__construct_array(items,fn_801E15A0,0,sizeof(Element),64);count=0;}
    ElementArray&operator=(const ElementArray&o){count=o.count;memmove(items,o.items,count*sizeof(Element));return *this;}};
struct Matrix {Word m[16];};
struct Block100 {char data[0x100];};
struct Header {void*target;Word index;void*parent;void*camera;void*object;void*secondary;void*extra;Word mode;};
struct Words16 {Word w[16];};
struct Words6 {Word w[6];};
struct Context {Header h;Matrix matrix;Words16 w60;
    Sphere first,second;PtrArray ptrs;ElementArray elements;Word tailZero;Block100 block;Words6 t;Handle_801F7F10 handle;
    Context():second(*(const Vec3*)&game_vec4_zero,*(const float*)&lbl_8037AC18){h.object=0;h.target=0;h.parent=0;h.secondary=0;h.extra=0;tailZero=0;}};

struct Node {char unknown00[0x1C];Handle parent;};
struct Target {char unknown00[0x14];Handle handle;
    void assign(const Handle&h){fn_801F86C8(lbl_801E9D24.manager,&handle,-1);handle.word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}};
struct Prefix8 {char unknown00[8];};
struct Receiver:Prefix8 {
    virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();
    virtual void receive(Context*,struct Listener*);};
struct Listener:Prefix8 {
    virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();
    virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();
    virtual void notify(Context*);
    Word mask;};
struct Bound {char unknown00[0x1C];Handle receiver;Handle listener;Handle secondary;Handle extra;char unknown2C[0xF4];Word flags;Matrix*matrix;};
struct Manipulator {char unknown00[0x18];signed char enabled;char unknown19[0x1F];int count;char unknown3C[4];Handle*bound;Handle owner;Handle camera;int index;Handle secondary;Handle extras[3];};

extern "C" void fn_80211A10(Manipulator*self,Target*target){
    if(self->enabled&&target){
    Context context;
    context.h.index=self->index;
    Word mask=0x20<<self->index;
    context.h.target=target;
    if(!fn_801F7EB8(&target->handle))((Target*)context.h.target)->assign(self->camera);
    Node*camera=(Node*)resolve(self->camera);
    context.h.camera=camera;
    context.h.parent=resolve(camera->parent);
    if(fn_801F7EB8(&self->secondary))context.h.secondary=resolve(((Node*)resolve(self->secondary))->parent);
    else context.h.secondary=0;
    void*special=resolve(lbl_801E9D24.owner->handle);
    context.ptrs.count=0;
    for(int i=0;i<3;i++){
        if(fn_801F7EB8(&self->extras[i]))context.ptrs.push(resolve(self->extras[i]));
    }
    fn_8023DE28(resolve(self->owner));
    Context copy;
    context.h.mode=4;
    for(int j=0;j<self->count;j++){
        Bound*bound=resolveT<Bound>(self->bound[j]);
        if(!bound)continue;
        *(Context*)&copy=context;
        copy.h.object=bound;
        copy.matrix=*bound->matrix;
        copy.h.extra=resolve(bound->extra);
        void*secondary=resolve(bound->secondary);
        if(secondary&&secondary!=special)copy.h.secondary=resolve(*(const Handle*)(unsigned long)&bound->secondary);
        Receiver*receiver=(Receiver*)resolve(bound->receiver);
        Listener*listener=(Listener*)resolve(bound->listener);
        if(bound->flags&0x10000)continue;
        if(listener&&((mask|1)&listener->mask))continue;
        if(receiver)receiver->receive(&copy,listener);
        if(listener)listener->notify(&copy);
    }
    }
}
