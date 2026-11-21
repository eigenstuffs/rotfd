/* Original scene logging and reset wrappers; see docs/notes/game-engine-scene-log-wrappers.md. */
struct CallbackRelatedHandle{unsigned long word;};extern "C" void fn_80259FB4(void*,const CallbackRelatedHandle&);extern "C" void fn_800356BC(void*self,const CallbackRelatedHandle&value){fn_80259FB4(self,value);}
