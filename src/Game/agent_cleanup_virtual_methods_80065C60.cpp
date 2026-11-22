#include "Game/early_handle_bind_views.h"
#include "Game/agent_cleanup_virtual_view_80065C60.h"
extern "C" {
 extern void*lbl_80377728;
 void method_80063074__14Agent_80062E18Fv(void*);void method_8006311C__14Agent_80062E18Fv(void*);void fn_80063290(void*,int);
 void fn_80063F98(void*,const OpaqueHandle&);void fn_80063FB8(void*);
 void fn_8025ED38(void*,void*,void*);void fn_800642A8(void*,void*);
 int fn_8025E70C(void*,void*,void*);int fn_8006434C(void*,void*);
}
extern "C" {
    extern char lbl_801EF5C8[],lbl_802B7098[];
    void fn_801EF610(void*,void*);
    void __dt__14Agent_80062E18Fv(void*,int);
}
struct CleanupFields_80065C60 {
    char unknown00[8];
    void*vtable;
    char unknown0C[136];
    void*secondary;
};
static inline void dispose(void*p)throw() {
    fn_801EF610(lbl_801EF5C8,p);
}
inline void*cleanup_impl_80065C60(CleanupFields_80065C60*self,int flag) {
    if(self) {
        self->vtable=lbl_802B7098;
        self->secondary=lbl_802B7098+180;
        __dt__14Agent_80062E18Fv(self,0);
        if((short)flag>0)dispose(self);
    }
    return self;
}

void*ObjectCleanupVirtualView_80065C60::cleanup(int flag){return cleanup_impl_80065C60(reinterpret_cast<CleanupFields_80065C60*>(this),flag);}
void ObjectCleanupVirtualView_80065C60::method_80063074(){BindObject*self=reinterpret_cast<BindObject*>(this);method_80063074__14Agent_80062E18Fv(self);self->bind(fn_801B52EC(lbl_801E9D24.manager,lbl_8029BE98));}
void ObjectCleanupVirtualView_80065C60::method_8006311C(){method_8006311C__14Agent_80062E18Fv(this);}
void ObjectCleanupVirtualView_80065C60::slot_040(int argument){fn_80063290(this,argument);}
void ObjectCleanupVirtualView_80065C60::slot_044(const OpaqueHandle&value){fn_80063F98(this,value);}
void ObjectCleanupVirtualView_80065C60::slot_0B0(){fn_80063FB8(this);}
unsigned long ObjectCleanupVirtualView_80065C60::slot_020(){return reinterpret_cast<unsigned long>(lbl_80377728);}
void ObjectCleanupVirtualView_80065C60::slot_024(unsigned long value){lbl_80377728=reinterpret_cast<void*>(value);}
void ObjectCleanupVirtualView_80065C60::slot_028(void*value){fn_8025ED38(this,value,lbl_80377728);fn_800642A8(this,value);}
int ObjectCleanupVirtualView_80065C60::slot_02C(void*value){int result=fn_8025E70C(this,value,lbl_80377728);if(result!=-1)return result;return fn_8006434C(this,value);}
