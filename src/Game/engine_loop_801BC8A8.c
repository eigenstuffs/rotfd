/* Original engine array and lifetime routines with private observed layouts.
 * See docs/notes/game-engine-loops.md. */

extern const char lbl_801EF5C8[];

extern void fn_801EF610(const void *,void *);

extern const char lbl_802E9F48[],__vt__13Manipulator_Z[];

extern void __dt__11Activable_ZFv(void *,int);

static inline void destroy_base(void *object) {if(object){*(void **)((char *)object+8)=(void *)__vt__13Manipulator_Z;__dt__11Activable_ZFv(object,0);}}

void *fn_801BC8A8(void *object,short release) {if(object){*(void **)((char *)object+8)=(void *)lbl_802E9F48;destroy_base(object);if(release>0)fn_801EF610(lbl_801EF5C8,object);}return object;}
