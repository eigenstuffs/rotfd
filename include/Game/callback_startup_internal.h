#ifndef GAME_CALLBACK_STARTUP_INTERNAL_H
#define GAME_CALLBACK_STARTUP_INTERNAL_H

struct CallbackStartupPrefix {
    char unknown0[8];
    void* table;
    char unknownC[0x2C];
    unsigned long long flags;
    char unknown40[0x40];
};

struct CallbackStartupWords {
    unsigned long words[3];
};

extern "C" {
void __ct__23CallbackSingle_802ECA18Fv(void*);
void fn_8025A930();
void __ct__24CallbackControl_802ECC00Fv(void*);
void fn_8025BCC4();
void fn_8025E714(void*, const CallbackStartupWords*);
void fn_80020FE8(void*, int);
void __dt__17LodAgent_802EC8A8Fv(void*, int);
extern void* lbl_80378060;
extern unsigned long lbl_80378040;
extern char lbl_802ECC00[];
extern char lbl_802EC8A8[];
extern CallbackStartupWords lbl_802ECBB8;
}

#endif
