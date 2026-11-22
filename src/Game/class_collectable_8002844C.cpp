struct AgentView_8002844C {unsigned long prefix[2];const void *vtable;unsigned char unknown0C[0x38-12]; unsigned long flags; unsigned char unknown3C[0x90-0x3C]; unsigned long state; unsigned long unknown94;};
extern "C" {
extern unsigned long lbl_8037758C,lbl_80377588;
extern const char lbl_802B10DC[],lbl_802B1058[];
void fn_8002AD5C();
void __ct__15Object_8002AD98Fv(void*);
void fn_8002AE0C(void*,short);
}
static inline void baseConstruct_8002844C(AgentView_8002844C *p) {__ct__15Object_8002AD98Fv(p);p->vtable=lbl_802B10DC;}
static inline void baseDestroy_8002844C(AgentView_8002844C *p) {p->vtable=lbl_802B10DC;fn_8002AE0C(p,0);}
static inline void baseRegister_8002844C() {
 lbl_80377588=0;fn_8002AD5C();AgentView_8002844C object;baseConstruct_8002844C(&object);baseDestroy_8002844C(&object);
}
static inline void derivedConstruct_8002844C(AgentView_8002844C *p) {baseConstruct_8002844C(p);p->vtable=lbl_802B1058;}
static inline void derivedDestroy_8002844C(AgentView_8002844C *p) {p->vtable=lbl_802B1058;baseDestroy_8002844C(p);}
extern "C" void fn_8002844C() {
 lbl_8037758C=0;baseRegister_8002844C();AgentView_8002844C object;derivedConstruct_8002844C(&object);derivedDestroy_8002844C(&object);
}

// Reset the base collectable, enable bit 2, and select this tile variant.
extern "C" {
void fn_8002AE88(void*);
void fn_800284D0(AgentView_8002844C *object) {fn_8002AE88(object);object->flags|=4;object->state=0;}
}
