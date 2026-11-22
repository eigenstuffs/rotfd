#ifndef GSQE78_GAME_CURVE_LOAD_H
#define GSQE78_GAME_CURVE_LOAD_H

typedef unsigned long size_t;

inline void *operator new(size_t, void *p) { return p; }

struct Allocator { char reserved[16]; };
struct Registry { char pad[0x118]; void *descriptor; };

extern "C" {
extern Allocator lbl_8028F698;
extern Registry lbl_801E9D24;
extern const float lbl_8037A218;
void *fn_8028FAF4(Allocator *, void *, int, int);
void *fn_8028FF24(Allocator *, int);
void fn_8028FD50(Allocator *, void *, int);
unsigned char *fn_801E9F40(void *, unsigned char *, int);
void __ct__15Handle_801F7F10Fv(void *);
void __dt__15Handle_801F7F10Fv(void *, short);
void fn_801B41B8(void *, void *, unsigned char **);
}

template<int Size> struct Key {
    short time;
    unsigned char payload[Size - 2];

    Key() : time(0) {}
    ~Key() {}
};

struct ReferenceKey {
    short time;
    short reserved;
    unsigned int reference;

    ReferenceKey() : time(0) { __ct__15Handle_801F7F10Fv(&reference); }
    ~ReferenceKey() { __dt__15Handle_801F7F10Fv(&reference, -1); }
};

struct Key20 {
    short time;
    short reserved;
    float fields_04[2], field_0c, field_10;

    Key20() : time(0), field_0c(lbl_8037A218) {}
    ~Key20() {}
};

template<class T> struct Array {
    int count, capacity;
    T *data;

    void resize_storage(int n)
    {
        if (n) {
            if (data)
                data = (T *)fn_8028FAF4(&lbl_8028F698, data,
                                        capacity * sizeof(T), n * sizeof(T));
            else
                data = (T *)fn_8028FF24(&lbl_8028F698, n * sizeof(T));
        } else if (data) {
            fn_8028FD50(&lbl_8028F698, data, capacity * sizeof(T));
            data = 0;
        }
        capacity = n;
    }

    void resize(int n)
    {
        int i;
        if (n > count) {
            resize_storage(n);
            for (i = count; i < n; ++i)
                new (&data[i]) T;
            count = n;
        } else if (n < count) {
            for (i = count - 1; i >= n; --i)
                data[i].~T();
            resize_storage(n);
            count = n;
        }
    }
};

template<class T> struct Curve {
    unsigned short mode;
    Array<T> keys;
};

template<class T> inline void load(Curve<T> *curve, unsigned char **cursor)
{
    *cursor = fn_801E9F40(curve, *cursor, 2);
    int count;
    *cursor = fn_801E9F40(&count, *cursor, 4);
    curve->keys.resize(count);
    *cursor = fn_801E9F40(curve->keys.data, *cursor, count * sizeof(T));
}

#endif
