typedef unsigned long u32;
struct ConsoleCommand {char name[64],help[128],alias[16];signed char(*callback)();ConsoleCommand*next,*prev;};
struct InterpreterStorage {u32 unknown[2];};
struct Interpreter:InterpreterStorage {
 virtual void unknown0();virtual void unknown1();virtual void unknown2();virtual void unknown3();virtual void unknown4();virtual void update();
};
struct ConsoleStorage {
 char *buffer,*last_line;char unknown8[0x54-8];ConsoleCommand*commands;
 char unknown58[0x860-0x58];int argc;char*argv[16];char numeric[16];float values[16];
 char unknown8F4[0xB0C-0x8F4];Interpreter*interpreter;
};
struct Console:ConsoleStorage {
 virtual void unknown0();virtual void unknown1();virtual void unknown2();virtual void unknown3();virtual void unknown4();virtual void mode(int);
};
struct GameGlobals{char unknown[0x110];Console*console;void*unknown114;void*manager;};

struct File {unsigned long words[23];};
struct HandleBits {union {u32 value;struct {signed int generation:8;signed int index:24;} fields;};};
struct Handle_801F7F10:HandleBits {Handle_801F7F10();~Handle_801F7F10();};
struct ResourceEntry {Interpreter*object;u32 unused[2];signed char generation;char padding[3];};
struct Manager {u32 unused[2];ResourceEntry*entries;};
extern "C" {
extern GameGlobals lbl_801E9D24;
extern const char lbl_802AD5E0[]="ConsoleInterp";
void __ct__13File_801F3E1CFv(File*);
void __dt__13File_801F3E1CFv(File*,short);
void*memcpy(void*,const void*,u32);
u32 fn_801F948C(u32*,const char*);

void fn_801F86C8(void*,const HandleBits*,int);
void fn_802139D8(Interpreter*);
void fn_801F9AD4(Interpreter*,const char*);
}
extern "C" void fn_801B550C(HandleBits*,void*,u32*,u32*);
extern "C" void __dt__15Handle_801F7F10Fv(HandleBits*,short);
namespace {
struct FirstLayer:Handle_801F7F10 {FirstLayer(){value=0;}};
struct HandleLayer:FirstLayer {HandleLayer(){value=0;}};
struct InterpreterHandle:HandleLayer {
 InterpreterHandle(const HandleBits&h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}
};
}
extern "C" {
int fn_801FAE58(){
 File file;char*argv[16];float values[16];char numeric[16];
 __ct__13File_801F3E1CFv(&file);
 memcpy(argv,lbl_801E9D24.console->argv,64);
 memcpy(numeric,lbl_801E9D24.console->numeric,16);
 memcpy(values,lbl_801E9D24.console->values,64);
 Console*self=lbl_801E9D24.console;char*argument=argv[1];
 if(!self->interpreter){
  HandleBits temporary;u32 name1,name2;
  name1=fn_801F948C(&name1,lbl_802AD5E0);
  name2=fn_801F948C(&name2,lbl_802AD5E0);
  fn_801B550C(&temporary,lbl_801E9D24.manager,&name2,&name1);
  InterpreterHandle handle(temporary);
  __dt__15Handle_801F7F10Fv(&temporary,-1);
  ResourceEntry*entry=((Manager*)lbl_801E9D24.manager)->entries+handle.fields.index;
  self->interpreter=entry->generation==handle.fields.generation?entry->object:0;
  fn_802139D8(self->interpreter);
 }
 fn_801F9AD4(self->interpreter,argument);
 __dt__13File_801F3E1CFv(&file,-1);
 return 1;
}
}
