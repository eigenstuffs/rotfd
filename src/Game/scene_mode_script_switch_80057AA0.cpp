/* Scene mode switch: stop the selected music, reset scene timers, compact the
   timer array, then run the extras/level script for the new mode. */
typedef unsigned long Word;
extern "C"{extern char lbl_8028F698[];void*fn_8028FAF4(void*,void*,int,int);void*fn_8028FF24(void*,int);void fn_8028FD50(void*,void*,int);}
template<class T>struct Array{int count,capacity;T*data;
 void resize(const int&n){if(n){if(data)data=(T*)fn_8028FAF4(lbl_8028F698,data,capacity*sizeof(T),n*sizeof(T));else data=(T*)fn_8028FF24(lbl_8028F698,n*sizeof(T));}else if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));data=0;}}
 void compact(){if(capacity>count){if(count==0){if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));data=0;}data=0;}else resize(count);capacity=count;}}
};
struct Handle{union{Word word;struct{signed int tag:8,index:24;}bits;};};
struct Entry{void*object;Word unknown04,unknown08;signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{Word unknown00,unknown04;Entry*entries;};
struct UI{char unknown00[0x2D];unsigned char flag2D;};
struct Scene{char unknown00[0x34];Array<Word>timers;};
struct ResetPrefix{char unknown00[0x1C];};
struct Resetter:ResetPrefix{virtual void s08();virtual void s0C();virtual void s10();virtual void s14();virtual void s18();virtual void s1C();virtual void s20();virtual void s24();virtual void s28();virtual void s2C();virtual void s30();virtual void s34();virtual void reset(int,int,int);};
struct SoundPrefix{char unknown00[0x7C];};
struct Sound:SoundPrefix{virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();virtual void slot8();virtual void slot9();virtual void slot10();virtual void slot11();virtual void slot12();virtual void slot13();virtual void slot14();virtual void stopAll();virtual void slot16();virtual void stop(const char*);};
extern "C" struct Context{char unknown00[0x110];void*diagnostics;char unknown114[4];Manager*manager;char unknown11C[8];Scene*scene;char unknown128[0x2C];Resetter*resetter;Sound*sound;char unknown15C[8];UI*ui;}lbl_801E9D24;
struct NamePool{char names[71][20];char pad58C[0xC];char format598[0x14];char mode0[0x1C];char mode1[0x1C];char mode2[0x1C];char mode3[0x18];char format618[1];};
extern "C"{extern const NamePool lbl_8029ACA8;extern Word lbl_803777B0;void fn_801FA014(void*,const char*,...);void fn_801FA1F0(void*,const char*);Word fn_801F7EB8(const Handle*);void fn_800AC70C(void*,signed char);void fn_800BE2BC(Scene*);void fn_80260180(Scene*);void fn_800B6C84(UI*,int,Word);void fn_8003FA74();int sprintf(char*,const char*,...);}
inline void*resolve(const Handle&h){int i=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[i].getTag();return tag==h.bits.tag?m->entries[i].object:0;}
inline const char*poolName(const NamePool*s,int i){const char(NamePool::*m)[71][20]=&NamePool::names;const char(*rows)[20]=s->*m;rows+=i;return*rows;}
struct Item{const char*name;char unknown04[0x1C];};
struct Record{char unknown00[0x2C];Item*items;char unknown30[0x64];};
struct Self{char unknown00[0x68];Handle menu;unsigned char flag6C;char unknown6D[0x83];int current,sub,previous,previousSub;char unknown100[8];int selection;char unknown10C[0xC];int field118,field11C,field120,field124;char unknown128[0x10];Record*records;char unknown13C[0xC];unsigned short slots[50];char unknown1AC[0x120];int field2CC;char unknown2D0[0x24];unsigned char flag2F4,flag2F5,enabled;char unknown2F7[0x25];int messages;};
extern "C" void fn_80057AA0(Self*self,int mode,int sub)
{
    const NamePool*const s=&lbl_8029ACA8;
    lbl_801E9D24.ui->flag2D=0;
    lbl_801E9D24.resetter->reset(0,0,0);
    self->field2CC=0;
    fn_800BE2BC(lbl_801E9D24.scene);
    for(unsigned short i=0;i<50;i++)self->slots[i]=0;
    self->flag2F4=0;
    fn_80260180(lbl_801E9D24.scene);
    self->enabled=0;
    if(self->selection!=-1){
        fn_801FA014(lbl_801E9D24.diagnostics,s->format598,poolName(s,self->selection));
        lbl_801E9D24.sound->stop(poolName(s,self->selection));
        self->selection=-1;
    }
    if(fn_801F7EB8(&self->menu))fn_800AC70C(resolve(self->menu),1);
    lbl_801E9D24.sound->stopAll();
    self->flag6C=0;
    self->previous=self->current;
    self->previousSub=self->sub;
    self->current=mode;
    self->sub=sub;
    self->field118=0;
    self->field11C=0;
    self->field124=0;
    self->field120=0;
    self->flag2F5=0;
    fn_80260180(lbl_801E9D24.scene);
    lbl_801E9D24.scene->timers.compact();
    fn_800B6C84(lbl_801E9D24.ui,0,lbl_803777B0);
    if(mode==-1){
        switch(sub){
        case 0:fn_801FA1F0(lbl_801E9D24.diagnostics,s->mode0);break;
        case 1:fn_801FA1F0(lbl_801E9D24.diagnostics,s->mode1);break;
        case 2:fn_801FA1F0(lbl_801E9D24.diagnostics,s->mode2);break;
        case 3:fn_801FA1F0(lbl_801E9D24.diagnostics,s->mode3);break;
        }
    }else if(self->messages==1)fn_8003FA74();
    else{
        char text[32];
        sprintf(text,s->format618,self->records[self->current].items[self->sub].name);
        fn_801FA1F0(lbl_801E9D24.diagnostics,text);
        self->messages++;
    }
}
