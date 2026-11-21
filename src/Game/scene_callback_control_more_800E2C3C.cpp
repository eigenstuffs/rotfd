/* Scene callback setup and nested Handle control; see docs/notes/game-scene-native-callback-controls-more.md. */
typedef unsigned long Word;struct Group{virtual void slot08();virtual void slot0C();virtual void slot10(int);char unknown04[0x28];void**entries;};
struct Owner{char unknown00[0x30];unsigned long long flags;char unknown38[0x2E0];Group group;};
extern "C"{extern char lbl_801EF5C8[];extern const char lbl_802AAFA8[],lbl_802AAFB8[];void*fn_801EFA1C(void*,unsigned long,const char*,const char*,int,int);void fn_8007D6A0(void*,int);void*fn_800E17B4(void*,Owner*,void*);void*fn_800E1DA4(void*,Owner*,void*);}
extern "C" void fn_800E2C3C(Owner*self,void*arg){
void*p0=fn_801EFA1C(lbl_801EF5C8,16,lbl_802AAFA8,lbl_802AAFB8,69,4);if(p0)p0=fn_800E17B4(p0,self,arg);self->group.entries[0]=p0;
void*p1=fn_801EFA1C(lbl_801EF5C8,20,lbl_802AAFA8,lbl_802AAFB8,70,4);if(p1)p1=fn_800E1DA4(p1,self,arg);self->group.entries[1]=p1;
self->group.slot10(2);fn_8007D6A0(&self->group,0);}
