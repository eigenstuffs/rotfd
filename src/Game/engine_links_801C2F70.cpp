typedef unsigned long U32;
extern "C" {
    extern char lbl_802E9F98[],__vt__13Manipulator_Z[],lbl_801EF5C8[],lbl_8028F698[];
    void fn_801EF610(void*,void*);
    void fn_8028FD50(void*,void*,int);
}
struct Activable_Z{
    U32 words[2];
    void*vtable;
    char tail[0x10];
    ~Activable_Z();
};
struct Manipulator_Z:Activable_Z{
    float scalar;
    ~Manipulator_Z(){
        vtable=__vt__13Manipulator_Z;
    }
};
struct Element_801C2F70{
    char data[32];
    ~Element_801C2F70(){
    }
};
struct Pool_801C2F70{
    int count,capacity;
    Element_801C2F70*data;
    ~Pool_801C2F70(){
        if(data){
            for(int i=0;i<count;i++)data[i].~Element_801C2F70();
            if(data){
                fn_8028FD50(lbl_8028F698,data,capacity*32);
                data=0;
            }data=0;
        }
    }
};
struct Handle_801F7F10{
    U32 value;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct HandleLayer0_801C2F70:Handle_801F7F10{
    HandleLayer0_801C2F70(){
        value=0;
    }~HandleLayer0_801C2F70(){
    }
};
struct HandleLayer1_801C2F70:HandleLayer0_801C2F70{
    HandleLayer1_801C2F70(){
        value=0;
    }~HandleLayer1_801C2F70(){
    }
};
struct HandleLayer2_801C2F70:HandleLayer1_801C2F70{
    HandleLayer2_801C2F70(){
        value=0;
    }~HandleLayer2_801C2F70(){
    }
};
struct DrawPair_801C2F70:Manipulator_Z{
    char pad20[4];
    HandleLayer1_801C2F70 first,second;
    char pad2c[4];
    HandleLayer2_801C2F70 third;
    Pool_801C2F70 firstRecords,secondRecords;
    ~DrawPair_801C2F70();
    static void operator delete(void*p){
        fn_801EF610(lbl_801EF5C8,p);
    }
};
DrawPair_801C2F70::~DrawPair_801C2F70(){
    vtable=lbl_802E9F98;
}
