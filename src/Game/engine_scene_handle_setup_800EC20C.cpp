/* Original scene/record Handle setup and cleanup; strict retained EH plus strong-owner backup audit.
 * See docs/notes/game-engine-scene-handle-setup.md. */
typedef unsigned long u32;
struct Handle_801F7F10 {u32 word;Handle_801F7F10();~Handle_801F7F10();};
struct Manager;
struct Record {u32 unknown00;Handle_801F7F10 handle04;};
struct Scene {char unknown00[0x1505C];Record*record1505C;void*service15060;};
struct Context {char unknown00[0x118];Manager*manager;char unknown11C[8];Scene*scene;char unknown128[0x164-0x128];void*recordService;};
extern "C" {extern Context lbl_801E9D24;extern u32 lbl_803777C4,lbl_803778C0;void fn_800C2700(void*);void fn_800B6F70(void*,u32,int,const Handle_801F7F10*);void fn_800B6C84(void*,int,u32);void fn_801F86C8(Manager*,const Handle_801F7F10*,short);void fn_801EF610(void*,void*);extern char lbl_801EF5C8[];}
struct Handle_80020478:Handle_801F7F10 {Handle_80020478(const Handle_801F7F10&v){word=v.word;fn_801F86C8(lbl_801E9D24.manager,&v,1);}~Handle_80020478(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Owner {char unknown00[0xC];Record*record0C;};
extern "C" void fn_800EC20C(Owner*self){fn_800C2700(lbl_801E9D24.scene->service15060);{const Handle_801F7F10&original=self->record0C->handle04;Handle_80020478 h(original);fn_800B6F70(lbl_801E9D24.recordService,lbl_803777C4,0,&h);}fn_800B6C84(lbl_801E9D24.recordService,0,lbl_803778C0);}
