/* Scene event controls (fn_80031740): event gates C2/C4/C5 toggle the agent's
 * stream selection and the primary scene flag; E0/CF reset whichever of the
 * third/first handles currently resolves to the same node as the second.
 * The temporaries live in small inline helpers: that both orders the stack
 * slots (C2 handle 0x14, C4 name 0x10, C5 name 0xC, C5 handle 0x8) and gives
 * the original saved-register coloring. The resolve helper reads the handle
 * tag before the manager and index (signed char comparison). */
typedef unsigned long Word;
struct Handle_801F7F10 {
    union { Word word; struct { signed int tag : 8, index : 24; } bits; };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct Name { Word word; Name(const char*); };
struct Resource { char unknown00[0x80]; Name name; };
struct Node { char unknown00[0x28]; short selected; char unknown2A[0x16]; Resource** resources; };
struct Entry { Node* object; char unknown04[8]; signed char tag; char unknown0D[3]; signed char getTag() const { return tag; } };
struct Manager { int count, capacity; Entry* entries; };
struct Input { Word unknown00; Handle_801F7F10 handle; };
struct Agent { char unknown00[0x24]; Input* input; char unknown28[0x5F8]; Word selected; };
struct Primary { char unknown00[0x319]; unsigned char active; };
struct Scene { char unknown00[0x15058]; Primary* primary; Input* input; Agent* agent; };
struct UI { char unknown00[0x1C]; int* modes; const int& modeRef(int i) const { return modes[i]; } };
extern "C" struct Context {
    char unknown00[0x118]; Manager* manager; char unknown11C[8]; Scene* scene;
    char unknown128[0x164 - 0x128]; UI* ui;
} lbl_801E9D24;
extern "C" { extern char lbl_801EF5C8[]; void fn_801EF610(void*, void*); void fn_801F86C8(Manager*, const Handle_801F7F10*, int); }
struct Handle_80020478 : Handle_801F7F10 {
    Handle_80020478(const Handle_801F7F10& h) { word = h.word; fn_801F86C8(lbl_801E9D24.manager, &h, 1); }
    ~Handle_80020478() {}
    static void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8, p); }
};
struct Owner { char unknown00[0x78]; Handle_801F7F10 first, second; char unknown80[0xC]; Handle_801F7F10 third; };
extern "C" {
signed char fn_8025E9FC(Owner*, int);
extern int lbl_803777C4, lbl_803777BC;
void fn_800B6C84(UI*, int, Word);
void fn_800B6F70(UI*, Word, int, const Handle_80020478&);
void fn_800C2700(Agent*);
void fn_8003FA74(Primary*);
void fn_800B50DC(Node*, int, int, int, float);
void fn_800B5134(Node*, int);
Word fn_801F948C(Name*, const char*);
extern const char lbl_8029A348[];
extern const float lbl_80378410;
}
inline Name::Name(const char* s) { word = fn_801F948C(this, s); }
inline Node* resolve(const Handle_801F7F10& h) {
    signed char tag = h.bits.tag;
    Manager* m = lbl_801E9D24.manager;
    int index = h.bits.index;
    signed char entryTag = m->entries[index].getTag();
    return entryTag == tag ? m->entries[index].object : 0;
}
inline bool same(const Handle_801F7F10& a, const Handle_801F7F10& b) { Node* first = resolve(a); Node* second = resolve(b); return first == second; }
inline bool isTarget(Node* n) { Name selected = n->resources[n->selected]->name; return selected.word == Name(lbl_8029A348).word; }
inline void showAgent(Agent* a) {
    fn_800B6C84(lbl_801E9D24.ui, 0, a->selected);
    fn_800B6F70(lbl_801E9D24.ui, lbl_803777C4, 0, Handle_80020478(lbl_801E9D24.scene->input->handle));
    fn_800C2700(a);
}
inline void hideAgent() {
    fn_800B6F70(lbl_801E9D24.ui, lbl_803777C4, 0, Handle_80020478(lbl_801E9D24.scene->agent->input->handle));
    fn_800B6C84(lbl_801E9D24.ui, 0, lbl_803777BC);
    fn_800C2700(lbl_801E9D24.scene->agent);
}

extern "C" void fn_80031740(Owner* self) {
    if (fn_8025E9FC(self, 0xC2) && lbl_803777C4 == lbl_801E9D24.ui->modeRef(0)) showAgent(lbl_801E9D24.scene->agent);
    if (fn_8025E9FC(self, 0xC4)) {
        if (isTarget(resolve(self->second))) { Primary* primary = lbl_801E9D24.scene->primary; primary->active = 1; fn_8003FA74(primary); }
    } else if (fn_8025E9FC(self, 0xC5)) {
        if (isTarget(resolve(self->second))) hideAgent();
    }
    if (fn_8025E9FC(self, 0xE0)) {
        if (same(self->third, self->second)) fn_800B50DC(resolve(self->third), 0, 0, 100, lbl_80378410);
        else if (same(self->first, self->second)) fn_800B50DC(resolve(self->first), 0, 0, 100, lbl_80378410);
    }
    if (fn_8025E9FC(self, 0xCF)) {
        if (same(self->third, self->second)) fn_800B5134(resolve(self->third), 0);
        else if (same(self->first, self->second)) fn_800B5134(resolve(self->first), 0);
    }
}
