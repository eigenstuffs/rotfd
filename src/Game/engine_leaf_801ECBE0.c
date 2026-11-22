extern const char lbl_801EF5C8[];

extern void fn_801EF610(const void *,void *);

extern const char lbl_802EA894[];

#include "Game/native_cleanup_table.h"

static inline void destroy_base(void *object) {if(object)*(void **)object=(void *)&lbl_802EA8A0;}

void *fn_801ECBE0(void *object,short release) {if(object){*(void **)object=(void *)lbl_802EA894;destroy_base(object);if(release>0)fn_801EF610(lbl_801EF5C8,object);}return object;}

void *fn_801ECC44(void *object,short release) {if(object){*(void **)object=(void *)&lbl_802EA8A0;if(release>0)fn_801EF610(lbl_801EF5C8,object);}return object;}
