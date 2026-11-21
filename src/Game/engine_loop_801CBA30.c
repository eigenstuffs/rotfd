/* Original engine array and lifetime routines with private observed layouts.
 * See docs/notes/game-engine-loops.md. */

extern const char lbl_801EF5C8[];

extern void fn_801EF610(const void *,void *);

extern const char lbl_802EA288[];

extern void fn_80243E90(void *,int);

void *fn_801CBA30(void *object,short release) {if(object){*(void **)((char *)object+8)=(void *)lbl_802EA288;fn_80243E90(object,0);if(release>0)fn_801EF610(lbl_801EF5C8,object);}return object;}
