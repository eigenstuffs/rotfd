/* Original engine dispatch and setup routines.
 * See docs/notes/game-engine-dispatch.md. */
#include "Game/path_owner_operations_table.h"
extern void fn_801F9420(void *);
extern void __ct__15BitSet_80207EE8Fv(void *);
extern int fn_801B3AD8(void),fn_801B3A90(void);
extern char lbl_802AC974[],lbl_8037A240[8],lbl_8037A248[8];
struct Object {
    char base[0x24];
    void *vtable;
    int a28,a2C,a30,selection;
    signed char flag38;
    char pad39[0x7f];
    int aB8,aBC,aC0,aC4;
    signed char flagC8,flagC9,flagCA;
    char padCB;
    int aCC,aD0,aD4;
    char bitset[0x10];
    int aE8,aEC;
};
struct Globals {
    char pad[0x110];
    void *state;
};
extern struct Globals lbl_801E9D24;
extern void fn_801FAC64(void *,const char *,int (*)(void),const char *);
struct Object *fn_801B5C20(struct Object *self){
    fn_801F9420(self);
    self->vtable=&lbl_802E9E70;
    self->a28=0;
    self->a2C=0;
    self->a30=0;
    self->aB8=0;
    self->aBC=0;
    self->aC0=0;
    self->aCC=0;
    self->aD0=0;
    self->aD4=0;
    __ct__15BitSet_80207EE8Fv(self->bitset);
    self->aE8=0;
    self->aEC=0;
    self->selection=-1;
    fn_801FAC64(lbl_801E9D24.state,lbl_8037A240,fn_801B3AD8,lbl_802AC974);
    fn_801FAC64(lbl_801E9D24.state,lbl_8037A248,fn_801B3A90,lbl_802AC974);
    self->aC4=0;
    self->flag38=0;
    self->flagC8=0;
    self->flagC9=0;
    self->flagCA=0;
    return self;
}
