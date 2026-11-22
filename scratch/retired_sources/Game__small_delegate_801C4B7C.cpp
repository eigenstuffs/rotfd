/* Original delegate; partial views documented in docs/notes/game-small-delegates-20261011b.md. */
struct Record{int type;unsigned long value,extra;Record(){type=-1;extra=0;value=0;}};
extern "C"signed char fn_801C4968(void*,Record*,void*,signed char);
extern "C"signed char fn_801C4B7C(void*self,void*value){Record record;record.type=0x23;return fn_801C4968(self,&record,value,1);}
