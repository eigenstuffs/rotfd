#ifndef GAME_ENGINE_MENU_SELECTION_WINDOW_H
#define GAME_ENGINE_MENU_SELECTION_WINDOW_H

struct MenuSelectionItem {
    char unknown00[0x8C];
    unsigned short flags;
};
struct MenuSelectionPrefix { unsigned long unknown00[2]; };
struct MenuSelectionWindow: MenuSelectionPrefix {
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
    virtual void refresh(int, int);
    char unknown0C[0x1C];
    short selected;
    short previous;
    short start;
    char unknown2E[2];
    int mode;
    char unknown34[4];
    int count;
    char unknown3C[4];
    MenuSelectionItem** items;
    unsigned short requestedVisible;
    unsigned short visible;
};
struct MenuSelectionGlobals {
    char unknown00[0x110];
    void* logger;
};
extern "C" {
    extern MenuSelectionGlobals lbl_801E9D24;
    extern const char lbl_802AE918[29];
    void fn_801FA014(void*, const char*, ...);
    int fn_8021DA0C(int, int);
    void fn_8021D51C(MenuSelectionWindow*, int);
}
typedef char MenuSelectionWindowSizeCheck[(sizeof(MenuSelectionWindow) == 0x48) ? 1 : -1];

#endif
