/* Original direct ABI-preserving delegate; see docs/notes/game-direct-delegate-leafs.md. */
struct OpaqueHandle;struct OpaquePoint;
extern "C" void fn_8025A3C8(void*self,const OpaqueHandle&value);
extern "C" void fn_80064540(void*self,const OpaqueHandle&value){fn_8025A3C8(self,value);}
