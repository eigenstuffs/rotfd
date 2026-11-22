typedef unsigned long u32;
struct Manager; struct Handle_8002F6B0;
struct LoggerPrefix{char opaque00[0xB10];};struct Logger:LoggerPrefix{virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void control(int);};
struct Globals {char opaque00[0x110];Logger*logger110;char*lists114;Manager*manager118;};
extern "C" { extern Globals lbl_801E9D24; extern char lbl_801EF5C8[]; void fn_801EF610(void*,void*); void fn_801F86C8(Manager*,const void*,int); u32 fn_801F948C(void*,const char*); void fn_801E2074(void*,const Handle_8002F6B0&,int); void fn_801E1F3C(void*,const Handle_8002F6B0&); void fn_80213A18(void*); void fn_802139D8(void*); extern const char lbl_80379804[7]; extern const float lbl_8037980C,lbl_80379810; }
struct Handle_801F7F10 {u32 word; Handle_801F7F10(); ~Handle_801F7F10(); static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);} };
struct RecordZero_DispatchMore:Handle_801F7F10 {RecordZero_DispatchMore(){word=0;} ~RecordZero_DispatchMore(){} };
struct Handle_80021BCC:RecordZero_DispatchMore {Handle_80021BCC(){word=0;} ~Handle_80021BCC(){} };
struct Handle_8002F6B0:Handle_80021BCC {Handle_8002F6B0(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager118,&h,1);} ~Handle_8002F6B0(){} };
struct Handle_800723F4:RecordZero_DispatchMore {~Handle_800723F4(){} };
struct NameHash {u32 word; NameHash(const char*s){word=fn_801F948C(this,s);} };
extern "C" Handle_800723F4 fn_802631B0(void*,const NameHash&);
inline void assign(Handle_801F7F10&d,const Handle_801F7F10&s){fn_801F86C8(lbl_801E9D24.manager118,&d,-1);d.word=s.word;fn_801F86C8(lbl_801E9D24.manager118,&s,1);}
struct View {char opaque00[4];Handle_801F7F10 handle04;char opaque08[0x10];signed char flag18;char opaque19[7];float value20,value24;signed char flag28,flag29;char opaque2A[2];Handle_801F7F10 handle2C;};
extern "C" const float lbl_803795B0;
extern "C" void fn_800C3D44(View*self,int index){if(self->flag18){const Handle_801F7F10&original=self->handle04;fn_801E1F3C(lbl_801E9D24.lists114+index*0x4C,Handle_8002F6B0(original));fn_802139D8(self);}}
