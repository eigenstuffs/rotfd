#ifndef GAME_ENGINE_GRID_RECORD_STREAM_H
#define GAME_ENGINE_GRID_RECORD_STREAM_H

typedef unsigned long GridStreamWord;

extern "C" {
extern char lbl_8028F698[];
void* fn_8028FAF4(void*, void*, GridStreamWord, GridStreamWord);
void* fn_8028FF24(void*, GridStreamWord);
void fn_8028FD50(void*, void*, GridStreamWord);
void* fn_801E9F40(void*, const void*, int);
}

inline void* operator new(unsigned long, void* p) { return p; }

template<class T> struct GridStreamArray {
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

struct GridStreamRecord {
    int previous, next, chain, cell;
    void* context;
    GridStreamRecord() { context = 0; }
};

/* Partial view of the streamed grid fields. */
struct GridStreamOwner {
    char unknown[0x18];
    int columns, rows, freeHead, freeCount;
    GridStreamArray<int> heads;
    GridStreamArray<GridStreamRecord> records;
};

struct GridRecordStream { void* position; };
extern "C" void fn_802668E0(GridStreamOwner*, GridRecordStream*);

#endif
