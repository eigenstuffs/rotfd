#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

struct EngineBase { unsigned char prefix[0x278]; };
/* Unknown virtual declarations preserve the observed notify slot at 0xAC.
 * These are layout placeholders, not reconstructed function bodies. */
struct Engine : EngineBase {
    virtual void unknown_00();
    virtual void unknown_01();
    virtual void unknown_02();
    virtual void unknown_03();
    virtual void unknown_04();
    virtual void unknown_05();
    virtual void unknown_06();
    virtual void unknown_07();
    virtual void unknown_08();
    virtual void unknown_09();
    virtual void unknown_10();
    virtual void unknown_11();
    virtual void unknown_12();
    virtual void unknown_13();
    virtual void unknown_14();
    virtual void unknown_15();
    virtual void unknown_16();
    virtual void unknown_17();
    virtual void unknown_18();
    virtual void unknown_19();
    virtual void unknown_20();
    virtual void unknown_21();
    virtual void unknown_22();
    virtual void unknown_23();
    virtual void unknown_24();
    virtual void unknown_25();
    virtual void unknown_26();
    virtual void unknown_27();
    virtual void unknown_28();
    virtual void unknown_29();
    virtual void unknown_30();
    virtual void unknown_31();
    virtual void unknown_32();
    virtual void unknown_33();
    virtual void unknown_34();
    virtual void unknown_35();
    virtual void unknown_36();
    virtual void unknown_37();
    virtual void unknown_38();
    virtual void unknown_39();
    virtual void unknown_40();
    virtual void notify(int);
    virtual void set_rectangle(int, int, int, int);
};

#endif
