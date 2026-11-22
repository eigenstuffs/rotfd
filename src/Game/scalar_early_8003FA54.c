extern struct {char pad[0x164];void *target;} lbl_801E9D24;

int fn_8003FA54(void *object) {*((unsigned char *)lbl_801E9D24.target+0x10)^=1;return 1;}
