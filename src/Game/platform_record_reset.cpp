#include "Game/platform_followup_controls.h"

typedef unsigned int Word;
struct PlatformResetRecord {
    char unknown00[16];
    float a, b;
    Word word18, word1C;
    int word20;
    Word word24, words28[6];
};
extern "C" const float lbl_8037B62C;

extern "C" void fn_802676F4(PlatformResetRecord* self) {
    self->words28[0] = 0;
    self->words28[1] = 0;
    self->words28[2] = 0;
    self->words28[3] = 0;
    self->words28[4] = 0;
    self->words28[5] = 0;
    self->word20 = -1;
    self->word24 = 0;
    self->word1C = 0;
    self->word18 = 0;
    self->a = lbl_8037B62C;
    self->b = lbl_8037B62C;
}
