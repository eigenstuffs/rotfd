/* Original direct ABI-preserving delegate; see docs/notes/game-direct-delegate-leafs.md. */
struct OpaqueHandle;struct OpaquePoint;
extern "C" void fn_80063F98(void*self,const OpaqueHandle&value);
extern "C" void fn_80065B30(void*self,const OpaqueHandle&value){fn_80063F98(self,value);}
