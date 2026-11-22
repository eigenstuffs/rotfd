extern const char lbl_801EF5C8[];

extern void fn_801EF610(const void *,void *);

extern void __dt__15Handle_801F7F10Fv(void *,int);

static inline void destroy_handle(void *object) {if(object)__dt__15Handle_801F7F10Fv(object,0);}

static inline void destroy_handle_base(void *object) {if(object)destroy_handle(object);}

extern const char __vt__30HandleAssignInterface_801C9D34[];

void *fn_801C9DA0(void *object,short release) {if(object){*(void **)((char *)object+4)=(void *)__vt__30HandleAssignInterface_801C9D34;destroy_handle_base(object);if(release>0)fn_801EF610(lbl_801EF5C8,object);}return object;}
