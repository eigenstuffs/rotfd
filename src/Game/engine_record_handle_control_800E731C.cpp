/* Original record Handle controls; see docs/notes/game-engine-record-handle-controls.md. */
typedef unsigned long u32;
struct Manager; struct Handle_8002F6B0;
struct Globals { char opaque00[0x114]; char*lists114; Manager*manager118; char opaque11C[0x30]; void*scope14C; };
extern "C" { extern Globals lbl_801E9D24; extern char lbl_801EF5C8[]; void fn_801EF610(void*,void*); void fn_801F86C8(Manager*,const void*,int); u32 fn_801F948C(void*,const char*); void fn_801E2074(void*,const Handle_8002F6B0&,int); void fn_801E1F3C(void*,const Handle_8002F6B0&); void fn_80213A18(void*); void fn_802139D8(void*); extern const char lbl_80379804[7]; extern const float lbl_8037980C,lbl_80379810; }
struct Handle_801F7F10 {u32 word; Handle_801F7F10(); ~Handle_801F7F10(); static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);} };
struct RecordHandleZero:Handle_801F7F10 {RecordHandleZero(){word=0;} ~RecordHandleZero(){} };
struct Handle_80021BCC:RecordHandleZero {Handle_80021BCC(){word=0;} ~Handle_80021BCC(){} };
struct Handle_8002F6B0:Handle_80021BCC {Handle_8002F6B0(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager118,&h,1);} ~Handle_8002F6B0(){} };
struct Handle_800723F4:RecordHandleZero {~Handle_800723F4(){} };
struct NameHash {u32 word; NameHash(const char*s){word=fn_801F948C(this,s);} };
extern "C" Handle_800723F4 fn_802631B0(void*,const NameHash&);
inline void assign(Handle_801F7F10&d,const Handle_801F7F10&s){fn_801F86C8(lbl_801E9D24.manager118,&d,-1);d.word=s.word;fn_801F86C8(lbl_801E9D24.manager118,&s,1);}
struct View {char opaque00[4];Handle_801F7F10 handle04;char opaque08[0x10];signed char flag18;char opaque19[7];int index20;Handle_801F7F10 handle24;float value28,value2C,value30;};
extern "C" void fn_800E731C(View*self){if(!self->flag18){const Handle_801F7F10&original=self->handle04;fn_801E2074(lbl_801E9D24.lists114,Handle_8002F6B0(original),0);fn_80213A18(self);}}
