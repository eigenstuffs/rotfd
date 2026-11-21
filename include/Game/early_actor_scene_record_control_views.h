#ifndef GAME_EARLY_ACTOR_SCENE_RECORD_CONTROL_VIEWS_H
#define GAME_EARLY_ACTOR_SCENE_RECORD_CONTROL_VIEWS_H
struct SceneRecordHandle { union { unsigned long value; struct { signed int tag:8; signed int index:24; } bits; }; };
struct SceneRecordColor;
struct SceneRecordResource { char unknown00[0x88]; unsigned char enabled; void setColor(SceneRecordColor,float); };
struct SceneRecordEntry { SceneRecordResource* object; char unknown04[8]; signed char tag; char unknown0D[3]; };
struct SceneRecordManager { int count, capacity; SceneRecordEntry* entries; };
struct SceneRecordMode { char unknown00[0x60]; SceneRecordHandle target; };
struct SceneRecordScene { char unknown00[0x15058]; SceneRecordMode* mode; };
struct SceneRecordSystem { char unknown00[0x2E]; signed char enabled; };
struct SceneRecordContext { char unknown00[0x118]; SceneRecordManager* manager; char unknown11C[8]; SceneRecordScene* scene; char unknown128[0x3C]; SceneRecordSystem* system; };
struct SceneRecordController { char unknown00[8]; int key; };
struct SceneRecordActor { char unknown00[0x24]; SceneRecordHandle handle; char unknown28[8]; unsigned long long flags; char unknown38[0x2E0]; SceneRecordController record; };
struct SceneRecordOwner { char unknown00[8]; SceneRecordActor* actor; void* controller; };
struct SceneRecordMonitor { char unknown00[0x130]; void* first; void* second; };
struct SceneRecordColor { float x,y,z,w; SceneRecordColor(float X,float Y,float Z,float W):x(X),y(Y),z(Z),w(W) {} };
extern "C" {
extern SceneRecordContext lbl_801E9D24;
extern SceneRecordMonitor* lbl_803776B8;
extern const float lbl_80378B84,lbl_80378AF8,lbl_80378B88;
void fn_8006803C(SceneRecordMonitor*,int);
void fn_80068158(SceneRecordMonitor*,int);
void fn_80255CBC(SceneRecordResource*,int,int);
void fn_80257828(void*,int,int,int);
int fn_801F1224(int,int);
void fn_8008D86C(SceneRecordOwner*);
int fn_80092844(SceneRecordActor*);
signed char fn_8007D6A0(SceneRecordController*,int);
void fn_80092DAC(SceneRecordActor*,double);
void fn_800A846C(SceneRecordResource*,SceneRecordColor,float);
}
inline SceneRecordResource* resolveSceneRecord(const SceneRecordHandle& h) {
    SceneRecordEntry* entry = &lbl_801E9D24.manager->entries[h.bits.index];
    if(entry->tag == h.bits.tag) return entry->object;
    return 0;
}
inline void SceneRecordResource::setColor(SceneRecordColor color,float amount) {fn_800A846C(this,color,amount);}
#endif
