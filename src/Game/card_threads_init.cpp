struct CardThreadOwnerView {
    char unknown00[0x38];
    char thread[0x318];
    char queue[8];
    char mutex[24];
    unsigned long status;
    char* stack;
    char unknown378[0x9C];
    int transferSize;
    int transferCount;
};

extern "C" {
extern char lbl_801EF5C8[],lbl_80341038[];
extern const char lbl_802AF158[];
extern char* lbl_803780C4;
void __ct__13File_801F3E1CFv(void*);
void __dt__13File_801F3E1CFv(void*, int);
void CARDInit();
signed char fn_801F3814(const char*);
void fn_80276C40(CardThreadOwnerView*, const char*, int);
void* fn_801EFA1C(void*, unsigned long, const char*, const char*, int, int);
void OSInitThreadQueue(void*);
void OSInitMutex(void*);
signed char OSCreateThread(void*, void* (*)(void*), void*, void*, unsigned long, int, unsigned short);
int OSResumeThread(void*);
void* fn_80279100(void*);
void* fn_80279300(void*);
}

extern "C" int fn_80278EC4(CardThreadOwnerView* self)
{
    const char* messages = (const char*)&lbl_802AF158;
    char local[96];
    __ct__13File_801F3E1CFv(local);
    CARDInit();
    if (fn_801F3814(messages + 0x1A4)) {
        self->transferSize = 0x1800;
        self->transferCount = 2;
    }
    if (fn_801F3814(messages + 0x1C4))
        fn_80276C40(self, messages + 0x1C4, 2);
    self->stack = (char*)fn_801EFA1C(lbl_801EF5C8, 0x1000,
        messages + 0x4C, messages + 0x5C, 0x104, 0x20);
    lbl_803780C4 = (char*)fn_801EFA1C(lbl_801EF5C8, 0x1000,
        messages + 0x4C, messages + 0x5C, 0x105, 0x20);
    OSInitThreadQueue(self->queue);
    OSInitMutex(self->mutex);
    if (!OSCreateThread(self->thread, fn_80279100, self, self->stack + 0x1000,
                        0x1000, 0x10, 1)) {
        __dt__13File_801F3E1CFv(local, -1);
        return 0;
    }
    OSResumeThread(self->thread);
    if (!OSCreateThread(lbl_80341038, fn_80279300, 0, lbl_803780C4 + 0x1000,
                        0x1000, 0x10, 1)) {
        __dt__13File_801F3E1CFv(local, -1);
        return 0;
    }
    __dt__13File_801F3E1CFv(local, -1);
    return 1;
}
