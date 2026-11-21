/* Original engine lifetime and record routines.
 * See docs/notes/game-engine-record-transfer.md. */
typedef unsigned int u32;
typedef unsigned long long u64;
struct Vec3_801BC99C {
    float x,y,z;
    void operator=(const Vec3_801BC99C&v) {
        x=v.x;
        y=v.y;
        z=v.z;
    }
};
struct Vec2_801BC99C {
    float x,y;
};
struct Child_801BC99C {
    char unknown000[0x120];
    u32 flags120;
};
struct Record_801BC99C {
    Child_801BC99C*object;
    Vec3_801BC99C vector04,vector10,vector1C,vector28;
    void*pointer34;
    Vec2_801BC99C vector38;
    u64 flags40;
    void*pointer48,*pointer4C;
    float value50;
    void operator=(const Record_801BC99C&r) {
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
struct Owner_801BC99C {
    char unknown000[0x78];
    Record_801BC99C record;
};
extern "C" {
    void fn_801BCB78(Record_801BC99C*,void*,const Vec3_801BC99C*);
    void fn_8023EEF0(Child_801BC99C*);
    void fn_801D5DF8(Vec3_801BC99C*,void*,void*,void*,const Vec2_801BC99C*);
}
extern "C" Child_801BC99C*fn_801BC99C(Owner_801BC99C*self,Vec3_801BC99C*first,Vec3_801BC99C*second,Vec3_801BC99C*third) {
    *first=self->record.vector04;
    *second=self->record.vector1C;
    *third=self->record.vector28;
    Child_801BC99C*object=self->record.object;
    if(object&&(object->flags120&0x800)&&(self->record.flags40&0x1000000000000ULL)) {
        fn_8023EEF0(object);
        void*firstArgument=self->record.pointer48;
        Vec3_801BC99C result;
        Vec2_801BC99C coordinate=self->record.vector38;
        fn_801D5DF8(&result,firstArgument,self->record.pointer4C,self->record.pointer34,&coordinate);
        *second=result;
    }
    return self->record.object;
}
