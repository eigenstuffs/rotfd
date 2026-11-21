/* Original direct ABI-preserving delegate; see docs/notes/game-direct-delegate-leafs.md. */
struct OpaqueHandle;struct OpaquePoint;
extern "C" void fn_80063FB8(void*self);
extern "C" void fn_800657FC(void*self){fn_80063FB8(self);}
