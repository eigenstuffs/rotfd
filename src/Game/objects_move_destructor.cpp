// Private destruction view: the original vtables and full virtual interface stay external.
struct Handle_801F7F10 { unsigned long value; Handle_801F7F10(); ~Handle_801F7F10(); };
struct MoveDtorHandle1:Handle_801F7F10 {};
struct MoveDtorHandle2:MoveDtorHandle1 {};
struct RecordPool_80209D30 { char unknown[0x24]; ~RecordPool_80209D30(); };
extern "C" {
extern char __vt__11ObjectsMove[];
extern char lbl_801EF5C8[];
void fn_801EF610(void*,void*);
void fn_801E5EA4(void*,int);
extern struct { char unknown00[0x150]; void* resource; } lbl_801E9D24;
}
struct MoveDtorInterface {
    char unknown00[0x130];
};
struct MoveDtorPrefix {unsigned long unknown00[2];};
struct MoveDtorVirtual:MoveDtorPrefix {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4C();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5C();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6C();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7C();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8C();
    virtual int index();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9C();
    virtual void slotA0();
    virtual void slotA4();
    virtual void slotA8();
    virtual void slotAC();
    virtual void slotB0();
    virtual void slotB4();
    virtual void slotB8();
    virtual void slotBC();
    virtual void slotC0();
    virtual void slotC4();
    virtual void slotC8();
    virtual void slotCC();
    virtual void slotD0();
    virtual void slotD4();
    virtual void slotD8();
    virtual void slotDC();
    virtual void slotE0();
    virtual void slotE4();
    virtual void slotE8();
    virtual void slotEC();
    virtual void slotF0();
    virtual void slotF4();
    virtual void slotF8();
    virtual void slotFC();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10C();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11C();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void remove(int);
};

struct ObjectsBase_802EB3F8 {
    unsigned long unknown00[2]; MoveDtorInterface* vtable;
    char unknown0C[0x168-0xC];
    ~ObjectsBase_802EB3F8();
};
struct ObjectsMove:ObjectsBase_802EB3F8 {
    MoveDtorHandle1 handle168;
    unsigned long unknown16C;
    int mode170;
    MoveDtorHandle2 handle174;
    char unknown178[8];
    RecordPool_80209D30 pool180;
    char unknown1A4[4];
    ~ObjectsMove();
    static void operator delete(void* memory){fn_801EF610(lbl_801EF5C8,memory);}
};
typedef char CheckMoveDtorBase[sizeof(ObjectsBase_802EB3F8)==0x168?1:-1];
typedef char CheckMoveDtorPool[sizeof(RecordPool_80209D30)==0x24?1:-1];
typedef char CheckMoveDtorOwner[sizeof(ObjectsMove)==0x1A8?1:-1];

ObjectsMove::~ObjectsMove(){
    vtable=(MoveDtorInterface*)__vt__11ObjectsMove;
    if(mode170>=0 && lbl_801E9D24.resource){
        for(int current=((MoveDtorVirtual*)this)->index();current>=0;current=((MoveDtorVirtual*)this)->index())
            ((MoveDtorVirtual*)this)->remove(current);
        fn_801E5EA4(lbl_801E9D24.resource,mode170);
    }
}
