struct CurveApplyStorage {char unknown00[8];};
struct CurveApplyObject:CurveApplyStorage {virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void apply();};
struct CurveApplyHandle {signed int generation:8;signed int index:24;};
struct CurveApplyEntry {char*object;char unknown04[8];signed char generation;char unknown0D[3];};
struct CurveApplyManager {char unknown00[8];CurveApplyEntry*entries;};
struct CurveApplyChannel {unsigned long unknown00;int count;char unknown08[8];};
struct CurveApplyOwner {char unknown00[0xC];unsigned char flags;char unknown0D[3];CurveApplyChannel channels[10];float time,duration;CurveApplyHandle handle;};
extern "C" {extern struct {char unknown00[0x118];CurveApplyManager*manager;}lbl_801E9D24;extern const float lbl_8037B300,lbl_8037B304;void fn_801B0EB8(void*,void*,float,int);void fn_801B07A4(void*,void*,float,int);void fn_801B093C(void*,void*,float,int);void fn_801AFA0C(void*,void*,float,int);void fn_801B0F8C(void*,void*,float,int);}
static inline char*resolveCurveApply(const CurveApplyHandle&h){CurveApplyEntry*e=&lbl_801E9D24.manager->entries[h.index];if(e->generation==h.generation)return e->object;return 0;}
extern "C" void fn_80239828(CurveApplyOwner*self,float delta){if(self->flags&1){self->time+=delta;if(self->time>self->duration&&(self->flags&4)){self->flags|=2;self->flags&=~1;self->time=self->duration;}else{while(self->time>self->duration)self->time-=self->duration;}float time=self->time;char*object=resolveCurveApply(self->handle);
 if(self->channels[0].count)fn_801B0EB8(&self->channels[0],object+0x74,time,1);
 if(self->channels[1].count)fn_801B07A4(&self->channels[1],object+0x54,time,1);
 if(self->channels[2].count)fn_801B07A4(&self->channels[2],object+0x5C,time,1);
 if(self->channels[3].count)fn_801B093C(&self->channels[3],object+0x50,time,1);
 if(self->channels[4].count)fn_801AFA0C(&self->channels[4],object+0xC,time,1);
 if(self->channels[5].count)fn_801AFA0C(&self->channels[5],object+0x1C,time,1);
 if(self->channels[6].count)fn_801B093C(&self->channels[6],object+0x18,time,1);
 if(self->channels[7].count)fn_801B0F8C(&self->channels[7],object+0x64,time,1);
 if(self->channels[8].count)fn_801B0F8C(&self->channels[8],object+0x68,time,1);
 if(self->channels[9].count)fn_801B0F8C(&self->channels[9],object+0x6C,time,1);
 ((CurveApplyObject*)object)->apply();
}}
