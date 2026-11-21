/* Original delegate; partial views documented in docs/notes/game-small-delegates-20261011b.md. */
struct Owner{char unknown00[0x74];unsigned long payload[14];float final[3];};
extern "C"{void fn_80243E44(Owner*,char**);char*fn_801E9F40(void*,char*,unsigned long);}
extern "C"void fn_801CBAB4(Owner*self,char**cursor){fn_80243E44(self,cursor);char*begin=(char*)&self->payload;*cursor=fn_801E9F40(begin,*cursor,(char*)&self->final-begin+sizeof(self->final));}
