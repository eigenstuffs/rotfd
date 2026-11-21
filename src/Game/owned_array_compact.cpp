struct OwnedCompactHandle{unsigned long value;};
struct OwnedCompactArray{int count,capacity;OwnedCompactHandle*handles;};
extern "C"{extern struct{char unknown00[0x118];void*manager;}lbl_801E9D24;void*fn_801F7EB8(const void*);signed char fn_801F8C88(void*,const void*);void __dt__15Handle_801F7F10Fv(void*,int);void*memcpy(void*,const void*,unsigned long);}
static inline void eraseOwnedCompact(OwnedCompactArray*self,int i){OwnedCompactHandle*entry=&self->handles[i];if(entry)if(entry)__dt__15Handle_801F7F10Fv(entry,0);OwnedCompactHandle*dest=&self->handles[i];int count=--self->count;memcpy(dest,dest+1,(count-i)*4);}
extern "C" void fn_8023AB78(OwnedCompactArray*self){for(int i=0;i<self->count;){if(!fn_801F7EB8(&self->handles[i]))eraseOwnedCompact(self,i);else if(!fn_801F8C88(lbl_801E9D24.manager,&self->handles[i]))eraseOwnedCompact(self,i);else ++i;}}
