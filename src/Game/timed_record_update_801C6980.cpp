/* Timed action-record update and loop-boundary dispatch; see docs/notes/game-timed-record-update.md. */
typedef unsigned long Word;
struct Handle { signed int tag:8; signed int index:24; };
struct Target;
struct Entry { Target*object;char unknown04[8];signed char tag;char unknown0D[3]; };
struct Manager { char unknown00[8];Entry*entries; };
struct Context { char unknown00[0x118];Manager*manager;char unknown11C[8];void*scene; };
extern "C" Context lbl_801E9D24;
struct Curve { int unknown00,count;void*data;int unknown0C; };
struct Resource { char unknown00[0x54];Curve actions;char unknown64[0x10];float duration; };
struct Work { int type,value,unknown08;float time;char unknown10[0x1C]; };
struct Owner { char unknown00[0x20];int handleCount,handleCapacity;Handle*handles;char unknown2C[0x18];Handle resource;Word unknown48;Handle event;Word unknown50;float current,previous;Word unknown5C;unsigned short flags;char unknown62[0x18];unsigned short repeatCount;float marker; };
extern "C" { extern const float lbl_8037A3FC,lbl_8037A400,lbl_8037A3D0;void fn_801C6968(void*);void __construct_array(void*,void(*)(void*),void(*)(void*),unsigned int,unsigned int);short fn_801F72E4(Curve*,Work*,int*,short,float,float,float);void fn_801C5698(Owner*,int);void fn_802322B8(Target*,float);void fn_802073E8(Owner*,int,Target*,float);void fn_802603E8(void*,float); }
static inline Target*resolve(const Handle&handle){Entry*entry=&lbl_801E9D24.manager->entries[handle.index];return entry->tag==handle.tag?entry->object:0;}
static inline Word resolveWord(const Handle&handle){Entry*entry=&lbl_801E9D24.manager->entries[handle.index];return entry->tag==handle.tag?(Word)entry->object:0;}
typedef char HandleSize[(sizeof(Handle)==4)?1:-1];
typedef char WorkSize[(sizeof(Work)==44)?1:-1];
extern "C" void fn_801C6980(Owner*self,float delta){
 if(delta<lbl_8037A3FC)return;
 Resource*resource=(Resource*)resolve(self->resource);
 self->previous=self->current;
 self->current+=delta;
 if(resource->actions.count && !(self->flags&8)){
  signed char repeat;
  do{
   Work records[64];__construct_array(records,fn_801C6968,0,sizeof(Work),64);
   int count=0;Work*record=records;repeat=0;
   float end=self->current;if(end>resource->duration)end=resource->duration;
   fn_801F72E4(&resource->actions,records,&count,0,self->previous,end,resource->duration);
   for(int i=0;i<count;++i,++record){
    if(record->type==12 && !(self->flags&2)){
     repeat=1;self->marker=record->time;self->flags|=2;self->flags&=~4;
    }else if(record->type==13){
     if(self->flags&4){
      if(self->repeatCount-- && !self->repeatCount)self->flags&=~6;
     }else{
      self->repeatCount=(unsigned short)record->value;self->flags|=4;
     }
     if(self->flags&4){
      float carry=self->current-record->time;self->current=record->time;
      fn_801C5698(self,0);self->previous=self->marker;
      int offset;int j=0;offset=0;for(;j<self->handleCount;++j){fn_802322B8(resolve(*(Handle*)((char*)self->handles+offset)),self->previous);offset+=4;}
      repeat=1;self->current=self->previous+carry;
     }
    }
   }
  }while(repeat);
 }
 signed char ended;
 if(self->current>resource->duration){self->current=resource->duration;ended=1;}else ended=0;
 fn_801C5698(self,0);
 if(ended){fn_802073E8(self,0x1F,(Target*)resolveWord(self->event),lbl_8037A400);fn_802603E8(lbl_801E9D24.scene,lbl_8037A3D0);}
}
