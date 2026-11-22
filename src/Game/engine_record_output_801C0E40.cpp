typedef unsigned int u32;
typedef unsigned long long u64;
struct Vec3_801C0E40 {
    float x,y,z;
    void operator=(const Vec3_801C0E40&v) {
        x=v.x;
        y=v.y;
        z=v.z;
    }
};
struct Vec2_801C0E40 {
    float x,y;
};
struct Child_801C0E40 {
    char unknown000[0x120];
    u32 flags120;
};
struct Record_801C0E40 {
    Child_801C0E40*object;
    Vec3_801C0E40 vector04,vector10,vector1C,vector28;
    void*pointer34;
    Vec2_801C0E40 vector38;
    u64 flags40;
    void*pointer48,*pointer4C;
    float value50;
    void operator=(const Record_801C0E40&r) {
        object=r.object;
        vector04=r.vector04;
        vector10=r.vector10;
        vector1C=r.vector1C;
        vector28=r.vector28;
        pointer34=r.pointer34;
        vector38.x=r.vector38.x;
        vector38.y=r.vector38.y;
        flags40=r.flags40;
        pointer48=r.pointer48;
        pointer4C=r.pointer4C;
        value50=r.value50;
    }
};
struct Slot_801C0E40 {
    char unknown[0x50];
    Record_801C0E40 record;
};
struct Owner_801C0E40 {
    char unknown000[0x188];
    struct Slot_801C0E40*records;
};
extern "C" {
    void fn_801BCB78(Record_801C0E40*,void*,const Vec3_801C0E40*);
    void fn_8023EEF0(Child_801C0E40*);
    void fn_801D5DF8(Vec3_801C0E40*,void*,void*,void*,const Vec2_801C0E40*);
}
extern "C" void fn_801C0E40(Owner_801C0E40*self,void*input,const Vec3_801C0E40*offset,int index) {
    Record_801C0E40 result;
    fn_801BCB78(&result,input,offset);
    self->records[index].record=result;
}
