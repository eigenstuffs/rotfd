extern "C" int strcmp(const char*,const char*);
/* Python pointer-name decoding with original move-to-front type conversion. */
typedef unsigned long Word;
struct PyObject;
struct PyType { char unknown00[0x18]; void(*destroy)(PyObject*); };
struct PyObject { int references; PyType*type; };
inline void release(PyObject*object){if(--object->references==0)object->type->destroy(object);}
struct NativeType {
 const char*name;
 void*(*convert)(void*);
 Word unknown08;
 NativeType*next;
 NativeType*previous;
 NativeType*check(const char*text){
  if(!this)return 0;
  NativeType*current=next;
  while(current){
   if(!strcmp(current->name,text)){
    if(current==next)return current;
    current->previous->next=current->next;
    if(current->next)current->next->previous=current->previous;
    current->next=next;
    if(next)next->previous=current;
    next=current;
    return current;
   }
   current=current->next;
  }
  return 0;
 }
 void*cast(void*value){if(!this||!convert)return value;return convert(value);}
};
extern "C" {
extern PyObject _Py_NoneStruct;extern PyType PyString_Type;extern PyObject*PyExc_TypeError;
extern PyObject*lbl_80377894;extern signed char lbl_80377898;
extern const char lbl_803796FC[5],lbl_80379704[5],lbl_802A2AA0[];
extern unsigned char lbl_801EF5C8[];
PyObject*PyString_InternFromString(const char*);PyObject*PyObject_GetAttr(PyObject*,PyObject*);char*PyString_AsString(PyObject*);
Word strlen(const char*);int sprintf(char*,const char*,...);void PyErr_SetString(PyObject*,const char*);
void*fn_801EFA1C(void*,Word,const char*,const char*,int,int);void fn_801EF610(void*,void*);
}
extern "C" int fn_800CD864(PyObject*object,void**pointer,NativeType*type,int flags){
 const char*strings=lbl_802A2AA0;
 if(!lbl_80377898){lbl_80377894=0;lbl_80377898=1;}
 Word value;int owned=0;
 if(!object||object==&_Py_NoneStruct){*pointer=0;return 0;}
 if(object->type!=&PyString_Type){
  if(!lbl_80377894)lbl_80377894=PyString_InternFromString(lbl_803796FC);
  object=PyObject_GetAttr(object,lbl_80377894);owned=1;
  if(!object)goto fail;
  if(object->type!=&PyString_Type){release(object);goto fail;}
 }
 {
 char*text=PyString_AsString(object);value=0;
 if(*text!='_'){
  *pointer=0;
  if(!strcmp(text,lbl_80379704)){if(owned)release(object);return 0;}
  if(owned)release(object);
  goto fail;
 }
 char*cursor=text+1;
 int digit;
 while((digit=*cursor)){
  if(digit>='0'&&digit<='9')value=(value<<4)+(digit-'0');
  else if(digit>='a'&&digit<='f')value=(value<<4)+(digit-('a'-10));
  else break;
  ++cursor;
 }
 *pointer=(void*)value;
 if(owned)release(object);
 if(type){
  NativeType*conversion=type->check(cursor);
  if(!conversion)goto fail;
  *pointer=conversion->cast((void*)value);
 }
 return 0;
 }
 fail:
 if(flags){
  if(type){
   char*message=(char*)fn_801EFA1C(lbl_801EF5C8,strlen(type->name)+64,strings+0x50,strings+0x60,0x18F,4);
   sprintf(message,strings+0x74,type->name);
   PyErr_SetString(PyExc_TypeError,message);
   fn_801EF610(lbl_801EF5C8,message);
  }else PyErr_SetString(PyExc_TypeError,strings+0x8C);
 }
 return -1;
}
