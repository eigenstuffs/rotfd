#ifndef GAME_AGENT_NATIVE_CONSTRUCTOR_8002B5F4_H
#define GAME_AGENT_NATIVE_CONSTRUCTOR_8002B5F4_H

// Same-layout partial views of the observed Lod/Agent constructor layers.
// Existing factory and derived-class views remain independent declarations.
typedef unsigned long AgentWord_8002B5F4;
extern "C" {
extern char lbl_801EF5C8[], lbl_802EC8A8[];
extern const char lbl_802B170C[];
void fn_801EF610(void*, void*);
void fn_80020FE8(void*, int);
}
struct LodAgent_802EC8A8 {
    AgentWord_8002B5F4 unknown00[2];
    const void* vtable;
    char unknown0C[0x2C];
    unsigned long long flags;
    char unknown40[0x40];
    LodAgent_802EC8A8();
    ~LodAgent_802EC8A8();
    static void operator delete(void* pointer) throw() {
        fn_801EF610(lbl_801EF5C8, pointer);
    }
};
struct AgentVtable_8002B5F4 {
    AgentVtable_8002B5F4(LodAgent_802EC8A8* owner) {
        owner->vtable = lbl_802B170C;
    }
};
struct Handle_801F7F10 {
    AgentWord_8002B5F4 value;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct AgentHandle_8002B5F4 : Handle_801F7F10 {
    AgentHandle_8002B5F4() { value = 0; }
};
struct Agent_8002B5F4 : LodAgent_802EC8A8, AgentVtable_8002B5F4 {
    AgentHandle_8002B5F4 handle80;
    AgentWord_8002B5F4 unknown84;
    unsigned char active88;
    unsigned short count8A;
    AgentWord_8002B5F4 value8C;
    Agent_8002B5F4();
};
typedef char LodAgentNativeSizeCheck[(sizeof(LodAgent_802EC8A8) == 0x80) ? 1 : -1];
typedef char AgentNativeSizeCheck[(sizeof(Agent_8002B5F4) == 0x90) ? 1 : -1];

#endif
