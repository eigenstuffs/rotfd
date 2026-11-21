extern "C" {
extern char lbl_8028F698[];
void* fn_8028FAF4(void*, void*, unsigned long, unsigned long);
void* fn_8028FF24(void*, unsigned long);
void fn_8028FD50(void*, void*, unsigned long);
void* fn_8028FACC(void*, unsigned long);
void fn_8028F8F0(void*, void*, unsigned long);
void DCInvalidateRange(void*, unsigned long);
void DCStoreRange(void*, unsigned long);
void GXBeginDisplayList(void*, unsigned long);
unsigned long GXEndDisplayList(void);
void GXResetWriteGatherPipe(void);
void GXBegin(int, int, unsigned short);
}

inline void* operator new(unsigned long, void* p) { return p; }

#define GXFIFO_S16 (*(volatile short*)0xCC008000)

struct DispList {
    void* data;
    unsigned long size;
    unsigned long used;
    DispList() : data(0), size(0), used(0) {}
    ~DispList()
    {
        if (data) fn_8028F8F0(lbl_8028F698, data, size);
        data = 0;
        size = 0;
        used = 0;
    }
};

template <class T> struct Array {
    int count, capacity;
    T* data;
    T& operator[](int i) { return data[i]; }
};

template <class T> inline void reserve(Array<T>* a, int n)
{
    if (n) {
        if (a->data) a->data = (T*)fn_8028FAF4(lbl_8028F698, a->data, a->capacity * sizeof(T), n * sizeof(T));
        else a->data = (T*)fn_8028FF24(lbl_8028F698, n * sizeof(T));
    } else if (a->data) {
        fn_8028FD50(lbl_8028F698, a->data, a->capacity * sizeof(T));
        a->data = 0;
    }
}

template <class T> inline void resize(Array<T>* a, int n, int& i)
{
    if (n > a->count) {
        if (n > a->capacity) {
            reserve(a, n);
            a->capacity = n;
        }
        int g;
        for (g = a->count; g < n; ++g) new (a->data + g) T;
        a->count = n;
    } else if (n < a->count) {
        for (i = a->count - 1; i >= n; --i) { T* p = &a->data[i]; p->~T(); }
        a->count = n;
    }
}

template <class T> inline void push(Array<T>* a)
{
    if (a->count + 1 > a->capacity) {
        reserve(a, a->capacity + 8);
        a->capacity += 8;
    }
    new (&a->data[a->count++]) T;
}

template <class T> inline T* ptrAt(Array<T>* a, int i) { return &a->data[i]; }
struct Strip {
    int count;
    int unk4;
    short* indices;
    int unkC;
    int unk10;
    int getCount() const { return count; }
    short& at(int i) { return indices[i]; }
};

struct Strip2 {
    int unk0;
    int unk4;
    short* indices;
};

struct Mesh {
    char pad0[0xA4];
    Array<Strip> stripArr;  /* 0xA4 */
    Array<Strip2> strip2Arr; /* 0xB0 */
    char padBC[0x44];
    int* ids;               /* 0x100 */
    Array<DispList> lists;  /* 0x104 */
    void* list;             /* 0x110 */
    unsigned long listSize; /* 0x114 */
    unsigned long listUsed; /* 0x118 */
};

#define STRIP(off) ((Strip*)((char*)self->stripArr.data + (off)))
#define STRIP2(off) ((Strip2*)((char*)self->strip2Arr.data + (off)))

extern "C" void fn_8026D980(Mesh* self)
{
    short i;
    int off1;
    short j;
    short k;
    short n;
    short cnt2;
    int ri;

    if (self->lists.count != 0) resize(&self->lists, 0, ri);

    n = self->stripArr.count;
    j = 0;
    for (i = 0; i < n; i++) {
        off1 = (short)self->ids[i] * sizeof(Strip);
        push(&self->lists);
        DispList* d1 = &self->lists[j++];
        d1->size = (STRIP(off1)->count * 8 + 0x42) & ~31;
        d1->data = fn_8028FACC(lbl_8028F698, d1->size);
    }

    for (i = 0, j = 0; i < n; i++, j++) {
        int id = (short)self->ids[i];
        off1 = id * sizeof(Strip);
        DispList* d2 = &self->lists[j];
        DCInvalidateRange(d2->data, d2->size);
        GXBeginDisplayList(d2->data, d2->size);
        GXResetWriteGatherPipe();
        short cnt = STRIP(off1)->count;
        GXBegin(0x98, 0, cnt);
        for (k = 0; k < cnt; k++) {
            GXFIFO_S16 = STRIP(off1)->indices[k];
            GXFIFO_S16 = STRIP2(id * sizeof(Strip2))->indices[k * 2 + 1];
            GXFIFO_S16 = STRIP(off1)->indices[k];
            GXFIFO_S16 = STRIP2(id * sizeof(Strip2))->indices[k * 2];
        }
        d2 = &self->lists[j];
        d2->used = GXEndDisplayList();
        DCStoreRange(d2->data, d2->size);
    }

    if (self->list == 0) {
        int size = 0;
        for (i = 0; i < n; i++) size += self->stripArr[i].getCount() * 2 + 3;
        self->listSize = (size + 0x3F) & ~31;
        self->list = fn_8028FACC(lbl_8028F698, self->listSize);
        DCInvalidateRange(self->list, self->listSize);
        GXBeginDisplayList(self->list, self->listSize);
        GXResetWriteGatherPipe();
        for (j = 0; j < n; j++) {
            cnt2 = self->stripArr[j].count;
            GXBegin(0x98, 4, cnt2);
            for (k = 0; k < cnt2; k++) GXFIFO_S16 = self->stripArr[j].at(k);
        }
        self->listUsed = GXEndDisplayList();
        DCStoreRange(self->list, self->listSize);
    }
}
