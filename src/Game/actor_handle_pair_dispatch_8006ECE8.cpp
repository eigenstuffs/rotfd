/* Actor Handle pair and counter control; see docs/notes/game-actor-handle-pair-controls.md. */
typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Context{char unknown0[0x118];void*manager;};extern "C"{extern Context lbl_801E9D24;extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(void*,const Handle_801F7F10*,int);}
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){word=0;}~Handle_8001FF78(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020B90:Handle_8001FF78{Handle_80020B90(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80020B90(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Object{char unknown0[0xD0];int mode;};
struct Record{Word key;Handle_801F7F10 handle;const Handle_801F7F10&getHandle()const{return handle;}};
extern "C"{Object*fn_8007D074(void*);void fn_8007705C(Object*);void fn_80075EC0(Object*,const Handle_80020B90&,const Handle_80020B90&);}
extern "C"void fn_8006ECE8(void*self,Record*first,Record*second){Object*object=fn_8007D074(self);if(object->mode==1||object->mode==2)fn_8007705C(object);fn_80075EC0(object,Handle_80020B90(first->getHandle()),Handle_80020B90(second->getHandle()));}
