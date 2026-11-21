#ifndef GAME_ENGINE_MENU_RESOURCE_LOAD_H
#define GAME_ENGINE_MENU_RESOURCE_LOAD_H

typedef unsigned long u32;
struct MenuHandleBits {signed int generation:8,index:24;};
struct Handle_801F7F10 {u32 word;Handle_801F7F10();~Handle_801F7F10();};
struct MenuEntry {void*object;char unknown04[8];
    signed char generation;char unknown0D[3];};
struct MenuManagerPrefix {char unknown00[8];MenuEntry*entries;char unknown0C[0x18];};
struct MenuManager:MenuManagerPrefix {
 virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
 virtual Handle_801F7F10 lookup(const void*);
};
struct MenuGroups {char unknown00[8];u32*handles;};
struct MenuContext {char unknown00[0x118];MenuManager*manager;MenuGroups*groups;};
extern "C" {extern MenuContext lbl_801E9D24;
    void fn_801F86C8(MenuManager*,const void*,short);void*fn_801F7EB8(const void*);
    void fn_801F372C(void*,char*);
    void fn_801F3238(void*,unsigned short*);
    void fn_801F2F54(void*,char*);
    signed char fn_801F2E04(void*);
    u32 fn_801F948C(void*,const char*);
    int fn_8026BC50(MenuGroups*,const void*);
    char*strcpy(char*,const char*);
    int strcmp(const char*,const char*);
    extern const char lbl_8037B020[8],lbl_8037B028[8],lbl_8037B030[6],lbl_8037B038[5],lbl_8037B008[5],lbl_802AE90C[10];}
struct MenuZeroHandle:Handle_801F7F10 {MenuZeroHandle(){word=0;}};
struct MenuLoadHandle:MenuZeroHandle {MenuLoadHandle(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}};
struct MenuLoadPrefix {u32 unknown00[2];};
struct MenuLoader:MenuLoadPrefix {
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
    virtual void finish(int);
 char unknown0C[0x14];u32 group;char unknown24[0xC];int mode;char unknown34[0x10];unsigned short field44;char unknown46[2];unsigned char field48;
};
extern "C" void fn_8021C7F4(MenuLoader*,void*);
struct MenuName {u32 word;MenuName(const char*text){word=fn_801F948C(this,text);}};
static inline void*menuLoadResolve(const MenuLoadHandle&h){const MenuHandleBits&bits=*(const MenuHandleBits*)&h;MenuEntry*e=&lbl_801E9D24.manager->entries[bits.index];return e->generation==bits.generation?e->object:0;}

typedef char MenuLoadHandleSizeCheck[(sizeof(MenuLoadHandle)==4)?1:-1];
typedef char MenuLoaderSizeCheck[(sizeof(MenuLoader)==0x4C)?1:-1];
extern "C" signed char fn_8021CB30(MenuLoader*,const void*);

#endif
