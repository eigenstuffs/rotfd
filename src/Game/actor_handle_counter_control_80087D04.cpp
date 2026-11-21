/* Actor Handle pair and counter control; see docs/notes/game-actor-handle-pair-controls.md. */
typedef unsigned long Word;typedef unsigned long long Wide;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Context{char unknown0[0x118];void*manager;};extern "C"{extern Context lbl_801E9D24;extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(void*,const Handle_801F7F10*,int);Word fn_801F7EB8(const Handle_801F7F10*);}
struct Zero1_80087D04:Handle_801F7F10{Zero1_80087D04(){word=0;}~Zero1_80087D04(){}};
struct Zero2_80087D04:Zero1_80087D04{Zero2_80087D04(){word=0;}~Zero2_80087D04(){}};
struct Zero3_80087D04:Zero2_80087D04{Zero3_80087D04(){word=0;}~Zero3_80087D04(){}};
struct Handle_80025BF4:Zero3_80087D04{Handle_80025BF4(){word=0;}~Handle_80025BF4(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80025B74:Handle_80025BF4{Handle_80025B74(){word=0;}~Handle_80025B74(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80038014:Handle_80025B74{Handle_80038014(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}Handle_80038014(const Handle_80038014&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80038014(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Counter{int value;};
struct Actor{char unknown0[0x30];Wide flags;char unknown38[0x1AC-0x38];Handle_801F7F10 handle;char unknown1B0[0x318-0x1B0];Counter counter;char unknown31C[0x410-0x31C];signed char enabled;};
struct Owner{char unknown0[8];Actor*actor;};
extern "C"{void fn_80229098(Actor*,const Handle_80025BF4&);int fn_80092844(Actor*);void fn_8007D6A0(Counter*,int);}
extern "C"void fn_80087D04(Owner*self){if(self->actor->enabled){Handle_80038014 target(Handle_80038014(self->actor->handle));if(!fn_801F7EB8(&target)){fn_80229098(self->actor,Handle_80025BF4());self->actor->flags&=0xFFFFFFFF7FFFFFFFULL;fn_8007D6A0(&self->actor->counter,fn_80092844(self->actor));}fn_8007D6A0(&self->actor->counter,0x18);}}
