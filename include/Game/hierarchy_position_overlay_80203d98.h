#ifndef GAME_HIERARCHY_POSITION_OVERLAY_80203D98_H
#define GAME_HIERARCHY_POSITION_OVERLAY_80203D98_H

// Partial views observed by the original hierarchy-position overlay.
namespace HierarchyPositionOverlay80203D98 {
// Reconstructed hierarchy position overlay from the original GSQE78 instructions.
typedef unsigned long u32;
struct OverlayHandle {
    union {
        u32 value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
};
struct OverlayList { int count, capacity; OverlayHandle* data; };
struct ObjectStorage { char unknown[8]; };
struct OverlayObject : ObjectStorage {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual int viewIndex();
    char unknownC[0x58 - 0xC]; OverlayHandle transform;
    char unknown5C[0xA8 - 0x5C]; OverlayList secondary;
    char unknownB4[4]; float x, y, z;
    char unknownC4[0xDC - 0xC4]; int count, activeCount, offset;
};
struct ResourceEntry {
    OverlayObject* object; u32 unknown[2]; signed char generation; char padding[3];
};
struct Manager { u32 unknown[2]; ResourceEntry* entries; };
struct OverlayGlobals { char unknown[0x104]; u32 flags; char unknown108[0x10]; Manager* manager; };
extern "C" OverlayGlobals lbl_801E9D24;
static inline OverlayObject* resolve(const OverlayHandle& handle) {
    ResourceEntry* entry = lbl_801E9D24.manager->entries + handle.bits.index;
    return entry->generation == handle.bits.generation ? entry->object : 0;
}
struct View { char unknown[0x4C]; };
struct RendererStorage { View views[4]; char unknown130[0x278 - 0x130]; };
struct Position { float x, y; Position(float px, float py) : x(px), y(py) {} };
struct Color { float r, g, b, a; };
struct Renderer : RendererStorage {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void draw(const Position&, const char*, const Color&);
};
// Inferred partial address representation: one target-width word caches a renderer
// pointer and converts it back unchanged. The original wrapper class is unknown.
struct RendererReceiver { u32 value; RendererReceiver(Renderer* p):value(reinterpret_cast<u32>(p)){} View* view(int i)const{return &reinterpret_cast<Renderer*>(value)->views[i];} void draw(const Position& p,const char* text,const Color& c)const{reinterpret_cast<Renderer*>(value)->draw(p,text,c);} };
struct OverlayContext { char unknown[0x48]; Renderer* renderer; };
struct OverlayGroup { char unknown[0x14]; OverlayList entries; };
extern "C" {
u32 fn_801F7EB8(const void*);
void fn_801E2E70(View*, int*, int*, int*, int*);
void fn_801BA714(char*, const char*, ...);
extern const char lbl_802AD970[];
extern Color lbl_8033E738;
extern const float lbl_8037A928, lbl_8037A92C;
}
}
extern "C" void fn_80203D98(HierarchyPositionOverlay80203D98::OverlayGroup*, HierarchyPositionOverlay80203D98::OverlayContext*);
#endif
