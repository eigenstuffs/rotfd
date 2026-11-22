struct AgentView_80028A6C {unsigned long prefix[2];const void *vtable;unsigned char unknown0C[0x38-12]; unsigned long flags; unsigned char unknown3C[0x90-0x3C]; unsigned long state; unsigned long unknown94;};
extern "C" {
extern unsigned long lbl_803775AC,lbl_80377588;
extern const char lbl_802B10DC[],lbl_802B0A18[];
void fn_8002AD5C();
void __ct__15Object_8002AD98Fv(void*);
void fn_8002AE0C(void*,short);
}
static inline void baseConstruct_80028A6C(AgentView_80028A6C *p) {__ct__15Object_8002AD98Fv(p);p->vtable=lbl_802B10DC;}
static inline void baseDestroy_80028A6C(AgentView_80028A6C *p) {p->vtable=lbl_802B10DC;fn_8002AE0C(p,0);}
static inline void baseRegister_80028A6C() {
 lbl_80377588=0;fn_8002AD5C();AgentView_80028A6C object;baseConstruct_80028A6C(&object);baseDestroy_80028A6C(&object);
}
static inline void derivedConstruct_80028A6C(AgentView_80028A6C *p) {baseConstruct_80028A6C(p);p->vtable=lbl_802B0A18;}
static inline void derivedDestroy_80028A6C(AgentView_80028A6C *p) {p->vtable=lbl_802B0A18;baseDestroy_80028A6C(p);}
extern "C" void fn_80028A6C() {
 lbl_803775AC=0;baseRegister_80028A6C();AgentView_80028A6C object;derivedConstruct_80028A6C(&object);derivedDestroy_80028A6C(&object);
}

// Reset the base collectable, enable bit 2, and select this tile variant.
extern "C" {
void fn_8002AE88(void*);
void fn_80028AF0(AgentView_80028A6C *object) {fn_8002AE88(object);object->flags|=4;object->state=8;}
}
