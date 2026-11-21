/* Original engine setup and record routines with private observed layouts.
 * See docs/notes/game-scalar-middle-more.md. */

extern struct {char pad[0x118];void *manager;} lbl_801E9D24;

extern void fn_801B3E54(void *,void *);

void fn_801CDC38(void *object) {int i;for(i=0;i<*(int *)((char *)object+0xbc);++i)fn_801B3E54(lbl_801E9D24.manager,*(char **)((char *)object+0xc4)+i*4);}
