/* Timed action query over frame-keyed action rows, reconstructed from GSQE78.
 * Collects every action entry whose row frame lies in [start, end] into a
 * caller-provided 44-byte event buffer; a wrapped interval (end < start) is
 * split into [start, length] and [0, end]. See docs/notes/game-resource-actions.md. */
typedef unsigned long u32;
struct RefEntry {int type;u32 reference,unknown;};
/* Event record (stride 44). Its copy constructor clears the third entry word
 * before copying and leaves the trailing flag word untouched. */
struct Record {
    RefEntry entry;float time;u32 extra[6];char flags[4];
    Record(){entry.unknown=0;}
    Record(const Record&v){entry.unknown=0;entry=v.entry;time=v.time;for(int i=0;i<6;++i)extra[i]=v.extra[i];}
    Record operator=(const RefEntry&e){entry=e;return *this;}
};
template<class T>struct RefArray {short id;int size,capacity;T*data;T&operator[](int i){return data[i];}};
struct RefRow:RefArray<RefEntry>{
    float getTime()const{return (1.0f/60.0f)*id;}
    int getSize()const{return size;}
};
struct ActionList:RefArray<RefRow>{u32 extra;};
extern "C" {
int fn_801F72E4(ActionList*o,float start,float end,float length,Record*buffer,int*count,char mode){
    if(end<start){
        fn_801F72E4(o,start,length,length,buffer,count,0);
        return fn_801F72E4(o,0.0f,end,length,buffer,count,0);
    }
    int first=-1,last=-1;int i;
    for(i=0;i<o->size;++i)if((*o)[i].getTime()>=start){first=i;break;}
    for(i=o->size-1;i>=0;--i)if((*o)[i].getTime()<=end){last=i;break;}
    if(last>=0&&first>=0)
        for(int i=first;i<=last;++i)
            for(int j=0;j<(*o)[i].getSize();++j){
                buffer[*count]=(*o)[i][j];
                buffer[(*count)++].time=(*o)[i].getTime();
            }
    return last;
}
}
