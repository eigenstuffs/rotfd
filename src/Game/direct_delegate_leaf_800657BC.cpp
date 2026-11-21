/* Original direct ABI-preserving delegate; see docs/notes/game-direct-delegate-leafs.md. */
struct OpaqueHandle;struct OpaquePoint;
extern "C" void fn_80063290(void*self,int argument);
extern "C" void fn_800657BC(void*self,int argument){fn_80063290(self,argument);}
