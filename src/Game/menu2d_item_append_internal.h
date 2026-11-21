#ifndef ROTFD_MENU2D_ITEM_APPEND_INTERNAL_H
#define ROTFD_MENU2D_ITEM_APPEND_INTERNAL_H

// Observed menu-item storage and native copy behavior from GSQE78.
typedef unsigned long u32;
extern "C" {
extern char lbl_8028F698[];
void* fn_8028FAF4(void*, void*, u32, u32);
void* fn_8028FF24(void*, u32);
void fn_8028FD50(void*, void*, u32);
}
inline void* operator new(unsigned long, void* p) { return p; }

struct Name_800A59D4 {
    u32 value;
    Name_800A59D4() { value = 0; }
};
struct MenuPosition {
    float x, y;
    MenuPosition(const MenuPosition& other) : x(other.x), y(other.y) {}
};
struct MenuItemHeader {
    char name[128];
    Name_800A59D4 keyword, next, previous;
    unsigned short flags;
};
struct MenuItem : MenuItemHeader {
    Name_800A59D4 parameters[8];
    unsigned char center0, center1, parameterCount, lineUp;
    MenuPosition position;
};

template<class T> struct MenuAppendArray {
    int count, capacity;
    T* data;

    void storage(int size) {
        if (size) {
            if (data)
                data = (T*)fn_8028FAF4(lbl_8028F698, data,
                                     capacity * sizeof(T), size * sizeof(T));
            else
                data = (T*)fn_8028FF24(lbl_8028F698, size * sizeof(T));
        } else if (data) {
            fn_8028FD50(lbl_8028F698, data, capacity * sizeof(T));
            data = 0;
        }
    }
    int append(const T& value) {
        if (count + 1 > capacity) {
            storage(capacity + 32);
            capacity += 32;
        }
        new (&data[count++]) T(value);
        return count - 1;
    }
};
struct Menu2DAppendView {
    char unknown00[0x38];
    MenuAppendArray<MenuItem*> pointers;
    char unknown44[0x24];
    MenuAppendArray<MenuItem> elements;
};

typedef char CheckMenuItemHeader[sizeof(MenuItemHeader) == 0x90 ? 1 : -1];
typedef char CheckMenuItem[sizeof(MenuItem) == 0xBC ? 1 : -1];
typedef char CheckMenuArray[sizeof(MenuAppendArray<MenuItem>) == 12 ? 1 : -1];
#endif
