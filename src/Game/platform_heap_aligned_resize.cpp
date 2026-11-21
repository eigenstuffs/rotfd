// Round allocation sizes to the native 32-byte pool boundary.
typedef unsigned long u32;
extern "C" void *fn_8028FAF4(void *,void *,u32,u32);
extern "C" void *fn_8028F8AC(void *self,void *memory,u32 oldSize,u32 newSize){
 oldSize=(oldSize+31)&~31U;
 newSize=(newSize+31)&~31U;
 if(oldSize==newSize)return memory;
 return fn_8028FAF4(self,memory,oldSize,newSize);
}
