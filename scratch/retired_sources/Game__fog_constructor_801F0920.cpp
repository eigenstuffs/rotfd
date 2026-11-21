/* Observed initialized prefix of the object allocated by the HFog_Z.h
 * factory. The remaining object fields retain their existing state. */
struct FogPrefix_801F0920 {
    char unknown00[8];
    void* table;
    char unknown0C[0x60];
    unsigned short kind;
    unsigned short flags;
    char unknown70[4];
    float field74, field78, field7C;
};

extern "C" {
    void fn_80243F28(FogPrefix_801F0920*);
    extern char lbl_802EA958[];
    extern const float lbl_8037A6B8;

    FogPrefix_801F0920* fn_801F0920(FogPrefix_801F0920* self) {
        fn_80243F28(self);
        self->table = lbl_802EA958;
        self->kind = 13;
        self->field74 = lbl_8037A6B8;
        self->field78 = lbl_8037A6B8;
        self->field7C = lbl_8037A6B8;
        unsigned short enabledFlags = self->flags;
        enabledFlags |= 0x20;
        self->flags = enabledFlags;
        return self;
    }
}
