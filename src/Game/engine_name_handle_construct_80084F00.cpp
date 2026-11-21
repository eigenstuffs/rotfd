#include "Game/state_native_operation_records_selected.h"
/* Original name-backed Handle construction; strict retained EH plus strong-owner backup audit.
 * See docs/notes/game-engine-name-handle-construct.md. */
typedef unsigned long u32;
struct Handle_801F7F10 {u32 word;Handle_801F7F10();~Handle_801F7F10();};
struct Manager;
struct Context {char unknown00[0x118];Manager*manager;};
extern "C" {extern Context lbl_801E9D24;void fn_801F86C8(Manager*,const Handle_801F7F10*,short);void fn_801EF610(void*,void*);extern char lbl_801EF5C8[];void fn_80090084(void*);extern char lbl_802B92B0[],lbl_8029D6A4[];extern const char lbl_80378AFC[4];u32 fn_801F948C(void*,const char*);}
struct ZeroHandle1_80084F00:Handle_801F7F10 {ZeroHandle1_80084F00(){word=0;}~ZeroHandle1_80084F00(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct ZeroHandle2_80084F00:ZeroHandle1_80084F00 {ZeroHandle2_80084F00(){word=0;}~ZeroHandle2_80084F00(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_8002F6B0:ZeroHandle2_80084F00 {Handle_8002F6B0(){word=0;}~Handle_8002F6B0(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80085054:Handle_8002F6B0 {
    Handle_80085054(int){word=0;}Handle_80085054(const Handle_801F7F10&v){word=v.word;fn_801F86C8(lbl_801E9D24.manager,&v,1);}~Handle_80085054(){}
    static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
    Handle_80085054&operator=(const Handle_801F7F10&v){Handle_80085054 h(v);fn_801F86C8(lbl_801E9D24.manager,this,-1);word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);return *this;}
};
struct Root {void*vtable;unsigned char enabled;char unknown05[3];Root(){fn_80090084(this);}~Root();};
struct Object_800814D0:Root {u32 value08,value0C;char unknown10[0x30];Object_800814D0(u32 a,u32 b){vtable=lbl_802B92B0;value08=0;value0C=0;value08=a;value0C=b;}~Object_800814D0();};
struct Name {u32 value;Name(const char*t){value=fn_801F948C(this,t);}};
extern "C" Handle_801F7F10 fn_801B550C(Manager*,const Name&,const Name&);
struct Object_80084F00:Object_800814D0 {Handle_80085054 handle40;unsigned char byte44,byte45,byte46;Object_80084F00(u32,u32);};
Object_80084F00::Object_80084F00(u32 a,u32 b):Object_800814D0(a,b),handle40((vtable=&lbl_802B8ED4,0)){byte44=0;byte45=0;byte46=0;enabled=1;handle40=fn_801B550C(lbl_801E9D24.manager,Name(lbl_8029D6A4),Name(lbl_80378AFC));}
