struct Vec2w {
    float v[2];
};

struct Src8027210C {
    char pad0[0x10];
    int unk10;
    int unk14;
    char pad18[0x48];
    Vec2w unk60[8];
};

struct Entry8027210C {
    unsigned short unk0;
    unsigned short unk2;
    int unk4;
    int unk8;
    int unkC;
    float mtx[3][4];
    Vec2w unk40[8];
    int unk80;
    int unk84;
    float unk88;
    float unk8C;
    float unk90;
    float unk94;
    char pad98[0x10];
};

struct Owner8027210C {
    char pad0[0x2D0];
    unsigned short unk2D0;
    int unk2D4;
    char pad2D8[8];
    float mtx[3][4];
    char pad310[0x90];
    float unk3A0;
    float unk3A4;
    float unk3A8;
    Entry8027210C* entries;
    int count;

    Entry8027210C* Alloc() {
        Entry8027210C* base;
        int off;
        int n;
        base = entries;
        n = count;
        off = n * sizeof(Entry8027210C);
        Entry8027210C* e = (Entry8027210C*)((char*)base + off);
        e->unk2 = n + 1;
        count++;
        return e;
    }
};

extern "C" void fn_800F6D38(float (*src)[4], float (*dst)[4]);

#pragma push
#pragma opt_propagation off
extern "C" void fn_8027210C(Owner8027210C* self, Src8027210C* src, int arg, float f) {
    Entry8027210C* e = self->Alloc();
    e->unk4 = arg;
    e->unk0 = self->unk2D0;
    e->unkC = self->unk2D4;
    e->unk80 = src->unk14;
    fn_800F6D38(self->mtx, e->mtx);
    e->unk40[0] = src->unk60[0];
    e->unk40[1] = src->unk60[1];
    e->unk40[2] = src->unk60[2];
    e->unk40[3] = src->unk60[3];
    e->unk40[4] = src->unk60[4];
    e->unk40[5] = src->unk60[5];
    e->unk40[6] = src->unk60[6];
    e->unk40[7] = src->unk60[7];
    e->unk84 = src->unk10;
    e->unk88 = self->unk3A0;
    e->unk8C = self->unk3A4;
    e->unk90 = self->unk3A8;
    e->unk94 = f;
}
#pragma pop
