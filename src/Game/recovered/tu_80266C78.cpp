// Original TU 80266C78..80267748: 2D index grid queries, record chains, record
// pool growth, platform record reset and an integer max helper.  The TU literal
// pool is .sdata2 0x8037B628..0x8037B638 (0.999999f, 0.0f, int->float bias, in
// first-use order); fn_802676F4 shares the pooled 0.0f.
#include "Game/index_grid_records_internal.h"
#include "Game/index_grid_acquire_internal.h"
#include "Game/platform_followup_controls.h"
extern "C" int fn_80267400(IndexGridAcquireView*);

/* ---- 80266C78: grid queries ---- */
extern "C" {
int fn_801EC764(int, int);
int fn_801EC778(int, int);
int fn_8021DA0C(int, int);
int fn_80267734(int, int);
}

struct GridObject {
    char pad[0x120];
    unsigned int flags;
    bool isMarked() const { return (flags & 2) != 0; }
    void mark() { flags |= 2; }
};

struct GridNode {
    int next;
    int unk4, unk8, unkC;
    GridObject* object;
};
struct GridNodeArr { GridNode* data; GridNode& operator[](int i) { return data[i]; } };

struct Grid2D {
    float originX;  /* 0x00 */
    float originZ;  /* 0x04 */
    float unk8;
    float unkC;
    float invX;     /* 0x10 */
    float invZ;     /* 0x14 */
    int countX;     /* 0x18 */
    int countZ;     /* 0x1C */
    char pad20[0x10];
    int* cells;     /* 0x30 */
    char pad34[8];
    GridNodeArr nodes; /* 0x3C */
    GridObject* results[0x1000]; /* 0x40 */
    int resultCount; /* 0x4040 */
};

struct Vec2 {
    float x, z;
};

struct Sphere {
    float x, y, z, r;
};

struct IRect {
    int minX, minZ, maxX, maxZ;
};

inline int roundDown(float v)
{
    if (v < 0.0f) return (int)(v - 0.999999f);
    return (int)v;
}

inline int roundUp(float v)
{
    if (v > 0.0f) return (int)(0.999999f + v);
    return (int)v;
}

extern "C" int fn_80266C78(Grid2D* self, const Vec2* lo, const Vec2* hi)
{
    int maxZ;
    int maxX;
    int d;
    int minX;
    int a;
    int c;
    int b;
    int minZ;
    float fa = self->countX * (self->invX * (lo->x - self->originX));
    if (fa < 0.0f) a = (int)(fa - 0.999999f); else a = (int)fa;
    float fb = self->countX * (self->invX * (hi->x - self->originX));
    if (fb > 0.0f) b = (int)(0.999999f + fb); else b = (int)fb;
    float fc = self->countZ * (self->invZ * (lo->z - self->originZ));
    if (fc < 0.0f) c = (int)(fc - 0.999999f); else c = (int)fc;
    float fd = self->countZ * (self->invZ * (hi->z - self->originZ));
    if (fd > 0.0f) d = (int)(0.999999f + fd); else d = (int)fd;
    maxX = fn_8021DA0C(self->countX, b);
    maxZ = fn_8021DA0C(self->countZ, d);
    minX = fn_80267734(0, a);
    minZ = fn_80267734(0, c);
    int n;
    int x = minX;
    int count = 0;
    int row = minZ * self->countX;
    GridObject* obj;
    for (int z = minZ; z < maxZ; z++) {
        for (; x < maxX; x++) {
            for (n = self->cells[x + row]; n >= 0; n = self->nodes[n].next) {
                GridNode& node = self->nodes[n];
                obj = node.object;
                if (obj != 0 && !obj->isMarked()) {
                    obj->mark();
                    self->results[count++] = obj;
                }
            }
        }
        x = minX;
        row += self->countX;
    }
    GridObject** p = self->results;
 for (n = 0; n < count; n++) { obj = *p++; obj->flags &= ~2; }
    self->resultCount = count;
    return count;
}

extern "C" int fn_80266FF8(Grid2D* self, int prev, const Sphere* s, IRect* out)
{
    int minX = roundDown(self->countX * (self->invX * ((s->x - s->r) - self->originX)));
    int minZ = roundDown(self->countZ * (self->invZ * ((s->z - s->r) - self->originZ)));
    int maxX = roundUp(self->countX * (self->invX * ((s->x + s->r) - self->originX)));
    int maxZ = roundUp(self->countZ * (self->invZ * ((s->z + s->r) - self->originZ)));
    minX = fn_801EC764(0, minX);
    minZ = fn_801EC764(0, minZ);
    maxX = fn_801EC778(self->countX, maxX);
    maxZ = fn_801EC778(self->countZ, maxZ);
    if (prev != -1 && minX == out->minX && maxX == out->maxX && minZ == out->minZ && maxZ == out->maxZ) {
        return 0;
    }
    out->minX = minX;
    out->minZ = minZ;
    out->maxX = maxX;
    out->maxZ = maxZ;
    return 1;
}

/* ---- 80267248: collect ---- */
extern "C" int fn_802672CC(IndexGridView*,int,int,void*);
extern "C" int fn_80267248(IndexGridView*self,void*context,IndexGridBounds*bounds){
    int previous=-1;
    for(int y=bounds->y0;y<bounds->y1;++y){
        for(int x=bounds->x0;x<bounds->x1;++x){
            previous=fn_802672CC(self,x+y*self->columns,previous,context);
        }
    }
    return previous;
}

/* ---- 802672CC: record chains ---- */

extern "C" int fn_802672CC(IndexGridView*self,int cell,int previous,void*context){
    int index=fn_80267400((IndexGridAcquireView*)self);
    int head=self->cellHeads[cell];
    if(head!=-1)self->records[head].next=index;
    IndexGridRecord*record=&self->records[index];
    record->chain=previous;
    record->previous=head;
    record->next=-1;
    record->context=context;
    record->cell=cell;
    self->cellHeads[cell]=index;
    return index;
}
extern "C" void fn_8026736C(IndexGridView*self,int index){
    while(index!=-1){
        int released=index;
        IndexGridRecord*record=&self->records[index];
        if(record->previous!=-1)self->records[record->previous].next=record->next;
        if(record->next!=-1)self->records[record->next].previous=record->previous;
        else self->cellHeads[record->cell]=record->previous;
        index=record->chain;
        record->chain=self->freeHead;
        record->cell=-1;
        self->freeHead=released;
        ++self->freeCount;
    }
}

/* ---- 80267400: acquire ---- */
extern "C" int fn_80267400(IndexGridAcquireView*self){
 int result=self->freeHead;
 IndexGridAcquireRecord*record=&self->records[result];
 self->freeHead=record->chain;
 if(self->freeHead<0){
  self->freeHead=self->records.count;
  self->freeCount+=16;
  int count=self->freeHead+16;
  self->records.resize(count);
  self->records[result].chain=self->freeHead;
  int i=self->freeHead;
  for(;i<count-1;++i){self->records[i].chain=i+1;self->records[i].cell=-1;}
  IndexGridAcquireRecord*last=&self->records[i];
  last->chain=-1;
  self->records[i].cell=-1;
 }
 --self->freeCount;
 return result;
}

/* ---- 802676F4: platform record reset ---- */

typedef unsigned int Word;
struct PlatformResetRecord {
    char unknown00[16];
    float a, b;
    Word word18, word1C;
    int word20;
    Word word24, words28[6];
};

extern "C" void fn_802676F4(PlatformResetRecord* self) {
    self->words28[0] = 0;
    self->words28[1] = 0;
    self->words28[2] = 0;
    self->words28[3] = 0;
    self->words28[4] = 0;
    self->words28[5] = 0;
    self->word20 = -1;
    self->word24 = 0;
    self->word1C = 0;
    self->word18 = 0;
    self->a = 0.0f;
    self->b = 0.0f;
}

/* ---- 80267734 ---- */
extern "C" {
/* Original scalar operations with private observed layouts.
 * See docs/notes/game-scalar-late.md. */


int fn_80267734(int a,int b) { if (a > b) b=a; return b; }
}
