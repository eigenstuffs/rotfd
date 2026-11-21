#ifndef GAME_ENGINE_MENU_MEMBER_CTORS_H
#define GAME_ENGINE_MENU_MEMBER_CTORS_H

struct MenuMemberPrefix {unsigned long unknown00[2];};
struct MenuBase_8021D7E4:MenuMemberPrefix {MenuBase_8021D7E4(unsigned long,unsigned char);virtual ~MenuBase_8021D7E4();char unknown0C[0x4C-0x0C];};
struct Handle_801F7F10 {unsigned long value;Handle_801F7F10();~Handle_801F7F10();};
struct MenuMemberZero:Handle_801F7F10 {MenuMemberZero(){value=0;}};
struct MenuMemberTwoZero:MenuMemberZero {MenuMemberTwoZero(){value=0;}};
struct MenuMemberArray {int count,capacity;void*data;MenuMemberArray(){count=0;capacity=0;data=0;}};
struct MenuPair_802EB2F0:MenuBase_8021D7E4 {MenuMemberArray array;MenuMemberTwoZero first,second;MenuPair_802EB2F0();virtual ~MenuPair_802EB2F0();};
struct MenuArray_802EB348:MenuBase_8021D7E4 {MenuMemberTwoZero first,second;char unknown54[5];unsigned char flag;char unknown5A[0x78-0x5A];MenuMemberArray array;MenuArray_802EB348();virtual ~MenuArray_802EB348();};

typedef char MenuMemberBaseSize[(sizeof(MenuBase_8021D7E4)==0x4C)?1:-1];
typedef char MenuPairSize[(sizeof(MenuPair_802EB2F0)==0x60)?1:-1];
typedef char MenuArraySize[(sizeof(MenuArray_802EB348)==0x84)?1:-1];

#endif
