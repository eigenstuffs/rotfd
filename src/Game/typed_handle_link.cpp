struct TypedLinkHandle {signed int generation:8;signed int index:24;};
struct TypedLinkObject {char unknown00[0x6C];unsigned short type;};
struct TypedLinkEntry {TypedLinkObject*object;char unknown04[8];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};
struct TypedLinkManager {char unknown00[8];TypedLinkEntry*entries;};
struct TypedLinkOwner {char unknown00[0x1C];TypedLinkHandle first,second;};
extern "C" {extern struct {char unknown00[0x118];TypedLinkManager*manager;}lbl_801E9D24;void fn_801D38A4(TypedLinkObject*,TypedLinkOwner*,TypedLinkObject*);}
static inline TypedLinkObject*resolveTypedLink(const TypedLinkHandle&h){int index=h.index;TypedLinkManager*m=lbl_801E9D24.manager;int gen=m->entries[index].getGeneration();return gen==h.generation?m->entries[index].object:0;}
extern "C" void fn_8023EEF0(TypedLinkOwner*self){TypedLinkObject*first=resolveTypedLink(self->first);if(first&&first->type==3)fn_801D38A4(first,self,resolveTypedLink(self->second));}
