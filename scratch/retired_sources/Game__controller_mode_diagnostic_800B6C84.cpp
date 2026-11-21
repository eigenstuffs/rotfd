// Store a controller mode and log its description from the shared format pool.
struct ControllerModeOwner_800B6C84 {
    char unknown00[0x1C];
    unsigned long* modes;
};
struct ControllerModeContext_800B6C84 {
    char unknown00[0x110];
    void* logger;
};

extern "C" {
extern ControllerModeContext_800B6C84 lbl_801E9D24;
extern const char lbl_802A0550[];
int sprintf(char*, const char*, ...);
void fn_801FA014(void*, const char*, ...);
}

extern "C" void fn_800B6C84(ControllerModeOwner_800B6C84* self, int index,
                            unsigned long mode) {
    const char* pool = lbl_802A0550;
    char text[64];
    self->modes[index] = mode;
    switch (mode) {
    case 0: sprintf(text, pool + 0x68); break;
    case 1: sprintf(text, pool + 0x7C); break;
    case 2: sprintf(text, pool + 0x94); break;
    case 3: sprintf(text, pool + 0xAC); break;
    case 4: sprintf(text, pool + 0xC4); break;
    case 5: sprintf(text, pool + 0xE0); break;
    case 6: sprintf(text, pool + 0xFC); break;
    case 7: sprintf(text, pool + 0x11C); break;
    case 8: sprintf(text, pool + 0x138); break;
    }
    fn_801FA014(lbl_801E9D24.logger, pool + 0x14C, text);
}
