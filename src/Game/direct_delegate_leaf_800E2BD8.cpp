/* Original direct ABI-preserving delegate; see docs/notes/game-direct-delegate-leafs.md. */
struct OpaqueHandle;struct OpaquePoint;
extern "C" void fn_80224888(void*self);
extern "C" void fn_800E2BD8(void*self){fn_80224888(self);}
