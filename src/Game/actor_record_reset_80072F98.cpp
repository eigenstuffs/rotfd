typedef unsigned long Word;
extern "C"{extern char lbl_801EF5C8[],lbl_8028F698[];void fn_801EF610(void*,void*);void fn_8028FD50(void*,void*,int);}
struct Handle_801F7F10{union{Word value;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct ResetHandle1_80072F98:Handle_801F7F10{~ResetHandle1_80072F98(){}};
struct ResetHandle2_80072F98:ResetHandle1_80072F98{~ResetHandle2_80072F98(){}};
struct ResetRecordBase_80072F98{int key;ResetHandle2_80072F98 handle;float a,b,c,d;~ResetRecordBase_80072F98(){}};
struct ResetRecord_80072F98:ResetRecordBase_80072F98{~ResetRecord_80072F98(){}};
struct Array_80025634{int count,capacity;ResetRecord_80072F98*data;Array_80025634(const Array_80025634&);~Array_80025634(){if(data){for(int i=0;i<count;++i)data[i].~ResetRecord_80072F98();if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(ResetRecord_80072F98));data=0;}data=0;}}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};

struct Prefix{char unknown0[8];};
struct Node:Prefix {
virtual void slot00();
virtual void slot01();
virtual void slot02();
virtual void slot03();
virtual void slot04();
virtual void slot05();
virtual void slot06();
virtual void slot07();
virtual void slot08();
virtual void slot09();
virtual void slot0A();
virtual void slot0B();
virtual void slot0C();
virtual void slot0D();
virtual void select(int);
char unknownC[0x20-0xC];Handle_801F7F10 related;
char unknown24[0x30-0x24];unsigned long long flags;
char unknown38[0x4C-0x38];Array_80025634 array;
char unknown58[0x120-0x58];Word stateFlags;
char unknown124[0x1F0-0x124];Handle_801F7F10 relatedArray;
};
struct Entry{Node*object;char unknown4[8];signed char tag;char unknownD[3];};
struct Manager{int count,capacity;Entry*entries;};
struct Context{char unknown0[0x118];Manager*manager;};
extern "C" Context lbl_801E9D24;
inline Node*resolve(const Handle_801F7F10&h){Entry*e=&lbl_801E9D24.manager->entries[h.bits.index];return e->tag==h.bits.tag?e->object:0;}
struct ArrayNode{char unknown0[0x4C];Array_80025634 array;};
struct ArrayEntry{ArrayNode*object;char unknown4[8];signed char tag;char unknownD[3];};
struct ArrayManager{int count,capacity;ArrayEntry*entries;};
inline ArrayNode*resolveArray(const Handle_801F7F10&h){ArrayEntry*e=&((ArrayManager*)lbl_801E9D24.manager)->entries[h.bits.index];return e->tag==h.bits.tag?e->object:0;}
struct RelatedNode:Node{};
struct RelatedEntry{RelatedNode*object;char unknown4[8];signed char tag;char unknownD[3];};
struct RelatedManager{int count,capacity;RelatedEntry*entries;};
inline RelatedNode*resolveRelated(const Handle_801F7F10&h){RelatedEntry*e=&((RelatedManager*)lbl_801E9D24.manager)->entries[h.bits.index];return e->tag==h.bits.tag?e->object:0;}
struct Actor:Prefix{
virtual void slot00();
virtual void slot01();
virtual void slot02();
virtual void slot03();
virtual void slot04();
virtual void slot05();
virtual void slot06();
virtual void slot07();
virtual void slot08();
virtual void slot09();
virtual void slot0A();
virtual void slot0B();
virtual void slot0C();
virtual void slot0D();
virtual void slot0E();
virtual void slot0F();
virtual void slot10();
virtual void slot11();
virtual void slot12();
virtual void slot13();
virtual void slot14();
virtual void slot15();
virtual void slot16();
virtual void slot17();
virtual void event(int);
char unknownC[0x58-0xC];Handle_801F7F10 first;
char unknown5C[0x64-0x5C];Handle_801F7F10 second;
char unknown68[0x70-0x68];Handle_801F7F10 third;
char unknown74[0x90-0x74];short selection;
char unknown92[6];unsigned char enabled;
};
extern "C"void fn_80072F98(Actor*self){
self->selection=-1;self->enabled=1;
resolve(self->third)->flags&=0xFFFFFFFF7E0001FFULL;
resolve(self->first)->stateFlags&=~0x40000UL;
Array_80025634 records(resolveArray(resolve(self->second)->relatedArray)->array);
int recordIndex;for(short i=0;(recordIndex=i)<records.count;++i)resolve(records.data[recordIndex].handle)->stateFlags&=~0x40000UL;
self->event(0);
resolveRelated(resolve(self->first)->related)->select(-1);
}
