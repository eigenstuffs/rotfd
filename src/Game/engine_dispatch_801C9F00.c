struct Object {
    void *matrices[2];
    char bitset[0x10];
    char pad18;
    unsigned char count;
    char pad1A[2];
    void *vtable;
};
#include "Game/typed_cleanup_tables.h"
extern char lbl_801EF5C8[];
extern void fn_801EF610(void *,void *);
extern void __dt__15BitSet_80207EE8Fv(void *,int);
struct Object *fn_801C9F00(struct Object *self,short destroy){
    if(self){
        int i;
        self->vtable=&lbl_802EA170;
        for(i=0;i<self->count;++i){
            if(self->matrices[i])fn_801EF610(lbl_801EF5C8,(char *)self->matrices[i]-0x10);
        }__dt__15BitSet_80207EE8Fv(self->bitset,-1);
        if(destroy>0)fn_801EF610(lbl_801EF5C8,self);
    }
    return self;
}
