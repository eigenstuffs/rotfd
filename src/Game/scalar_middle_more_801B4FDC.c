/* Original engine setup and record routines with private observed layouts.
 * See docs/notes/game-scalar-middle-more.md. */

extern struct {char pad[0x110];void *logger;} lbl_801E9D24;

extern const char lbl_802AC938[];

extern void fn_80207A14(void *,char *);

extern signed char fn_801F3918(void *,const char *,int);

extern void fn_801FA014(void *,const char *,...);

int fn_801B4FDC(void *unused,void *context,void *out) {char name[128];fn_80207A14(context,name);if(!fn_801F3918(out,name,1)){fn_801FA014(lbl_801E9D24.logger,lbl_802AC938,name);return 0;}return 1;}
