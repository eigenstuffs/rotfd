/* Original short control delegates; see docs/notes/game-short-control-delegates.md. */
struct Handle;struct Record{char opaque00[0x4C];};extern "C"void fn_801E2E04(Record*,const Handle&);extern "C"void fn_8003125C(Record*self,int index,const Handle&value){fn_801E2E04(&self[index],value);}
