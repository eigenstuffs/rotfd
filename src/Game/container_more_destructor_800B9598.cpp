/* Typed pool cleanup with original compiler exception metadata.
 * See docs/notes/game-container-more-destructors.md. */
typedef unsigned long u32;
extern "C" {
extern char lbl_801EF5C8[],lbl_8028F698[],lbl_802EC720[],lbl_802EC6A0[],lbl_802BFA00[];
void fn_801EF610(void*,void*);void fn_8028FD50(void*,void*,int);
}
struct Handle_801F7F10{u32 word;~Handle_801F7F10();};
struct H1:Handle_801F7F10{~H1(){}};
struct H2:H1{~H2(){}};
struct H3:H2{~H3(){}};
struct Element{u32 word;~Element(){}};
struct Pool{int size,capacity;Element*data;~Pool(){if(data){for(int i=0;i<size;i++)data[i].~Element();if(data){fn_8028FD50(lbl_8028F698,data,capacity*4);data=0;}data=0;}}};
struct Object_8025F0D8{u32 unknown00[2];const void*vtable;char unknown0C[0x3C];~Object_8025F0D8();static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct ContainerPrefix:Object_8025F0D8{Pool pool48;u32 unknown54;H2 handle58;char unknown5C[4];~ContainerPrefix(){vtable=lbl_802EC720;}};
struct Object_800B9598:ContainerPrefix{char unknown60[4];H3 handle64;~Object_800B9598();};
Object_800B9598::~Object_800B9598(){vtable=lbl_802EC6A0;}
