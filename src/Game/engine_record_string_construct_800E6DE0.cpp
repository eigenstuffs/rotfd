typedef unsigned long u32;
extern "C" { extern char lbl_802C8E18[];extern const char lbl_803797F8[5]; int sprintf(char*,const char*,...); }
struct Record_800E6A58 {char opaque[0x3B5C]; Record_800E6A58(); ~Record_800E6A58();};
struct RecordTable {void*vtable;char header04[8];RecordTable(){vtable=lbl_802C8E18;}};
struct Object_800E6E68:RecordTable {Record_800E6A58 records0C[3];Object_800E6E68();~Object_800E6E68();};
Object_800E6E68::Object_800E6E68(){sprintf(header04,lbl_803797F8);for(int i=0;i<3;i++)header04[i+4]=0;}
typedef char ObjectSizeCheck[(sizeof(Object_800E6E68)==0xB220)?1:-1];
