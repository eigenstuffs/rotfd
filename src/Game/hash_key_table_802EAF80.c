#include "Game/hash_key_tables.h"
extern void fn_802089E4(struct PointerKey *);
extern unsigned long fn_802089BC(struct PointerKey *);
extern unsigned long fn_80208994(struct PointerKey *);
extern signed char fn_80208978(struct PointerKey *, struct PointerKey *);
extern signed char fn_80208958(struct PointerKey *, struct PointerKey *);
extern struct PointerKey * fn_802088D0(struct PointerKey *);
PointerKeyInterfaceTable lbl_802EAF80 = { 0, 0, fn_802089E4, fn_802089BC, fn_80208994, fn_80208978, fn_80208958, fn_802088D0 };
typedef char CheckTableSize[sizeof(PointerKeyInterfaceTable) == 32 ? 1 : -1];
