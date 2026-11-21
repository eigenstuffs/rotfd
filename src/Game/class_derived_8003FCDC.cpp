// Derived-agent lifetime hooks; factory storage is 0xA0 bytes.
// The field at offset 8 is the original virtual-table pointer.
// See docs/notes/game-class-registry.md.
struct AgentView_8003FCDC {unsigned long prefix[2];const void *vtable;unsigned char opaque[0xA0-12];};
extern "C" {
extern unsigned long lbl_80377628;
extern const char lbl_802B3628[],lbl_802B3168[];
void fn_8003FF10();
void fn_80040064(void*);
void __dt__14Agent_8002B5F4Fv(void*,short);
}
static inline void baseDestroy_8003FCDC(AgentView_8003FCDC *p) {p->vtable=lbl_802B3168;__dt__14Agent_8002B5F4Fv(p,0);}
static inline void derivedDestroy_8003FCDC(AgentView_8003FCDC *p) {p->vtable=lbl_802B3628;baseDestroy_8003FCDC(p);}
extern "C" void fn_8003FCDC() {
 AgentView_8003FCDC object;
 lbl_80377628=0;
 fn_8003FF10();
 fn_80040064(&object);
 object.vtable=lbl_802B3628;
 derivedDestroy_8003FCDC(&object);
}
