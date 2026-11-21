/* Original engine setup and record routines with private observed layouts.
 * See docs/notes/game-scalar-middle-more.md. */

extern struct {char pad[0x118];void *manager;} lbl_801E9D24;

extern void fn_801B3E54(void *,void *);

void fn_801CB348(void *object) {int i;for(i=0;i<10;++i)fn_801B3E54(lbl_801E9D24.manager,(char *)object+0x88+i*4);for(i=0;i<*(int *)((char *)object+0xd8);++i)fn_801B3E54(lbl_801E9D24.manager,*(char **)((char *)object+0xe0)+i*4);for(i=0;i<*(int *)((char *)object+0xe4);++i)fn_801B3E54(lbl_801E9D24.manager,*(char **)((char *)object+0xec)+i*4);}
