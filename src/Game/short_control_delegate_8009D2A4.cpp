/* Original short control delegates; see docs/notes/game-short-control-delegates.md. */
struct Component;struct Control{char opaque00[0x318];};extern "C"{void fn_8009BEE8(Control*);void fn_8007D6A0(Component*,int);}extern "C"void fn_8009D2A4(Control*self){fn_8009BEE8(self);fn_8007D6A0((Component*)((char*)self+0x318),0);}
