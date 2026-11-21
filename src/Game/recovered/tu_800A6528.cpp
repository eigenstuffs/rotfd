/* Merged translation unit for .text 0x800A5D68-0x800A8E8C: the text-record owner
   (Object_800A6090) construction/destruction, record layout, per-frame update,
   formatting, rendering and the random record grid.  .sdata2 0x80378F78-0x80379000
   holds this unit's pooled literals in first-use order. */
#pragma readonly_strings on
#pragma fp_contract on
typedef unsigned long Word;
extern "C" {
extern char lbl_801EF5C8[];
void fn_801EF610(void*, void*);
void fn_801F86C8(void*, const void*, int);
void __dt__11Activable_ZFv(void*, int);
}
struct SharedEntry { void* object; char unknown04[8]; signed char tag; char unknown0D[3]; };
struct SharedManager { int count, capacity; SharedEntry* entries; };
/* One declaration of the engine context for the whole unit: the inline handle
   constructors and the functions' own reads must address the same object type,
   or mwcc stops sharing the &lbl_801E9D24 base register between them.  Parts view
   the untyped fields through their own pointer types. */
struct SharedContext {
    char unknown00[0x114];
    void* p114;
    SharedManager* manager;
    char unknown11C[8];
    void* p124;
    char unknown128[0x14];
    void* p13C;
    char unknown140[0xC];
    void* p14C;
    char unknown150[4];
    void* p154;
};
extern "C" SharedContext lbl_801E9D24;

struct Handle_801F7F10 {
    union { Word word; struct { signed int tag : 8, index : 24; } bits; };
    Handle_801F7F10();
    ~Handle_801F7F10();
    static void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8, p); }
};
struct Handle_8001FF78 : Handle_801F7F10 { Handle_8001FF78() { word = 0; } ~Handle_8001FF78() {} static void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8, p); } };
struct Handle_80020478 : Handle_801F7F10 { Handle_80020478() { word = 0; } ~Handle_80020478() {} static void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8, p); } };
struct Handle_80020834 : Handle_80020478 {
    Handle_80020834() { word = 0; }
    Handle_80020834(const Handle_80020478& h) { word = h.word; fn_801F86C8(lbl_801E9D24.manager, &h, 1); }
    ~Handle_80020834() {}
    Handle_80020834& operator=(const Handle_80020834& h) { fn_801F86C8(lbl_801E9D24.manager, this, -1); word = h.word; fn_801F86C8(lbl_801E9D24.manager, &h, 1); return *this; }
    static void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8, p); }
};
struct Handle_800723F4 : Handle_80020478 {
    Handle_800723F4() { word = 0; }
    Handle_800723F4(int) { word = 0; }
    ~Handle_800723F4() {}
    Handle_800723F4& operator=(const Handle_800723F4& h) { fn_801F86C8(lbl_801E9D24.manager, this, -1); word = h.word; fn_801F86C8(lbl_801E9D24.manager, &h, 1); return *this; }
    static void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8, p); }
};
struct Handle_80021BCC : Handle_80020478 { Handle_80021BCC() { word = 0; } ~Handle_80021BCC() {} static void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8, p); } };
struct Handle_8002F6B0 : Handle_80021BCC { Handle_8002F6B0(const Handle_801F7F10& h) { word = h.word; fn_801F86C8(lbl_801E9D24.manager, &h, 1); } ~Handle_8002F6B0() {} };
struct Handle_80052930 : Handle_801F7F10 { Handle_80052930(const Handle_801F7F10& h) { word = h.word; fn_801F86C8(lbl_801E9D24.manager, &h, 1); } ~Handle_80052930() {} };
struct Handle_8003F47C : Handle_8001FF78 { Handle_8003F47C() { word = 0; } ~Handle_8003F47C() {} static void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8, p); } };
struct Handle_800A8204 : Handle_8001FF78 {
    Handle_800A8204() { word = 0; }
    Handle_800A8204(const Handle_801F7F10& h) { word = h.word; fn_801F86C8(lbl_801E9D24.manager, &h, 1); }
    Handle_800A8204(const Handle_800A8204& h) { word = h.word; fn_801F86C8(lbl_801E9D24.manager, &h, 1); }
    ~Handle_800A8204() {}
    static void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8, p); }
};

/* Owner class hierarchy.  Each class declares an undefined virtual before its
   destructor, so this unit defines no key function and emits no vtable. */
struct RootPrefix { Word unknown00[2]; };
struct Manipulator_Z : RootPrefix {
    Manipulator_Z();
    virtual void keyManipulator();
    virtual ~Manipulator_Z() { __dt__11Activable_ZFv(this, 0); }
    char unknown0C[8];
    Word unknown14;
    signed char active18;
    char unknown19[7];
};
struct ManipulatorDraw_802BC9D0 : Manipulator_Z {
    ManipulatorDraw_802BC9D0() {}
    virtual void keyManipulatorDraw();
    virtual ~ManipulatorDraw_802BC9D0();
    static void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8, p); }
};
struct PoolElementBase1 : Handle_801F7F10 {};
struct PoolElementBase2 : PoolElementBase1 {};
struct PoolElement : PoolElementBase2 { char unknown04[0xD0]; ~PoolElement() {} };
struct Object_800A5F24 {
    int count, capacity;
    PoolElement* data;
    Object_800A5F24(int) { count = 0; capacity = 0; data = 0; }
    ~Object_800A5F24();
    static void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8, p); }
};
struct Object_800A6090 : ManipulatorDraw_802BC9D0 {
    Object_800A5F24 pool20; Word field2C; Handle_80020834 handle30, handle34; float field38; unsigned char field3C, field3D; char unknown3E[6];
    unsigned char field44; char unknown45[3]; Word field48; float field4C, field50, field54, field58, field5C, field60; unsigned char field64, field65; char unknown66[2];
    Word field68; char unknown6C[4]; float field70; char unknown74[4]; char records78[400 * 16]; char unknown1978[8]; Handle_800723F4 handle1980;
    unsigned char field1984; char unknown1985[3];
    Object_800A6090();
    virtual void keyObject();
    virtual ~Object_800A6090();
    static void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8, p); }
};
typedef char Object_extent[(sizeof(Object_800A6090) == 0x1988) ? 1 : -1];
/* ---- 0x800A5D68 Object_800A6090::Object_800A6090 ---- */
extern "C" {
extern Word lbl_803776BC;
void fn_800A5F20(void*);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, unsigned long);
void fn_800A8520(void*, int, int);
}
Object_800A6090::Object_800A6090() : pool20(0), handle1980((__construct_array(records78, fn_800A5F20, 0, 16, 400), 0)) {
    field2C = 6; field70 = 0.0f; field64 = 0; field65 = 0; field68 = 0; field3C = 1; field3D = 0; field44 = 0; field38 = 0.0f; field60 = 0.0f; field48 = 0; field4C = 0.0f; field1984 = 0;
    field50 = 0.5f; field54 = 0.5f; field58 = 0.5f; field5C = 1.0f;
    fn_800A8520(this, 0, 2); handle34 = Handle_80020834(Handle_80020478()); lbl_803776BC = 0;
}
struct Flush5D68;

/* ---- 0x800A5F20 ---- */
extern "C" void fn_800A5F20(void*) {}
struct Flush5F20;

/* ---- 0x800A5F24 Object_800A5F24::~Object_800A5F24 ---- */
extern "C" { extern char lbl_8028F698[]; void fn_8028FD50(void*, void*, int); }
Object_800A5F24::~Object_800A5F24() {
    if (data) {
        for (int i = 0; i < count; i++) data[i].~PoolElement();
        if (data) {
            fn_8028FD50(lbl_8028F698, data, capacity * sizeof(PoolElement));
            data = 0;
        }
        data = 0;
    }
}
struct Flush5F24;

/* ---- 0x800A6004 ManipulatorDraw_802BC9D0::~ManipulatorDraw_802BC9D0 ---- */
ManipulatorDraw_802BC9D0::~ManipulatorDraw_802BC9D0() {}
struct Flush6004;

/* ---- 0x800A6090 Object_800A6090::~Object_800A6090 ---- */
extern "C" { void fn_800A84D8(void*); void fn_800A7840(void*); }
namespace Dtor6090 { struct Context { char unknown00[0x114]; void* manager114; }; extern "C" Context lbl_801E9D24; }
Object_800A6090::~Object_800A6090() {
    fn_800A84D8(this);
    if (Dtor6090::lbl_801E9D24.manager114 && active18) fn_800A7840(this);
}
struct Flush6090;
/* ---- 0x800A6234 fn_800A6234 (record visibility flags) ---- */
namespace Visibility6234 {
struct Name{Word value;Name(const char*s);bool operator==(const Name&n)const{return value==n.value;}};
struct Record{Word unknown00;Name key;char unknown08[0xA1];unsigned char flags;char unknownAA[0x2A];};
struct Owner{char unknown00[0x20];int count;char unknown24[4];Record*records;char unknown2C[0xC];float time;signed char enabled;
 Record&getRecord(int i){return records[i];}
 Record*at(int n){Record*r=records;r+=n;return r;}};
struct Strings{char scoreMe[0xC];char scoreYou[0xC];char displayMessage[0x10];char menuAction[0xC];
 char menuNewGame[0x10];char menuLoadGame[0x10];char menuOptions[0x10];char menuExtras[0xC];};
extern "C"{
extern const Strings lbl_8029EC80;
Word fn_801F948C(void*,const char*);
int fn_800A78E4(Owner*,const Name&);
}
inline Name::Name(const char*s){value=fn_801F948C(this,s);}
inline const char*scoreMe(const Strings*s){const char(Strings::*m)[0xC]=&Strings::scoreMe;return s->*m;}

extern "C" void fn_800A6234(Owner*self,signed char enable,const Name&name){
 const Strings*const s=&lbl_8029EC80;
 self->enabled=enable;
 if(enable){
  for(int i=0;i<self->count;i++){
   self->at(i)->flags=self->at(i)->flags|1;
   if(self->records[i].key==Name("TIMER")||self->records[i].key==Name(scoreMe(s))||
      self->records[i].key==Name(s->scoreYou)||self->records[i].key==Name(s->displayMessage)||
      self->records[i].key==Name(s->menuAction))
    self->records[i].flags&=~1;
  }
 }else{
  self->time=5.0f;
  if(!(name==Name(""))){
   int index=fn_800A78E4(self,name);
   if(index>=0)self->getRecord(index).flags&=~1;
  }
  for(int i=0;i<self->count;i++){
   if(name==Name(""))self->records[i].flags&=~1;
   if(self->records[i].key==Name(s->menuNewGame))self->records[i].flags|=1;
   else if(self->records[i].key==Name(s->menuLoadGame))self->records[i].flags|=1;
   else if(self->records[i].key==Name(s->menuOptions))self->records[i].flags|=1;
   else if(self->records[i].key==Name(s->menuExtras))self->records[i].flags|=1;
  }
 }
}
}
struct Flush6234;

/* ---- 0x800A64E0 ---- */
extern "C" void fn_800A64E0(void *object,signed char mode) {if(mode){*((signed char *)object+0x3d)=mode;*(float *)((char *)object+0x40)=0.0f;}else *(float *)((char *)object+0x40)=0.2f;}
struct Flush64E0;

/* ---- 0x800A6504 fn_800A6504 ---- */
namespace SceneLeafMore {
struct InputRecord;
struct Records { int count; int capacity; InputRecord* data; };
struct ArrayOwner { char unknown00[0x20]; Records records; int index; };
extern "C" void fn_800A6528(ArrayOwner*);
extern "C" void fn_800A6504(ArrayOwner* self,int index){self->index=index;fn_800A6528(self);}
}
struct Flush6504;

/* ---- 0x800A6528 fn_800A6528 (text record layout) ---- */
namespace Layout6528 {
typedef unsigned char u8;
struct Entry { void* object; char unknown04[8]; signed char tag; char unknown0D[3]; };
struct Manager { int count, capacity; Entry* entries; };
struct Manager2 { int count, capacity; Entry* items; };
struct Viewport { char unknown00[0x4C]; };
struct FontInfo { int height; };
struct Font { char unknown00[8]; FontInfo* info; };
struct FontService { char unknown00[0x24]; Font* fonts; };
struct Context { char unknown00[0x114]; Viewport* viewports; Manager* manager; char unknown11C[0x30]; FontService* fontService; };
extern "C" {
extern Context lbl_801E9D24;
struct CellHeights { unsigned int cell[3][3]; };
extern const CellHeights lbl_8029ECF0;
struct GroupCounts { int count[16]; };
extern const GroupCounts lbl_8029ED14;
Word fn_801F7EB8(const Handle_801F7F10*);
void fn_801E2E70(Viewport*, int*, int*, int*, int*);
int fn_80261B64(Font*, const char*);
}
struct Texture { char unknown00[0x30]; int width; int getWidth() const { return width; } float getWidthF() const { return (float)width; } };
struct Material { char unknown00[0x74]; Handle_801F7F10 texture; };
struct Bitmap { char unknown00[0xB8]; Handle_801F7F10 material; };
template <class T> inline T* resolve(const Handle_801F7F10& h)
{
    Entry* entry = &lbl_801E9D24.manager->entries[h.bits.index];
    if (entry->tag == h.bits.tag) return (T*)entry->object;
    return 0;
}
template <class T> inline T* resolve2(const Handle_801F7F10& h)
{
    Entry* entry = &((Manager2*)lbl_801E9D24.manager)->items[h.bits.index];
    if (entry->tag == h.bits.tag) return (T*)entry->object;
    return 0;
}
struct Vec2 { float x, y; Vec2() {} Vec2(float a, float b) : x(a), y(b) {} };
struct Record {
    Handle_801F7F10 bitmap;
    char unknown04[0xA5];
    u8 flags;
    char unknownAA[2];
    u8 getFlags() const { return flags; }
    bool hCenter() const { return (flags & 0xC) == 0xC; }
    bool hLeft() const { return flags & 4; }
    bool hRight() const { return flags & 8; }
    bool vCenter() const { return (flags & 0x30) == 0x30; }
    bool vTop() const { return flags & 0x10; }
    bool vBottom() const { return flags & 0x20; }
    Vec2 pos;
    u8 percentX, percentY, font;
    char unknownB7[0x19];
    float scale;
};
struct Owner { char unknown00[0x20]; int count; char unknown24[4]; Record* records; int viewport; Record& at(int i) { return records[i]; } };
extern "C" void fn_800A7510(Owner*, int, char*);

extern "C" void fn_800A6528(Owner* self)
{
    if (self->count == 0) return;
    Viewport* viewport = &lbl_801E9D24.viewports[self->viewport];
    CellHeights cellHeights = lbl_8029ECF0;
    int v, h, i;
    Font* font;
    for (i = 0; i < self->count; i++) {
        Record* record = &self->records[i];
        if (!(record->flags & 1)) {
            float scale = record->scale;
            v = 0;
            h = 0;
            if ((record->flags & 0xC) == 0xC) h = 1;
            else if (record->flags & 4) h = 0;
            else if (record->flags & 8) h = 2;
            if ((record->flags & 0x30) == 0x30) v = 1;
            else if (record->flags & 0x10) v = 0;
            else if (record->flags & 0x20) v = 2;
            Font* recordFont = &lbl_801E9D24.fontService->fonts[record->font];
            font = recordFont;
            cellHeights.cell[h][v] += (unsigned int)(scale * (float)recordFont->info->height);
        }
    }
    int x, y, width, height;
    fn_801E2E70(viewport, &x, &y, &width, &height);
    x = 0x10;
    width -= 0x20;
    y = 0x10;
    height -= 0x20;
    unsigned int starts[3][3];
    for (h = 0; h < 3; h++) {
        for (v = 0; v < 3; v++) {
            starts[h][v] = 0x10;
            switch (v) {
            case 1:
                starts[h][v] += (height - cellHeights.cell[h][v]) >> 1;
                break;
            case 2:
                starts[h][v] += height - cellHeights.cell[h][v];
                break;
            }
            cellHeights.cell[h][v] = 0;
        }
    }
    GroupCounts groupCounts = lbl_8029ED14;
    int groups[16][8];
    int groupTotal = 0;
    for (int i = 0; i < self->count; i++) {
        u8 flags = self->at(i).getFlags();
        if (!(flags & 1) && (flags & 0x40) == 0x40) {
            signed char found = 0;
            for (int g = 0; g < groupTotal; g++) {
                for (int k = 0; k < groupCounts.count[g]; k++) {
                    if (self->at(i).percentX == self->at(groups[g][k]).percentX
                        && self->at(i).percentY == self->at(groups[g][k]).percentY) {
                        found = 1;
                        break;
                    }
                }
                if (found) groups[g][groupCounts.count[g]++] = i;
            }
            if (!found) {
                groups[groupTotal][groupCounts.count[groupTotal]++] = i;
                groupTotal++;
            }
        }
    }
    for (int g = 0; g < groupTotal; g++) {
        Record& first = self->at(groups[g][0]);
        int n = groupCounts.count[g];
        float py = (float)y + (float)(height * first.percentY) / 100.0f - (float)((n * font->info->height) / 2);
        float px = (float)x + (float)(width * first.percentX) / 100.0f;
        first.pos.x = px;
        first.pos.y = py;
        for (int k = 1; k < groupCounts.count[g]; k++) {
            py += (float)font->info->height;
            self->at(groups[g][k]).pos = Vec2(px, py);
        }
    }
    int extra4, h4, v4, i4;
    for (i4 = 0; i4 < self->count; i4++) {
        u8 flags = self->at(i4).getFlags();
        if (!(flags & 1) && !(flags & 0x40)) {
            char text[0x80];
            float scale = self->at(i4).scale;
            Font* recordFont = &lbl_801E9D24.fontService->fonts[self->at(i4).font];
            fn_800A7510(self, i4, text);
            float px = (float)x;
            extra4 = 0;
            v4 = 0;
            h4 = 0;
            if (fn_801F7EB8(&self->at(i4).bitmap)) {
                int textureWidth = resolve2<Texture>(resolve2<Material>(resolve<Bitmap>(self->at(i4).bitmap)->material)->texture)->width;
                extra4 = (int)((float)textureWidth * scale);
                extra4 += 4;
            }
            if (self->at(i4).hCenter()) {
                h4 = 1;
                px = (float)(x + (width >> 1));
            } else if (self->at(i4).hLeft()) {
                h4 = 0;
                px = (float)x;
            } else if (self->at(i4).hRight()) {
                px = (float)(x + width);
                int textWidth = fn_80261B64(recordFont, text) + 8;
                px -= (float)(extra4 + textWidth);
                h4 = 2;
            }
            if (self->at(i4).vCenter()) v4 = 1;
            else if (self->at(i4).vTop()) v4 = 0;
            else if (self->at(i4).vBottom()) v4 = 2;
            float py = (float)(starts[h4][v4] + cellHeights.cell[h4][v4]);
            cellHeights.cell[h4][v4] += (unsigned int)(scale * (float)recordFont->info->height);
            self->at(i4).pos = Vec2(px, py);
        }
    }
}

}
struct Flush6528;

/* ---- 0x800A6D90 fn_800A6D90 (per-frame record/timer update) ---- */
namespace Update6D90 {
struct Manager;
struct Handle{signed int tag:8,index:24;};
struct Node;
struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{char unknown00[8];Entry*entries;};
struct Child{char unknown00[0x238];float color[4];};
struct Parent{char unknown00[0x48];Child*child;};
struct SceneRecord{char unknown00[0x20];signed char flags[9];char unknown29[0x6B];};
struct Scene{char unknown00[0x68];Handle_801F7F10 handle68;char unknown6C[0x84];int selected;char unknownF4[0x38];float x,y,z;SceneRecord*records;};
struct World{char unknown00[0x15058];Scene*scene;};
struct Holder{char unknown00[0x1C];Handle*handle;};
extern "C"{void fn_801F86C8(Manager*,const void*,int);Word fn_801F948C(void*,const char*);Word fn_801F7EB8(const Handle_801F7F10*);}
inline Node*resolve(const Handle&h){int index=h.index;Manager*m=(Manager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
struct Name{Word value;Name(const char*s){value=fn_801F948C(this,s);}Name(const Name&n){value=n.value;}bool operator==(const Name&n)const{return value==n.value;}};
struct Record{Word unknown00;Name key;char unknown08[0xA1];unsigned char flags;char unknownAA[0x2A];bool hidden()const{return flags&1;}};
struct Owner{char unknown00[0x20];int count;char unknown24[4];Record*records;char unknown2C[0xC];float timer;signed char locked;signed char active;char unknown3E[2];float delay;char unknown44[4];int state;float decay;float color[4];float wait;char unknown64[0xC];float step;};
struct Position{char unknown00[0x30];float x,y,z;};
struct Matrix3{float m[9];};
struct Target{char unknown00[0x30];Matrix3 basis30;Matrix3 transpose54;char unknown78[0xA8];unsigned int flags120;Position*position;};
struct Link{char unknown00[0x58];Handle handle58;};
struct Actor{char unknown00[0xB0];Handle*link;};
struct Handle2{signed int tag:8,index:24;};
inline Node*resolve2(const Handle2&h){int index=h.index;Manager*m=(Manager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
struct Color{unsigned char a,b,c,d;};
extern "C"{extern const char lbl_8029EC80[];extern float lbl_80377780;extern signed char lbl_803777E4;
void fn_800A6234(Owner*,signed char,const Name&);void fn_800A84D8(Owner*);void fn_800ACB3C(Node*,float);void fn_800C0874();void fn_800C0EBC(Word);int fn_80055D90(Scene*);void fn_801F2124(const Matrix3*,Matrix3*);float fn_800A8E8C(float,float,float);}
extern "C" void fn_800A6D90(Owner*self,float dt){
    const char*pool=lbl_8029EC80;
    Scene*scene=((World*)lbl_801E9D24.p124)->scene;
    self->step=dt;
    self->timer-=dt;
    if(self->timer<=0.0f){self->timer=0.0f;fn_800A6234(self,1,Name(Name("")));}
    if(self->active&&self->delay>0.0f){self->delay-=dt;if(self->delay<=0.0f){self->delay=0.0f;self->active=0;}}
    if(!self->active)self->decay-=dt;
    if(self->decay<-5.0f)self->state=0;
    if(self->wait>0.0f)self->wait-=dt;
    else if(self->color[3]<1.0f){
        self->color[3]+=dt;
        Child*child=((Parent*)lbl_801E9D24.p114)->child;
        child->color[0]=self->color[0];child->color[1]=self->color[1];child->color[2]=self->color[2];child->color[3]=self->color[3];
        if(self->color[3]>=1.0f)fn_800A84D8(self);
    }
    Handle_80052930 handle(((World*)lbl_801E9D24.p124)->scene->handle68);
    if(fn_801F7EB8(&handle))fn_800ACB3C(resolve(*(Handle*)&handle),dt);
    if(!self->locked){
        for(int i=0;i<self->count;i++){
            Record*record;if((record=&self->records[i])->hidden())continue;
            if((record=&self->records[i])->key==Name(pool+0xD4)){if(!scene->records[scene->selected].flags[0])record->flags&=~2;}
            else if((record=&self->records[i])->key==Name(pool+0xE4)){if(!scene->records[scene->selected].flags[1])record->flags&=~2;}
            else if((record=&self->records[i])->key==Name(pool+0xF4)){if(!scene->records[scene->selected].flags[2])record->flags&=~2;}
            else if((record=&self->records[i])->key==Name(pool+0x104)){if(!scene->records[scene->selected].flags[3])record->flags&=~2;}
            else if((record=&self->records[i])->key==Name(pool+0x114)){if(!scene->records[scene->selected].flags[4])record->flags&=~2;}
            else if((record=&self->records[i])->key==Name(pool+0x124)){if(!scene->records[scene->selected].flags[5])record->flags&=~2;}
            else if((record=&self->records[i])->key==Name(pool+0x134)){if(!scene->records[scene->selected].flags[6])record->flags&=~2;}
            else if((record=&self->records[i])->key==Name(pool+0x144)){if(!scene->records[scene->selected].flags[7])record->flags&=~2;}
            else if((record=&self->records[i])->key==Name(pool+0x154)){if(!scene->records[scene->selected].flags[8])record->flags&=~2;}
        }
    }
    lbl_80377780-=dt;
    if(lbl_80377780<=0.0f){fn_800C0874();lbl_80377780=0.1f;}
    Color color;color.a=0;color.b=0;color.c=0;color.d=0;
    if(lbl_803777E4&&fn_80055D90(scene)==1){
        color.a=1;
        Node*actor=resolve(*((Holder*)lbl_801E9D24.p13C)->handle);
        Link*link=(Link*)resolve(*((Actor*)actor)->link);
        Target*t=(Target*)resolve(link->handle58);
        float dx,dy,dz;
        dz=t->position->z-scene->z;
        dx=t->position->x-scene->x;
        dy=t->position->y-scene->y;
        Target*target=(Target*)resolve2(*(Handle2*)&link->handle58);
        if(target->flags120&0x40){fn_801F2124(&target->basis30,&target->transpose54);target->flags120&=~0x40;}
        const float*m=target->transpose54.m;
        float x=m[0]*dx+m[3]*dy+m[6]*dz;
        float z=m[2]*dx+m[5]*dy+m[8]*dz;
        float cx=fn_800A8E8C(x,-40.0f,40.0f);
        float cz=fn_800A8E8C(z,-40.0f,40.0f);
        color.b=(int)cx;color.c=(int)cz;
    }
    fn_800C0EBC(*(Word*)&color);
}
}
struct Flush6D90;

/* ---- 0x800A7510 fn_800A7510 (text record formatting) ---- */
namespace Format7510 {
struct TextHandle{signed int tag:8,index:24;};
struct TextPrefix{char unknown00[8];};
struct TextActor:TextPrefix{virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();virtual void slot8();virtual void slot9();virtual void slot10();virtual void slot11();virtual void slot12();virtual void slot13();virtual void slot14();virtual void slot15();virtual void slot16();virtual void slot17();virtual void slot18();virtual void slot19();virtual void slot20();virtual void slot21();virtual void slot22();virtual void slot23();virtual void slot24();virtual void slot25();virtual Word query(const Word&,const TextHandle&);};
struct TextEntry{TextActor*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct TextManager{char unknown00[8];TextEntry*entries;};
struct TextContext{char unknown00[0x118];TextManager*manager;};
extern "C"TextContext lbl_801E9D24;
inline TextActor*resolveText(const TextHandle&h){int index=h.index;TextManager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
struct TextName{Word value;TextName(const char*s);bool operator==(const TextName&n)const{return value==n.value;}};
struct TextRecord{Word unknown00;TextName key;char text[0x80];TextHandle handles[4];Word values[4];unsigned char count;char unknownA9[0x2B];char*getText(){return text;}};
struct TextOwner{char unknown00[0x28];TextRecord*records;char unknown2C[4];TextHandle handle;char unknown34[0x14];char*savedText;float time;char unknown50[0x1934];unsigned char flag;TextRecord&getRecord(int i){return records[i];}char*getText(int i){return records[i].text;}};
extern "C"{extern const char lbl_8029EC80[];extern int lbl_8037767C;Word fn_801F948C(void*,const char*);int fn_800A78E4(TextOwner*,const TextName&);char*strcpy(char*,const char*);void fn_801F44DC(void*,const char*,Word*);}
inline TextName::TextName(const char*s){value=fn_801F948C(this,s);}
extern "C"void fn_800A7510(TextOwner*self,int index,void*output){const char*pool=lbl_8029EC80;TextRecord*record;for(int i=0;i<(record=&self->records[index])->count;++i)record->values[i]=resolveText(self->handle)->query(record->key.value,record->handles[i]);
if((record=&self->records[index])->key==TextName(pool+0x28)){record->text[0]=0;if(lbl_8037767C>0){self->getText(index)[0]=0;int found=-1;switch(lbl_8037767C){case 1:found=fn_800A78E4(self,TextName(pool+0x34));break;case 2:found=fn_800A78E4(self,TextName(pool+0x44));break;case 3:found=fn_800A78E4(self,TextName(pool+0x54));break;case 4:found=fn_800A78E4(self,TextName(pool+0x64));break;}if(found>-1)strcpy(self->getText(index),self->getRecord(found).getText());}}
else if((record=&self->records[index])->key==TextName(pool+0x18)){record->text[0]=0;if(self->savedText&&self->time>0.0f)strcpy(self->getText(index),self->savedText);}
if(self->records[index].key==TextName(pool+0x18))self->flag=1;else self->flag=0;
fn_801F44DC(output,self->getText(index),self->records[index].values);}
}
struct Flush7510;

/* ---- 0x800A7798 fn_800A7798 ---- */
namespace Retained7798 {
typedef unsigned long RetainedControlWord;
struct RetainedControlManager;
struct RetainedControlPrefix{char unknown00[0x1C];};
struct RetainedControlOutput:RetainedControlPrefix{
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
virtual void clear(int,int,int);
};
struct RetainedControlScene{char unknown00[0x15058];void*screen;};
struct RetainedControlContext{char unknown00[0x114];char*lists;RetainedControlManager*manager;char unknown11C[8];RetainedControlScene*scene;char unknown128[0x2C];RetainedControlOutput*output;};
extern "C"{extern RetainedControlContext lbl_801E9D24;extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(RetainedControlManager*,const void*,int);RetainedControlWord fn_801F948C(void*,const char*);void fn_801E2074(void*,const struct Handle_8002F6B0&,int);void fn_801E1F3C(void*,const struct Handle_8002F6B0&);void fn_80213A18(void*);void fn_802139D8(void*);void fn_800B3344(void*);void fn_80255678(void*);extern const float lbl_80379354;extern const char lbl_802A0178[],lbl_802A04EC[];}
struct RetainedControlResource{char unknown00[0x38];unsigned long long flags;};
struct RetainedControlEntry{RetainedControlResource*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct RetainedControlManager{char unknown00[8];RetainedControlEntry*entries;};
struct RetainedControlName{RetainedControlWord word;RetainedControlName(const char*s){word=fn_801F948C(this,s);}};
struct RetainedControlItem{char unknown00[0x80];RetainedControlName name;char unknown84[8];unsigned short flags;char unknown8E[0x36];};
struct RetainedControlRecord{char unknown00[4];Handle_801F7F10 handle;char unknown08[0x24];short start;char unknown2E[6];unsigned char selection;char unknown35[0x11];unsigned short count;char unknown48[0x28];RetainedControlItem*items;char unknown74[0x130];float scalar;signed char active;};
struct RetainedControlAction{char unknown00[4];Handle_801F7F10 handle;char unknown08[0x10];signed char active;char unknown19[0x13];int index;};
extern "C"void fn_800A7798(RetainedControlAction*self){if(!self->active){const Handle_801F7F10&original=self->handle;fn_801E2074(lbl_801E9D24.lists+self->index*0x4C,Handle_8002F6B0(original),0);fn_80213A18(self);}}
}
struct Flush7798;

/* ---- 0x800A7840 fn_800A7840 ---- */
namespace Dispatch7840 {
typedef unsigned long u32;
struct Manager;
struct Globals { char opaque00[0x114]; char*lists114; Manager*manager118; char opaque11C[0x30]; void*scope14C; };
extern "C" { extern Globals lbl_801E9D24; extern char lbl_801EF5C8[]; void fn_801EF610(void*,void*); void fn_801F86C8(Manager*,const void*,int); u32 fn_801F948C(void*,const char*); void fn_801E2074(void*,const Handle_8002F6B0&,int); void fn_801E1F3C(void*,const Handle_8002F6B0&); void fn_80213A18(void*); void fn_802139D8(void*); extern const char lbl_80379804[7]; extern const float lbl_8037980C,lbl_80379810; }
struct NameHash {u32 word; NameHash(const char*s){word=fn_801F948C(this,s);} };
extern "C" Handle_800723F4 fn_802631B0(void*,const NameHash&);
inline void assign(Handle_801F7F10&d,const Handle_801F7F10&s){fn_801F86C8(lbl_801E9D24.manager118,&d,-1);d.word=s.word;fn_801F86C8(lbl_801E9D24.manager118,&s,1);}
struct View {char opaque00[4];Handle_801F7F10 handle04;char opaque08[0x10];signed char flag18;char opaque19[0x13];int index20;Handle_801F7F10 handle24;float value28,value2C,value30;};
extern "C" void fn_800A7840(View*self){if(self->flag18){const Handle_801F7F10&original=self->handle04;fn_801E1F3C(lbl_801E9D24.lists114+self->index20*0x4C,Handle_8002F6B0(original));fn_802139D8(self);}}
}
struct Flush7840;

/* ---- 0x800A78E4 fn_800A78E4 (record key search) ---- */
namespace Search78E4 {
struct RecordKey_800A78E4 {
    unsigned int value;
    bool operator==(const RecordKey_800A78E4& other) const {
        return value == other.value;
    }
};
struct SearchRecord_800A78E4 {
    char unknown00[4];
    RecordKey_800A78E4 key;
    char unknown08[0xCC];
};
struct SearchOwner_800A78E4 {
    char unknown00[0x20];
    int count;
    char unknown24[4];
    SearchRecord_800A78E4* records;
};
extern "C" int fn_800A78E4(const SearchOwner_800A78E4* self,
    const RecordKey_800A78E4* needle)
{
    for (int i = 0; i < self->count; ++i) {
        if (self->records[i].key == *needle) return i;
    }
    return -1;
}
typedef char CheckSearchRecordSize[sizeof(SearchRecord_800A78E4) == 0xD4 ? 1 : -1];
}
struct Flush78E4;

/* ---- 0x800A7930 fn_800A7930 (text record rendering), 0x800A81FC, 0x800A8200 ---- */
namespace Render7930 {
typedef unsigned char u8;
typedef ::SharedEntry Entry;
typedef ::SharedManager Manager;
struct Manager2 { int count, capacity; Entry* items; };
extern "C" { extern char lbl_801EF5C8[]; void fn_801EF610(void*, void*); void fn_801F86C8(Manager*, const Handle_801F7F10*, int); Word fn_801F948C(void*, const char*); }
struct Vec2;
struct Vec3;
struct RendererPrefix { char unknown00[0x278]; };
struct Renderer : RendererPrefix {
    virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14(); virtual void slot18(); virtual void slot1C();
    virtual void slot20(); virtual void slot24(); virtual void slot28(); virtual void slot2C(); virtual void slot30(); virtual void slot34();
    virtual void slot38(); virtual void slot3C(); virtual void slot40(); virtual void slot44(); virtual void slot48(); virtual void slot4C();
    virtual void slot50(); virtual void slot54(); virtual void slot58(); virtual void slot5C(); virtual void slot60(); virtual void slot64();
    virtual void slot68(); virtual void slot6C(); virtual void slot70(); virtual void slot74(); virtual void slot78();
    virtual void draw(const Vec2&, const Vec2&, const Vec2&, const Vec2&, const Vec3&, const Vec3&, float);
    virtual void slot80();
    virtual void slot84(); virtual void slot88(); virtual void slot8C(); virtual void slot90(); virtual void slot94(); virtual void slot98(); virtual void slot9C();
    virtual void bind(const Handle_800A8204&);
};
struct Viewport { char unknown00[0x48]; Renderer* renderer; Renderer* getRenderer() const { return renderer; } };
struct FontInfo { int height; };
struct Font { char unknown00[8]; FontInfo* info; };
struct FontService { char unknown00[0x24]; Font* fonts; Font* get(u8 i) { return &fonts[i]; } Font& ref(u8 i) { return fonts[i]; } };
struct Mode;
struct Scene { char unknown00[0x15058]; Mode* first; };
extern "C" {
struct CellHeights { unsigned int cell[3][3]; };
extern const CellHeights lbl_8029ECF0;
struct GroupCounts { int count[16]; };
extern const GroupCounts lbl_8029ED14;
extern float lbl_80375308, lbl_8037530C;
extern const char lbl_8029EDE4[], lbl_8029EC98[];
extern char lbl_801EF5C8[];
void fn_801EF610(void*, void*);
void fn_801F86C8(Manager*, const Handle_801F7F10*, int);
Word fn_801F948C(void*, const char*);
char* strchr(const char*, int);
Word fn_801F7EB8(const Handle_801F7F10*);
void fn_801E2E70(Viewport*, int*, int*, int*, int*);
int fn_80261B64(Font*, const char*);
}
struct Texture { char unknown00[0x30]; int width, height; int getWidth() const { return width; } float getWidthF() const { return (float)width; } };
struct Material { char unknown00[0x74]; Handle_801F7F10 texture; };
struct Bitmap { char unknown00[0xB8]; Handle_801F7F10 material; };
template <class T> inline T* resolve(const Handle_801F7F10& h)
{
    Entry* entry = &lbl_801E9D24.manager->entries[h.bits.index];
    if (entry->tag == h.bits.tag) return (T*)entry->object;
    return 0;
}
template <class T> inline T* resolve2(const Handle_801F7F10& h)
{
    Entry* entry = &((Manager2*)lbl_801E9D24.manager)->items[h.bits.index];
    if (entry->tag == h.bits.tag) return (T*)entry->object;
    return 0;
}
struct Vec2 { float x, y; Vec2() {} Vec2(float a, float b) : x(a), y(b) {} };
struct Name { Word value; Name(const char* s) { value = fn_801F948C(this, s); } bool operator==(const Name& n) const { return value == n.value; } };
struct Vec3 { float x, y, z; Vec3() {} Vec3(float a, float b, float c) : x(a), y(b), z(c) {} Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); } };
struct Record {
    Handle_801F7F10 bitmap;
    Name key;
    char unknown08[0xA1];
    u8 flags;
    char unknownAA[2];
    u8 getFlags() const { return flags; }
    bool hCenter() const { return (flags & 0xC) == 0xC; }
    bool hLeft() const { return flags & 4; }
    bool hRight() const { return flags & 8; }
    bool vCenter() const { return (flags & 0x30) == 0x30; }
    bool vTop() const { return flags & 0x10; }
    bool vBottom() const { return flags & 0x20; }
    Vec2 pos;
    u8 percentX, percentY, font;
    char unknownB7;
    Vec3 color0;
    Vec3 color1;
    float scale;
};
struct Owner {
    char unknown00[0x18];
    signed char visible;
    char unknown19[7];
    int count;
    char unknown24[4];
    Record* records;
    int viewport;
    char unknown30[8];
    float fade;
    signed char fixedScale;
    signed char dimmed;
    char unknown3E[0xA];
    int gridState;
    char unknown4C[0x18];
    signed char gridActive;
    char unknown65[0x191F];
    signed char shadow;
    Record& at(int i) { return records[i]; }
};
struct SubtitleLines { Vec3 color0; Vec3 color1; char unknown18[8]; char* text; };
struct Subtitle { char unknown00[0x10]; int current; char unknown14[4]; SubtitleLines lines; SubtitleLines* getLines() { return &lines; } };
struct Mode { char unknown00[0x68]; Handle_801F7F10 menu; };
struct Menu;
extern "C" {
void fn_800A7510(Owner*, int, char*);
void fn_800A8278(Owner*, Viewport*);
void fn_800A882C(Owner*, Viewport*);
Subtitle* fn_800AC260(Menu*);
void fn_80261870(Font*, Renderer*, const char*, int, int, const Vec3&, const Vec3&, float, float);
}

inline Subtitle* currentSubtitle()
{
    Mode* mode = ((Scene*)lbl_801E9D24.p124)->first;
    if (fn_801F7EB8(&mode->menu)) return fn_800AC260(resolve<Menu>(mode->menu));
    return 0;
}
/* Empty renderer slots (Renderer vtable 0x802EA718 +0x7C draw / +0xA0 bind).
   In the original they are inline virtuals that mwcc emits after fn_800A7930,
   which calls them; dtk names them fn_.  As C-named inline functions they are
   emitted the same way once fn_800A7930 references them: weak copies follow
   their user, last-referenced first, so the references at the end of
   fn_800A7930 (after the Handle_800A8204 temporary) give the original order
   fn_800A7930, fn_800A81FC, fn_800A8200, ~Handle_800A8204.  The references
   generate no code. */
extern "C" inline void fn_800A81FC(void) {}
extern "C" inline void fn_800A8200(void) {}
extern "C" void fn_800A7930(Owner* self, Viewport* viewport)
{
    Vec2 pos;
    Subtitle* subtitle;
    Renderer* renderer;
    SubtitleLines* lines;
    char* line;
    short i;
    long index;
    Font* font;
    Record* record;
    float scale;
    if (!self->visible) return;
    renderer = viewport->getRenderer();
    int x, y, width, height;
    fn_801E2E70(viewport, &x, &y, &width, &height);
    if (self->dimmed == 1) fn_800A8278(self, viewport);
    if (self->gridActive == 1) {
        self->gridState = 0;
        fn_800A882C(self, viewport);
    }
    float shade = 1.0f;
    subtitle = currentSubtitle();
    for (i = 0; (index = i) < self->count; i++) {
        if (self->records[index].key == Name(lbl_8029EDE4)) {
            if (subtitle && subtitle->current >= 0) {
                Font* subtitleFont = ((FontService*)lbl_801E9D24.p14C)->get(self->records[index].font);
                pos = self->records[index].pos;
                float subtitleScale = self->records[index].scale;
                lines = subtitle->getLines();
                line = 0;
                if (lines) line = lines->text;
                pos.y = 0.77f * (float)height;
                while (line) {
                    char* next = strchr(line, '\n');
                    if (next) *next = 0;
                    float left = pos.x - subtitleScale * (float)fn_80261B64(subtitleFont, line) / 2.0f;
                    fn_80261870(subtitleFont, renderer, line, (int)left, (int)pos.y, lines->color0 * shade, lines->color1 * shade, subtitleScale, 1.0f);
                    if (next) {
                        *next = '\n';
                        next++;
                        pos.y += 1.05f * (subtitleScale * (float)subtitleFont->info->height);
                    }
                    line = next;
                }
            }
        } else if ((!(self->records[index].flags & 1) && !self->dimmed) || (self->records[index].key == Name(lbl_8029EC98) && !subtitle)) {
            Record& head = self->records[index];
            if (head.flags & 2) shade = 0.35f;
            else shade = 1.0f;
            font = &((FontService*)lbl_801E9D24.p14C)->fonts[head.font];
            pos = head.pos;
            scale = self->records[index].scale;
            if (!self->fixedScale && self->fade <= 1.0f && !(self->records[index].key == Name(lbl_8029EC98)) && !(self->records[index].key == Name("TIMER"))) {
                scale *= self->fade;
            }
            char text[0x80];
            fn_800A7510(self, i, text);
            if (fn_801F7EB8(&self->records[index].bitmap)) {
                record = &self->records[index];
                Texture* texture = resolve2<Texture>(resolve2<Material>(resolve<Bitmap>(record->bitmap)->material)->texture);
                int w = (unsigned int)((float)texture->width * scale);
                int h = (unsigned int)((float)texture->height * scale);
                if ((record->flags & 0xC) == 0xC) {
                    pos.x -= (float)((scale * (float)fn_80261B64(font, text) + (float)w) / 2.0f);
                }
                renderer->bind(Handle_800A8204(resolve<Bitmap>(self->records[index].bitmap)->material));
                Vec2 hi(pos.x + (float)w, pos.y + (float)h);
                Vec2 uv0(0.0f, 0.0f);
                Vec2 uv1(1.0f, 1.0f);
                renderer->draw(pos, hi, uv0, uv1, Vec3(0.5f * shade, 0.5f * shade, 0.5f * shade), Vec3(0.5f * shade, 0.5f * shade, 0.5f * shade), 1.0f);
                pos.x += (float)(w + 4);
            } else if ((self->records[index].flags & 0xC) == 0xC) {
                pos.x -= scale * (float)fn_80261B64(font, text) / 2.0f;
            }
            fn_80261870(font, renderer, text, (int)pos.x, (int)pos.y, self->records[index].color0 * shade, self->records[index].color1 * shade, scale, 1.0f);
            if (self->shadow) {
                Vec3 black(0.0f, 0.0f, 0.0f);
                pos.x += lbl_80375308;
                pos.y += lbl_8037530C;
                fn_80261870(font, renderer, text, (int)pos.x, (int)pos.y, black, black, scale, 1.02f);
            }
        }
    }
    (void)&fn_800A8200;
    (void)&fn_800A81FC;
}
}
struct Flush7930;

/* ---- 0x800A8278 fn_800A8278 (dim bars) ---- */
namespace Bars8278 {
extern "C"{extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);}
struct Vec2{float x,y;Vec2(){}Vec2(float a,float b):x(a),y(b){}};
struct Vec4{float x,y,z,w;Vec4(float a,float b,float c,float d):x(a),y(b),z(c),w(d){}};
struct RendererPrefix{char unknown00[0x278];};
struct Renderer:RendererPrefix{
virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();
virtual void fill(const Vec2&,const Vec2&,const Vec4&,const Vec4&,float);
virtual void slot84();virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();virtual void slot98();virtual void slot9C();virtual void slotA0();
virtual void bind(const Handle_8003F47C&);
};
struct Viewport{char unknown00[0x48];Renderer*renderer;};
extern "C" void fn_801E2E70(Viewport*,int*,int*,int*,int*);
extern "C" void fn_800A8278(void*self,Viewport*viewport){
    Renderer*renderer=viewport->renderer;
    int x,y,width,height;
    fn_801E2E70(viewport,&x,&y,&width,&height);
    Vec4 color(0.0f,0.0f,0.0f,1.0f);
    renderer->bind(Handle_8003F47C());
    Vec2 lo,hi;lo.x=(float)x;lo.y=(float)y;hi.x=(float)(x+width);hi.y=0.1f*(float)height;renderer->fill(lo,hi,color,color,1.0f);
 lo.x=(float)x;lo.y=0.75f*(float)height;hi.x=(float)(x+width);hi.y=(float)(y+height);renderer->fill(lo,hi,color,color,1.0f);
}

}
struct Flush8278;

/* ---- 0x800A8464 / 0x800A8468 ---- */
extern "C" void fn_800A8464(void) {}
struct Flush8464;
extern "C" void fn_800A8468(void) {}
struct Flush8468;

/* ---- 0x800A846C fn_800A846C ---- */
namespace Color846C {
struct Child {char pad[0x234];unsigned int flags;float color[4];};

struct Parent {char pad[0x48];struct Child *child;};

struct Context846C {char pad[0x114];struct Parent *parent;};
extern "C" Context846C lbl_801E9D24;

static inline void copy4(float *out,const float *in) {out[0]=in[0];out[1]=in[1];out[2]=in[2];out[3]=in[3];}

extern "C" void fn_800A846C(float *object,const float *color,float amount) {object[0x60/4]=amount;copy4(object+0x50/4,color);lbl_801E9D24.parent->child->flags|=4U;copy4(lbl_801E9D24.parent->child->color,color);}
}
struct Flush846C;

/* ---- 0x800A84D8 fn_800A84D8 ---- */
namespace Color84D8 {
struct Child {char pad[0x234];unsigned int flags;float color[4];};

struct Parent {char pad[0x48];struct Child *child;};

struct Context84D8 {char pad[0x114];struct Parent *parent;};
extern "C" Context84D8 lbl_801E9D24;


static inline void set4(float *out,float x,float y,float z,float w) {out[0]=x;out[1]=y;out[2]=z;out[3]=w;}

extern "C" void fn_800A84D8(void) {if(lbl_801E9D24.parent){lbl_801E9D24.parent->child->flags&=~4U;set4(lbl_801E9D24.parent->child->color,0.5f,0.5f,0.5f,1.0f);}}
}
struct Flush84D8;

/* ---- 0x800A8520 fn_800A8520 ---- */
namespace Token8520 {
struct TokenControlHandle{signed int tag:8,index:24;};
struct TokenControlActorPrefix{char unknown00[8];};
struct TokenControlActor:TokenControlActorPrefix{
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
virtual const TokenControlHandle&related(int);
char unknown0C[0x18];TokenControlHandle handle;char unknown28[8];unsigned long long flags;char unknown38[0xE8];unsigned long relatedFlags;
};
struct TokenControlOwner{char unknown00[8];TokenControlActor*actor;TokenControlActor*resolved;char unknown10[8];float value;};
struct TokenControlEntry{TokenControlActor*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct TokenControlManager{char unknown00[8];TokenControlEntry*entries;};
struct TokenControlContext{char unknown00[0x118];TokenControlManager*manager;};
extern "C" TokenControlContext lbl_801E9D24;
inline TokenControlActor*resolveToken(const TokenControlHandle&h){int index=h.index;TokenControlManager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
extern "C"{int sprintf(char*,const char*,...);char*strcpy(char*,const char*);char*strcat(char*,const char*);int strcmp(const char*,const char*);void fn_801F372C(void*,char*);float fn_801F1200();unsigned long fn_801F948C(void*,const char*);extern const char lbl_80378F74[3],lbl_80378F70[2],lbl_803791B4[3],lbl_803791C8[2],lbl_802A0338[],lbl_802A0344[],lbl_80379238[7];extern const float lbl_80379088;}
struct TokenControlName{unsigned long value;TokenControlName(const char*s){value=fn_801F948C(this,s);}TokenControlName(const TokenControlName&n){value=n.value;}};
struct TokenControlSetup{char unknown00[0x48];int count;char unknown4C[0x18];signed char enabled,variant;char unknown66[2];int kind;float value;};
struct TokenControlSelection{char unknown00[0x30];int kind;};
extern "C"{void fn_800A6234(TokenControlSetup*,signed char,const TokenControlName&);void fn_800A85AC(TokenControlSetup*);}
extern "C"void fn_800A8520(TokenControlSetup*self,signed char variant,int kind){fn_800A6234(self,1,TokenControlName(TokenControlName("")));self->count=0;self->enabled=1;self->variant=variant;self->kind=kind;self->value=0.0f;if(kind==2)self->value=1.0f;fn_800A85AC(self);}
}
struct Flush8520;

/* ---- 0x800A85AC fn_800A85AC (random record grid reset) ---- */
namespace Grid85AC {
typedef unsigned long u32;
struct GridEntry{void*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct GridManager{char unknown00[8];GridEntry*entries;};
struct GridContext{char unknown00[0x118];GridManager*manager;char unknown11C[0x30];void*scope;};
extern "C" {extern GridContext lbl_801E9D24;extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(GridManager*,const void*,int);u32 fn_801F948C(void*,const char*);float fn_801F1200();extern const char lbl_8029EDF0[];void fn_80239A7C(void*);void fn_802397E0(void*);}
struct GridName{u32 word;GridName(const char*s){word=fn_801F948C(this,s);}};
extern "C" Handle_800723F4 fn_802631B0(void*,const GridName&);
inline void assign(Handle_801F7F10&d,const Handle_801F7F10&s){fn_801F86C8(lbl_801E9D24.manager,&d,-1);d.word=s.word;fn_801F86C8(lbl_801E9D24.manager,&s,1);}
inline void*resolveGrid(const Handle_801F7F10&h){int index=h.bits.index;GridManager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
struct GridRecord{float x,y,z,w;};
struct RandomGrid{char unknown00[0x34];Handle_801F7F10 handle34;char unknown38[0x3C];float value;GridRecord records[400];unsigned char flag1978,flag1979;char unknown197A[2];int index;Handle_801F7F10 handle1980;};
extern "C" void fn_800A85AC(RandomGrid*);
extern "C" void fn_800A85AC(RandomGrid*self){
 self->flag1978=0;self->flag1979=0;self->value=10.0f;self->index=0;
 assign(self->handle34,Handle_80020834());
 float y=600.0f,w=0.4f;int index=0;
 for(int row=0;row<20;row++){
  for(int column=0;column<20;column++){
   self->records[index].x=700.0f*fn_801F1200();
   self->records[index].x-=30.0f*fn_801F1200();
   self->records[index].y=y;self->records[index].y-=30.0f*fn_801F1200();
   self->records[index].z=1.3f*fn_801F1200()+0.25f;
   self->records[index].w=w*fn_801F1200();index++;
  }
  y-=30.0f;w+=0.05f;
 }
 assign(self->handle1980,fn_802631B0(lbl_801E9D24.scope,GridName(lbl_8029EDF0)));
 fn_80239A7C(resolveGrid(self->handle1980));fn_802397E0(resolveGrid(self->handle1980));
}
}
struct Flush85AC;

/* ---- 0x800A882C fn_800A882C (random record grid render) ---- */
namespace Grid882C {
struct Entry { void* object; char unknown04[8]; signed char tag; char unknown0D[3]; signed char getTag() const { return tag; } };
struct Manager { int count, capacity; Entry* entries; };
extern "C" {
extern char lbl_801EF5C8[];
extern const char lbl_8029EDFC[];
void fn_801EF610(void*, void*);
void fn_801F86C8(Manager*, const void*, int);
Word fn_801F948C(void*, const char*);
void* fn_801F7EB8(const Handle_801F7F10*);
void fn_802073E8(void*, int, void*, float);
}
inline void* resolve(const Handle_801F7F10& h) { int index = h.bits.index; Manager* m = (Manager*)lbl_801E9D24.manager; int tag = m->entries[index].getTag(); return tag == h.bits.tag ? m->entries[index].object : 0; }
inline void* resolve2(const Handle_801F7F10& h) { int index = h.bits.index; Manager* m = (Manager*)lbl_801E9D24.manager; int tag = m->entries[index].getTag(); if (tag == h.bits.tag) return m->entries[index].object; return 0; }
struct Name { Word value; Name(const char* s) { value = fn_801F948C(this, s); } };
struct Vec2 { float x, y; Vec2() {} Vec2(float a, float b) : x(a), y(b) {} Vec2(int a, int b) : x((float)a), y((float)b) {} Vec2 operator*(float t) const { return Vec2(x * t, y * t); } };
inline Vec2 operator+(const Vec2& a, const Vec2& b) { return Vec2(a.x + b.x, a.y + b.y); }
struct Vec3 { float x, y, z; Vec3(float a, float b, float c) : x(a), y(b), z(c) {} };
struct Vec4 { float x, y, z, w; Vec4(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {} };
struct RendererPrefix { char unknown00[0x278]; };
struct Renderer : RendererPrefix {
    virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14(); virtual void slot18(); virtual void slot1C();
    virtual void slot20(); virtual void slot24(); virtual void slot28(); virtual void slot2C(); virtual void slot30(); virtual void slot34();
    virtual void slot38(); virtual void slot3C(); virtual void slot40(); virtual void slot44(); virtual void slot48(); virtual void slot4C();
    virtual void slot50(); virtual void slot54(); virtual void slot58(); virtual void slot5C(); virtual void slot60(); virtual void slot64();
    virtual void slot68(); virtual void slot6C(); virtual void slot70(); virtual void slot74(); virtual void slot78();
    virtual void draw(const Vec2&, const Vec2&, const Vec2&, const Vec2&, const Vec3&, const Vec3&, float);
    virtual void fill(const Vec2&, const Vec2&, const Vec4&, const Vec4&, float);
    virtual void slot84(); virtual void slot88(); virtual void slot8C(); virtual void slot90(); virtual void slot94(); virtual void slot98(); virtual void slot9C();
    virtual void bind(const Handle_800A8204&);
};
struct Viewport { char unknown00[0x48]; Renderer* renderer; Renderer* getRenderer() const { return renderer; } };
struct Bitmap { char unknown00[0xB8]; Handle_801F7F10 material; };
struct Material { char unknown00[0x18]; float alpha; char unknown1C[0x58]; Handle_801F7F10 texture; };
struct Texture { char unknown00[0x30]; int width, height; };
inline Texture* textureFor(const Handle_801F7F10& h) { int index = h.bits.index; Manager* m = (Manager*)lbl_801E9D24.manager; int tag = m->entries[index].getTag(); if (tag == h.bits.tag) return (Texture*)m->entries[index].object; return 0; }
struct Record { Vec2 position; float scale, time; };
struct RandomGrid {
    char unknown00[0x34];
    Handle_801F7F10 handle34;
    char unknown38[0x2C];
    unsigned char active;
    char unknown65[3];
    int mode;
    float fade;
    float step;
    float value;
    Record records[400];
    bool done;
    signed char notified;
    char unknown197A[2];
    int state;
    Handle_801F7F10 handle1980;
};
extern "C" {
void fn_801E2E70(const Viewport*, int*, int*, int*, int*);
Handle_800723F4 fn_802631B0(void*, const Name&);
}
extern "C" void fn_800A882C(RandomGrid* self, const Viewport* viewport) {
    float zero = 0.0f;
    float one = 1.0f;
    Renderer* renderer = viewport->renderer;
    Vec4 color(zero, zero, zero, one);
    int x, y, width, height;
    fn_801E2E70(viewport, &x, &y, &width, &height);
    Vec2 lo(x, y);
    Vec2 hi(x + width, y + height);
    Handle_800A8204 material(((Bitmap*)resolve(self->handle1980))->material);
    renderer->bind(Handle_800A8204(material));
    float alpha = ((Material*)resolve(material))->alpha;
    if (self->mode == 2) {
        alpha = self->fade;
        self->fade -= self->step;
        if (self->fade < 0.0f) self->fade = 0.0f;
    }
    if (!self->notified && alpha > 0.85f && fn_801F7EB8(&self->handle34)) {
        fn_802073E8(self, 0x8C, resolve2(self->handle34), -1612.0f);
        self->notified = 1;
    }
    color.w = alpha;
    renderer->fill(lo, hi, color, color, 1.0f);
    if (self->mode == 0) {
        Handle_800723F4 bitmap;
        bitmap = fn_802631B0(lbl_801E9D24.p14C, Name(lbl_8029EDFC));
        Texture* texture = textureFor(((Material*)resolve(((Bitmap*)resolve(bitmap))->material))->texture);
        int tw = texture->width, th = texture->height;
        renderer->bind(Handle_800A8204(((Bitmap*)resolve(bitmap))->material));
        for (int i = 0; (float)i < self->value; ++i) {
            if (self->records[i].time > 0.0f) {
                Vec2 lo(self->records[i].position);
                Vec2 wh((float)tw, (float)th);
                Vec2 hi = self->records[i].position + wh * self->records[i].scale;
                Vec2 uvLo(0.0f, 0.0f);
                Vec2 uvHi(1.0f, 1.0f);
                Vec3 first(0.5f, 0.5f, 0.5f);
                Vec3 second(0.5f, 0.5f, 0.5f);
                renderer->draw(lo, hi, uvLo, uvHi, first, second, 1.0f);
            }
        }
    }
    if (self->state == 0) {
        self->value += 400.0f * self->step;
    } else if (self->state == 1) {
        self->done = 1;
        for (int i = 0; i < 400; ++i) {
            self->records[i].time -= self->step;
            if (self->records[i].time > 0.0f) self->done = 0;
        }
    }
    if (self->value >= 400.0f) {
        self->value = 400.0f;
        self->state = 1;
    }
    if ((int)self->done == 1) self->active = 0;
}

}
struct Flush882C;
