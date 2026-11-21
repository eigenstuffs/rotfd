#ifndef GAME_ENGINE_HANDLE_ARRAY_STREAM_RESIZE_H
#define GAME_ENGINE_HANDLE_ARRAY_STREAM_RESIZE_H

typedef unsigned long HandleStreamWord;
struct Handle_801F7F10 {
    HandleStreamWord value;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct HandleStreamZero : Handle_801F7F10 {
    HandleStreamZero() { value = 0; }
    ~HandleStreamZero() {}
};
struct HandleStreamValue : HandleStreamZero {
    HandleStreamValue() { value = 0; }
    ~HandleStreamValue() {}
};
struct HandleArrayStream { void* position; };
extern "C" {
extern char lbl_8028F698[];
void* fn_8028FAF4(void*, void*, HandleStreamWord, HandleStreamWord);
void* fn_8028FF24(void*, HandleStreamWord);
void fn_8028FD50(void*, void*, HandleStreamWord);
void* fn_801E9F40(void*, const void*, int);
void fn_801B3FD0(void*, Handle_801F7F10*, HandleArrayStream*);
}
inline void* operator new(unsigned long, void* p) { return p; }
struct HandleStreamArray {
    int count, capacity;
    HandleStreamValue* data;
    void reserve(int n) {
        if (n) {
            if (data)
                data = (HandleStreamValue*)fn_8028FAF4(lbl_8028F698, data,
                    capacity * sizeof(HandleStreamValue), n * sizeof(HandleStreamValue));
            else
                data = (HandleStreamValue*)fn_8028FF24(lbl_8028F698,
                    n * sizeof(HandleStreamValue));
        } else if (data) {
            fn_8028FD50(lbl_8028F698, data, capacity * sizeof(HandleStreamValue));
            data = 0;
        }
        capacity = n;
    }
    void resize(int n) {
        int i;
        if (n > count) {
            reserve(n);
            for (i = count; i < n; i++)
                new(data + i) HandleStreamValue;
            count = n;
        } else if (n < count) {
            for (i = count - 1; i >= n; i--)
                data[i].~HandleStreamValue();
            reserve(n);
            count = n;
        }
    }
};
/* Partial Root storage; this entry explicitly calls its existing native method. */
struct BaseObject_Z {
    HandleStreamWord unknown[3];
    void slot0C(HandleStreamWord);
};
struct HandleStreamOwner : BaseObject_Z { HandleStreamArray handles; };

extern "C" void fn_802642C4(HandleStreamOwner*, HandleArrayStream*);

#endif
