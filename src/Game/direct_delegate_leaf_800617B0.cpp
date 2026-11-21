/* Original direct ABI-preserving delegate; see docs/notes/game-direct-delegate-leafs.md. */
struct OpaqueHandle;struct OpaquePoint;
extern "C" void fn_8002BA94(void*self,const OpaqueHandle&value);
extern "C" void fn_800617B0(void*self,const OpaqueHandle&value){fn_8002BA94(self,value);}
