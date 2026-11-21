/* Original engine lifetime and record routines.
 * See docs/notes/game-engine-cache-setup.md. */
extern "C" {
    extern char lbl_801EF5C8[],__vt__18CacheBase_802EA868[],__vt__16Cache10_802F1490[],__vt__17Cache900_802F149C[];
    extern char platform_type_registry_Anonymous_Alloc[],platform_type_registry_SurfaceGCCache_Z_h[];
    void fn_801EAC04(void*,int,int);
    void *fn_801EFA1C(void*,unsigned long,const char*,const char*,int,int);
}
struct Node_801EAEBC {
    int handle;
    unsigned short index,unknown6,prev,next;
};
struct Block_801EAEBC {
    void*data;
    void*second;
    void*third;
    void*fourth;
};
struct Cache_801EAEBC {
    int count,capacity;
    Node_801EAEBC*data;
    int stride;
    Block_801EAEBC*blocks;
    void*vtable;
    Node_801EAEBC&at(unsigned int n) {
        Node_801EAEBC*base=data;
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
    Block_801EAEBC*get(unsigned short n) {
        unsigned int next=n+1;
        unlink(next);
        prepend(next);
        return &blocks[n*stride];
    }
};
extern "C" Cache_801EAEBC*fn_801EAEBC(Cache_801EAEBC*self) {
    self->vtable=__vt__18CacheBase_802EA868;
    self->count=0;
    self->capacity=0;
    self->data=0;
    self->blocks=0;
    self->vtable=__vt__17Cache900_802F149C;
    fn_801EAC04(self,900,1);
    char*p=(char*)fn_801EFA1C(lbl_801EF5C8,900*0x240,platform_type_registry_Anonymous_Alloc,platform_type_registry_SurfaceGCCache_Z_h,40,32);
    for(unsigned short i=0; i<900; i++) {
        Block_801EAEBC&b=*self->get(i);
        b.data=p;
        b.second=p+0xc0;
        b.third=p+0x180;
        b.fourth=p+0x1c0;
        p+=0x240;
    }
    return self;
}
