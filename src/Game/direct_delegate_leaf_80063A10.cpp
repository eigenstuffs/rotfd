/* Original direct ABI-preserving delegate; see docs/notes/game-direct-delegate-leafs.md. */
struct OpaqueHandle;struct OpaquePoint;
extern "C" void fn_8025A324(void*self,void*value);
extern "C" void fn_80063A10(void*self,void*value){fn_8025A324(self,value);}
