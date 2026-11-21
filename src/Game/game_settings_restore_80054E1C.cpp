/* fn_80054E1C: restore game settings from a saved Output block (inverse of fn_800541F0).
 * Based on scratch/game_settings_restore_80054e1c/native_gekko.cpp. The flag setter takes its
 * arguments as (second, first) and binds the first value through a const reference, which keeps
 * the original load order (0x3900 then 0x3901) by blocking expression propagation. */
typedef unsigned long Word;
struct SourceRecord{char unknown00[8];Word first,second,third;unsigned char*name,*description,*tags;};
struct SourceGroup{Word unknown00;Word first,second,third,fourth;char unknown14[12];unsigned char bytes[9];unsigned char a,b,c;SourceRecord*records;short values[50];};
struct Settings{SourceGroup group[7];};
struct Source{char unknown00[0xF0];Word first,second;char unknownF8[8];Word field100,field104;char unknown108[0x30];Settings*settings;Word x,y,z;char unknown148[0x64];short values[100];char unknown274[0x78];unsigned char byte2EC,byte2ED;short unknown2EE;Word field2F0;char unknown2F4;unsigned char byte2F5;};
struct OutputRecord{Word first,second,third;unsigned char name[250],description[100],tags[100];short unknown1CE;};
template<int N>struct OutputGroup{Word first,second,third,fourth;unsigned char bytes[9];unsigned char a,b,c;short values[50];OutputRecord records[N];};
struct Output{Word first,second,field08,field0C;float firstFloat,secondFloat;unsigned char byte18,byte19;short unknown1A;Word x,y,z;short values[100];OutputGroup<5>g0;OutputGroup<3>g6;OutputGroup<4>g1,g2,g3;OutputGroup<5>g4;OutputGroup<4>g5;unsigned char flags[300][2];Word field3B58;};

struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Node{char unknown00[0x84];Word field84;char unknown88[0x28];Handle_801F7F10*child;};
struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};struct Manager{char unknown00[8];Entry*entries;};
struct Related{char unknown00[0x1C];Handle_801F7F10*handle;};
struct ModePrefix{char unknown00[0x7C];};struct Mode:ModePrefix{virtual void s0();virtual void s1();virtual void s2();virtual void s3();virtual void s4();virtual void s5();virtual void s6();virtual void s7();virtual void s8();virtual void s9();virtual void setFirst(float);virtual void s11();virtual void setSecond(float);};
extern "C" struct Global{char unknown00[0x118];Manager*manager;char unknown11C[8];void*scene;char unknown128[0x14];Related*related;char unknown140[0x18];Mode*mode;}lbl_801E9D24;
extern "C"{extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(Manager*,const Handle_801F7F10*,short);Word fn_801F7EB8(const Handle_801F7F10*);void fn_80056434(Source*,Word);void fn_80030E9C(Node*,int,int);void fn_80031654(Node*,Word,Word);}
struct Handle_8002B67C:Handle_801F7F10{Handle_8002B67C(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_8002B67C(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020478:Handle_801F7F10{Handle_80020478(){word=0;}~Handle_80020478(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020834:Handle_80020478{Handle_80020834(){word=0;}~Handle_80020834(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_8003E120:Handle_80020834{Handle_8003E120(const Handle_8003E120&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_8003E120(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
extern "C" Handle_8003E120 fn_800BCF58(void*,const Handle_8002B67C&);
inline Node*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
inline Node*relatedChild(){Handle_8002B67C h(*lbl_801E9D24.related->handle);if(fn_801F7EB8(&h)){const Handle_801F7F10&child=*resolve(h)->child;if(fn_801F7EB8(&child))return resolve(child);}return 0;}
struct FlagRecord{char unknown00[0x4C];unsigned char second,unknown4D,first,unknown4F;void set(const unsigned char b,const unsigned char a){const unsigned char&r=a;first=r;second=b;}};extern "C" FlagRecord lbl_802F4208[300];inline FlagRecord*getFlags(int i){return &lbl_802F4208[i];}
#define COPY_GROUP(K,D,N) \
 self->settings->group[K].first=out->D.first; \
 self->settings->group[K].second=out->D.second; \
 self->settings->group[K].third=out->D.third; \
 self->settings->group[K].fourth=out->D.fourth; \
 self->settings->group[K].a=out->D.a;self->settings->group[K].b=out->D.b;self->settings->group[K].c=out->D.c; \
 for(int j=0;j<50;++j)self->settings->group[K].values[j]=out->D.values[j]; \
 for(int j=0;j<9;++j)self->settings->group[K].bytes[j]=out->D.bytes[j]; \
 for(int i=0;i<N;++i){ \
  self->settings->group[K].records[i].first=out->D.records[i].first; \
  self->settings->group[K].records[i].second=out->D.records[i].second; \
  self->settings->group[K].records[i].third=out->D.records[i].third; \
  for(int j=0;j<250;++j)self->settings->group[K].records[i].name[j]=out->D.records[i].name[j]; \
  for(int j=0;j<100;++j)self->settings->group[K].records[i].description[j]=out->D.records[i].description[j]; \
  for(int j=0;j<100;++j)self->settings->group[K].records[i].tags[j]=out->D.records[i].tags[j]; \
 }
extern "C" void fn_80054E1C(Source*self,Output*out,signed char preserve){
 lbl_801E9D24.mode->setFirst(out->firstFloat);lbl_801E9D24.mode->setSecond(out->secondFloat);
 self->byte2EC=out->byte19;self->x=out->x;self->y=out->y;self->z=out->z;
 for(int i=0;i<100;++i)self->values[i]=out->values[i];
 COPY_GROUP(0,g0,5);COPY_GROUP(6,g6,3);COPY_GROUP(1,g1,4);COPY_GROUP(2,g2,4);COPY_GROUP(3,g3,4);COPY_GROUP(4,g4,5);COPY_GROUP(5,g5,4);
 self->field100=out->field08;fn_80056434(self,out->field0C);self->field2F0=out->field3B58;
 if(!preserve){self->field2F0=0;Handle_8002B67C h(*lbl_801E9D24.related->handle);Handle_8003E120 scene(fn_800BCF58(lbl_801E9D24.scene,h));Word identifier=out->field0C;relatedChild()->field84=identifier;fn_80030E9C(resolve(scene),0,0);self->byte2F5=1;fn_80031654(resolve(scene),out->first,out->second);}
 for(unsigned short i=0;i<300;++i){FlagRecord*record=getFlags(i);if(record){record->set(out->flags[i][1],out->flags[i][0]);}}
}
