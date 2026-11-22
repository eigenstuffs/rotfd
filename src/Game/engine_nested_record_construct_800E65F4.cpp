typedef unsigned long u32;
extern "C" {void __construct_array(void*,void*,void*,u32,u32);void fn_800E5F40(void*);void fn_800E6A48(void*);void __dt__15Record_800E5F90Fv(void*,int);void __dt__15Record_800E69E4Fv(void*,int);}
struct Object_800E5FF4 {u32 word0,word4,opaque8,wordC;unsigned char flags10[9],flag19,flag1A,flag1B;unsigned short indices1C[50];Object_800E5FF4(){word0=0;word4=0;wordC=0;flag19=0;flag1A=0;flag1B=0;for(int i=0;i<50;i++)indices1C[i]=0;for(int i=0;i<9;i++)flags10[i]=1;}~Object_800E5FF4();};
struct Object_800E6098:Object_800E5FF4 {char records80[2320];Object_800E6098(){__construct_array(records80,(void*)fn_800E5F40,(void*)__dt__15Record_800E5F90Fv,0x1D0,5);}~Object_800E6098();};
struct Object_800E615C:Object_800E5FF4 {char records80[1392];Object_800E615C(){__construct_array(records80,(void*)fn_800E5F40,(void*)__dt__15Record_800E5F90Fv,0x1D0,3);}~Object_800E615C();};
struct Object_800E6220:Object_800E5FF4 {char records80[1856];Object_800E6220(){__construct_array(records80,(void*)fn_800E5F40,(void*)__dt__15Record_800E5F90Fv,0x1D0,4);}~Object_800E6220();};
struct Object_800E62E4:Object_800E5FF4 {char records80[1856];Object_800E62E4(){__construct_array(records80,(void*)fn_800E5F40,(void*)__dt__15Record_800E5F90Fv,0x1D0,4);}~Object_800E62E4();};
struct Object_800E63A8:Object_800E5FF4 {char records80[1856];Object_800E63A8(){__construct_array(records80,(void*)fn_800E5F40,(void*)__dt__15Record_800E5F90Fv,0x1D0,4);}~Object_800E63A8();};
struct Object_800E646C:Object_800E5FF4 {char records80[2320];Object_800E646C(){__construct_array(records80,(void*)fn_800E5F40,(void*)__dt__15Record_800E5F90Fv,0x1D0,5);}~Object_800E646C();};
struct Object_800E6530:Object_800E5FF4 {char records80[1856];Object_800E6530(){__construct_array(records80,(void*)fn_800E5F40,(void*)__dt__15Record_800E5F90Fv,0x1D0,4);}~Object_800E6530();};
struct RecordPrefix {u32 word0,word4,word8,wordC;char opaque10[12];u32 word1C,word20,word24;unsigned short indices28[100];RecordPrefix(){word0=0;word4=0;word8=0;wordC=0;word1C=0;word20=0;word24=0;}};
struct ShortRecords {char records[600];ShortRecords(){__construct_array(records,(void*)fn_800E6A48,(void*)__dt__15Record_800E69E4Fv,2,300);}};
struct Record_800E6A58:RecordPrefix {Object_800E6098 groupF0;Object_800E615C groupA80;Object_800E6220 group1070;Object_800E62E4 group1830;Object_800E63A8 group1FF0;Object_800E646C group27B0;Object_800E6530 group3140;ShortRecords records3900;u32 word3B58;Record_800E6A58();~Record_800E6A58();};
Record_800E6A58::Record_800E6A58(){word3B58=0;for(int i=0;i<100;i++)indices28[i]=0;}
typedef char HeaderSizeCheck[(sizeof(Object_800E5FF4)==0x80)?1:-1];
typedef char RecordPrefixSizeCheck[(sizeof(RecordPrefix)==0xF0)?1:-1];
typedef char RecordSizeCheck[(sizeof(Record_800E6A58)==0x3B5C)?1:-1];
