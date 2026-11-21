// Collectable variant registration and reset methods.
// All opaque object extents are 0x98 bytes, as established by their factories.
// See docs/notes/game-class-registry.md.
struct AgentView_80028820 {unsigned long prefix[2];const void *vtable;unsigned char unknown0C[0x38-12]; unsigned long flags; unsigned char unknown3C[0x90-0x3C]; unsigned long state; unsigned long unknown94;};
extern "C" {
extern unsigned long lbl_803775A0,lbl_80377588;
extern const char lbl_802B10DC[],lbl_802B0C70[];
void fn_8002AD5C();
void __ct__15Object_8002AD98Fv(void*);
void fn_8002AE0C(void*,short);
}
static inline void baseConstruct_80028820(AgentView_80028820 *p) {__ct__15Object_8002AD98Fv(p);p->vtable=lbl_802B10DC;}
static inline void baseDestroy_80028820(AgentView_80028820 *p) {p->vtable=lbl_802B10DC;fn_8002AE0C(p,0);}
static inline void baseRegister_80028820() {
 lbl_80377588=0;fn_8002AD5C();AgentView_80028820 object;baseConstruct_80028820(&object);baseDestroy_80028820(&object);
}
static inline void derivedConstruct_80028820(AgentView_80028820 *p) {baseConstruct_80028820(p);p->vtable=lbl_802B0C70;}
static inline void derivedDestroy_80028820(AgentView_80028820 *p) {p->vtable=lbl_802B0C70;baseDestroy_80028820(p);}
extern "C" void fn_80028820() {
 lbl_803775A0=0;baseRegister_80028820();AgentView_80028820 object;derivedConstruct_80028820(&object);derivedDestroy_80028820(&object);
}

// Reset the base collectable, enable bit 2, and select this tile variant.
extern "C" {
void fn_8002AE88(void*);
void fn_800288A4(AgentView_80028820 *object) {fn_8002AE88(object);object->flags|=4;object->state=5;}
}
