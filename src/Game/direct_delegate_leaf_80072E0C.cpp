/* Original direct ABI-preserving delegate; see docs/notes/game-direct-delegate-leafs.md. */
struct OpaqueHandle;struct OpaquePoint;
extern "C" void fn_8002B820(void*self);
extern "C" void fn_80072E0C(void*self){fn_8002B820(self);}
