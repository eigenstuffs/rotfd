/* Original short control delegates; see docs/notes/game-short-control-delegates.md. */
struct Control;struct Object;extern "C"signed char fn_8006BA70(Control*,Object*);extern "C"signed char fn_8006B940(Control*self,unsigned char ignored){fn_8006BA70(self,0);return 1;}
