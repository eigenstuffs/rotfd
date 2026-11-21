/* Original engine lifetime and record routines.
* See docs/notes/game-engine-pool-resize.md. */
extern "C" {
    extern char lbl_8028F698[],lbl_801EF5C8[];
    void *fn_8028FAF4(void*,void*,int,int);
    void *fn_8028FF24(void*,int);
    void fn_8028FD50(void*,void*,int);
    void fn_801EF610(void*,void*);
}
inline void*operator new(unsigned long,void*p){
    return p;
}
template<int N>struct Element_801D5B08{
    char data[N];
    ~Element_801D5B08(){
    }
}
;
template<class T>struct Pool_801D5B08{
    int count,capacity;
    T*data;
    Pool_801D5B08(){
        count=0;
        capacity=0;
        data=0;
    }
    ~Pool_801D5B08(){
        if(data){
            for(int i=0;
            i<count;
            i++)data[i].~T();
            if(data){
                fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));
                data=0;
            }
            data=0;
        }
    }
}
;
template<class T>struct Vector_801D5B08:Pool_801D5B08<T>{
    Vector_801D5B08(){
    }
    ~Vector_801D5B08(){
    }
}
;
template<class T>struct Array_801D5B08{
    int count,capacity;
    T*data;
    inline void reserve(int n){
        if(n){
            if(data)data=(T*)fn_8028FAF4(lbl_8028F698,data,capacity*sizeof(T),n*sizeof(T));
            else data=(T*)fn_8028FF24(lbl_8028F698,n*sizeof(T));
        }
        else if(data){
            fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));
            data=0;
        }
        capacity=n;
    }
}
;
struct Record_801D5B08:Pool_801D5B08<Element_801D5B08<2> >{
    Pool_801D5B08<Element_801D5B08<2> > second;
    unsigned short firstField,secondField;
    char tail[4];
    Record_801D5B08(){
        secondField=0;
        firstField=0;
    }
    ~Record_801D5B08(){
    }
}
;
extern "C" void fn_801D5B08(Array_801D5B08<Record_801D5B08 >*self,int n,signed char keep){
    if(n>self->count){
        if(n>self->capacity||!keep)self->reserve(n);
        for(int i=self->count;
        i<n;
        i++)new(&self->data[i]) Record_801D5B08;
        self->count=n;
    }
    else if(n<self->count){
        for(int i=self->count-1;
        i>=n;
        i--)self->data[i].~Record_801D5B08();
        if(keep)self->count=n;
        else{
            self->reserve(n);
            self->count=n;
        }
    }
}
