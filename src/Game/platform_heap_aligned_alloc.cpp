// Round allocation sizes to the native 32-byte pool boundary.
typedef unsigned long u32;
extern "C" void *fn_8028FF24(void *,u32);
extern "C" void *fn_8028FACC(void *self,u32 size){return fn_8028FF24(self,(size+31)&~31U);}
