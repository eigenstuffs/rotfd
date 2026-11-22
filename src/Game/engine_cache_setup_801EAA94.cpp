extern "C" {
    extern char lbl_801EF5C8[],__vt__18CacheBase_802EA868[],__vt__16Cache10_802F1490[],__vt__17Cache900_802F149C[];
    extern char platform_type_registry_Anonymous_Alloc[],platform_type_registry_SurfaceGCCache_Z_h[];
    void fn_801EAC04(void*,int,int);
    void *fn_801EFA1C(void*,unsigned long,const char*,const char*,int,int);
}
struct Node_801EAA94 {
    int handle;
    unsigned short index,unknown6,prev,next;
};
struct Block_801EAA94 {
    void*data;
    void*second;
    void*third;
    void*fourth;
};
struct Cache_801EAA94 {
    int count,capacity;
    Node_801EAA94*data;
    int stride;
    Block_801EAA94*blocks;
    void*vtable;
    Node_801EAA94&at(unsigned int n) {
        Node_801EAA94*base=data;
        return base[n];
    }
    void unlink(unsigned int n) {
        at(at(n).prev).next=at(n).next;
        at(at(n).next).prev=at(n).prev;
    }
    void prepend(unsigned int n) {
        at(n).next=at(0).next;
        at(n).prev=0;
        at(at(0).next).prev=n;
        at(0).next=n;
    }
    Block_801EAA94*get(unsigned short n) {
        unsigned int next=n+1;
        unlink(next);
        prepend(next);
        return &blocks[n*stride];
    }
};
extern "C" Cache_801EAA94*fn_801EAA94(Cache_801EAA94*self) {
    self->vtable=__vt__18CacheBase_802EA868;
    self->count=0;
    self->capacity=0;
    self->data=0;
    self->blocks=0;
    self->vtable=__vt__16Cache10_802F1490;
    fn_801EAC04(self,10,1);
    char*p=(char*)fn_801EFA1C(lbl_801EF5C8,10*0x240,platform_type_registry_Anonymous_Alloc,platform_type_registry_SurfaceGCCache_Z_h,90,32);
    for(unsigned short i=0; i<10; i++) {
        Block_801EAA94&b=*self->get(i);
        b.data=p;
        b.second=p+0xc0;
        b.third=p+0x180;
        b.fourth=p+0x1c0;
        p+=0x240;
    }
    return self;
}
