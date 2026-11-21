/* Typed actor Handle-array capacity; see docs/notes/game-early-actor-handle-array-capacity.md. */
extern "C" {
extern char lbl_8028F698[];
void* fn_8028FAF4(void*, void*, int, int);
void* fn_8028FF24(void*, int);
void fn_8028FD50(void*, void*, int);
}
inline void* operator new(unsigned long, void* p) { return p; }
struct Handle_801F7F10 { unsigned long value; Handle_801F7F10(); ~Handle_801F7F10(); };
struct CapacityZero1_8008AE74 : Handle_801F7F10 {
 CapacityZero1_8008AE74() { value=0; }
 ~CapacityZero1_8008AE74() {}
};
struct CapacityZero2_8008AE74 : CapacityZero1_8008AE74 {
 CapacityZero2_8008AE74() { value=0; }
 ~CapacityZero2_8008AE74() {}
};
struct CapacityHandle_8008AE74 : CapacityZero2_8008AE74 {
 CapacityHandle_8008AE74() { value=0; }
 ~CapacityHandle_8008AE74() {}
};
struct CapacityArray_8008AE74 {
 int count, capacity; CapacityHandle_8008AE74* data;
 void reserve(int n) {
  if(n) {
   if(data) data=(CapacityHandle_8008AE74*)fn_8028FAF4(lbl_8028F698,data,capacity*4,n*4);
   else data=(CapacityHandle_8008AE74*)fn_8028FF24(lbl_8028F698,n*4);
  } else if(data) { fn_8028FD50(lbl_8028F698,data,capacity*4); data=0; }
  capacity=n;
 }
 void resize(int n) {
  int i;
  if(n>count) {
   reserve(n);
   for(i=count;i<n;++i) new(&data[i]) CapacityHandle_8008AE74;
   count=n;
  } else if(n<count) {
   for(i=count-1;i>=n;--i) data[i].~CapacityHandle_8008AE74();
   reserve(n); count=n;
  }
 }
};

extern "C" void fn_8008AE74(CapacityArray_8008AE74* self, int n) {
 if(n<self->count) self->resize(n);
 else self->reserve(n);
}
