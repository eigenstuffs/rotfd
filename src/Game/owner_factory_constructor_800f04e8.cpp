/* Two original subobjects retain their native destruction identities. */
extern "C" {
    void fn_8007D550(void*);
    extern unsigned char lbl_801EF5C8[],lbl_802C96DC[];
    extern const char lbl_802AB880[],lbl_802AB890[];
    void* fn_801EFA1C(void*,unsigned int,const char*,const char*,int,int);
}
struct ObjectsRoot_80213EBC {
    unsigned long unknown00[2];
    void* vtable;
    char unknown0C[0x14];
    ObjectsRoot_80213EBC();
    ~ObjectsRoot_80213EBC();
};
struct Object_8007D594 {
    void* secondaryTable;
    char unknown04[0x28];
    Object_8007D594() { fn_8007D550(this); }
    ~Object_8007D594();
};
struct Object_800F04E8:ObjectsRoot_80213EBC,Object_8007D594 {
    void** slots;
    Object_800F04E8();
};
Object_800F04E8::Object_800F04E8() {
    vtable=lbl_802C96DC;
    secondaryTable=lbl_802C96DC+0x40;
    slots=(void**)fn_801EFA1C(lbl_801EF5C8,96,lbl_802AB880,lbl_802AB890,8,4);
}
