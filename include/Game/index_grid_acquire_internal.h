#ifndef GAME_INDEX_GRID_ACQUIRE_INTERNAL_H
#define GAME_INDEX_GRID_ACQUIRE_INTERNAL_H

extern "C" {
extern char lbl_8028F698[];
void*fn_8028FAF4(void*,void*,unsigned long,unsigned long);
void*fn_8028FF24(void*,unsigned long);
void fn_8028FD50(void*,void*,unsigned long);
}
inline void*operator new(unsigned long,void*p){return p;}
struct IndexGridAcquireRecord {int previous,next,chain,cell;void*context;IndexGridAcquireRecord():context(0){}~IndexGridAcquireRecord(){}};
struct IndexGridAcquireArray {
 int count,capacity;IndexGridAcquireRecord*data;
 IndexGridAcquireRecord&operator[](int i){return data[i];}
 void storage(int n){
  if(n){if(data)data=(IndexGridAcquireRecord*)fn_8028FAF4(lbl_8028F698,data,capacity*sizeof(IndexGridAcquireRecord),n*sizeof(IndexGridAcquireRecord));else data=(IndexGridAcquireRecord*)fn_8028FF24(lbl_8028F698,n*sizeof(IndexGridAcquireRecord));}
  else if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(IndexGridAcquireRecord));data=0;}
  capacity=n;
 }
 void resize(int n){
  if(n>count){storage(n);for(int i=count;i<n;++i)new(data+i)IndexGridAcquireRecord;count=n;}
  else if(n<count){for(int i=count-1;i>=n;--i)data[i].~IndexGridAcquireRecord();storage(n);count=n;}
 }
};
struct IndexGridAcquireView {char unknown00[0x18];int columns,unknown1C,freeHead,freeCount;char heads[12];IndexGridAcquireArray records;};

typedef char CheckIndexGridAcquireRecord[sizeof(IndexGridAcquireRecord)==20?1:-1];
typedef char CheckIndexGridAcquireArray[sizeof(IndexGridAcquireArray)==12?1:-1];
typedef char CheckIndexGridAcquireView[sizeof(IndexGridAcquireView)==0x40?1:-1];
#endif
