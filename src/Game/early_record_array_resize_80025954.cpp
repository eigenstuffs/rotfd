/* Native record-array resize; see docs/notes/game-early-record-array-resize.md. */
extern "C" {
extern char lbl_8028F698[];
void*fn_8028FAF4(void*,void*,int,int);
void*fn_8028FF24(void*,int);
void fn_8028FD50(void*,void*,int);
extern const float lbl_80378250;
struct ArrayResizeVector_80025954 {float x,y,z,w;};
extern ArrayResizeVector_80025954 game_vec4_zero;
}
inline void*operator new(unsigned long,void*p){return p;}
struct Handle_801F7F10 {unsigned long value;Handle_801F7F10();~Handle_801F7F10();};
struct ResizeHandleBase_80025954:Handle_801F7F10 {ResizeHandleBase_80025954(){value=0;}~ResizeHandleBase_80025954(){}};
struct ResizeHandle_80025954:ResizeHandleBase_80025954 {ResizeHandle_80025954(){value=0;}~ResizeHandle_80025954(){}};
struct ResizeRecordBase_80025954 {
 int key;ResizeHandle_80025954 handle;float a,b,c,d;
 ResizeRecordBase_80025954():key(0) {a=game_vec4_zero.x;b=game_vec4_zero.y;c=game_vec4_zero.z;d=lbl_80378250;}
 ~ResizeRecordBase_80025954(){}
};
struct ResizeRecord_80025954:ResizeRecordBase_80025954 {ResizeRecord_80025954(){}~ResizeRecord_80025954(){}};
typedef char ResizeRecordSize[sizeof(ResizeRecord_80025954)==24?1:-1];
struct ResizeArray_80025954 {
 int count,capacity;ResizeRecord_80025954*data;
 void reserve(int n){
  if(n){
   if(data)data=(ResizeRecord_80025954*)fn_8028FAF4(lbl_8028F698,data,capacity*sizeof(ResizeRecord_80025954),n*sizeof(ResizeRecord_80025954));
   else data=(ResizeRecord_80025954*)fn_8028FF24(lbl_8028F698,n*sizeof(ResizeRecord_80025954));
  }else if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(ResizeRecord_80025954));data=0;}
  capacity=n;
 }
};
extern "C" void fn_80025954(ResizeArray_80025954*self,int n,signed char keep){int shrinkIndex;
 if(n>self->count){
  if(n>self->capacity||!keep)self->reserve(n);
  for(int i=self->count;i<n;++i)new(&self->data[i])ResizeRecord_80025954;
  self->count=n;
 }else if(n<self->count){
  for(shrinkIndex=self->count-1;shrinkIndex>=n;--shrinkIndex)self->data[shrinkIndex].~ResizeRecord_80025954();
  if(keep)self->count=n;
  else {self->reserve(n);self->count=n;}
 }
}
