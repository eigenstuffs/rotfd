/* Adapted from CPython 2.1 Objects/abstract.c and Include headers.
 * See reference/cpython-2.1/LICENSE. GSQE78 .text 0x80130084..0x80134E70.
 * GC bookkeeping and assertions are disabled in this target build.
 * Explicit inline helpers retain the original linked function inventory.
 */
#include "object.h"
typedef struct _FILE FILE;
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


static PyObject *__class__ = NULL;
static PyObject *__bases__ = NULL;

#define PyList_SET_ITEM(op, i, v) (((PyListObject *)(op))->ob_item[i] = (v))
#define PyType_Check(op) ((op)->ob_type == &PyType_Type)
static char abstract_class_attribute[] = "PyAbstract__class__";
static char abstract_isinstance_class[] = "isinstance() arg 2 must be a class or type";
static char abstract_bases_attribute[] = "PyAbstract__bases__";
static char abstract_issubclass_arg2[] = "issubclass() arg 2 must be a class";
static char abstract_issubclass_arg1[] = "issubclass() arg 1 must be a class";
static char abstract_null_argument[] = "null argument to internal routine";
static char abstract_noncallable_attribute[] = "call of non-callable attribute";
static char abstract_unindexable[] = "unindexable object";
static char abstract_integer_index[] = "sequence index must be integer";
static char abstract_unsubscriptable[] = "unsubscriptable object";
static char abstract_no_assignment[] = "object doesn't support item assignment";
static char abstract_no_item_assignment[] = "object does not support item assignment";
static char abstract_unsized_object[] = "len() of unsized object";
static char abstract_contains_sequence[] = "'in' or 'not in' needs sequence right argument";
static char abstract_list_sequence[] = "list() argument must be a sequence";
static char abstract_tuple_sequence[] = "tuple() argument must be a sequence";
static char abstract_no_slice_deletion[] = "object doesn't support slice deletion";
static char abstract_no_slice_assignment[] = "object doesn't support slice assignment";
static char abstract_no_item_deletion[] = "object doesn't support item deletion";
static char abstract_unsliceable[] = "unsliceable object";
static char abstract_long_null_byte[] = "null byte in argument for long()";
static char abstract_character_buffer[] = "expected a character buffer object";
static char abstract_single_segment[] = "expected a single-segment buffer object";
static char abstract_no_long_conversion[] = "object can't be converted to long";
static char abstract_int_null_byte[] = "null byte in argument for int()";
static char abstract_no_int_conversion[] = "object can't be converted to int";
static char abstract_abs_operand[] = "bad operand type for abs()";
static char abstract_invert_operand[] = "bad operand type for unary ~";
static char abstract_positive_operand[] = "bad operand type for unary +";
static char abstract_negative_operand[] = "bad operand type for unary -";
static char abstract_binary_operands[] = "unsupported operand type(s) for %s";
static char abstract_multiply_nonint[] = "can't multiply sequence to non-int";
static char abstract_power_operator[] = "** or pow()";
static char abstract_add_operands[] = "unsupported operand types for +";
static char abstract_divmod_operator[] = "divmod()";
static char abstract_readable_buffer[] = "expected a readable buffer object";
static char abstract_no_mapping_deletion[] = "object does not support item deletion";

/* Abstract Object Interface (many thanks to Jim Fulton) */






#define NEW_STYLE_NUMBER(o) PyType_HasFeature((o)->ob_type, \
				Py_TPFLAGS_CHECKTYPES)

/* Shorthands to return certain errors */

static inline PyObject *
type_error(const char *msg)
{
	PyErr_SetString(PyExc_TypeError, msg);
	return NULL;
}

static inline PyObject *
null_error(void)
{
	if (!PyErr_Occurred())
		PyErr_SetString(PyExc_SystemError,
				abstract_null_argument);
	return NULL;
}

/* Operations on any object */

int
PyObject_Cmp(PyObject *o1, PyObject *o2, int *result)
{
	int r;

	if (o1 == NULL || o2 == NULL) {
		null_error();
		return -1;
	}
	r = PyObject_Compare(o1, o2);
	if (PyErr_Occurred())
		return -1;
	*result = r;
	return 0;
}


int
PyObject_Size(PyObject *o)
{
	PySequenceMethods *m;

	if (o == NULL) {
		null_error();
		return -1;
	}

	m = o->ob_type->tp_as_sequence;
	if (m && m->sq_length)
		return m->sq_length(o);

	return PyMapping_Size(o);
}

#undef PyObject_Length
#define PyObject_Length PyObject_Size

PyObject *
PyObject_GetItem(PyObject *o, PyObject *key)
{
	PyMappingMethods *m;

	if (o == NULL || key == NULL)
		return null_error();

	m = o->ob_type->tp_as_mapping;
	if (m && m->mp_subscript)
		return m->mp_subscript(o, key);

	if (o->ob_type->tp_as_sequence) {
		if (PyInt_Check(key))
			return PySequence_GetItem(o, PyInt_AsLong(key));
		else if (PyLong_Check(key)) {
			long key_value = PyLong_AsLong(key);
			if (key_value == -1 && PyErr_Occurred())
				return NULL;
			return PySequence_GetItem(o, key_value);
		}
		return type_error(abstract_integer_index);
	}

	return type_error(abstract_unsubscriptable);
}

int
PyObject_SetItem(PyObject *o, PyObject *key, PyObject *value)
{
	PyMappingMethods *m;

	if (o == NULL || key == NULL || value == NULL) {
		null_error();
		return -1;
	}
	m = o->ob_type->tp_as_mapping;
	if (m && m->mp_ass_subscript)
		return m->mp_ass_subscript(o, key, value);

	if (o->ob_type->tp_as_sequence) {
		if (PyInt_Check(key))
			return PySequence_SetItem(o, PyInt_AsLong(key), value);
		else if (PyLong_Check(key)) {
			long key_value = PyLong_AsLong(key);
			if (key_value == -1 && PyErr_Occurred())
				return -1;
			return PySequence_SetItem(o, key_value, value);
		}
		type_error(abstract_integer_index);
		return -1;
	}

	type_error(abstract_no_item_assignment);
	return -1;
}

int
PyObject_DelItem(PyObject *o, PyObject *key)
{
	PyMappingMethods *m;

	if (o == NULL || key == NULL) {
		null_error();
		return -1;
	}
	m = o->ob_type->tp_as_mapping;
	if (m && m->mp_ass_subscript)
		return m->mp_ass_subscript(o, key, (PyObject*)NULL);

	if (o->ob_type->tp_as_sequence) {
		if (PyInt_Check(key))
			return PySequence_DelItem(o, PyInt_AsLong(key));
		else if (PyLong_Check(key)) {
			long key_value = PyLong_AsLong(key);
			if (key_value == -1 && PyErr_Occurred())
				return -1;
			return PySequence_DelItem(o, key_value);
		}
		type_error(abstract_integer_index);
		return -1;
	}

	type_error(abstract_no_mapping_deletion);
	return -1;
}

int PyObject_AsCharBuffer(PyObject *obj,
			  const char **buffer,
			  int *buffer_len)
{
	PyBufferProcs *pb;
	const char *pp;
	int len;

	if (obj == NULL || buffer == NULL || buffer_len == NULL) {
		null_error();
		return -1;
	}
	pb = obj->ob_type->tp_as_buffer;
	if ( pb == NULL ||
	     pb->bf_getcharbuffer == NULL ||
	     pb->bf_getsegcount == NULL ) {
		PyErr_SetString(PyExc_TypeError,
				abstract_character_buffer);
		goto onError;
	}
	if ( (*pb->bf_getsegcount)(obj,NULL) != 1 ) {
		PyErr_SetString(PyExc_TypeError,
				abstract_single_segment);
		goto onError;
	}
	len = (*pb->bf_getcharbuffer)(obj,0,&pp);
	if (len < 0)
		goto onError;
	*buffer = pp;
	*buffer_len = len;
	return 0;

 onError:
	return -1;
}

int PyObject_AsReadBuffer(PyObject *obj,
			  const void **buffer,
			  int *buffer_len)
{
	PyBufferProcs *pb;
	void *pp;
	int len;

	if (obj == NULL || buffer == NULL || buffer_len == NULL) {
		null_error();
		return -1;
	}
	pb = obj->ob_type->tp_as_buffer;
	if ( pb == NULL ||
	     pb->bf_getreadbuffer == NULL ||
	     pb->bf_getsegcount == NULL ) {
		PyErr_SetString(PyExc_TypeError,
				abstract_readable_buffer);
		goto onError;
	}
	if ( (*pb->bf_getsegcount)(obj,NULL) != 1 ) {
		PyErr_SetString(PyExc_TypeError,
				abstract_single_segment);
		goto onError;
	}
	len = (*pb->bf_getreadbuffer)(obj,0,&pp);
	if (len < 0)
		goto onError;
	*buffer = pp;
	*buffer_len = len;
	return 0;

 onError:
	return -1;
}


/* Operations on numbers */


/* Binary operators */

/* New style number protocol support */

#define NB_SLOT(x) offsetof(PyNumberMethods, x)
#define NB_BINOP(nb_methods, slot) \
		((binaryfunc*)(& ((char*)nb_methods)[slot] ))
#define NB_TERNOP(nb_methods, slot) \
		((ternaryfunc*)(& ((char*)nb_methods)[slot] ))

/*
  Calling scheme used for binary operations:

  v	w	Action
  -------------------------------------------------------------------
  new	new	v.op(v,w), w.op(v,w)
  new	old	v.op(v,w), coerce(v,w), v.op(v,w)
  old	new	w.op(v,w), coerce(v,w), v.op(v,w)
  old	old	coerce(v,w), v.op(v,w)

  Legend:
  -------
  * new == new style number
  * old == old style number
  * Action indicates the order in which operations are tried until either
    a valid result is produced or an error occurs.

 */

static PyObject *
binary_op1(PyObject *v, PyObject *w, const int op_slot)
{
	PyObject *x;
	binaryfunc *slot;
	if (v->ob_type->tp_as_number != NULL && NEW_STYLE_NUMBER(v)) {
		slot = NB_BINOP(v->ob_type->tp_as_number, op_slot);
		if (*slot) {
			x = (*slot)(v, w);
			if (x != Py_NotImplemented) {
				return x;
			}
			Py_DECREF(x); /* can't do it */
		}
		if (v->ob_type == w->ob_type) {
			goto binop_error;
		}
	}
	if (w->ob_type->tp_as_number != NULL && NEW_STYLE_NUMBER(w)) {
		slot = NB_BINOP(w->ob_type->tp_as_number, op_slot);
		if (*slot) {
			x = (*slot)(v, w);
			if (x != Py_NotImplemented) {
				return x;
			}
			Py_DECREF(x); /* can't do it */
		}
	}
	if (!NEW_STYLE_NUMBER(v) || !NEW_STYLE_NUMBER(w)) {
		int err = PyNumber_CoerceEx(&v, &w);
		if (err < 0) {
			return NULL;
		}
		if (err == 0) {
			PyNumberMethods *mv = v->ob_type->tp_as_number;
			if (mv) {
				slot = NB_BINOP(mv, op_slot);
				if (*slot) {
					PyObject *x = (*slot)(v, w);
					Py_DECREF(v);
					Py_DECREF(w);
					return x;
				}
			}
			/* CoerceEx incremented the reference counts */
			Py_DECREF(v);
			Py_DECREF(w);
		}
	}
binop_error:
	Py_INCREF(Py_NotImplemented);
	return Py_NotImplemented;
}
	    
static inline PyObject *
binary_op(PyObject *v, PyObject *w, const int op_slot, const char *op_name)
{
	PyObject *result = binary_op1(v, w, op_slot);
	if (result == Py_NotImplemented) {
		Py_DECREF(Py_NotImplemented);
		PyErr_Format(PyExc_TypeError, 
				abstract_binary_operands, op_name);
		return NULL;
	}
	return result;
}


/*
  Calling scheme used for ternary operations:

  v	w	z	Action
  -------------------------------------------------------------------
  new	new	new	v.op(v,w,z), w.op(v,w,z), z.op(v,w,z)
  new	old	new	v.op(v,w,z), z.op(v,w,z), coerce(v,w,z), v.op(v,w,z)
  old	new	new	w.op(v,w,z), z.op(v,w,z), coerce(v,w,z), v.op(v,w,z)
  old	old	new	z.op(v,w,z), coerce(v,w,z), v.op(v,w,z)
  new	new	old	v.op(v,w,z), w.op(v,w,z), coerce(v,w,z), v.op(v,w,z)
  new	old	old	v.op(v,w,z), coerce(v,w,z), v.op(v,w,z)
  old	new	old	w.op(v,w,z), coerce(v,w,z), v.op(v,w,z)
  old	old	old	coerce(v,w,z), v.op(v,w,z)

  Legend:
  -------
  * new == new style number
  * old == old style number
  * Action indicates the order in which operations are tried until either
    a valid result is produced or an error occurs.
  * coerce(v,w,z) actually does: coerce(v,w), coerce(v,z), coerce(w,z) and
    only if z != Py_None; if z == Py_None, then it is treated as absent
    variable and only coerce(v,w) is tried.

 */

static PyObject *
ternary_op(PyObject *v,
	   PyObject *w,
	   PyObject *z,
	   const int op_slot,
	   const char *op_name)
{
	PyNumberMethods *mv, *mw, *mz;
	register PyObject *x = NULL;
	register ternaryfunc *slot;
	
	mv = v->ob_type->tp_as_number;
	if (mv != NULL && NEW_STYLE_NUMBER(v)) {
		/* try v.op(v,w,z) */
		slot = NB_TERNOP(mv, op_slot);
		if (*slot) {
			x = (*slot)(v, w, z);
			if (x != Py_NotImplemented)
				return x;
			/* Can't do it... fall through */
			Py_DECREF(x);
		}
		if (v->ob_type == w->ob_type &&
				(z == Py_None || z->ob_type == v->ob_type)) {
			goto ternary_error;
		}
	}
	mw = w->ob_type->tp_as_number;
	if (mw != NULL && NEW_STYLE_NUMBER(w)) {
		/* try w.op(v,w,z) */
		slot = NB_TERNOP(mw,op_slot);
		if (*slot) {
			x = (*slot)(v, w, z);
			if (x != Py_NotImplemented)
				return x;
			/* Can't do it... fall through */
			Py_DECREF(x);
		}
		if (NEW_STYLE_NUMBER(v) &&
				(z == Py_None || z->ob_type == v->ob_type)) {
			goto ternary_error;
		}
	}
	mz = z->ob_type->tp_as_number;
	if (mz != NULL && NEW_STYLE_NUMBER(z)) {
		/* try: z.op(v,w,z) */
		slot = NB_TERNOP(mz, op_slot);
		if (*slot) {
			x = (*slot)(v, w, z);
			if (x != Py_NotImplemented)
				return x;
			/* Can't do it... fall through */
			Py_DECREF(x);
		}
	}

	if (!NEW_STYLE_NUMBER(v) || !NEW_STYLE_NUMBER(w) ||
			(z != Py_None && !NEW_STYLE_NUMBER(z))) {
		/* we have an old style operand, coerce */
		PyObject *v1, *z1, *w2, *z2;
		int c;
		
		c = PyNumber_Coerce(&v, &w);
		if (c != 0)
			goto error3;

		/* Special case: if the third argument is None, it is
		   treated as absent argument and not coerced. */
		if (z == Py_None) {
			if (v->ob_type->tp_as_number) {
				slot = NB_TERNOP(v->ob_type->tp_as_number,
						 op_slot);
				if (*slot)
					x = (*slot)(v, w, z);
				else
					c = -1;
			}
			else
				c = -1;
			goto error2;
		}
		v1 = v;
		z1 = z;
		c = PyNumber_Coerce(&v1, &z1);
		if (c != 0)
			goto error2;
		w2 = w;
		z2 = z1;
		c = PyNumber_Coerce(&w2, &z2);
		if (c != 0)
			goto error1;

		if (v1->ob_type->tp_as_number != NULL) {
			slot = NB_TERNOP(v1->ob_type->tp_as_number,
					 op_slot);
			if (*slot)
				x = (*slot)(v1, w2, z2);
			else
				c = -1;
		}
		else
			c = -1;

		Py_DECREF(w2);
		Py_DECREF(z2);
	error1:
		Py_DECREF(v1);
		Py_DECREF(z1);
	error2:
		Py_DECREF(v);
		Py_DECREF(w);
	error3:
		if (c >= 0)
			return x;
	}
	
ternary_error:
	PyErr_Format(PyExc_TypeError, abstract_binary_operands,
			op_name);
	return NULL;
}

#define BINARY_FUNC(func, op, op_name) \
    PyObject * \
    func(PyObject *v, PyObject *w) { \
	    return binary_op(v, w, NB_SLOT(op), op_name); \
    }

BINARY_FUNC(PyNumber_Or, nb_or, "|")
BINARY_FUNC(PyNumber_Xor, nb_xor, "^")
BINARY_FUNC(PyNumber_And, nb_and, "&")
BINARY_FUNC(PyNumber_Lshift, nb_lshift, "<<")
BINARY_FUNC(PyNumber_Rshift, nb_rshift, ">>")
BINARY_FUNC(PyNumber_Subtract, nb_subtract, "-")
BINARY_FUNC(PyNumber_Multiply, nb_multiply, "*")
BINARY_FUNC(PyNumber_Divide, nb_divide, "/")
BINARY_FUNC(PyNumber_Divmod, nb_divmod, abstract_divmod_operator)

PyObject *
PyNumber_Add(PyObject *v, PyObject *w)
{
	PyObject *result = binary_op1(v, w, NB_SLOT(nb_add));
	if (result == Py_NotImplemented) {
		PySequenceMethods *m = v->ob_type->tp_as_sequence;
		Py_DECREF(Py_NotImplemented);
		if (m && m->sq_concat) {
			result = (*m->sq_concat)(v, w);
		}
                else {
                    PyErr_SetString(PyExc_TypeError,
                                    abstract_add_operands);
                    result = NULL;
                }
	}
	return result;
}

PyObject *
PyNumber_Remainder(PyObject *v, PyObject *w)
{
	if (PyString_Check(v))
		return PyString_Format(v, w);
	else if (PyUnicode_Check(v))
		return PyUnicode_Format(v, w);
	return binary_op(v, w, NB_SLOT(nb_remainder), "%");
}

PyObject *
PyNumber_Power(PyObject *v, PyObject *w, PyObject *z)
{
	return ternary_op(v, w, z, NB_SLOT(nb_power), abstract_power_operator);
}

/* Binary in-place operators */

/* The in-place operators are defined to fall back to the 'normal',
   non in-place operations, if the in-place methods are not in place.

   - If the left hand object has the appropriate struct members, and
     they are filled, call the appropriate function and return the
     result.  No coercion is done on the arguments; the left-hand object
     is the one the operation is performed on, and it's up to the
     function to deal with the right-hand object.
     
   - Otherwise, in-place modification is not supported. Handle it exactly as
     a non in-place operation of the same kind.

   */

#define HASINPLACE(t) PyType_HasFeature((t)->ob_type, Py_TPFLAGS_HAVE_INPLACEOPS)

static inline PyObject *
binary_iop(PyObject *v, PyObject *w, const int iop_slot, const int op_slot,
		const char *op_name)
{
	PyNumberMethods *mv = v->ob_type->tp_as_number;
	if (mv != NULL && HASINPLACE(v)) {
		binaryfunc *slot = NB_BINOP(mv, iop_slot);
		if (*slot) {
			PyObject *x = (*slot)(v, w);
			if (x != Py_NotImplemented) {
				return x;
			}
			Py_DECREF(x);
		}
	}
	return binary_op(v, w, op_slot, op_name);
}

#define INPLACE_BINOP(func, iop, op, op_name) \
	PyObject * \
	func(PyObject *v, PyObject *w) { \
		return binary_iop(v, w, NB_SLOT(iop), NB_SLOT(op), op_name); \
	}

INPLACE_BINOP(PyNumber_InPlaceOr, nb_inplace_or, nb_or, "|=")
INPLACE_BINOP(PyNumber_InPlaceXor, nb_inplace_xor, nb_xor, "^=")
INPLACE_BINOP(PyNumber_InPlaceAnd, nb_inplace_and, nb_and, "&=")
INPLACE_BINOP(PyNumber_InPlaceLshift, nb_inplace_lshift, nb_lshift, "<<=")
INPLACE_BINOP(PyNumber_InPlaceRshift, nb_inplace_rshift, nb_rshift, ">>=")
INPLACE_BINOP(PyNumber_InPlaceSubtract, nb_inplace_subtract, nb_subtract, "-=")
INPLACE_BINOP(PyNumber_InPlaceDivide, nb_inplace_divide, nb_divide, "/=")

PyObject *
PyNumber_InPlaceAdd(PyObject *v, PyObject *w)
{
	binaryfunc f = NULL;

	if (v->ob_type->tp_as_sequence != NULL) {
		if (HASINPLACE(v))
			f = v->ob_type->tp_as_sequence->sq_inplace_concat;
		if (f == NULL)
			f = v->ob_type->tp_as_sequence->sq_concat;
		if (f != NULL)
			return (*f)(v, w);
	}
	return binary_iop(v, w, NB_SLOT(nb_inplace_add), NB_SLOT(nb_add), "+=");
}

PyObject *
PyNumber_InPlaceMultiply(PyObject *v, PyObject *w)
{
	PyObject * (*g)(PyObject *, int) = NULL;
	if (HASINPLACE(v) && v->ob_type->tp_as_sequence &&
		(g = v->ob_type->tp_as_sequence->sq_inplace_repeat)) {
		long n;
		if (PyInt_Check(w)) {
			n  = PyInt_AsLong(w);
		}
		else if (PyLong_Check(w)) {
			n = PyLong_AsLong(w);
			if (n == -1 && PyErr_Occurred())
				return NULL;
		}
		else {
			return type_error(abstract_multiply_nonint);
		}
		return (*g)(v, (int)n);
	}
	return binary_iop(v, w, NB_SLOT(nb_inplace_multiply),
				NB_SLOT(nb_multiply), "*=");
}



PyObject *
PyNumber_InPlaceRemainder(PyObject *v, PyObject *w)
{
	if (PyString_Check(v))
		return PyString_Format(v, w);
	else if (PyUnicode_Check(v))
		return PyUnicode_Format(v, w);
	else
		return binary_iop(v, w, NB_SLOT(nb_inplace_remainder),
					NB_SLOT(nb_remainder), "%=");
}


PyObject *
PyNumber_InPlacePower(PyObject *v, PyObject *w, PyObject *z)
{
	if (HASINPLACE(v) && v->ob_type->tp_as_number &&
	    v->ob_type->tp_as_number->nb_inplace_power != NULL) {
		return ternary_op(v, w, z, NB_SLOT(nb_inplace_power), "**=");
	}
	else {
		return ternary_op(v, w, z, NB_SLOT(nb_power), "**=");
	}
}


/* Unary operators and functions */

PyObject *
PyNumber_Negative(PyObject *o)
{
	PyNumberMethods *m;

	if (o == NULL)
		return null_error();
	m = o->ob_type->tp_as_number;
	if (m && m->nb_negative)
		return (*m->nb_negative)(o);

	return type_error(abstract_negative_operand);
}

PyObject *
PyNumber_Positive(PyObject *o)
{
	PyNumberMethods *m;

	if (o == NULL)
		return null_error();
	m = o->ob_type->tp_as_number;
	if (m && m->nb_positive)
		return (*m->nb_positive)(o);

	return type_error(abstract_positive_operand);
}

PyObject *
PyNumber_Invert(PyObject *o)
{
	PyNumberMethods *m;

	if (o == NULL)
		return null_error();
	m = o->ob_type->tp_as_number;
	if (m && m->nb_invert)
		return (*m->nb_invert)(o);

	return type_error(abstract_invert_operand);
}

PyObject *
PyNumber_Absolute(PyObject *o)
{
	PyNumberMethods *m;

	if (o == NULL)
		return null_error();
	m = o->ob_type->tp_as_number;
	if (m && m->nb_absolute)
		return m->nb_absolute(o);

	return type_error(abstract_abs_operand);
}

/* Add a check for embedded NULL-bytes in the argument. */
static inline PyObject *
int_from_string(const char *s, int len)
{
	char *end;
	PyObject *x;

	x = PyInt_FromString((char*)s, &end, 10);
	if (x == NULL)
		return NULL;
	if (end != s + len) {
		PyErr_SetString(PyExc_ValueError,
				abstract_int_null_byte);
		Py_DECREF(x);
		return NULL;
	}
	return x;
}

PyObject *
PyNumber_Int(PyObject *o)
{
	PyNumberMethods *m;
	const char *buffer;
	int buffer_len;

	if (o == NULL)
		return null_error();
	if (PyInt_Check(o)) {
		Py_INCREF(o);
		return o;
	}
	if (PyString_Check(o))
		return int_from_string(PyString_AS_STRING(o), 
				       PyString_GET_SIZE(o));
	if (PyUnicode_Check(o))
		return PyInt_FromUnicode(PyUnicode_AS_UNICODE(o),
					 PyUnicode_GET_SIZE(o),
					 10);
	m = o->ob_type->tp_as_number;
	if (m && m->nb_int)
		return m->nb_int(o);
	if (!PyObject_AsCharBuffer(o, &buffer, &buffer_len))
		return int_from_string((char*)buffer, buffer_len);

	return type_error(abstract_no_int_conversion);
}

/* Add a check for embedded NULL-bytes in the argument. */
static inline PyObject *
long_from_string(const char *s, int len)
{
	char *end;
	PyObject *x;

	x = PyLong_FromString((char*)s, &end, 10);
	if (x == NULL)
		return NULL;
	if (end != s + len) {
		PyErr_SetString(PyExc_ValueError,
				abstract_long_null_byte);
		Py_DECREF(x);
		return NULL;
	}
	return x;
}

PyObject *
PyNumber_Long(PyObject *o)
{
	PyNumberMethods *m;
	const char *buffer;
	int buffer_len;

	if (o == NULL)
		return null_error();
	if (PyLong_Check(o)) {
		Py_INCREF(o);
		return o;
	}
	if (PyString_Check(o))
		/* need to do extra error checking that PyLong_FromString() 
		 * doesn't do.  In particular long('9.5') must raise an
		 * exception, not truncate the float.
		 */
		return long_from_string(PyString_AS_STRING(o),
					PyString_GET_SIZE(o));
	if (PyUnicode_Check(o))
		/* The above check is done in PyLong_FromUnicode(). */
		return PyLong_FromUnicode(PyUnicode_AS_UNICODE(o),
					  PyUnicode_GET_SIZE(o),
					  10);
	m = o->ob_type->tp_as_number;
	if (m && m->nb_long)
		return m->nb_long(o);
	if (!PyObject_AsCharBuffer(o, &buffer, &buffer_len))
		return long_from_string(buffer, buffer_len);

	return type_error(abstract_no_long_conversion);
}

PyObject *
PyNumber_Float(PyObject *o)
{
	PyNumberMethods *m;

	if (o == NULL)
		return null_error();
	if (PyFloat_Check(o)) {
		Py_INCREF(o);
		return o;
	}
	if (!PyString_Check(o)) {
		m = o->ob_type->tp_as_number;
		if (m && m->nb_float)
			return m->nb_float(o);
	}
	return PyFloat_FromString(o, NULL);
}

/* Operations on sequences */

int
PySequence_Check(PyObject *s)
{
	return s != NULL && s->ob_type->tp_as_sequence;
}

int
PySequence_Size(PyObject *s)
{
	PySequenceMethods *m;

	if (s == NULL) {
		null_error();
		return -1;
	}

	m = s->ob_type->tp_as_sequence;
	if (m && m->sq_length)
		return m->sq_length(s);

	type_error(abstract_unsized_object);
	return -1;
}

#undef PySequence_Length
#define PySequence_Length PySequence_Size





PyObject *
PySequence_GetItem(PyObject *s, int i)
{
	PySequenceMethods *m;

	if (s == NULL)
		return null_error();

	m = s->ob_type->tp_as_sequence;
	if (m && m->sq_item) {
		if (i < 0) {
			if (m->sq_length) {
				int l = (*m->sq_length)(s);
				if (l < 0)
					return NULL;
				i += l;
			}
		}
		return m->sq_item(s, i);
	}

	return type_error(abstract_unindexable);
}

static inline PyObject *
sliceobj_from_intint(int i, int j)
{
	PyObject *start, *end, *slice;
	start = PyInt_FromLong((long)i);
	if (!start)
		return NULL;
	end = PyInt_FromLong((long)j);
	if (!end) {
		Py_DECREF(start);
		return NULL;
	}
	slice = PySlice_New(start, end, NULL);
	Py_DECREF(start);
	Py_DECREF(end);
	return slice;
}

PyObject *
PySequence_GetSlice(PyObject *s, int i1, int i2)
{
	PySequenceMethods *m;
	PyMappingMethods *mp;

	if (!s) return null_error();

	m = s->ob_type->tp_as_sequence;
	if (m && m->sq_slice) {
		if (i1 < 0 || i2 < 0) {
			if (m->sq_length) {
				int l = (*m->sq_length)(s);
				if (l < 0)
					return NULL;
				if (i1 < 0)
					i1 += l;
				if (i2 < 0)
					i2 += l;
			}
		}
		return m->sq_slice(s, i1, i2);
	} else if ((mp = s->ob_type->tp_as_mapping) && mp->mp_subscript) {
		PyObject *res;
		PyObject *slice = sliceobj_from_intint(i1, i2);
		if (!slice)
			return NULL;
		res = mp->mp_subscript(s, slice);
		Py_DECREF(slice);
		return res;
	}

	return type_error(abstract_unsliceable);
}

static inline int
PySequence_SetItem(PyObject *s, int i, PyObject *o)
{
	PySequenceMethods *m;

	if (s == NULL) {
		null_error();
		return -1;
	}

	m = s->ob_type->tp_as_sequence;
	if (m && m->sq_ass_item) {
		if (i < 0) {
			if (m->sq_length) {
				int l = (*m->sq_length)(s);
				if (l < 0)
					return -1;
				i += l;
			}
		}
		return m->sq_ass_item(s, i, o);
	}

	type_error(abstract_no_assignment);
	return -1;
}

int
PySequence_DelItem(PyObject *s, int i)
{
	PySequenceMethods *m;

	if (s == NULL) {
		null_error();
		return -1;
	}

	m = s->ob_type->tp_as_sequence;
	if (m && m->sq_ass_item) {
		if (i < 0) {
			if (m->sq_length) {
				int l = (*m->sq_length)(s);
				if (l < 0)
					return -1;
				i += l;
			}
		}
		return m->sq_ass_item(s, i, (PyObject *)NULL);
	}

	type_error(abstract_no_item_deletion);
	return -1;
}

int
PySequence_SetSlice(PyObject *s, int i1, int i2, PyObject *o)
{
	PySequenceMethods *m;
	PyMappingMethods *mp;

	if (s == NULL) {
		null_error();
		return -1;
	}

	m = s->ob_type->tp_as_sequence;
	if (m && m->sq_ass_slice) {
		if (i1 < 0 || i2 < 0) {
			if (m->sq_length) {
				int l = (*m->sq_length)(s);
				if (l < 0)
					return -1;
				if (i1 < 0)
					i1 += l;
				if (i2 < 0)
					i2 += l;
			}
		}
		return m->sq_ass_slice(s, i1, i2, o);
	} else if ((mp = s->ob_type->tp_as_mapping) && mp->mp_ass_subscript) {
		int res;
		PyObject *slice = sliceobj_from_intint(i1, i2);
		if (!slice)
			return -1;
		res = mp->mp_ass_subscript(s, slice, o);
		Py_DECREF(slice);
		return res;
	}

	type_error(abstract_no_slice_assignment);
	return -1;
}

int
PySequence_DelSlice(PyObject *s, int i1, int i2)
{
	PySequenceMethods *m;

	if (s == NULL) {
		null_error();
		return -1;
	}

	m = s->ob_type->tp_as_sequence;
	if (m && m->sq_ass_slice) {
		if (i1 < 0 || i2 < 0) {
			if (m->sq_length) {
				int l = (*m->sq_length)(s);
				if (l < 0)
					return -1;
				if (i1 < 0)
					i1 += l;
				if (i2 < 0)
					i2 += l;
			}
		}
		return m->sq_ass_slice(s, i1, i2, (PyObject *)NULL);
	}
	type_error(abstract_no_slice_deletion);
	return -1;
}

PyObject *
PySequence_Tuple(PyObject *v)
{
	PySequenceMethods *m;

	if (v == NULL)
		return null_error();

	if (PyTuple_Check(v)) {
		Py_INCREF(v);
		return v;
	}

	if (PyList_Check(v))
		return PyList_AsTuple(v);

	/* There used to be code for strings here, but tuplifying strings is
	   not a common activity, so I nuked it.  Down with code bloat! */

	/* Generic sequence object */
	m = v->ob_type->tp_as_sequence;
	if (m && m->sq_item) {
		int i;
		PyObject *t;
		int n = PySequence_Size(v);
		if (n < 0)
			return NULL;
		t = PyTuple_New(n);
		if (t == NULL)
			return NULL;
		for (i = 0; ; i++) {
			PyObject *item = (*m->sq_item)(v, i);
			if (item == NULL) {
				if (PyErr_ExceptionMatches(PyExc_IndexError))
					PyErr_Clear();
				else {
					Py_DECREF(t);
					t = NULL;
				}
				break;
			}
			if (i >= n) {
				if (n < 500)
					n += 10;
				else
					n += 100;
				if (_PyTuple_Resize(&t, n, 0) != 0)
					break;
			}
			PyTuple_SET_ITEM(t, i, item);
		}
		if (i < n && t != NULL)
			_PyTuple_Resize(&t, i, 0);
		return t;
	}

	/* None of the above */
	return type_error(abstract_tuple_sequence);
}

PyObject *
PySequence_List(PyObject *v)
{
	PySequenceMethods *m;

	if (v == NULL)
		return null_error();

	if (PyList_Check(v))
		return PyList_GetSlice(v, 0, PyList_GET_SIZE(v));

	m = v->ob_type->tp_as_sequence;
	if (m && m->sq_item) {
		int i;
		PyObject *l;
		int n = PySequence_Size(v);
		if (n < 0)
			return NULL;
		l = PyList_New(n);
		if (l == NULL)
			return NULL;
		for (i = 0; ; i++) {
			PyObject *item = (*m->sq_item)(v, i);
			if (item == NULL) {
				if (PyErr_ExceptionMatches(PyExc_IndexError))
					PyErr_Clear();
				else {
					Py_DECREF(l);
					l = NULL;
				}
				break;
			}
			if (i < n)
				PyList_SET_ITEM(l, i, item);
			else if (PyList_Append(l, item) < 0) {
				Py_DECREF(l);
				l = NULL;
				break;
			}
		}
		if (i < n && l != NULL) {
			if (PyList_SetSlice(l, i, n, (PyObject *)NULL) != 0) {
				Py_DECREF(l);
				l = NULL;
			}
		}
		return l;
	}
	return type_error(abstract_list_sequence);
}

PyObject *
PySequence_Fast(PyObject *v, const char *m)
{
	if (v == NULL)
		return null_error();

	if (PyList_Check(v) || PyTuple_Check(v)) {
		Py_INCREF(v);
		return v;
	}

	v = PySequence_Tuple(v);
	if (v == NULL && PyErr_ExceptionMatches(PyExc_TypeError))
		return type_error(m);

	return v;
}


int
PySequence_Contains(PyObject *w, PyObject *v) /* v in w */
{
	int i, cmp;
	PyObject *x;
	PySequenceMethods *sq;

	if(PyType_HasFeature(w->ob_type, Py_TPFLAGS_HAVE_SEQUENCE_IN)) {
		sq = w->ob_type->tp_as_sequence;
	        if(sq != NULL && sq->sq_contains != NULL)
			return (*sq->sq_contains)(w, v);
	}
	
	/* If there is no better way to check whether an item is is contained,
	   do it the hard way */
	sq = w->ob_type->tp_as_sequence;
	if (sq == NULL || sq->sq_item == NULL) {
		PyErr_SetString(PyExc_TypeError,
			abstract_contains_sequence);
		return -1;
	}

	for (i = 0; ; i++) {
		x = (*sq->sq_item)(w, i);
		if (x == NULL) {
			if (PyErr_ExceptionMatches(PyExc_IndexError)) {
				PyErr_Clear();
				break;
			}
			return -1;
		}
		cmp = PyObject_RichCompareBool(v, x, Py_EQ);
		Py_XDECREF(x);
		if (cmp > 0)
			return 1;
		if (cmp < 0)
			return -1;
	}

	return 0;
}

/* Backwards compatibility */
#undef PySequence_In


/* Operations on mappings */


static inline int
PyMapping_Size(PyObject *o)
{
	PyMappingMethods *m;

	if (o == NULL) {
		null_error();
		return -1;
	}

	m = o->ob_type->tp_as_mapping;
	if (m && m->mp_length)
		return m->mp_length(o);

	type_error(abstract_unsized_object);
	return -1;
}

#undef PyMapping_Length
#define PyMapping_Length PyMapping_Size

PyObject *
PyMapping_GetItemString(PyObject *o, char *key)
{
	PyObject *okey, *r;

	if (key == NULL)
		return null_error();

	okey = PyString_FromString(key);
	if (okey == NULL)
		return NULL;
	r = PyObject_GetItem(o, okey);
	Py_DECREF(okey);
	return r;
}

int
PyMapping_SetItemString(PyObject *o, char *key, PyObject *value)
{
	PyObject *okey;
	int r;

	if (key == NULL) {
		null_error();
		return -1;
	}

	okey = PyString_FromString(key);
	if (okey == NULL)
		return -1;
	r = PyObject_SetItem(o, okey, value);
	Py_DECREF(okey);
	return r;
}

int
PyMapping_HasKeyString(PyObject *o, char *key)
{
	PyObject *v;

	v = PyMapping_GetItemString(o, key);
	if (v) {
		Py_DECREF(v);
		return 1;
	}
	PyErr_Clear();
	return 0;
}


/* Operations on callable objects */

/* XXX PyCallable_Check() is in object.c */

PyObject *
PyObject_CallObject(PyObject *o, PyObject *a)
{
	PyObject *r;
	PyObject *args = a;

	if (args == NULL) {
		args = PyTuple_New(0);
		if (args == NULL)
			return NULL;
	}

	r = PyEval_CallObject(o, args);

	if (args != a) {
		Py_DECREF(args);
	}

	return r;
}


/* Recovered target-specific no-argument call helper; original name unknown. */
PyObject *
fn_801308B4(PyObject *callable)
{
    PyObject *args, *retval;
    if (callable == NULL)
        return null_error();
    args = PyTuple_New(0);
    if (args == NULL)
        retval = NULL;
    else {
    retval = PyEval_CallObject(callable, args);
    Py_XDECREF(args);
    }
    return retval;
}

PyObject *
PyObject_CallFunction(PyObject *callable, char *format, ...)
{
	va_list va;
	PyObject *args, *retval;
	va_start(va, format);

	if (callable == NULL) {
		va_end(va);
		return null_error();
	}

	if (format)
		args = Py_VaBuildValue(format, va);
	else
		args = PyTuple_New(0);

	va_end(va);
	
	if (args == NULL)
		return NULL;

	if (!PyTuple_Check(args)) {
		PyObject *a;

		a = PyTuple_New(1);
		if (a == NULL)
			return NULL;
		if (PyTuple_SetItem(a, 0, args) < 0)
			return NULL;
		args = a;
	}
	retval = PyObject_CallObject(callable, args);

	Py_DECREF(args);

	return retval;
}

PyObject *
PyObject_CallMethod(PyObject *o, char *name, char *format, ...)
{
	va_list va;
	PyObject *args, *func = 0, *retval;
	va_start(va, format);

	if (o == NULL || name == NULL) {
		va_end(va);
		return null_error();
	}

	func = PyObject_GetAttrString(o, name);
	if (func == NULL) {
		va_end(va);
		PyErr_SetString(PyExc_AttributeError, name);
		return 0;
	}

	if (!PyCallable_Check(func)) {
		va_end(va);
		return type_error(abstract_noncallable_attribute);
	}

	if (format && *format)
		args = Py_VaBuildValue(format, va);
	else
		args = PyTuple_New(0);

	va_end(va);

	if (!args)
		return NULL;

	if (!PyTuple_Check(args)) {
		PyObject *a;

		a = PyTuple_New(1);
		if (a == NULL)
			return NULL;
		if (PyTuple_SetItem(a, 0, args) < 0)
			return NULL;
		args = a;
	}

	retval = PyObject_CallObject(func, args);

	Py_DECREF(args);
	Py_DECREF(func);

	return retval;
}


/* isinstance(), issubclass() */

static int
abstract_issubclass(PyObject *derived, PyObject *cls, int first)
{
	PyObject *bases;
	int i, n;
	int r = 0;

	if (__bases__ == NULL) {
		__bases__ = PyString_FromString(abstract_bases_attribute);
		if (__bases__ == NULL)
			return -1;
	}

	if (first) {
		bases = PyObject_GetAttr(cls, __bases__);
		if (bases == NULL || !PyTuple_Check(bases)) {
			Py_XDECREF(bases);
			PyErr_SetString(PyExc_TypeError,
					abstract_issubclass_arg2);
			return -1;
		}
		Py_DECREF(bases);
	}

	if (derived == cls)
		return 1;

	bases = PyObject_GetAttr(derived, __bases__);
	if (bases == NULL || !PyTuple_Check(bases)) {
	        Py_XDECREF(bases);
		PyErr_SetString(PyExc_TypeError,
				abstract_issubclass_arg1);
		return -1;
	}

	n = PyTuple_GET_SIZE(bases);
	for (i = 0; i < n; i++) {
		r = abstract_issubclass(PyTuple_GET_ITEM(bases, i), cls, 0);
		if (r != 0)
			break;
	}

	Py_DECREF(bases);

	return r;
}

int
PyObject_IsInstance(PyObject *inst, PyObject *cls)
{
	PyObject *icls;
	int retval = 0;

        if (PyClass_Check(cls)) {
		if (PyInstance_Check(inst)) {
			PyObject *inclass =
				(PyObject*)((PyInstanceObject*)inst)->in_class;
			retval = PyClass_IsSubclass(inclass, cls);
		}
	}
	else if (PyType_Check(cls)) {
		retval = ((PyObject *)(inst->ob_type) == cls);
	}
	else if (!PyInstance_Check(inst)) {
		if (__class__ == NULL) {
			__class__ = PyString_FromString(abstract_class_attribute);
			if (__class__ == NULL)
				return -1;
		}
		icls = PyObject_GetAttr(inst, __class__);
		if (icls != NULL) {
			retval = abstract_issubclass(icls, cls, 1);
			Py_DECREF(icls);
			if (retval < 0 &&
			    !PyErr_ExceptionMatches(PyExc_TypeError))
				return -1;
		}
		else
			retval = -1;
	}
	else
		retval = -1;

	if (retval < 0) {
		PyErr_SetString(PyExc_TypeError,
				abstract_isinstance_class);
	}
	return retval;
}

int
PyObject_IsSubclass(PyObject *derived, PyObject *cls)
{
	int retval;

	if (!PyClass_Check(derived) || !PyClass_Check(cls)) {
		retval = abstract_issubclass(derived, cls, 1);
	}
	else {
		/* shortcut */
	  	if (!(retval = (derived == cls)))
			retval = PyClass_IsSubclass(derived, cls);
	}

	return retval;
}
