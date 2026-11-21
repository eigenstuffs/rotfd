/* Original engine records and resource lifetime routines.
 * See docs/notes/game-engine-records-more.md. */
extern const char lbl_801EF5C8[];extern void fn_801EF610(const void *,void *);extern const char lbl_802EA330[];extern void fn_801CF8D4(void *,int);
void *fn_801CDAC4(void *object,short release) {if(object){*(void **)((char *)object+8)=(void *)lbl_802EA330;fn_801CF8D4(object,0);if(release>0)fn_801EF610(lbl_801EF5C8,object);}return object;}
