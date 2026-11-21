/* Apply the stored planar motion delta to an actor's position. */
struct PlanarMotionActor {
    char unknown00[0x144];
    float x;
    char unknown148[4];
    float z;
    char unknown150[0x208];
    float deltaX;
    char unknown35C[4];
    float deltaZ;
};

extern "C" float game_vec3_zero[3];

extern "C" void fn_8009237C(PlanarMotionActor* self) {
    float deltaX = self->deltaX;
    float x = self->x;
    float zeroX = game_vec3_zero[0];
    float sumX = deltaX + x;
    float deltaZ = self->deltaZ;
    float z = self->z;
    float zeroZ = game_vec3_zero[2];
    float sumZ = deltaZ + z;
    self->x = zeroX + sumX;
    self->z = zeroZ + sumZ;
}
