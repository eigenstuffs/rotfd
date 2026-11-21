/* Object_80260C7C construction: member setup and agent type registration. */
typedef unsigned long Word;

struct HandleManager;
struct Registry;
struct Globals {
    char unknown00[0x118];
    HandleManager* manager;
};
struct Pool {
    char definitions[0x14];
    char abcAgent[0x88];          /* +0x14 */
    char streamAgent[0x10];       /* +0x9C */
    char animatedMsgAgent[0x14];  /* +0xAC */
    char animatedAgent[0x10];     /* +0xC0 */
    char lodDynAgent[0x10];       /* +0xD0 */
    char skinAgent[0xC];          /* +0xE0 */
    char movingAgent[0x10];       /* +0xEC */
    char throwable[0xC];          /* +0xFC */
    char lodAgent[0xC];           /* +0x108 */
    char breakable[0xC];          /* +0x114 */
    char cameraAgent[0x10];       /* +0x120 */
    char rtcAgent[0xC];           /* +0x130 */
    char volumeAgent[0x10];       /* +0x13C */
    char particlesAgent[0x14];    /* +0x14C */
};
typedef void* (*Factory)();

extern "C" {
extern Globals lbl_801E9D24;
extern const Pool lbl_802AECC8;
extern const char lbl_8037B598[8];
extern const float lbl_8037B574;
extern char lbl_802ED0C0[];
void fn_801F86C8(HandleManager*, const void*, int);
void fn_801B5664(HandleManager*, const char*, const char*, Factory);
void fn_80208830(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*, int), unsigned long, unsigned long);
void fn_802617F8(void*);
void fn_80260F08(void*, int);
void fn_8025F92C(void*);
void fn_8025F6F4(void*, int);
void fn_80285DB4(void*);
void fn_80256448();
void fn_802548B8();
void fn_8025E5FC();
void fn_80258948();
void fn_802599D0();
void fn_8025B158();
void fn_8025A930();
void fn_8025BCC4();
void fn_802598F4();
void fn_8025959C();
void fn_8025CC04();
void fn_8025DE20();
void fn_8025E31C();
void fn_802558B8();
void* fn_802617A0();
void* fn_80261708();
void* fn_802616A0();
void* fn_80261648();
void* fn_802615F0();
void* fn_80261598();
void* fn_80261540();
void* fn_802614E8();
void* fn_80261490();
void* fn_80261438();
void* fn_802613E0();
void* fn_80261388();
void* fn_80261320();
void* fn_802612C8();
}

struct Handle_801F7F10 {
    Word word;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct SceneHandle : Handle_801F7F10 {
    SceneHandle() { word = 0; }
    ~SceneHandle() {}
};
struct SceneHandleLayer : SceneHandle {
    SceneHandleLayer() { word = 0; }
    ~SceneHandleLayer() {}
    void operator=(const SceneHandleLayer& h) {
        fn_801F86C8(lbl_801E9D24.manager, this, -1);
        word = h.word;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
    }
};

extern "C" void __ct__15Handle_801F7F10Fv(void*);

struct Object_80260C7C {
    char unknown00[9];
    unsigned char field09;
    unsigned char field0A;
    unsigned char field0B;
    float field0C;
    float field10;
    Word field14;
    SceneHandleLayer handle18;
    void* head;
    char hash20[0x10];
    void* vtable;
    int count34, capacity38;
    void* data3C;
    Word unknown40;
    char records44[0xA000];
    Word unknownA044;
    char snapshotsA048[0xB000];
    Word unknown15048;
};

extern "C" Object_80260C7C* fn_80260FF8(Object_80260C7C* self) {
    const Pool* const pool = &lbl_802AECC8;
    self->vtable = lbl_802ED0C0;
    SceneHandleLayer* const handle = &self->handle18;
    __ct__15Handle_801F7F10Fv(handle);
    handle->word = 0;
    handle->word = 0;
    fn_80208830(self->hash20, 0x40);
    self->count34 = 0;
    self->capacity38 = 0;
    self->data3C = 0;
    __construct_array(self->records44, fn_802617F8, fn_80260F08, 0x14, 0x800);
    __construct_array(self->snapshotsA048, fn_8025F92C, fn_8025F6F4, 0x2C, 0x400);
    self->field0A = 0;
    self->field0B = 0;
    self->field09 = 1;
    self->head = 0;
    self->field0C = lbl_8037B574;
    self->field10 = lbl_8037B574;
    self->field14 = 0;
    self->handle18 = SceneHandleLayer();
    fn_80256448();
    fn_801B5664(lbl_801E9D24.manager, lbl_8037B598, pool->abcAgent, fn_802617A0);
    fn_802548B8();
    fn_801B5664(lbl_801E9D24.manager, pool->streamAgent, pool->abcAgent, fn_80261708);
    fn_8025E5FC();
    fn_801B5664(lbl_801E9D24.manager, pool->animatedMsgAgent, lbl_8037B598, fn_802616A0);
    fn_80258948();
    fn_801B5664(lbl_801E9D24.manager, pool->animatedAgent, pool->animatedMsgAgent, fn_80261648);
    fn_802599D0();
    fn_801B5664(lbl_801E9D24.manager, pool->lodDynAgent, pool->animatedAgent, fn_802615F0);
    fn_8025B158();
    fn_801B5664(lbl_801E9D24.manager, pool->skinAgent, pool->animatedAgent, fn_80261598);
    fn_8025A930();
    fn_801B5664(lbl_801E9D24.manager, pool->movingAgent, pool->animatedAgent, fn_80261540);
    fn_8025BCC4();
    fn_801B5664(lbl_801E9D24.manager, pool->throwable, pool->movingAgent, fn_802614E8);
    fn_802598F4();
    fn_801B5664(lbl_801E9D24.manager, pool->lodAgent, pool->throwable, fn_80261490);
    fn_8025959C();
    fn_801B5664(lbl_801E9D24.manager, pool->breakable, pool->throwable, fn_80261438);
    fn_8025CC04();
    fn_801B5664(lbl_801E9D24.manager, pool->cameraAgent, lbl_8037B598, fn_802613E0);
    fn_8025DE20();
    fn_801B5664(lbl_801E9D24.manager, pool->rtcAgent, pool->animatedMsgAgent, fn_80261388);
    fn_8025E31C();
    fn_801B5664(lbl_801E9D24.manager, pool->volumeAgent, lbl_8037B598, fn_80261320);
    fn_802558B8();
    fn_801B5664(lbl_801E9D24.manager, pool->particlesAgent, lbl_8037B598, fn_802612C8);
    fn_80285DB4(self);
    return self;
}
