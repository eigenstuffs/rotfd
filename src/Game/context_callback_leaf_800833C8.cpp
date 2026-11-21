/* Original checked context callback; see docs/notes/game-context-callback-leafs.md. */
typedef unsigned long Word;
struct Node{char opaque00[0x320];void* data320;};
struct Owner{Word opaque00[2];Node*node;void*callback;};
struct Context{char opaque00[0x130];void* guard130;void*guard134;};
extern "C" {extern Context*lbl_803776B8;void fn_8025795C(void*,int,int);void fn_8008CE2C(Owner*);void fn_8006803C(Context*,void*);}
extern "C" void fn_800833C8(Owner*self){
 fn_8025795C(self->callback,0x1b,0);
 Context* context=lbl_803776B8;
 if(context && context->guard130) fn_8006803C(context,self->node->data320);
}
