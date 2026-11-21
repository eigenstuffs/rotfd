#ifndef GAME_ENGINE_PACKED_GEOMETRY_STREAM_H
#define GAME_ENGINE_PACKED_GEOMETRY_STREAM_H

typedef unsigned long PackedStreamWord;

extern "C" {
extern char lbl_8028F698[];
void* fn_8028FAF4(void*, void*, PackedStreamWord, PackedStreamWord);
void* fn_8028FF24(void*, PackedStreamWord);
void fn_8028FD50(void*, void*, PackedStreamWord);
void* fn_801E9F40(void*, const void*, int);
}

inline void* operator new(unsigned long, void* p) { return p; }

struct PackedStreamTriple { short x, y, z; };

template<class T> struct PackedStreamArray {
    int count, capacity;
    T* data;

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

    void resize(int n) {
        int i;
        if (n > count) {
            reserve(n);
            for (i = count; i < n; i++)
                new(data + i) T;
            count = n;
        } else if (n < count) {
            for (i = count - 1; i >= n; i--)
                data[i].~T();
            reserve(n);
            count = n;
        }
    }
};

struct PackedStreamBits {
    int unknown;
    PackedStreamArray<PackedStreamWord> words;
    int count;

    void resize(int n) {
        count = n;
        if (n && (n >> 5) + 1 > words.count)
            words.resize((count >> 5) + 1);
    }
};

struct PackedStreamVector { float x, y, z; };

/* Partial layout: the final fixed span is read as its original raw field range. */
struct PackedStreamOwner {
    PackedStreamArray<PackedStreamTriple> vertices;
    PackedStreamArray<unsigned short> indices;
    PackedStreamBits flags;
    PackedStreamVector first;
    char middle[0x40];
    PackedStreamVector last;
};

struct PackedGeometryStream { void* position; };

extern "C" void fn_802647FC(PackedStreamOwner*, PackedGeometryStream*);

#endif
