struct AgentView_800288E4 {unsigned long prefix[2];const void *vtable;unsigned char unknown0C[0x38-12]; unsigned long flags; unsigned char unknown3C[0x90-0x3C]; unsigned long state; unsigned long unknown94;};
extern "C" {
extern unsigned long lbl_803775A4,lbl_80377588;
extern const char lbl_802B10DC[],lbl_802B0BA8[];
void fn_8002AD5C();
void __ct__15Object_8002AD98Fv(void*);
void fn_8002AE0C(void*,short);
}
static inline void baseConstruct_800288E4(AgentView_800288E4 *p) {__ct__15Object_8002AD98Fv(p);p->vtable=lbl_802B10DC;}
static inline void baseDestroy_800288E4(AgentView_800288E4 *p) {p->vtable=lbl_802B10DC;fn_8002AE0C(p,0);}
static inline void baseRegister_800288E4() {
 lbl_80377588=0;fn_8002AD5C();AgentView_800288E4 object;baseConstruct_800288E4(&object);baseDestroy_800288E4(&object);
}
static inline void derivedConstruct_800288E4(AgentView_800288E4 *p) {baseConstruct_800288E4(p);p->vtable=lbl_802B0BA8;}
static inline void derivedDestroy_800288E4(AgentView_800288E4 *p) {p->vtable=lbl_802B0BA8;baseDestroy_800288E4(p);}
extern "C" void fn_800288E4() {
 lbl_803775A4=0;baseRegister_800288E4();AgentView_800288E4 object;derivedConstruct_800288E4(&object);derivedDestroy_800288E4(&object);
}

// Reset the base collectable, enable bit 2, and select this tile variant.
extern "C" {
void fn_8002AE88(void*);
void fn_80028968(AgentView_800288E4 *object) {fn_8002AE88(object);object->flags|=4;object->state=6;}
}
