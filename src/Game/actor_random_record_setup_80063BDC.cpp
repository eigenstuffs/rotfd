/* Randomized scene record setup and conditional actor resource activation.
 * See docs/notes/game-actor-random-record-setup.md. */
typedef unsigned long Word;typedef unsigned long long Wide;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Node;struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};struct Manager{char unknown00[8];Entry*entries;};
struct Controller{char unknown00[0xF0];int state,mode;};struct Panel{char unknown00[0x15058];Controller*controller;};extern "C" struct Global{char unknown00[0x118];Manager*manager;char unknown11C[8];Panel*panel;}lbl_801E9D24;
extern "C"{void fn_801EF610(void*,void*);extern char lbl_801EF5C8[];extern const float lbl_80378704,lbl_80378708,lbl_8037870C,lbl_80378710,lbl_80378714,lbl_80378718,lbl_803786F8,lbl_803786FC;extern const char lbl_8037871C[8],lbl_80378724[8];float fn_801F1200();int fn_801F1224(int,int);int sprintf(char*,const char*,...);void fn_80069078(void*,int);}
struct RecordZero_63BDC1:Handle_801F7F10{~RecordZero_63BDC1(){}};struct RecordZero_63BDC2:RecordZero_63BDC1{~RecordZero_63BDC2(){}};struct RecordZero_63BDC3:RecordZero_63BDC2{~RecordZero_63BDC3(){}};
struct Record_800218F8{float f00,f04,f08,f0C,f10,f14,f18,f1C,f20;char unknown24[0x68];RecordZero_63BDC3 first,second;Record_800218F8();~Record_800218F8(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Point{float x,y,z;Point(float a,float b,float c):x(a),y(b),z(c){}void set(float a,float b,float c){x=a;y=b;z=c;}Point(const Point&p){set(p.x,p.y,p.z);}};struct Origin{char unknown00[0x30];Point position;};
struct Prefix{char unknown00[8];};struct Node:Prefix{virtual void v08();virtual void v0C();virtual void v10();virtual void v14();virtual void v18();virtual void v1C();virtual void v20();virtual void v24();virtual void v28();virtual void v2C();virtual void v30();virtual void v34();virtual void activate();char unknown0C[0x24];Wide flags;char unknown38[0xEC];Origin*origin;};
struct Self{char unknown00[0x38];Wide flags;char unknown40[0x18];Handle_801F7F10 parent;char unknown5C[0x34];char counter[4];char unknown94[0x15C];void*resource;Handle_801F7F10 child;signed char enabled;};
struct Returned_63BDC:Handle_801F7F10{Returned_63BDC();~Returned_63BDC(){}};
struct Name{Word value;Name(const char*);};extern "C"Word fn_801F948C(Name*,const char*);inline Name::Name(const char*s){value=fn_801F948C(this,s);}
extern "C"{void fn_8022F49C(Node*,const Record_800218F8*);void fn_80213A18(Node*);void fn_80255D88(Self*,void*,int,int,int);Returned_63BDC fn_80058778(Controller*,const Name&,int);void fn_802554F4(Node*);void fn_80254BB4(Node*,const Point*);}
inline Node*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
extern "C"void fn_80063BDC(Self*self){
 int eligible=0;Controller*c=lbl_801E9D24.panel->controller;int mode=c->mode,state=c->state;
 if((mode==1&&state==6)||(mode==4&&state==0)||(mode==0&&state==4)||(mode==0&&state==7))eligible=1;
 signed char special=eligible;Record_800218F8 record;record.f18=lbl_80378704;record.f0C=lbl_80378708*(lbl_8037870C*fn_801F1200());record.f10=lbl_80378714*fn_801F1200()+lbl_80378710;record.f14=lbl_80378718;record.f20=lbl_803786F8;
 self->flags|=0x8000;fn_80069078(self->counter,0);resolve(self->child)->flags&=0xFFFFFFFF7E0001FFULL;fn_8022F49C(resolve(self->child),&record);fn_80213A18(resolve(self->child));if(self->resource)fn_80255D88(self,self->resource,15,0,0);
 if(self->enabled&&special){char text[12];if(fn_801F1224(0,1)==0)sprintf(text,lbl_8037871C);else sprintf(text,lbl_80378724);Node*target=resolve(fn_80058778(lbl_801E9D24.panel->controller,Name(text),1));if(target){target->activate();fn_802554F4(target);const Point&position=Point(resolve(self->parent)->origin->position);Point next(position.x+lbl_803786FC,position.y+lbl_803786F8,position.z+lbl_803786FC);fn_80254BB4(target,&next);}}
}
