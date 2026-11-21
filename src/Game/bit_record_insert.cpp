extern "C" {extern char lbl_8028F698[];void*fn_8028FAF4(void*,void*,unsigned long,unsigned long);void*fn_8028FF24(void*,unsigned long);void fn_8028FD50(void*,void*,unsigned long);}
struct BitRecordWords {int count,capacity;unsigned long*words;
 void reserve(int n){if(n){if(words)words=(unsigned long*)fn_8028FAF4(lbl_8028F698,words,capacity*4,n*4);else words=(unsigned long*)fn_8028FF24(lbl_8028F698,n*4);}else if(words){fn_8028FD50(lbl_8028F698,words,capacity*4);words=0;}capacity=n;}
 void resize(int n){if(n>count){reserve(n);for(int i=count;i<n;++i){}count=n;}else if(n<count){for(int i=count-1;i>=n;--i){}reserve(n);count=n;}}
};
struct BitRecordOwner {int count,capacity;char*records;BitRecordWords storage;int size,initialized,used;
 void setSize(int n){size=n;if(n&&((n>>5)+1)>storage.count)storage.resize((size>>5)+1);}
 void setBit(int i){storage.words[i>>5]|=1UL<<(i&31);}
};
extern "C" {void fn_80227380(BitRecordOwner*,int,int);void fn_80207DE4(BitRecordWords*,int,int);int fn_80207B94(BitRecordWords*,int,int);void fn_80225C58(BitRecordOwner*,const void*);void fn_80225A50(void*,const void*);}
static inline int findBitRecord(BitRecordOwner*self){if(self->initialized==0){return -1;}else{return fn_80207B94(&self->storage,0,0);}}
extern "C" int fn_802257EC(BitRecordOwner*self,const void*record){int index=findBitRecord(self);++self->used;if(index==-1){fn_80225C58(self,record);self->setSize(self->initialized+1);self->setBit(self->initialized);return self->initialized++;}fn_80225A50(self->records+index*0xA8,record);self->setBit(index);return index;}
