/* Original reference-counted handle assignment with private observed layout.
 * See docs/notes/game-record-setup-late.md. */
typedef unsigned int u32;
extern struct {char unknown[0x118];void *manager;} lbl_801E9D24;
extern void fn_801F86C8(void *manager,const u32 *handle,int adjustment);
struct Object {char unknown[80];u32 handle0;u32 handle1;u32 handle2;u32 handle3;};
void fn_8021121C(struct Object *object,const u32 *source0,const u32 *source1,const u32 *source2,const u32 *source3) {
    fn_801F86C8(lbl_801E9D24.manager,&object->handle0,-1);
    object->handle0=*source0;
    fn_801F86C8(lbl_801E9D24.manager,source0,1);
    fn_801F86C8(lbl_801E9D24.manager,&object->handle1,-1);
    object->handle1=*source1;
    fn_801F86C8(lbl_801E9D24.manager,source1,1);
    fn_801F86C8(lbl_801E9D24.manager,&object->handle2,-1);
    object->handle2=*source2;
    fn_801F86C8(lbl_801E9D24.manager,source2,1);
    fn_801F86C8(lbl_801E9D24.manager,&object->handle3,-1);
    object->handle3=*source3;
    fn_801F86C8(lbl_801E9D24.manager,source3,1);
}
