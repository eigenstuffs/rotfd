#ifndef GAME_ENGINE_CONTROLLER_SHUTDOWN_H
#define GAME_ENGINE_CONTROLLER_SHUTDOWN_H

/* Partial storage and virtual-slot views for the global shutdown entry. */
typedef unsigned long ShutdownWord;

extern "C" {
extern char lbl_801EF5C8[], lbl_8028F698[];
void fn_801EF610(void*, void*);
void fn_8028FD50(void*, void*, int);
void fn_801EA0FC();
void fn_801FB0F4(void*);
void fn_80263B08(void*, short);
void fn_801B5D04(void*, short);
void fn_801C9DA0(void*, short);
void fn_8007F33C();
void fn_801B57F4(void*);
}

template<int N> struct ShutdownStorage { char unknown[N]; };
template<> struct ShutdownStorage<0> {};

template<int N> struct ShutdownService : ShutdownStorage<N> {
    virtual ~ShutdownService();
    virtual void slot0C();
    virtual void slot10();
};

struct ShutdownLog : ShutdownStorage<0xB10> {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
};

struct ShutdownOwner : ShutdownStorage<0x7C> {
    virtual void slot08();
    virtual void slot0C();
    virtual ~ShutdownOwner();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
};

struct ShutdownController : ShutdownStorage<0x24> {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual ~ShutdownController();
    char unknown28[0xA0];
    signed char flag;
};

struct Handle_801F7F10 {
    ShutdownWord word;
    ~Handle_801F7F10();
};
struct ShutdownHandle : Handle_801F7F10 { ~ShutdownHandle() {} };
struct ShutdownRecordBase {
    Handle_801F7F10 handle;
    ShutdownWord unknown[2];
    ~ShutdownRecordBase() {}
};
struct ShutdownRecord : ShutdownRecordBase { ~ShutdownRecord() {} };
struct ShutdownElement { ShutdownWord word; ~ShutdownElement() {} };

template<class T> struct ShutdownArray {
    int count, capacity;
    T* data;
    ~ShutdownArray() {
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

struct ShutdownArrayLayer : ShutdownArray<ShutdownRecord> { ~ShutdownArrayLayer() {} };
struct ShutdownReserved : ShutdownArrayLayer {
    ShutdownWord unknown0C;
    ShutdownElement* reserved;
    ~ShutdownReserved() {
        if (reserved) {
            if (reserved)
                fn_801EF610(lbl_801EF5C8, (char*)reserved - 16);
        }
    }
    static void operator delete(void* p) { fn_801EF610(lbl_801EF5C8, p); }
};
struct ShutdownPrefixPool {
    ShutdownWord unknown00;
    ShutdownReserved array;
    ~ShutdownPrefixPool() {}
    static void operator delete(void* p) { fn_801EF610(lbl_801EF5C8, p); }
};
struct ShutdownPrefixDelete : ShutdownPrefixPool { ~ShutdownPrefixDelete() {} };
struct ShutdownReservedDelete : ShutdownReserved { ~ShutdownReservedDelete() {} };
struct ShutdownPair : ShutdownHandle {
    ShutdownHandle secondary;
    ~ShutdownPair() {}
    static void operator delete(void* p) { fn_801EF610(lbl_801EF5C8, p); }
};
struct Handle_801FFE58 {
    ShutdownWord word;
    ~Handle_801FFE58();
};
struct ShutdownFourHandles {
    Handle_801FFE58 handles[4];
    ShutdownWord unknown10;
    ShutdownArray<ShutdownHandle> array;
    ~ShutdownFourHandles() {}
    static void operator delete(void* p) { fn_801EF610(lbl_801EF5C8, p); }
};

struct ShutdownGlobals {
    char unknown00[0x110];
    ShutdownLog* log;
    ShutdownService<0x278>* service114;
    ShutdownController* controller;
    ShutdownService<0x24>* service11C;
    ShutdownService<0x10>* service120;
    void* unknown124;
    ShutdownPrefixDelete* pool128;
    ShutdownPrefixDelete* pool12C;
    ShutdownReservedDelete* pool130;
    ShutdownService<0x1C>* service134;
    ShutdownPair* pair;
    ShutdownFourHandles* four;
    void* unknown140;
    ShutdownOwner* owner144;
    void* service148;
    void* service14C;
    ShutdownService<0x40>* service150;
    ShutdownService<0x1C>* service154;
    ShutdownOwner* owner158;
    ShutdownService<8>* service15C;
    void* service160;
    void* unknown164;
    void* buffer168;
    ShutdownService<0>* service16C;
};

extern "C" {
extern ShutdownGlobals lbl_801E9D24;
void fn_8020B078();
}

#endif
