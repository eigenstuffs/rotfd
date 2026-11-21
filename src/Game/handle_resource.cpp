#include "handle_resource_internal.h"
extern "C" {
void fn_801B3E54(Manager*,void*);
void fn_801B41B8(Manager*,void*,u32*);
u32 fn_801E9F40(void*,u32,int);
}
template<class T> inline     void reserveArray(WorldCurveArray<T>* self,int n) {
        if (n) {
            if (self->data)
                self->data = (T*)fn_8028FAF4(lbl_8028F698, self->data,
                                      self->capacity * sizeof(T), n * sizeof(T));
            else
                self->data = (T*)fn_8028FF24(lbl_8028F698, n * sizeof(T));
        } else if (self->data) {
            fn_8028FD50(lbl_8028F698, self->data, self->capacity * sizeof(T));
            self->data = 0;
        }
    }

template<class T> inline void resizeArray(WorldCurveArray<T>* self,int n){
    int i;
    if(n>self->count){
        reserveArray(self,n);self->capacity=n;
        for(i=self->count;i<n;++i)new(self->data+i)T;
        self->count=n;
    }else if(n<self->count){
        for(i=self->count-1;i>=n;--i)self->data[i].~T();
        reserveArray(self,n);self->capacity=n;self->count=n;
    }
}

HandleResource_802EA820::~HandleResource_802EA820(){}
extern "C" ResourceHandle fn_801E7654(HandleResource_802EA820*self,const u32* name){
    for(int i=0;i<self->handles.count;++i){
        Activable_Z* object=fn_801F7EB8(&self->handles.data[i]);
        if(object && object->unknown0==*name)return ResourceHandle(object->getIdentity());
    }
    return ResourceHandle();
}
void HandleResource_802EA820::slot10(){
    resizeArray(&handles,handles.count);
    for(int i=0;i<handles.count;++i)fn_801B3E54(lbl_801E9D24.manager,&handles.data[i]);
}
void HandleResource_802EA820::slot0C(u32 stream){
    BaseObject_Z::slot0C(stream);
    int count;
    *(u32*)stream=fn_801E9F40(&count,*(u32*)stream,4);
    resizeArray(&handles,count);
    for(int i=0;i<count;++i)fn_801B41B8(lbl_801E9D24.manager,&handles.data[i],(u32*)stream);
}
signed char HandleResource_802EA820::slot1C(){
    if(!BaseObject_Z::slot1C())return 0;
    for(int i=0;i<handles.count;++i){
        if(fn_801F7EB8(&handles.data[i]))fn_801F7EB8(&handles.data[i])->slot1C();
    }
    return 1;
}
