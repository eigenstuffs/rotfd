typedef unsigned long FloatRecordWordType;
extern "C" {
extern char lbl_8028F698[];
void* fn_8028FAF4(void*, void*, FloatRecordWordType, FloatRecordWordType);
void* fn_8028FF24(void*, FloatRecordWordType);
void fn_8028FD50(void*, void*, FloatRecordWordType);
}
inline void* operator new(FloatRecordWordType, void* address)
{
    return address;
}
struct FloatRecord {float first,second,third,fourth,fifth,sixth,seventh,eighth;FloatRecord(){}~FloatRecord(){}};
struct FloatRecordArray {
 int count,capacity;FloatRecord*items;
 inline void storage(int size){
 if(size){if(items)items=(FloatRecord*)fn_8028FAF4(lbl_8028F698,items,capacity*sizeof(FloatRecord),size*sizeof(FloatRecord));else items=(FloatRecord*)fn_8028FF24(lbl_8028F698,size*sizeof(FloatRecord));}
 else if(items){fn_8028FD50(lbl_8028F698,items,capacity*sizeof(FloatRecord));items=0;}
 }
 inline void resize(int size,int keep){int i;if(size>count){if(!keep||size>capacity){storage(size);capacity=size;}for(i=count;i<size;++i)new(&items[i])FloatRecord;count=size;}else if(size<count){for(i=count-1;i>=size;--i)items[i].~FloatRecord();if(!keep){storage(size);capacity=size;}count=size;}}
 inline void reserve(int size){if(size<count)resize(size,0);else{storage(size);capacity=size;}}
 inline void append(const FloatRecord&value){if(count+1>capacity){storage(capacity+64);capacity+=64;}new(&items[count++])FloatRecord(value);}
};
extern "C" FloatRecordArray*fn_801C33F4(FloatRecordArray*self,const FloatRecordArray&other){self->resize(0,1);self->reserve(other.count);for(int i=0;i<other.count;++i)self->append(other.items[i]);return self;}
