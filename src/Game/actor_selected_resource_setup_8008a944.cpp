/* Select an actor resource group and resolve its three named children. */
typedef unsigned long Word;
struct Handle {union{Word value;struct{signed int tag:8,index:24;}bits;};};
struct Name {Word value;Name(const char*);};
struct Node {char unknown00[0x24];Handle owner;char unknown28[0x64-0x28];Handle resource;char unknown68[0x88-0x68];unsigned char state;char unknown89[0x1F0-0x89];Handle target;};
struct Owner:Node{};
struct Entry {Node*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager {int count,capacity;Entry*entries;};
struct Scene {char unknown00[0x15058];Node*owner;};
struct HandleArray {int count,capacity;Handle*elements;};
struct Actor {char unknown00[8];Node*parent;char unknown0C[0x40-0x0C];HandleArray selection;Node*first,*second,*third;};
extern "C" struct Context {char unknown00[0x118];Manager*manager;char unknown11C[8];Scene*scene;}lbl_801E9D24;
extern "C" {
 Word fn_801F948C(Name*,const char*);
 void fn_8024BDA0(Handle*,Node*,const Name&);
 void __dt__15Handle_801F7F10Fv(Handle*,int);
 const HandleArray*fn_8005AD58(Node*);
 void fn_8008AC5C(HandleArray*,const HandleArray*);
 void fn_802554F4(Node*);
 void fn_80255D88(Node*,int,int,int,int);
 extern __declspec(section ".sdata2") const char lbl_80378B50[],lbl_80378B58[];extern const char lbl_8029D7E4[];
}
inline Name::Name(const char*text){value=fn_801F948C(this,text);}
inline Node*resolve(const Handle&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
extern "C" void fn_8008A944(Actor*self){
 Owner*owner=(Owner*)resolve(self->parent->owner);
 fn_8008AC5C(&self->selection,fn_8005AD58(lbl_801E9D24.scene->owner));
 Node*target=resolve(resolve(owner->resource)->target);
 {Name name(lbl_80378B50);Handle child;fn_8024BDA0(&child,target,name);self->first=resolve(child);__dt__15Handle_801F7F10Fv(&child,0);}
 {Name name(lbl_80378B58);Handle child;fn_8024BDA0(&child,target,name);self->second=resolve(child);__dt__15Handle_801F7F10Fv(&child,0);}
 {Name name(lbl_8029D7E4);Handle child;fn_8024BDA0(&child,target,name);self->third=resolve(child);__dt__15Handle_801F7F10Fv(&child,0);}
 fn_802554F4(resolve(self->selection.elements[0]));
 fn_802554F4(resolve(self->selection.elements[1]));
 fn_80255D88(owner,0x79,15,0,0);owner->state=8;
}
