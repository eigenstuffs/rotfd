/* Original delegate; partial views described in docs/notes/game-small-delegates-20261011.md. */
struct Array{int count,capacity;void*items;};struct Owner{unsigned long unknown0;Array rows;};
extern "C" void fn_801AD6A0(Array*,int,signed char);
extern "C" void fn_801AD678(Owner*self,int count){fn_801AD6A0(&self->rows,count,0);}
