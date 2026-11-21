/* Select a menu record through the owner's menu handle, rebind the menu's
   target handle, and send event 0xA2 to the target and the observer. */
typedef unsigned long Word;
struct Handle{union{Word word;struct{signed int tag:8,index:24;}bits;};};
struct MenuRecord{int key;};
struct Menu{char unknown00[0x20];int selected;char unknown24[0x12C];Handle target;};
struct Entry{void*object;char unknown04[8];signed char tag;char unknown0D[3];bool matchesTag(signed char t)const{return tag==t;}};
struct EntryArray{Entry*p;Entry&operator[](int i)const{return p[i];}};
struct Manager{int count,capacity;EntryArray entries;};
extern "C" struct Global{char unknown00[0x118];Manager*manager;}lbl_801E9D24;
struct ObserverPrefix{Word unknown00;};
struct Observer:ObserverPrefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void*slot14();};
extern "C"{extern Observer*lbl_803776B8;Word fn_801F7EB8(const Handle*);void fn_801F86C8(Manager*,const Handle*,int);MenuRecord*fn_800AC260(Menu*);void fn_800AC70C(Menu*,signed char);void fn_800AC2B4(Menu*,int);void fn_802073E8(void*,int,void*,float);}
inline void*resolve(const Handle&h){Manager*m=lbl_801E9D24.manager;int index=h.bits.index;const signed char tag=h.bits.tag;if(m->entries[index].matchesTag(tag))return m->entries[index].object;return 0;}
struct Owner{char unknown00[0x68];Handle menu;};
extern "C" void fn_80058CB8(Owner*self,int key,Handle*target)
{
    if(!fn_801F7EB8(&self->menu))return;
    if(((Menu*)resolve(self->menu))->selected>=0){
        if(fn_800AC260((Menu*)resolve(self->menu))->key>=9000)fn_800AC70C((Menu*)resolve(self->menu),0);
        else return;
    }
    fn_800AC2B4((Menu*)resolve(self->menu),key);
    Menu*menu=(Menu*)resolve(self->menu);
    fn_801F86C8(lbl_801E9D24.manager,&menu->target,-1);
    menu->target.word=target->word;
    fn_801F86C8(lbl_801E9D24.manager,target,1);
    if(fn_801F7EB8(target))fn_802073E8(self,0xA2,resolve(*target),(float)key);
    if(lbl_803776B8)fn_802073E8(self,0xA2,lbl_803776B8->slot14(),(float)key);
}
