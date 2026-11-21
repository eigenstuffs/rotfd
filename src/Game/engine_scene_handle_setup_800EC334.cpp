/* Original scene/record Handle setup and cleanup; strict retained EH plus strong-owner backup audit.
 * See docs/notes/game-engine-scene-handle-setup.md. */
typedef unsigned long u32;
struct Handle_801F7F10 {u32 word;Handle_801F7F10();~Handle_801F7F10();};
struct Manager;
struct Record {u32 unknown00;Handle_801F7F10 handle04;};
struct Scene {char unknown00[0x1505C];Record*record1505C;void*service15060;};
struct State {u32 word;};struct RecordService {char unknown00[0x1C];State*state1C;};
struct Context {char unknown00[0x118];Manager*manager;char unknown11C[8];Scene*scene;char unknown128[0x164-0x128];RecordService*recordService;};
extern "C" {extern Context lbl_801E9D24;extern u32 lbl_803777C4,lbl_803778C0;void fn_800C2700(void*);void fn_800B6F70(void*,u32,int,const Handle_801F7F10*);void fn_800B6C84(void*,int,u32);void fn_801F86C8(Manager*,const Handle_801F7F10*,short);void fn_801EF610(void*,void*);extern char lbl_801EF5C8[];}
struct Handle_80020478:Handle_801F7F10 {Handle_80020478(const Handle_801F7F10&v){word=v.word;fn_801F86C8(lbl_801E9D24.manager,&v,1);}~Handle_80020478(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Owner {char unknown00[0x8];void*field08;Record*record0C;union {unsigned char field10;float value10;};float field14;char unknown18;unsigned char field19;char unknown1A[2];u32 field1C;};

struct Name {u32 value;Name(const char*t);Name(const Name&v){value=v.value;}};
extern "C" {u32 fn_801F948C(void*,const char*);void fn_800B6DA8(void*,u32,int,Handle_80020478);void fn_800C3934(void*,Record*,const Name*,int,int,int,int);void fn_800C2540(void*);void fn_8007D7F4(void*,int);extern char lbl_802AB3F8[],lbl_802AB40C[],lbl_802AB4C0[],lbl_802AB4FC[];extern const float lbl_80379868,lbl_8037986C;}
inline Name::Name(const char*t){value=fn_801F948C(this,t);}
static inline void applyHandle(Owner*self){const Handle_801F7F10&original=self->record0C->handle04;fn_800B6DA8(lbl_801E9D24.recordService,lbl_803777C4,0,Handle_80020478(original));}
extern "C" void fn_800EC334(Owner*self){self->record0C=lbl_801E9D24.scene->record1505C;lbl_803778C0=lbl_801E9D24.recordService->state1C->word;fn_800B6C84(lbl_801E9D24.recordService,0,lbl_803777C4);applyHandle(self);self->field14=lbl_8037986C;self->field19=0;self->field1C=0;self->field10=0;void*service=lbl_801E9D24.scene->service15060;const Name&originalName=Name(lbl_802AB4C0);Name name(originalName);fn_800C3934(service,self->record0C,&name,6,0,0,0);fn_800C2540(service);fn_8007D7F4((char*)self->field08+0x20,0x16);fn_8007D7F4((char*)self->field08+0x20,0x17);}
