#include "Game/python_scalar_bindings.h"
struct Handle_801F7F10{unsigned long word;Handle_801F7F10();~Handle_801F7F10();};
extern "C" struct{char unknown[0x118];void*manager;}lbl_801E9D24;
extern "C" void fn_801F86C8(void*,const void*,int);
extern "C" void fn_801EF610(void*,void*);
struct Handle_80020478:Handle_801F7F10{Handle_80020478(){word=0;}~Handle_80020478(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020834:Handle_80020478{Handle_80020834(){word=0;}Handle_80020834(const Handle_80020834&other){word=other.word;fn_801F86C8(lbl_801E9D24.manager,&other,1);}~Handle_80020834(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};

struct Handle_80020B90:Handle_80020478{Handle_80020B90(){word=0;}~Handle_80020B90(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Key{unsigned long word;};
extern "C" Handle_80020834 fn_801FCF20(void*,void*,Key,const Handle_80020B90&);
extern "C" FactoryPyObject*fn_800D00E8(FactoryPyObject*,FactoryPyObject*args){
 register const char*pool=lbl_802A2AA0;
 void*self;void*second;void*third;
 FactoryPyObject*parsed=0;FactoryPyObject*secondObject=0;FactoryPyObject*thirdObject=0;
 if(!PyArg_ParseTuple(args,pool+0x524,&parsed,&secondObject,&thirdObject))return 0;
 if(fn_800CD864(parsed,&self,lbl_80318988[0x1c/4],1)==-1)return 0;
 if(fn_800CD864(secondObject,&second,lbl_80318988[0xd8/4],1)==-1)return 0;
 if(fn_800CD864(thirdObject,&third,lbl_80318988[0xd8/4],1)==-1)return 0;
 Handle_80020834*object=new(fn_801EFA1C(lbl_801EF5C8,sizeof(Handle_80020834),pool+0x174,pool+0x60,0x585,4))Handle_80020834(fn_801FCF20(self,second,Key(*(Key*)third),Handle_80020B90()));
 return factoryPointerObject(object,lbl_80318988[0xc4/4]);
}
