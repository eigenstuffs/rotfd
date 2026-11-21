#ifndef GAME_EARLY_HANDLE_COMMAND_VIEWS_H
#define GAME_EARLY_HANDLE_COMMAND_VIEWS_H
struct CommandHandle { signed int tag:8; signed int index:24; };
struct CommandPrefix { char unknown00[8]; };
struct CommandTarget:CommandPrefix {
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual void slot8();
virtual void slot9();
virtual void slot10();
virtual void slot11();
virtual void slot12();
virtual void slot13();
virtual void slot14(int);
virtual void slot15(int);
virtual void slot16();
virtual void slot17();
virtual void slot18();
virtual void slot19();
virtual void slot20();
virtual void slot21();
virtual void slot22();
virtual void slot23();
virtual void slot24();
virtual void slot25();
virtual void slot26();
virtual void slot27();
virtual void slot28();
virtual void slot29();
virtual void slot30();
virtual void slot31();
virtual void slot32();
virtual void slot33();
virtual void slot34();
virtual void slot35();
virtual void slot36();
virtual const CommandHandle*slot37(int);
};
struct CommandIntermediate {char unknown00[0x20];CommandHandle related;};
struct CommandActor {char unknown00[0x120];unsigned long flags;char unknown124[0x1F4];char record[0xC];};
struct CommandEntry {CommandActor*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct CommandManager {char unknown00[8];CommandEntry*entries;};
struct CommandIntermediateEntry {CommandIntermediate*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct CommandIntermediateManager {char unknown00[8];CommandIntermediateEntry*entries;};
struct CommandTargetEntry {CommandTarget*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct CommandTargetManager {char unknown00[8];CommandTargetEntry*entries;};
struct CommandContext {char unknown00[0x118];CommandManager*manager;};
extern "C" CommandContext lbl_801E9D24;
inline CommandActor*resolveCommand(const CommandHandle&h){int index=h.index;CommandManager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
inline CommandIntermediate*resolveIntermediate(const CommandHandle&h){int index=h.index;CommandIntermediateManager*m=(CommandIntermediateManager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
inline CommandTarget*resolveTarget(const CommandHandle&h){int index=h.index;CommandTargetManager*m=(CommandTargetManager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
struct CommandConditionalOwner {char unknown00[0x70];CommandHandle actor;};
struct CommandNode {char unknown00[0x58];CommandHandle owner;};
struct CommandOwner {char unknown00[0xC];CommandNode*node;};
extern "C" {signed char fn_8025E9FC(CommandConditionalOwner*,int);void fn_80286058(CommandConditionalOwner*,int);void fn_8007D6A0(void*,int);}
#endif
