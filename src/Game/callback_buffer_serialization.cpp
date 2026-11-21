struct CallbackBufferOwner {char unknown0[0xC];char*data;int length;};
extern "C" {
    void slot0C__12BaseObject_ZFUl(void*,void*);
    void*fn_801E9F40(void*,void*,int);
    unsigned long strlen(const char*);
    void*memcpy(void*,const void*,unsigned long);
    void fn_801EF610(void*,void*);
    void*fn_801EFA1C(void*,int,const char*,const char*,int,int);
    void fn_80253250(void*);
    extern char lbl_801EF5C8[],lbl_802AEB18[],lbl_802AEB28[];
}
inline void assignCallbackBuffer(CallbackBufferOwner*self,const char*source,int length){
    if(length==-1)self->length=strlen(source);
    else self->length=length;
    if(self->data){fn_801EF610(lbl_801EF5C8,self->data);self->data=0;}
    if(self->length!=0){
        self->data=(char*)fn_801EFA1C(lbl_801EF5C8,self->length,lbl_802AEB18,lbl_802AEB28,0x1E,4);
        memcpy(self->data,source,self->length);
        fn_80253250(self);
    }
}
extern "C" void fn_80252FD4(CallbackBufferOwner*self,char**cursor){
    slot0C__12BaseObject_ZFUl(self,cursor);
    *cursor=(char*)fn_801E9F40(&self->length,*cursor,4);
    assignCallbackBuffer(self,*cursor,self->length);
    *cursor+=self->length;
}
