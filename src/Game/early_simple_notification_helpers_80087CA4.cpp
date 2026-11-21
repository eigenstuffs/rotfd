/* Original notification, virtual setup and string helpers; see docs/notes/game-early-simple-notification-helpers.md. */
struct Actor { char opaque[0x320]; int token320; };
struct Owner { char opaque[8]; Actor* actor8; void* controlC; };
struct Monitor { char opaque[0x130]; void* active130; };
extern "C" Monitor* lbl_803776B8;
extern "C" void fn_80257828(void*,int,int,int);
extern "C" void fn_8006803C(Monitor*,int);
extern "C" void fn_80087CA4(Owner* self) {
 fn_80257828(self->controlC,0x74,0x7c,0);
 if(lbl_803776B8 && lbl_803776B8->active130)fn_8006803C(lbl_803776B8,self->actor8->token320);
}
