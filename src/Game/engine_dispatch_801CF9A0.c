extern void __ct__13Root_80207414Fv(void *);
extern char __vt__17Resource_802E9E20[],__vt__20SpatialBase_802EC118[],lbl_802EA440[];
extern const float lbl_8037A468;
extern struct Vector {
    float x,y,z,w;
} game_vec4_zero;
static inline void copy(struct Vector *to,struct Vector *from,float w){
    to->x=from->x;
    to->y=from->y;
    to->z=from->z;
    to->w=w;
}
struct Object{
    char base[8];
    void *vtable;
    int flags;
    struct Vector vector;
    unsigned short id;
};
struct Object *fn_801CF9A0(struct Object *self){
    __ct__13Root_80207414Fv(self);
    self->vtable=__vt__17Resource_802E9E20;
    self->vtable=__vt__20SpatialBase_802EC118;
    copy(&self->vector,&game_vec4_zero,lbl_8037A468);
    self->flags=0;
    self->vtable=lbl_802EA440;
    self->id=0xffff;
    return self;
}
