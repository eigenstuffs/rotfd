/* Ordinary typed settings snapshot with inline record copies.
 * See docs/notes/game-settings-snapshot.md for the verified field layout. */
typedef unsigned long Word;
struct SourceRecord{char unknown00[8];Word first,second,third;unsigned char*name,*description,*tags;};
struct SourceGroup{Word unknown00;Word first,second,third,fourth;char unknown14[12];unsigned char bytes[9];unsigned char a,b,c;SourceRecord*records;short values[50];};
struct Settings{SourceGroup group[7];};
struct Source{char unknown00[0xF0];Word first,second;char unknownF8[8];Word field100,field104;char unknown108[0x30];Settings*settings;Word x,y,z;char unknown148[0x64];short values[100];char unknown274[0x78];unsigned char byte2EC,byte2ED;short unknown2EE;Word field2F0;};
struct OutputRecord{Word first,second,third;unsigned char name[250],description[100],tags[100];short unknown1CE;};
template<int N>struct OutputGroup{Word first,second,third,fourth;unsigned char bytes[9];unsigned char a,b,c;short values[50];OutputRecord records[N];};
struct Output{Word first,second,field08,field0C;float firstFloat,secondFloat;unsigned char byte18,byte19;short unknown1A;Word x,y,z;short values[100];OutputGroup<5>g0;OutputGroup<3>g6;OutputGroup<4>g1,g2,g3;OutputGroup<5>g4;OutputGroup<4>g5;unsigned char flags[300][2];Word field3B58;};
struct ModePrefix{char unknown00[0x7C];};struct Mode:ModePrefix{virtual void s0();virtual void s1();virtual void s2();virtual void s3();virtual void s4();virtual void s5();virtual void s6();virtual void s7();virtual void s8();virtual void s9();virtual void s10();virtual float getFirst();virtual void s12();virtual float getSecond();};
extern "C" struct Global{char unknown00[0x158];Mode*mode;}lbl_801E9D24;
struct FlagRecord{char unknown00[0x4C];unsigned char second,unknown4D,first,unknown4F;};extern "C" FlagRecord lbl_802F4208[300];
inline FlagRecord*getFlags(int i){return &lbl_802F4208[i];}
#define COPY_GROUP(K,D,N) \
 out->D.first=self->settings->group[K].first; \
 out->D.second=self->settings->group[K].second; \
 out->D.third=self->settings->group[K].third; \
 out->D.fourth=self->settings->group[K].fourth; \
 out->D.a=self->settings->group[K].a;out->D.b=self->settings->group[K].b;out->D.c=self->settings->group[K].c; \
 for(int j=0;j<50;++j)out->D.values[j]=self->settings->group[K].values[j]; \
 for(int j=0;j<9;++j)out->D.bytes[j]=self->settings->group[K].bytes[j]; \
 for(int i=0;i<N;++i){ \
  out->D.records[i].first=self->settings->group[K].records[i].first; \
  out->D.records[i].second=self->settings->group[K].records[i].second; \
  out->D.records[i].third=self->settings->group[K].records[i].third; \
  for(int j=0;j<250;++j)out->D.records[i].name[j]=self->settings->group[K].records[i].name[j]; \
  for(int j=0;j<100;++j)out->D.records[i].description[j]=self->settings->group[K].records[i].description[j]; \
  for(int j=0;j<100;++j)out->D.records[i].tags[j]=self->settings->group[K].records[i].tags[j]; \
 }
extern "C" void fn_800541F0(Source*self,Output*out){
 out->second=self->second;out->first=self->first;out->field3B58=self->field2F0;out->field08=self->field100;out->field0C=self->field104;
 out->firstFloat=lbl_801E9D24.mode->getFirst();out->secondFloat=lbl_801E9D24.mode->getSecond();out->byte18=self->byte2ED;out->byte19=self->byte2EC;out->x=self->x;out->y=self->y;out->z=self->z;
 for(int i=0;i<100;++i)out->values[i]=self->values[i];
 COPY_GROUP(0,g0,5);COPY_GROUP(6,g6,3);COPY_GROUP(1,g1,4);COPY_GROUP(2,g2,4);COPY_GROUP(3,g3,4);COPY_GROUP(4,g4,5);COPY_GROUP(5,g5,4);
 for(unsigned short i=0;i<300;++i){FlagRecord*record=getFlags(i);if(record){out->flags[i][0]=record->first;out->flags[i][1]=record->second;}}
}

typedef char SourceGroupSize[(sizeof(SourceGroup)==0x94)?1:-1];
typedef char OutputRecordSize[(sizeof(OutputRecord)==0x1D0)?1:-1];
typedef char OutputSize[(sizeof(Output)==0x3B5C)?1:-1];
