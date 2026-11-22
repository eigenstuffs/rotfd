typedef unsigned long U32;
extern "C" {
    extern char lbl_8028F698[],lbl_801EF5C8[];
    void fn_8028FD50(void*,void*,int);
    void fn_801EF610(void*,void*);
    void fn_80243E90(void*,int);
}
template<int N>struct Element_801CC4F0{
    char data[N];
    ~Element_801CC4F0(){
    }
}
;
template<class T>struct Pool_801CC4F0{
    int count,capacity;
    T*data;
    ~Pool_801CC4F0(){
        if(data){
            for(int i=0;
            i<count;
            i++)data[i].~T();
            if(data){
                fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));
                data=0;
            }
            data=0;
        }
    }
}
;
struct Handle_801F7F10{
    U32 word;
    ~Handle_801F7F10();
}
;
struct Handle0_801CC4F0:Handle_801F7F10{
    ~Handle0_801CC4F0(){
    }
}
;
struct Handle1_801CC4F0:Handle0_801CC4F0{
    ~Handle1_801CC4F0(){
    }
}
;
struct Handle2_801CC4F0:Handle1_801CC4F0{
    ~Handle2_801CC4F0(){
    }
}
;
struct Handle3_801CC4F0:Handle2_801CC4F0{
    ~Handle3_801CC4F0(){
    }
}
;
extern "C" {
    extern char __vt__23SpatialHandles_802EA2E0[],lbl_802EA288[],__vt__20SpatialBase_802EC118[],__vt__17Resource_802E9E20[];
}
struct BaseObject_Z{
    char pad[8];
    void*vtable;
    ~BaseObject_Z();
}
;
struct Resource_801CC4F0:BaseObject_Z{
    ~Resource_801CC4F0(){
        vtable=__vt__17Resource_802E9E20;
    }
}
;
struct ResourceLayer_801CC4F0:Resource_801CC4F0{
    char padc[0x14];
    ~ResourceLayer_801CC4F0(){
        vtable=__vt__20SpatialBase_802EC118;
    }
}
;
struct Child_801CC4F0{
    char pad[8];
    void*vtable;
    char padc[0xac];
    ~Child_801CC4F0(){
        vtable=lbl_802EA288;
        fn_80243E90(this,0);
    }
}
;
struct OwnedMemory_801CC4F0{
    int count,capacity;
    void*data;
    ~OwnedMemory_801CC4F0(){
        if(data){
            fn_801EF610(lbl_801EF5C8,data);
            data=0;
        }
    }
}
;
struct Object_801CC4F0:ResourceLayer_801CC4F0{
    Pool_801CC4F0<Handle1_801CC4F0> first;
    char pad2c[0x20];
    Child_801CC4F0 child;
    Handle1_801CC4F0 a;
    Handle2_801CC4F0 b,c;
    OwnedMemory_801CC4F0 memory;
    Pool_801CC4F0<Element_801CC4F0<4> > second;
}
;
extern "C" Object_801CC4F0 *fn_801CC4F0(Object_801CC4F0*self,short release){
    if(self){
        self->vtable=__vt__23SpatialHandles_802EA2E0;
        self->second.~Pool_801CC4F0();
        self->memory.~OwnedMemory_801CC4F0();
        self->c.~Handle2_801CC4F0();
        self->b.~Handle2_801CC4F0();
        self->a.~Handle1_801CC4F0();
        self->child.~Child_801CC4F0();
        self->first.~Pool_801CC4F0();
        self->ResourceLayer_801CC4F0::~ResourceLayer_801CC4F0();
        if(release>0)fn_801EF610(lbl_801EF5C8,self);
    }
    return self;
}
