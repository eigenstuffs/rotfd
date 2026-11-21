#include "Game/callback_related_dispatch_internal.h"
struct IndexDispatchOwner {
    char unknown0[4];
    CallbackRelatedHandle own;
    char unknown8[0x58];
    CallbackRelatedHandle handle60;
    int index;
    char unknown68[4];
    CallbackRelatedHandle handle6C;
};
struct IndexDispatchStorage {char unknown0[8];};
struct IndexDispatchVirtual:IndexDispatchStorage {
    virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();
    virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();
    virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();
    virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();
    virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();
    virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();
    virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74(int,int);
};
extern "C" {
void fn_801C4F7C(void*);void fn_801C6C94(void*);void fn_801C4BC4(void*);
void fn_802020AC(void*);void fn_8025ECD8(void*,int);
void fn_801FC26C(void*,int,CallbackRelatedHandle*,int,float);
}
extern "C" void fn_8025D054(IndexDispatchOwner*self){
    void*object=resolveRelated(self->handle6C);
    fn_801C4F7C(object);
    fn_801C6C94(object);
    fn_801C4BC4(object);
    fn_802020AC(resolveRelated(self->handle60));
    ((IndexDispatchVirtual*)self)->slot74(0,0);
    fn_8025ECD8(self,3);
    float index=(float)self->index;
    fn_801FC26C(resolveRelated(self->handle60),11,&self->own,31,index);
}
