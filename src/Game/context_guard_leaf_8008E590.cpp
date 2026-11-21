/* Original checked context forwarding; see docs/notes/game-context-guard-leafs.md. */
typedef unsigned long Word;
struct Node{char opaque00[0x320];void* data320;};
struct Owner{Word opaque00[2];Node*node;void*callback;char opaque10[0x30];float reset40;};
struct Context{char opaque00[0x130];void* guard130;void*guard134;};
extern "C" {extern Context*lbl_803776B8;extern const float lbl_80378AD0;void fn_8025795C(void*,int,int);void fn_8008CE2C(Owner*);void fn_80068158(Context*,void*);}
extern "C" void fn_8008E590(Owner*self){
 Context* context=lbl_803776B8;
 if(context && context->guard134) fn_80068158(context,self->node->data320);
}
