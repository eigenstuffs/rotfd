/* Scene event callback: dispatches the owner's pending event flags (scene mode
 * select/switch, child flags, menu toggles, music start/stop around the device
 * binding, actor flags and service rebinding).  The music start/stop blocks are
 * the inlined bodies of fn_80057100(primary,-1) and fn_80057294(primary); the
 * names and format strings are addressed through the lbl_8029ACA8 string pool. */
typedef unsigned long Word;

struct Handle_801F7F10 {
    union { Word word; struct { signed int tag:8, index:24; } bits; };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct Node;
struct Entry {
    Node* object; Word unknown04, unknown08; signed char tag; char unknown0D[3];
    signed char getTag() const { return tag; }
};
struct Manager { int count, capacity; Entry* entries; };
struct Service { char unknown00[0x1C]; const Handle_801F7F10* handle; };
struct Secondary { char unknown00[0x24]; Node* target; };
struct Registry { char unknown00[0x15058]; Node* primary; Word unknown1505C; Secondary* secondary; };
struct Device { char unknown00[0x4C]; void* record; Word unknown50; int current; };
struct UIPrefix { char unknown00[0x18]; unsigned char flag18, flag19; char unknown1A[2]; };
struct UI : UIPrefix {
    virtual void slot8(); virtual void slotC(); virtual void slot10(); virtual void slot14();
    virtual void slot18(); virtual void slot1C(); virtual void slot20(); virtual void slot24();
    virtual void slot28(); virtual void slot2C(); virtual void slot30();
    virtual void select(int, int);
    virtual void clear(int, int, int);
};
struct SoundPrefix { char unknown00[0x7C]; };
struct Handle_80020B90;
struct Sound : SoundPrefix {
    virtual void slot8(); virtual void slotC(); virtual void slot10(); virtual void slot14();
    virtual void slot18(); virtual void slot1C(); virtual void slot20(); virtual void slot24();
    virtual void slot28(); virtual void slot2C(); virtual void slot30(); virtual void slot34();
    virtual void slot38(); virtual void slot3C(); virtual void slot40(); virtual void slot44();
    virtual void play(const char*, int, const Handle_80020B90&, const Handle_80020B90&);
    virtual void stop(const char*);
    virtual signed char exists(const char*);
    virtual void slot54(); virtual void slot58(); virtual void slot5C(); virtual void slot60();
    virtual void reset();
    virtual void* getRecord();
};
struct Context {
    char unknown00[0x110]; void* logger; Word unknown114; Manager* manager;
    char unknown11C[8]; Registry* registry; char unknown128[0x14]; Service* service;
    char unknown140[0x14]; UI* ui; Sound* sound; char unknown15C[8]; Device* device;
};
extern "C" {
    extern Context lbl_801E9D24;
    extern char lbl_801EF5C8[];
    extern signed char lbl_80377788, lbl_80377794;
    extern int lbl_803777C4, lbl_803777C8, lbl_803777CC;
    void fn_801EF610(void*, void*);
    void fn_801F86C8(Manager*, const Handle_801F7F10*, short);
    void* fn_801F7EB8(const Handle_801F7F10*);
}
#define DELETE_HANDLE static void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8, p); }
struct Handle_80020478 : Handle_801F7F10 {
    Handle_80020478() { word = 0; }
    Handle_80020478(const Handle_801F7F10& h) { word = h.word; fn_801F86C8(lbl_801E9D24.manager, &h, 1); }
    ~Handle_80020478() {}
    DELETE_HANDLE
};
struct HandleZeroLayer : Handle_801F7F10 {
    HandleZeroLayer() { word = 0; }
    ~HandleZeroLayer() {}
};
struct Handle_80020834 : HandleZeroLayer {
    Handle_80020834() { word = 0; }
    ~Handle_80020834() {}
    DELETE_HANDLE
};
struct Handle_8003E120 : Handle_80020834 {
    Handle_8003E120(const Handle_8003E120& h) { word = h.word; fn_801F86C8(lbl_801E9D24.manager, &h, 1); }
    ~Handle_8003E120() {}
    DELETE_HANDLE
};
struct Handle_8002B67C : Handle_801F7F10 {
    Handle_8002B67C(const Handle_801F7F10& h) { word = h.word; fn_801F86C8(lbl_801E9D24.manager, &h, 1); }
    ~Handle_8002B67C() {}
    DELETE_HANDLE
};
struct Handle_80020B90 : HandleZeroLayer {
    Handle_80020B90() { word = 0; }
    ~Handle_80020B90() {}
    DELETE_HANDLE
};
struct Node {
    Word unknown00; Handle_801F7F10 selfHandle; void* vptr; char unknown0C[0x20];
    float elapsed; char unknown30[0x30];
    Handle_801F7F10 parent; Word unknown64; Handle_801F7F10 secondary; Word unknown6C;
    Handle_801F7F10 action; char unknown74[0x20];
    signed char enabled94; char unknown95[0x1B];
    const Handle_801F7F10* child; char unknownB4[0x3C];
    int mode, substate; char unknownF8[8]; int activeKind; Word unknown104; int current;
    char unknown10C[0x48]; unsigned char flag154; char unknown155[0x197];
    signed char flag2EC; char unknown2ED[9]; unsigned char active; char unknown2F7[0x21];
    signed char enabled318; char unknown319[0xEB]; unsigned char flag404;
    /* Returning the object through an inline keeps &selfHandle materialized. */
    Node* node() { return this; }
};
struct NamePool {
    char music[13][20]; char modes[6][15]; char pad15E[0x584 - 0x15E];
    char format584[0x14]; char format598[0x14];
};
extern "C" const NamePool lbl_8029ACA8;
inline const char* musicName(const NamePool* s, int i)
{
    const char (NamePool::*m)[13][20] = &NamePool::music;
    const char (*rows)[20] = s->*m;
    rows += i;
    return *rows;
}
inline Node* resolve(const Handle_801F7F10& h)
{
    int index = h.bits.index;
    Manager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    return tag == h.bits.tag ? m->entries[index].object : 0;
}
inline Node* checked(const Handle_801F7F10& h) { return fn_801F7EB8(&h) ? resolve(h) : 0; }
extern "C" {
    signed char fn_8025E9FC(Node*, int);
    void fn_80057334(Node*, int);
    void fn_80057AA0(Node*, short, short);
    void fn_800AC70C(Node*, int);
    void fn_8005970C(Node*);
    void fn_8007D6A0(void*, int);
    Handle_8003E120 fn_800BCF58(Registry*, const Handle_8002B67C&);
    void fn_800A7798(Node*);
    signed char fn_8005B0F0(Node*);
    void fn_801FA014(void*, const char*, ...);
    void fn_80208C24(void*);
    void fn_800B6F70(Device*, Word, int, const Handle_80020478&);
    void fn_800B6DA8(Device*, Word, int, const Handle_80020478&);
    void fn_800B6C84(Device*, int, Word);
    void fn_800C2540(Secondary*);
    void fn_800C2700(void*);
    void fn_80285ED8(Node*, int, int);
    int fn_801FF18C(Service*, const Handle_8002B67C&);
    void fn_801FEE10(Service*, int);
    void fn_802073E8(Node*, int, float, Node*);
}
/* Inlined body of fn_80057294. */
inline void stopMusic(const NamePool* s, Node* p)
{
    p->active = 0;
    if (p->current != -1) {
        fn_801FA014(lbl_801E9D24.logger, s->format598, musicName(s, p->current));
        lbl_801E9D24.sound->stop(musicName(s, p->current));
        p->current = -1;
    }
}
/* Inlined body of fn_80057100. */
inline void startMusic(const NamePool* s, Node* p, int requested)
{
    p->active = 1;
    int selected = -1;
    int flag = 0;
    if (p->current != -1 && !lbl_801E9D24.sound->exists(musicName(s, p->current)))
        p->current = -1;
    if (requested > -1) {
        stopMusic(s, p);
        selected = requested;
    } else if (p->current == -1) {
        selected = p->activeKind;
        if (p->mode == 2) selected = 6;
        else if (p->mode == 5) selected = 7;
        if (fn_8005B0F0(p)) selected = 12;
        flag = 2;
    }
    if (selected > -1) {
        const char* name;
        fn_801FA014(lbl_801E9D24.logger, s->format584, name = musicName(s, selected));
        p->current = selected;
        Handle_80020B90 first;
        Handle_80020B90 second;
        lbl_801E9D24.sound->play(name, flag, first, second);
    }
}
extern "C" void fn_8005B1FC(Node* self)
{
    const NamePool* const s = &lbl_8029ACA8;
    if (fn_8025E9FC(self, 0x57))
        fn_80057334(self, (int)self->elapsed);
    if (fn_8025E9FC(self, 0x56)) {
        int n = (int)self->elapsed;
        fn_80057AA0(self, (short)(n >> 16), (short)(n & 0xFFFF));
    }
    if (fn_8025E9FC(self, 0x1F) && fn_801F7EB8(&self->secondary))
        resolve(self->secondary)->flag154 = 1;
    if (fn_8025E9FC(self, 0x5F) && fn_801F7EB8(&self->secondary))
        fn_800AC70C(resolve(self->secondary), 0);
    if (fn_8025E9FC(self, 0xAD)) {
        if (self->mode != 5 || self->substate != 2)
            fn_8005970C(self);
        else
            fn_8007D6A0(&checked(resolve(*resolve(*lbl_801E9D24.service->handle)->child)->action)->enabled318, 6);
    }
    if (fn_8025E9FC(self, 0xC4)) {
        Handle_8002B67C source(*lbl_801E9D24.service->handle);
        Handle_8003E120 held = fn_800BCF58(lbl_801E9D24.registry, source);
        if (!resolve(held)->enabled94) {
            lbl_801E9D24.ui->clear(0, 0, 0);
            fn_800A7798(resolve(self->parent));
            startMusic(s, lbl_801E9D24.registry->primary, -1);
            fn_80208C24(lbl_801E9D24.sound->getRecord());
        } else if (lbl_80377788) {
            lbl_80377794 = 0;
        }
        if (self->enabled318) {
            fn_800B6F70(lbl_801E9D24.device, lbl_803777C8, 0, Handle_80020478(self->node()->selfHandle));
            if (lbl_803777CC == lbl_801E9D24.device->current) {
                fn_800B6DA8(lbl_801E9D24.device, lbl_803777CC, 0,
                            Handle_80020478(lbl_801E9D24.registry->secondary->target->selfHandle));
                fn_800B6C84(lbl_801E9D24.device, 0, lbl_803777CC);
            } else {
                fn_800B6DA8(lbl_801E9D24.device, lbl_803777C4, 0,
                            Handle_80020478(lbl_801E9D24.registry->secondary->target->selfHandle));
                fn_800B6C84(lbl_801E9D24.device, 0, lbl_803777C4);
            }
            fn_800C2540(lbl_801E9D24.registry->secondary);
            stopMusic(s, lbl_801E9D24.registry->primary);
            lbl_801E9D24.sound->reset();
            self->enabled318 = 0;
        } else {
            fn_800B6C84(lbl_801E9D24.device, 0, lbl_801E9D24.device->current);
            fn_800B6F70(lbl_801E9D24.device, lbl_803777C8, 0, Handle_80020478(self->node()->selfHandle));
        }
        fn_800C2700(lbl_801E9D24.device->record);
        lbl_801E9D24.ui->select(0, 0);
        lbl_801E9D24.ui->flag18 = 0;
        lbl_801E9D24.ui->flag19 = 0;
        lbl_801E9D24.ui->flag18 = 1;
        lbl_801E9D24.ui->flag19 = 1;
        if (self->flag2EC)
            lbl_801E9D24.ui->select(0, 1);
    }
    if (fn_8025E9FC(self, 0x74)) {
        fn_80285ED8(self, 0x74, 0);
        checked(resolve(*resolve(*lbl_801E9D24.service->handle)->child)->action)->flag404 = 0;
    }
    if (fn_8025E9FC(self, 0xE3)) {
        Handle_8002B67C source(*lbl_801E9D24.service->handle);
        int v = fn_801FF18C(lbl_801E9D24.service, source);
        fn_801FEE10(lbl_801E9D24.service, v);
        fn_802073E8(self, 0x56, self->elapsed, self);
    }
}
