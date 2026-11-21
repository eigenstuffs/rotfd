#ifndef GAME_FIXED_RECORD_COPY_INTERNAL_H
#define GAME_FIXED_RECORD_COPY_INTERNAL_H

inline void*operator new(unsigned long,void*p){return p;}
struct FixedRecordVector3{float x,y,z;FixedRecordVector3(){}FixedRecordVector3(const FixedRecordVector3&v):x(v.x),y(v.y),z(v.z){}};
struct FixedRecord40 {
 FixedRecordVector3 point;float distance;FixedRecordVector3 normal;void*object;unsigned long long token;
 FixedRecord40():object(0){}~FixedRecord40(){}
 FixedRecord40(const FixedRecord40&v):point(v.point),distance(v.distance),normal(v.normal),object(v.object),token(v.token){}
};
struct FixedRecordArray256{
 FixedRecord40 data[256];int count;
 FixedRecord40&operator[](unsigned int i){return data[i];}
 const FixedRecord40&operator[](unsigned int i)const{return data[i];}
 void resize(int n){if(n>count){for(int i=count;i<n;++i)new(&(*this)[i])FixedRecord40;}else if(n<count){for(int i=count-1;i>=n;--i)data[i].~FixedRecord40();}count=n;}
 void append(const FixedRecord40&r){if(count>=256)new(&(*this)[255])FixedRecord40(r);else new(&(*this)[count++])FixedRecord40(r);}
};

typedef char CheckFixedRecordCopyElement[sizeof(FixedRecord40)==40?1:-1];
#endif
