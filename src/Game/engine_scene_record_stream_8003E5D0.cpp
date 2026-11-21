/* Original scene record stream controls; see docs/notes/game-engine-scene-record-stream.md. */
struct Target{};struct Scene{char opaque00[0x15058];Target*first15058;};extern "C" struct Global{char opaque00[0x124];Scene*scene;}lbl_801E9D24;extern "C"{void fn_80056144(Target*);void fn_80056648(Target*,int);}
extern "C" int fn_8003E5D0(){Target*t=lbl_801E9D24.scene->first15058;for(int i=0;i<9;i++){fn_80056144(t);fn_80056648(t,i);}return 1;}
