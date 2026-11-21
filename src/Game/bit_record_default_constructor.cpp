#include "Game/bit_record_native_lifetime.h"
extern "C" const BitNativeCtorPoint game_vec3_zero;
struct BitDefaultRecord{BitNativeCtorPoint point00;BitNativeCtorRotation rotation0C;BitNativeCtorPoint point1C,point28;char unknown34[4];unsigned long long token38;BitNativeCtorHandle handle40;BitNativeCtorHandle2 handle44,handle48,handle4C;int state50;BitNativeCtorPoint point54,point60,point6C,point78;int state84;float value88,value8C;unsigned long long token90;int state98,state9C;float valueA0;BitDefaultRecord();};
inline void assignDefault(Handle_801F7F10&dest,const Handle_801F7F10&input){fn_801F86C8(lbl_801E9D24.manager,&dest,-1);dest.value=input.value;fn_801F86C8(lbl_801E9D24.manager,&input,1);}
BitDefaultRecord::BitDefaultRecord(){state50=0;assignDefault(handle40,BitNativeCtorHandle());assignDefault(handle44,BitNativeCtorHandle2());assignDefault(handle4C,BitNativeCtorHandle2());point00=game_vec3_zero;}
