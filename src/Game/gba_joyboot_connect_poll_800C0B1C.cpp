/* GBA joy-boot connection state machine for one transfer record. */
typedef unsigned long Word;
struct TransferRecord {
    int state;
    unsigned long type;
    int pending;
    int timeout;
    Word gap10;
    Word identity;
    Word gap18;
    signed char channel;
    unsigned char status;
    unsigned char progress;
    unsigned char unknown1F;
    unsigned char received;
};
struct Context { char gap00[0x110]; void* logger; };
extern "C" {
extern Context lbl_801E9D24;
extern const char lbl_802A17D8[];
extern unsigned char* lbl_803777D8;
extern int lbl_803777DC;
extern int lbl_803777E0;
extern unsigned char lbl_803777E4;
extern unsigned char lbl_80306E28[];
unsigned long SIProbe(int);
int GBAReset(int, unsigned char*);
int GBAGetStatus(int, unsigned char*);
int GBAGetProcessStatus(int, unsigned char*);
int GBARead(int, void*, unsigned char*);
int GBAWrite(int, const void*, unsigned char*);
int GBAJoyBootAsync(int, int, int, unsigned char*, int, unsigned char*, void (*)(int, unsigned long));
void fn_800C085C(int, unsigned long);
char* strncpy(char*, const char*, unsigned long);
void fn_801FA014(void*, const char*, ...);
}

inline int readIdentity(TransferRecord* self) {
    int result = GBAGetStatus(self->channel, &self->status);
    if (result != 0) return result;
    if (self->status != 0x28) return 1;
    Word value;
    result = GBARead(self->channel, &value, &self->status);
    if (result != 0) return result;
    self->identity = value;
    self->received = 1;
    return 0;
}

inline int writeIdentity(TransferRecord* self) {
    int result = GBAGetStatus(self->channel, &self->status);
    if (result != 0) return result;
    if (self->status != 0x20) return 1;
    result = GBAWrite(self->channel, lbl_803777D8, &self->status);
    if (result != 0) return result;
    result = GBAGetStatus(self->channel, &self->status);
    if (result != 0) return result;
    if (self->status != 0x30) return 1;
    return 0;
}

extern "C" void fn_800C0B1C(TransferRecord* self) {
    const char* pool = lbl_802A17D8;
    switch (self->state) {
    case 0:
        self->pending = 1;
    case 1: {
        self->progress = 0;
        self->unknown1F = 0;
        self->received = 0;
        unsigned long type = SIProbe(self->channel);
        if (type == 0x80 || type == 8 || type == 0x40) return;
        if (type != 0x40000) { self->type = type; return; }
        self->state = 2;
        self->timeout = 30;
    }
    case 2:
        if (GBAReset(self->channel, &self->status) != 0) goto fail;
        if (readIdentity(self)) { self->state = 2; goto fail; }
        self->type = 0x40000;
        if (writeIdentity(self)) { self->state = 2; goto fail; }
        if (lbl_803777E0 == -1) {
            char name[5];
            strncpy(name, (const char*)&self->identity, 4);
            name[4] = 0;
            fn_801FA014(lbl_801E9D24.logger, pool + 0x80, name);
            lbl_803777E0 = self->channel;
            self->state = 6;
            return;
        }
        self->state = 3;
        return;
    case 3:
        if (SIProbe(self->channel) != 0x40000) { self->state = 0; return; }
        return;
    case 4:
        self->state = 5;
        self->timeout = 30;
    case 5:
        if (self->pending == 0) {
            fn_801FA014(lbl_801E9D24.logger, pool + 0x94, self->channel);
            self->state = 1;
            lbl_803777E4 = 1;
            return;
        }
        if (GBAGetProcessStatus(self->channel, &self->progress) == 2) {
            if (self->timeout != 0) self->timeout--;
            return;
        }
        if (self->timeout == 0) { self->state = 0; return; }
        fn_801FA014(lbl_801E9D24.logger, pool + 0xB4, self->channel);
        self->timeout--;
        {
            /* The original read the channel byte unsigned and converted it. */
            int channel = (signed char)*(const unsigned char*)&self->channel;
            GBAJoyBootAsync(channel, channel * 2, 2, lbl_80306E28, lbl_803777DC, &self->status, fn_800C085C);
        }
        return;
    fail:
        if (self->timeout == 0) {
            self->state = 4;
            self->pending = 1;
        } else {
            self->timeout--;
        }
    }
}
