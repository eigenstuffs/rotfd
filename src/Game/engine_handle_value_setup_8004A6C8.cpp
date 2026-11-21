/* Original engine Handle value construction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-handle-value-setup.md. */
typedef unsigned long u32;
struct Handle_801F7F10 {u32 word;Handle_801F7F10();~Handle_801F7F10();};
struct Manager;
struct Context {char unknown00[0x118];Manager*manager;char unknown11C[0x124-0x11C];void*scene;};
extern "C" {extern Context lbl_801E9D24;void fn_801F86C8(Manager*,const Handle_801F7F10*,short);}
struct H1:Handle_801F7F10 {H1(){word=0;}~H1();};
struct Handle_80020834:H1 {Handle_80020834(){word=0;}~Handle_80020834();};
struct H3:Handle_80020834 {H3(){word=0;}~H3();};
struct Handle_8004A72C:H3 {Handle_8004A72C(){word=0;}~Handle_8004A72C();};
struct H5:Handle_8004A72C {H5(){word=0;}~H5();};
struct H6:H5 {H6(){word=0;}~H6();};
struct H7:H6 {H7(){word=0;}~H7();};
struct Handle_8004099C:H7 {Handle_8004099C(){word=0;}~Handle_8004099C();};
struct Owner {char unknown00[0x60];Handle_801F7F10 handle60;};
struct Copy:Handle_8004A72C {Copy(const Handle_801F7F10&value){word=value.word;fn_801F86C8(lbl_801E9D24.manager,&value,1);}~Copy();};
extern "C" Copy fn_8004A6C8(const Owner*self){return Copy(self->handle60);}
