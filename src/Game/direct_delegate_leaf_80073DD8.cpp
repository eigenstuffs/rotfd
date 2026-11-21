/* Original direct ABI-preserving delegate; see docs/notes/game-direct-delegate-leafs.md. */
struct OpaqueHandle;struct OpaquePoint;
extern "C" void fn_80259FB4(void*self,const OpaqueHandle&value);
extern "C" void fn_80073DD8(void*self,const OpaqueHandle&value){fn_80259FB4(self,value);}
