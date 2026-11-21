// Original hierarchy console command registration and final-list search.
typedef unsigned long u32;
struct Console;
struct Object;
struct Handle {
    union { u32 value; struct { signed int generation:8; signed int index:24; } bits; };
};
struct Entry { Object* object; u32 unknown[2]; signed char generation; char padding[3]; };
struct Manager { u32 unknown[2]; Entry* entries; };
struct Globals { char unknown[0x110]; Console* console; void* game; Manager* manager; };
struct HandleList { int count, capacity; Handle* data; };
struct Hierarchy { char unknown[0xD0]; HandleList finalList; };
typedef int (*ConsoleCallback)();
extern "C" {
extern Globals lbl_801E9D24;
// Shared original literal pool view; all underlying storage remains external.
extern const char lbl_802AD958[];
extern const char lbl_8037A938[8], lbl_8037A940[7], lbl_8037A948[8], lbl_8037A950[8];
void fn_801FAC64(Console*, const char*, ConsoleCallback, const char*);
Object* fn_801F7EB8(Handle*);
signed char fn_8025CEA4(Object*, const Handle*);
void fn_80206500();
signed char fn_802056DC();
signed char fn_802055A8();
signed char fn_802042EC();
void fn_802064DC();
signed char fn_80205964();
signed char fn_80205810();
void fn_802062D0();
void fn_802062AC();
signed char fn_80205D98();
signed char fn_80204CC0();
signed char fn_80205A98();
signed char fn_80205C18();
signed char fn_80204AA8();
signed char fn_80204F80();
signed char fn_80204E38();
void fn_80204760();
void fn_8020478C();
void fn_80204734();
signed char fn_80204580();
signed char fn_802043FC();
signed char fn_80204184();
signed char fn_80203B10();
signed char fn_80204000();
}

extern "C" void fn_80206524() {
    const char* const strings = lbl_802AD958;
    // SetGame:  WorldName NbPlayers [AgentCameraClassName=CameraGame]
    fn_801FAC64(lbl_801E9D24.console, lbl_8037A938, (ConsoleCallback)fn_80206500, strings + 0x50);
    // ActivateGame:  WorldName
    fn_801FAC64(lbl_801E9D24.console, strings + 0x88, (ConsoleCallback)fn_802056DC, strings + 0x98);
    // DeactivateGame:  WorldName
    fn_801FAC64(lbl_801E9D24.console, strings + 0xA4, (ConsoleCallback)fn_802055A8, strings + 0x98);
    // RemoveGame:  WorldName 
    fn_801FAC64(lbl_801E9D24.console, strings + 0xB4, (ConsoleCallback)fn_802042EC, strings + 0xC0);
    // SetMonoGame:  WorldName NbPlayers [AgentCameraClassName=CameraGame]
    fn_801FAC64(lbl_801E9D24.console, strings + 0xCC, (ConsoleCallback)fn_802064DC, strings + 0x50);
    // SwitchGameToMono:  WorldName
    fn_801FAC64(lbl_801E9D24.console, strings + 0xD8, (ConsoleCallback)fn_80205964, strings + 0x98);
    // SwitchGameToMUlti:  WorldName NbVp
    fn_801FAC64(lbl_801E9D24.console, strings + 0xEC, (ConsoleCallback)fn_80205810, strings + 0x100);
    // AddGamePlayer:  WorldName PlayerId(1-MAX_NUMBER_OF_PLAYERS) PlayerName [TeamId=0]
    fn_801FAC64(lbl_801E9D24.console, strings + 0x110, (ConsoleCallback)fn_802062D0, strings + 0x120);
    // AddMenuPlayer:  WorldName PlayerId(1-MAX_NUMBER_OF_PLAYERS) PlayerName [TeamId=0]
    fn_801FAC64(lbl_801E9D24.console, strings + 0x164, (ConsoleCallback)fn_802062AC, strings + 0x120);
    // ReMoveGamePlayer:  WorldName PlayerId(1-MAX_NUMBER_OF_PLAYERS)
    fn_801FAC64(lbl_801E9D24.console, strings + 0x174, (ConsoleCallback)fn_80205D98, strings + 0x188);
    // REsetGame:  VpId(1-MAX_VIEWPORT)
    fn_801FAC64(lbl_801E9D24.console, strings + 0x1B8, (ConsoleCallback)fn_80204CC0, strings + 0x1C4);
    // DeactivateGamePlayer:  WorldName PlayerId(1-MAX_NUMBER_OF_PLAYERS)
    fn_801FAC64(lbl_801E9D24.console, strings + 0x1DC, (ConsoleCallback)fn_80205A98, strings + 0x188);
    // ACtivateGamePlayer:  WorldName PlayerId(1-MAX_NUMBER_OF_PLAYERS)
    fn_801FAC64(lbl_801E9D24.console, strings + 0x1F4, (ConsoleCallback)fn_80205C18, strings + 0x188);
    // PlayerGotoCoord:   X Y Z Viewport
    fn_801FAC64(lbl_801E9D24.console, strings + 0x208, (ConsoleCallback)fn_80204AA8, strings + 0x218);
    // SwitchCameraUser:  ViewPortId
    fn_801FAC64(lbl_801E9D24.console, strings + 0x22C, (ConsoleCallback)fn_80204F80, strings + 0x240);
    // SetPersoCamera:  ViewPortId
    fn_801FAC64(lbl_801E9D24.console, strings + 0x24C, (ConsoleCallback)fn_80204E38, strings + 0x240);
    // MakeCameraPatch:  ViewPortId PatchMax Step
    fn_801FAC64(lbl_801E9D24.console, strings + 0x25C, (ConsoleCallback)fn_80204760, strings + 0x26C);
    // MakeCameraFrame:  ViewPortId FrameRate Step
    fn_801FAC64(lbl_801E9D24.console, strings + 0x288, (ConsoleCallback)fn_8020478C, strings + 0x298);
    // MakeCameraTexture:  ViewPortId Step
    fn_801FAC64(lbl_801E9D24.console, strings + 0x2B4, (ConsoleCallback)fn_80204734, strings + 0x2C8);
    // EndCameraCapture:  ViewPortId
    fn_801FAC64(lbl_801E9D24.console, strings + 0x2DC, (ConsoleCallback)fn_80204580, strings + 0x240);
    // ResetCameraZone:  ViewPortId
    fn_801FAC64(lbl_801E9D24.console, strings + 0x2F0, (ConsoleCallback)fn_802043FC, strings + 0x240);
    // SetRTC:  WorldName RtcNb
    fn_801FAC64(lbl_801E9D24.console, lbl_8037A940, (ConsoleCallback)fn_80204184, strings + 0x300);
    // LoadRTC:  WorldName RtcId RtcName [AgentRtcClassName=RtcGame]
    fn_801FAC64(lbl_801E9D24.console, lbl_8037A948, (ConsoleCallback)fn_80203B10, strings + 0x314);
    // PlayRTC:  WorldName RtcId [ViewPortId]
    fn_801FAC64(lbl_801E9D24.console, lbl_8037A950, (ConsoleCallback)fn_80204000, strings + 0x34C);
}

static inline Object* resolve(const Handle& h) {
    Entry* entry = lbl_801E9D24.manager->entries + h.bits.index;
    return entry->generation == h.bits.generation ? entry->object : 0;
}

extern "C" int fn_802067A0(Hierarchy* self, const Handle* handle) {
    for (int i = 0; i < self->finalList.count; ++i) {
        if (fn_801F7EB8(&self->finalList.data[i])) {
            if (fn_8025CEA4(resolve(self->finalList.data[i]), handle))
                return i;
        }
    }
    return -1;
}
