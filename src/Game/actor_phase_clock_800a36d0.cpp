// Advance the inherited phase controller, then accumulate its local clock.
struct ActorPhaseClock_800A36D0 {
    unsigned char prefix[0x394];
    float elapsed;
};
extern "C" void fn_8009DF78(ActorPhaseClock_800A36D0*, float);
extern "C" void fn_800A36D0(ActorPhaseClock_800A36D0* self, float delta) {
    fn_8009DF78(self, delta);
    self->elapsed = delta + self->elapsed;
}
