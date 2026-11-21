/* Original engine setup and record routines with private observed layouts.
 * See docs/notes/game-scalar-middle-more.md. */

extern const char lbl_801EF5C8[];

extern void fn_801EF610(const void *,void *);

extern void fn_801D4C3C(void *,int);

void *fn_801D4BDC(void *object,short release) {if(object){fn_801D4C3C((char *)object+4,-1);if(release>0)fn_801EF610(lbl_801EF5C8,object);}return object;}
