#include "Game/early_handle_bind_views.h"
#include "Game/agent_cleanup_virtual_view_8006565C.h"
extern "C" {
 extern void*lbl_80377718;
 void method_80063074__14Agent_80062E18Fv(void*);void method_8006311C__14Agent_80062E18Fv(void*);void fn_80063290(void*,int);
 void fn_80063F98(void*,const OpaqueHandle&);void fn_80063FB8(void*);
 void fn_8025ED38(void*,void*,void*);void fn_800642A8(void*,void*);
 int fn_8025E70C(void*,void*,void*);int fn_8006434C(void*,void*);
}
/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-fn-cleanup-eh.md. */
extern "C" {
    extern char lbl_801EF5C8[],lbl_802B69E8[];
    void fn_801EF610(void*,void*);
    void __dt__14Agent_80062E18Fv(void*,int);
}
struct CleanupFields_8006565C {
    char unknown00[8];
    void*vtable;
    char unknown0C[136];
    void*secondary;
};
static inline void dispose(void*p)throw() {
    fn_801EF610(lbl_801EF5C8,p);
}
inline void*cleanup_impl_8006565C(CleanupFields_8006565C*self,int flag) {
    if(self) {
        self->vtable=lbl_802B69E8;
        self->secondary=lbl_802B69E8+180;
        __dt__14Agent_80062E18Fv(self,0);
        if((short)flag>0)dispose(self);
    }
    return self;
}

void*ObjectCleanupVirtualView_8006565C::cleanup(int flag){return cleanup_impl_8006565C(reinterpret_cast<CleanupFields_8006565C*>(this),flag);}
void ObjectCleanupVirtualView_8006565C::method_80063074(){BindObject*self=reinterpret_cast<BindObject*>(this);method_80063074__14Agent_80062E18Fv(self);self->bind(fn_801B52EC(lbl_801E9D24.manager,lbl_8029BD28));}
void ObjectCleanupVirtualView_8006565C::method_8006311C(){method_8006311C__14Agent_80062E18Fv(this);}
void ObjectCleanupVirtualView_8006565C::slot_040(int argument){fn_80063290(this,argument);}
void ObjectCleanupVirtualView_8006565C::slot_044(const OpaqueHandle&value){fn_80063F98(this,value);}
void ObjectCleanupVirtualView_8006565C::slot_0B0(){fn_80063FB8(this);}
unsigned long ObjectCleanupVirtualView_8006565C::slot_020(){return reinterpret_cast<unsigned long>(lbl_80377718);}
void ObjectCleanupVirtualView_8006565C::slot_024(unsigned long value){lbl_80377718=reinterpret_cast<void*>(value);}
void ObjectCleanupVirtualView_8006565C::slot_028(void*value){fn_8025ED38(this,value,lbl_80377718);fn_800642A8(this,value);}
int ObjectCleanupVirtualView_8006565C::slot_02C(void*value){int result=fn_8025E70C(this,value,lbl_80377718);if(result!=-1)return result;return fn_8006434C(this,value);}
