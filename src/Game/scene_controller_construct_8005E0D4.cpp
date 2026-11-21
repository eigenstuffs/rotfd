/* Native Object_8005E258 construction; see docs/notes/game-scene-controller-construction.md. */
typedef unsigned long Word;
struct Handle_801F7F10 {Word word;Handle_801F7F10();~Handle_801F7F10();};
struct Zero_E0D4:Handle_801F7F10 {Zero_E0D4(){word=0;}~Zero_E0D4();};
struct Handle_80021B54:Zero_E0D4 {Handle_80021B54(int){word=0;word=0;}~Handle_80021B54();};
extern "C"{extern char lbl_802B5748[];extern const float lbl_80378650;void fn_8005E240(void*);void __construct_array(void*,void(*)(void*),void(*)(void*),unsigned long,unsigned long);}
struct Ref;
struct Record_8005E240 {unsigned char flag00;char unknown01[3];float value04;unsigned char flag08;char unknown09[3];};
struct Object_8005E258 {
 Word unknown00;void*table;char unknown08[0x10];Word field18,field1C,field20;char unknown24[0x14];
 Handle_80021B54 handle38;unsigned char field3C;char unknown3D[3];Ref*field40;unsigned char field44,field45;char unknown46[2];float field48;
 Word array4C[10];unsigned char flags74[17];char unknown85[3];Record_8005E240 records88[11];Ref*array10C[17];
 unsigned char field150,field151,field152,field153,field154;char unknown155;unsigned short field156;unsigned char field158;char unknown159[7];
 Object_8005E258();
};
Object_8005E258::Object_8005E258():handle38((table=lbl_802B5748,field18=0,field1C=0,field20=0,0)){
 field3C=0;field45=0;field48=lbl_80378650;
 flags74[0]=0;
 flags74[1]=0;
 flags74[2]=0;
 flags74[3]=0;
 flags74[4]=0;
 flags74[5]=0;
 flags74[6]=0;
 flags74[7]=0;
 flags74[8]=0;
 flags74[9]=0;
 flags74[10]=0;
 flags74[11]=0;
 flags74[12]=0;
 flags74[13]=0;
 flags74[14]=0;
 flags74[15]=0;
 flags74[16]=0;
 __construct_array(records88,fn_8005E240,0,12,11);
 field150=0;field151=0;field152=1;field153=1;field154=1;field156=100;field158=0;field40=0;
 array10C[0]=0;
 array10C[1]=0;
 array10C[2]=0;
 array10C[3]=0;
 array10C[4]=0;
 array10C[5]=0;
 array10C[6]=0;
 array10C[7]=0;
 array10C[8]=0;
 array10C[9]=0;
 array10C[10]=0;
 array10C[11]=0;
 array10C[12]=0;
 array10C[13]=0;
 array10C[14]=0;
 array10C[15]=0;
 array10C[16]=0;
 field44=0;for(unsigned char i=0;i<10;i++)array4C[i]=0;
}
typedef char Object_extent[(sizeof(Object_8005E258)==0x160)?1:-1];
typedef char Record_extent[(sizeof(Record_8005E240)==12)?1:-1];
