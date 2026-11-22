typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct StateNode{char unknown00[0x98];Handle_801F7F10*child;char unknown9C[0x140];unsigned char state;};
struct StateEntry{StateNode*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct StateManager{int count,capacity;StateEntry*entries;};
struct StateRelated{char unknown00[0x1C];Handle_801F7F10*handle;};
extern "C" struct StateGlobals{char unknown00[0x118];StateManager*manager;char unknown11C[0x20];StateRelated*related;}lbl_801E9D24;
inline StateNode*resolve(const Handle_801F7F10&h){int index=h.bits.index;StateManager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
struct NestedReturn_8005112C:Handle_801F7F10{~NestedReturn_8005112C(){}};
extern "C" NestedReturn_8005112C fn_8004A6C8(StateNode*);
inline Word resolveValue(const Handle_801F7F10&h){int index=h.bits.index;StateManager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?(Word)m->entries[index].object:0;}
extern "C" void fn_8005112C(void*,unsigned char value){resolve(fn_8004A6C8((StateNode*)resolveValue(*resolve(*lbl_801E9D24.related->handle)->child)))->state=value;}
