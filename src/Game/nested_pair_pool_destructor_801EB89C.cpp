// Two word pools form each 24-byte record in this array.
extern "C" {
extern char lbl_8028F698[];
extern char lbl_801EF5C8[];
void fn_8028FD50(void*, void*, int);
void fn_801EF610(void*, void*);
}

template <int N> struct PoolElement {
    char data[N];
    ~PoolElement() {}
};

template <class T> struct Pool {
    int count;
    int capacity;
    T* data;

    ~Pool() {
        if (data) {
            for (int i = 0; i < count; ++i)
                data[i].~T();
            if (data) {
                fn_8028FD50(lbl_8028F698, data, capacity * sizeof(T));
                data = 0;
            }
            data = 0;
        }
    }
};

struct PoolPair : Pool<PoolElement<4> > {
    Pool<PoolElement<4> > second;
    ~PoolPair() {}
};

struct NestedPairPool {
    int count;
    int capacity;
    PoolPair* data;

    ~NestedPairPool();
    static void operator delete(void* p) {
        fn_801EF610(lbl_801EF5C8, p);
    }
};

NestedPairPool::~NestedPairPool() {
    if (data) {
        for (int i = 0; i < count; ++i)
            data[i].~PoolPair();
        if (data) {
            fn_8028FD50(lbl_8028F698, data, capacity * sizeof(PoolPair));
            data = 0;
        }
        data = 0;
    }
}
