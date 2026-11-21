/* Typed actor Handle-array assignment; see docs/notes/game-early-actor-handle-array-assign.md. */
extern "C" {
extern char lbl_8028F698[],lbl_801EF5C8[];
void*fn_8028FAF4(void*,void*,int,int);void*fn_8028FF24(void*,int);void fn_8028FD50(void*,void*,int);
void fn_801EF610(void*,void*);void fn_801F86C8(void*,const void*,int);
struct AssignGlobals_8008AC5C{char unknown[0x118];void*manager;};
extern AssignGlobals_8008AC5C lbl_801E9D24;
}
inline void*operator new(unsigned long,void*p){return p;}
struct Handle_801F7F10{unsigned long value;Handle_801F7F10();~Handle_801F7F10();};
struct AssignZero_8008AC5C:Handle_801F7F10{AssignZero_8008AC5C(){value=0;}~AssignZero_8008AC5C(){}};
struct Handle_80020834:AssignZero_8008AC5C{
 Handle_80020834(){value=0;}~Handle_80020834(){}
 static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
};
struct AssignHandle_8008AC5C:Handle_80020834{
 AssignHandle_8008AC5C(){value=0;}
 AssignHandle_8008AC5C(const AssignHandle_8008AC5C&other){value=other.value;fn_801F86C8(lbl_801E9D24.manager,&other,1);}
 ~AssignHandle_8008AC5C(){}
};
inline void constructAssign(AssignHandle_8008AC5C*p){new(p)AssignHandle_8008AC5C;}
struct AssignArray_8008AC5C{
 int count,capacity;AssignHandle_8008AC5C*data;
 void reserve(int n){
  if(n){if(data)data=(AssignHandle_8008AC5C*)fn_8028FAF4(lbl_8028F698,data,capacity*4,n*4);else data=(AssignHandle_8008AC5C*)fn_8028FF24(lbl_8028F698,n*4);}
  else if(data){fn_8028FD50(lbl_8028F698,data,capacity*4);data=0;}
  capacity=n;
 }
 void resize(int n,signed char keep){int i;
  if(n>count){if(n>capacity||!keep)reserve(n);for(i=count;i<n;++i)constructAssign(&data[i]);count=n;}
  else if(n<count){for(i=count-1;i>=n;--i)data[i].~AssignHandle_8008AC5C();if(keep)count=n;else{reserve(n);count=n;}}
 }
 void append(const AssignHandle_8008AC5C&other){
  if(count+1>capacity){int n=capacity+8;
   if(n){if(data)data=(AssignHandle_8008AC5C*)fn_8028FAF4(lbl_8028F698,data,capacity*4,n*4);else data=(AssignHandle_8008AC5C*)fn_8028FF24(lbl_8028F698,n*4);}
   else if(data){fn_8028FD50(lbl_8028F698,data,capacity*4);data=0;}
   capacity+=8;
  }
  new(&data[count++])AssignHandle_8008AC5C(other);
 }
};
extern "C"void fn_8008AE74(AssignArray_8008AC5C*,int);
extern "C"AssignArray_8008AC5C*fn_8008AC5C(AssignArray_8008AC5C*self,const AssignArray_8008AC5C*other){
 self->resize(0,1);fn_8008AE74(self,other->count);
 for(int i=0;i<other->count;++i)self->append(other->data[i]);
 return self;
}
