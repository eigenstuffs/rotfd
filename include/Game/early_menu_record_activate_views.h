#ifndef GAME_EARLY_MENU_RECORD_ACTIVATE_VIEWS_H
#define GAME_EARLY_MENU_RECORD_ACTIVATE_VIEWS_H
struct ActivateHandle{union{unsigned long word;struct{signed int tag:8,index:24;}bits;};};
struct ActivatePrefix{char unknown00[8];};
struct ActivateRecord{int word;};
struct ActivateObject:ActivatePrefix{virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();virtual void slot8();virtual void slot9();virtual void slot10();virtual void slot11();virtual void slot12();virtual void slot13();virtual void slot14();virtual void destroy(int);virtual void slot16();virtual void slot17();virtual void slot18();virtual void slot19();virtual void slot20();virtual void slot21();virtual void slot22();virtual void slot23();virtual void slot24();virtual void slot25();virtual void slot26();virtual void slot27();virtual void slot28();virtual void slot29();virtual void slot30();virtual void slot31();virtual void slot32();virtual void slot33();virtual void slot34();virtual void slot35();virtual void slot36();virtual const ActivateHandle&getHandle(int);char unknown0C[0x14];ActivateHandle handle20;char unknown24[0x4C];ActivateHandle handle70;char unknown74[0x3C];ActivateHandle*related;char unknownB4[0x264];ActivateRecord record;void notify(int);};
struct ActivateEntry{ActivateObject*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct ActivateManager{int count,capacity;ActivateEntry*entries;};
struct ActivateVector{float x,y,z;};
struct ActivateMenuRecord{int key,next;char unknown08[0xE];signed char flag;char unknown17[0x19];float current,saved;char unknown38[0x20];};
struct ActivateOwner{char unknown00[0x14];int count,capacity;ActivateMenuRecord*records;int selected,active;char unknown28[0x124];float time;ActivateMenuRecord*search(int key){for(int i=0;i<count;++i)if(records[i].key==key)return &records[i];return 0;}ActivateMenuRecord*find(int key){if(key>-1)return search(key);return 0;}};
struct ActivateSlot{int key;};struct ActivateService{char unknown00[0x1C];ActivateSlot*current;const int&get(int index){return current[index].key;}};
struct ActivateScene{char unknown00[0x15058];struct ActivateSceneOwner{char unknown00[0x60];ActivateHandle handle;}*owner;};
struct ActivateRelated{char unknown00[0x1C];ActivateHandle*handle;};
struct ActivateDevicePrefix{char unknown00[0x7C];};struct ActivateDevice:ActivateDevicePrefix{virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();virtual void slot8();virtual void slot9();virtual void slot10();virtual void slot11();virtual void slot12();virtual void slot13();virtual void slot14();virtual void slot15();virtual void slot16();virtual void set(void*);};
struct ActivateContext{char unknown00[0x110];void*logger;char unknown114[4];ActivateManager*manager;char unknown11C[8];ActivateScene*scene;char unknown128[0x14];ActivateRelated*related;char unknown140[0x18];ActivateDevice*device;char unknown15C[8];ActivateService*service;};
struct ActivateState{char unknown00[0xD0];int mode;char unknownD4[0x138];ActivateVector vector;char unknown218[0x10];int status;};
extern "C"{extern ActivateContext lbl_801E9D24;extern float lbl_803790B8;extern const char lbl_8029EFF8[];extern int lbl_803777CC,lbl_803777B0;extern ActivateVector game_vec3_zero;void fn_801FA014(void*,const char*,...);void fn_800AD54C(ActivateOwner*);void fn_800AC2B4(ActivateOwner*,int);void fn_800A64E0(ActivateObject*,int);void fn_800B6C84(ActivateService*,int,int);ActivateObject*fn_801F7EB8(const ActivateHandle*);signed char fn_8007D604(ActivateRecord*,int);int fn_80092844(ActivateObject*);void fn_8007D6A0(ActivateRecord*,int);void fn_8002C130();void fn_80057100(ActivateScene::ActivateSceneOwner*,int);ActivateState*fn_8007D074();void fn_8007705C(ActivateState*);}
inline ActivateObject*resolveActivate(const ActivateHandle&h){int index=h.bits.index;ActivateManager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
inline ActivateObject*optionalActivate(const ActivateHandle&h){return fn_801F7EB8(&h)?resolveActivate(h):0;}

inline void ActivateObject::notify(int key){fn_8007D6A0(&record,key);}
#endif
