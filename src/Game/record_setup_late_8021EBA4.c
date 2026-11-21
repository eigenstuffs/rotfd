/* Original reference-counted handle assignment with private observed layout.
 * See docs/notes/game-record-setup-late.md. */
typedef unsigned int u32;
extern struct {char unknown[0x118];void *manager;} lbl_801E9D24;
extern void fn_801F86C8(void *manager,const u32 *handle,int adjustment);
struct Object {char unknown[300];u32 handle0;};
void fn_8021EBA4(struct Object *object,const u32 *source0) {
    fn_801F86C8(lbl_801E9D24.manager,&object->handle0,-1);
    object->handle0=*source0;
    fn_801F86C8(lbl_801E9D24.manager,source0,1);
}
