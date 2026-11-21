/* Original logged and timed control delegates; see docs/notes/game-logged-timed-control-delegates.md. */
struct Actor;struct Owner{char opaque00[8];Actor*actor;};extern "C"void fn_80092DAC(Actor*,double);extern "C"void fn_8008D110(Owner*self,double delta){fn_80092DAC(self->actor,delta);}
