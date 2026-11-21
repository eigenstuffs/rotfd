#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

/* Inferred controller layout; original class and field names unknown. */
struct Controller;
struct Action {
    char name[128];
    void (Controller::*callback)(float);
    Action() : callback(0) {}
    ~Action() {}
};
struct ControllerBase {
    unsigned char prefix[0x18];
    float inverse_rate;
    unsigned char reserved_1c[0xB08 - 0x1c];
    unsigned int enabled;
    unsigned int reserved_b0c;
};
struct Controller : ControllerBase {
    virtual void unknown_00();
    virtual void unknown_01();
    virtual void unknown_02();
    virtual void unknown_03();
    virtual void unknown_04();
    virtual void select(unsigned int);
    virtual void disable(unsigned int);
    void set_rate(float);
    void message(float);
    void script(float);
    int count, capacity;
    Action *actions;
};

#endif
