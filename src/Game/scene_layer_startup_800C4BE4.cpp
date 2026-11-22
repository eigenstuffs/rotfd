typedef unsigned long u32;
extern "C" {
extern char lbl_801EF5C8[],lbl_8028F698[],lbl_802EC720[],lbl_802EC6A0[],lbl_802BFA00[];
void fn_801EF610(void*,void*);void fn_8028FD50(void*,void*,int);
}
struct Handle_801F7F10{u32 word;~Handle_801F7F10();};
struct StartupHandleOne:Handle_801F7F10{~StartupHandleOne(){}};
struct StartupHandleTwo:StartupHandleOne{~StartupHandleTwo(){}};
struct StartupHandleThree:StartupHandleTwo{~StartupHandleThree(){}};
struct StartupElement{u32 word;~StartupElement(){}};
struct StartupPool{int size,capacity;StartupElement*data;~StartupPool(){if(data){for(int i=0;i<size;i++)data[i].~StartupElement();if(data){fn_8028FD50(lbl_8028F698,data,capacity*4);data=0;}data=0;}}};
struct Object_8025F0D8{u32 unknown00[2];const void*vtable;char unknown0C[0x3C];~Object_8025F0D8();static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct StartupContainerPrefix:Object_8025F0D8{StartupPool pool48;u32 unknown54;StartupHandleTwo handle58;char unknown5C[4];~StartupContainerPrefix(){vtable=lbl_802EC720;}};
struct ContainerLayer_802EC6A0:StartupContainerPrefix {
    char unknown60[4];StartupHandleThree handle64;u32 word68,word6C;
    ContainerLayer_802EC6A0();
    ~ContainerLayer_802EC6A0(){vtable=lbl_802EC6A0;}
};
struct SceneLayer:ContainerLayer_802EC6A0 {
    SceneLayer(){vtable=lbl_802BFA00;}
    ~SceneLayer(){vtable=lbl_802BFA00;}
};
extern "C" {extern u32 lbl_803777F8; void fn_802558B8();
void fn_800C4BE4(){lbl_803777F8=0;fn_802558B8();SceneLayer layer;}}
