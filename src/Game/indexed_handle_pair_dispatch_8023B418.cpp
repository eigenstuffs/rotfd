/* Observed indexed device interface and native Handle lifetimes. */
typedef unsigned long Word;

struct Handle_801F7F10 {
    Word value;
    Handle_801F7F10();
    ~Handle_801F7F10();
};

struct IndexedDevicePad_8023B418 { char unknown00[0x7C]; };
struct IndexedDevice_8023B418 : IndexedDevicePad_8023B418 {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
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
    virtual void slot48();
    virtual void slot4C();
    virtual void slot50();
    virtual void slot54(Handle_801F7F10*, Word, const Handle_801F7F10*,
                        Handle_801F7F10*);
};

struct IndexedContext_8023B418 { char unknown00[0x118]; void* manager; };
extern "C" {
    extern IndexedContext_8023B418 lbl_801E9D24;
    Handle_801F7F10 fn_801F5C04(IndexedDevice_8023B418*, int, int);
    void fn_801F86C8(void*, const void*, int);
}

struct IndexedZeroHandle_8023B418 : Handle_801F7F10 {
    IndexedZeroHandle_8023B418() { value = 0; }
};
struct IndexedCopyHandle_8023B418 : IndexedZeroHandle_8023B418 {
    IndexedCopyHandle_8023B418(const Handle_801F7F10& source) {
        value = source.value;
        fn_801F86C8(lbl_801E9D24.manager, &source, 1);
    }
    ~IndexedCopyHandle_8023B418() {}
};

extern "C" void fn_8023B418(IndexedDevice_8023B418* self,
                           const Handle_801F7F10* first, int index, int event,
                           Word flags, const Handle_801F7F10* second) {
    if (index >= 0) {
        IndexedCopyHandle_8023B418 selected(fn_801F5C04(self, index, event));
        self->slot54(&selected, flags, first,
                     &IndexedCopyHandle_8023B418(*second));
    }
}
