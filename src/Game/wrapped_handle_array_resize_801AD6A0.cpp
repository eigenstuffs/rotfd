/* Wrapped Handle array resize reconstruction; see docs/notes/game-wrapped-handle-array-resize.md. */
typedef unsigned long WrappedHandleResizeWord;
extern "C"{extern char lbl_8028F698[];void*fn_8028FAF4(void*,void*,WrappedHandleResizeWord,WrappedHandleResizeWord);void*fn_8028FF24(void*,WrappedHandleResizeWord);void fn_8028FD50(void*,void*,WrappedHandleResizeWord);extern struct{char unknown00[0x118];void*manager;}lbl_801E9D24;void fn_801F86C8(void*,const void*,short);}
inline void*operator new(unsigned long,void*p){return p;}
struct Handle_801F7F10{WrappedHandleResizeWord value;Handle_801F7F10();~Handle_801F7F10();};
struct WrappedHandleResizeZero:Handle_801F7F10{WrappedHandleResizeZero(){value=0;}~WrappedHandleResizeZero(){}};
struct WrappedHandleResizeHandle:WrappedHandleResizeZero{WrappedHandleResizeHandle(){value=0;}~WrappedHandleResizeHandle(){}WrappedHandleResizeHandle&operator=(const WrappedHandleResizeHandle&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);return *this;}};
struct WrappedHandleResizeKey{unsigned short key;WrappedHandleResizeKey(){key=0;}};
struct WrappedHandleResizeRow:WrappedHandleResizeKey{WrappedHandleResizeHandle handle;char unknown08[20];WrappedHandleResizeRow(){handle=WrappedHandleResizeHandle();}~WrappedHandleResizeRow(){}};
template<class T>struct WrappedHandleResizeArray{int count,capacity;T*items;
 void reserve(int n){if(n){if(items)items=(T*)fn_8028FAF4(lbl_8028F698,items,capacity*sizeof(T),n*sizeof(T));else items=(T*)fn_8028FF24(lbl_8028F698,n*sizeof(T));}else if(items){fn_8028FD50(lbl_8028F698,items,capacity*sizeof(T));items=0;}capacity=n;}
};
extern "C"void fn_801AD6A0(WrappedHandleResizeArray<WrappedHandleResizeRow>*self,int n,signed char keep){int i;
 if(n>self->count){if(n>self->capacity||!keep)self->reserve(n);for(i=self->count;i<n;++i)new(self->items+i)WrappedHandleResizeRow;self->count=n;}
 else if(n<self->count){for(i=self->count-1;i>=n;--i)self->items[i].~WrappedHandleResizeRow();if(keep)self->count=n;else{self->reserve(n);self->count=n;}}
}
