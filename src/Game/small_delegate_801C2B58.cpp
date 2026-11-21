/* Original delegate; partial views described in docs/notes/game-small-delegates-20261011.md. */
struct BitSet{unsigned long words[4];};struct Owner{char unknown0[0x18C];BitSet occupied;int limit;};
extern "C" int fn_80207B94(BitSet*,signed char,int);
extern "C" int fn_801C2B58(Owner*self){if(self->limit==0)return -1;return fn_80207B94(&self->occupied,1,0);}
