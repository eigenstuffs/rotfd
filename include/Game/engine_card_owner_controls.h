#ifndef GAME_ENGINE_CARD_OWNER_CONTROLS_H
#define GAME_ENGINE_CARD_OWNER_CONTROLS_H

struct CardOwnerControlsView {
    char unknown00[0x4A8];
    char label4A8[32];
    int unknown4C8;
    int state4CC;
    int connected4D0;
};

extern "C" void fn_80276BF0(CardOwnerControlsView* self);
extern "C" void fn_80276F58(CardOwnerControlsView* self, const char* name);

#endif
