typedef unsigned long Word;
extern "C"{void __ct__15Object_8009A9D8Fv(void*);void*fn_801EFA1C(void*,int,void*,void*,int,int);extern char lbl_801EF5C8[],lbl_802B93F4[],lbl_8029DC48[],lbl_8029DC58[];extern float game_quat_identity[4],game_vec3_zero[3];
extern const float lbl_80378BAC,lbl_80378BB0,lbl_80378BB4,lbl_80378BB8,lbl_80378BBC,lbl_80378BC0,lbl_80378BC4,lbl_80378BC8,lbl_80378BCC,lbl_80378BD0,lbl_80378BD4,lbl_80378BD8,lbl_80378BDC,lbl_80378BE0,lbl_80378BE4;}
struct Object_8009AA98{char unknown00[8];void*primaryTable;char unknown0C[0x30C];void*secondaryTable;char unknown31C[0x28];void*storage344;char unknown348[0xC];float value354;char unknown358[0xC];float value364,value368,value36C;float value370,value374,value378;char unknown37C[0x14];Object_8009AA98(){__ct__15Object_8009A9D8Fv(this);}~Object_8009AA98();};
struct Object_8009010C:Object_8009AA98{
 float quat390[4],quat3A0[4],quat3B0[4],point3C0[3],value3CC,value3D0,value3D4,value3D8,value3DC,value3E0,value3E4,value3E8,value3EC,value3F0,value3F4,point3F8[3];
 unsigned char byte404,byte405,byte406,byte407,byte408,byte409,byte40A,byte40B,byte40C,byte40D,byte40E,byte40F,byte410,byte411,byte412,unknown413;
 float point414[3];unsigned char byte420;char unknown421[3];float value424;Word reset428,reset42C;float value430;unsigned char byte434,byte435;char unknown436[2];Word reset438,reset43C,reset440;int index444;unsigned char byte448,byte449;char unknown44A[2];float point44C[3],value458;char unknown45C[4];Object_8009010C();
};
Object_8009010C::Object_8009010C(){
 primaryTable=lbl_802B93F4;secondaryTable=lbl_802B93F4+0x170;
 quat390[0]=game_quat_identity[0];quat390[1]=game_quat_identity[1];quat390[2]=game_quat_identity[2];quat390[3]=game_quat_identity[3];
 quat3A0[0]=game_quat_identity[0];quat3A0[1]=game_quat_identity[1];quat3A0[2]=game_quat_identity[2];quat3A0[3]=game_quat_identity[3];
 quat3B0[0]=game_quat_identity[0];quat3B0[1]=game_quat_identity[1];quat3B0[2]=game_quat_identity[2];quat3B0[3]=game_quat_identity[3];
 point3C0[0]=game_vec3_zero[0];point3C0[1]=game_vec3_zero[1];point3C0[2]=game_vec3_zero[2];
 value3CC=lbl_80378BAC;value3D0=lbl_80378BAC;value3D4=lbl_80378BAC;value3D8=lbl_80378BAC;value3DC=lbl_80378BAC;value3E0=lbl_80378BAC;value3E4=lbl_80378BAC;value3E8=lbl_80378BAC;value3EC=lbl_80378BAC;value3F0=lbl_80378BAC;
 point3F8[0]=lbl_80378BAC;point3F8[1]=lbl_80378BAC;point3F8[2]=lbl_80378BAC;
 byte404=0;byte405=1;byte406=1;byte407=0;byte408=0;byte409=0;byte40A=0;byte40B=0;byte40C=0;byte40D=0;byte40E=0;byte40F=0;byte410=0;byte411=0;byte412=0;
 point414[0]=game_vec3_zero[0];point414[1]=game_vec3_zero[1];point414[2]=game_vec3_zero[2];byte420=0;value424=lbl_80378BB0;reset428=0;reset42C=0;value430=lbl_80378BAC;byte434=0;byte435=0;reset43C=0;reset438=0;reset440=0;index444=-1;byte448=0;byte449=0;point44C[0]=game_vec3_zero[0];point44C[1]=game_vec3_zero[1];point44C[2]=game_vec3_zero[2];value458=lbl_80378BAC;
 storage344=fn_801EFA1C(lbl_801EF5C8,232,lbl_8029DC48,lbl_8029DC58,127,4);
 value3DC=lbl_80378BB4;value36C=lbl_80378BB8;value3E8=lbl_80378BBC;value370=lbl_80378BC0;value374=lbl_80378BC0;value3E0=lbl_80378BC4;value3E4=lbl_80378BC8;value378=lbl_80378BCC;value3F4=lbl_80378BD0;point3F8[0]=lbl_80378BD4;value354=lbl_80378BD8;value364=lbl_80378BDC;value368=lbl_80378BD4;value3EC=lbl_80378BE0;value3F0=lbl_80378BE4;value3D8=lbl_80378BD4;
}

typedef char EstablishedFactoryExtent_460[(sizeof(Object_8009010C)==0x460)?1:-1];
