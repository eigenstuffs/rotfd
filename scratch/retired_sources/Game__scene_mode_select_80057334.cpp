/* Scene mode selection: release the owner's handle arrays, record the new mode,
   refresh the actor link, stop the selected music and switch the named scene mode. */
typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Entry{void*object;Word unknown04,unknown08;signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{Word unknown00,unknown04;Entry*entries;};
struct UI{char unknown00[0x2D];unsigned char flag2D;};
struct Scene;
struct Related{char unknown00[0x1C];Handle_801F7F10*handle;};
struct ResetPrefix{char unknown00[0x1C];};
struct Resetter:ResetPrefix{virtual void s08();virtual void s0C();virtual void s10();virtual void s14();virtual void s18();virtual void s1C();virtual void s20();virtual void s24();virtual void s28();virtual void s2C();virtual void s30();virtual void s34();virtual void reset(int,int,int);};
struct SoundPrefix{char unknown00[0x7C];};
struct Sound:SoundPrefix{virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();virtual void slot8();virtual void slot9();virtual void slot10();virtual void slot11();virtual void slot12();virtual void slot13();virtual void slot14();virtual void stopAll();virtual void slot16();virtual void stop(const char*);};
extern "C" struct Context{char unknown00[0x110];void*diagnostics;char unknown114[4];Manager*manager;char unknown11C[8];Scene*scene;char unknown128[0x14];Related*related;char unknown140[0x14];Resetter*resetter;Sound*sound;char unknown15C[8];UI*ui;}lbl_801E9D24;
extern "C"{extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(Manager*,const Handle_801F7F10*,int);Word fn_801F7EB8(const Handle_801F7F10*);Word fn_801F948C(void*,const char*);}
struct Handle_8002B67C:Handle_801F7F10{Handle_8002B67C(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_8002B67C(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct NamePool{char music[13][20];char modes[6][15];char pad15E[0x598-0x15E];char format598[0x14];};
struct Name{Word value;Name(){}Name(const char*t){value=fn_801F948C(this,t);}Name(const Name&n){value=n.value;}void set(const char*t){value=fn_801F948C(this,t);}};
struct Node{char unknown00[0x70];Handle_801F7F10 actor;char unknown74[0x10];int field84;char unknown88[0x28];Handle_801F7F10*child;char unknownB4[0xF8];Handle_801F7F10 handle1AC;};
template<class T>struct Array{int count,capacity;T*data;};
struct Self{char unknown00[0x68];Handle_801F7F10 menu;char unknown6C[0x94];int current,field104,selection;char unknown10C[0x168];Array<Handle_801F7F10>first;Array<Handle_801F7F10>second;char unknown28C[0x68];unsigned char flag2F4,flag2F5,enabled;char unknown2F7[0x1D];void*field314;};
extern "C"{extern const NamePool lbl_8029ACA8;void fn_801FA014(void*,const char*,...);void fn_800AC70C(void*,signed char);void fn_80255678(void*);void fn_80057908(Self*);}
extern "C" void fn_800BDA88(Scene*,const Name&,const Name&);
inline void*resolve(const Handle_801F7F10&h){int i=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[i].getTag();return tag==h.bits.tag?m->entries[i].object:0;}
inline const char*musicName(const NamePool*s,int i){const char(NamePool::*m)[13][20]=&NamePool::music;const char(*rows)[20]=s->*m;rows+=i;return*rows;}
inline const char*modeName(const NamePool*s,int i){const char(NamePool::*m)[6][15]=&NamePool::modes;const char(*rows)[15]=s->*m;rows+=i;return*rows;}
inline Node*relatedChild(){Handle_8002B67C h(*lbl_801E9D24.related->handle);if(fn_801F7EB8(&h)){Handle_801F7F10*child=((Node*)resolve(h))->child;if(fn_801F7EB8(child))return (Node*)resolve(*child);}return 0;}
inline Node*actor(){const Handle_801F7F10&h=((Node*)resolve(*((Node*)resolve(*lbl_801E9D24.related->handle))->child))->actor;if(fn_801F7EB8(&h))return (Node*)resolve(h);return 0;}
extern "C" void fn_80057334(Self*self,int mode)
{
    const NamePool*const s=&lbl_8029ACA8;
    self->flag2F4=1;
    int old=self->current;
    Node*child=relatedChild();
    if(mode==self->current)mode=0;
    int i;
    for(i=0;i<self->first.count;i++)if(fn_801F7EB8(&self->first.data[i]))fn_80255678(resolve(self->first.data[i]));
    for(i=0;i<self->second.count;i++)if(fn_801F7EB8(&self->second.data[i]))fn_80255678(resolve(self->second.data[i]));
    fn_80057908(self);
    self->current=mode;
    self->field104=child->field84;
    Node*a=actor();
    self->field314=0;
    if(fn_801F7EB8(&a->handle1AC))self->field314=resolve(actor()->handle1AC);
    lbl_801E9D24.resetter->reset(0,0,0);
    lbl_801E9D24.ui->flag2D=0;
    if(fn_801F7EB8(&self->menu))fn_800AC70C(resolve(self->menu),1);
    self->enabled=0;
    if(self->selection!=-1){
        fn_801FA014(lbl_801E9D24.diagnostics,s->format598,musicName(s,self->selection));
        lbl_801E9D24.sound->stop(musicName(s,self->selection));
        self->selection=-1;
    }
    Name newCopy,newName,oldCopy,oldName;
    oldName.set(modeName(s,old));
    oldCopy=oldName;
    newName.set(modeName(s,self->current));
    newCopy=newName;
    fn_800BDA88(lbl_801E9D24.scene,newCopy,oldCopy);
}
