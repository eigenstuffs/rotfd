/* Original scene logging and reset wrappers; see docs/notes/game-engine-scene-log-wrappers.md. */
extern "C"{extern struct Global{char opaque00[0x110];void*args;}lbl_801E9D24;extern const char lbl_8029A500[];void fn_801FA014(void*,const char*,...);void fn_8003543C(void*,int);}
extern "C" void fn_80036B68(void*self,int value){fn_801FA014(lbl_801E9D24.args,lbl_8029A500);fn_8003543C(self,value);}
