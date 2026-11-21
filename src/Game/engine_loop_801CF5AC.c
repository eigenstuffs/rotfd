/* Original engine array and lifetime routines with private observed layouts.
 * See docs/notes/game-engine-loops.md. */

extern const char lbl_801EF5C8[];

extern void fn_801EF610(const void *,void *);

extern const char __vt__17Occluder_802EA3E8[];

extern void __dt__15BitSet_80207EE8Fv(void *,int);

extern void fn_801CA6B8(void *,int);

void *fn_801CF5AC(void *object,short release) {if(object){*(void **)((char *)object+8)=(void *)__vt__17Occluder_802EA3E8;__dt__15BitSet_80207EE8Fv((char *)object+0xd8,-1);fn_801CA6B8(object,0);if(release>0)fn_801EF610(lbl_801EF5C8,object);}return object;}
