#ifndef GAME_OWNER_RESET_ACTION_VIEWS_H
#define GAME_OWNER_RESET_ACTION_VIEWS_H

extern "C" {
unsigned long fn_801F948C(void*, const char*);
extern const char lbl_8029DC78[], lbl_8029DC84[];
}

struct ResetName {
    unsigned long value;
    ResetName(const char* text) { value = fn_801F948C(this, text); }
};

extern "C" {
void fn_80229C30(void*, const ResetName&);
void fn_80229BBC(void*, const ResetName&);
void fn_8007D7F4(void*, int);
void fn_8025795C(void*, signed char, signed char);
void fn_80055EE4(void*, int);
}

struct ResetVector {
    float x, y, z;
    ResetVector& operator=(const ResetVector& other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }
};

struct ResetAgent {
    char unknown00[0x30];
    unsigned long long flags30;
    unsigned long long flags38;
    char unknown40[0x104];
    ResetVector velocity;
    char unknown150[0x1C8];
    char controls;
};

struct ResetAction {
    char unknown00[8];
    ResetAgent* agent;
    ResetAgent* target;
};

struct ResetScreenWorld {
    char unknown00[0x15058];
    void* screen;
};

struct ResetContext {
    char unknown00[0x124];
    ResetScreenWorld* world;
};

extern "C" {
extern const ResetVector game_vec3_zero;
extern ResetContext lbl_801E9D24;
}

#endif
