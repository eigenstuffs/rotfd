/* Assign one retained four-byte Handle array to another.
 * The element construction member preserves the original generic array lifetime.
 * The natural unused base-wrapper destructor receives no source credit.
 */
typedef unsigned long ArrayCopyWord;
extern "C" {
extern char lbl_8028F698[];
void* fn_8028FAF4(void*, void*, unsigned long, unsigned long);
void* fn_8028FF24(void*, unsigned long);
void fn_8028FD50(void*, void*, unsigned long);
void fn_801F86C8(void*, const void*, short);
}
struct ArrayCopyGlobals { char unknown00[0x118]; void* manager; };
extern "C" ArrayCopyGlobals lbl_801E9D24;
inline void* operator new(unsigned long, void* memory) { return memory; }
struct Handle_801F7F10 {
    ArrayCopyWord word;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct RetainedArrayCopyBase : Handle_801F7F10 {
    RetainedArrayCopyBase() { word = 0; }
    RetainedArrayCopyBase(const RetainedArrayCopyBase& h) {
        word = 0;
        word = h.word;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
    }
    ~RetainedArrayCopyBase() {}
};
struct RetainedArrayCopyHandle : RetainedArrayCopyBase {
    RetainedArrayCopyHandle() { word = 0; }
    RetainedArrayCopyHandle(const RetainedArrayCopyHandle& h)
        : RetainedArrayCopyBase(h) {}
    ~RetainedArrayCopyHandle() {}
};
template<class T> struct RetainedCopyArray {
    int count, capacity;
    T* data;
    const T& operator[](int i) const { return data[i]; }
    void reserve(int n) {
        if (n) {
            if (data)
                data = (T*)fn_8028FAF4(lbl_8028F698, data,
                                      capacity * sizeof(T), n * sizeof(T));
            else
                data = (T*)fn_8028FF24(lbl_8028F698, n * sizeof(T));
        } else if (data) {
            fn_8028FD50(lbl_8028F698, data, capacity * sizeof(T));
            data = 0;
        }
        capacity = n;
    }
    void constructElement(int i) { new (&data[i]) T; }
    void resize(int n, signed char keep) {
        if (n > count) {
            if (n > capacity || !keep) reserve(n);
            for (int i = count; i < n; ++i) constructElement(i);
            count = n;
        } else if (n < count) {
            for (int i = count - 1; i >= n; --i) data[i].~T();
            if (keep) count = n;
            else { reserve(n); count = n; }
        }
    }
    void append(const T& value) {
        if (count + 1 > capacity) {
            int n = capacity + 32;
            if (n) {
                if (data)
                    data = (T*)fn_8028FAF4(lbl_8028F698, data,
                                          capacity * sizeof(T), n * sizeof(T));
                else
                    data = (T*)fn_8028FF24(lbl_8028F698, n * sizeof(T));
            } else if (data) {
                fn_8028FD50(lbl_8028F698, data, capacity * sizeof(T));
                data = 0;
            }
            capacity += 32;
        }
        new (&data[count++]) T(value);
    }
};
extern "C" void fn_801D1D6C(RetainedCopyArray<RetainedArrayCopyHandle>*, int);
extern "C" RetainedCopyArray<RetainedArrayCopyHandle>* fn_801D1B60(
    RetainedCopyArray<RetainedArrayCopyHandle>* self,
    const RetainedCopyArray<RetainedArrayCopyHandle>* other) {
    self->resize(0, 1);
    fn_801D1D6C(self, other->count);
    for (int i = 0; i < other->count; ++i) self->append((*other)[i]);
    return self;
}
typedef char CopyHandleSize[(sizeof(RetainedArrayCopyHandle) == 4) ? 1 : -1];
typedef char CopyArraySize[(sizeof(RetainedCopyArray<RetainedArrayCopyHandle>) == 12) ? 1 : -1];
