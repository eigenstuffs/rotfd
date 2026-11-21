/* Original engine setup and record routines with private observed layouts.
 * See docs/notes/game-scalar-middle-more.md. */

extern const char lbl_801EF5C8[];

extern void fn_801EF610(const void *,void *);

void *fn_801B5D04(void *object,short release) {if(object && release>0)fn_801EF610(lbl_801EF5C8,object);return object;}
