/* Console callbacks and buffer lifecycle reconstructed from GSQE78.
 * See docs/notes/game-console-callbacks.md. */
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
extern "C" {
 extern GameGlobals lbl_801E9D24;
 extern char lbl_801EF5C8[];
 void fn_801EF610(void*,void*);
 void*fn_801EFA1C(void*,int,const char*,const char*,int,int);
 void*memset(void*,int,u32);
 void fn_801FA014(void*,const char*,...);
 void fn_801FADD0(void*);
 void fn_801F9D0C(void*);
 const char lbl_802AD5F0[]="Too much parameters";
 const char lbl_802AD604[]="Anonymous New";
 const char lbl_802AD614[]="Console_Z.cpp";
 void fn_801FB17C(Console*self){
  self->buffer=(char*)fn_801EFA1C(lbl_801EF5C8,0x6000,lbl_802AD604,lbl_802AD614,32,4);
  self->last_line=self->buffer;
  memset(self->buffer,0,0x6000);
 }
 void fn_801FB0F4(Console*self){
  ConsoleCommand*p=self->commands;
  while(p){ConsoleCommand*next=p->next;fn_801EF610(lbl_801EF5C8,p);p=next;}
  if(self->buffer)fn_801EF610(lbl_801EF5C8,self->buffer);
  self->buffer=0;self->last_line=0;self->interpreter=0;
 }
 void fn_801FB0BC(Console*self){if(self->interpreter)self->interpreter->update();}
 int fn_801FB078(){if(lbl_801E9D24.console->argc>1)return 0;fn_801F9D0C(lbl_801E9D24.console);return 1;}
 int fn_801FB028(){if(lbl_801E9D24.console->argc>1)fn_801FA014(lbl_801E9D24.console,lbl_802AD5F0);else fn_801FADD0(lbl_801E9D24.console);return 1;}
 int fn_801FAFE8(){lbl_801E9D24.console->mode(2);return 1;}
}
