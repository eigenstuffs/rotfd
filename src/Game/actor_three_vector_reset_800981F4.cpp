struct ActorResetVector {
    float x, y, z;

    ActorResetVector& operator=(const ActorResetVector& other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }
};

struct ActorResetAgent {
    char unknown00[0x38];
    unsigned long long flags38;
    char unknown40[0x104];
    ActorResetVector velocity144;
    char unknown150[0xC];
    ActorResetVector angularVelocity15C;
    char unknown168[0x1B0];
    char controls318;
    char unknown319[0x3F];
    ActorResetVector movement358;

    void setVelocity(const ActorResetVector& value) { velocity144 = value; }
    void setAngularVelocity(const ActorResetVector& value) { angularVelocity15C = value; }
    void setMovement(const ActorResetVector& value) { movement358 = value; }
};

struct ActorResetAction {
    char unknown00[8];
    ActorResetAgent* agent08;
    ActorResetAgent* target0C;
};

extern "C" {
extern const ActorResetVector game_vec3_zero;
signed char fn_8007D7F4(void*, int);
void fn_800981F4(ActorResetAction*);
}

extern "C" void fn_800981F4(ActorResetAction* self)
{
    self->target0C->flags38 |= 0x20000ULL;
    self->agent08->setVelocity(game_vec3_zero);
    self->agent08->setAngularVelocity(game_vec3_zero);
    self->agent08->setMovement(game_vec3_zero);
    fn_8007D7F4(&self->agent08->controls318, 0);
    fn_8007D7F4(&self->agent08->controls318, 1);
    fn_8007D7F4(&self->agent08->controls318, 2);
}
