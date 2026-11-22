struct Owner;struct Node{char opaque00[0x94];Owner*owner;};extern "C"void fn_800718B4(Owner*,Node*);extern "C"void fn_8007350C(Node*self){fn_800718B4(self->owner,self);}
