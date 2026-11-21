/* Named scene actor queries, setup and virtual forwarding.
 * See docs/notes/game-early-named-scene-setup.md. */
typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Returned_E5918:Handle_801F7F10{Returned_E5918();~Returned_E5918(){}};
struct Prefix_E5918{char unknown00[8];};
struct Node_E5918:Prefix_E5918{
virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();virtual void slot8();virtual void slot9();virtual void slot10();virtual void activate();virtual void slot12();virtual void slot13();virtual void slot14();virtual void slot15();virtual void slot16();virtual void slot17();virtual void slot18();virtual void slot19();virtual void slot20();virtual void slot21();virtual void slot22();virtual void slot23();virtual void slot24();virtual void slot25();virtual void slot26();virtual void slot27();virtual void apply(Node_E5918*,Node_E5918*);
char unknown0C[0x2C];unsigned long long flags;char unknown40[0x1B0];Handle_801F7F10 parent;
};
struct Entry_E5918{Node_E5918*object;char unknown04[8];signed char tag;char unknown0D[3];int generation()const{return tag;}};struct Manager_E5918{int count,capacity;Entry_E5918*entries;};
struct Mode_E5918{char unknown00[0xF0];int mode;};struct Scene_E5918{char unknown00[0x15058];Mode_E5918*mode;};struct Globals_E5918{char unknown00[0x118];Manager_E5918*manager;char unknown11C[8];Scene_E5918*scene;};
struct Resource_E5918{char unknown00[0x58];Handle_801F7F10 related58;char unknown5C[8];Handle_801F7F10 related64;};
struct Owner_E5918{char unknown00[0xC];Resource_E5918*resource;char unknown10[0x32];signed char active;char unknown43;signed char selected;char unknown45[3];Node_E5918*second,*first;};
extern "C"{extern Globals_E5918 lbl_801E9D24;extern const char lbl_802AB0E0[];extern const char lbl_803797E0[5];Word fn_801F948C(void*,const char*);void fn_802554F4(Node_E5918*);}
struct Name_E5918{Word word;Name_E5918(const char*s){word=fn_801F948C(this,s);}};
extern "C"{Returned_E5918 fn_80058778(Mode_E5918*,const Name_E5918&,signed char);Returned_E5918 fn_8024BDA0(Node_E5918*,const Name_E5918&);}
inline Node_E5918*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager_E5918*m=lbl_801E9D24.manager;int generation=m->entries[index].generation();if(generation==h.bits.tag)return m->entries[index].object;return 0;}
extern "C"void fn_800E5918(Owner_E5918*self){
const Word strings=(Word)lbl_802AB0E0;
resolve(fn_80058778(lbl_801E9D24.scene->mode,Name_E5918((const char*)(strings+0x24)),0));
resolve(fn_80058778(lbl_801E9D24.scene->mode,Name_E5918((const char*)(strings+0x38)),0));
self->active=1;self->selected=lbl_801E9D24.scene->mode->mode==6;
if(self->selected){
Node_E5918*first=resolve(fn_80058778(lbl_801E9D24.scene->mode,Name_E5918((const char*)(strings+0x54)),0));
if(first){
self->first=first;
Node_E5918*parent=resolve(resolve(self->resource->related64)->parent);
Node_E5918*other=resolve(fn_8024BDA0(parent,Name_E5918(lbl_803797E0)));
self->first->flags|=0x20000ULL;
self->first->apply(resolve(self->resource->related58),other);
fn_802554F4(self->first);self->first->activate();
}
Node_E5918*second=resolve(fn_80058778(lbl_801E9D24.scene->mode,Name_E5918((const char*)(strings+0x68)),0));
if(second){self->second=second;self->second->flags|=0x20000ULL;fn_802554F4(self->second);self->second->activate();}
}}
