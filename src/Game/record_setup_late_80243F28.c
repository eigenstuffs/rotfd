extern float game_vec4_zero[];
extern const float lbl_8037B3A0;
extern const unsigned char __vt__17Resource_802E9E20[];
extern const unsigned char lbl_802EC164[];
extern void __ct__12BaseObject_ZFv(void *object);
void *fn_80243F28(void *object) {
    __ct__12BaseObject_ZFv(object);
    *(const void * *)((char *)object+8)=__vt__17Resource_802E9E20;
    *(const void * *)((char *)object+8)=lbl_802EC164;
    *(float *)((char *)object+12)=game_vec4_zero[0];
    *(float *)((char *)object+16)=game_vec4_zero[1];
    *(float *)((char *)object+20)=game_vec4_zero[2];
    *(float *)((char *)object+24)=lbl_8037B3A0;
    *(unsigned short *)((char *)object+108)=0;
    *(unsigned short *)((char *)object+110)=0;
    *(unsigned int *)((char *)object+112)=0;
    return object;
}
