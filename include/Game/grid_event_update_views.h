#ifndef GAME_GRID_EVENT_UPDATE_VIEWS_H
#define GAME_GRID_EVENT_UPDATE_VIEWS_H

struct GridEventNode {
    char unknown00[0x90];
    short value;
};

struct GridEventCell {
    short index;
    GridEventNode* node;
    float x, y, z;
};

struct GridEventOwner {
    char unknown00[0x74];
    GridEventCell cells[9];
    char unknown128[0x264];
    int counter;
};

struct GridEventPrefix {
    int unknown00;
};

struct GridEventQuery : GridEventPrefix {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void* getResource();
};

struct GridEventContext {
    char unknown00[0x110];
    void* logger;
};

struct GridEventFormats {
    char prefix[0x24];
    char row0[0x2C];
    char row1[0x2C];
    char row2[0x2C];
};

extern "C" {
extern GridEventQuery* lbl_803776B8;
extern GridEventContext lbl_801E9D24;
extern const float lbl_80378910, lbl_80378900;
extern const char lbl_8029C8E0[0xA8];
extern const char lbl_80378914[2];
void fn_802073E8(void*, int, void*, float);
signed char fn_8025E9FC(void*, int);
void fn_800729C8(GridEventOwner*);
int sprintf(char*, const char*, ...);
void fn_801FA014(void*, const char*, ...);
}

#endif
