/* Original direct ABI-preserving delegate; see docs/notes/game-direct-delegate-leafs.md. */
struct OpaqueHandle;struct OpaquePoint;
extern "C" int fn_8025E9FC(void*self,int index);
extern "C" int fn_800645A4(void*self,int index){return fn_8025E9FC(self,index);}
