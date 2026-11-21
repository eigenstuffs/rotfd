#ifndef GAME_ENGINE_MENU_ITEM_PARSER_H
#define GAME_ENGINE_MENU_ITEM_PARSER_H

typedef unsigned long MenuItemWord;
extern "C" {
    extern const char lbl_8037AFD8[2], lbl_8037AFDC[2], lbl_8037AFE0[5];
    extern const char lbl_8037AFE8[8], lbl_8037AFF0[8], lbl_8037AFF8[8];
    extern const char lbl_8037B000[7], lbl_8037B008[5], lbl_8037B010[5], lbl_8037B018[5];
    MenuItemWord fn_801F948C(void*, const char*);
    char* strcpy(char*, const char*);
    int strcmp(const char*, const char*);
    void fn_801F372C(void*, char*);
    signed char fn_801F2F3C(void*);
    int fn_8021C558(void*, const void*);
    void fn_8021C7F4(void*, void*);
}
struct MenuItemName {
    MenuItemWord word;
    MenuItemName() { word = 0; }
    void operator=(const char* text) { word = fn_801F948C(this, text); }
};
struct MenuParsedItem {
    char name[128];
    MenuItemName keyword, next, previous;
    unsigned short flags;
    MenuParsedItem(): flags(0) {}
};
struct MenuItemStringView {
    const char* text;
    MenuItemStringView(const char* value): text(value) {}
    operator const char*() const { return text; }
};
typedef char MenuParsedItemSizeCheck[(sizeof(MenuParsedItem) == 144) ? 1 : -1];

#endif
