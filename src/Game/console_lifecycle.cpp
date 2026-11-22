typedef unsigned long u32;
struct ConsoleVTable {void*typeInfo;void*baseOffset;void(*methods[10])();};
extern "C" {extern char lbl_8028F698[],lbl_801EF5C8[];extern ConsoleVTable lbl_802EAF10;void fn_8028FD50(void*,void*,u32);void fn_801EF610(void*,void*);}
template<class T>struct Array {
 int size,capacity;T*data;
 void releaseStorage(){if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));data=0;}}
 ~Array(){if(data){for(int i=0;i<size;++i)data[i].~T();releaseStorage();data=0;}}
};
struct Line {u32 start,length;};
struct Console {
 char*buffer,*lastLine;int current;
 Array<Line>lines;
 char unknown18[0x3C-0x18];int field3C,field40,field44;u32 field48;int field4C,field50;
 void*commands;int historyCursor,historyCount;char history[16][128];
 int argc;char*argv[16];char numeric[16];float values[16];
 int field8F4;char unknown8F8[0xAF8-0x8F8];int fieldAF8;char unknownAFC[8];
 int mode,enabled;void*interpreter;const void*vtable;
};
struct HandleBits {u32 value;};
struct Handle_801F7F10:HandleBits {Handle_801F7F10();~Handle_801F7F10();};
struct ManagerStorage {int count;char unknown[0x24-4];};
struct Manager:ManagerStorage {
 virtual void unknown0();virtual void unknown1();virtual void unknown2();virtual void unknown3();virtual void unknown4();virtual void unknown5();virtual void unknown6();virtual void unknown7();
 virtual Handle_801F7F10 load(const char*);
};
struct GameStorage {char unknown[0x234];u32 flags;char unknown238[0x278-0x238];};
struct Game:GameStorage {
 virtual void unknown0();virtual void unknown1();virtual void unknown2();virtual void unknown3();virtual void unknown4();virtual void unknown5();virtual void unknown6();virtual void unknown7();virtual void unknown8();virtual void unknown9();virtual void unknown10();virtual void unknown11();virtual void unknown12();virtual void unknown13();virtual void unknown14();virtual void unknown15();virtual void unknown16();virtual void unknown17();virtual void unknown18();virtual void unknown19();virtual void unknown20();virtual void unknown21();virtual void unknown22();virtual void unknown23();virtual void unknown24();
 virtual void setPicture(const HandleBits&);
};
struct Globals {char unknown[0x110];Console*console;Game*game;Manager*manager;};
extern "C" {extern Globals lbl_801E9D24;extern const char lbl_802AD628[],lbl_802AD638[],lbl_802AD64C[];void fn_801FA014(Console*,const char*,...);int sprintf(char*,const char*,...);void fn_801F86C8(Manager*,const HandleBits*,int);void*fn_801F7EB8(const HandleBits*);}
namespace {
struct HandleLayer:Handle_801F7F10 {HandleLayer(){value=0;}};
struct PictureHandle:HandleLayer {PictureHandle(const Handle_801F7F10&h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}};
}
extern "C" {
int fn_801FB37C(){
 char name[128];
 if(lbl_801E9D24.console->argc<2){fn_801FA014(lbl_801E9D24.console,lbl_802AD638);return 0;}
 sprintf(name,lbl_802AD64C,lbl_801E9D24.console->argv[1]);
 PictureHandle handle(lbl_801E9D24.manager->load(name));
 if(fn_801F7EB8(&handle)){
  lbl_801E9D24.game->flags&=~2;
  lbl_801E9D24.game->setPicture(handle);
  return 1;
 }
 return 0;
}int fn_801FB338(){fn_801FA014(lbl_801E9D24.console,lbl_802AD628,lbl_801E9D24.manager->count);return 1;}
Console*fn_801FB2D4(Console*self){
 self->vtable=&lbl_802EAF10;
 self->lines.size=0;self->lines.capacity=0;self->lines.data=0;
 self->current=0;self->historyCount=0;self->historyCursor=-1;self->commands=0;self->mode=2;self->enabled=1;
 self->field3C=0;self->field40=0;self->field44=0;self->field4C=0;self->field50=0;self->interpreter=0;self->field8F4=0;self->fieldAF8=0;
 return self;
}
Console*fn_801FB1E8(Console*self,short flag){
 if(self){self->vtable=&lbl_802EAF10;self->lines.~Array<Line>();if(flag>0)fn_801EF610(lbl_801EF5C8,self);}
 return self;
}

}

/* Observed virtual table; method identities retain their versioned labels. */
extern "C" {
void fn_801EBAC8();void fn_801FAE50();void fn_801F01AC();void fn_801F01BC();void fn_800C4500();void fn_800C46C4();void fn_801FAE54();void fn_801F9D60();void fn_801F9D64();
ConsoleVTable lbl_802EAF10={0,0,{(void(*)())fn_801FB1E8,fn_801EBAC8,fn_801FAE50,fn_801F01AC,fn_801F01BC,fn_800C4500,fn_800C46C4,fn_801FAE54,fn_801F9D60,fn_801F9D64}};
}
