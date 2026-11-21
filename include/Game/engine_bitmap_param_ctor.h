#ifndef GAME_ENGINE_BITMAP_PARAM_CTOR_H
#define GAME_ENGINE_BITMAP_PARAM_CTOR_H

struct RootStorage_80207414 { unsigned long unknown0,identity; };
struct BaseObject_Z : RootStorage_80207414 {
    BaseObject_Z();
    virtual ~BaseObject_Z();
    virtual void slot0C(unsigned long);
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual signed char slot1C();
};
struct Resource_802E9E20 : BaseObject_Z {
    Resource_802E9E20() {}
    virtual ~Resource_802E9E20();
};
struct Bitmap_802EBEE0 : Resource_802E9E20 {
    unsigned char storage[0x3C];
    Bitmap_802EBEE0(int,int,unsigned char);
    virtual ~Bitmap_802EBEE0();
    virtual void slot18();
};
extern "C" void fn_80238BA8(Bitmap_802EBEE0*,int,int,unsigned char);

#endif
