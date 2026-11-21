/* Text buffers returned by the actor and scene-statistics token dispatchers.
 * Each dispatcher clears byte0 and formats token values with sprintf. */
char lbl_802F4154[68];

/* Existing three-float scene vector populated by its startup initializer. */
float lbl_802F4148[3];

char lbl_802F4108[64];

typedef char ActorTokenBufferSize[sizeof(lbl_802F4108) == 64 ? 1 : -1];
typedef char SceneVectorSize[sizeof(lbl_802F4148) == 12 ? 1 : -1];
typedef char SceneTokenBufferSize[sizeof(lbl_802F4154) == 68 ? 1 : -1];
