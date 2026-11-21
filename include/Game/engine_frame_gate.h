#ifndef GAME_ENGINE_FRAME_GATE_H
#define GAME_ENGINE_FRAME_GATE_H

struct EngineFrameGateHandle { signed int tag:8; signed int index:24; };
struct EngineFrameGateStorage { char unknown00[8]; };
struct EngineFrameGateNode : EngineFrameGateStorage {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38(float);
    char unknown0C[0x3C];
    EngineFrameGateHandle target;
};
struct EngineFrameGateEntry {
    EngineFrameGateNode* object;
    int unknown04, unknown08;
    signed char tag;
    char unknown0D[3];
};
struct EngineFrameGateManager { char unknown00[8]; EngineFrameGateEntry* entries; };
struct EngineFrameGateRoot { char unknown00[0x18]; EngineFrameGateHandle handle; };
struct EngineFrameGateContext {
    char unknown00[0x110];
    void* console;
    int unknown114;
    EngineFrameGateManager* manager;
    int unknown11C, unknown120;
    EngineFrameGateRoot* root;
};

extern "C" {
extern EngineFrameGateContext lbl_801E9D24;
extern char registry_No_Comment[];
extern volatile signed char lbl_80377FB4, lbl_80377FF0;
extern const float lbl_8037AA40;
void fn_801FA014(void* console, const char* format, ...);
void fn_8020B908(void);
void fn_8020B078(void);
void fn_8020C248(void);
signed char fn_801FA1F0(void* console, const char* command);
signed char fn_801EBCC8(void);
signed char fn_8020C0F8(void);
}

#endif
