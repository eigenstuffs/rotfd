#include "Game/array_interface_tables.h"
extern struct OwnerLifecycleBase *fn_8020B774(struct OwnerLifecycleBase *, int);
extern struct EngineArrayOwnerPair *fn_8020C5CC(struct EngineArrayOwnerPair *, short);
extern void fn_8020C5BC(void *, float);
OwnerArrayInterfaceTable lbl_802EAFE0 = { 0, 0, fn_8020B774, fn_8020C5BC };
PairArrayInterfaceTable lbl_802EAFF0 = { 0, 0, fn_8020C5CC, fn_8020C5BC };
typedef char CheckOwnerTable[sizeof(OwnerArrayInterfaceTable) == 16 ? 1 : -1];
typedef char CheckPairTable[sizeof(PairArrayInterfaceTable) == 16 ? 1 : -1];
