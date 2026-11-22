struct AgentView_8003FDB0 {unsigned long prefix[2];const void *vtable;unsigned char opaque[0xA0-12];};
extern "C" {
extern unsigned long lbl_8037762C;
extern const char lbl_802B34F8[],lbl_802B3168[];
void fn_8003FF10();
void fn_80040064(void*);
void __dt__14Agent_8002B5F4Fv(void*,short);
}
static inline void baseDestroy_8003FDB0(AgentView_8003FDB0 *p) {p->vtable=lbl_802B3168;__dt__14Agent_8002B5F4Fv(p,0);}
static inline void derivedDestroy_8003FDB0(AgentView_8003FDB0 *p) {p->vtable=lbl_802B34F8;baseDestroy_8003FDB0(p);}
extern "C" void fn_8003FDB0() {
 AgentView_8003FDB0 object;
 lbl_8037762C=0;
 fn_8003FF10();
 fn_80040064(&object);
 object.vtable=lbl_802B34F8;
 derivedDestroy_8003FDB0(&object);
}

struct AgentView_8003FE08 {unsigned long prefix[2];const void *vtable;unsigned char opaque[0xA0-12];};
extern "C" {
extern unsigned long lbl_80377630;
extern const char lbl_802B33C8[],lbl_802B3168[];
void fn_8003FF10();
void fn_80040064(void*);
void __dt__14Agent_8002B5F4Fv(void*,short);
}
static inline void baseDestroy_8003FE08(AgentView_8003FE08 *p) {p->vtable=lbl_802B3168;__dt__14Agent_8002B5F4Fv(p,0);}
static inline void derivedDestroy_8003FE08(AgentView_8003FE08 *p) {p->vtable=lbl_802B33C8;baseDestroy_8003FE08(p);}
extern "C" void fn_8003FE08() {
 AgentView_8003FE08 object;
 lbl_80377630=0;
 fn_8003FF10();
 fn_80040064(&object);
 object.vtable=lbl_802B33C8;
 derivedDestroy_8003FE08(&object);
}

struct AgentView_8003FE60 {unsigned long prefix[2];const void *vtable;unsigned char opaque[0xA0-12];};
extern "C" {
extern unsigned long lbl_80377634;
extern const char lbl_802B308C[],lbl_802B3168[];
void fn_8003FF10();
void fn_80040064(void*);
void __dt__14Agent_8002B5F4Fv(void*,short);
}
static inline void baseDestroy_8003FE60(AgentView_8003FE60 *p) {p->vtable=lbl_802B3168;__dt__14Agent_8002B5F4Fv(p,0);}
static inline void derivedDestroy_8003FE60(AgentView_8003FE60 *p) {p->vtable=lbl_802B308C;baseDestroy_8003FE60(p);}
extern "C" void fn_8003FE60() {
 AgentView_8003FE60 object;
 lbl_80377634=0;
 fn_8003FF10();
 fn_80040064(&object);
 object.vtable=lbl_802B308C;
 derivedDestroy_8003FE60(&object);
}

struct AgentView_8003FEB8 {unsigned long prefix[2];const void *vtable;unsigned char opaque[0xA0-12];};
extern "C" {
extern unsigned long lbl_80377638;
extern const char lbl_802B3298[],lbl_802B3168[];
void fn_8003FF10();
void fn_80040064(void*);
void __dt__14Agent_8002B5F4Fv(void*,short);
}
static inline void baseDestroy_8003FEB8(AgentView_8003FEB8 *p) {p->vtable=lbl_802B3168;__dt__14Agent_8002B5F4Fv(p,0);}
static inline void derivedDestroy_8003FEB8(AgentView_8003FEB8 *p) {p->vtable=lbl_802B3298;baseDestroy_8003FEB8(p);}
extern "C" void fn_8003FEB8() {
 AgentView_8003FEB8 object;
 lbl_80377638=0;
 fn_8003FF10();
 fn_80040064(&object);
 object.vtable=lbl_802B3298;
 derivedDestroy_8003FEB8(&object);
}
