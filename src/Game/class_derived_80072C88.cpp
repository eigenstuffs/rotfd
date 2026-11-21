// Derived-agent initialization; see docs/notes/game-class-registry.md.
struct AgentView {unsigned long prefix[2];const void *vtable;unsigned char opaque[0xb0-12];};
extern "C" {
extern unsigned long lbl_80377750;
extern const char lbl_802B7C24[];
void fn_8002B58C();
void fn_80072CD0(void*);
void __dt__14Agent_8002B5F4Fv(void*,short);
void fn_80072C88() {
 AgentView object;
 lbl_80377750=0;
 fn_8002B58C();
 fn_80072CD0(&object);
 object.vtable=lbl_802B7C24;
 __dt__14Agent_8002B5F4Fv(&object,0);
}
}
