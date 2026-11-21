/* Original scene callback registration and lookup wrappers; see docs/notes/game-engine-scene-callback-wrappers.md. */
extern "C"{extern void*lbl_80377630;void fn_8025ED38(void*,void*,void*);void fn_80043934(void*,void*);int fn_8025E70C(void*,void*,void*);int fn_80043A24(void*,void*);}
extern "C" int fn_80043D88(void*self,void*value){int result=fn_8025E70C(self,value,lbl_80377630);if(result!=-1)return result;return fn_80043A24(self,value);}
