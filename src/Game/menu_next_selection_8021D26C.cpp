// Menu selection cursor: find the next selectable item and update its window.
static inline int menuSelectableFlags8021D26C(int flags){
  if(flags&0x100) return (signed char)!(flags&2);
  int result=0;
  if(!(flags&6) && (flags&1)) result=1;
  return (signed char)result;
 }
struct MenuSelectionCount8021D26C{ const int value; MenuSelectionCount8021D26C(int v):value(v){} operator int()const{return value;} };
struct MenuSelectionFound8021D26C { signed char value; MenuSelectionFound8021D26C(signed char v):value(v){} operator signed char()const{return value;} MenuSelectionFound8021D26C& operator=(signed char v){value=v;return *this;} };
struct MenuVisibleCount8021D26C{ unsigned short value; MenuVisibleCount8021D26C(unsigned short v):value(v){} operator unsigned short()const{return value;} };
struct MenuSavedIndex8021D26C { short value; MenuSavedIndex8021D26C(short v):value(v){} operator short()const{return value;} };
struct MenuSelectionItem8021D26C {
 char unknown00[0x8C]; unsigned short flags;
 int selectable() const {return menuSelectableFlags8021D26C(flags);}
};
struct MenuSelectionStorage8021D26C {char unknown00[8];};
struct MenuSelectionCursor8021D26C:MenuSelectionStorage8021D26C {
 virtual void unused0();
 virtual void unused1();
 virtual void unused2();
 virtual void unused3();
 virtual void unused4();
 virtual void unused5();
 virtual void unused6();
 virtual void unused7();
 virtual void unused8();
 virtual void unused9();
 virtual void unused10();
 virtual void unused11();
 virtual void unused12();
 virtual void unused13();
 virtual void unused14();
 virtual void unused15();
 virtual void unused16();

 virtual void notify(signed char,int);
 char unknown0C[0x1C]; short current,previous,first; char unknown2E[2];
 int mode; unsigned long unknown34; int count,capacity; MenuSelectionItem8021D26C**items;
 unsigned short desired,visible; signed char cycle;
 unsigned short getVisible()const{return visible;}
};
extern "C" {
 extern struct {char unknown00[0x110];void*logger;}lbl_801E9D24;
 extern const char lbl_802AE918[];
 int fn_8021DA0C(int,int);
 void fn_801FA014(void*,const char*,...);
}
extern "C" int fn_8021D26C(MenuSelectionCursor8021D26C*self) {

MenuSelectionCount8021D26C count(self->count);
MenuSelectionFound8021D26C found(0);
 self->previous=self->current;
 MenuSavedIndex8021D26C start(self->current);
 ++self->current;
 for(;;) {
  if(self->cycle) {
   if(self->current==start)break;
   self->current=(unsigned int)self->current%(unsigned int)count;
  }
  if(self->current>=(int)count)break;
  if((signed char)self->items[self->current]->selectable()){found=1;break;}
  ++self->current;
 }
 if(!found){self->current=self->previous;return 0;}
 switch(self->mode) {
 case 0:break;
 case 2:
  if(self->desired==1){self->visible=self->desired;self->first=self->current;break;}
  {
   int previous;
   do {
    previous=self->visible;
    int end=fn_8021DA0C(self->first+previous,self->count);
    self->visible=self->desired;
    for(int i=self->first;i<end;)if(self->items[i++]->flags&2)--self->visible;
    if(self->visible>=self->count)self->visible=self->count;
    if(self->first+self->visible<=self->current)self->first=self->current-self->visible+1;
    if(self->current<self->first)self->first=self->current;
    if(self->first+self->visible>=self->count)self->first=self->count-self->visible;
    if(self->getVisible()>2) {
     if(self->current>0 && self->current==self->first)--self->first;
     else if(self->current<self->count-1 && self->current==MenuVisibleCount8021D26C(self->getVisible())+self->first-1)++self->first;
    }
   }while(previous!=self->visible);
  }
  break;
 case 1:fn_801FA014(lbl_801E9D24.logger,lbl_802AE918);break;
 }
 self->notify(1,0);
 return 1;
}
