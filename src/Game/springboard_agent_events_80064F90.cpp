/* Springboard agent queued events (fn_80064F90).
 * 0x97: resolve the primary service's record object, its 0xB0 child and the
 *       child's 0x70 target handle; when the target's flag at 0x420 is set,
 *       post event 0x97 with the target's 0x24 handle to the scene.
 * 0xDD: re-activate the tracked node at 0x70 at the owner's matrix position.
 * 0xDC: copy the queued event, look up the node named by its key in the scene
 *       primary (fn_80058778), place it at an offset from the owner position,
 *       flag it (0x20000), prepare it and re-activate the tracked node.
 * The event copy is a user copy constructor (key default-constructed, then
 * assigned; the four-word array copied in a loop). Handle and resolve idioms
 * follow early_agent_queued_events_800373BC.cpp and
 * engine_record_scene_operation_800EB59C.cpp. */
typedef unsigned long Word;
typedef unsigned long long Wide;
struct Handle_801F7F10 { union { Word word; struct { signed int tag : 8, index : 24; } bits; }; Handle_801F7F10(); ~Handle_801F7F10(); };
struct Entry { char* object; Word key, opaque08; signed char generation; char opaque0D[3]; };
struct Manager { char opaque00[8]; Entry* entries; };
struct Scene { char unknown00[0x15058]; void* primary; };
struct State { Word word; };
struct RecordService { char unknown00[0x1C]; State* state1C; };
extern "C" struct Context {
    char unknown00[0x118];
    Manager* manager;
    char unknown11C[8];
    Scene* scene;
    char unknown128[0x13C - 0x128];
    RecordService* primaryService;
} lbl_801E9D24;
extern "C" const float lbl_80378738, lbl_8037873C, lbl_80378740;
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    Vec3(const Vec3& o) : x(o.x), y(o.y), z(o.z) {}
    Vec3 offset(float dx, float dy, float dz) const { return Vec3(x + dx, y + dy, z + dz); }
};
struct Matrix { float m[16]; Vec3 getPos() const { return Vec3(m[12], m[13], m[14]); } };
struct NodePrefix { char unknown00[8]; };
struct Node : NodePrefix {
    virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14(); virtual void slot18();
    virtual void slot1C(); virtual void slot20(); virtual void slot24(); virtual void slot28(); virtual void slot2C();
    virtual void slot30(); virtual void prepare(); virtual void activate();
    char unknown0C[0x2C];
    Wide flags;
};
struct Owner { char unknown00[0x124]; Matrix* matrix; Vec3 getPos() const { return matrix->getPos(); } };
struct Target { char unknown00[0x24]; Handle_801F7F10 handle24; char unknown28[0x420 - 0x28]; signed char flag420; };
struct Key { Word value; Key() { value = 0; } };
struct Event {
    Word unknown00, unknown04; Key key; float value0C; Word values[4]; Word unknown20, unknown24;
    Event(const Event& o)
    {
        unknown00 = o.unknown00;
        unknown04 = o.unknown04;
        key = o.key;
        value0C = o.value0C;
        for (int i = 0; i < 4; i++) values[i] = o.values[i];
        unknown20 = o.unknown20;
        unknown24 = o.unknown24;
    }
};
struct Self { char unknown00[0x58]; Handle_801F7F10 handle58; char unknown5C[0x14]; Node* field70; };
extern "C" {
    Word fn_801F7EB8(const Handle_801F7F10*);
    signed char fn_8025E9FC(Self*, int);
    Event* fn_8025E548(Self*);
    signed char fn_80255618(Node*);
    void fn_802554F4(Node*);
    void fn_80255678(Node*);
    void fn_80254BB4(Node*, const Vec3&);
    void fn_802603A0(Scene*, int, char*, float);
}
struct Handle_80024844 : Handle_801F7F10 { ~Handle_80024844() {} };
extern "C" Handle_80024844 fn_80058778(void*, const Key&, int);
inline char* resolve(const Handle_801F7F10& h) { int index = h.bits.index; signed char tag = h.bits.tag; Entry* entry = lbl_801E9D24.manager->entries + index; if (entry->generation == tag) return entry->object; return 0; }
inline char* resolveAlternate(const Handle_801F7F10& h) { struct ByteManager { char opaque00[8]; char* entries; }; int index = h.bits.index; signed char tag = h.bits.tag; Entry* entry = (Entry*)(((ByteManager*)lbl_801E9D24.manager)->entries + index * 16); if (entry->generation == tag) return entry->object; return 0; }
extern "C" void fn_80064F90(Self* self)
{
    if (fn_8025E9FC(self, 0x97)) {
        char* object = resolve(*(Handle_801F7F10*)lbl_801E9D24.primaryService->state1C);
        char* child = resolveAlternate(**(Handle_801F7F10**)(object + 0xB0));
        const Handle_801F7F10* handle = (const Handle_801F7F10*)(child + 0x70);
        Target* target;
        if (fn_801F7EB8(handle)) target = (Target*)resolve(*handle);
        else target = 0;
        if (target->flag420) fn_802603A0(lbl_801E9D24.scene, 0x97, resolve(target->handle24), lbl_80378738);
    }
    if (fn_8025E9FC(self, 0xDD)) {
        if (self->field70 && fn_80255618(self->field70)) {
            self->field70->activate();
            fn_802554F4(self->field70);
            fn_80254BB4(self->field70, ((Owner*)resolve(self->handle58))->getPos());
        }
    }
    if (fn_8025E9FC(self, 0xDC)) {
        Event event(*fn_8025E548(self));
        Node* node = (Node*)resolve(fn_80058778(lbl_801E9D24.scene->primary, event.key, 0));
        if (node && self->field70) {
            node->activate();
            fn_802554F4(node);
            fn_80254BB4(node, ((Owner*)resolve(self->handle58))->getPos().offset(lbl_8037873C, lbl_80378740, lbl_8037873C));
            node->flags |= 0x20000ULL;
            node->prepare();
            self->field70->activate();
            fn_80255678(self->field70);
        }
    }
}
