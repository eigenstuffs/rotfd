extern "C" unsigned int fn_801F948C(void *,const char *);
struct Key_801B3AD8 {
    unsigned int value;
    Key_801B3AD8(const char *text){
        value=fn_801F948C(this,text);
    }
};
struct ManagerStorage_801B3AD8 {
    char pad[0x24];
};
struct Manager_801B3AD8:ManagerStorage_801B3AD8 {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C(int,Key_801B3AD8);
    char pad28[0xA1];
    signed char active,loading;
};
struct StateStorage_801B3AD8 {
    char pad[0x860];
    int count;
    char pad864[4];
    int selection;
    const char *name;
    char pad870[0x2A0];
};
struct State_801B3AD8:StateStorage_801B3AD8{
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C(int);
};
struct Globals_801B3AD8 {
    char pad[0x110];
    State_801B3AD8 *state;
    char gap[4];
    Manager_801B3AD8 *manager;
};
extern "C" Globals_801B3AD8 lbl_801E9D24;
extern "C" const char lbl_802AC8D0[],lbl_802AC8E4[];
extern "C" void fn_801FA014(State_801B3AD8 *,const char *,...);
extern "C" int fn_801B3AD8(void){
    if(lbl_801E9D24.state->count<2){
        fn_801FA014(lbl_801E9D24.state,lbl_802AC8D0);
        return 0;
    }
    lbl_801E9D24.manager->loading=1;
    if(lbl_801E9D24.state->count==2){
        lbl_801E9D24.manager->slot1C(lbl_801E9D24.state->selection,Key_801B3AD8(lbl_802AC8E4));
    }
    else{
        lbl_801E9D24.manager->slot1C(lbl_801E9D24.state->selection,Key_801B3AD8(lbl_801E9D24.state->name));
    }
    if(lbl_801E9D24.manager->active)lbl_801E9D24.state->slot1C(2);
    return 1;
}
