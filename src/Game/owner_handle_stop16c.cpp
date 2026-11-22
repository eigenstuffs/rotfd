struct FindEraseHandle{signed int generation:8;signed int index:24;};
struct FindEraseEntry{void*object;char unknown04[8];signed char generation;char unknown0D[3];};
struct FindEraseManager{char unknown00[8];FindEraseEntry*entries;};
extern "C"{extern struct{char unknown00[0x118];FindEraseManager*manager;}lbl_801E9D24;void __dt__15Handle_801F7F10Fv(void*,int);void*memcpy(void*,const void*,unsigned long);}
static inline void*resolveFindErase(const FindEraseHandle&h){FindEraseEntry*e=&lbl_801E9D24.manager->entries[h.index];if(e->generation==h.generation)return e->object;return 0;}
struct FindEraseOwner{char unknown00[0x16C];FindEraseHandle handle;};
extern "C" void fn_8024A6B4(void*);
extern "C" void slot12C__13ObjectThrow_ZFv(FindEraseOwner*self){void*object=resolveFindErase(self->handle);if(object)fn_8024A6B4(object);}
