/* Stream read of a nested handle-record owner (fn_801AD094). */
typedef unsigned long StreamWord_801AD094;
extern "C" {
extern char lbl_8028F698[];
void* fn_8028FAF4(void*, void*, StreamWord_801AD094, StreamWord_801AD094);
void* fn_8028FF24(void*, StreamWord_801AD094);
void fn_8028FD50(void*, void*, StreamWord_801AD094);
void fn_801B41B8(void*, void*, void**);
void* fn_801E9F40(void*, void*, StreamWord_801AD094);
void fn_801B217C(void*, void**);
void fn_801B1DC4(void*, void**);
void fn_801B2354(void*, void**);
void fn_801B1A14(void*, void**);
void fn_801F6BFC(void*, void**);
}
inline void* operator new(unsigned long, void* p) { return p; }
struct RootStorage_80207414 { unsigned long unknown00, identity; };
struct BaseObject_Z : RootStorage_80207414 {
    BaseObject_Z();
    virtual ~BaseObject_Z();
    virtual void slot0C(unsigned long);
};
struct Handle_801F7F10 { StreamWord_801AD094 value; Handle_801F7F10(); ~Handle_801F7F10(); };
struct NestedReadHandle : Handle_801F7F10 { NestedReadHandle() { value = 0; } ~NestedReadHandle() {} };
struct NestedReadElement : NestedReadHandle { StreamWord_801AD094 tail; ~NestedReadElement() {} };
template <class T> struct NestedReadArray {
    int count, capacity;
    T* items;
    void reserve(int n)
    {
        if (n) {
            if (items) items = (T*)fn_8028FAF4(lbl_8028F698, items, capacity * sizeof(T), n * sizeof(T));
            else items = (T*)fn_8028FF24(lbl_8028F698, n * sizeof(T));
        } else if (items) {
            fn_8028FD50(lbl_8028F698, items, capacity * sizeof(T));
            items = 0;
        }
        capacity = n;
    }
    void resize(int n)
    {
        int i;
        if (n > count) {
            reserve(n);
            for (i = count; i < n; ++i) new (items + i) T;
            count = n;
        } else if (n < count) {
            for (i = count - 1; i >= n; --i) items[i].~T();
            reserve(n);
            count = n;
        }
    }
};
struct NestedReadRow {
    unsigned short key;
    NestedReadArray<NestedReadElement> records;
};
struct WrappedReadRow {
    unsigned short key;
    Handle_801F7F10 handle;
    StreamWord_801AD094 field08;
    char unknown0C[0xC];
    StreamWord_801AD094 field18;
};
struct WrappedReadOwner {
    StreamWord_801AD094 unknown00;
    NestedReadArray<WrappedReadRow> rows;
};
struct NestedReadCurve { int unknown00, count; void* items; int unknown0C; };
struct NestedReadOwner : BaseObject_Z {
    char unknown0C[0x14];
    Handle_801F7F10 handle20;
    StreamWord_801AD094 field24;
    NestedReadCurve curve28, curve38, curve48, curve58;
    WrappedReadOwner wrapped68;
    StreamWord_801AD094 unknown78;
    NestedReadArray<NestedReadRow> nested7C;
    NestedReadCurve curve88, curve98;
    char objectA8[0x14];
    StreamWord_801AD094 fieldBC;
    char unknownC0[8];
    StreamWord_801AD094 fieldC8;
};
struct NestedReadGlobals { char unknown00[0x118]; void* manager; };
extern "C" NestedReadGlobals lbl_801E9D24;
extern "C" void fn_801AD678(WrappedReadOwner*, int);
extern "C" void fn_801AD438(NestedReadArray<NestedReadRow>*, int, signed char);

extern "C" void fn_801AD094(NestedReadOwner* self, void** stream)
{
    self->BaseObject_Z::slot0C((unsigned long)stream);
    fn_801B41B8(lbl_801E9D24.manager, &self->handle20, stream);
    *stream = fn_801E9F40(&self->field24, *stream, 4);
    fn_801B217C(&self->curve28, stream);
    fn_801B1DC4(&self->curve38, stream);
    fn_801B217C(&self->curve48, stream);
    fn_801B2354(&self->curve58, stream);
    fn_801B1A14(&self->curve88, stream);
    fn_801B1A14(&self->curve98, stream);
    fn_801F6BFC(self->objectA8, stream);
    int count;
    int i;
    *stream = fn_801E9F40(&count, *stream, 4);
    fn_801AD678(&self->wrapped68, count);
    for (i = 0; i < count; ++i) {
        fn_801B41B8(lbl_801E9D24.manager, &self->wrapped68.rows.items[i].handle, stream);
        WrappedReadRow& row = self->wrapped68.rows.items[i];
        *stream = fn_801E9F40(&row.field08, *stream, (char*)&row.field18 - (char*)&row.field08 + sizeof(row.field18));
    }
    *stream = fn_801E9F40(&count, *stream, 4);
    fn_801AD438(&self->nested7C, count, 0);
    for (i = 0; i < count; ++i) {
        long n;
        *stream = fn_801E9F40(&n, *stream, 4);
        self->nested7C.items[i].records.resize(n);
        *stream = fn_801E9F40(&self->nested7C.items[i].key, *stream, 2);
        for (int j = 0; j < n; ++j) {
            fn_801B41B8(lbl_801E9D24.manager, &((NestedReadRow*)((char*)self->nested7C.items + 16*i))->records.items[j], stream);
            *stream = fn_801E9F40(&((NestedReadRow*)((char*)self->nested7C.items + 16*i))->records.items[j].tail, *stream, 4);
        }
    }
    *stream = fn_801E9F40(&self->fieldBC, *stream, (char*)&self->fieldC8 - (char*)&self->fieldBC + sizeof(self->fieldC8));
}
