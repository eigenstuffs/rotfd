/* Console flag and display callbacks reconstructed from GSQE78.
 * See docs/notes/game-console-controls.md. */
typedef unsigned long u32;
struct Console {char unknown[0x860];int argc;char*argv[16];signed char numeric[16];float values[16];};
struct GameStorage {char unknown[0x278];};
struct Game:GameStorage {
 virtual void unknown0();virtual void unknown1();virtual void unknown2();virtual void unknown3();virtual void unknown4();virtual void unknown5();
 virtual void update();
 virtual void unknown7();virtual void unknown8();virtual void unknown9();virtual void unknown10();virtual void unknown11();virtual void unknown12();virtual void unknown13();virtual void unknown14();virtual void unknown15();virtual void unknown16();virtual void unknown17();virtual void unknown18();virtual void unknown19();virtual void unknown20();virtual void unknown21();virtual void unknown22();virtual void unknown23();
 virtual void dimensions(int,int,int);
};
struct ControlEntry {char unknown[0x3C];int state;};
struct ControlList {int count,capacity;ControlEntry*entries;};
struct GameGlobals {char unknown[0x104];u32 flags;char unknown108[8];Console*console;Game*game;void*manager;char unknown11C[0x154-0x11C];ControlList*controls;};
extern "C" {
extern GameGlobals lbl_801E9D24;
void fn_801FA014(void*,const char*,...);
extern const char lbl_802AD658[];
extern const char lbl_802AD66C[];
extern const float lbl_8037A8A0[1];
int fn_801FB79C(){
 if(lbl_801E9D24.console->argc==2 && lbl_801E9D24.console->numeric[1]){ControlList*list=lbl_801E9D24.controls;int index=(int)lbl_801E9D24.console->values[1];
if(index<list->count){
ControlEntry*entry=&list->entries[index];
  if(entry->state==2)entry->state=4;else if(entry->state==4)entry->state=2;
  return 1;
 }}
 fn_801FA014(lbl_801E9D24.console,lbl_802AD66C);return 0;
}
int fn_801FB714(){
 if(lbl_801E9D24.console->argc!=2){fn_801FA014(lbl_801E9D24.console,lbl_802AD658);return 0;}
 if(lbl_801E9D24.console->numeric[1]){if(lbl_8037A8A0[0]==lbl_801E9D24.console->values[1])lbl_801E9D24.flags&=~8;else lbl_801E9D24.flags|=8;}
 return 1;
}
int fn_801FB68C(){
 if(lbl_801E9D24.console->argc!=2){fn_801FA014(lbl_801E9D24.console,lbl_802AD658);return 0;}
 if(lbl_801E9D24.console->numeric[1]){if(lbl_8037A8A0[0]==lbl_801E9D24.console->values[1])lbl_801E9D24.flags&=~4;else lbl_801E9D24.flags|=4;}
 return 1;
}
int fn_801FB5DC(){
 if(lbl_801E9D24.console->argc!=3){fn_801FA014(lbl_801E9D24.console,lbl_802AD66C);return 0;}
 if(!lbl_801E9D24.console->numeric[1])return 0;
 if(!lbl_801E9D24.console->numeric[2])return 0;
 lbl_801E9D24.game->dimensions(0,(int)lbl_801E9D24.console->values[1],(int)lbl_801E9D24.console->values[2]);return 1;
}
int fn_801FB594(){lbl_801E9D24.flags|=1;lbl_801E9D24.game->update();return 1;}
int fn_801FB50C(){
 if(lbl_801E9D24.console->argc!=2){fn_801FA014(lbl_801E9D24.console,lbl_802AD658);return 0;}
 if(lbl_801E9D24.console->numeric[1]){if(lbl_8037A8A0[0]==lbl_801E9D24.console->values[1])lbl_801E9D24.flags&=~2;else lbl_801E9D24.flags|=2;}
 return 1;
}
int fn_801FB504(){return 1;}
int fn_801FB4E8(){lbl_801E9D24.flags^=16;return 1;}
int fn_801FB4CC(){lbl_801E9D24.flags^=32;return 1;}
int fn_801FB4B0(){lbl_801E9D24.flags^=64;return 1;}
}
