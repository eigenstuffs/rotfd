/* Vertical motion step for an early actor: combine the stored vertical
 * velocity with the accumulated acceleration, cap the upward speed, apply
 * the scaled gravity for this frame, clamp to the terminal speed and move the
 * actor's position. Field layout follows the actor views used by the callers
 * (see include/Game/early_actor_completion_control_views.h).
 *
 * Matching notes: the working value lives in a Vec3 local (a plain float
 * local gets an extra fmr from copy propagation), the position is updated
 * through a Vec3 copy (gives the f1 load/add), and the gravity step is a
 * separate local so -fp_contract on does not fuse it into fmadds. Vec3 needs
 * a user-declared constructor so the struct copy is member-wise. */

struct Vec3 {
    float x, y, z;
    Vec3() {}
};

struct Actor {
    char unknown00[0x30];
    unsigned long long flags;
    char unknown38[0x10C];
    Vec3 position;
    char unknown150[0xC];
    Vec3 velocity;
    char unknown168[0x1E8];
    float speed;
    float gravityScale;
    Vec3 acceleration;
    char unknown364[0x14];
    float terminalSpeed;
    char unknown37C[0x68];
    float maxRiseSpeed;
};

extern "C" double __fabs(double);

extern "C" void fn_80092DAC(Actor* self, float delta) {
    if (!(self->flags & 0x8000000000ULL)) {
        Vec3 motion;
        motion.y = self->velocity.y + self->acceleration.y;
        if (motion.y > self->maxRiseSpeed) motion.y = self->maxRiseSpeed;
        float gravity = self->speed * self->gravityScale;
        float step = gravity * delta;
        motion.y += step;
        if ((float)__fabs(motion.y) > self->terminalSpeed) motion.y = -self->terminalSpeed;
        Vec3 position = self->position;
        position.y += motion.y;
        self->position = position;
    }
}
