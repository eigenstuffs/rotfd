/* Nested integer-array membership lookup reconstructed from GSQE78. */
struct IntArray { int count,capacity; int* data; int getCount()const{return count;} int&at(const int&i){return data[i];} };
struct ArrayOwner { char unknown00[0x70]; int count,capacity; IntArray* records; IntArray&at(const int&i){return records[i];} };
extern "C" int fn_8024A800(ArrayOwner*self,int key){
 for(int i=0;i<self->count;++i){
  for(int j=0;j<self->at(i).getCount();++j){
   if(self->at(i).at(j)==key)return i;
  }
 }
 return -1;
}
