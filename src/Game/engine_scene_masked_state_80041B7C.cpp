enum EventCode{Event05=0x5,Event06=0x6,Event07=0x7,Event08=0x8,Event09=0x9,Event0A=0xA,Event0B=0xB,Event0C=0xC,Event0D=0xD,Event0E=0xE,Event0F=0xF,Event10=0x10,Event11=0x11,Event12=0x12,Event13=0x13,Event14=0x14,Event15=0x15,Event16=0x16,Event17=0x17,Event18=0x18,Event19=0x19,Event1A=0x1A,Event1B=0x1B,Event1C=0x1C,Event1D=0x1D,Event1E=0x1E,Event97=0x97,Event98=0x98};
typedef unsigned long u32;struct Handle{union{u32 word;struct{signed int tag:8,index:24;}bits;};};struct Owner{char opaque00[0x70];Handle handle70;};struct Node{char opaque00[0x438];unsigned long long flags438;};struct Entry{Node*object;u32 opaque04,opaque08;signed char generation0C;char opaque0D[3];};struct Manager{int count,capacity;Entry*entries;};extern "C" struct Global{char opaque00[0x118];Manager*manager;}lbl_801E9D24;
extern "C"{signed char fn_8025E9FC(Owner*,int);void fn_80255D88(Owner*,int,int,int,int);}
inline Node*resolve(const Handle&h){Entry*e=&lbl_801E9D24.manager->entries[h.bits.index];return e->generation0C==h.bits.tag?e->object:0;}
extern "C" void fn_80041B7C(Owner*self){signed char flag=fn_8025E9FC(self,0xBF);int event;switch(resolve(self->handle70)->flags438&0x07800000ULL){
case 0x800000ULL:event=flag?Event05:Event12;break;
case 0x1000000ULL:event=flag?Event06:Event13;break;
case 0x1800000ULL:event=flag?Event08:Event15;break;
case 0x2000000ULL:event=flag?Event07:Event14;break;
case 0x2800000ULL:event=flag?Event09:Event16;break;
case 0x3000000ULL:event=flag?Event0A:Event17;break;
case 0x3800000ULL:event=flag?Event0B:Event18;break;
case 0x4000000ULL:event=flag?Event0C:Event19;break;
case 0x4800000ULL:event=flag?Event0D:Event1A;break;
case 0x5000000ULL:event=flag?Event0E:Event1B;break;
case 0x5800000ULL:event=flag?Event0F:Event1C;break;
case 0x6000000ULL:event=flag?Event10:Event1D;break;
case 0x6800000ULL:event=flag?Event97:Event98;break;
default:event=flag?Event11:Event1E;break;}fn_80255D88(self,event,0xF,0,0);}
