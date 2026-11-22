struct Actor;struct Owner{char opaque00[8];Actor*actor;};extern "C"void fn_80092DAC(Actor*,double);extern "C"void fn_80083EB0(Owner*self,double delta){fn_80092DAC(self->actor,delta);}
