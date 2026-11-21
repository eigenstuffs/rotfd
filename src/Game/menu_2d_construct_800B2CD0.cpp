/* Native Menu2D construction; full observed factory extent 0x1A4.
 * See docs/notes/game-menu-2d-construction.md. */
typedef unsigned long Word;
struct Prefix {Word unknown00[2];};
struct MenuBase_8021D7E4:Prefix {
    MenuBase_8021D7E4(Word,unsigned char);
    virtual ~MenuBase_8021D7E4();
    char unknown0C[0x4C-0xC];
    unsigned short& field2C(){return *(unsigned short*)((char*)this+0x2C);}
    Word& field30(){return *(Word*)((char*)this+0x30);}
    unsigned char& field34(){return *(unsigned char*)((char*)this+0x34);}
};
struct Handle_801F7F10{Word word;Handle_801F7F10();~Handle_801F7F10();};
struct Zero_B2CD0:Handle_801F7F10{Zero_B2CD0(){word=0;}~Zero_B2CD0(){}};
struct Handle_80020B90:Zero_B2CD0{Handle_80020B90(){word=0;}~Handle_80020B90();};
extern "C" {extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);}
struct Handle_800723F4:Zero_B2CD0{Handle_800723F4(){word=0;}~Handle_800723F4(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}Handle_800723F4&operator=(const Handle_800723F4&);};
struct Object_800B2E40{int count,capacity;void*data;Object_800B2E40(){count=0;capacity=0;data=0;}~Object_800B2E40();};
struct Record {char data[20];};
struct Globals {char unknown00[0x118];void*manager;};
extern "C" {
extern Globals lbl_801E9D24;
extern const float lbl_803792F0,lbl_803792F4,lbl_803792F8,lbl_803792FC,lbl_80379300;
void fn_800B2E3C(void*,int);
void __construct_array(void*,void(*)(void*,int),void(*)(void*,int),Word,Word);
void fn_801F86C8(void*,const void*,int);
}
inline Handle_800723F4&Handle_800723F4::operator=(const Handle_800723F4&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);return*this;}
struct Object_800B4F28:MenuBase_8021D7E4 {
 Handle_80020B90 first4C;unsigned char flag50;char unknown51[0x13];float value64;
 Object_800B2E40 records68;Handle_800723F4 second74;float value78;unsigned char flag7C;char unknown7D[3];
 float values80[16];Record recordsC0[10];Word field188;char unknown18C[0x18];
 Object_800B4F28();virtual ~Object_800B4F28();
};
Object_800B4F28::Object_800B4F28():MenuBase_8021D7E4(0,255){
 __construct_array(recordsC0,fn_800B2E3C,0,sizeof(Record),10);
 field30()=0;flag50=0;field2C()=0;
 second74=Handle_800723F4();
 value64=lbl_803792F0;field34()=6;value78=lbl_803792F4;
 values80[0]=lbl_803792F0;values80[1]=lbl_803792F8;values80[2]=lbl_803792F8;values80[3]=lbl_803792F8;
 values80[4]=lbl_803792FC;values80[5]=lbl_803792FC;values80[6]=lbl_803792F0;values80[7]=lbl_803792F0;
 values80[8]=lbl_803792F0;values80[9]=lbl_803792F0;values80[10]=lbl_803792F8;values80[11]=lbl_803792F8;
 values80[12]=lbl_803792F0;values80[13]=lbl_80379300;values80[14]=lbl_80379300;values80[15]=lbl_803792F8;
 flag7C=0;field188=0;
}
typedef char Size[(sizeof(Object_800B4F28)==0x1A4)?1:-1];
