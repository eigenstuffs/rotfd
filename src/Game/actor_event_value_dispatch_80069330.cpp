struct ActorEventPrefix_80069330 {
    char opaque00[4];
};

struct ActorEventOwner_80069330 : ActorEventPrefix_80069330 {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void* eventTarget();
};

extern "C" void fn_802073E8(void*, int, void*, float);

extern "C" signed char fn_80069330(ActorEventOwner_80069330* self,
                                    void* target, unsigned short value)
{
    void* eventTarget = self->eventTarget();
    fn_802073E8(eventTarget, 0xAA, target, (float)value);
    return 0;
}
