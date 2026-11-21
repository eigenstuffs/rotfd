#ifndef GAME_RESOURCE_MODE_UPDATE_VIEWS_H
#define GAME_RESOURCE_MODE_UPDATE_VIEWS_H

struct ResourceModeResource {
    char unknown00[0x38];
    unsigned long long flags;
};

struct ResourceModePrefix {
    int unknown00;
};

struct ResourceModeQuery : ResourceModePrefix {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual ResourceModeResource* getResource();
};

extern "C" void fn_8006B968(ResourceModeQuery*, unsigned char);
extern "C" void fn_8006B9D4(ResourceModeQuery*, unsigned char);

#endif
