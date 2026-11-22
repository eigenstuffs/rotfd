extern const char lbl_801EF5C8[];

extern void fn_801EF610(const void *,void *);

extern void __dt__15Handle_801F7F10Fv(void *,int);

static inline void destroy_handle(void *object) {if(object)__dt__15Handle_801F7F10Fv(object,0);}

static inline void destroy_handle_base(void *object) {if(object)destroy_handle(object);}

extern const char __vt__13Manipulator_Z[];

extern void __dt__11Activable_ZFv(void *,int);

static inline void destroy_owner(void *object) {if(object){*(void **)((char *)object+8)=(void *)__vt__13Manipulator_Z;__dt__11Activable_ZFv(object,0);}}

extern const char lbl_802EA080[];

void *fn_801C866C(void *object,short release) {if(object){*(void **)((char *)object+8)=(void *)lbl_802EA080;destroy_handle_base((char *)object+0x124);destroy_owner(object);if(release>0)fn_801EF610(lbl_801EF5C8,object);}return object;}
