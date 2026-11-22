struct Prefix { unsigned long unknown; };
struct HashKey : Prefix {
    virtual void dispose();
    virtual int hash();
    virtual int stride();
    virtual signed char equals(HashKey*);
    virtual void unknown18();
    virtual HashKey* clone();
};
struct HashTable { int cursor,capacity,count; HashKey**slots; };
extern "C" {
void fn_801EF610(void*,void*);
extern char lbl_801EF5C8[];
extern const char lbl_802ADCF0[],lbl_802ADD00[];
void*fn_801EFA1C(void*,unsigned long,const char*,const char*,int,int);
void*memset(void*,int,unsigned long);
void fn_802086C8(HashTable*,signed char);
void fn_80207FDC(HashTable*,int);
signed char fn_802083C8(HashTable*,HashKey*,HashKey**,signed char);
static inline void resize_inner(HashTable*t,int size){long i;
 int oldsize=t->capacity;HashKey**old=t->slots;
 t->capacity=size;t->count=0;
 t->slots=(HashKey**)fn_801EFA1C(lbl_801EF5C8,t->capacity*sizeof(HashKey*),lbl_802ADCF0,lbl_802ADD00,0x1D7,4);
 memset(t->slots,0,t->capacity*sizeof(HashKey*));
 for(i=0;i<oldsize;++i){
  if(old[i] && old[i]!=(HashKey*)-1){HashKey*out;fn_802083C8(t,old[i],&out,0);}
 }
 if(oldsize>0)fn_801EF610(lbl_801EF5C8,old);
}
static inline signed char insert_middle(HashTable*t,HashKey*key,HashKey**out,signed char clone){
 int index=(t->capacity-1)&key->hash();
 int step=key->stride();if(!(step&1))++step;
 int deleted=-1;
 for(;;){
  HashKey*p=t->slots[index];
  if(!p){
   if(deleted>0)index=deleted;
   if(clone)t->slots[index]=key->clone();else t->slots[index]=key;
   *out=t->slots[index];++t->count;
   if(t->count*5>t->capacity*3)resize_inner(t,t->capacity*2);
   return 1;
  }
  if(p==(HashKey*)-1){if(deleted<0)deleted=index;}
  else if(p->equals(key)){*out=t->slots[index];return 0;}
  index=(t->capacity-1)&(index+step);
 }
}
void fn_80207FDC(HashTable*t,int size){long i;
 int oldsize=t->capacity;HashKey**old=t->slots;
 t->capacity=size;t->count=0;
 t->slots=(HashKey**)fn_801EFA1C(lbl_801EF5C8,t->capacity*sizeof(HashKey*),lbl_802ADCF0,lbl_802ADD00,0x1D7,4);
 memset(t->slots,0,t->capacity*sizeof(HashKey*));
 for(i=0;i<oldsize;++i){
  if(old[i] && old[i]!=(HashKey*)-1){HashKey*out;insert_middle(t,old[i],&out,0);}
 }
 if(oldsize>0)fn_801EF610(lbl_801EF5C8,old);
}
}
