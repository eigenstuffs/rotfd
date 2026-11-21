/* Original record Handle controls; see docs/notes/game-engine-record-handle-controls.md. */
typedef unsigned long u32;
struct Manager; struct Handle_8002F6B0;
struct LoggerPrefix{char opaque00[0xB10];};struct Logger:LoggerPrefix{virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void control(int);virtual void finish(int);};
struct InputPrefix{char opaque00[0x1C];};struct Input:InputPrefix{virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();virtual void slot6();virtual signed char query(int);};
struct Globals {char opaque00[0x110];Logger*logger110;char*lists114;Manager*manager118;char opaque11C[0x38];Input*input154;};
extern "C" { extern Globals lbl_801E9D24; extern char lbl_801EF5C8[]; void fn_801EF610(void*,void*); void fn_801F86C8(Manager*,const void*,int); u32 fn_801F948C(void*,const char*); void fn_801E2074(void*,const Handle_8002F6B0&,int); void fn_801E1F3C(void*,const Handle_8002F6B0&); void fn_80213A18(void*); void fn_802139D8(void*); extern const char lbl_80379804[7]; extern const float lbl_8037980C,lbl_80379810; }
struct Handle_801F7F10 {u32 word; Handle_801F7F10(); ~Handle_801F7F10(); static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);} };
struct RecordZero_C4570:Handle_801F7F10 {RecordZero_C4570(){word=0;} ~RecordZero_C4570(){} };
struct Handle_80021BCC:RecordZero_C4570 {Handle_80021BCC(){word=0;} ~Handle_80021BCC(){} };
struct Handle_8002F6B0:Handle_80021BCC {Handle_8002F6B0(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager118,&h,1);} ~Handle_8002F6B0(){} };
struct Handle_800723F4:RecordZero_C4570 {~Handle_800723F4(){} };
struct NameHash {u32 word; NameHash(const char*s){word=fn_801F948C(this,s);} };
extern "C" Handle_800723F4 fn_802631B0(void*,const NameHash&);
inline void assign(Handle_801F7F10&d,const Handle_801F7F10&s){fn_801F86C8(lbl_801E9D24.manager118,&d,-1);d.word=s.word;fn_801F86C8(lbl_801E9D24.manager118,&s,1);}
struct View {char opaque00[4];Handle_801F7F10 handle04;char opaque08[0x10];signed char flag18;char opaque19[7];float value20,value24;signed char flag28,flag29;char opaque2A[2];Handle_801F7F10 handle2C;};
extern "C" const float lbl_803795B0;
extern "C" void fn_800C4570(View*self,float delta){self->value24+=delta;if(self->flag28){self->value24=lbl_803795B0;if(lbl_801E9D24.input154->query(11))self->flag28=0;}else if(self->value24>self->value20){lbl_801E9D24.logger110->finish(2);const Handle_801F7F10&original=self->handle04;fn_801E1F3C(lbl_801E9D24.lists114+0x1C8,Handle_8002F6B0(original));fn_802139D8(self);}else if(self->flag29){if(lbl_801E9D24.input154->query(2))self->value20=lbl_803795B0;}}
