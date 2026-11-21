#include "Game/native_runtime_type_records_remaining.h"
#include "Game/costume_native_operation_records.h"

extern "C" {
Object_8008B49C *__dt__15Object_8008B49CFv(Object_8008B49C *, short);
Object_8008B378 *__dt__15Object_8008B378Fv(Object_8008B378 *, short);
void *fn_8008A830(View *, int);
Object_8008A468 *__dt__15Object_8008A468Fv(Object_8008A468 *, short);
void *fn_8008A1DC(InlineBase *, int);
Object_8008A0DC *__dt__15Object_8008A0DCFv(Object_8008A0DC *, short);
void fn_8008B528(void *);
void fn_8008B534(Owner *, float);
void fn_8008B8C0(void *);
void fn_80081414(void);
void fn_8008B8D0(Owner *);
void fn_8008B404(void);
void fn_8008B408(void);
void fn_8008B40C(void);
void fn_8008B410(void);
void fn_8008A944(Actor *);
void fn_8008B0A8(Control *);
void fn_8008B0EC(SceneOwner *);
void fn_8008B1AC(Owner *);
void fn_8008A4F4(void *);
void fn_8008A54C(void);
void fn_8008A550(void *);
void fn_8008A5A8(Owner *);
void fn_8008A278(void);
void fn_8008A27C(void);
void fn_8008A280(void);
void fn_8008A284(Owner *);
void fn_8008ED84(void);
void fn_8008ED88(void);
void fn_8008ED8C(void);
void fn_8008ED90(void);

NativeRuntimeBaseList<2> lbl_802B89F0 = {{{&lbl_80374A1C,0},{&lbl_80374A24,0}},0};
StateCostumeKarateNativeOperations lbl_802B8A04 = {&lbl_80374A8C,0,__dt__15Object_8008B49CFv,fn_8008B528,fn_8008B534,fn_8008B8C0,fn_80081414,fn_8008B8D0};
NativeRuntimeBaseList<2> lbl_802B8A24 = {{{&lbl_80374A1C,0},{&lbl_80374A24,0}},0};
StateCostumeTreasureHuntingNativeOperations lbl_802B8A38 = {&lbl_80374A94,0,__dt__15Object_8008B378Fv,fn_8008B404,fn_8008B408,fn_8008B40C,fn_80081414,fn_8008B410};
NativeRuntimeBaseList<2> lbl_802B8A58 = {{{&lbl_80374A1C,0},{&lbl_80374A24,0}},0};
StateCostumeReefblowerNativeOperations lbl_802B8A6C = {&lbl_80374A9C,0,fn_8008A830,fn_8008A944,fn_8008B0A8,fn_8008B0EC,fn_80081414,fn_8008B1AC};
NativeRuntimeBaseList<2> lbl_802B8A8C = {{{&lbl_80374A1C,0},{&lbl_80374A24,0}},0};
StateCostumeJellyfishingNativeOperations lbl_802B8AA0 = {&lbl_80374AA4,0,__dt__15Object_8008A468Fv,fn_8008A4F4,fn_8008A54C,fn_8008A550,fn_80081414,fn_8008A5A8};
NativeRuntimeBaseList<2> lbl_802B8AC0 = {{{&lbl_80374A1C,0},{&lbl_80374A24,0}},0};
NativeRuntimeBaseList<3> lbl_802B8AD4 = {{{&lbl_80374A1C,0},{&lbl_80374A24,0},{&lbl_80374AAC,0}},0};
StateCostumeDefaultNativeOperations lbl_802B8AF0 = {&lbl_80374AB4,0,fn_8008A1DC,fn_8008A278,fn_8008A27C,fn_8008A280,fn_80081414,fn_8008A284};
StateCostumeBaseNativeOperations lbl_802B8B10 = {&lbl_80374AAC,0,__dt__15Object_8008A0DCFv,fn_8008ED84,fn_8008ED88,fn_8008ED8C,fn_80081414,fn_8008ED90};
}

typedef char CheckStateCostumeKarateSize[sizeof(StateCostumeKarateNativeOperations)==32?1:-1];
typedef char CheckStateCostumeTreasureHuntingSize[sizeof(StateCostumeTreasureHuntingNativeOperations)==32?1:-1];
typedef char CheckStateCostumeReefblowerSize[sizeof(StateCostumeReefblowerNativeOperations)==32?1:-1];
typedef char CheckStateCostumeJellyfishingSize[sizeof(StateCostumeJellyfishingNativeOperations)==32?1:-1];
typedef char CheckStateCostumeDefaultSize[sizeof(StateCostumeDefaultNativeOperations)==32?1:-1];
typedef char CheckStateCostumeBaseSize[sizeof(StateCostumeBaseNativeOperations)==32?1:-1];
typedef char CheckBaseList2[sizeof(NativeRuntimeBaseList<2>)==20?1:-1];
typedef char CheckBaseList3[sizeof(NativeRuntimeBaseList<3>)==28?1:-1];
