/* Original engine setup and record routines with private observed layouts.
 * See docs/notes/game-scalar-middle-more.md. */

extern struct {char pad[0x118];void *manager;} lbl_801E9D24;

extern void fn_801B13C4(void *);

extern void fn_801B3E54(void *,void *);

void fn_801C9878(void *object) {fn_801B13C4((char *)object+0x10);fn_801B3E54(lbl_801E9D24.manager,(char *)object+0xb8);}
