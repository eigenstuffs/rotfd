/* The existing Light_Z.h factory allocates 0xB8 bytes for this constructor.
 * These observed members use the existing resource base and shared globals. */
extern "C" {
    extern float game_quat_identity[];
    extern float game_vec3_zero[];
    extern const float lbl_8037B3A8, lbl_8037B3AC;
    extern const unsigned char lbl_802EA288[];
    void* fn_80243F28(void*);
}

struct LightBase_8024405C {
    char unknown00[8];
    const void* table;
    char unknown0C[0x60];
    unsigned short type, flags;
    unsigned long field70;

    LightBase_8024405C() {
        fn_80243F28(this);
        table = lbl_802EA288;
    }
};

struct Light_8024405C : LightBase_8024405C {
    float quaternion[4];
    float field84, field88, field8C, field90, field94, field98;
    float field9C, fieldA0, fieldA4;
    unsigned char enabled;
    char unknownA9[3];
    float point[3];

    Light_8024405C();
};

typedef char LightBaseSizeCheck[(sizeof(LightBase_8024405C) == 0x74) ? 1 : -1];
typedef char LightSizeCheck[(sizeof(Light_8024405C) == 0xB8) ? 1 : -1];

Light_8024405C::Light_8024405C() {
    type = 12;
    field84 = lbl_8037B3AC;
    field88 = lbl_8037B3AC;
    field8C = lbl_8037B3AC;
    point[0] = game_vec3_zero[0];
    point[1] = game_vec3_zero[1];
    point[2] = game_vec3_zero[2];
    field90 = lbl_8037B3A8;
    field94 = lbl_8037B3A8;
    field98 = lbl_8037B3AC;
    field9C = lbl_8037B3A8;
    fieldA0 = lbl_8037B3A8;
    fieldA4 = lbl_8037B3A8;
    quaternion[0] = game_quat_identity[0];
    quaternion[1] = game_quat_identity[1];
    quaternion[2] = game_quat_identity[2];
    quaternion[3] = game_quat_identity[3];
    enabled = 1;
    unsigned short enabledFlags = flags;
    enabledFlags |= 0x20;
    flags = enabledFlags;
}
