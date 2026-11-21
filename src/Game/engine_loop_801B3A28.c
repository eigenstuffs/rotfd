/* Original engine array and lifetime routines with private observed layouts.
 * See docs/notes/game-engine-loops.md. */

extern const char lbl_801EF5C8[];

extern void fn_801EF610(const void *,void *);

extern const char __vt__17Resource_802E9E20[];

extern void __dt__12BaseObject_ZFv(void *,int);

void *__dt__17Resource_802E9E20Fv(void *object,short release) {if(object){*(void **)((char *)object+8)=(void *)__vt__17Resource_802E9E20;__dt__12BaseObject_ZFv(object,0);if(release>0)fn_801EF610(lbl_801EF5C8,object);}return object;}
