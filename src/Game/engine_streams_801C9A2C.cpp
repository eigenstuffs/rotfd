struct Storage_801C9A2C  {
    char pad[8];
};
struct Service_801C9A2C : Storage_801C9A2C  {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14(int);
    virtual void slot18();
};
struct State_801C9A2C  {
    char pad[0x860];
    int count;
    char gap[4];
    int selection;
};
extern "C" struct  {
    char pad[0x110];
    State_801C9A2C *state;
    char gap[0x48];
    Service_801C9A2C *service;
}
lbl_801E9D24;
extern "C" int fn_801C9A2C()  {
    if(lbl_801E9D24.state->count<2)return 0;
    lbl_801E9D24.service->slot14(lbl_801E9D24.state->selection);
    lbl_801E9D24.service->slot18();
    return 1;
}
