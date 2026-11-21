/* Original early selection and type controls; see docs/notes/game-engine-early-selection-controls.md. */
typedef unsigned long long u64;
struct Handle_801F7F10{unsigned long word;Handle_801F7F10();~Handle_801F7F10();};
struct Owner{char opaque00[0x38];u64 flags38;};
extern "C" struct Global{char opaque00[0x118];void*manager;}lbl_801E9D24;
extern "C"{Handle_801F7F10 fn_801B52EC(void*,const char*);void fn_8025A3C8(Owner*,const Handle_801F7F10&);void fn_802597A4(Owner*);extern const char lbl_80299C68[],lbl_80299F58[];}
extern "C" void fn_80024F50(Owner*self){self->flags38&=~8ULL;fn_8025A3C8(self,fn_801B52EC(lbl_801E9D24.manager,lbl_80299C68));fn_802597A4(self);}
