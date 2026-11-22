typedef unsigned long Word;struct Group{virtual void slot08();virtual void slot0C();virtual void slot10(int);char unknown04[0x28];void**entries;};
struct Owner{char unknown00[0x30];unsigned long long flags;char unknown38[0x130];Group group;};
extern "C"{extern char lbl_801EF5C8[];extern const char lbl_802AAE60[],lbl_802AAE70[];void*fn_801EFA1C(void*,unsigned long,const char*,const char*,int,int);void fn_8007D6A0(void*,int);void*fn_800E0554(void*,Owner*,void*);void*fn_800E06F4(void*,Owner*,void*);}
extern "C" void fn_800E111C(Owner*self,void*arg){
void*p0=fn_801EFA1C(lbl_801EF5C8,16,lbl_802AAE60,lbl_802AAE70,38,4);if(p0)p0=fn_800E0554(p0,self,arg);self->group.entries[0]=p0;
void*p1=fn_801EFA1C(lbl_801EF5C8,40,lbl_802AAE60,lbl_802AAE70,39,4);if(p1)p1=fn_800E06F4(p1,self,arg);self->group.entries[1]=p1;
self->group.slot10(2);fn_8007D6A0(&self->group,0);self->flags&=0xFFFFFFFF7E0001FFULL;}
