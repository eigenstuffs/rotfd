/* Original direct ABI-preserving delegate; see docs/notes/game-direct-delegate-leafs.md. */
extern "C" {void fn_8002BAB4(void*);void fn_8005EED4(void*);}
extern "C" void fn_80063FB8(void*self){fn_8002BAB4(self);fn_8005EED4((char*)self+0x90);}
