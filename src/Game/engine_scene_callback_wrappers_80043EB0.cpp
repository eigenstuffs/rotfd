/* Original scene callback registration and lookup wrappers; see docs/notes/game-engine-scene-callback-wrappers.md. */
extern "C"{extern void*lbl_8037762C;void fn_8025ED38(void*,void*,void*);void fn_80043934(void*,void*);int fn_8025E70C(void*,void*,void*);int fn_80043A24(void*,void*);}
extern "C" int fn_80043EB0(void*self,void*value){int result=fn_8025E70C(self,value,lbl_8037762C);if(result!=-1)return result;return fn_80043A24(self,value);}
