/* Nested Handle record array resize reconstruction; see docs/notes/game-nested-handle-records-resize.md. */
typedef unsigned long NestedHandleResizeWord;
extern "C"{extern char lbl_8028F698[];void*fn_8028FAF4(void*,void*,NestedHandleResizeWord,NestedHandleResizeWord);void*fn_8028FF24(void*,NestedHandleResizeWord);void fn_8028FD50(void*,void*,NestedHandleResizeWord);}
inline void*operator new(unsigned long,void*p){return p;}
struct Handle_801F7F10{NestedHandleResizeWord value;Handle_801F7F10();~Handle_801F7F10();};
struct NestedHandleResizeLayer:Handle_801F7F10{~NestedHandleResizeLayer(){}};
struct NestedHandleResizeElement:NestedHandleResizeLayer{NestedHandleResizeWord tail;~NestedHandleResizeElement(){}};
template<class T>struct NestedHandleResizeArray{
 int count,capacity;T*items;
 NestedHandleResizeArray(){count=0;capacity=0;items=0;}
 void reserve(int n){if(n){if(items)items=(T*)fn_8028FAF4(lbl_8028F698,items,capacity*sizeof(T),n*sizeof(T));else items=(T*)fn_8028FF24(lbl_8028F698,n*sizeof(T));}else if(items){fn_8028FD50(lbl_8028F698,items,capacity*sizeof(T));items=0;}capacity=n;}
 ~NestedHandleResizeArray(){if(items){for(int i=0;i<count;++i)items[i].~T();if(items){fn_8028FD50(lbl_8028F698,items,capacity*sizeof(T));items=0;}items=0;}}
};
struct NestedHandleResizeKey{unsigned short key;NestedHandleResizeKey(){key=0;}};
struct NestedHandleResizeRow:NestedHandleResizeKey{NestedHandleResizeArray<NestedHandleResizeElement>records;NestedHandleResizeRow(){}~NestedHandleResizeRow(){}};
extern "C"void fn_801AD438(NestedHandleResizeArray<NestedHandleResizeRow>*self,int n,signed char keep){
 int i;
 if(n>self->count){if(n>self->capacity||!keep)self->reserve(n);for(i=self->count;i<n;++i)new(self->items+i)NestedHandleResizeRow;self->count=n;}
 else if(n<self->count){for(i=self->count-1;i>=n;--i)self->items[i].~NestedHandleResizeRow();if(keep)self->count=n;else{self->reserve(n);self->count=n;}}
}
