#ifndef GAME_BIT_RECORD_NATIVE_LIFETIME_H
#define GAME_BIT_RECORD_NATIVE_LIFETIME_H
extern "C"{extern struct{char unknown00[0x118];void*manager;}lbl_801E9D24;void fn_801F86C8(void*,const void*,int);}
struct Handle_801F7F10{unsigned long value;Handle_801F7F10();~Handle_801F7F10();};
struct BitNativeCtorZero:Handle_801F7F10{BitNativeCtorZero(){value=0;}};struct BitNativeCtorZero2:BitNativeCtorZero{BitNativeCtorZero2(){value=0;}};
struct BitNativeCtorHandle:BitNativeCtorZero{BitNativeCtorHandle(){value=0;}BitNativeCtorHandle(const BitNativeCtorHandle&input){value=input.value;fn_801F86C8(lbl_801E9D24.manager,&input,1);}BitNativeCtorHandle&operator=(const BitNativeCtorHandle&input){fn_801F86C8(lbl_801E9D24.manager,this,-1);value=input.value;fn_801F86C8(lbl_801E9D24.manager,&input,1);return *this;}};
struct BitNativeCtorPoint{float x,y,z;BitNativeCtorPoint(){}BitNativeCtorPoint(const BitNativeCtorPoint&v):x(v.x),y(v.y),z(v.z){}BitNativeCtorPoint&operator=(const BitNativeCtorPoint&input){x=input.x;y=input.y;z=input.z;return *this;}};
struct BitNativeCtorRotation{float x,y,z,w;BitNativeCtorRotation(){}BitNativeCtorRotation(const BitNativeCtorRotation&v):x(v.x),y(v.y),z(v.z),w(v.w){}BitNativeCtorRotation&operator=(const BitNativeCtorRotation&input){x=input.x;y=input.y;z=input.z;w=input.w;return *this;}};
struct BitNativeCtorHandle2:BitNativeCtorZero2{BitNativeCtorHandle2(){value=0;}BitNativeCtorHandle2(const BitNativeCtorHandle2&input){value=input.value;fn_801F86C8(lbl_801E9D24.manager,&input,1);}};
struct BitNativeCopyRecord{BitNativeCtorPoint point00;BitNativeCtorRotation rotation0C;BitNativeCtorPoint point1C,point28;char unknown34[4];unsigned long long token38;BitNativeCtorHandle handle40;BitNativeCtorHandle2 handle44,handle48,handle4C;int state50;BitNativeCtorPoint point54,point60,point6C,point78;int state84;float value88,value8C;unsigned long long token90;int state98,state9C;float valueA0;BitNativeCopyRecord(const BitNativeCopyRecord&);};
#endif
