#ifndef GAME_QSNAIL_AGENT_INTERNAL_H
#define GAME_QSNAIL_AGENT_INTERNAL_H
// QSnailBase lifetime layout; opaque fields retain factory-proven extent/alignment.
extern "C" {
void fn_8006F290(void*);
void fn_8006F2E0(void*,short);
extern const char lbl_802C1098[];
extern char lbl_801EF5C8[];
void fn_801EF610(void*,void*);
}
struct Agent_800C61B8 {
    union {
        double alignment;
        struct {unsigned long prefix[2];const void *vtable;unsigned char unknown0c[0xA0-12];unsigned long fieldA0;unsigned long unknownA4;} fields;
    };
    Agent_800C61B8();
    ~Agent_800C61B8();
    static void operator delete(void *object) throw() {fn_801EF610(lbl_801EF5C8,object);}
};
#endif
