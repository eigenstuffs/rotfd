#include "Game/python_scalar_bindings.h"
struct Handle_801F7F10{unsigned long word;Handle_801F7F10();~Handle_801F7F10();};
extern "C" struct{char unknown[0x118];void*manager;}lbl_801E9D24;
extern "C" void fn_801F86C8(void*,const void*,int);
extern "C" void fn_801EF610(void*,void*);
struct Handle_80020478:Handle_801F7F10{Handle_80020478(){word=0;}~Handle_80020478(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020834:Handle_80020478{Handle_80020834(const Handle_80020834&other){word=other.word;fn_801F86C8(lbl_801E9D24.manager,&other,1);}~Handle_80020834(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
extern "C" void fn_801FC514(void*,const Handle_80020834&);
extern "C" const char lbl_802A3110[];
extern "C" FactoryPyObject*fn_800D0A08(FactoryPyObject*,FactoryPyObject*args){
 void*self;void*other;
 FactoryPyObject*parsed=0;FactoryPyObject*otherObject=0;
 if(!PyArg_ParseTuple(args,lbl_802A3110,&parsed,&otherObject))return 0;
 if(fn_800CD864(parsed,&self,lbl_80318988[0x1c/4],1)==-1)return 0;
 if(fn_800CD864(otherObject,&other,lbl_80318988[0xc4/4],1)==-1)return 0;
 fn_801FC514(self,Handle_80020834(*(Handle_80020834*)other));
 ++_Py_NoneStruct.references;return &_Py_NoneStruct;
}
