// Advance the inherited phase controller, then accumulate its local clock.
struct ActorPhaseClock_800A36D0 {
    unsigned char prefix[0x394];
    float elapsed;
};
extern "C" void slot38__11CScriptMoveFf(ActorPhaseClock_800A36D0*, float);
extern "C" void slot38__11CSimpleMoveFf(ActorPhaseClock_800A36D0* self, float delta) {
    slot38__11CScriptMoveFf(self, delta);
    self->elapsed = delta + self->elapsed;
}
