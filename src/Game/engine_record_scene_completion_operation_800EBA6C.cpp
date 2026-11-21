/* Original record scene operation with completion branches (fn_800E8AEC / fn_800E8BD4); adapted from
 * engine_record_scene_variant_800EBDE0.cpp. The three strings are addressed from the shared pool base
 * lbl_802AB3B8 (+0xAC/+0xC0/+0xD4) through a local pool pointer. The scene service is read before the saved
 * state word is stored; the named reference to the early state pointer keeps its load ahead of the service
 * read (it blocks forward propagation), which fixes the r6/r7 allocation. */
/* Original scene/record Handle setup and cleanup; strict retained EH plus strong-owner backup audit.
 * See docs/notes/game-engine-scene-handle-setup.md. */
typedef unsigned long u32;
struct Handle_801F7F10 {union{u32 word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Entry{char*object;u32 key,opaque08;signed char generation;char opaque0D[3];};struct Manager{char opaque00[8];Entry*entries;};
struct Record {u32 unknown00;Handle_801F7F10 handle04;char opaque08[0xB300-8];signed char flagsB300[9];};
struct Scene {char unknown00[0x1505C];Record*record1505C;void*service15060;};
struct State {u32 word;};struct RecordService {char unknown00[0x1C];State*state1C;};
struct Context {char unknown00[0x110];void*logger110;char unknown114[4];Manager*manager;char unknown11C[8];Scene*scene;char unknown128[0x13C-0x128];RecordService*primaryService;char unknown140[0x164-0x140];RecordService*recordService;};
extern "C" {extern Context lbl_801E9D24;extern u32 lbl_803777C4,lbl_803778C0;void fn_800C2700(void*);void fn_800B6F70(void*,u32,int,const Handle_801F7F10*);void fn_800B6C84(void*,int,u32);void fn_801F86C8(Manager*,const Handle_801F7F10*,short);void fn_801EF610(void*,void*);extern char lbl_801EF5C8[];}
struct Handle_80020478:Handle_801F7F10 {Handle_80020478(const Handle_801F7F10&v){word=v.word;fn_801F86C8(lbl_801E9D24.manager,&v,1);}~Handle_80020478(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Owner {char unknown00[0x8];void*field08;Record*record0C;union {unsigned char field10;float value10;};union{float field14;u32 word14;signed char flag14;};char unknown18;unsigned char field19;char unknown1A[2];int field1C;};

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

extern "C" {void fn_801FA014(void*,const char*,...);int fn_800E8AA0(Record*);void fn_800E89D0(Record*);int fn_800E8AEC(Record*);signed char fn_800E8CA4(Record*);signed char fn_800E8BD4(Record*);signed char fn_800E8E54(Record*);signed char fn_800E8DE8(Record*);void fn_800E8D58(Record*);void fn_800E86E4(Record*);void fn_800E88EC(Record*);extern const char lbl_802AB3B8[],lbl_802AB41C[],lbl_802AB428[],lbl_802AB44C[],lbl_802AB584[],lbl_802AB5B0[],lbl_802AB5C8[],lbl_802AB4A0[],lbl_802AB4E8[];}
inline void playOperation(Owner*self,void*service,const char*text){Name name(text);Name copy(name);fn_800C3934(service,self->record0C,&copy,3,0,0,0);fn_800C2540(service);}
extern "C" void fn_800EBA6C(Owner*self){
    const char*pool=lbl_802AB3B8;
    self->record0C=lbl_801E9D24.scene->record1505C;
    State*state=lbl_801E9D24.recordService->state1C;
    State*const&current=state;
    void*service=lbl_801E9D24.scene->service15060;
    lbl_803778C0=current->word;
    fn_800B6C84(lbl_801E9D24.recordService,0,lbl_803777C4);
    {
        const Handle_801F7F10&original=self->record0C->handle04;
        fn_800B6DA8(lbl_801E9D24.recordService,lbl_803777C4,0,Handle_80020478(original));
    }
    if(fn_800E8AEC(self->record0C)==0){
        fn_800E8CA4(self->record0C);
        if(fn_800E8BD4(self->record0C)){
            fn_800E8D58(self->record0C);
            fn_801FA014(lbl_801E9D24.logger110,pool+0xAC);
        }else{
            playOperation(self,service,pool+0xC0);
        }
    }else{
        playOperation(self,service,pool+0xD4);
    }
}
