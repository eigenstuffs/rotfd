#ifndef GAME_FIXED_ARRAY_LIFETIME_H
#define GAME_FIXED_ARRAY_LIFETIME_H
typedef unsigned long u32;
extern "C" {extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);}
struct Record_800E5F90 {char bytes[0x1D0];~Record_800E5F90();static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Record_800E69E4 {unsigned short value;~Record_800E69E4();static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
#endif
