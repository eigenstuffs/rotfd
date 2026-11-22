struct OpaqueHandle;struct OpaquePoint;
extern "C" void fn_80222CFC(void*self,const OpaquePoint*first,const OpaquePoint*second,const OpaquePoint*third,int index,float delta);
extern "C" void fn_800E2C1C(void*self,const OpaquePoint*first,const OpaquePoint*second,const OpaquePoint*third,int index,float delta){fn_80222CFC(self,first,second,third,index,delta);}
