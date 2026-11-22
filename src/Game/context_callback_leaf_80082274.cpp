typedef unsigned long Word;
struct Node{char opaque00[0x320];void* data320;};
struct Owner{Word opaque00[2];Node*node;void*callback;};
struct Context{char opaque00[0x130];void* guard130;void*guard134;};
extern "C" {extern Context*lbl_803776B8;void fn_8025795C(void*,int,int);void fn_8008CE2C(Owner*);void fn_8006803C(Context*,void*);}
extern "C" void fn_80082274(Owner*self){
 fn_8025795C(self->callback,0x14,0);
 Context* context=lbl_803776B8;
 if(context && context->guard130) fn_8006803C(context,self->node->data320);
}
