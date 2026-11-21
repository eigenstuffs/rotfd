/* Original engine array and lifetime routines with private observed layouts.
 * See docs/notes/game-engine-loops.md. */

extern const char lbl_801EF5C8[];

extern void fn_801EF610(const void *,void *);

extern const char __vt__17Resource_802E9E20[];

extern void __dt__12BaseObject_ZFv(void *,int);

static inline void destroy_resource(void *object) {if(object){*(void **)((char *)object+8)=(void *)__vt__17Resource_802E9E20;__dt__12BaseObject_ZFv(object,0);}}

extern const char __vt__12Txt_802E9E50[];

extern void __dt__13File_801F3E1CFv(void *,int);

void *fn_801B4AAC(void *object,short release) {if(object){*(void **)((char *)object+8)=(void *)__vt__12Txt_802E9E50;__dt__13File_801F3E1CFv((char *)object+0xc,-1);destroy_resource(object);if(release>0)fn_801EF610(lbl_801EF5C8,object);}return object;}
