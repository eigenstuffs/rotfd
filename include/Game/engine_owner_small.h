#ifndef GAME_ENGINE_OWNER_SMALL_H
#define GAME_ENGINE_OWNER_SMALL_H
typedef struct EngineOwnerSmallVec2 EngineOwnerSmallVec2;
typedef struct EngineOwnerSmallHandle EngineOwnerSmallHandle;
typedef struct EngineOwnerSmallObject EngineOwnerSmallObject;
typedef struct EngineOwnerSmallEntry EngineOwnerSmallEntry;
typedef struct EngineOwnerSmallManager EngineOwnerSmallManager;
typedef struct EngineOwnerSmallContext EngineOwnerSmallContext;
typedef struct EngineOwnerSmallReset EngineOwnerSmallReset;
typedef struct EngineOwnerSmallFlagOwner EngineOwnerSmallFlagOwner;
typedef struct EngineOwnerSmallDispatch EngineOwnerSmallDispatch;
typedef struct EngineOwnerSmallChoice EngineOwnerSmallChoice;
typedef struct EngineOwnerSmallRecord EngineOwnerSmallRecord;
typedef struct EngineOwnerSmallRecordOwner EngineOwnerSmallRecordOwner;
typedef struct EngineOwnerSmallMaskOwner EngineOwnerSmallMaskOwner;
struct EngineOwnerSmallVec2{float x,y;};
struct EngineOwnerSmallHandle{signed int tag:8;signed int index:24;};
struct EngineOwnerSmallObject{char unknown00[0x120];unsigned long flags;};
struct EngineOwnerSmallEntry{EngineOwnerSmallObject* object;int unknown04,unknown08;signed char tag;char unknown0D[3];};
struct EngineOwnerSmallManager{char unknown00[8];EngineOwnerSmallEntry* entries;};
struct EngineOwnerSmallContext{char unknown00[0x118];EngineOwnerSmallManager* manager;};
struct EngineOwnerSmallReset{char unknown00[0x20];unsigned long handle20,handle24;EngineOwnerSmallVec2 position;};
struct EngineOwnerSmallFlagOwner{char unknown00[0x20];EngineOwnerSmallHandle handle;signed char enabled,active;};
struct EngineOwnerSmallDispatch{char unknown00[0x28];short selected;char unknown2A[0x56];char* records;};
struct EngineOwnerSmallChoice{char unknown00[0x58];signed char selected,active;};
struct EngineOwnerSmallRecord{float x,y,z;int unknown0C;unsigned long long flags;float a,b,c;int unknown24;};
struct EngineOwnerSmallRecordOwner{char unknown00[0x74];char* records;};
struct EngineOwnerSmallMaskOwner{char unknown00[0x30];unsigned long long flags;char unknown38[0x150];char* records;};
#ifdef __cplusplus
extern "C" {
#endif
extern struct EngineOwnerSmallContext lbl_801E9D24;
extern struct EngineOwnerSmallVec2 game_vec2_zero;
void slot18__11Activable_ZFv(struct EngineOwnerSmallReset*);
void fn_8021BD28(struct EngineOwnerSmallDispatch*,void*,int,void*);
void fn_8021C248(struct EngineOwnerSmallChoice*);
void fn_8021C030(struct EngineOwnerSmallChoice*);
void fn_8021B860(struct EngineOwnerSmallChoice*);
void fn_8021FC00(struct EngineOwnerSmallMaskOwner*,int);
void fn_8020CE5C(struct EngineOwnerSmallReset*);
void fn_8020ED58(struct EngineOwnerSmallFlagOwner*);
void fn_8020EE10(struct EngineOwnerSmallFlagOwner*);
void fn_8021B800(struct EngineOwnerSmallDispatch*,void*,signed char);
void fn_8021C504(struct EngineOwnerSmallChoice*);
void fn_8021F518(struct EngineOwnerSmallRecordOwner*,const struct EngineOwnerSmallRecord*,int);
void fn_80224C1C(struct EngineOwnerSmallMaskOwner*,int);
#ifdef __cplusplus
}
#endif
static inline struct EngineOwnerSmallObject* engineOwnerSmallResolve(const struct EngineOwnerSmallHandle* h){
 struct EngineOwnerSmallEntry* e=&lbl_801E9D24.manager->entries[h->index];
 return e->tag==h->tag?e->object:0;
}
#endif
