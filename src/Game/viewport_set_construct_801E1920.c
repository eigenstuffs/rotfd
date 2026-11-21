/* Viewport set setup (Viewport_Z.cpp): installs the interface table at +0x278,
 * constructs the seven 0x4C-byte viewports and the two zeroed handles at
 * +0x220/+0x224, registers the SetSplitType / SetWorldToSplit / SetLodRender /
 * FitOnObject / DisplayImage console commands and seeds the split state.
 * fn_801E1870 is the matching teardown.  The command strings stay external:
 * lbl_802ACD70.. is owned by engine_game_strings_802ACD08.cpp. */
typedef unsigned long Word;
typedef int (*Command)(void);
struct Handle { Word word; };
struct Viewport { char data[0x4C]; };
struct Viewports {
    struct Viewport records[7];
    signed char count;
    signed char unknown215;
    char unknown216[10];
    struct Handle handle220, handle224;
    int lod;
    int unknown22C;
    signed char unknown230;
    char unknown231[3];
    Word flags;
    float unknown238[3];
    float unknown244;
    char unknown248[8];
    float unknown250[2];
    float unknown258[2];
    float unknown260[2];
    char unknown268[0x10];
    const void *table;
};
struct Console;
struct Context { char unknown00[0x110]; struct Console *console; };
struct Pool {
    char invalidParameter[0x14]; char splitMissing[0x1C]; char parameter1[0x18];
    char invalidLod[0x14]; char parameter2[0x18]; char worldMissing[0x1C];
    char parameterInvalid[0x14]; char setSplitType[0x10]; char noComment[0xC];
    char setWorldToSplit[0x10]; char setLodRender[0x10]; char fitOnObject[0xC];
    char fitUsage[0x18]; char displayImage[0x10]; char displayUsage[0x10];
};
extern struct Context lbl_801E9D24;
extern const struct Pool lbl_802ACD70;
extern const char lbl_802EA718[];
extern const float lbl_8037A588, lbl_8037A58C, lbl_8037A594;
extern void __ct__17Viewport_801E300CFv(void *);
extern void __dt__17Viewport_801E300CFv(void *, int);
extern void __ct__15Handle_801F7F10Fv(void *);
extern void __construct_array(void *, void (*)(void *), void (*)(void *, int), unsigned long, unsigned long);
extern void fn_801FAC64(struct Console *, const char *, Command, const char *);
extern int fn_801E12E8(void);
extern int fn_801E1108(void);
extern int fn_801E1038(void);
extern int fn_801E0F48(void);
extern int fn_801FB37C(void);
struct Viewports *fn_801E1920(struct Viewports *self) {
    const struct Pool *const pool = &lbl_802ACD70;
    self->table = lbl_802EA718;
    __construct_array(self, __ct__17Viewport_801E300CFv, __dt__17Viewport_801E300CFv, 0x4C, 7);
    { struct Handle *h = &self->handle220; __ct__15Handle_801F7F10Fv(h); h->word = 0; h->word = 0; }
    { struct Handle *h = &self->handle224; __ct__15Handle_801F7F10Fv(h); h->word = 0; h->word = 0; }
    fn_801FAC64(lbl_801E9D24.console, pool->setSplitType, fn_801E12E8, pool->noComment);
    fn_801FAC64(lbl_801E9D24.console, pool->setWorldToSplit, fn_801E1108, pool->noComment);
    fn_801FAC64(lbl_801E9D24.console, pool->setLodRender, fn_801E1038, pool->noComment);
    fn_801FAC64(lbl_801E9D24.console, pool->fitOnObject, fn_801E0F48, pool->fitUsage);
    fn_801FAC64(lbl_801E9D24.console, pool->displayImage, fn_801FB37C, pool->displayUsage);
    self->unknown215 = 0;
    self->flags = 0;
    self->unknown230 = 0;
    self->count = 0;
    self->lod = 3;
    self->unknown22C = 1;
    self->flags |= 2;
    self->unknown238[0] = lbl_8037A594;
    self->unknown238[1] = lbl_8037A594;
    self->unknown238[2] = lbl_8037A594;
    self->unknown244 = lbl_8037A58C;
    self->unknown250[0] = lbl_8037A588;
    self->unknown250[1] = lbl_8037A588;
    self->unknown258[0] = lbl_8037A58C;
    self->unknown258[1] = lbl_8037A58C;
    self->unknown260[0] = lbl_8037A588;
    self->unknown260[1] = lbl_8037A588;
    return self;
}
