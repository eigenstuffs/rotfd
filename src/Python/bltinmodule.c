/* Adapted from CPython 2.1, Python/bltinmodule.c.
 * Copyright (c) 2001 Python Software Foundation; All Rights Reserved.
 * License: reference/cpython-2.1/LICENSE.
 * Changes: recovered target ABI and disabled threading/FPE/assertion macros.
 * Original text: 0x801A387C..0x801A7628.
 */
#include "object.h"
typedef struct _FILE { char contents[80]; } FILE;
typedef unsigned int size_t;
typedef PyObject * (*unaryfunc)(PyObject *);
typedef PyObject * (*binaryfunc)(PyObject *, PyObject *);
typedef PyObject * (*ternaryfunc)(PyObject *, PyObject *, PyObject *);
typedef int (*inquiry)(PyObject *);
typedef int (*coercion)(PyObject **, PyObject **);
typedef PyObject *(*intargfunc)(PyObject *, int);
typedef PyObject *(*intintargfunc)(PyObject *, int, int);
typedef int(*intobjargproc)(PyObject *, int, PyObject *);
typedef int(*intintobjargproc)(PyObject *, int, int, PyObject *);
typedef int(*objobjargproc)(PyObject *, PyObject *, PyObject *);
typedef int (*getreadbufferproc)(PyObject *, int, void **);
typedef int (*getwritebufferproc)(PyObject *, int, void **);
typedef int (*getsegcountproc)(PyObject *, int *);
typedef int (*getcharbufferproc)(PyObject *, int, const char **);
typedef int (*objobjproc)(PyObject *, PyObject *);
typedef int (*visitproc)(PyObject *, void *);
typedef int (*traverseproc)(PyObject *, visitproc, void *);

typedef struct {

	binaryfunc nb_add;
	binaryfunc nb_subtract;
	binaryfunc nb_multiply;
	binaryfunc nb_divide;
	binaryfunc nb_remainder;
	binaryfunc nb_divmod;
	ternaryfunc nb_power;
	unaryfunc nb_negative;
	unaryfunc nb_positive;
	unaryfunc nb_absolute;
	inquiry nb_nonzero;
	unaryfunc nb_invert;
	binaryfunc nb_lshift;
	binaryfunc nb_rshift;
	binaryfunc nb_and;
	binaryfunc nb_xor;
	binaryfunc nb_or;
	coercion nb_coerce;
	unaryfunc nb_int;
	unaryfunc nb_long;
	unaryfunc nb_float;
	unaryfunc nb_oct;
	unaryfunc nb_hex;
	binaryfunc nb_inplace_add;
	binaryfunc nb_inplace_subtract;
	binaryfunc nb_inplace_multiply;
	binaryfunc nb_inplace_divide;
	binaryfunc nb_inplace_remainder;
	ternaryfunc nb_inplace_power;
	binaryfunc nb_inplace_lshift;
	binaryfunc nb_inplace_rshift;
	binaryfunc nb_inplace_and;
	binaryfunc nb_inplace_xor;
	binaryfunc nb_inplace_or;
} PyNumberMethods;

typedef struct {
	inquiry sq_length;
	binaryfunc sq_concat;
	intargfunc sq_repeat;
	intargfunc sq_item;
	intintargfunc sq_slice;
	intobjargproc sq_ass_item;
	intintobjargproc sq_ass_slice;
	objobjproc sq_contains;
	binaryfunc sq_inplace_concat;
	intargfunc sq_inplace_repeat;
} PySequenceMethods;

typedef struct {
	inquiry mp_length;
	binaryfunc mp_subscript;
	objobjargproc mp_ass_subscript;
} PyMappingMethods;

typedef struct {
	getreadbufferproc bf_getreadbuffer;
	getwritebufferproc bf_getwritebuffer;
	getsegcountproc bf_getsegcount;
	getcharbufferproc bf_getcharbuffer;
} PyBufferProcs;

typedef void (*destructor)(PyObject *);
typedef int (*printfunc)(PyObject *, FILE *, int);
typedef PyObject *(*getattrfunc)(PyObject *, char *);
typedef PyObject *(*getattrofunc)(PyObject *, PyObject *);
typedef int (*setattrfunc)(PyObject *, char *, PyObject *);
typedef int (*setattrofunc)(PyObject *, PyObject *, PyObject *);
typedef int (*cmpfunc)(PyObject *, PyObject *);
typedef PyObject *(*reprfunc)(PyObject *);
typedef long (*hashfunc)(PyObject *);
typedef PyObject *(*richcmpfunc) (PyObject *, PyObject *, int);

struct _typeobject {
	PyObject_VAR_HEAD
	char *tp_name; 
	int tp_basicsize, tp_itemsize; 

	destructor tp_dealloc;
	printfunc tp_print;
	getattrfunc tp_getattr;
	setattrfunc tp_setattr;
	cmpfunc tp_compare;
	reprfunc tp_repr;

	PyNumberMethods *tp_as_number;
	PySequenceMethods *tp_as_sequence;
	PyMappingMethods *tp_as_mapping;

	hashfunc tp_hash;
	ternaryfunc tp_call;
	reprfunc tp_str;
	getattrofunc tp_getattro;
	setattrofunc tp_setattro;

	PyBufferProcs *tp_as_buffer;

	long tp_flags;

	char *tp_doc; 

	traverseproc tp_traverse;

	inquiry tp_clear;

	richcmpfunc tp_richcompare;

	long tp_weaklistoffset;

};

typedef struct {
    PyObject_HEAD
    PyObject	*cl_bases;	
    PyObject	*cl_dict;	
    PyObject	*cl_name;	
    
    PyObject	*cl_getattr;
    PyObject	*cl_setattr;
    PyObject	*cl_delattr;
} PyClassObject;

typedef struct {
    PyObject_HEAD
    PyClassObject *in_class;	
    PyObject	  *in_dict;	
    PyObject	  *in_weakreflist; 
} PyInstanceObject;

typedef struct {
    PyObject_HEAD
    PyObject *im_func;   
    PyObject *im_self;   
    PyObject *im_class;  
    PyObject *im_weakreflist; 
} PyMethodObject;

typedef struct {
    PyObject_HEAD
    PyObject *func_code;
    PyObject *func_globals;
    PyObject *func_defaults;
    PyObject *func_closure;
    PyObject *func_doc;
    PyObject *func_name;
    PyObject *func_dict;
    PyObject *func_weakreflist;
} PyFunctionObject;

typedef struct { PyObject_VAR_HEAD long ob_shash; PyObject *ob_sinterned; char ob_sval[1]; } PyStringObject;
typedef struct { PyObject_VAR_HEAD PyObject *ob_item[1]; } PyTupleObject;
struct memberlist { char *name; int type; int offset; int readonly; };
#define T_INT 1
#define T_OBJECT 6
#define offsetof(type, member) ((int)&((type *)0)->member)
#define assert(expr) ((void)0)
#define PyObject_HEAD_INIT(type) 1, type,
#define Py_TPFLAGS_DEFAULT 0x6B
#define Py_TPFLAGS_GC 0
#define Py_TPFLAGS_CHECKTYPES 0x10
#define Py_TPFLAGS_HAVE_WEAKREFS 0x40
#define _Py_NewReference(op) ((op)->ob_refcnt = 1)
#define _Py_Dealloc(op) (*(op)->ob_type->tp_dealloc)((PyObject *)(op))
#undef Py_DECREF
#define Py_DECREF(op) if (--(op)->ob_refcnt != 0) ; else _Py_Dealloc((PyObject *)(op))
#define Py_XINCREF(op) if ((op) == NULL) ; else Py_INCREF(op)
#define Py_XDECREF(op) if ((op) == NULL) ; else Py_DECREF(op)
#define Py_None (&_Py_NoneStruct)
#define Py_NotImplemented (&_Py_NotImplementedStruct)
#define Py_LT 0
#define Py_LE 1
#define Py_EQ 2
#define Py_NE 3
#define Py_GT 4
#define Py_GE 5
#define PyString_AS_STRING(op) (((PyStringObject *)(op))->ob_sval)
#define PyString_GET_SIZE(op) (((PyStringObject *)(op))->ob_size)
#define PyTuple_GET_ITEM(op, i) (((PyTupleObject *)(op))->ob_item[i])
extern PyTypeObject PyClass_Type;
#define PyClass_Check(op) ((op)->ob_type == &PyClass_Type)
extern PyTypeObject PyInstance_Type;
#define PyInstance_Check(op) ((op)->ob_type == &PyInstance_Type)
extern PyTypeObject PyMethod_Type;
#define PyMethod_Check(op) ((op)->ob_type == &PyMethod_Type)
extern PyTypeObject PyFunction_Type;
#define PyFunction_Check(op) ((op)->ob_type == &PyFunction_Type)
extern PyTypeObject PyDict_Type;
#define PyDict_Check(op) ((op)->ob_type == &PyDict_Type)
extern PyTypeObject PyString_Type;
#define PyString_Check(op) ((op)->ob_type == &PyString_Type)
extern PyTypeObject PyTuple_Type;
#define PyTuple_Check(op) ((op)->ob_type == &PyTuple_Type)
extern PyTypeObject PyInt_Type;
#define PyInt_Check(op) ((op)->ob_type == &PyInt_Type)
extern PyTypeObject PyType_Type;
extern PyObject _Py_NoneStruct, _Py_NotImplementedStruct;
extern PyObject * PyClass_New(PyObject *, PyObject *, PyObject *);
extern PyObject * PyInstance_New(PyObject *, PyObject *, PyObject *);
extern PyObject * PyInstance_NewRaw(PyObject *, PyObject *);
extern PyObject * PyMethod_New(PyObject *, PyObject *, PyObject *);
extern PyObject * PyMethod_Function(PyObject *);
extern PyObject * PyMethod_Self(PyObject *);
extern PyObject * PyMethod_Class(PyObject *);
extern int PyClass_IsSubclass(PyObject *, PyObject *);
extern PyObject * PySlice_New(PyObject* start, PyObject* stop, PyObject* step);
extern PyObject * PyTuple_New(int size);
extern int PyTuple_Size(PyObject *);
extern PyObject * PyTuple_GetItem(PyObject *, int);
extern PyObject * PyInt_FromLong(long);
extern long PyInt_AsLong(PyObject *);
extern void PyErr_SetString(PyObject *, const char *);
extern PyObject * PyErr_Occurred(void);
extern void PyErr_Clear(void);
extern void PyErr_Fetch(PyObject **, PyObject **, PyObject **);
extern void PyErr_Restore(PyObject *, PyObject *, PyObject *);
extern int PyErr_ExceptionMatches(PyObject *);
extern PyObject * PyErr_Format(PyObject *, const char *, ...);
extern void _PyErr_BadInternalCall(char *filename, int lineno);
extern void PyErr_WriteUnraisable(PyObject *);
extern PyObject * PyDict_New(void);
extern PyObject * PyDict_GetItem(PyObject *mp, PyObject *key);
extern int PyDict_SetItem(PyObject *mp, PyObject *key, PyObject *item);
extern int PyDict_DelItem(PyObject *mp, PyObject *key);
extern int PyDict_Size(PyObject *mp);
extern PyObject * PyDict_GetItemString(PyObject *dp, char *key);
extern PyObject * PyEval_CallObjectWithKeywords(PyObject *, PyObject *, PyObject *);
extern PyObject * PyEval_CallObject(PyObject *, PyObject *);
extern PyObject * PyEval_GetGlobals(void);
extern int PyEval_GetRestricted(void);
extern PyObject * PyMember_Get(char *, struct memberlist *, char *);
extern int PyObject_Cmp(PyObject *o1, PyObject *o2, int *result);
extern int PyCallable_Check(PyObject *o);
extern PyObject * PyNumber_Add(PyObject *o1, PyObject *o2);
extern PyObject * PyNumber_Subtract(PyObject *o1, PyObject *o2);
extern PyObject * PyNumber_Multiply(PyObject *o1, PyObject *o2);
extern PyObject * PyNumber_Divide(PyObject *o1, PyObject *o2);
extern PyObject * PyNumber_Remainder(PyObject *o1, PyObject *o2);
extern PyObject * PyNumber_Divmod(PyObject *o1, PyObject *o2);
extern PyObject * PyNumber_Power(PyObject *o1, PyObject *o2, PyObject *o3);
extern PyObject * PyNumber_Lshift(PyObject *o1, PyObject *o2);
extern PyObject * PyNumber_Rshift(PyObject *o1, PyObject *o2);
extern PyObject * PyNumber_And(PyObject *o1, PyObject *o2);
extern PyObject * PyNumber_Xor(PyObject *o1, PyObject *o2);
extern PyObject * PyNumber_Or(PyObject *o1, PyObject *o2);
extern PyObject * PyNumber_InPlaceAdd(PyObject *o1, PyObject *o2);
extern PyObject * PyNumber_InPlaceSubtract(PyObject *o1, PyObject *o2);
extern PyObject * PyNumber_InPlaceMultiply(PyObject *o1, PyObject *o2);
extern PyObject * PyNumber_InPlaceDivide(PyObject *o1, PyObject *o2);
extern PyObject * PyNumber_InPlaceRemainder(PyObject *o1, PyObject *o2);
extern PyObject * PyNumber_InPlacePower(PyObject *o1, PyObject *o2, PyObject *o3);
extern PyObject * PyNumber_InPlaceLshift(PyObject *o1, PyObject *o2);
extern PyObject * PyNumber_InPlaceRshift(PyObject *o1, PyObject *o2);
extern PyObject * PyNumber_InPlaceAnd(PyObject *o1, PyObject *o2);
extern PyObject * PyNumber_InPlaceXor(PyObject *o1, PyObject *o2);
extern PyObject * PyNumber_InPlaceOr(PyObject *o1, PyObject *o2);
extern PyObject * Py_BuildValue(char *, ...);
extern PyObject * PyString_FromStringAndSize(const char *, int);
extern PyObject * PyString_FromString(const char *);
extern int PyString_Size(PyObject *);
extern char * PyString_AsString(PyObject *);
extern PyObject * PyString_InternFromString(const char *);
extern int PyObject_Compare(PyObject *, PyObject *);
extern PyObject * PyObject_GetAttrString(PyObject *, char *);
extern PyObject * PyObject_GetAttr(PyObject *, PyObject *);
extern long PyObject_Hash(PyObject *);
extern int PyObject_IsTrue(PyObject *);
extern int PyNumber_CoerceEx(PyObject **, PyObject **);
extern long _Py_HashPointer(void*);
extern void PyMethod_Fini(void);
extern PyObject *PyExc_AttributeError;
extern PyObject *PyExc_IndexError;
extern PyObject *PyExc_RuntimeError;
extern PyObject *PyExc_SystemError;
extern PyObject *PyExc_TypeError;
extern PyObject *PyExc_ValueError;
extern void (*PyObject_ClearWeakRefs)(PyObject *);
#define PyGC_HEAD_SIZE 0
#define PyObject_AS_GC(o) (o)
#define PyObject_GC_Init(o)
#define PyObject_GC_Fini(o)
#define PyObject_INIT(o,t) ((o)->ob_type=(t), _Py_NewReference((PyObject *)(o)), (o))
#define PyObject_NEW(t,tp) ((t *)PyObject_Init((PyObject *)malloc((tp)->tp_basicsize), (tp)))
#define PyObject_DEL free
extern PyObject *PyObject_Init(PyObject *, PyTypeObject *);
extern void *malloc(unsigned int);
extern void free(void *);
extern int strcmp(const char *, const char *), sprintf(char *, const char *, ...);
extern unsigned int strlen(const char *);
extern char *strchr(const char *, int);

#define PyEval_CallObject(fn,arg) PyEval_CallObjectWithKeywords(fn,arg,(PyObject *)NULL)

typedef struct { char gpr; char fpr; char reserved[2]; char *input_arg_area; char *reg_save_area; } va_list[1];
extern void __builtin_va_info(void *);
extern void *__va_arg(va_list, unsigned char);
#define va_start(ap,fmt) ((void)fmt,__builtin_va_info(&ap))
#define va_arg(ap,t) (*((t *)__va_arg(ap,_var_arg_typeof(t))))
#define va_end(ap) ((void)0)

#define DL_IMPORT(t) t
#define HAVE_STDARG_PROTOTYPES 1
#ifndef Py_ABSTRACTOBJECT_H
#define Py_ABSTRACTOBJECT_H
#ifdef __cplusplus
extern "C" {
#endif
#define  PyObject_DelAttrString(O,A) PyObject_SetAttrString((O),(A),NULL)
#define  PyObject_DelAttr(O,A) PyObject_SetAttr((O),(A),NULL)
     DL_IMPORT(int) PyObject_Cmp(PyObject *o1, PyObject *o2, int *result);
     DL_IMPORT(int) PyCallable_Check(PyObject *o);
     DL_IMPORT(PyObject *) PyObject_CallObject(PyObject *callable_object,
                                               PyObject *args);
     DL_IMPORT(PyObject *) PyObject_CallFunction(PyObject *callable_object,
                                                 char *format, ...);
     DL_IMPORT(PyObject *) PyObject_CallMethod(PyObject *o, char *m,
                                               char *format, ...);
     DL_IMPORT(PyObject *) PyObject_Type(PyObject *o);
     DL_IMPORT(int) PyObject_Size(PyObject *o);
#undef PyObject_Length
     DL_IMPORT(int) PyObject_Length(PyObject *o);
#define PyObject_Length PyObject_Size
     DL_IMPORT(PyObject *) PyObject_GetItem(PyObject *o, PyObject *key);
     DL_IMPORT(int) PyObject_SetItem(PyObject *o, PyObject *key, PyObject *v);
     DL_IMPORT(int) PyObject_DelItem(PyObject *o, PyObject *key);
     DL_IMPORT(int) PyObject_AsCharBuffer(PyObject *obj,
					  const char **buffer,
					  int *buffer_len);
     DL_IMPORT(int) PyObject_AsReadBuffer(PyObject *obj,
					  const void **buffer,
					  int *buffer_len);
     DL_IMPORT(int) PyObject_AsWriteBuffer(PyObject *obj,
					   void **buffer,
					   int *buffer_len);
     DL_IMPORT(int) PyNumber_Check(PyObject *o);
     DL_IMPORT(PyObject *) PyNumber_Add(PyObject *o1, PyObject *o2);
     DL_IMPORT(PyObject *) PyNumber_Subtract(PyObject *o1, PyObject *o2);
     DL_IMPORT(PyObject *) PyNumber_Multiply(PyObject *o1, PyObject *o2);
     DL_IMPORT(PyObject *) PyNumber_Divide(PyObject *o1, PyObject *o2);
     DL_IMPORT(PyObject *) PyNumber_Remainder(PyObject *o1, PyObject *o2);
     DL_IMPORT(PyObject *) PyNumber_Divmod(PyObject *o1, PyObject *o2);
     DL_IMPORT(PyObject *) PyNumber_Power(PyObject *o1, PyObject *o2,
                                          PyObject *o3);
     DL_IMPORT(PyObject *) PyNumber_Negative(PyObject *o);
     DL_IMPORT(PyObject *) PyNumber_Positive(PyObject *o);
     DL_IMPORT(PyObject *) PyNumber_Absolute(PyObject *o);
     DL_IMPORT(PyObject *) PyNumber_Invert(PyObject *o);
     DL_IMPORT(PyObject *) PyNumber_Lshift(PyObject *o1, PyObject *o2);
     DL_IMPORT(PyObject *) PyNumber_Rshift(PyObject *o1, PyObject *o2);
     DL_IMPORT(PyObject *) PyNumber_And(PyObject *o1, PyObject *o2);
     DL_IMPORT(PyObject *) PyNumber_Xor(PyObject *o1, PyObject *o2);
     DL_IMPORT(PyObject *) PyNumber_Or(PyObject *o1, PyObject *o2);
     DL_IMPORT(PyObject *) PyNumber_Int(PyObject *o);
     DL_IMPORT(PyObject *) PyNumber_Long(PyObject *o);
     DL_IMPORT(PyObject *) PyNumber_Float(PyObject *o);
     DL_IMPORT(PyObject *) PyNumber_InPlaceAdd(PyObject *o1, PyObject *o2);
     DL_IMPORT(PyObject *) PyNumber_InPlaceSubtract(PyObject *o1, PyObject *o2);
     DL_IMPORT(PyObject *) PyNumber_InPlaceMultiply(PyObject *o1, PyObject *o2);
     DL_IMPORT(PyObject *) PyNumber_InPlaceDivide(PyObject *o1, PyObject *o2);
     DL_IMPORT(PyObject *) PyNumber_InPlaceRemainder(PyObject *o1, PyObject *o2);
     DL_IMPORT(PyObject *) PyNumber_InPlacePower(PyObject *o1, PyObject *o2,
     						 PyObject *o3);
     DL_IMPORT(PyObject *) PyNumber_InPlaceLshift(PyObject *o1, PyObject *o2);
     DL_IMPORT(PyObject *) PyNumber_InPlaceRshift(PyObject *o1, PyObject *o2);
     DL_IMPORT(PyObject *) PyNumber_InPlaceAnd(PyObject *o1, PyObject *o2);
     DL_IMPORT(PyObject *) PyNumber_InPlaceXor(PyObject *o1, PyObject *o2);
     DL_IMPORT(PyObject *) PyNumber_InPlaceOr(PyObject *o1, PyObject *o2);
     DL_IMPORT(int) PySequence_Check(PyObject *o);
     DL_IMPORT(int) PySequence_Size(PyObject *o);
#undef PySequence_Length
     DL_IMPORT(int) PySequence_Length(PyObject *o);
#define PySequence_Length PySequence_Size
     DL_IMPORT(PyObject *) PySequence_Concat(PyObject *o1, PyObject *o2);
     DL_IMPORT(PyObject *) PySequence_Repeat(PyObject *o, int count);
     DL_IMPORT(PyObject *) PySequence_GetItem(PyObject *o, int i);
     DL_IMPORT(PyObject *) PySequence_GetSlice(PyObject *o, int i1, int i2);
     static inline int PySequence_SetItem(PyObject *o, int i, PyObject *v);
     DL_IMPORT(int) PySequence_DelItem(PyObject *o, int i);
     DL_IMPORT(int) PySequence_SetSlice(PyObject *o, int i1, int i2,
                                        PyObject *v);
     DL_IMPORT(int) PySequence_DelSlice(PyObject *o, int i1, int i2);
     DL_IMPORT(PyObject *) PySequence_Tuple(PyObject *o);
     DL_IMPORT(PyObject *) PySequence_List(PyObject *o);
     DL_IMPORT(PyObject *) PySequence_Fast(PyObject *o, const char* m);
#define PySequence_Fast_GET_ITEM(o, i)\
     (PyList_Check(o) ? PyList_GET_ITEM(o, i) : PyTuple_GET_ITEM(o, i))
     DL_IMPORT(int) PySequence_Count(PyObject *o, PyObject *value);
     DL_IMPORT(int) PySequence_Contains(PyObject *o, PyObject *value);
#undef PySequence_In
     DL_IMPORT(int) PySequence_In(PyObject *o, PyObject *value);
#define PySequence_In PySequence_Contains
     DL_IMPORT(int) PySequence_Index(PyObject *o, PyObject *value);
     DL_IMPORT(PyObject *) PySequence_InPlaceConcat(PyObject *o1, PyObject *o2);
     DL_IMPORT(PyObject *) PySequence_InPlaceRepeat(PyObject *o, int count);
     DL_IMPORT(int) PyMapping_Check(PyObject *o);
     static inline int PyMapping_Size(PyObject *o);
#undef PyMapping_Length
     DL_IMPORT(int) PyMapping_Length(PyObject *o);
#define PyMapping_Length PyMapping_Size
#define PyMapping_DelItemString(O,K) PyDict_DelItemString((O),(K))
#define PyMapping_DelItem(O,K) PyDict_DelItem((O),(K))
     DL_IMPORT(int) PyMapping_HasKeyString(PyObject *o, char *key);
     DL_IMPORT(int) PyMapping_HasKey(PyObject *o, PyObject *key);
#define PyMapping_Keys(O) PyObject_CallMethod(O,"keys",NULL)
#define PyMapping_Values(O) PyObject_CallMethod(O,"values",NULL)
#define PyMapping_Items(O) PyObject_CallMethod(O,"items",NULL)
     DL_IMPORT(PyObject *) PyMapping_GetItemString(PyObject *o, char *key);
     DL_IMPORT(int) PyMapping_SetItemString(PyObject *o, char *key,
                                            PyObject *value);
DL_IMPORT(int) PyObject_IsInstance(PyObject *object, PyObject *typeorclass);
DL_IMPORT(int) PyObject_IsSubclass(PyObject *object, PyObject *typeorclass);
#ifdef __cplusplus
}
#endif
#endif 

#define Py_TPFLAGS_HAVE_INPLACEOPS 8
#define Py_TPFLAGS_HAVE_SEQUENCE_IN 2
#define Py_TPFLAGS_HAVE_GETCHARBUFFER 1
#define PyType_HasFeature(t, f) (((t)->tp_flags & (f)) != 0)
#define PyTuple_GET_SIZE(o) (((PyVarObject *)(o))->ob_size)
#define PyTuple_SET_ITEM(o,i,v) (((PyTupleObject *)(o))->ob_item[i]=(v))
#define PyList_GET_SIZE(o) (((PyVarObject *)(o))->ob_size)
#define PyList_GET_ITEM(o,i) (((PyListObject *)(o))->ob_item[i])
typedef struct { PyObject_VAR_HEAD PyObject **ob_item; } PyListObject;
typedef struct { PyObject_HEAD int length; unsigned short *str; } PyUnicodeObject;
#define PyUnicode_GET_SIZE(o) (((PyUnicodeObject *)(o))->length)
#define PyUnicode_AS_UNICODE(o) (((PyUnicodeObject *)(o))->str)
#define Py_CHARMASK(c) ((c) & 0xff)
extern unsigned char __ctype_map[];
#define isspace(c) (__ctype_map[(unsigned char)(c)] & 6)
#define PyLong_Check(o) ((o)->ob_type==&PyLong_Type)
#define PyFloat_Check(o) ((o)->ob_type==&PyFloat_Type)
#define PyUnicode_Check(o) ((o)->ob_type==&PyUnicode_Type)
#define PyList_Check(o) ((o)->ob_type==&PyList_Type)
extern PyTypeObject PyLong_Type, PyFloat_Type, PyUnicode_Type, PyList_Type;
extern long PyLong_AsLong(PyObject *);
extern PyObject *PyFloat_FromString(PyObject *, char **);
extern PyObject *PyLong_FromString(char *, char **, int);
extern PyObject *PyInt_FromString(char *, char **, int);
extern PyObject *PyLong_FromUnicode(unsigned short *, int, int);
extern PyObject *PyInt_FromUnicode(unsigned short *, int, int);
extern PyObject *PyList_New(int);
extern int PyList_Append(PyObject *, PyObject *), PyList_SetItem(PyObject *, int, PyObject *);
extern int _PyTuple_Resize(PyObject **, int, int);
extern PyObject *PyString_Format(PyObject *, PyObject *);
extern PyObject *PyUnicode_Format(PyObject *, PyObject *);
extern PyObject *PyList_AsTuple(PyObject *);
extern PyObject *PyList_GetSlice(PyObject *, int, int);
extern PyObject *Py_VaBuildValue(char *, va_list);
extern PyObject *PyExc_OverflowError;



#define PyMem_NEW(type,n) ((type *)malloc(1+(n)*sizeof(type)))
#define PyMem_DEL(p) free(p)
#define PyMem_FREE(p) free(p)
#define Py_BEGIN_ALLOW_THREADS
#define Py_END_ALLOW_THREADS
#define PyFPE_START_PROTECT(err,leave)
#define PyFPE_END_PROTECT(v)
#define PyList_SET_ITEM(op,i,v) (((PyListObject *)(op))->ob_item[i]=(v))
#define PyComplex_Check(o) ((o)->ob_type==&PyComplex_Type)
#define PyCode_Check(o) ((o)->ob_type==&PyCode_Type)
#define Py_True ((PyObject *)&_Py_TrueStruct)
#define Py_False ((PyObject *)&_Py_ZeroStruct)
#define Py_Ellipsis (&_Py_EllipsisObject)
#define Py_END_OF_BUFFER (-1)
#define Py_PRINT_RAW 1
#define Py_single_input 256
#define Py_file_input 257
#define Py_eval_input 258
#define PYTHON_API_VERSION 1010
#define INT_MAX 2147483647
#define isdigit(c) (__ctype_map[(unsigned char)(c)] & 0x10)
typedef struct { PyObject_HEAD long ob_ival; } PyIntObject;
typedef struct { double real, imag; } Py_complex;
typedef struct { PyObject_HEAD Py_complex cval; } PyComplexObject;
typedef struct { PyObject_HEAD int co_argcount, co_nlocals, co_stacksize, co_flags; } PyCodeObject;
typedef struct { int cf_nested_scopes; } PyCompilerFlags;
typedef unsigned short Py_UNICODE;
typedef PyObject *(*PyCFunction)(PyObject *, PyObject *);
typedef struct { char *ml_name; PyCFunction ml_meth; int ml_flags; char *ml_doc; } PyMethodDef;
extern PyIntObject _Py_TrueStruct, _Py_ZeroStruct;
extern PyObject _Py_EllipsisObject;
extern PyTypeObject PyComplex_Type, PyCode_Type;
extern FILE __files[];
#define stdin (&__files[0])
#define stdout (&__files[1])
#define stderr (&__files[2])
extern int errno, Py_OptimizeFlag;
#define abs(value) __abs(value)
extern double floor(double), ceil(double);
extern int fileno(FILE *), isatty(int);
extern FILE *fopen(const char *, const char *);
extern char *PyOS_Readline(char *);
extern int PyArg_ParseTuple(PyObject *, const char *, ...);
extern int PyArg_Parse(PyObject *, const char *, ...);
extern PyObject *PyImport_ImportModuleEx(char *, PyObject *, PyObject *, PyObject *);
extern PyObject *PyImport_ReloadModule(PyObject *);
extern PyObject *PyBuffer_FromObject(PyObject *, int, int);
extern PyObject *PyUnicode_FromEncodedObject(PyObject *, const char *, const char *);
extern PyObject *PyUnicode_FromUnicode(Py_UNICODE *, int);
extern int PyUnicode_EncodeDecimal(Py_UNICODE *, int, char *, const char *);
extern int PyNumber_Coerce(PyObject **, PyObject **);
extern int PyEval_GetNestedScopes(void);
extern PyObject *Py_CompileString(char *, char *, int);
extern PyObject *Py_CompileStringFlags(char *, char *, int, PyCompilerFlags *);
extern PyObject *PyRun_String(char *, int, PyObject *, PyObject *);
extern PyObject *PyRun_FileEx(FILE *, char *, int, PyObject *, PyObject *, int);
extern PyObject *PyRun_FileExFlags(FILE *, char *, int, PyObject *, PyObject *, int, PyCompilerFlags *);
extern PyObject *PyEval_EvalCode(PyCodeObject *, PyObject *, PyObject *);
extern PyObject *PyEval_GetLocals(void);
extern PyObject *PyEval_GetBuiltins(void);
extern PyObject *PyComplex_FromDoubles(double, double);
extern PyObject *PyComplex_FromCComplex(Py_complex);
extern double PyFloat_AsDouble(PyObject *);
extern PyObject *PyFloat_FromDouble(double);
extern PyObject *PyErr_SetFromErrno(PyObject *);
extern PyObject *PyErr_NoMemory(void);
extern void PyErr_SetNone(PyObject *);
extern PyObject *PyExc_KeyboardInterrupt, *PyExc_EOFError, *PyExc_IOError;
extern PyObject *PyLong_FromVoidPtr(void *);
extern int PyList_SetSlice(PyObject *, int, int, PyObject *);
extern int PyTuple_SetItem(PyObject *, int, PyObject *);
extern void PyString_InternInPlace(PyObject **);
extern int PyString_AsStringAndSize(PyObject *, char **, int *);
extern int _PyString_Resize(PyObject **, int);
extern int PyObject_SetAttr(PyObject *, PyObject *, PyObject *);
extern int PyObject_RichCompareBool(PyObject *, PyObject *, int);
extern PyObject *PyObject_Repr(PyObject *);
extern PyObject *PyObject_Str(PyObject *);
extern PyObject *PyRange_New(long, long, long, int);
extern PyObject *PyFile_FromString(char *, char *);
extern void PyFile_SetBufSize(PyObject *, int);
extern FILE *PyFile_AsFile(PyObject *);
extern int PyFile_WriteObject(PyObject *, PyObject *, int);
extern PyObject *PyFile_GetLine(PyObject *, int);
extern PyObject *PySys_GetObject(char *);
extern int Py_FlushLine(void);
extern int PyDict_SetItemString(PyObject *, char *, PyObject *);
extern PyObject *Py_InitModule4(char *, PyMethodDef *, char *, PyObject *, int);
extern PyObject *PyModule_GetDict(PyObject *);

/* Forward */
static PyObject *filterstring(PyObject *, PyObject *);
static PyObject *filtertuple (PyObject *, PyObject *);

static PyObject *
builtin___import__(PyObject *self, PyObject *args)
{
	char *name;
	PyObject *globals = NULL;
	PyObject *locals = NULL;
	PyObject *fromlist = NULL;

	if (!PyArg_ParseTuple(args, "s|OOO:__import__",
			&name, &globals, &locals, &fromlist))
		return NULL;
	return PyImport_ImportModuleEx(name, globals, locals, fromlist);
}

static char import_doc[] =
"__import__(name, globals, locals, fromlist) -> module\n\
\n\
Import a module.  The globals are only used to determine the context;\n\
they are not modified.  The locals are currently unused.  The fromlist\n\
should be a list of names to emulate ``from name import ...'', or an\n\
empty list to emulate ``import name''.\n\
When importing a module from a package, note that __import__('A.B', ...)\n\
returns package A when fromlist is empty, but its submodule B when\n\
fromlist is not empty.";


static PyObject *
builtin_abs(PyObject *self, PyObject *args)
{
	PyObject *v;

	if (!PyArg_ParseTuple(args, "O:abs", &v))
		return NULL;
	return PyNumber_Absolute(v);
}

static char abs_doc[] =
"abs(number) -> number\n\
\n\
Return the absolute value of the argument.";


static PyObject *
builtin_apply(PyObject *self, PyObject *args)
{
	PyObject *func, *alist = NULL, *kwdict = NULL;
	PyObject *t = NULL, *retval = NULL;

	if (!PyArg_ParseTuple(args, "O|OO:apply", &func, &alist, &kwdict))
		return NULL;
	if (alist != NULL) {
		if (!PyTuple_Check(alist)) {
			if (!PySequence_Check(alist)) {
				PyErr_Format(PyExc_TypeError,
				     "apply() arg 2 expect sequence, found %s",
					     alist->ob_type->tp_name);
				return NULL;
			}
			t = PySequence_Tuple(alist);
			if (t == NULL)
				return NULL;
			alist = t;
		}
	}
	if (kwdict != NULL && !PyDict_Check(kwdict)) {
		PyErr_Format(PyExc_TypeError,
			     "apply() arg 3 expected dictionary, found %s",
			     kwdict->ob_type->tp_name);
		goto finally;
	}
	retval = PyEval_CallObjectWithKeywords(func, alist, kwdict);
  finally:
	Py_XDECREF(t);
	return retval;
}

static char apply_doc[] =
"apply(object[, args[, kwargs]]) -> value\n\
\n\
Call a callable object with positional arguments taken from the tuple args,\n\
and keyword arguments taken from the optional dictionary kwargs.\n\
Note that classes are callable, as are instances with a __call__() method.";


static PyObject *
builtin_buffer(PyObject *self, PyObject *args)
{
	PyObject *ob;
	int offset = 0;
	int size = Py_END_OF_BUFFER;

	if ( !PyArg_ParseTuple(args, "O|ii:buffer", &ob, &offset, &size) )
	    return NULL;
	return PyBuffer_FromObject(ob, offset, size);
}

static char buffer_doc[] =
"buffer(object [, offset[, size]]) -> object\n\
\n\
Create a new buffer object which references the given object.\n\
The buffer will reference a slice of the target object from the\n\
start of the object (or at the specified offset). The slice will\n\
extend to the end of the target object (or with the specified size).";


static PyObject *
builtin_unicode(PyObject *self, PyObject *args)
{
        PyObject *v;
	char *encoding = NULL;
	char *errors = NULL;

	if ( !PyArg_ParseTuple(args, "O|ss:unicode", &v, &encoding, &errors) )
	    return NULL;
	return PyUnicode_FromEncodedObject(v, encoding, errors);
}

static char unicode_doc[] =
"unicode(string [, encoding[, errors]]) -> object\n\
\n\
Create a new Unicode object from the given encoded string.\n\
encoding defaults to the current default string encoding and \n\
errors, defining the error handling, to 'strict'.";


static PyObject *
builtin_callable(PyObject *self, PyObject *args)
{
	PyObject *v;

	if (!PyArg_ParseTuple(args, "O:callable", &v))
		return NULL;
	return PyInt_FromLong((long)PyCallable_Check(v));
}

static char callable_doc[] =
"callable(object) -> Boolean\n\
\n\
Return whether the object is callable (i.e., some kind of function).\n\
Note that classes are callable, as are instances with a __call__() method.";


static PyObject *
builtin_filter(PyObject *self, PyObject *args)
{
	PyObject *func, *seq, *result;
	PySequenceMethods *sqf;
	int len;
	register int i, j;

	if (!PyArg_ParseTuple(args, "OO:filter", &func, &seq))
		return NULL;

	if (PyString_Check(seq)) {
		PyObject *r = filterstring(func, seq);
		return r;
	}

	if (PyTuple_Check(seq)) {
		PyObject *r = filtertuple(func, seq);
		return r;
	}

	sqf = seq->ob_type->tp_as_sequence;
	if (sqf == NULL || sqf->sq_length == NULL || sqf->sq_item == NULL) {
		PyErr_SetString(PyExc_TypeError,
			   "filter() arg 2 must be a sequence");
		goto Fail_2;
	}

	if ((len = (*sqf->sq_length)(seq)) < 0)
		goto Fail_2;

	if (PyList_Check(seq) && seq->ob_refcnt == 1) {
		Py_INCREF(seq);
		result = seq;
	}
	else {
		if ((result = PyList_New(len)) == NULL)
			goto Fail_2;
	}

	for (i = j = 0; ; ++i) {
		PyObject *item, *good;
		int ok;

		if ((item = (*sqf->sq_item)(seq, i)) == NULL) {
			if (PyErr_ExceptionMatches(PyExc_IndexError)) {
				PyErr_Clear();
				break;
			}
			goto Fail_1;
		}

		if (func == Py_None) {
			good = item;
			Py_INCREF(good);
		}
		else {
			PyObject *arg = Py_BuildValue("(O)", item);
			if (arg == NULL)
				goto Fail_1;
			good = PyEval_CallObject(func, arg);
			Py_DECREF(arg);
			if (good == NULL) {
				Py_DECREF(item);
				goto Fail_1;
			}
		}
		ok = PyObject_IsTrue(good);
		Py_DECREF(good);
		if (ok) {
			if (j < len) {
				if (PyList_SetItem(result, j++, item) < 0)
					goto Fail_1;
			}
			else {
				int status = PyList_Append(result, item);
				j++;
				Py_DECREF(item);
				if (status < 0)
					goto Fail_1;
			}
		} else {
			Py_DECREF(item);
		}
	}


	if (j < len && PyList_SetSlice(result, j, len, NULL) < 0)
		goto Fail_1;

	return result;

Fail_1:
	Py_DECREF(result);
Fail_2:
	return NULL;
}

static char filter_doc[] =
"filter(function, sequence) -> list\n\
\n\
Return a list containing those items of sequence for which function(item)\n\
is true.  If function is None, return a list of items that are true.";


static PyObject *
builtin_chr(PyObject *self, PyObject *args)
{
	long x;
	char s[1];

	if (!PyArg_ParseTuple(args, "l:chr", &x))
		return NULL;
	if (x < 0 || x >= 256) {
		PyErr_SetString(PyExc_ValueError,
				"chr() arg not in range(256)");
		return NULL;
	}
	s[0] = (char)x;
	return PyString_FromStringAndSize(s, 1);
}

static char chr_doc[] =
"chr(i) -> character\n\
\n\
Return a string of one character with ordinal i; 0 <= i < 256.";


static PyObject *
builtin_unichr(PyObject *self, PyObject *args)
{
	long x;
	Py_UNICODE s[1];

	if (!PyArg_ParseTuple(args, "l:unichr", &x))
		return NULL;
	if (x < 0 || x >= 65536) {
		PyErr_SetString(PyExc_ValueError,
				"unichr() arg not in range(65536)");
		return NULL;
	}
	s[0] = (Py_UNICODE)x;
	return PyUnicode_FromUnicode(s, 1);
}

static char unichr_doc[] =
"unichr(i) -> Unicode character\n\
\n\
Return a Unicode string of one character with ordinal i; 0 <= i < 65536.";


static PyObject *
builtin_cmp(PyObject *self, PyObject *args)
{
	PyObject *a, *b;
	int c;

	if (!PyArg_ParseTuple(args, "OO:cmp", &a, &b))
		return NULL;
	if (PyObject_Cmp(a, b, &c) < 0)
		return NULL;
	return PyInt_FromLong((long)c);
}

static char cmp_doc[] =
"cmp(x, y) -> integer\n\
\n\
Return negative if x<y, zero if x==y, positive if x>y.";


static PyObject *
builtin_coerce(PyObject *self, PyObject *args)
{
	PyObject *v, *w;
	PyObject *res;

	if (!PyArg_ParseTuple(args, "OO:coerce", &v, &w))
		return NULL;
	if (PyNumber_Coerce(&v, &w) < 0)
		return NULL;
	res = Py_BuildValue("(OO)", v, w);
	Py_DECREF(v);
	Py_DECREF(w);
	return res;
}

static char coerce_doc[] =
"coerce(x, y) -> None or (x1, y1)\n\
\n\
When x and y can be coerced to values of the same type, return a tuple\n\
containing the coerced values.  When they can't be coerced, return None.";


static PyObject *
builtin_compile(PyObject *self, PyObject *args)
{
	char *str;
	char *filename;
	char *startstr;
	int start;

	if (!PyArg_ParseTuple(args, "sss:compile", &str, &filename, &startstr))
		return NULL;
	if (strcmp(startstr, "exec") == 0)
		start = Py_file_input;
	else if (strcmp(startstr, "eval") == 0)
		start = Py_eval_input;
	else if (strcmp(startstr, "single") == 0)
		start = Py_single_input;
	else {
		PyErr_SetString(PyExc_ValueError,
		   "compile() arg 3 must be 'exec' or 'eval' or 'single'");
		return NULL;
	}
	if (PyEval_GetNestedScopes()) {
		PyCompilerFlags cf;
		cf.cf_nested_scopes = 1;
		return Py_CompileStringFlags(str, filename, start, &cf);
	} else
		return Py_CompileString(str, filename, start);
}

static char compile_doc[] =
"compile(source, filename, mode) -> code object\n\
\n\
Compile the source string (a Python module, statement or expression)\n\
into a code object that can be executed by the exec statement or eval().\n\
The filename will be used for run-time error messages.\n\
The mode must be 'exec' to compile a module, 'single' to compile a\n\
single (interactive) statement, or 'eval' to compile an expression.";


#ifndef WITHOUT_COMPLEX

static PyObject *
complex_from_string(PyObject *v)
{
	extern double strtod(const char *, char **);
	const char *s, *start;
	char *end;
	double x=0.0, y=0.0, z;
	int got_re=0, got_im=0, done=0;
	int digit_or_dot;
	int sw_error=0;
	int sign;
	char buffer[256]; /* For errors */
	char s_buffer[256];
	int len;

	if (PyString_Check(v)) {
		s = PyString_AS_STRING(v);
		len = PyString_GET_SIZE(v);
	}
	else if (PyUnicode_Check(v)) {
		if (PyUnicode_GET_SIZE(v) >= sizeof(s_buffer)) {
			PyErr_SetString(PyExc_ValueError,
				 "complex() literal too large to convert");
			return NULL;
		}
		if (PyUnicode_EncodeDecimal(PyUnicode_AS_UNICODE(v),
					    PyUnicode_GET_SIZE(v),
					    s_buffer,
					    NULL))
			return NULL;
		s = s_buffer;
		len = (int)strlen(s);
	}
	else if (PyObject_AsCharBuffer(v, &s, &len)) {
		PyErr_SetString(PyExc_TypeError,
				"complex() arg is not a string");
		return NULL;
	}

	/* position on first nonblank */
	start = s;
	while (*s && isspace(Py_CHARMASK(*s)))
		s++;
	if (s[0] == '\0') {
		PyErr_SetString(PyExc_ValueError,
				"complex() arg is an empty string");
		return NULL;
	}

	z = -1.0;
	sign = 1;
	do {

		switch (*s) {

		case '\0':
			if (s-start != len) {
				PyErr_SetString(
					PyExc_ValueError,
					"complex() arg contains a null byte");
				return NULL;
			}
			if(!done) sw_error=1;
			break;

		case '-':
			sign = -1;
				/* Fallthrough */
		case '+':
			if (done)  sw_error=1;
			s++;
			if  (  *s=='\0'||*s=='+'||*s=='-'  ||
			       isspace(Py_CHARMASK(*s))  )  sw_error=1;
			break;

		case 'J':
		case 'j':
			if (got_im || done) {
				sw_error = 1;
				break;
			}
			if  (z<0.0) {
				y=sign;
			}
			else{
				y=sign*z;
			}
			got_im=1;
			s++;
			if  (*s!='+' && *s!='-' )
				done=1;
			break;

		default:
			if (isspace(Py_CHARMASK(*s))) {
				while (*s && isspace(Py_CHARMASK(*s)))
					s++;
				if (s[0] != '\0')
					sw_error=1;
				else
					done = 1;
				break;
			}
			digit_or_dot =
				(*s=='.' || isdigit(Py_CHARMASK(*s)));
			if  (done||!digit_or_dot) {
				sw_error=1;
				break;
			}
			errno = 0;
			PyFPE_START_PROTECT("strtod", return 0)
				z = strtod(s, &end) ;
			PyFPE_END_PROTECT(z)
				if (errno != 0) {
					sprintf(buffer,
					  "float() out of range: %.150s", s);
					PyErr_SetString(
						PyExc_ValueError,
						buffer);
					return NULL;
				}
			s=end;
			if  (*s=='J' || *s=='j') {

				break;
			}
			if  (got_re) {
				sw_error=1;
				break;
			}

				/* accept a real part */
			x=sign*z;
			got_re=1;
			if  (got_im)  done=1;
			z = -1.0;
			sign = 1;
			break;

		}  /* end of switch  */

	} while (*s!='\0' && !sw_error);

	if (sw_error) {
		PyErr_SetString(PyExc_ValueError,
				"complex() arg is a malformed string");
		return NULL;
	}

	return PyComplex_FromDoubles(x,y);
}

static PyObject *
builtin_complex(PyObject *self, PyObject *args)
{
	PyObject *r, *i, *tmp;
	PyNumberMethods *nbr, *nbi = NULL;
	Py_complex cr, ci;
	int own_r = 0;

	i = NULL;
	if (!PyArg_ParseTuple(args, "O|O:complex", &r, &i))
		return NULL;
	if (PyString_Check(r) || PyUnicode_Check(r))
		return complex_from_string(r);
	if ((nbr = r->ob_type->tp_as_number) == NULL ||
	    nbr->nb_float == NULL ||
	    (i != NULL &&
	     ((nbi = i->ob_type->tp_as_number) == NULL ||
	      nbi->nb_float == NULL))) {
		PyErr_SetString(PyExc_TypeError,
			   "complex() arg can't be converted to complex");
		return NULL;
	}
	/* XXX Hack to support classes with __complex__ method */
	if (PyInstance_Check(r)) {
		static PyObject *complexstr;
		PyObject *f;
		if (complexstr == NULL) {
			complexstr = PyString_InternFromString("__complex__");
			if (complexstr == NULL)
				return NULL;
		}
		f = PyObject_GetAttr(r, complexstr);
		if (f == NULL)
			PyErr_Clear();
		else {
			PyObject *args = Py_BuildValue("()");
			if (args == NULL)
				return NULL;
			r = PyEval_CallObject(f, args);
			Py_DECREF(args);
			Py_DECREF(f);
			if (r == NULL)
				return NULL;
			own_r = 1;
		}
	}
	if (PyComplex_Check(r)) {
		cr = ((PyComplexObject*)r)->cval;
		if (own_r) {
			Py_DECREF(r);
		}
	}
	else {
		tmp = PyNumber_Float(r);
		if (own_r) {
			Py_DECREF(r);
		}
		if (tmp == NULL)
			return NULL;
		if (!PyFloat_Check(tmp)) {
			PyErr_SetString(PyExc_TypeError,
					"float(r) didn't return a float");
			Py_DECREF(tmp);
			return NULL;
		}
		cr.real = PyFloat_AsDouble(tmp);
		Py_DECREF(tmp);
		cr.imag = 0.0;
	}
	if (i == NULL) {
		ci.real = 0.0;
		ci.imag = 0.0;
	}
	else if (PyComplex_Check(i))
		ci = ((PyComplexObject*)i)->cval;
	else {
		tmp = (*nbi->nb_float)(i);
		if (tmp == NULL)
			return NULL;
		ci.real = PyFloat_AsDouble(tmp);
		Py_DECREF(tmp);
		ci.imag = 0.;
	}
	cr.real -= ci.imag;
	cr.imag += ci.real;
	return PyComplex_FromCComplex(cr);
}

static char complex_doc[] =
"complex(real[, imag]) -> complex number\n\
\n\
Create a complex number from a real part and an optional imaginary part.\n\
This is equivalent to (real + imag*1j) where imag defaults to 0.";


#endif

static PyObject *
builtin_dir(PyObject *self, PyObject *args)
{
	static char *attrlist[] = {"__members__", "__methods__", NULL};
	PyObject *v = NULL, *l = NULL, *m = NULL;
	PyObject *d, *x;
	int i;
	char **s;

	if (!PyArg_ParseTuple(args, "|O:dir", &v))
		return NULL;
	if (v == NULL) {
		x = PyEval_GetLocals();
		if (x == NULL)
			goto error;
		l = PyMapping_Keys(x);
		if (l == NULL)
			goto error;
	}
	else {
		d = PyObject_GetAttrString(v, "__dict__");
		if (d == NULL)
			PyErr_Clear();
		else {
			l = PyMapping_Keys(d);
			if (l == NULL)
				PyErr_Clear();
			Py_DECREF(d);
		}
		if (l == NULL) {
			l = PyList_New(0);
			if (l == NULL)
				goto error;
		}
		for (s = attrlist; *s != NULL; s++) {
			m = PyObject_GetAttrString(v, *s);
			if (m == NULL) {
				PyErr_Clear();
				continue;
			}
			for (i = 0; ; i++) {
				x = PySequence_GetItem(m, i);
				if (x == NULL) {
					PyErr_Clear();
					break;
				}
				if (PyList_Append(l, x) != 0) {
					Py_DECREF(x);
					Py_DECREF(m);
					goto error;
				}
				Py_DECREF(x);
			}
			Py_DECREF(m);
		}
	}
	if (PyList_Sort(l) != 0)
		goto error;
	return l;
  error:
	Py_XDECREF(l);
	return NULL;
}

static char dir_doc[] =
"dir([object]) -> list of strings\n\
\n\
Return an alphabetized list of names comprising (some of) the attributes\n\
of the given object.  Without an argument, the names in the current scope\n\
are listed.  With an instance argument, only the instance attributes are\n\
returned.  With a class argument, attributes of the base class are not\n\
returned.  For other types or arguments, this may list members or methods.";


static PyObject *
builtin_divmod(PyObject *self, PyObject *args)
{
	PyObject *v, *w;

	if (!PyArg_ParseTuple(args, "OO:divmod", &v, &w))
		return NULL;
	return PyNumber_Divmod(v, w);
}

static char divmod_doc[] =
"divmod(x, y) -> (div, mod)\n\
\n\
Return the tuple ((x-x%y)/y, x%y).  Invariant: div*y + mod == x.";


static PyObject *
builtin_eval(PyObject *self, PyObject *args)
{
	PyObject *cmd;
	PyObject *globals = Py_None, *locals = Py_None;
	char *str;

	if (!PyArg_ParseTuple(args, "O|O!O!:eval",
			&cmd,
			&PyDict_Type, &globals,
			&PyDict_Type, &locals))
		return NULL;
	if (globals == Py_None) {
		globals = PyEval_GetGlobals();
		if (locals == Py_None)
			locals = PyEval_GetLocals();
	}
	else if (locals == Py_None)
		locals = globals;
	if (PyDict_GetItemString(globals, "__builtins__") == NULL) {
		if (PyDict_SetItemString(globals, "__builtins__",
					 PyEval_GetBuiltins()) != 0)
			return NULL;
	}
	if (PyCode_Check(cmd))
		return PyEval_EvalCode((PyCodeObject *) cmd, globals, locals);
	if (!PyString_Check(cmd) &&
	    !PyUnicode_Check(cmd)) {
		PyErr_SetString(PyExc_TypeError,
			   "eval() arg 1 must be a string or code object");
		return NULL;
	}
	if (PyString_AsStringAndSize(cmd, &str, NULL))
		return NULL;
	while (*str == ' ' || *str == '\t')
		str++;
	return PyRun_String(str, Py_eval_input, globals, locals);
}

static char eval_doc[] =
"eval(source[, globals[, locals]]) -> value\n\
\n\
Evaluate the source in the context of globals and locals.\n\
The source may be a string representing a Python expression\n\
or a code object as returned by compile().\n\
The globals and locals are dictionaries, defaulting to the current\n\
globals and locals.  If only globals is given, locals defaults to it.";


static PyObject *
builtin_execfile(PyObject *self, PyObject *args)
{
	char *filename;
	PyObject *globals = Py_None, *locals = Py_None;
	PyObject *res;
	FILE* fp;

	if (!PyArg_ParseTuple(args, "s|O!O!:execfile",
			&filename,
			&PyDict_Type, &globals,
			&PyDict_Type, &locals))
		return NULL;
	if (globals == Py_None) {
		globals = PyEval_GetGlobals();
		if (locals == Py_None)
			locals = PyEval_GetLocals();
	}
	else if (locals == Py_None)
		locals = globals;
	if (PyDict_GetItemString(globals, "__builtins__") == NULL) {
		if (PyDict_SetItemString(globals, "__builtins__",
					 PyEval_GetBuiltins()) != 0)
			return NULL;
	}
	Py_BEGIN_ALLOW_THREADS
	fp = fopen(filename, "r");
	Py_END_ALLOW_THREADS
	if (fp == NULL) {
		PyErr_SetFromErrno(PyExc_IOError);
		return NULL;
	}
	if (PyEval_GetNestedScopes()) {
		PyCompilerFlags cf;
		cf.cf_nested_scopes = 1;
		res = PyRun_FileExFlags(fp, filename, Py_file_input, globals, 
				   locals, 1, &cf);
	} else 
		res = PyRun_FileEx(fp, filename, Py_file_input, globals, 
				   locals, 1);
	return res;
}

static char execfile_doc[] =
"execfile(filename[, globals[, locals]])\n\
\n\
Read and execute a Python script from a file.\n\
The globals and locals are dictionaries, defaulting to the current\n\
globals and locals.  If only globals is given, locals defaults to it.";


static PyObject *
builtin_getattr(PyObject *self, PyObject *args)
{
	PyObject *v, *result, *dflt = NULL;
	PyObject *name;

	if (!PyArg_ParseTuple(args, "OO|O:getattr", &v, &name, &dflt))
		return NULL;
	result = PyObject_GetAttr(v, name);
	if (result == NULL && dflt != NULL) {
		PyErr_Clear();
		Py_INCREF(dflt);
		result = dflt;
	}
	return result;
}

static char getattr_doc[] =
"getattr(object, name[, default]) -> value\n\
\n\
Get a named attribute from an object; getattr(x, 'y') is equivalent to x.y.\n\
When a default argument is given, it is returned when the attribute doesn't\n\
exist; without it, an exception is raised in that case.";


static PyObject *
builtin_globals(PyObject *self, PyObject *args)
{
	PyObject *d;

	if (!PyArg_ParseTuple(args, ":globals"))
		return NULL;
	d = PyEval_GetGlobals();
	Py_INCREF(d);
	return d;
}

static char globals_doc[] =
"globals() -> dictionary\n\
\n\
Return the dictionary containing the current scope's global variables.";


static PyObject *
builtin_hasattr(PyObject *self, PyObject *args)
{
	PyObject *v;
	PyObject *name;

	if (!PyArg_ParseTuple(args, "OO:hasattr", &v, &name))
		return NULL;
	v = PyObject_GetAttr(v, name);
	if (v == NULL) {
		PyErr_Clear();
		Py_INCREF(Py_False);
		return Py_False;
	}
	Py_DECREF(v);
	Py_INCREF(Py_True);
	return Py_True;
}

static char hasattr_doc[] =
"hasattr(object, name) -> Boolean\n\
\n\
Return whether the object has an attribute with the given name.\n\
(This is done by calling getattr(object, name) and catching exceptions.)";


static PyObject *
builtin_id(PyObject *self, PyObject *args)
{
	PyObject *v;

	if (!PyArg_ParseTuple(args, "O:id", &v))
		return NULL;
	return PyLong_FromVoidPtr(v);
}

static char id_doc[] =
"id(object) -> integer\n\
\n\
Return the identity of an object.  This is guaranteed to be unique among\n\
simultaneously existing objects.  (Hint: it's the object's memory address.)";


static PyObject *
builtin_map(PyObject *self, PyObject *args)
{
	typedef struct {
		PyObject *seq;
		PySequenceMethods *sqf;
		int len;
	} sequence;

	PyObject *func, *result;
	sequence *seqs = NULL, *sqp;
	int n, len;
	register int i, j;

	n = PyTuple_Size(args);
	if (n < 2) {
		PyErr_SetString(PyExc_TypeError,
				"map() requires at least two args");
		return NULL;
	}

	func = PyTuple_GetItem(args, 0);
	n--;

	if (func == Py_None && n == 1) {
		/* map(None, S) is the same as list(S). */
		return PySequence_List(PyTuple_GetItem(args, 1));
	}

	if ((seqs = PyMem_NEW(sequence, n)) == NULL) {
		PyErr_NoMemory();
		goto Fail_2;
	}

	for (len = 0, i = 0, sqp = seqs; i < n; ++i, ++sqp) {
		int curlen;
		PySequenceMethods *sqf;

		if ((sqp->seq = PyTuple_GetItem(args, i + 1)) == NULL)
			goto Fail_2;

		sqp->sqf = sqf = sqp->seq->ob_type->tp_as_sequence;
		if (sqf == NULL ||
		    sqf->sq_length == NULL ||
		    sqf->sq_item == NULL)
		{
			static char errmsg[] =
			    "argument %d to map() must be a sequence object";
			char errbuf[sizeof(errmsg) + 25];

			sprintf(errbuf, errmsg, i+2);
			PyErr_SetString(PyExc_TypeError, errbuf);
			goto Fail_2;
		}

		if ((curlen = sqp->len = (*sqp->sqf->sq_length)(sqp->seq)) < 0)
			goto Fail_2;

		if (curlen > len)
			len = curlen;
	}

	if ((result = (PyObject *) PyList_New(len)) == NULL)
		goto Fail_2;

	for (i = 0; ; ++i) {
		PyObject *alist, *item=NULL, *value;
		int any = 0;

		if (func == Py_None && n == 1)
			alist = NULL;
		else {
			if ((alist = PyTuple_New(n)) == NULL)
				goto Fail_1;
		}

		for (j = 0, sqp = seqs; j < n; ++j, ++sqp) {
			if (sqp->len < 0) {
				Py_INCREF(Py_None);
				item = Py_None;
			}
			else {
				item = (*sqp->sqf->sq_item)(sqp->seq, i);
				if (item == NULL) {
					if (PyErr_ExceptionMatches(
						PyExc_IndexError))
					{
						PyErr_Clear();
						Py_INCREF(Py_None);
						item = Py_None;
						sqp->len = -1;
					}
					else {
						goto Fail_0;
					}
				}
				else
					any = 1;

			}
			if (!alist)
				break;
			if (PyTuple_SetItem(alist, j, item) < 0) {
				Py_DECREF(item);
				goto Fail_0;
			}
			continue;

		Fail_0:
			Py_XDECREF(alist);
			goto Fail_1;
		}

		if (!alist)
			alist = item;

		if (!any) {
			Py_DECREF(alist);
			break;
		}

		if (func == Py_None)
			value = alist;
		else {
			value = PyEval_CallObject(func, alist);
			Py_DECREF(alist);
			if (value == NULL)
				goto Fail_1;
		}
		if (i >= len) {
			int status = PyList_Append(result, value);
			Py_DECREF(value);
			if (status < 0)
				goto Fail_1;
		}
		else {
			if (PyList_SetItem(result, i, value) < 0)
				goto Fail_1;
		}
	}

	if (i < len && PyList_SetSlice(result, i, len, NULL) < 0)
		goto Fail_1;

	PyMem_DEL(seqs);
	return result;

Fail_1:
	Py_DECREF(result);
Fail_2:
	if (seqs) PyMem_DEL(seqs);
	return NULL;
}

static char map_doc[] =
"map(function, sequence[, sequence, ...]) -> list\n\
\n\
Return a list of the results of applying the function to the items of\n\
the argument sequence(s).  If more than one sequence is given, the\n\
function is called with an argument list consisting of the corresponding\n\
item of each sequence, substituting None for missing values when not all\n\
sequences have the same length.  If the function is None, return a list of\n\
the items of the sequence (or a list of tuples if more than one sequence).";


static PyObject *
builtin_setattr(PyObject *self, PyObject *args)
{
	PyObject *v;
	PyObject *name;
	PyObject *value;

	if (!PyArg_ParseTuple(args, "OOO:setattr", &v, &name, &value))
		return NULL;
	if (PyObject_SetAttr(v, name, value) != 0)
		return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}

static char setattr_doc[] =
"setattr(object, name, value)\n\
\n\
Set a named attribute on an object; setattr(x, 'y', v) is equivalent to\n\
``x.y = v''.";


static PyObject *
builtin_delattr(PyObject *self, PyObject *args)
{
	PyObject *v;
	PyObject *name;

	if (!PyArg_ParseTuple(args, "OO:delattr", &v, &name))
		return NULL;
	if (PyObject_SetAttr(v, name, (PyObject *)NULL) != 0)
		return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}

static char delattr_doc[] =
"delattr(object, name)\n\
\n\
Delete a named attribute on an object; delattr(x, 'y') is equivalent to\n\
``del x.y''.";


static PyObject *
builtin_hash(PyObject *self, PyObject *args)
{
	PyObject *v;
	long x;

	if (!PyArg_ParseTuple(args, "O:hash", &v))
		return NULL;
	x = PyObject_Hash(v);
	if (x == -1)
		return NULL;
	return PyInt_FromLong(x);
}

static char hash_doc[] =
"hash(object) -> integer\n\
\n\
Return a hash value for the object.  Two objects with the same value have\n\
the same hash value.  The reverse is not necessarily true, but likely.";


static PyObject *
builtin_hex(PyObject *self, PyObject *args)
{
	PyObject *v;
	PyNumberMethods *nb;

	if (!PyArg_ParseTuple(args, "O:hex", &v))
		return NULL;

	if ((nb = v->ob_type->tp_as_number) == NULL ||
	    nb->nb_hex == NULL) {
		PyErr_SetString(PyExc_TypeError,
			   "hex() argument can't be converted to hex");
		return NULL;
	}
	return (*nb->nb_hex)(v);
}

static char hex_doc[] =
"hex(number) -> string\n\
\n\
Return the hexadecimal representation of an integer or long integer.";


static PyObject *builtin_raw_input(PyObject *, PyObject *);

static PyObject *
builtin_input(PyObject *self, PyObject *args)
{
	PyObject *line;
	char *str;
	PyObject *res;
	PyObject *globals, *locals;

	line = builtin_raw_input(self, args);
	if (line == NULL)
		return line;
	if (!PyArg_Parse(line, "s;embedded '\\0' in input line", &str))
		return NULL;
	while (*str == ' ' || *str == '\t')
			str++;
	globals = PyEval_GetGlobals();
	locals = PyEval_GetLocals();
	if (PyDict_GetItemString(globals, "__builtins__") == NULL) {
		if (PyDict_SetItemString(globals, "__builtins__",
					 PyEval_GetBuiltins()) != 0)
			return NULL;
	}
	res = PyRun_String(str, Py_eval_input, globals, locals);
	Py_DECREF(line);
	return res;
}

static char input_doc[] =
"input([prompt]) -> value\n\
\n\
Equivalent to eval(raw_input(prompt)).";


static PyObject *
builtin_intern(PyObject *self, PyObject *args)
{
	PyObject *s;
	if (!PyArg_ParseTuple(args, "S:intern", &s))
		return NULL;
	Py_INCREF(s);
	PyString_InternInPlace(&s);
	return s;
}

static char intern_doc[] =
"intern(string) -> string\n\
\n\
``Intern'' the given string.  This enters the string in the (global)\n\
table of interned strings whose purpose is to speed up dictionary lookups.\n\
Return the string itself or the previously interned string object with the\n\
same value.";


static PyObject *
builtin_int(PyObject *self, PyObject *args)
{
	PyObject *v;
	int base = -909;		     /* unlikely! */

	if (!PyArg_ParseTuple(args, "O|i:int", &v, &base))
		return NULL;
	if (base == -909)
		return PyNumber_Int(v);
	else if (PyString_Check(v))
		return PyInt_FromString(PyString_AS_STRING(v), NULL, base);
	else if (PyUnicode_Check(v))
		return PyInt_FromUnicode(PyUnicode_AS_UNICODE(v),
					 PyUnicode_GET_SIZE(v),
					 base);
	else {
		PyErr_SetString(PyExc_TypeError,
				"int() can't convert non-string with explicit base");
		return NULL;
	}
}

static char int_doc[] =
"int(x[, base]) -> integer\n\
\n\
Convert a string or number to an integer, if possible.  A floating point\n\
argument will be truncated towards zero (this does not include a string\n\
representation of a floating point number!)  When converting a string, use\n\
the optional base.  It is an error to supply a base when converting a\n\
non-string.";


static PyObject *
builtin_long(PyObject *self, PyObject *args)
{
	PyObject *v;
	int base = -909;		     /* unlikely! */

	if (!PyArg_ParseTuple(args, "O|i:long", &v, &base))
		return NULL;
	if (base == -909)
		return PyNumber_Long(v);
	else if (PyString_Check(v))
		return PyLong_FromString(PyString_AS_STRING(v), NULL, base);
	else if (PyUnicode_Check(v))
		return PyLong_FromUnicode(PyUnicode_AS_UNICODE(v),
					  PyUnicode_GET_SIZE(v),
					  base);
	else {
		PyErr_SetString(PyExc_TypeError,
				"long() can't convert non-string with explicit base");
		return NULL;
	}
}

static char long_doc[] =
"long(x) -> long integer\n\
long(x, base) -> long integer\n\
\n\
Convert a string or number to a long integer, if possible.  A floating\n\
point argument will be truncated towards zero (this does not include a\n\
string representation of a floating point number!)  When converting a\n\
string, use the given base.  It is an error to supply a base when\n\
converting a non-string.";


static PyObject *
builtin_float(PyObject *self, PyObject *args)
{
	PyObject *v;

	if (!PyArg_ParseTuple(args, "O:float", &v))
		return NULL;
	if (PyString_Check(v))
		return PyFloat_FromString(v, NULL);
	return PyNumber_Float(v);
}

static char float_doc[] =
"float(x) -> floating point number\n\
\n\
Convert a string or number to a floating point number, if possible.";


static PyObject *
builtin_len(PyObject *self, PyObject *args)
{
	PyObject *v;
	long res;

	if (!PyArg_ParseTuple(args, "O:len", &v))
		return NULL;
	res = PyObject_Size(v);
	if (res < 0 && PyErr_Occurred())
		return NULL;
	return PyInt_FromLong(res);
}

static char len_doc[] =
"len(object) -> integer\n\
\n\
Return the number of items of a sequence or mapping.";


static PyObject *
builtin_list(PyObject *self, PyObject *args)
{
	PyObject *v;

	if (!PyArg_ParseTuple(args, "O:list", &v))
		return NULL;
	return PySequence_List(v);
}

static char list_doc[] =
"list(sequence) -> list\n\
\n\
Return a new list whose items are the same as those of the argument sequence.";


static PyObject *
builtin_slice(PyObject *self, PyObject *args)
{
	PyObject *start, *stop, *step;

	start = stop = step = NULL;

	if (!PyArg_ParseTuple(args, "O|OO:slice", &start, &stop, &step))
		return NULL;

	/* This swapping of stop and start is to maintain similarity with
	   range(). */
	if (stop == NULL) {
		stop = start;
		start = NULL;
	}
	return PySlice_New(start, stop, step);
}

static char slice_doc[] =
"slice([start,] stop[, step]) -> slice object\n\
\n\
Create a slice object.  This is used for slicing by the Numeric extensions.";


static PyObject *
builtin_locals(PyObject *self, PyObject *args)
{
	PyObject *d;

	if (!PyArg_ParseTuple(args, ":locals"))
		return NULL;
	d = PyEval_GetLocals();
	Py_INCREF(d);
	return d;
}

static char locals_doc[] =
"locals() -> dictionary\n\
\n\
Return the dictionary containing the current scope's local variables.";


static PyObject *
min_max(PyObject *args, int op)
{
	int i;
	PyObject *v, *w, *x;
	PySequenceMethods *sq;

	if (PyTuple_Size(args) > 1)
		v = args;
	else if (!PyArg_ParseTuple(args, "O:min/max", &v))
		return NULL;
	sq = v->ob_type->tp_as_sequence;
	if (sq == NULL || sq->sq_item == NULL) {
		PyErr_SetString(PyExc_TypeError,
				"min() or max() arg must be a sequence");
		return NULL;
	}
	w = NULL;
	for (i = 0; ; i++) {
		x = (*sq->sq_item)(v, i); /* Implies INCREF */
		if (x == NULL) {
			if (PyErr_ExceptionMatches(PyExc_IndexError)) {
				PyErr_Clear();
				break;
			}
			Py_XDECREF(w);
			return NULL;
		}
		if (w == NULL)
			w = x;
		else {
			int cmp = PyObject_RichCompareBool(x, w, op);
			if (cmp > 0) {
				Py_DECREF(w);
				w = x;
			}
			else if (cmp < 0) {
				Py_DECREF(x);
				Py_XDECREF(w);
				return NULL;
			}
			else
				Py_DECREF(x);
		}
	}
	if (w == NULL)
		PyErr_SetString(PyExc_ValueError,
				"min() or max() arg is an empty sequence");
	return w;
}

static PyObject *
builtin_min(PyObject *self, PyObject *v)
{
	return min_max(v, Py_LT);
}

static char min_doc[] =
"min(sequence) -> value\n\
min(a, b, c, ...) -> value\n\
\n\
With a single sequence argument, return its smallest item.\n\
With two or more arguments, return the smallest argument.";


static PyObject *
builtin_max(PyObject *self, PyObject *v)
{
	return min_max(v, Py_GT);
}

static char max_doc[] =
"max(sequence) -> value\n\
max(a, b, c, ...) -> value\n\
\n\
With a single sequence argument, return its largest item.\n\
With two or more arguments, return the largest argument.";


static PyObject *
builtin_oct(PyObject *self, PyObject *args)
{
	PyObject *v;
	PyNumberMethods *nb;

	if (!PyArg_ParseTuple(args, "O:oct", &v))
		return NULL;
	if (v == NULL || (nb = v->ob_type->tp_as_number) == NULL ||
	    nb->nb_oct == NULL) {
		PyErr_SetString(PyExc_TypeError,
			   "oct() argument can't be converted to oct");
		return NULL;
	}
	return (*nb->nb_oct)(v);
}

static char oct_doc[] =
"oct(number) -> string\n\
\n\
Return the octal representation of an integer or long integer.";


static PyObject *
builtin_open(PyObject *self, PyObject *args)
{
	char *name;
	char *mode = "r";
	int bufsize = -1;
	PyObject *f;

	if (!PyArg_ParseTuple(args, "s|si:open", &name, &mode, &bufsize))
		return NULL;
	f = PyFile_FromString(name, mode);
	if (f != NULL)
		PyFile_SetBufSize(f, bufsize);
	return f;
}

static char open_doc[] =
"open(filename[, mode[, buffering]]) -> file object\n\
\n\
Open a file.  The mode can be 'r', 'w' or 'a' for reading (default),\n\
writing or appending.  The file will be created if it doesn't exist\n\
when opened for writing or appending; it will be truncated when\n\
opened for writing.  Add a 'b' to the mode for binary files.\n\
Add a '+' to the mode to allow simultaneous reading and writing.\n\
If the buffering argument is given, 0 means unbuffered, 1 means line\n\
buffered, and larger numbers specify the buffer size.";


static PyObject *
builtin_ord(PyObject *self, PyObject *args)
{
	PyObject *obj;
	long ord;
	int size;

	if (!PyArg_ParseTuple(args, "O:ord", &obj))
		return NULL;

	if (PyString_Check(obj)) {
		size = PyString_GET_SIZE(obj);
		if (size == 1) {
			ord = (long)((unsigned char)*PyString_AS_STRING(obj));
			return PyInt_FromLong(ord);
		}
	} else if (PyUnicode_Check(obj)) {
		size = PyUnicode_GET_SIZE(obj);
		if (size == 1) {
			ord = (long)*PyUnicode_AS_UNICODE(obj);
			return PyInt_FromLong(ord);
		}
	} else {
		PyErr_Format(PyExc_TypeError,
			     "ord() expected string of length 1, but " \
			     "%.200s found", obj->ob_type->tp_name);
		return NULL;
	}

	PyErr_Format(PyExc_TypeError,
		     "ord() expected a character, "
		     "but string of length %d found",
		     size);
	return NULL;
}

static char ord_doc[] =
"ord(c) -> integer\n\
\n\
Return the integer ordinal of a one-character string.";


static PyObject *
builtin_pow(PyObject *self, PyObject *args)
{
	PyObject *v, *w, *z = Py_None;

	if (!PyArg_ParseTuple(args, "OO|O:pow", &v, &w, &z))
		return NULL;
	return PyNumber_Power(v, w, z);
}

static char pow_doc[] =
"pow(x, y[, z]) -> number\n\
\n\
With two arguments, equivalent to x**y.  With three arguments,\n\
equivalent to (x**y) % z, but may be more efficient (e.g. for longs).";


/* Return number of items in range/xrange (lo, hi, step).  step > 0
 * required.  Return a value < 0 if & only if the true value is too
 * large to fit in a signed long.
 */
static inline long
get_len_of_range(long lo, long hi, long step)
{
	/* -------------------------------------------------------------
	If lo >= hi, the range is empty.
	Else if n values are in the range, the last one is
	lo + (n-1)*step, which must be <= hi-1.  Rearranging,
	n <= (hi - lo - 1)/step + 1, so taking the floor of the RHS gives
	the proper value.  Since lo < hi in this case, hi-lo-1 >= 0, so
	the RHS is non-negative and so truncation is the same as the
	floor.  Letting M be the largest positive long, the worst case
	for the RHS numerator is hi=M, lo=-M-1, and then
	hi-lo-1 = M-(-M-1)-1 = 2*M.  Therefore unsigned long has enough
	precision to compute the RHS exactly.
	---------------------------------------------------------------*/
	long n = 0;
	if (lo < hi) {
		unsigned long uhi = (unsigned long)hi;
		unsigned long ulo = (unsigned long)lo;
		unsigned long diff = uhi - ulo - 1;
		n = (long)(diff / (unsigned long)step + 1);
	}
	return n;
}

static PyObject *
builtin_range(PyObject *self, PyObject *args)
{
	long ilow = 0, ihigh = 0, istep = 1;
	long bign;
	int i, n;

	PyObject *v;

	if (PyTuple_Size(args) <= 1) {
		if (!PyArg_ParseTuple(args,
				"l;range() requires 1-3 int arguments",
				&ihigh))
			return NULL;
	}
	else {
		if (!PyArg_ParseTuple(args,
				"ll|l;range() requires 1-3 int arguments",
				&ilow, &ihigh, &istep))
			return NULL;
	}
	if (istep == 0) {
		PyErr_SetString(PyExc_ValueError, "range() arg 3 must not be zero");
		return NULL;
	}
	if (istep > 0)
		bign = get_len_of_range(ilow, ihigh, istep);
	else
		bign = get_len_of_range(ihigh, ilow, -istep);
	n = (int)bign;
	if (bign < 0 || (long)n != bign) {
		PyErr_SetString(PyExc_OverflowError,
				"range() result has too many items");
		return NULL;
	}
	v = PyList_New(n);
	if (v == NULL)
		return NULL;
	for (i = 0; i < n; i++) {
		PyObject *w = PyInt_FromLong(ilow);
		if (w == NULL) {
			Py_DECREF(v);
			return NULL;
		}
		PyList_SET_ITEM(v, i, w);
		ilow += istep;
	}
	return v;
}

static char range_doc[] =
"range([start,] stop[, step]) -> list of integers\n\
\n\
Return a list containing an arithmetic progression of integers.\n\
range(i, j) returns [i, i+1, i+2, ..., j-1]; start (!) defaults to 0.\n\
When step is given, it specifies the increment (or decrement).\n\
For example, range(4) returns [0, 1, 2, 3].  The end point is omitted!\n\
These are exactly the valid indices for a list of 4 elements.";


static PyObject *
builtin_xrange(PyObject *self, PyObject *args)
{
	long ilow = 0, ihigh = 0, istep = 1;
	long n;

	if (PyTuple_Size(args) <= 1) {
		if (!PyArg_ParseTuple(args,
				"l;xrange() requires 1-3 int arguments",
				&ihigh))
			return NULL;
	}
	else {
		if (!PyArg_ParseTuple(args,
				"ll|l;xrange() requires 1-3 int arguments",
				&ilow, &ihigh, &istep))
			return NULL;
	}
	if (istep == 0) {
		PyErr_SetString(PyExc_ValueError, "xrange() arg 3 must not be zero");
		return NULL;
	}
	if (istep > 0)
		n = get_len_of_range(ilow, ihigh, istep);
	else
		n = get_len_of_range(ihigh, ilow, -istep);
	if (n < 0) {
		PyErr_SetString(PyExc_OverflowError,
				"xrange() result has too many items");
		return NULL;
	}
	return PyRange_New(ilow, n, istep, 1);
}

static char xrange_doc[] =
"xrange([start,] stop[, step]) -> xrange object\n\
\n\
Like range(), but instead of returning a list, returns an object that\n\
generates the numbers in the range on demand.  This is slightly slower\n\
than range() but more memory efficient.";


static PyObject *
builtin_raw_input(PyObject *self, PyObject *args)
{
	PyObject *v = NULL;
	PyObject *f;

	if (!PyArg_ParseTuple(args, "|O:[raw_]input", &v))
		return NULL;
	if (PyFile_AsFile(PySys_GetObject("stdin")) == stdin &&
	    PyFile_AsFile(PySys_GetObject("stdout")) == stdout &&
	    isatty(fileno(stdin)) && isatty(fileno(stdout))) {
		PyObject *po;
		char *prompt;
		char *s;
		PyObject *result;
		if (v != NULL) {
			po = PyObject_Str(v);
			if (po == NULL)
				return NULL;
			prompt = PyString_AsString(po);
			if (prompt == NULL)
				return NULL;
		}
		else {
			po = NULL;
			prompt = "";
		}
		s = PyOS_Readline(prompt);
		Py_XDECREF(po);
		if (s == NULL) {
			PyErr_SetNone(PyExc_KeyboardInterrupt);
			return NULL;
		}
		if (*s == '\0') {
			PyErr_SetNone(PyExc_EOFError);
			result = NULL;
		}
		else { /* strip trailing '\n' */
			size_t len = strlen(s);
			if (len > INT_MAX) {
				PyErr_SetString(PyExc_OverflowError, "input too long");
				result = NULL;
			}
			else {
				result = PyString_FromStringAndSize(s, (int)(len-1));
			}
		}
		PyMem_FREE(s);
		return result;
	}
	if (v != NULL) {
		f = PySys_GetObject("stdout");
		if (f == NULL) {
			PyErr_SetString(PyExc_RuntimeError, "lost sys.stdout");
			return NULL;
		}
		if (Py_FlushLine() != 0 ||
		    PyFile_WriteObject(v, f, Py_PRINT_RAW) != 0)
			return NULL;
	}
	f = PySys_GetObject("stdin");
	if (f == NULL) {
		PyErr_SetString(PyExc_RuntimeError, "lost sys.stdin");
		return NULL;
	}
	return PyFile_GetLine(f, -1);
}

static char raw_input_doc[] =
"raw_input([prompt]) -> string\n\
\n\
Read a string from standard input.  The trailing newline is stripped.\n\
If the user hits EOF (Unix: Ctl-D, Windows: Ctl-Z+Return), raise EOFError.\n\
On Unix, GNU readline is used if enabled.  The prompt string, if given,\n\
is printed without a trailing newline before reading.";


static PyObject *
builtin_reduce(PyObject *self, PyObject *args)
{
	PyObject *seq, *func, *result = NULL;
	PySequenceMethods *sqf;
	register int i;

	if (!PyArg_ParseTuple(args, "OO|O:reduce", &func, &seq, &result))
		return NULL;
	if (result != NULL)
		Py_INCREF(result);

	sqf = seq->ob_type->tp_as_sequence;
	if (sqf == NULL || sqf->sq_item == NULL) {
		PyErr_SetString(PyExc_TypeError,
		    "reduce() arg 2 must be a sequence");
		return NULL;
	}

	if ((args = PyTuple_New(2)) == NULL)
		goto Fail;

	for (i = 0; ; ++i) {
		PyObject *op2;

		if (args->ob_refcnt > 1) {
			Py_DECREF(args);
			if ((args = PyTuple_New(2)) == NULL)
				goto Fail;
		}

		if ((op2 = (*sqf->sq_item)(seq, i)) == NULL) {
			if (PyErr_ExceptionMatches(PyExc_IndexError)) {
				PyErr_Clear();
				break;
			}
			goto Fail;
		}

		if (result == NULL)
			result = op2;
		else {
			PyTuple_SetItem(args, 0, result);
			PyTuple_SetItem(args, 1, op2);
			if ((result = PyEval_CallObject(func, args)) == NULL)
				goto Fail;
		}
	}

	Py_DECREF(args);

	if (result == NULL)
		PyErr_SetString(PyExc_TypeError,
			   "reduce() of empty sequence with no initial value");

	return result;

Fail:
	Py_XDECREF(args);
	Py_XDECREF(result);
	return NULL;
}

static char reduce_doc[] =
"reduce(function, sequence[, initial]) -> value\n\
\n\
Apply a function of two arguments cumulatively to the items of a sequence,\n\
from left to right, so as to reduce the sequence to a single value.\n\
For example, reduce(lambda x, y: x+y, [1, 2, 3, 4, 5]) calculates\n\
((((1+2)+3)+4)+5).  If initial is present, it is placed before the items\n\
of the sequence in the calculation, and serves as a default when the\n\
sequence is empty.";


static PyObject *
builtin_reload(PyObject *self, PyObject *args)
{
	PyObject *v;

	if (!PyArg_ParseTuple(args, "O:reload", &v))
		return NULL;
	return PyImport_ReloadModule(v);
}

static char reload_doc[] =
"reload(module) -> module\n\
\n\
Reload the module.  The module must have been successfully imported before.";


static PyObject *
builtin_repr(PyObject *self, PyObject *args)
{
	PyObject *v;

	if (!PyArg_ParseTuple(args, "O:repr", &v))
		return NULL;
	return PyObject_Repr(v);
}

static char repr_doc[] =
"repr(object) -> string\n\
\n\
Return the canonical string representation of the object.\n\
For most object types, eval(repr(object)) == object.";


static PyObject *
builtin_round(PyObject *self, PyObject *args)
{
	double x;
	double f;
	int ndigits = 0;
	int i;

	if (!PyArg_ParseTuple(args, "d|i:round", &x, &ndigits))
			return NULL;
	f = 1.0;
	i = abs(ndigits);
	while  (--i >= 0)
		f = f*10.0;
	if (ndigits < 0)
		x /= f;
	else
		x *= f;
	if (x >= 0.0)
		x = floor(x + 0.5);
	else
		x = ceil(x - 0.5);
	if (ndigits < 0)
		x *= f;
	else
		x /= f;
	return PyFloat_FromDouble(x);
}

static char round_doc[] =
"round(number[, ndigits]) -> floating point number\n\
\n\
Round a number to a given precision in decimal digits (default 0 digits).\n\
This always returns a floating point number.  Precision may be negative.";


static PyObject *
builtin_str(PyObject *self, PyObject *args)
{
	PyObject *v;

	if (!PyArg_ParseTuple(args, "O:str", &v))
		return NULL;
	return PyObject_Str(v);
}

static char str_doc[] =
"str(object) -> string\n\
\n\
Return a nice string representation of the object.\n\
If the argument is a string, the return value is the same object.";


static PyObject *
builtin_tuple(PyObject *self, PyObject *args)
{
	PyObject *v;

	if (!PyArg_ParseTuple(args, "O:tuple", &v))
		return NULL;
	return PySequence_Tuple(v);
}

static char tuple_doc[] =
"tuple(sequence) -> list\n\
\n\
Return a tuple whose items are the same as those of the argument sequence.\n\
If the argument is a tuple, the return value is the same object.";


static PyObject *
builtin_type(PyObject *self, PyObject *args)
{
	PyObject *v;

	if (!PyArg_ParseTuple(args, "O:type", &v))
		return NULL;
	v = (PyObject *)v->ob_type;
	Py_INCREF(v);
	return v;
}

static char type_doc[] =
"type(object) -> type object\n\
\n\
Return the type of the object.";


static PyObject *
builtin_vars(PyObject *self, PyObject *args)
{
	PyObject *v = NULL;
	PyObject *d;

	if (!PyArg_ParseTuple(args, "|O:vars", &v))
		return NULL;
	if (v == NULL) {
		d = PyEval_GetLocals();
		if (d == NULL) {
			if (!PyErr_Occurred())
				PyErr_SetString(PyExc_SystemError,
						"no locals!?");
		}
		else
			Py_INCREF(d);
	}
	else {
		d = PyObject_GetAttrString(v, "__dict__");
		if (d == NULL) {
			PyErr_SetString(PyExc_TypeError,
			    "vars() argument must have __dict__ attribute");
			return NULL;
		}
	}
	return d;
}

static char vars_doc[] =
"vars([object]) -> dictionary\n\
\n\
Without arguments, equivalent to locals().\n\
With an argument, equivalent to object.__dict__.";

static PyObject *
builtin_isinstance(PyObject *self, PyObject *args)
{
	PyObject *inst;
	PyObject *cls;
	int retval;

	if (!PyArg_ParseTuple(args, "OO:isinstance", &inst, &cls))
		return NULL;

	retval = PyObject_IsInstance(inst, cls);
	if (retval < 0)
		return NULL;
	return PyInt_FromLong(retval);
}

static char isinstance_doc[] =
"isinstance(object, class-or-type) -> Boolean\n\
\n\
Return whether an object is an instance of a class or of a subclass thereof.\n\
With a type as second argument, return whether that is the object's type.";


static PyObject *
builtin_issubclass(PyObject *self, PyObject *args)
{
	PyObject *derived;
	PyObject *cls;
	int retval;

	if (!PyArg_ParseTuple(args, "OO:issubclass", &derived, &cls))
		return NULL;

	retval = PyObject_IsSubclass(derived, cls);
	if (retval < 0)
		return NULL;
	return PyInt_FromLong(retval);
}

static char issubclass_doc[] =
"issubclass(C, B) -> Boolean\n\
\n\
Return whether class C is a subclass (i.e., a derived class) of class B.";


static PyObject*
builtin_zip(PyObject *self, PyObject *args)
{
	PyObject *ret;
	int itemsize = PySequence_Length(args);
	int i, j;

	if (itemsize < 1) {
		PyErr_SetString(PyExc_TypeError,
				"zip() requires at least one sequence");
		return NULL;
	}
	/* args must be a tuple */
	assert(PyTuple_Check(args));

	if ((ret = PyList_New(0)) == NULL)
		return NULL;

	for (i = 0;; i++) {
		PyObject *next = PyTuple_New(itemsize);
		if (!next) {
			Py_DECREF(ret);
			return NULL;
		}
		for (j = 0; j < itemsize; j++) {
			PyObject *seq = PyTuple_GET_ITEM(args, j);
			PyObject *item = PySequence_GetItem(seq, i);

			if (!item) {
				if (PyErr_ExceptionMatches(PyExc_IndexError)) {
					PyErr_Clear();
					Py_DECREF(next);
					return ret;
				}
				Py_DECREF(next);
				Py_DECREF(ret);
				return NULL;
			}
			PyTuple_SET_ITEM(next, j, item);
		}
		PyList_Append(ret, next);
		Py_DECREF(next);
	}
	/* no return */
}


static char zip_doc[] =
"zip(seq1 [, seq2 [...]]) -> [(seq1[0], seq2[0] ...), (...)]\n\
\n\
Return a list of tuples, where each tuple contains the i-th element\n\
from each of the argument sequences.  The returned list is truncated\n\
in length to the length of the shortest argument sequence.";


static PyMethodDef builtin_methods[] = {
	{"__import__",	builtin___import__, 1, import_doc},
	{"abs",		builtin_abs, 1, abs_doc},
	{"apply",	builtin_apply, 1, apply_doc},
	{"buffer",	builtin_buffer, 1, buffer_doc},
	{"callable",	builtin_callable, 1, callable_doc},
	{"chr",		builtin_chr, 1, chr_doc},
	{"cmp",		builtin_cmp, 1, cmp_doc},
	{"coerce",	builtin_coerce, 1, coerce_doc},
	{"compile",	builtin_compile, 1, compile_doc},
#ifndef WITHOUT_COMPLEX
	{"complex",	builtin_complex, 1, complex_doc},
#endif
	{"delattr",	builtin_delattr, 1, delattr_doc},
	{"dir",		builtin_dir, 1, dir_doc},
	{"divmod",	builtin_divmod, 1, divmod_doc},
	{"eval",	builtin_eval, 1, eval_doc},
	{"execfile",	builtin_execfile, 1, execfile_doc},
	{"filter",	builtin_filter, 1, filter_doc},
	{"float",	builtin_float, 1, float_doc},
	{"getattr",	builtin_getattr, 1, getattr_doc},
	{"globals",	builtin_globals, 1, globals_doc},
	{"hasattr",	builtin_hasattr, 1, hasattr_doc},
	{"hash",	builtin_hash, 1, hash_doc},
	{"hex",		builtin_hex, 1, hex_doc},
	{"id",		builtin_id, 1, id_doc},
	{"input",	builtin_input, 1, input_doc},
	{"intern",	builtin_intern, 1, intern_doc},
	{"int",		builtin_int, 1, int_doc},
	{"isinstance",  builtin_isinstance, 1, isinstance_doc},
	{"issubclass",  builtin_issubclass, 1, issubclass_doc},
	{"len",		builtin_len, 1, len_doc},
	{"list",	builtin_list, 1, list_doc},
	{"locals",	builtin_locals, 1, locals_doc},
	{"long",	builtin_long, 1, long_doc},
	{"map",		builtin_map, 1, map_doc},
	{"max",		builtin_max, 1, max_doc},
	{"min",		builtin_min, 1, min_doc},
	{"oct",		builtin_oct, 1, oct_doc},
	{"open",	builtin_open, 1, open_doc},
	{"ord",		builtin_ord, 1, ord_doc},
	{"pow",		builtin_pow, 1, pow_doc},
	{"range",	builtin_range, 1, range_doc},
	{"raw_input",	builtin_raw_input, 1, raw_input_doc},
	{"reduce",	builtin_reduce, 1, reduce_doc},
	{"reload",	builtin_reload, 1, reload_doc},
	{"repr",	builtin_repr, 1, repr_doc},
	{"round",	builtin_round, 1, round_doc},
	{"setattr",	builtin_setattr, 1, setattr_doc},
	{"slice",       builtin_slice, 1, slice_doc},
	{"str",		builtin_str, 1, str_doc},
	{"tuple",	builtin_tuple, 1, tuple_doc},
	{"type",	builtin_type, 1, type_doc},
	{"unicode",	builtin_unicode, 1, unicode_doc},
	{"unichr",	builtin_unichr, 1, unichr_doc},
	{"vars",	builtin_vars, 1, vars_doc},
	{"xrange",	builtin_xrange, 1, xrange_doc},
 	{"zip",         builtin_zip, 1, zip_doc},
	{NULL,		NULL},
};

static char builtin_doc[] =
"Built-in functions, exceptions, and other objects.\n\
\n\
Noteworthy: None is the `nil' object; Ellipsis represents `...' in slices.";

PyObject *
_PyBuiltin_Init(void)
{
	PyObject *mod, *dict, *debug;
	mod = Py_InitModule4("__builtin__", builtin_methods,
			     builtin_doc, (PyObject *)NULL,
			     PYTHON_API_VERSION);
	if (mod == NULL)
		return NULL;
	dict = PyModule_GetDict(mod);
	if (PyDict_SetItemString(dict, "None", Py_None) < 0)
		return NULL;
	if (PyDict_SetItemString(dict, "Ellipsis", Py_Ellipsis) < 0)
		return NULL;
	if (PyDict_SetItemString(dict, "NotImplemented",
				 Py_NotImplemented) < 0)
		return NULL;
	debug = PyInt_FromLong(Py_OptimizeFlag == 0);
	if (PyDict_SetItemString(dict, "__debug__", debug) < 0) {
		Py_XDECREF(debug);
		return NULL;
	}
	Py_XDECREF(debug);

	return mod;
}

/* Helper for filter(): filter a tuple through a function */

static PyObject *
filtertuple(PyObject *func, PyObject *tuple)
{
	PyObject *result;
	register int i, j;
	int len = PyTuple_Size(tuple);

	if (len == 0) {
		Py_INCREF(tuple);
		return tuple;
	}

	if ((result = PyTuple_New(len)) == NULL)
		return NULL;

	for (i = j = 0; i < len; ++i) {
		PyObject *item, *good;
		int ok;

		if ((item = PyTuple_GetItem(tuple, i)) == NULL)
			goto Fail_1;
		if (func == Py_None) {
			Py_INCREF(item);
			good = item;
		}
		else {
			PyObject *arg = Py_BuildValue("(O)", item);
			if (arg == NULL)
				goto Fail_1;
			good = PyEval_CallObject(func, arg);
			Py_DECREF(arg);
			if (good == NULL)
				goto Fail_1;
		}
		ok = PyObject_IsTrue(good);
		Py_DECREF(good);
		if (ok) {
			Py_INCREF(item);
			if (PyTuple_SetItem(result, j++, item) < 0)
				goto Fail_1;
		}
	}

	if (_PyTuple_Resize(&result, j, 0) < 0)
		return NULL;

	return result;

Fail_1:
	Py_DECREF(result);
	return NULL;
}


/* Helper for filter(): filter a string through a function */

static PyObject *
filterstring(PyObject *func, PyObject *strobj)
{
	PyObject *result;
	register int i, j;
	int len = PyString_Size(strobj);

	if (func == Py_None) {
		/* No character is ever false -- share input string */
		Py_INCREF(strobj);
		return strobj;
	}
	if ((result = PyString_FromStringAndSize(NULL, len)) == NULL)
		return NULL;

	for (i = j = 0; i < len; ++i) {
		PyObject *item, *arg, *good;
		int ok;

		item = (*strobj->ob_type->tp_as_sequence->sq_item)(strobj, i);
		if (item == NULL)
			goto Fail_1;
		arg = Py_BuildValue("(O)", item);
		if (arg == NULL) {
			Py_DECREF(item);
			goto Fail_1;
		}
		good = PyEval_CallObject(func, arg);
		Py_DECREF(arg);
		if (good == NULL) {
			Py_DECREF(item);
			goto Fail_1;
		}
		ok = PyObject_IsTrue(good);
		Py_DECREF(good);
		if (ok)
			PyString_AS_STRING((PyStringObject *)result)[j++] =
				PyString_AS_STRING((PyStringObject *)item)[0];
		Py_DECREF(item);
	}

	if (j < len && _PyString_Resize(&result, j) < 0)
		return NULL;

	return result;

Fail_1:
	Py_DECREF(result);
	return NULL;
}
