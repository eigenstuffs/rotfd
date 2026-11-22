extern "C" {
    extern char lbl_801EF5C8[],__vt__13CComplexAgent[];
    void fn_801EF610(void*,void*);
    void __dt__17CActorScriptAgentFv(void*,int);
}
struct View {
    char unknown00[8];
    void*vtable;
    char unknown0C[136];
    void*secondary;
};
static inline void dispose(void*p)throw() {
    fn_801EF610(lbl_801EF5C8,p);
}
extern "C" void*fn_80065CB0(View*self,int flag) {
    if(self) {
        self->vtable=__vt__13CComplexAgent;
        self->secondary=__vt__13CComplexAgent+180;
        __dt__17CActorScriptAgentFv(self,0);
        if((short)flag>0)dispose(self);
    }
    return self;
}
