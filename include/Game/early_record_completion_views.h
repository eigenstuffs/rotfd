#ifndef GAME_EARLY_RECORD_COMPLETION_VIEWS_H
#define GAME_EARLY_RECORD_COMPLETION_VIEWS_H

struct Handle_801F7F10{unsigned long value;Handle_801F7F10();~Handle_801F7F10();};
struct CompletionAgent;
struct CompletionHandle{union{unsigned long value;struct{signed int tag:8;signed int index:24;}bits;};};
struct CompletionEntry{CompletionAgent*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct CompletionManager{int count,capacity;CompletionEntry*entries;};
struct CompletionMenuRecord{char unknown00[0x2B];signed char completed;char unknown2C[0x68];};
struct CompletionScreen{char unknown00[0xF0];int current;char unknownF4[0x44];CompletionMenuRecord*records;char unknown13C[0x16];short pending;short getPending(){return pending;}};
struct CompletionScene{char unknown00[0x15058];CompletionScreen*screen;};
struct CompletionInput{char unknown00[0x2D];signed char enabled;};
struct CompletionContext{char unknown00[0x118];CompletionManager*manager;char unknown11C[8];CompletionScene*scene;char unknown128[0x3C];CompletionInput*input;};
extern "C" CompletionContext lbl_801E9D24;
struct CompletionPrefix{char unknown00[8];};
struct CompletionAgent:CompletionPrefix{
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual void slot8();
virtual void slot9();
virtual void slot10();
virtual void slot11();
virtual void slot12();
virtual void slot13();
virtual void slot14();
virtual void slot15();
virtual void slot16();
virtual void slot17();
virtual void slot18();
virtual void slot19();
virtual void slot20();
virtual void slot21(int);
virtual void slot22(int);
virtual void slot23();
virtual void slot24();
virtual void slot25();
virtual void slot26();
virtual void slot27();
virtual void slot28();
virtual void slot29();
virtual void slot30();
virtual void slot31();
virtual void slot32();
virtual void slot33();
virtual void slot34();
virtual void slot35(int,int);
char unknown0C[0x2C];unsigned long long flags;char unknown40[0x30];CompletionHandle controller;char unknown74[0x1C];short slot;char unknown92[0x196];float field228,field22C;char unknown230[0x20];float field250;char unknown254[0x68];float field2BC,field2C0,field2C4;void setPair(float value){field22C=field250=value;}};
inline CompletionAgent*resolveCompletion(const CompletionHandle&h){CompletionEntry*entry=&lbl_801E9D24.manager->entries[h.bits.index];if(entry->tag==h.bits.tag)return entry->object;return 0;}
struct CompletionRecord{short id;CompletionAgent*node;float position[3];};
struct CompletionOwner{char unknown00[0x6A];short count;char unknown6C[8];CompletionRecord records[8];char unknown114[4];void*object;char unknown11C[0x270];int state;};
struct CompletionQueryPrefix{char unknown00[4];};
struct CompletionQuery:CompletionQueryPrefix{virtual void slot0();virtual void slot1();virtual void slot2();virtual void*getResource();};
extern "C"{Handle_801F7F10 fn_801B52EC(CompletionManager*,const char*);void fn_8025A3C8(CompletionAgent*,const Handle_801F7F10&);void fn_8002B780(CompletionAgent*);void fn_8025BBA8(CompletionAgent*);signed char fn_80259F0C(CompletionAgent*);unsigned long fn_801F7EB8(const CompletionHandle*);void fn_800732B8(void*);void fn_802073E8(void*,int,void*,float);extern CompletionQuery*lbl_803776B8;extern const char lbl_8029C9B8[],lbl_8029CA48[];extern const float lbl_8037890C,lbl_80378938,lbl_8037893C,lbl_80378940,lbl_80378944,lbl_80378948;}

#endif
