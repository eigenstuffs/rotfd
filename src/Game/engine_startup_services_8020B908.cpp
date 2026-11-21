// Main_Z.cpp engine startup (fn_8020B908): creates the engine services kept in
// the global context lbl_801E9D24 (released again by fn_8020B078), runs the
// Zouna/Game init steps and registers the global console commands.
//
// The strings stay external: the Main_Z.cpp string pool starts at
// registry_No_Comment (0x802ADD20; "No Comment" is owned by type_registry.cpp,
// the rest by the native readable pools) and is viewed here as one const pool
// struct whose base the original kept in r31. The short command names are
// .sdata2 strings owned by frame_lifecycle_scalar_constants.c.
//
// The original referenced each pooled literal separately (no CSE of
// base+offset across the allocations), which is reproduced with
// opt_common_subs off; opt_propagation off keeps the context pointer in r30.
// The offset-0 help text is (member pointer to the +0xC string) - 0xC, which
// keeps the original `addi r6,r31,0x0`. The vtable stored by the inlined
// ParticlesManager constructor (lbl_802EAFE0) is unnamed and stored directly.
typedef unsigned long Word;

struct Pool {
    char noComment[0xC];        // 0x000 "No Comment"
    char setDBPath[0xC];        // 0x00C
    char setDFPath[0xC];        // 0x018
    char loadObjectLib[0x10];   // 0x024
    char removeObjectLib[0x10]; // 0x034
    char checkHandles[0x10];    // 0x044
    char loadMaterialLib[0x10]; // 0x054
    char initRandomSeed[0x10];  // 0x064
    char setBFPath[0xC];        // 0x074
    char targetSource[0x14];    // 0x080 " [Target] [Source]"
    char enableBF[0xC];         // 0x094
    char readWrite[0x10];       // 0x0A0 " [Read/Write]"
    char unknown0B0[0x304 - 0xB0];
    char anonymousNew[0x10];    // 0x304 "Anonymous New"
    char unknown314[0x608 - 0x314];
    char worldHeader[0xC];      // 0x608 "World_Z.h"
    char targetInit[0xC];       // 0x614 "Target Init"
    char mainSource[0xC];       // 0x620 "Main_Z.cpp"
    char particlesManager[0x14];// 0x62C "ParticlesManager"
    char zounaInit[0xC];        // 0x640 "Zouna Init"
    char gameInit[0xC];         // 0x64C "Game Init"
    char registerOk[0x1C];      // 0x658 "RegisterGlobalCommands ok"
    char rendererInit[0x10];    // 0x674 "Renderer Init"
    char rendererDone[0x14];    // 0x684 "Renderer Init Done"
    char programOk[0x10];       // 0x698 "Program Init ok"
};

struct Startup124Prefix {
    char unknown00[0x30];
};
struct Startup124 : Startup124Prefix {
    virtual void slot08();
    virtual void slot0C();
};

struct Globals {
    char unknown00[0x110];
    void* log;
    void* unknown114;
    void* manager118;
    void* service11C;
    void* service120;
    Startup124* startup124;
    void* pool128;
    void* pool12C;
    void* pool130;
    void* cache134;
    void* owners138;
    void* group13C;
    void* unknown140;
    void* owner144;
    void* service148;
    void* service14C;
    void* service150;
    char unknown154[0x16C - 0x154];
    void* particles16C;
};

extern "C" {
extern Globals lbl_801E9D24;
extern char lbl_801EF5C8[];
extern const Pool registry_No_Comment;
extern const char lbl_8037A988[7], lbl_8037A990[6], lbl_8037A998[5], lbl_8037A9A0[6];
extern char lbl_802EAFE0[];
void* fn_801EFA1C(void*, unsigned long, const char*, const char*, int, int);
void fn_801EC5DC(const char*);
void fn_801F94DC();
void fn_80208CD4();
void fn_801EA734();
void* fn_801B5C20(void*);
void* fn_8026BE78(void*);
void* fn_8020C0C8(void*);
void* fn_8020BF78(void*);
void* __ct__23Vector3Storage_8020BE78Fv(void*);
void* __ct__13MatrixCache_ZFv(void*);
void* __ct__18OwnerList_80213824Fv(void*);
void* __ct__14Group_801FFC94Fv(void*);
void* __ct__17Registry_801F50E8Fv(void*);
void* fn_801B5D4C(void*);
void* __ct__26SparseActionOwner_80263DDCFv(void*);
void* __ct__21SlotResource_802EA810Fv(void*);
void* fn_8023AD80(void*);
void* fn_8020C744(void*, const char*);
void fn_8007EE70();
void fn_801FAC64(void*, const char*, void (*)(), const char*);
void fn_801FAE58();
void fn_801FB078();
void fn_801FB028();
void fn_801FAFE8();
void fn_802076DC();
void fn_8020766C();
void fn_802623C4();
void fn_80262210();
void fn_801B4BF4();
void fn_80262428();
void fn_801F1184();
void fn_802075AC();
void fn_802074F4();
void fn_80206524();
void fn_801FBDE4();
void fn_8025FCFC();
void fn_8007F028();
void fn_801FA014(void*, const char*, ...);
void fn_801E1658(void*, int);
}

inline const char* setDBPathName(const Pool* pool) {
    const char (Pool::*m)[0xC] = &Pool::setDBPath;
    return pool->*m;
}
inline const char* noCommentText(const Pool* pool) {
    return setDBPathName(pool) - sizeof(pool->noComment);
}
inline void* alloc(const Pool* pool, unsigned long size, int line) {
    return fn_801EFA1C(lbl_801EF5C8, size, pool->anonymousNew, pool->mainSource, line, 4);
}

// The original loaded the logger and the handler before the help text; the
// two locals keep that evaluation order (with propagation off).
inline void registerCommand(Globals* context, const char* name, void (*handler)(),
                            const Pool* pool) {
    void* log = context->log;
    void (*command)() = handler;
    fn_801FAC64(log, name, command, noCommentText(pool));
}

struct ParticlesManager {
    void* table;
    char unknown04[0x30];
};

#pragma opt_common_subs off
#pragma opt_propagation off
extern "C" void fn_8020B908() {
    const Pool* const pool = &registry_No_Comment;
    void* object;
    fn_801EC5DC(pool->targetInit);
    fn_801F94DC();
    Globals* g = &lbl_801E9D24;
    g->startup124 = 0;
    object = alloc(pool, 0xF0, 381);
    if (object) object = fn_801B5C20(object);
    lbl_801E9D24.manager118 = object;
    fn_80208CD4();
    fn_801EA734();
    object = alloc(pool, 0x28, 392);
    if (object) object = fn_8026BE78(object);
    lbl_801E9D24.service11C = object;
    object = alloc(pool, 0x18, 393);
    if (object) object = fn_8020C0C8(object);
    lbl_801E9D24.pool128 = object;
    object = alloc(pool, 0x18, 394);
    if (object) object = fn_8020BF78(object);
    lbl_801E9D24.pool12C = object;
    object = alloc(pool, 0x14, 395);
    if (object) object = __ct__23Vector3Storage_8020BE78Fv(object);
    lbl_801E9D24.pool130 = object;
    object = alloc(pool, 0x20, 396);
    if (object) object = __ct__13MatrixCache_ZFv(object);
    lbl_801E9D24.cache134 = object;
    object = alloc(pool, 0xC, 397);
    if (object) object = __ct__18OwnerList_80213824Fv(object);
    lbl_801E9D24.owners138 = object;
    object = alloc(pool, 0x24, 398);
    if (object) object = __ct__14Group_801FFC94Fv(object);
    lbl_801E9D24.group13C = object;
    object = alloc(pool, 0xF4, 399);
    if (object) object = __ct__17Registry_801F50E8Fv(object);
    lbl_801E9D24.owner144 = object;
    object = alloc(pool, 1, 400);
    if (object) object = fn_801B5D4C(object);
    lbl_801E9D24.service148 = object;
    object = alloc(pool, 0x290, 401);
    if (object) object = __ct__26SparseActionOwner_80263DDCFv(object);
    lbl_801E9D24.service14C = object;
    object = alloc(pool, 0x44, 402);
    if (object) object = __ct__21SlotResource_802EA810Fv(object);
    lbl_801E9D24.service150 = object;
    object = alloc(pool, 0x14, 405);
    if (object) object = fn_8023AD80(object);
    lbl_801E9D24.service120 = object;
    ParticlesManager* particles = (ParticlesManager*)alloc(pool, 0x34, 406);
    if (particles) {
        fn_8020C744(particles, pool->particlesManager);
        particles->table = lbl_802EAFE0;
    }
    lbl_801E9D24.particles16C = particles;
    fn_801EC5DC(pool->zounaInit);
    fn_8007EE70();
    fn_801EC5DC(pool->gameInit);
    g->startup124->slot0C();
    Globals* context = &lbl_801E9D24;
    fn_801FAC64(context->log, lbl_8037A988, fn_801FAE58, noCommentText(pool));
    registerCommand(context, lbl_8037A990, fn_801FB078, pool);
    registerCommand(context, lbl_8037A998, fn_801FB028, pool);
    registerCommand(context, lbl_8037A9A0, fn_801FAFE8, pool);
    registerCommand(context, pool->setDBPath, fn_802076DC, pool);
    registerCommand(context, pool->setDFPath, fn_8020766C, pool);
    registerCommand(context, pool->loadObjectLib, fn_802623C4, pool);
    registerCommand(context, pool->removeObjectLib, fn_80262210, pool);
    registerCommand(context, pool->checkHandles, fn_801B4BF4, pool);
    registerCommand(context, pool->loadMaterialLib, fn_80262428, pool);
    registerCommand(context, pool->initRandomSeed, fn_801F1184, pool);
    fn_801FAC64(context->log, pool->setBFPath, fn_802075AC, pool->targetSource);
    fn_801FAC64(context->log, pool->enableBF, fn_802074F4, pool->readWrite);
    fn_80206524();
    fn_801FBDE4();
    fn_8025FCFC();
    fn_8007F028();
    fn_801FA014(context->log, pool->registerOk);
    fn_801EC5DC(pool->rendererInit);
    fn_801EC5DC(pool->rendererDone);
    fn_801E1658(lbl_801E9D24.unknown114, 1);
    fn_801FA014(context->log, pool->programOk);
}
#pragma opt_propagation reset
#pragma opt_common_subs reset
