typedef unsigned long u32;
struct Handle_801F7F10 {union{u32 word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Entry{char*object;u32 key,opaque08;signed char generation;char opaque0D[3];};struct Manager{char opaque00[8];Entry*entries;};
struct Record {u32 unknown00;Handle_801F7F10 handle04;char opaque08[0xB300-8];signed char flagsB300[9];};
struct Scene {char unknown00[0x1505C];Record*record1505C;void*service15060;};
struct State {u32 word;};struct RecordService {char unknown00[0x1C];State*state1C;};
struct Context {char unknown00[0x118];Manager*manager;char unknown11C[8];Scene*scene;char unknown128[0x13C-0x128];RecordService*primaryService;char unknown140[0x164-0x140];RecordService*recordService;};
extern "C" {extern Context lbl_801E9D24;extern u32 lbl_803777C4,lbl_803778C0;void fn_800C2700(void*);void fn_800B6F70(void*,u32,int,const Handle_801F7F10*);void fn_800B6C84(void*,int,u32);void fn_801F86C8(Manager*,const Handle_801F7F10*,short);void fn_801EF610(void*,void*);extern char lbl_801EF5C8[];}
struct Handle_80020478:Handle_801F7F10 {Handle_80020478(const Handle_801F7F10&v){word=v.word;fn_801F86C8(lbl_801E9D24.manager,&v,1);}~Handle_80020478(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Owner {char unknown00[0x8];void*field08;Record*record0C;union {unsigned char field10;float value10;};float field14;char unknown18;unsigned char field19;char unknown1A[2];u32 field1C;};

struct Name {u32 value;Name(const char*t);Name(const Name&v){value=v.value;}};
extern "C" {u32 fn_801F948C(void*,const char*);void fn_800B6DA8(void*,u32,int,Handle_80020478);void fn_800C3934(void*,Record*,const Name*,int,int,int,int);void fn_800C2540(void*);void fn_8007D7F4(void*,int);extern char lbl_802AB3F8[],lbl_802AB40C[],lbl_802AB4C0[],lbl_802AB4FC[];extern const float lbl_80379868,lbl_8037986C;}
inline Name::Name(const char*t){value=fn_801F948C(this,t);}
static inline void applyHandle(Owner*self){const Handle_801F7F10&original=self->record0C->handle04;fn_800B6DA8(lbl_801E9D24.recordService,lbl_803777C4,0,Handle_80020478(original));}

extern "C"{void*fn_801F7EB8(const Handle_801F7F10*);extern const float lbl_80379860,lbl_80379864;}
struct HandleBits{signed int tag:8,index:24;};
inline char*resolve(const Handle_801F7F10&h){int index=h.bits.index;signed char tag=h.bits.tag;Entry*entry=lbl_801E9D24.manager->entries+index;if(entry->generation==tag)return entry->object;return 0;}
extern "C" void fn_8007D6A0(void*,int);
inline char*resolveAlternate(const Handle_801F7F10&h){struct ByteManager{char opaque00[8];char*entries;};int index=h.bits.index;signed char tag=h.bits.tag;Entry*entry=(Entry*)(((ByteManager*)lbl_801E9D24.manager)->entries+index*16);if(entry->generation==tag)return entry->object;return 0;}
inline void notifyRelated(int message){char*object=resolve(*(Handle_801F7F10*)lbl_801E9D24.primaryService->state1C);char*child=resolveAlternate(**(Handle_801F7F10**)(object+0xB0));const Handle_801F7F10*handle=(const Handle_801F7F10*)(child+0x70);char*target;if(fn_801F7EB8(handle))target=resolve(*handle);else target=0;fn_8007D6A0(target+0x318,message);}
extern "C" void fn_8007D6A0(void*,int);

extern "C" char lbl_802AB40C[];

extern "C" char lbl_802AB440[];

extern "C" char lbl_802AB514[];

extern "C" char lbl_802AB530[];

extern "C" char lbl_802AB554[];

extern "C" char lbl_802AB56C[];

extern "C" char lbl_802AB478[];

extern "C" char lbl_802AB5E0[];

extern "C" char lbl_802AB5F8[];

extern "C" {void fn_800E88EC(Record*);void fn_800E8744(Record*,int);}
extern "C" void fn_800EE944(Owner*self){if(self->record0C->flagsB300[0])notifyRelated(0);fn_800C2700(lbl_801E9D24.scene->service15060);const Handle_801F7F10&original=self->record0C->handle04;fn_800B6F70(lbl_801E9D24.recordService,lbl_803777C4,0,&Handle_80020478(original));fn_800B6C84(lbl_801E9D24.recordService,0,lbl_803778C0);}
