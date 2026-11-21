/* Original direct ABI-preserving delegate; see docs/notes/game-direct-delegate-leafs.md. */
struct OpaqueHandle;struct OpaquePoint;
extern "C" void fn_800C152C(void*self,float delta);
extern "C" void fn_800C1988(void*self,float delta){fn_800C152C(self,delta);}
