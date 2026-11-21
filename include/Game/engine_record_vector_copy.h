#ifndef GAME_ENGINE_RECORD_VECTOR_COPY_H
#define GAME_ENGINE_RECORD_VECTOR_COPY_H

typedef unsigned short RecordVectorCopyScalar2;
extern "C" {
 extern char lbl_8028F698[];
 void*fn_8028FAF4(void*,void*,int,int);
 void*fn_8028FF24(void*,int);
 void fn_8028FD50(void*,void*,int);
}
inline void*operator new(unsigned long,void*p){return p;}
struct RecordVectorCopyRecord28 {
 float a,b,c,d,e,f,g;
 RecordVectorCopyRecord28(){}
 ~RecordVectorCopyRecord28(){}
 RecordVectorCopyRecord28(const RecordVectorCopyRecord28&v):a(v.a),b(v.b),c(v.c),d(v.d),e(v.e),f(v.f),g(v.g){}
};
template<class T>struct RecordVectorCopyArray {
    int count,capacity;
    T*data;
    const T&operator[](int i)const {
        return data[i];
    }
    void reserve(int n) {
        if(n) {
            if(data)data=(T*)fn_8028FAF4(lbl_8028F698,data,capacity*sizeof(T),n*sizeof(T));
            else data=(T*)fn_8028FF24(lbl_8028F698,n*sizeof(T));
        }
        else if(data) {
            fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));
            data=0;
        }
        capacity=n;
    }
    void resize(int n,signed char keep) {
        int i;
        if(n>count) {
            if(n>capacity||!keep)reserve(n);
            for(i=count; i<n; ++i)new(&data[i])T;
            count=n;
        }
        else if(n<count) {
            for(i=count-1; i>=n; --i)data[i].~T();
            if(keep)count=n;
            else {
                reserve(n);
                count=n;
            }
        }
    }
    void setCapacity(int n) {
        if(n<count)resize(n,0);
        else reserve(n);
    }
    void append(const T&value) {
        if(count+1>capacity) {
            int n=capacity+32;
            if(n) {
                if(data)data=(T*)fn_8028FAF4(lbl_8028F698,data,capacity*sizeof(T),n*sizeof(T));
                else data=(T*)fn_8028FF24(lbl_8028F698,n*sizeof(T));
            }
            else if(data) {
                fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));
                data=0;
            }
            capacity+=32;
        }
        new(&data[count++])T(value);
    }
};

typedef char RecordVectorCopyScalarSizeCheck[sizeof(RecordVectorCopyScalar2)==2?1:-1];
typedef char RecordVectorCopyRecordSizeCheck[sizeof(RecordVectorCopyRecord28)==28?1:-1];
typedef char RecordVectorCopyArraySizeCheck[sizeof(RecordVectorCopyArray<RecordVectorCopyScalar2>)==12?1:-1];
extern "C" RecordVectorCopyArray<RecordVectorCopyScalar2>*fn_80249250(RecordVectorCopyArray<RecordVectorCopyScalar2>*,const RecordVectorCopyArray<RecordVectorCopyScalar2>*);
extern "C" RecordVectorCopyArray<RecordVectorCopyRecord28>*fn_802495A0(RecordVectorCopyArray<RecordVectorCopyRecord28>*,const RecordVectorCopyArray<RecordVectorCopyRecord28>*);
#endif
