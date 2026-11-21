// Generation-checked related resource lookup. Native C-entry views retain
// the observed by-value Handle copies and destruction boundaries.
struct RelatedLookupObject;struct RelatedLookupEntry{RelatedLookupObject*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};struct RelatedLookupEntryArray{RelatedLookupEntry*p;RelatedLookupEntry&operator[](int i)const{return p[i];}};struct RelatedLookupManager{int count,capacity;RelatedLookupEntryArray entries;};
extern "C"{extern struct RelatedLookupContext{char unknown00[0x118];RelatedLookupManager*manager;}lbl_801E9D24;void fn_801F86C8(RelatedLookupManager*,const void*,short);extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);}
struct Handle_801F7F10{union{unsigned long word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Handle_80020478:Handle_801F7F10{Handle_80020478(){word=0;}~Handle_80020478();};
struct Handle_80020834:Handle_80020478{Handle_80020834(){word=0;}~Handle_80020834();};
struct RelatedLookupHandle:Handle_80020834{RelatedLookupHandle(){word=0;}RelatedLookupHandle(const RelatedLookupHandle&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~RelatedLookupHandle();};
struct RelatedLookupObject{char unknown00[0x60];Handle_801F7F10 parent;};
inline RelatedLookupObject*resolveRelatedLookup(const Handle_801F7F10&h){RelatedLookupEntry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
struct RelatedLookupOwner{char unknown00[0x1504C];int count,capacity;RelatedLookupHandle*data;};
inline RelatedLookupObject*resolveFirst(const Handle_801F7F10&h){int index=h.bits.index;RelatedLookupManager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
inline RelatedLookupObject*resolveSecond(const Handle_801F7F10&h){RelatedLookupEntry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
struct Handle_8002B67C:Handle_801F7F10{Handle_8002B67C(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}Handle_8002B67C(const Handle_8002B67C&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_8002B67C(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};extern "C"Handle_8002B67C fn_800312D4(const RelatedLookupObject*);inline signed char sameRelated(const Handle_801F7F10&a,const Handle_801F7F10&b){return resolveFirst(a)==resolveSecond(b);}
extern "C"RelatedLookupHandle fn_800BCF58(RelatedLookupOwner*self,const Handle_801F7F10&parent){for(int i=0;i<self->count;++i)if(sameRelated(fn_800312D4(resolveRelatedLookup(self->data[i])),parent))return self->data[i];return RelatedLookupHandle();}
