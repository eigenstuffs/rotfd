extern "C" {
extern char lbl_8028F698[];
extern struct { char unknown00[0x118]; void* manager; } lbl_801E9D24;
void* fn_8028FAF4(void*, void*, unsigned long, unsigned long);
void* fn_8028FF24(void*, unsigned long);
void fn_8028FD50(void*, void*, unsigned long);
void fn_801F86C8(void*, const void*, int);
}
inline void* operator new(unsigned long, void* address) { return address; }
struct Handle_801F7F10 {
    unsigned long value;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct SparseInsertZero1 : Handle_801F7F10 { SparseInsertZero1() { value = 0; } };
struct SparseInsertHandle : SparseInsertZero1 {
    SparseInsertHandle(const SparseInsertHandle& input) {
        value = input.value;
        fn_801F86C8(lbl_801E9D24.manager, &input, 1);
    }
    SparseInsertHandle& operator=(const SparseInsertHandle& input) {
        fn_801F86C8(lbl_801E9D24.manager, this, -1);
        value = input.value;
        fn_801F86C8(lbl_801E9D24.manager, &input, 1);
        return *this;
    }
};
struct SparseInsertArray {
    int count, capacity;
    SparseInsertHandle* items;
    SparseInsertHandle& operator[](int i) { return items[i]; }
    void storage(int n) {
        if (n) {
            if (items) items = (SparseInsertHandle*)fn_8028FAF4(lbl_8028F698, items, capacity * 4, n * 4);
            else items = (SparseInsertHandle*)fn_8028FF24(lbl_8028F698, n * 4);
        } else if (items) {
            fn_8028FD50(lbl_8028F698, items, capacity * 4);
            items = 0;
        }
    }
    void append(const SparseInsertHandle& input) {
        if (count + 1 > capacity) { storage(capacity + 8); capacity += 8; }
        new (&items[count++]) SparseInsertHandle(input);
    }
};
struct SparseInsertWords {
    int count, capacity;
    unsigned long* words;
    void reserve(int n) {
        if (n) {
            if (words) words = (unsigned long*)fn_8028FAF4(lbl_8028F698, words, capacity * 4, n * 4);
            else words = (unsigned long*)fn_8028FF24(lbl_8028F698, n * 4);
        } else if (words) {
            fn_8028FD50(lbl_8028F698, words, capacity * 4);
            words = 0;
        }
        capacity = n;
    }
    void resize(int n) {
        if (n > count) {
            reserve(n);
            for (int i = count; i < n; ++i) {}
            count = n;
        } else if (n < count) {
            for (int i = count - 1; i >= n; --i) {}
            reserve(n);
            count = n;
        }
    }
};
struct SparseInsertSelf : SparseInsertArray {
    SparseInsertWords occupied;
    int bitCount, limit, used;
    void setSize(int n) {
        bitCount = n;
        if (n && ((n >> 5) + 1) > occupied.count) occupied.resize((bitCount >> 5) + 1);
    }
    void setBit(int i) { occupied.words[i >> 5] |= 1UL << (i & 31); }
};
extern "C" int fn_80207B94(SparseInsertWords*, signed char, int);
inline int findSparseInsert(SparseInsertSelf* self) {
    if (self->limit == 0) return -1;
    return fn_80207B94(&self->occupied, 0, 0);
}
extern "C" int fn_8026B908(SparseInsertSelf* self, const SparseInsertHandle& input) {
    int index = findSparseInsert(self);
    ++self->used;
    if (index == -1) {
        self->append(input);
        self->setSize(self->limit + 1);
        self->setBit(self->limit);
        return self->limit++;
    }
    (*self)[index] = input;
    self->setBit(index);
    return index;
}
