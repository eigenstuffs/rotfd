/* Bounded resource-key erasure. Existing GLOBAL context and string providers
 * remain externally owned; this unit owns only its exported function. */
struct HandleIndex {
    int value;
    HandleIndex(int v) : value(v) {}
    operator int() const { return value; }
};
struct Handle_801F7F10 {
 union { unsigned long value; struct { signed int generation:8; signed int index:24; } bits; };
 Handle_801F7F10(); ~Handle_801F7F10();
};
struct ResourceEraseBase : Handle_801F7F10 {};
struct ResourceEraseHandle : ResourceEraseBase {};
struct ResourceEraseKey {
 unsigned long value;
 ResourceEraseKey(unsigned long n) : value(n) {}
 ResourceEraseKey(const char* text);
 bool operator==(const ResourceEraseKey& other) const { return value == other.value; }
};
struct ResourceEraseEntry { void* object; unsigned long key; unsigned long unknown08; signed char generation; char unknown0D[3]; };
struct ResourceEraseManager { int count, capacity; ResourceEraseEntry* entries; };
struct ResourceEraseBuffer { char text[128]; };
extern "C" void* memcpy(void*,const void*,unsigned long);
struct ResourceEraseSelf {
 char unknown00[12]; int count, capacity; ResourceEraseHandle* items;
 void erase(int i) {
  items[static_cast<unsigned int>(i)].~ResourceEraseHandle();
  ResourceEraseHandle* dest=&items[static_cast<unsigned int>(i)];
  memcpy(dest,dest+1,(--count-i)*4);
 }

};
extern "C" {
 extern struct { char unknown00[0x110]; void* logger; char unknown114[4]; ResourceEraseManager* manager; } lbl_801E9D24;
 extern const char lbl_802AEF54[];
 void fn_80207A14(const char*,ResourceEraseBuffer*);
 void fn_80207974(const ResourceEraseBuffer*,ResourceEraseBuffer*);
 unsigned long fn_801F948C(void*,const char*);
 void fn_801F9D68(void*,const char*,...);
 void* memcpy(void*,const void*,unsigned long);
}
inline ResourceEraseKey::ResourceEraseKey(const char* text) { value=fn_801F948C(this,text); }
inline ResourceEraseKey resourceKey(const ResourceEraseHandle& handle) {
 ResourceEraseManager* manager=lbl_801E9D24.manager;
 const HandleIndex index(handle.bits.index);
 signed char generation=handle.bits.generation;
 int valid=0;
 if(index<manager->count && generation==((signed char*)manager->entries)[index*sizeof(ResourceEraseEntry)+12])valid=1;
 if(valid)return ResourceEraseKey(*(unsigned long*)((char*)manager->entries+index*sizeof(ResourceEraseEntry)+4));
 return ResourceEraseKey(0UL);
}
extern "C" int fn_80262DB8(ResourceEraseSelf* self,const char* input) {
 ResourceEraseBuffer normalized;
 fn_80207A14(input,&normalized);
 ResourceEraseBuffer canonical;
 fn_80207974(&normalized,&canonical);
 ResourceEraseKey key(canonical.text);
 for(int i=0;i<self->count;++i) {
  if(resourceKey(self->items[i])==key) { self->erase(i); return 1; }
 }
 fn_801F9D68(lbl_801E9D24.logger,lbl_802AEF54,input);
 return 0;
}
