// Fixed arrays and their observed reset prefixes.
#include "Game/fixed_array_lifetime.h"
struct GroupHeader {u32 word0,word4,unknown8,wordC;char opaque10[9];unsigned char flag19,flag1A,flag1B;unsigned short indices[50];
 ~GroupHeader(){word0=0;word4=0;wordC=0;flag19=0;flag1A=0;flag1B=0;for(int i=0;i<50;i++)indices[i]=0;}
};
template<int N>struct Group:GroupHeader {Record_800E5F90 records[N];~Group(){}};
struct ShortArray {Record_800E69E4 records[300];~ShortArray(){}};
struct Record_800E6A58 {u32 word0,word4,word8,wordC;char opaque10[12];u32 word1C,word20,word24;unsigned short indices[100];Group<5> groupF0;Group<3> groupA80;Group<4> group1070,group1830,group1FF0;Group<5> group27B0;Group<4> group3140;ShortArray records3900;~Record_800E6A58();static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
Record_800E6A58::~Record_800E6A58(){word0=0;word4=0;word8=0;word1C=0;word20=0;word24=0;wordC=0;for(int i=0;i<100;i++)indices[i]=0;}
typedef char HeaderSize[(sizeof(GroupHeader)==0x80)?1:-1];
typedef char OwnerSize[(sizeof(Record_800E6A58)==0x3B58)?1:-1];
