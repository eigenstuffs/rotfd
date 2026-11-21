/* Original checked context callback; see docs/notes/game-context-callback-leafs.md. */
typedef unsigned long Word;
struct Node{char opaque00[0x320];void* data320;};
struct Owner{Word opaque00[2];Node*node;void*callback;};
struct Context{char opaque00[0x130];void* guard130;void*guard134;};
extern "C" {extern Context*lbl_803776B8;void fn_8025795C(void*,int,int);void fn_8008CE2C(Owner*);void fn_80068158(Context*,void*);}
extern "C" void fn_80082444(Owner*self){
 fn_8025795C(self->callback,0x15,0);
 Context* context=lbl_803776B8;
 if(context && context->guard134) fn_80068158(context,self->node->data320);
}
