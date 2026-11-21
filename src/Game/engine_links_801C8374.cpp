/* Original engine lifetime and record routines.
* See docs/notes/game-engine-links.md. */
typedef unsigned long U32;
extern "C" {
    extern char lbl_802EA040[],__vt__13Manipulator_Z[],lbl_801EF5C8[],lbl_8028F698[];
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
struct Element_801C8374{
    char data[32];
    ~Element_801C8374(){
    }
};
struct Pool_801C8374{
    int count,capacity;
    Element_801C8374*data;
    ~Pool_801C8374(){
        if(data){
            for(int i=0;i<count;i++)data[i].~Element_801C8374();
            if(data){
                fn_8028FD50(lbl_8028F698,data,capacity*32);
                data=0;
            }data=0;
        }
    }
};
struct DrawNode_801C8374:Manipulator_Z{
    char pad20[8];
    Pool_801C8374 records;
    ~DrawNode_801C8374();
    static void operator delete(void*p){
        fn_801EF610(lbl_801EF5C8,p);
    }
};
DrawNode_801C8374::~DrawNode_801C8374(){
    vtable=lbl_802EA040;
}
