#ifndef ROTFD_MENU_ITEM_TEXT_INTERNAL_H
#define ROTFD_MENU_ITEM_TEXT_INTERNAL_H
#include "objects_owner_internal.h"
#include "menu2d_item_append_internal.h"
// Observed virtual interface of the object held by the menu's second handle.
struct MenuTextResolver : BaseObject_Z {
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
    virtual void slot54();
    virtual void slot58();
    virtual void slot5C();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6C();
    virtual u32 slot70(const Name_800A59D4&,const Name_800A59D4&);
};
struct MenuTextHandle : OwnerHandle {
    MenuTextResolver* get() const { return (MenuTextResolver*)OwnerHandle::get(); }
};
struct MenuItemTextView {
    char unknown00[0x24];
    MenuTextHandle resolver;
    char unknown28[0x48];
    MenuItem* items;
};
extern "C" int fn_801F44DC(char*,const char*,void*);
#endif
