// Collectable variant registration and reset methods.
// All opaque object extents are 0x98 bytes, as established by their factories.
// See docs/notes/game-class-registry.md.
struct AgentView_80028698 {unsigned long prefix[2];const void *vtable;unsigned char unknown0C[0x38-12]; unsigned long flags; unsigned char unknown3C[0x90-0x3C]; unsigned long state; unsigned long unknown94;};
extern "C" {
extern unsigned long lbl_80377598,lbl_80377588;
extern const char lbl_802B10DC[],lbl_802B0E00[];
void fn_8002AD5C();
void __ct__15Object_8002AD98Fv(void*);
void fn_8002AE0C(void*,short);
}
static inline void baseConstruct_80028698(AgentView_80028698 *p) {__ct__15Object_8002AD98Fv(p);p->vtable=lbl_802B10DC;}
static inline void baseDestroy_80028698(AgentView_80028698 *p) {p->vtable=lbl_802B10DC;fn_8002AE0C(p,0);}
static inline void baseRegister_80028698() {
 lbl_80377588=0;fn_8002AD5C();AgentView_80028698 object;baseConstruct_80028698(&object);baseDestroy_80028698(&object);
}
static inline void derivedConstruct_80028698(AgentView_80028698 *p) {baseConstruct_80028698(p);p->vtable=lbl_802B0E00;}
static inline void derivedDestroy_80028698(AgentView_80028698 *p) {p->vtable=lbl_802B0E00;baseDestroy_80028698(p);}
extern "C" void fn_80028698() {
 lbl_80377598=0;baseRegister_80028698();AgentView_80028698 object;derivedConstruct_80028698(&object);derivedDestroy_80028698(&object);
}

// Reset the base collectable, enable bit 2, and select this tile variant.
extern "C" {
void fn_8002AE88(void*);
void fn_8002871C(AgentView_80028698 *object) {fn_8002AE88(object);object->flags|=4;object->state=3;}
}
