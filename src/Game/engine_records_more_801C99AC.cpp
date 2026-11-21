/* Original engine records and resource lifetime routines.
 * See docs/notes/game-engine-records-more.md. */
struct ObjectStorage_801C99AC {char pad[8];};struct Object_801C99AC:ObjectStorage_801C99AC {virtual void slot08();virtual void slot0C();virtual void slot10();};
#include "Game/service_interface_tables.h"
extern "C" {
extern const char lbl_801EF5C8[];extern void fn_801EF610(const void *,void *);
void *fn_801C99AC(Object_801C99AC *object,short release) {if(object){*(void **)((char *)object+8)=(void *)&lbl_802EA0F8;object->slot10();if(release>0)fn_801EF610(lbl_801EF5C8,object);}return object;}
}
