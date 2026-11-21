/* Merged translation unit: Game/scalar_constant_80379330.c, Game/scalar_constant_80379340.c, part_800B3344, Game/early_actor_record_dispatch_800b3b94.cpp, Game/scene_leaf_more_control_800B3C68.cpp, Game/world_menu_item_lookup_800B3C8C.cpp, Game/scalar_distance_query_800B3E00.cpp, Game/scalar_early_more_800B3E58.c, Game/engine_scalar_last_800B3FC8.cpp, Game/selection_record_find_800B409C.cpp, Game/scalar_early_800B41A0.c, part_800B423C. */
/* ---- part_800B3344 ---- */
typedef unsigned long Word;
struct Handle_801F7F10 { union { Word word; struct { signed int tag : 8, index : 24; } bits; }; Handle_801F7F10(); ~Handle_801F7F10(); int getIndex() const { return bits.index; } signed char getTag() const { return bits.tag; } int getTagI() const { return bits.tag; } };
struct Handle_8001FF78 : Handle_801F7F10 { Handle_8001FF78() { word = 0; } ~Handle_8001FF78() {} };
namespace part_800B3344 {
// Menu bounds setup (fn_800B3344): viewport-inset bounds, random sparkle records,
// optional frame-object bounds and optional projected mesh quad bounds.
struct Entry { void* object; char unknown04[8]; signed char tag; char unknown0D[3]; signed char getTag() const { return tag; } };
struct Manager { char unknown00[8]; Entry* entries; };
struct Viewport { char unknown00[0x4C]; };
struct Globals { char unknown00[0x114]; Viewport* viewports; Manager* manager; };
struct Vec2 { float x, y; Vec2() {} Vec2(float a, float b) : x(a), y(b) {} };
inline float reciprocalSqrt(register float value) { register float result; asm { frsqrte result, value } return result; }
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3 operator-(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    void normalize() { float r = reciprocalSqrt(x * x + y * y + z * z); x *= r; y *= r; z *= r; }
};
struct Matrix4 { float m[4][4]; };
struct Query { signed char hit; char unknown01[3]; Vec3 a; Vec3 b; float fov; char unknown20[0x20]; };
extern "C" {
extern Globals lbl_801E9D24;
extern char lbl_801EF5C8[];
extern const Vec3 game_vec3_zero;
extern const float lbl_803792F0, lbl_803792F8, lbl_803792FC, lbl_80379300, lbl_80379304, lbl_80379308, lbl_8037930C, lbl_80379310, lbl_80379314, lbl_80379320, lbl_80379324, lbl_80379328, lbl_8037932C;
void fn_801EF610(void*, void*);
void fn_801F86C8(Manager*, const Handle_801F7F10*, short);
void* fn_801F7EB8(const Handle_801F7F10*);
void fn_801E2E70(Viewport*, int*, int*, int*, int*);
float fn_801F1200();
void fn_80239A7C(void*);
void fn_802397E0(void*);
void fn_801D8980(void*, Vec3*);
signed char fn_80269A64(void*, const Handle_801F7F10&, const Vec3*, Query*);
void fn_801F18D0(const Vec3*, const Vec3*, Matrix4*);
void fn_801F230C(const Matrix4*, Matrix4*);
Matrix4* fn_801F2788(Matrix4*, const Matrix4*);
float fn_80284E34(float);
}
struct HandleRef : Handle_8001FF78 {
    HandleRef(const Handle_801F7F10& h) { word = h.word; fn_801F86C8(lbl_801E9D24.manager, &h, 1); }
    ~HandleRef() {}
};
inline void* resolve(const Handle_801F7F10& h) {
    int index = h.bits.index;
    Manager* m = lbl_801E9D24.manager;
    return m->entries[index].getTag() == h.getTag() ? m->entries[index].object : 0;
}
inline void* resolve2(const Handle_801F7F10& h) {
    int index = h.bits.index;
    Manager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    if (tag == h.bits.tag) return m->entries[index].object;
    return 0;
}
struct Frame { char unknown00[0x30]; int halfW, halfH; char unknown38[0x3C]; Handle_801F7F10 h74; char unknown78[0x40]; Handle_801F7F10 hB8; };
struct Mesh { char unknown00[0x6C]; unsigned short kind; };
struct Node { char unknown00[0x1C]; Handle_801F7F10 mesh; char unknown20[0x104]; Matrix4* world; };
struct Spark { float a, b, c, d, e; };
struct Menu {
    char unknown00[0x20];
    Handle_801F7F10 h20;
    char unknown24[0x10];
    unsigned char viewport;
    char unknown35[0x17];
    Handle_801F7F10 h4C;
    char unknown50[4];
    Vec2 min, max;
    float z;
    void setBounds2(const Vec2& a, const Vec2& b) { min = a; max = b; }
    void setBounds(float a, float b, float c, float d) { min.x = a; min.y = b; max.x = c; max.y = d; }
    char unknown68[0xC];
    Handle_801F7F10 h74;
    char unknown78[0x48];
    Spark sparks[10];
};
extern "C" void fn_800B3344(Menu* self) {
    int x, y, w, h;
    int i;
    fn_801E2E70(&lbl_801E9D24.viewports[self->viewport], &x, &y, &w, &h);
    self->min = Vec2((float)(x + 16), (float)(y + 16));
    self->max = Vec2((float)(w - 16), (float)(h - 16));
    for (i = 0; i < 10; i++) {
        self->sparks[i].d = lbl_80379304 * fn_801F1200();
        self->sparks[i].c = lbl_80379308 * fn_801F1200();
        self->sparks[i].a = lbl_8037930C * fn_801F1200();
        self->sparks[i].b = lbl_80379310;
        self->sparks[i].e = lbl_80379314 * (lbl_803792FC + fn_801F1200());
    }
    if (fn_801F7EB8(&self->h74)) {
        fn_80239A7C(resolve(self->h74));
        fn_802397E0(resolve(self->h74));
        HandleRef ref(((Frame*)resolve(((Frame*)resolve(self->h74))->hB8))->h74);
        Frame* f = (Frame*)resolve(ref);
int fw = f->halfW;
 int fh = f->halfH;
 int hw = w >> 1;
 int hh = h >> 1;
self->setBounds((float)(hw - fw), (float)(hh - fh), (float)(hw + fw), (float)(hh + fh));
    }
    if (fn_801F7EB8(&self->h4C) && fn_801F7EB8(&((Node*)resolve(self->h4C))->mesh) &&
        ((Mesh*)resolve(((Node*)resolve(self->h4C))->mesh))->kind == 1) {
        Vec3 corners[4];
        Query q;
        Matrix4 view;
        Matrix4 inv;
        Vec3 out[4];
        fn_801D8980(resolve(((Node*)resolve(self->h4C))->mesh), corners);
        q.hit = 0;
        fn_80269A64(resolve2(self->h20), self->h4C, &game_vec3_zero, &q);
        Vec3 dir = q.a - q.b;
        Vec3 up; up.x = lbl_80379300; up.y = lbl_803792F0; up.z = up.x;
        dir.normalize();
        fn_801F18D0(&dir, &up, &view);
        view.m[3][0] = q.b.x;
        view.m[3][1] = q.b.y;
        view.m[3][2] = q.b.z;
        fn_801F230C(&view, &inv);
        fn_801F2788(&inv, ((Node*)resolve(self->h4C))->world);
        float scale = (float)h / (lbl_80379320 * fn_80284E34(q.fov * lbl_803792F8));
        self->z = lbl_80379324;
        self->min.x = lbl_80379328;
        self->min.y = lbl_80379328;
        self->max.x = lbl_8037932C;
        self->max.y = lbl_8037932C;
        for (i = 0; i < 4; i++) {
            out[i].x = inv.m[3][0] + (inv.m[0][0] * corners[i].x + inv.m[1][0] * corners[i].y + inv.m[2][0] * corners[i].z);
            out[i].y = inv.m[3][1] + (inv.m[0][1] * corners[i].x + inv.m[1][1] * corners[i].y + inv.m[2][1] * corners[i].z);
            out[i].z = inv.m[3][2] + (inv.m[0][2] * corners[i].x + inv.m[1][2] * corners[i].y + inv.m[2][2] * corners[i].z);
            if (out[i].z < self->z) self->z = out[i].z;
            float iz = lbl_803792F0 / out[i].z;
            out[i].x = (float)(w / 2) + iz * (scale * out[i].x);
            out[i].y = (float)(h / 2) + iz * (scale * -out[i].y);
            if (out[i].x < self->min.x) self->min.x = out[i].x;
            if (out[i].y < self->min.y) self->min.y = out[i].y;
            if (out[i].x > self->max.x) self->max.x = out[i].x;
            if (out[i].y > self->max.y) self->max.y = out[i].y;
        }
        self->z -= 0.009999999776482582f;
    }
}

}
/* ---- Game/early_actor_record_dispatch_800b3b94.cpp ---- */
namespace early_actor_record_dispatch_800b3b94 {
#include "Game/early_actor_record_dispatch_views.h"
extern "C"void fn_800B3B94(RecordDispatchQuery*self,int index,void*output){unsigned long values[10];RecordDispatchRecord*record;for(int i=0;i<(record=&self->records[index])->count;++i)values[i]=resolveActor(self->handle)->query(record->key,record->handles[i]);fn_801F44DC(output,record,values);}

}
/* ---- Game/scene_leaf_more_control_800B3C68.cpp ---- */
namespace scene_leaf_more_control_800B3C68 {
#include "Game/scene_leaf_more_controls.h"

extern "C" void fn_800B3C68(SceneLeafMore::KeyOwner* self,int key){self->key=key;fn_800B3FC8(self);}

}
/* ---- Game/world_menu_item_lookup_800B3C8C.cpp ---- */
namespace world_menu_item_lookup_800B3C8C {
// World menu item lookup (fn_800B3C8C): maps the world index (+0x188) to its
// WORLD_* name from the pooled strings at lbl_802A0400 (base register; offset 0
// reached through a member pointer for the original addi r4,r4,0) and returns the
// first 0xC4-byte item in [first, first+count) whose name (+0x80) matches.
// The switch jump table is compiler-generated (EXACT-DATA -> jumptable_802BD720).
typedef unsigned long Word;
extern "C" Word fn_801F948C(void*,const char*);
struct Name{Word word;Name(){word=0;}Name(const char*s){word=fn_801F948C(this,s);}
 Name&operator=(const Name&n){word=n.word;return*this;}
 bool operator==(const Name&n)const{return word==n.word;}};
struct Item{char unknown00[0x80];Name name;char unknown84[0x40];};
struct Owner{char unknown00[0x2C];short first;char unknown2E[0x18];unsigned short count;char unknown48[0x28];Item*items;char unknown74[0x114];unsigned long world;
 Item*find(Name key){for(int i=first;i<first+count;++i){Item*item=&items[i];if(item->name==key)return item;}return 0;}};
struct Strings{char bb[12];char jf[12];char ca[12];char dn[12];char gl[12];char dg[12];char td[12];char test[12];};
extern "C" const Strings lbl_802A0400;
inline const char*worldBB(const Strings*s){const char(Strings::*m)[12]=&Strings::bb;return s->*m;}
extern "C" Item*fn_800B3C8C(Owner*self){
 const Strings*const s=&lbl_802A0400;
 Name key;
 switch(self->world){
 case 0:key=Name(worldBB(s));break;
 case 1:key=Name(s->jf);break;
 case 2:key=Name(s->ca);break;
 case 3:key=Name(s->dn);break;
 case 4:key=Name(s->gl);break;
 case 5:key=Name(s->dg);break;
 case 6:key=Name(s->td);break;
 case 7:key=Name(s->test);break;
 }
 Item*found=self->find(key);
 Item*result=0;
 if(found)result=found;
 return result;
}

}

/* ---- Game/scalar_distance_query_800B3E00.cpp ---- */
namespace scalar_distance_query_800B3E00 {
/* Original scalar distance and query leaves; see docs/notes/game-scalar-distance-query-leafs.md. */
struct Record{char opaque00[0xC];char text[0x40];signed char active;char opaque4D[3];};extern "C"{extern Record lbl_802F4208[300];extern const char lbl_802A0460[];}extern "C"const char*fn_800B3E00(void*ignored,int index){Record*record=0;const char*text=0;if(index>=0&&index<300)record=&lbl_802F4208[index];if(record&&record->active)text=record->text;if(!text)text=lbl_802A0460;return text;}

}

/* ---- Game/scalar_early_more_800B3E58.c ---- */
namespace scalar_early_more_800B3E58 {
extern "C" {
/* Original array and scalar routines with private observed layouts.
 * See docs/notes/game-scalar-early-more.md. */

struct Record {int key,group;char pad[0x44];signed char enabled;char tail[3];};

extern struct Record lbl_802F4208[300];

struct RecordSelection {char pad[0x188];int group;int indices[6];};

int fn_800B3E58(struct RecordSelection *object) {int found=0;int i;int index=object->indices[0];while(--index>=0)if(object->group==lbl_802F4208[index].group && lbl_802F4208[index].enabled==1){object->indices[0]=index;found=1;break;}for(i=1;i<6;++i){index=object->indices[i-1];while(++index<300)if(object->group==lbl_802F4208[index].group && lbl_802F4208[index].enabled==1){object->indices[i]=index;break;}}return found;}

int fn_800B3F10(struct RecordSelection *object) {int found=0;int i;int index=object->indices[5];while(++index<300)if(object->group==lbl_802F4208[index].group && lbl_802F4208[index].enabled==1){object->indices[5]=index;found=1;break;}for(i=4;i>=0;--i){index=object->indices[i+1];while(--index>=0)if(object->group==lbl_802F4208[index].group && lbl_802F4208[index].enabled==1){object->indices[i]=index;break;}}return found;}

}

}

/* ---- Game/engine_scalar_last_800B3FC8.cpp ---- */
namespace engine_scalar_last_800B3FC8 {
/* Original scalar flag and fixed-record operations; see docs/notes/game-engine-scalar-last.md. */
struct Record{int unknown00,key04;char unknown08[0x4C-8];signed char enabled4C;char unknown4D[3];};extern "C" Record lbl_802F4208[300];
struct Owner{char unknown00[0x188];int key188;int results18C[6];};
extern "C" void fn_800B3FC8(Owner*self){int j=0;for(int i=0;i<6;i++)self->results18C[i]=-1;for(;j<300;j++){if(self->key188==lbl_802F4208[j].key04&&lbl_802F4208[j].enabled4C==1){self->results18C[0]=j;break;}}for(int i=1;i<6;i++){int j=self->results18C[i-1];while(++j<300){if(self->key188==lbl_802F4208[j].key04&&lbl_802F4208[j].enabled4C==1){self->results18C[i]=j;break;}}}}

}

/* ---- Game/selection_record_find_800B409C.cpp ---- */
namespace selection_record_find_800B409C {
// Select a typed scene record by key, notify once and update its text view.
#include "Game/scene_static_records.h"
struct Handle{signed int tag:8,index:24;};struct Text{char unknown00[0x48];const char*text;float time;};struct State{char unknown00[0x60];Handle text;};struct Scene{char unknown00[0x15058];State*state;};struct Entry{Text*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};struct Manager{char unknown00[8];Entry*entries;};extern "C"struct Context{char unknown00[0x118];Manager*manager;char unknown11C[8];Scene*scene;}lbl_801E9D24;extern "C"{void fn_80059340(State*,int);}inline Text*resolve(const Handle&h){int index=h.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
struct SelectionRecordArrayView{SceneSelectionRecord(&records)[300];SelectionRecordArrayView(SceneSelectionRecord(&r)[300]):records(r){}SceneSelectionRecord*find(int key)const{SceneSelectionRecord*record=0;for(int i=0;i<300;++i){SceneSelectionRecord*item=&records[i];if(key==item->key){record=item;break;}}return record;}};
extern "C"void fn_800B409C(int key){SelectionRecordArrayView records(lbl_802F4208);SceneSelectionRecord*record=records.find(key);if(record){State*state=lbl_801E9D24.scene->state;if(key<700&&!record->enabled)fn_80059340(state,0x2B);record->enabled=1;Text*target=resolve(state->text);if(target->text!=record->text){target->text=record->text;target->time=4.0f;}}}
}
/* ---- Game/scalar_early_800B41A0.c ---- */
namespace scalar_early_800B41A0 {
extern "C" {
/* Original scalar operations with private observed layouts.
 * See docs/notes/game-scalar-early.md. */

struct GlobalRecord {int key;char pad4[0x48];signed char enabled,previous,changed;char tail;};

extern struct GlobalRecord lbl_802F4208[300];

static inline struct GlobalRecord *find_record(int key) {int i;struct GlobalRecord *found=0;for(i=0;i<300;++i)if(key==lbl_802F4208[i].key){found=&lbl_802F4208[i];break;}return found;}

void fn_800B41A0(int key) {struct GlobalRecord *found=find_record(key);if(found){found->changed=1;found->enabled=1;}}

void fn_800B41F0(int key) {struct GlobalRecord *found=find_record(key);if(found){found->changed=0;}}

}

}

/* ---- part_800B423C ---- */
namespace part_800B423C {
// Menu item layout (fn_800B423C): groups "cell" items (flags&0x38==0x38) sharing a
// (col,row) cell into stacks and places them; then lays out the remaining items.
extern "C" void* memset(void*, int, unsigned long);
struct Font { char unknown00[8]; int* lineHeight; };
struct FontTable { char unknown00[0x24]; Font* fonts; };
struct Globals { char unknown00[0x14C]; FontTable* table; };
extern "C" Globals lbl_801E9D24;
extern "C" const float lbl_803792F8;
struct Vec2 { float x, y; };
struct Item {
    char unknown00[0x8C];
    unsigned short flags;
    char unknown8E[0x22];
    unsigned char col, row, unknownB2, lines;
    Vec2 pos;
    char unknownBC[8];
};
struct Owner {
    char unknown00[0x2C];
    short first;
    char unknown2E[0x18];
    unsigned short count;
    char unknown48[8];
    unsigned char topLines;
    char unknown51[3];
    float x0, y0, x1, y1;
    char unknown64[0xC];
    Item* items;
    char unknown74[8];
    unsigned char font;
};
inline void set(float& x, float& y, float a, float b) { x = a; y = b; }
inline float mulf(float a, float b) { return a * b; }
extern "C" void fn_800B423C(Owner* self) {
    int groups[30][8];
    int counts[30];
    int i, j, k;
    float x, y;
    Font* font = &lbl_801E9D24.table->fonts[self->font];
    int n = 0;
    memset(counts, 0, sizeof(counts));
    for (i = self->first; i < self->first + self->count; i++) {
        Item* item = &self->items[i];
        if (!(item->flags & 2) && (item->flags & 0x38) == 0x38) {
            char found = 0;
            for (j = 0; j < n; j++) {
                for (k = 0; k < counts[j]; k++) {
                    if (self->items[i].col == self->items[groups[j][k]].col &&
                        self->items[i].row == self->items[groups[j][k]].row) {
                        found = 1;
                        break;
                    }
                }
                if (found) {
                    groups[j][counts[j]++] = i;
                }
            }
            if (!found) {
                groups[n][counts[n]++] = i;
                n++;
            }
        }
    }
    for (j = 0; j < n; j++) {
        Item* item = &self->items[groups[j][0]];
        float h = self->y1 - self->y0;
        float w = self->x1 - self->x0;
        y = self->y0 + h * (float)item->row / 100.0f;
        int c = counts[j];
        y -= (float)(c * *font->lineHeight / 2);
        x = self->x0 + w * (float)item->col / 100.0f;
        item->pos.x = x;
        item->pos.y = y;
        for (k = 1; k < counts[j]; k++) {
            y += (float)*font->lineHeight;
            Vec2* p = &self->items[groups[j][k]].pos;
            p->x = x;
            p->y = y;
        }
    }
    y = self->y0 + (float)self->topLines * (float)*lbl_801E9D24.table->fonts[0].lineHeight;
    for (int m = self->first; m < self->first + self->count; m++) {
        if (!(self->items[m].flags & 2) && (self->items[m].flags & 0x38) != 0x38) {
            Item* item = &self->items[m];
            y -= (float)(item->lines - 1) * (float)*font->lineHeight;
            if ((item->flags & 0x18) == 0x18) {
                x = mulf(self->x0 + self->x1, lbl_803792F8);
            } else if (item->flags & 8) {
                x = self->x0;
            } else if (item->flags & 0x10) {
                x = self->x1;
            }
            item->pos.x = x;
            item->pos.y = y;
        }
    }
}

}

