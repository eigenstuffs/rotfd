/* Original control forwarding and predicates; see docs/notes/game-control-forward-leafs.md. */
struct Control;extern "C"{Control*fn_8005E9A0();signed char fn_800669D0(Control*,Control*,unsigned char);}extern "C"signed char fn_800665D8(Control*self,unsigned char value){Control*other=fn_8005E9A0();if(other)return fn_800669D0(self,other,value);return 0;}
