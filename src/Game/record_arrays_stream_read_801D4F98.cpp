typedef unsigned long StreamRecordWordType;
extern "C" {
extern char lbl_8028F698[];
void* fn_8028FAF4(void*, void*, StreamRecordWordType, StreamRecordWordType);
void* fn_8028FF24(void*, StreamRecordWordType);
void fn_8028FD50(void*, void*, StreamRecordWordType);
void fn_80243E44(void*, void*);
void*fn_801D52EC(void*);
void __construct_array(void*,void*(*)(void*),void*,unsigned long,unsigned long);
void* fn_801E9F40(void*, void*, StreamRecordWordType);
}
inline void* operator new(StreamRecordWordType, void* address)
{
    return address;
}
struct StreamRecordVector {float x,y,z;StreamRecordVector(){}~StreamRecordVector(){}};
struct StreamRecordElement {char data[28];};
struct StreamRecordRow {char unknown00[24];StreamRecordElement elements[8];StreamRecordRow(){__construct_array(elements,fn_801D52EC,0,sizeof(StreamRecordElement),8);}~StreamRecordRow(){}};
template<class T> struct StreamRecordArray {
    int count;
    int capacity;
    T* items;

    inline void storage(int size)
    {
        if (size) {
            if (items)
                items = (T*)fn_8028FAF4(lbl_8028F698, items,
                    capacity * sizeof(T), size * sizeof(T));
            else
                items = (T*)fn_8028FF24(lbl_8028F698, size * sizeof(T));
        } else if (items) {
            fn_8028FD50(lbl_8028F698, items, capacity * sizeof(T));
            items = 0;
        }
    }

    inline void resize(int size)
    {
        int i;
        if (size > count) {
            storage(size);
            capacity = size;
            for (i = count; i < size; ++i)
                new (&items[i]) T;
            count = size;
        } else if (size < count) {
            for (i = count - 1; i >= size; --i)
                items[i].~T();
            storage(size);
            capacity = size;
            count = size;
        }
    }
};


struct StreamRecordOwner {
 char unknown00[0x74];
 StreamRecordArray<StreamRecordVector> vectors;
 StreamRecordArray<StreamRecordRow> rows;
 char tail[20];
};
extern "C" void fn_801D4F98(StreamRecordOwner*self,void**stream){
 fn_80243E44(self,stream);
 int count;
 *stream=fn_801E9F40(&count,*stream,4);
 self->vectors.resize(count);
 *stream=fn_801E9F40(self->vectors.items,*stream,count*sizeof(StreamRecordVector));
 *stream=fn_801E9F40(&count,*stream,4);
 self->rows.resize(count);
 *stream=fn_801E9F40(self->rows.items,*stream,count*sizeof(StreamRecordRow));
 *stream=fn_801E9F40(self->tail,*stream,sizeof(self->tail));
}
