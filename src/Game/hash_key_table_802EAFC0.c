#include "Game/hash_key_tables.h"
extern void fn_80208BD0(struct IntegerKey *);
extern signed long fn_80208BA8(struct IntegerKey *);
extern signed long fn_80208B80(struct IntegerKey *);
extern signed char fn_80208B64(struct IntegerKey *, struct IntegerKey *);
extern signed char fn_80208B44(struct IntegerKey *, struct IntegerKey *);
extern struct IntegerKey * fn_80208AC4(struct IntegerKey *);
IntegerKeyInterfaceTable lbl_802EAFC0 = { 0, 0, fn_80208BD0, fn_80208BA8, fn_80208B80, fn_80208B64, fn_80208B44, fn_80208AC4 };
typedef char CheckTableSize[sizeof(IntegerKeyInterfaceTable) == 32 ? 1 : -1];
