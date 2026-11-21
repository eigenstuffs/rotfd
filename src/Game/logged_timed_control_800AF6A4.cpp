/* Original logged and timed control delegates; see docs/notes/game-logged-timed-control-delegates.md. */
struct Component;struct Owner;extern "C"{signed char fn_8007DA74(Component*,float);void fn_80229A78(Owner*,float);}extern "C"void fn_800AF6A4(Owner*self,float delta){fn_80229A78(self,delta);fn_8007DA74((Component*)((char*)self+0x1F8),delta);}
