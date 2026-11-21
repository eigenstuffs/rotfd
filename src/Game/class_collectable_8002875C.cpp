// Collectable variant registration and reset methods.
// All opaque object extents are 0x98 bytes, as established by their factories.
// See docs/notes/game-class-registry.md.
struct AgentView_8002875C {unsigned long prefix[2];const void *vtable;unsigned char unknown0C[0x38-12]; unsigned long flags; unsigned char unknown3C[0x90-0x3C]; unsigned long state; unsigned long unknown94;};
extern "C" {
extern unsigned long lbl_8037759C,lbl_80377588;
extern const char lbl_802B10DC[],lbl_802B0D38[];
void fn_8002AD5C();
void __ct__15Object_8002AD98Fv(void*);
void fn_8002AE0C(void*,short);
}
static inline void baseConstruct_8002875C(AgentView_8002875C *p) {__ct__15Object_8002AD98Fv(p);p->vtable=lbl_802B10DC;}
static inline void baseDestroy_8002875C(AgentView_8002875C *p) {p->vtable=lbl_802B10DC;fn_8002AE0C(p,0);}
static inline void baseRegister_8002875C() {
 lbl_80377588=0;fn_8002AD5C();AgentView_8002875C object;baseConstruct_8002875C(&object);baseDestroy_8002875C(&object);
}
static inline void derivedConstruct_8002875C(AgentView_8002875C *p) {baseConstruct_8002875C(p);p->vtable=lbl_802B0D38;}
static inline void derivedDestroy_8002875C(AgentView_8002875C *p) {p->vtable=lbl_802B0D38;baseDestroy_8002875C(p);}
extern "C" void fn_8002875C() {
 lbl_8037759C=0;baseRegister_8002875C();AgentView_8002875C object;derivedConstruct_8002875C(&object);derivedDestroy_8002875C(&object);
}

// Reset the base collectable, enable bit 2, and select this tile variant.
extern "C" {
void fn_8002AE88(void*);
void fn_800287E0(AgentView_8002875C *object) {fn_8002AE88(object);object->flags|=4;object->state=4;}
}
