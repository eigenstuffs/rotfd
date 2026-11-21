/* Original direct ABI-preserving delegate; see docs/notes/game-direct-delegate-leafs.md. */
struct OpaqueHandle;struct OpaquePoint;
extern "C" void fn_8005C6D0(void*self,const OpaqueHandle&value);
extern "C" void fn_8005D834(void*self,const OpaqueHandle&value){fn_8005C6D0(self,value);}
