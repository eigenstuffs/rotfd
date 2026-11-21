/* Scene callback and native Handle control; see docs/notes/game-scene-native-callback-controls.md. */
typedef unsigned long Word;
struct Group{virtual void slot08();virtual void slot0C();virtual void slot10(int);char unknown04[0x28];void**entries;};
struct Owner{char unknown00[0x318];Group group;};
extern "C"{extern char lbl_801EF5C8[];extern const char lbl_802A2970[],lbl_802A2980[];void*fn_801EFA1C(void*,unsigned long,const char*,const char*,int,int);void*fn_800CBD08(void*,Owner*,void*);void*fn_800CBEE4(void*,Owner*,void*);void*fn_800CC020(void*,Owner*,void*);void*fn_800CC454(void*,Owner*,void*);}
extern "C" void fn_800CC7D0(Owner*self,void*arg){
void*p0=fn_801EFA1C(lbl_801EF5C8,16,lbl_802A2970,lbl_802A2980,59,4);if(p0)p0=fn_800CBD08(p0,self,arg);self->group.entries[0]=p0;
void*p1=fn_801EFA1C(lbl_801EF5C8,16,lbl_802A2970,lbl_802A2980,60,4);if(p1)p1=fn_800CBEE4(p1,self,arg);self->group.entries[1]=p1;
void*p2=fn_801EFA1C(lbl_801EF5C8,16,lbl_802A2970,lbl_802A2980,61,4);if(p2)p2=fn_800CC020(p2,self,arg);self->group.entries[2]=p2;
void*p3=fn_801EFA1C(lbl_801EF5C8,16,lbl_802A2970,lbl_802A2980,62,4);if(p3)p3=fn_800CC454(p3,self,arg);self->group.entries[3]=p3;
self->group.slot10(4);}
