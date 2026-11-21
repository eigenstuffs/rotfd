/* Original direct ABI-preserving delegate; see docs/notes/game-direct-delegate-leafs.md. */
struct OpaqueHandle;struct OpaquePoint;
extern "C" void fn_80257D20(void*self,const OpaqueHandle&value);
extern "C" void fn_800648A0(void*self,const OpaqueHandle&value){fn_80257D20(self,value);}
