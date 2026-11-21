/* Original engine setup and record routines with private observed layouts.
 * See docs/notes/game-scalar-middle-more.md. */

extern struct {char pad[0x118];void *manager;} lbl_801E9D24;

extern void __ct__15Handle_801F7F10Fv(void *);

extern void fn_801F86C8(void *,void *,int);

void fn_801BE46C(unsigned int *out,void *object) {__ct__15Handle_801F7F10Fv(out);*out=0;*out=0;*out=*(unsigned int *)((char *)object+0x28);fn_801F86C8(lbl_801E9D24.manager,(char *)object+0x28,1);}
