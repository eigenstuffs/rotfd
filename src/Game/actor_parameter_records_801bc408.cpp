// Observed actor parameter records and three independent fixed-width script keys.
// The partial views below describe only fields accessed by fn_801BC408.
static const char dynamicXFilter_801BC408[16]="DYN_XFILTER";
static const char dynamicYFilter_801BC408[16]="DYN_YFILTER";
static const char dynamicTension_801BC408[16]="DYN_TENSION";
struct APVector_801BC408 {float x,y,z;void operator=(const APVector_801BC408&v){x=v.x;y=v.y;z=v.z;}void set(float a,float b,float c){x=a;y=b;z=c;}void negate(){set(-x,-y,-z);}};
struct APHandle_801BC408 {signed int generation:8;signed int index:24;};
struct APNested_801BC408 {char unknown00[0x30];APVector_801BC408 position;};
struct APObject_801BC408 {char unknown00[0x2C];APHandle_801BC408 parent;char unknown30[0x98];float x,y,z,w;char unknownD8[0x4C];APNested_801BC408*nested;};
struct APEntry_801BC408 {APObject_801BC408*object;char unknown04[8];signed char generation;char unknown0D[3];};
struct APManager_801BC408 {char unknown00[8];APEntry_801BC408*entries;};
struct APResource_801BC408 {char unknown00[0x94];int*indices;int index(const int&i)const{return indices[i];}};
struct APContext_801BC408 {char unknown00[0x118];APManager_801BC408*manager;char unknown11C[0x28];APResource_801BC408*resource;};
struct APInput_801BC408 {char unknown00[0x28];APHandle_801BC408*handles;};
extern "C" {extern APVector_801BC408 game_vec3_zero;extern APContext_801BC408 lbl_801E9D24;extern const float lbl_8037A2A0,lbl_8037A2A4,lbl_8037A2C0;unsigned long strlen(const char*);int strncmp(const char*,const char*,unsigned long);int atoi(const char*);const char*fn_8025318C(APObject_801BC408*,int*);const char*fn_802530C8(APObject_801BC408*,int*);}
static inline APObject_801BC408*resolveAP_801BC408(const APHandle_801BC408&h){APEntry_801BC408*e=&lbl_801E9D24.manager->entries[h.index];if(e->generation==h.generation)return e->object;return 0;}
inline void*operator new(unsigned long,void*p){return p;}
struct APRecord_801BC408 {APObject_801BC408*object;float x,y,z,w;APVector_801BC408 position,zero;float copyX;APVector_801BC408 inverse;char unknown3C[0x40];float a,b,c,d,e,f;APRecord_801BC408(){}~APRecord_801BC408(){}};
template<class T,int N>struct APFixed_801BC408 {T storage[N];int count;T&operator[](int i){return storage[i];}int append(){if(count>=N){new(&storage[N-1])T;return N-1;}new(&storage[count++])T;return count-1;}void resize(int n){if(n>count){for(int i=count;i<n;++i)new(&storage[i])T;}else if(n<count){for(int i=count-1;i>=n;--i)storage[i].~T();}count=n;}};
struct APOwner_801BC408 {char unknown00[0x20];float value;APFixed_801BC408<APRecord_801BC408,16>records;int found;char unknown96C[0x22C];APInput_801BC408*input;};
typedef char APRecordSize_801BC408[sizeof(APRecord_801BC408)==0x94?1:-1];
extern "C" void fn_801BC408(APOwner_801BC408*self,APInput_801BC408*input){
 self->found=0;self->records.resize(0);self->value=lbl_8037A2A0;self->input=input;
 if(self->input){for(int i=0;i<16;++i){APObject_801BC408*object=resolveAP_801BC408(self->input->handles[lbl_801E9D24.resource->index(i+12)]);if(object){
 int index=self->records.append();APRecord_801BC408&record=self->records[index];record.object=object;record.position.set(object->nested->position.x,object->nested->position.y,object->nested->position.z);
 record.x=object->x;record.y=object->y;record.z=object->z;record.w=object->w;
 record.copyX=record.x;record.inverse.x=record.y;record.inverse.y=record.z;record.inverse.z=record.w;record.inverse.negate();record.zero=game_vec3_zero;record.a=lbl_8037A2A4;record.b=lbl_8037A2A4;
 APObject_801BC408*parent=resolveAP_801BC408(object->parent);record.f=record.e=record.d=record.c=lbl_8037A2A0;
 if(parent){int length;const char*line=fn_8025318C(parent,&length);while(line){
 if(strncmp(line,dynamicXFilter_801BC408,strlen(dynamicXFilter_801BC408))==0){int n=atoi(line+strlen(dynamicXFilter_801BC408));if(n<0)n=0;if(n>100)n=100;record.e=(float)n/lbl_8037A2C0;}
 if(strncmp(line,dynamicYFilter_801BC408,strlen(dynamicYFilter_801BC408))==0){int n=atoi(line+strlen(dynamicYFilter_801BC408));if(n<0)n=0;if(n>100)n=100;record.f=(float)n/lbl_8037A2C0;}
 if(strncmp(line,dynamicTension_801BC408,strlen(dynamicTension_801BC408))==0){int n=atoi(line+strlen(dynamicXFilter_801BC408));if(n<0)n=0;if(n>100)n=100;record.c=(float)n/lbl_8037A2C0;}
 line=fn_802530C8(parent,&length);}}
 ++self->found;}}}
}
