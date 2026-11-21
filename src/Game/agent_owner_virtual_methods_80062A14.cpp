#include "Game/agent_owner_virtual_view_80061AC0.h"
typedef unsigned long u32;
struct Handle_801F7F10 {u32 word;Handle_801F7F10();~Handle_801F7F10();};
struct HandleEntry_80061AC0 {void*object;char pad[8];signed char tag;char tail[3];};
struct Manager_80061AC0 {char pad[8];HandleEntry_80061AC0*entries;};
struct Context_80061AC0 {char pad[0x110];void*logger;char*slots114;Manager_80061AC0*manager;};
extern "C" {extern Context_80061AC0 lbl_801E9D24;void fn_80024C00(Owner_80061AC0*);void fn_80024BCC(Owner_80061AC0*);void fn_801FA014(void*,const char*,...);void fn_801F86C8(Manager_80061AC0*,const Handle_801F7F10*,short);void fn_801EF610(void*,void*);extern char lbl_801EF5C8[];int fn_8025E9FC(void*,int);
extern const char lbl_8029BACC[],lbl_8029BAFC[],lbl_8029BB2C[],lbl_8029BB58[],lbl_8029BB88[],lbl_8029BBB8[];
}
struct Handle_80021C40:Handle_801F7F10{Handle_80021C40(){word=0;}~Handle_80021C40(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80021BCC:Handle_80021C40{Handle_80021BCC(const Handle_801F7F10&v){word=v.word;fn_801F86C8(lbl_801E9D24.manager,&v,1);}~Handle_80021BCC(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct HandleOwnerView_80061AC0 {char unknown00[0x1F4];Handle_801F7F10 handle;};
struct Handle_80061AC0 {signed int tag:8;signed int index:24;};
static inline void*resolve(const Handle_80061AC0*h){HandleEntry_80061AC0*entry=&lbl_801E9D24.manager->entries[h->index];if(entry->tag==h->tag)return entry->object;return 0;}
void Agent_80061AC0::notifyOwner(){if(owner)fn_80024C00(owner);}
void Agent_80061AC0::method_80062A40(){fn_80024BCC(owner);}
void Agent_80061AC0::method_80062A64(){}
void Agent_80061AC0::method_80062A68(){fn_801FA014(lbl_801E9D24.logger,lbl_8029BACC);}
void Agent_80061AC0::method_80062AA0(){fn_801FA014(lbl_801E9D24.logger,lbl_8029BAFC);}
void Agent_80061AC0::method_80062AD8(){fn_801FA014(lbl_801E9D24.logger,lbl_8029BB2C);}
int Agent_80061AC0::method_80062B10(){return 0;}
void Agent_80061AC0::method_80062B18(){}
void Agent_80061AC0::method_80062B1C(){}
void Agent_80061AC0::method_80062B20(const Handle_801F7F10&value){HandleOwnerView_80061AC0*self=reinterpret_cast<HandleOwnerView_80061AC0*>(this);Handle_80021BCC h(value);fn_801F86C8(lbl_801E9D24.manager,&self->handle,-1);self->handle.word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}
void Agent_80061AC0::method_80062BB8(){}
int Agent_80061AC0::method_80062BBC(){fn_801FA014(lbl_801E9D24.logger,lbl_8029BB58);return 0;}
int Agent_80061AC0::method_80062BF8(){fn_801FA014(lbl_801E9D24.logger,lbl_8029BB88);return 0;}
int Agent_80061AC0::method_80062C34(){fn_801FA014(lbl_801E9D24.logger,lbl_8029BBB8);return -1;}
void*Agent_80061AC0::method_80062C70(){return (char*)this+492;}
int Agent_80061AC0::method_80062C78(int index){return fn_8025E9FC(this,index);}
void*Agent_80061AC0::method_80062C98(){return (char*)this+444;}
float Agent_80061AC0::method_80062CA0(){return *(const float*)((const char*)this+44);}
void*Agent_80061AC0::method_80062CA8(){return resolve((const Handle_80061AC0*)((const char*)this+0x28));}
void Agent_80061AC0::method_80062CF4(){}

typedef char CheckPrimarySize[(sizeof(PrimaryView_80061AC0)==0x60)?1:-1];
typedef char CheckSecondarySize[(sizeof(SecondaryView_80061AC0)==0x160)?1:-1];
