/* World handle loader fn_801E8E2C (801E8E2C..801E9A24).
 * Root load, entry-pool resize, dynamic two-layer handle arrays at C/24/18,
 * handle 30, three index structures, one-layer handles C100, five-layer fixed
 * arrays C110/C140, three-layer dynamic handles C134 and final handles C164/C168.
 * See docs/notes/game-world-handle-loader.md. */
typedef unsigned long u32;
struct Manager;
struct Globals { char unknown0[0x118]; Manager* manager; };
extern "C" {
extern Globals lbl_801E9D24;
extern char lbl_8028F698[];
void* fn_8028FAF4(void*,void*,u32,u32);
void* fn_8028FF24(void*,u32);
void fn_8028FD50(void*,void*,u32);
unsigned char* fn_801E9F40(void*,const unsigned char*,int);
void fn_801E9A24(void*,int);
void fn_801B41B8(Manager*,void*,unsigned char**);
void fn_801B3FD0(Manager*,void*,unsigned char**);
void fn_802668E0(void*,unsigned char**);
}
inline void* operator new(unsigned long,void* p){return p;}
struct Handle_801F7F10 {
    u32 value;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct BaseObject_Z { void slot0C(unsigned long); };
template<int Depth> struct LoadHandle:LoadHandle<Depth-1> {LoadHandle(){this->value=0;}~LoadHandle(){}};
template<> struct LoadHandle<1>:Handle_801F7F10 {LoadHandle(){value=0;}~LoadHandle(){}};
template<class T> struct LoadArray {int count,capacity;T*data;};
template<class T> inline void storage(LoadArray<T>*a,int n){
    if(n){
        if(a->data)a->data=(T*)fn_8028FAF4(lbl_8028F698,a->data,a->capacity*sizeof(T),n*sizeof(T));
        else a->data=(T*)fn_8028FF24(lbl_8028F698,n*sizeof(T));
    }else if(a->data){fn_8028FD50(lbl_8028F698,a->data,a->capacity*sizeof(T));a->data=0;}
    a->capacity=n;
}
template<class T> inline void resize(LoadArray<T>*a,int n){
    int i;
    if(n>a->count){
        storage(a,n);
        for(i=a->count;i<n;++i)new(a->data+i)T;
        a->count=n;
    }else if(n<a->count){
        for(i=a->count-1;i>=n;--i)a->data[i].~T();
        storage(a,n);a->count=n;
    }
}
template<class T> struct LoadFixedArray {
    T data[8];int count;
    T&operator[](unsigned int i){return data[i];}
    void resize(int n){
        int i=count;
        if(n>count){for(int j=i;j<n;++j)new(&(*this)[j])T;}
        else if(n<count){for(i=count-1;i>=n;--i)(*this)[i].~T();}
        count=n;
    }
};
struct WorldLoadView {
    char base[0xC];
    LoadArray<LoadHandle<2> > handlesC,handles18,handles24;
    LoadHandle<2> handle30;
    char index34[0x4044],index4078[0x4044],index80BC[0x4044];
    LoadArray<LoadHandle<1> > handlesC100;
    u32 fieldC10C;
    LoadFixedArray<LoadHandle<5> > handlesC110;
    LoadArray<LoadHandle<3> > handlesC134;
    LoadFixedArray<LoadHandle<5> > handlesC140;
    LoadHandle<2> handleC164,handleC168;
    u32 fieldC16C;
    char arrayC170[12];
};
extern "C" void fn_801E8E2C(WorldLoadView*self,unsigned char**cursor){
    ((BaseObject_Z*)self)->slot0C((u32)cursor);
    Manager*manager=lbl_801E9D24.manager;
    int count,i;
    *cursor=fn_801E9F40(&count,*cursor,4);
    if(count)fn_801E9A24(self->arrayC170,count);
    *cursor=fn_801E9F40(&count,*cursor,4);resize(&self->handlesC,count);
    for(i=0;i<count;++i)fn_801B41B8(manager,&self->handlesC.data[i],cursor);
    *cursor=fn_801E9F40(&count,*cursor,4);resize(&self->handles24,count);
    for(i=0;i<count;++i)fn_801B41B8(manager,&self->handles24.data[i],cursor);
    *cursor=fn_801E9F40(&count,*cursor,4);resize(&self->handles18,count);
    for(i=0;i<count;++i)fn_801B41B8(manager,&self->handles18.data[i],cursor);
    fn_801B41B8(manager,&self->handle30,cursor);
    fn_802668E0(self->index34,cursor);fn_802668E0(self->index4078,cursor);fn_802668E0(self->index80BC,cursor);
    *cursor=fn_801E9F40(&count,*cursor,4);resize(&self->handlesC100,count);
    for(i=0;i<self->handlesC100.count;++i)fn_801B3FD0(manager,&self->handlesC100.data[i],cursor);
    *cursor=fn_801E9F40(&count,*cursor,4);self->handlesC110.resize(count);
    for(i=0;i<count;++i)fn_801B41B8(manager,&self->handlesC110[i],cursor);
    *cursor=fn_801E9F40(&count,*cursor,4);resize(&self->handlesC134,count);
    for(i=0;i<count;++i)fn_801B41B8(manager,&self->handlesC134.data[i],cursor);
    *cursor=fn_801E9F40(&count,*cursor,4);self->handlesC140.resize(count);
    for(i=0;i<count;++i)fn_801B41B8(manager,&self->handlesC140[i],cursor);
    fn_801B41B8(manager,&self->handleC164,cursor);fn_801B41B8(manager,&self->handleC168,cursor);
}
