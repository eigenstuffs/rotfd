typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Node;struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};struct Manager{char unknown00[8];Entry*entries;};
struct Service{char unknown00[0x1C];Handle_801F7F10*handle;};struct Config{char unknown00[0x60];Handle_801F7F10 handle;};struct State{char unknown00[0x15058];Config*config;};
struct Globals{char unknown00[0x110];void*console;char unknown114[4];Manager*manager;char unknown11C[8];State*state;char unknown128[0x14];Service*service;char unknown140[0xC];void*fonts;};
extern "C"{extern Globals lbl_801E9D24;extern Word lbl_803777D0;extern char lbl_801EF5C8[];extern const char agent_type_registry_CMsgBoxManipulator[];extern const char lbl_803794D0[4];void fn_801EF610(void*,void*);void fn_801F86C8(Manager*,const Handle_801F7F10*,int);Word fn_801F7EB8(const Handle_801F7F10*);Word fn_801F948C(void*,const char*);}
struct Zero1_BDA88:Handle_801F7F10{Zero1_BDA88(){word=0;}~Zero1_BDA88(){}};
struct Zero2_BDA88:Zero1_BDA88{Zero2_BDA88(){word=0;}~Zero2_BDA88(){}};
struct Zero3_BDA88:Zero2_BDA88{Zero3_BDA88(){word=0;}~Zero3_BDA88(){}};
struct Handle_80025BF4:Zero3_BDA88{Handle_80025BF4(){word=0;}~Handle_80025BF4(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80025B74:Handle_80025BF4{Handle_80025B74(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80025B74(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Name{Word value;Name(const char*t){value=fn_801F948C(this,t);}Name(const Name&n){value=n.value;}};
inline bool operator==(const Name&a,const Name&b){return a.value==b.value;}inline bool operator!=(const Name&a,const Name&b){return a.value!=b.value;}
struct Point{float x,y,z;Point(){}Point(const Point&p){x=p.x;y=p.y;z=p.z;}Point&operator=(const Point&p){x=p.x;y=p.y;z=p.z;return*this;}};
struct Rotation{float x,y,z,w;Rotation(){}Rotation(const Rotation&p){x=p.x;y=p.y;z=p.z;w=p.w;}Rotation&operator=(const Rotation&p){x=p.x;y=p.y;z=p.z;w=p.w;return*this;}};
extern "C"{extern Point lbl_80306E08;extern Rotation lbl_80306E14;}
struct Prefix{Word unknown00;Handle_801F7F10 self;};
struct Node:Prefix{
virtual void v8();
virtual void vC();
virtual void v10();
virtual void v14();
virtual void v18();
virtual void v1C();
virtual void v20();
virtual void v24();
virtual void v28();
virtual void v2C();
virtual void v30();
virtual void v34();
virtual void v38();
virtual void v3C();
virtual void v40();
virtual void v44();
virtual void v48();
virtual void v4C();
virtual void v50();
virtual void v54();
virtual void v58();
virtual void v5C();
virtual void v60();
virtual void v64();
virtual void v68();
virtual void v6C();
virtual void v70();
virtual void v74();
virtual void v78();
virtual void v7C();
virtual void v80();
virtual void v84();
virtual void v88();
virtual void v8C();
virtual void v90();
virtual void v94();
virtual void v98();
virtual void v9C();
virtual void vA0();
virtual void vA4();
virtual void vA8();
virtual void vAC();
virtual Point position(int);virtual void vB4();virtual Rotation rotation(int);
char unknown0C[0x18];Handle_801F7F10 parent;char unknown28[0x7C];Handle_801F7F10*selected;};
inline Node*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
inline Node*current(){return resolve(*lbl_801E9D24.service->handle);}
extern "C"{void fn_80285E10(Node*);void fn_802601C8(Node*,Node*,int);void fn_800A6234(Node*,int,Name);void fn_801FEE10(Service*,int);void fn_802022FC(Node*);int fn_80262DB8(void*,const char*);void fn_80200CBC(Node*,int,int);void fn_801FA1F0(void*,const char*);}
inline Word resolveWord(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?(Word)m->entries[index].object:0;}
struct PoolView{const char*data;PoolView(const char*p):data(p){}const char*at(Word offset)const{return data+offset;}};
extern "C"void fn_800BDA88(Node*self,const Name&first,const Name&second){
PoolView pool(agent_type_registry_CMsgBoxManipulator);lbl_803777D0=first.value;
const Handle_801F7F10&original=*current()->selected;Handle_80025B74 selected(original);
if(fn_801F7EB8(&selected)){
lbl_80306E08=resolve(selected)->position(0);
lbl_80306E14=resolve(selected)->rotation(0);
fn_80285E10(resolve(resolve(selected)->parent));
fn_802601C8(self,(Node*)resolveWord(resolve(selected)->parent),0);
}
Node*actor=resolve(lbl_801E9D24.state->config->handle);
fn_800A6234(actor,1,Name(Name(lbl_803794D0)));
fn_801FEE10(lbl_801E9D24.service,0);
fn_802022FC(current());
if(second!=Name(pool.at(0x1E0))){
if(second==Name(pool.at(0x1EC)))fn_80262DB8(lbl_801E9D24.fonts,pool.at(0xD38));
else if(second==Name(pool.at(0x21C)))fn_80262DB8(lbl_801E9D24.fonts,pool.at(0xD60));
else if(second==Name(pool.at(0x210)))fn_80262DB8(lbl_801E9D24.fonts,pool.at(0xD88));
else if(second==Name(pool.at(0x1F8)))fn_80262DB8(lbl_801E9D24.fonts,pool.at(0xDB0));
else if(second==Name(pool.at(0x204)))fn_80262DB8(lbl_801E9D24.fonts,pool.at(0xDD8));
}
fn_80200CBC(current(),0,1);
if(first==Name(pool.at(0x1E0)))fn_801FA1F0(lbl_801E9D24.console,pool.at(0xE00));
else if(first==Name(pool.at(0x1EC)))fn_801FA1F0(lbl_801E9D24.console,pool.at(0xE1C));
else if(first==Name(pool.at(0x21C)))fn_801FA1F0(lbl_801E9D24.console,pool.at(0xE38));
else if(first==Name(pool.at(0x210)))fn_801FA1F0(lbl_801E9D24.console,pool.at(0xE54));
else if(first==Name(pool.at(0x1F8)))fn_801FA1F0(lbl_801E9D24.console,pool.at(0xE70));
else if(first==Name(pool.at(0x204)))fn_801FA1F0(lbl_801E9D24.console,pool.at(0xE8C));
}
