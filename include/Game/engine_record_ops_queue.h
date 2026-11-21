#ifndef GAME_ENGINE_RECORD_OPS_QUEUE_H
#define GAME_ENGINE_RECORD_OPS_QUEUE_H

// Observed queue prefixes; virtual methods and tables retain their original owners.
struct EngineQueueStorage { unsigned int unknown00, identity; };
struct EngineQueue : EngineQueueStorage {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20(int, int);
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C(const unsigned int *, int);
    virtual void slot30();
    virtual void slot34(const unsigned int *, int, int);
    virtual void slot38();
    virtual void slot3C(int, int);
    char unknown0C[8];
    unsigned int handles[8];
    int values[8];
    int count, cursor;
    signed char finished, dirty;
};
struct EngineGroupQueue : EngineQueueStorage {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20(int, int);
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C(const unsigned int *, int);
    virtual void slot30();
    virtual void slot34(const unsigned int *, int, int);
    virtual void slot38();
    virtual void slot3C(int, int);
    char unknown0C[0x54];
    unsigned int handles[4][8];
    int values[4][8];
    int count[4], cursor[4];
    signed char finished[4], dirty[4];
};
typedef char EngineQueuePrefixSize[(sizeof(EngineQueue) == 0x60) ? 1 : -1];
typedef char EngineGroupQueuePrefixSize[(sizeof(EngineGroupQueue) == 0x188) ? 1 : -1];

extern "C" void fn_801F7914(unsigned int *output, const unsigned int *source);

#endif
