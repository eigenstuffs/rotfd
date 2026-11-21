#ifndef GAME_EVENT_STATE_NOTIFY_VIEWS_H
#define GAME_EVENT_STATE_NOTIFY_VIEWS_H

struct StateVector {
    float x, y, z;
};
struct StatePrefix {
    char unknown00[8];
};
struct StateNotifyOwner : StatePrefix {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void notify(const StateVector*,int);
    char unknown0C[0x314];
    int state;
    char unknown324[0xA0];
    StateVector position;
    char unknown3D0[0x18];
    int previous;
};

#endif
