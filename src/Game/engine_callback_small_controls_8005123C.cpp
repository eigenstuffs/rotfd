/* Original small callback control operations; see docs/notes/game-engine-callback-small-controls.md. */
struct Object{char opaque00[0x74];float value74,value78;};extern "C"{extern const float lbl_80378570,lbl_80378578,lbl_8037857C;void fn_802073BC(Object*,int,Object*,float,float);}
extern "C" void fn_8005123C(Object*self){if(self->value74!=lbl_80378570)fn_802073BC(self,0x8E,self,self->value74,lbl_80378578);if(self->value78!=lbl_80378570)fn_802073BC(self,0x8E,self,self->value78,lbl_8037857C);}
