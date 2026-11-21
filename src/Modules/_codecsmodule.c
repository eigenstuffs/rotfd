/* Builtin codec bindings in the GSQE78 Python runtime.
 * Derived from CPython 2.1 Modules/_codecsmodule.c and its public headers.
 * Original module copyright: Corporation for National Research Initiatives.
 * License: reference/cpython-2.1/LICENSE.
 * Complete linked text: 0x801A96F4..0x801AB66C.
 */
typedef unsigned int size_t;
typedef unsigned short Py_UNICODE;
typedef struct { unsigned char reserved[80]; } FILE;
typedef struct _object {
 int ob_refcnt; struct _typeobject *ob_type;
} PyObject;
typedef struct {
 int ob_refcnt; struct _typeobject *ob_type; int ob_size;
} PyVarObject;
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
typedef struct _typeobject {
 int ob_refcnt; struct _typeobject *ob_type; int ob_size;
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
} PyTypeObject;
extern PyTypeObject PyType_Type;
extern void (*PyObject_ClearWeakRefs)(PyObject *);
extern PyObject _Py_NoneStruct;
extern PyObject _Py_NotImplementedStruct;
extern int _PyTrash_delete_nesting;
extern PyObject * _PyTrash_delete_later;
typedef struct {
    int ob_refcnt; struct _typeobject *ob_type; int ob_size;
    PyObject *ob_item[1];
} PyTupleObject;
extern PyTypeObject PyTuple_Type;
extern PyObject * PyTuple_New(int size);
typedef struct {
    int ob_refcnt; struct _typeobject *ob_type; int ob_size;
    long ob_shash;
    PyObject *ob_sinterned;
    char ob_sval[1];
} PyStringObject;
extern PyTypeObject PyString_Type;
extern PyObject * PyString_FromStringAndSize(const char *, int);
typedef struct {
    int ob_refcnt; struct _typeobject *ob_type;
    long ob_ival;
} PyIntObject;
extern PyTypeObject PyInt_Type;
extern PyObject * PyInt_FromLong(long);
extern PyIntObject _Py_ZeroStruct, _Py_TrueStruct;
extern PyTypeObject PyCFunction_Type;
typedef PyObject *(*PyCFunction)(PyObject *, PyObject *);
typedef PyObject *(*PyCFunctionWithKeywords)(PyObject *, PyObject *,
          PyObject *);
struct PyMethodDef {
    char *ml_name;
    PyCFunction ml_meth;
    int ml_flags;
    char *ml_doc;
};
typedef struct PyMethodDef PyMethodDef;
typedef struct PyMethodChain {
    PyMethodDef *methods;
    struct PyMethodChain *link;
} PyMethodChain;
typedef struct {
    int ob_refcnt; struct _typeobject *ob_type;
    PyMethodDef *m_ml;
    PyObject *m_self;
} PyCFunctionObject;
extern PyTypeObject PyModule_Type;
extern PyObject * PyExc_Exception;
extern PyObject * PyExc_StandardError;
extern PyObject * PyExc_ArithmeticError;
extern PyObject * PyExc_LookupError;
extern PyObject * PyExc_AssertionError;
extern PyObject * PyExc_AttributeError;
extern PyObject * PyExc_EOFError;
extern PyObject * PyExc_FloatingPointError;
extern PyObject * PyExc_EnvironmentError;
extern PyObject * PyExc_IOError;
extern PyObject * PyExc_OSError;
extern PyObject * PyExc_ImportError;
extern PyObject * PyExc_IndexError;
extern PyObject * PyExc_KeyError;
extern PyObject * PyExc_KeyboardInterrupt;
extern PyObject * PyExc_MemoryError;
extern PyObject * PyExc_NameError;
extern PyObject * PyExc_OverflowError;
extern PyObject * PyExc_RuntimeError;
extern PyObject * PyExc_NotImplementedError;
extern PyObject * PyExc_SyntaxError;
extern PyObject * PyExc_IndentationError;
extern PyObject * PyExc_TabError;
extern PyObject * PyExc_SystemError;
extern PyObject * PyExc_SystemExit;
extern PyObject * PyExc_TypeError;
extern PyObject * PyExc_UnboundLocalError;
extern PyObject * PyExc_UnicodeError;
extern PyObject * PyExc_ValueError;
extern PyObject * PyExc_ZeroDivisionError;
extern PyObject * PyExc_MemoryErrorInst;
extern PyObject * PyExc_Warning;
extern PyObject * PyExc_UserWarning;
extern PyObject * PyExc_DeprecationWarning;
extern PyObject * PyExc_SyntaxWarning;
extern PyObject * PyExc_RuntimeWarning;
     int PyObject_AsReadBuffer(PyObject *obj,
       const void **buffer,
       int *buffer_len);
extern int PyCodec_Register(
       PyObject *search_function
       );
extern PyObject * _PyCodec_Lookup(
       const char *encoding
       );
typedef struct {
    int ob_refcnt; struct _typeobject *ob_type;
    int length;
    Py_UNICODE *str;
    long hash;
    PyObject *defenc;
} PyUnicodeObject;
extern PyTypeObject PyUnicode_Type;
extern PyObject* PyUnicode_FromUnicode(
    const Py_UNICODE *u,
    int size
    );
extern PyObject* PyUnicode_FromObject(
    register PyObject *obj
    );
extern PyObject* PyUnicode_DecodeUTF8(
    const char *string,
    int length,
    const char *errors
    );
extern PyObject* PyUnicode_EncodeUTF8(
    const Py_UNICODE *data,
    int length,
    const char *errors
    );
extern PyObject* PyUnicode_DecodeUTF16(
    const char *string,
    int length,
    const char *errors,
    int *byteorder
    );
extern PyObject* PyUnicode_EncodeUTF16(
    const Py_UNICODE *data,
    int length,
    const char *errors,
    int byteorder
    );
extern PyObject* PyUnicode_DecodeUnicodeEscape(
    const char *string,
    int length,
    const char *errors
    );
extern PyObject* PyUnicode_EncodeUnicodeEscape(
    const Py_UNICODE *data,
    int length
    );
extern PyObject* PyUnicode_DecodeRawUnicodeEscape(
    const char *string,
    int length,
    const char *errors
    );
extern PyObject* PyUnicode_EncodeRawUnicodeEscape(
    const Py_UNICODE *data,
    int length
    );
extern PyObject* PyUnicode_DecodeLatin1(
    const char *string,
    int length,
    const char *errors
    );
extern PyObject* PyUnicode_EncodeLatin1(
    const Py_UNICODE *data,
    int length,
    const char *errors
    );
extern PyObject* PyUnicode_DecodeASCII(
    const char *string,
    int length,
    const char *errors
    );
extern PyObject* PyUnicode_EncodeASCII(
    const Py_UNICODE *data,
    int length,
    const char *errors
    );
extern PyObject* PyUnicode_DecodeCharmap(
    const char *string,
    int length,
    PyObject *mapping,
    const char *errors
    );
extern PyObject* PyUnicode_EncodeCharmap(
    const Py_UNICODE *data,
    int length,
    PyObject *mapping,
    const char *errors
    );
extern int PyArg_ParseTuple(PyObject *, char *, ...);
extern PyObject *Py_InitModule4(char *, PyMethodDef *, char *, PyObject *, int);
extern PyObject *Py_BuildValue(char *, ...);

#define DL_EXPORT(t) t
#define NULL 0
#define PyTuple_SET_ITEM(op,i,v) (((PyTupleObject *)(op))->ob_item[i] = v)
#define PyUnicode_AS_DATA(op) ((const char *)((PyUnicodeObject *)(op))->str)
#define PyUnicode_AS_UNICODE(op) (((PyUnicodeObject *)(op))->str)
#define PyUnicode_Check(op) (((op)->ob_type == &PyUnicode_Type))
#define PyUnicode_GET_DATA_SIZE(op) (((PyUnicodeObject *)(op))->length * sizeof(Py_UNICODE))
#define PyUnicode_GET_SIZE(op) (((PyUnicodeObject *)(op))->length)
#define Py_DECREF(op) if (--(op)->ob_refcnt != 0) ; else _Py_Dealloc((PyObject *)(op))
#define Py_INCREF(op) ((op)->ob_refcnt++)
#define Py_InitModule(name,methods) Py_InitModule4((name),(methods),(char *)NULL,(PyObject *)NULL,1010)
#define Py_None (&_Py_NoneStruct)
#define _Py_Dealloc(op) (*(op)->ob_type->tp_dealloc)((PyObject *)(op))
/* ------------------------------------------------------------------------

   _codecs -- Provides access to the codec registry and the builtin
              codecs.

   This module should never be imported directly. The standard library
   module "codecs" wraps this builtin module for use within Python.

   The codec registry is accessible via:

     register(search_function) -> None

     lookup(encoding) -> (encoder, decoder, stream_reader, stream_writer)

   The builtin Unicode codecs use the following interface:

     <encoding>_encode(Unicode_object[,errors='strict']) -> 
     	(string object, bytes consumed)

     <encoding>_decode(char_buffer_obj[,errors='strict']) -> 
        (Unicode object, bytes consumed)

   <encoding>_encode() interfaces also accept non-Unicode object as
   input. The objects are then converted to Unicode using
   PyUnicode_FromObject() prior to applying the conversion.

   These <encoding>s are available: utf_8, unicode_escape,
   raw_unicode_escape, unicode_internal, latin_1, ascii (7-bit),
   mbcs (on win32).


Written by Marc-Andre Lemburg (mal@lemburg.com).

Copyright (c) Corporation for National Research Initiatives.

   ------------------------------------------------------------------------ */



/* --- Registry ----------------------------------------------------------- */

static
PyObject *codecregister(PyObject *self, PyObject *args)
{
    PyObject *search_function;

    if (!PyArg_ParseTuple(args, "O:register", &search_function))
        goto onError;

    if (PyCodec_Register(search_function))
	goto onError;
    
    Py_INCREF(Py_None);
    return Py_None;

 onError:
    return NULL;
}

static
PyObject *codeclookup(PyObject *self, PyObject *args)
{
    char *encoding;

    if (!PyArg_ParseTuple(args, "s:lookup", &encoding))
        goto onError;

    return _PyCodec_Lookup(encoding);

 onError:
    return NULL;
}

/* --- Helpers ------------------------------------------------------------ */

static inline
PyObject *codec_tuple(PyObject *unicode,
		      int len)
{
    PyObject *v,*w;
    
    if (unicode == NULL)
	return NULL;
    v = PyTuple_New(2);
    if (v == NULL) {
	Py_DECREF(unicode);
	return NULL;
    }
    PyTuple_SET_ITEM(v,0,unicode);
    w = PyInt_FromLong(len);
    if (w == NULL) {
	Py_DECREF(v);
	return NULL;
    }
    PyTuple_SET_ITEM(v,1,w);
    return v;
}

/* --- Decoder ------------------------------------------------------------ */

static PyObject *
unicode_internal_decode(PyObject *self,
			PyObject *args)
{
    PyObject *obj;
    const char *errors = NULL;
    const char *data;
    int size;
    
    if (!PyArg_ParseTuple(args, "O|z:unicode_internal_decode",
			  &obj, &errors))
	return NULL;

    if (PyUnicode_Check(obj))
	return codec_tuple(obj, PyUnicode_GET_SIZE(obj));
    else {
	if (PyObject_AsReadBuffer(obj, (const void **)&data, &size))
	    return NULL;
	return codec_tuple(PyUnicode_FromUnicode((Py_UNICODE *)data,
						 size / sizeof(Py_UNICODE)),
			   size);
    }
}

static PyObject *
utf_8_decode(PyObject *self,
	    PyObject *args)
{
    const char *data;
    int size;
    const char *errors = NULL;
    
    if (!PyArg_ParseTuple(args, "t#|z:utf_8_decode",
			  &data, &size, &errors))
	return NULL;

    return codec_tuple(PyUnicode_DecodeUTF8(data, size, errors),
		       size);
}

static PyObject *
utf_16_decode(PyObject *self,
	    PyObject *args)
{
    const char *data;
    int size;
    const char *errors = NULL;
    int byteorder = 0;
    
    if (!PyArg_ParseTuple(args, "t#|z:utf_16_decode",
			  &data, &size, &errors))
	return NULL;
    return codec_tuple(PyUnicode_DecodeUTF16(data, size, errors, &byteorder),
		       size);
}

static PyObject *
utf_16_le_decode(PyObject *self,
		 PyObject *args)
{
    const char *data;
    int size;
    const char *errors = NULL;
    int byteorder = -1;
    
    if (!PyArg_ParseTuple(args, "t#|z:utf_16_le_decode",
			  &data, &size, &errors))
	return NULL;
    return codec_tuple(PyUnicode_DecodeUTF16(data, size, errors, &byteorder),
		       size);
}

static PyObject *
utf_16_be_decode(PyObject *self,
		 PyObject *args)
{
    const char *data;
    int size;
    const char *errors = NULL;
    int byteorder = 1;
    
    if (!PyArg_ParseTuple(args, "t#|z:utf_16_be_decode",
			  &data, &size, &errors))
	return NULL;
    return codec_tuple(PyUnicode_DecodeUTF16(data, size, errors, &byteorder),
		       size);
}

/* This non-standard version also provides access to the byteorder
   parameter of the builtin UTF-16 codec.

   It returns a tuple (unicode, bytesread, byteorder) with byteorder
   being the value in effect at the end of data.

*/

static PyObject *
utf_16_ex_decode(PyObject *self,
		 PyObject *args)
{
    const char *data;
    int size;
    const char *errors = NULL;
    int byteorder = 0;
    PyObject *unicode, *tuple;
    
    if (!PyArg_ParseTuple(args, "t#|zi:utf_16_ex_decode",
			  &data, &size, &errors, &byteorder))
	return NULL;

    unicode = PyUnicode_DecodeUTF16(data, size, errors, &byteorder);
    if (unicode == NULL)
	return NULL;
    tuple = Py_BuildValue("Oii", unicode, size, byteorder);
    Py_DECREF(unicode);
    return tuple;
}

static PyObject *
unicode_escape_decode(PyObject *self,
		     PyObject *args)
{
    const char *data;
    int size;
    const char *errors = NULL;
    
    if (!PyArg_ParseTuple(args, "t#|z:unicode_escape_decode",
			  &data, &size, &errors))
	return NULL;

    return codec_tuple(PyUnicode_DecodeUnicodeEscape(data, size, errors),
		       size);
}

static PyObject *
raw_unicode_escape_decode(PyObject *self,
			PyObject *args)
{
    const char *data;
    int size;
    const char *errors = NULL;
    
    if (!PyArg_ParseTuple(args, "t#|z:raw_unicode_escape_decode",
			  &data, &size, &errors))
	return NULL;

    return codec_tuple(PyUnicode_DecodeRawUnicodeEscape(data, size, errors),
		       size);
}

static PyObject *
latin_1_decode(PyObject *self,
	       PyObject *args)
{
    const char *data;
    int size;
    const char *errors = NULL;
    
    if (!PyArg_ParseTuple(args, "t#|z:latin_1_decode",
			  &data, &size, &errors))
	return NULL;

    return codec_tuple(PyUnicode_DecodeLatin1(data, size, errors),
		       size);
}

static PyObject *
ascii_decode(PyObject *self,
	     PyObject *args)
{
    const char *data;
    int size;
    const char *errors = NULL;
    
    if (!PyArg_ParseTuple(args, "t#|z:ascii_decode",
			  &data, &size, &errors))
	return NULL;

    return codec_tuple(PyUnicode_DecodeASCII(data, size, errors),
		       size);
}

static PyObject *
charmap_decode(PyObject *self,
	       PyObject *args)
{
    const char *data;
    int size;
    const char *errors = NULL;
    PyObject *mapping = NULL;
    
    if (!PyArg_ParseTuple(args, "t#|zO:charmap_decode",
			  &data, &size, &errors, &mapping))
	return NULL;
    if (mapping == Py_None)
	mapping = NULL;

    return codec_tuple(PyUnicode_DecodeCharmap(data, size, mapping, errors),
		       size);
}

#ifdef MS_WIN32

static PyObject *
mbcs_decode(PyObject *self,
	    PyObject *args)
{
    const char *data;
    int size;
    const char *errors = NULL;
    
    if (!PyArg_ParseTuple(args, "t#|z:mbcs_decode",
			  &data, &size, &errors))
	return NULL;

    return codec_tuple(PyUnicode_DecodeMBCS(data, size, errors),
		       size);
}

#endif /* MS_WIN32 */

/* --- Encoder ------------------------------------------------------------ */

static PyObject *
readbuffer_encode(PyObject *self,
		  PyObject *args)
{
    const char *data;
    int size;
    const char *errors = NULL;

    if (!PyArg_ParseTuple(args, "s#|z:readbuffer_encode",
			  &data, &size, &errors))
	return NULL;

    return codec_tuple(PyString_FromStringAndSize(data, size),
		       size);
}

static PyObject *
charbuffer_encode(PyObject *self,
		  PyObject *args)
{
    const char *data;
    int size;
    const char *errors = NULL;

    if (!PyArg_ParseTuple(args, "t#|z:charbuffer_encode",
			  &data, &size, &errors))
	return NULL;

    return codec_tuple(PyString_FromStringAndSize(data, size),
		       size);
}

static PyObject *
unicode_internal_encode(PyObject *self,
			PyObject *args)
{
    PyObject *obj;
    const char *errors = NULL;
    const char *data;
    int size;
    
    if (!PyArg_ParseTuple(args, "O|z:unicode_internal_encode",
			  &obj, &errors))
	return NULL;

    if (PyUnicode_Check(obj)) {
	data = PyUnicode_AS_DATA(obj);
	size = PyUnicode_GET_DATA_SIZE(obj);
	return codec_tuple(PyString_FromStringAndSize(data, size),
			   size);
    }
    else {
	if (PyObject_AsReadBuffer(obj, (const void **)&data, &size))
	    return NULL;
	return codec_tuple(PyString_FromStringAndSize(data, size),
			   size);
    }
}

static PyObject *
utf_8_encode(PyObject *self,
	    PyObject *args)
{
    PyObject *str, *v;
    const char *errors = NULL;

    if (!PyArg_ParseTuple(args, "O|z:utf_8_encode",
			  &str, &errors))
	return NULL;

    str = PyUnicode_FromObject(str);
    if (str == NULL)
	return NULL;
    v = codec_tuple(PyUnicode_EncodeUTF8(PyUnicode_AS_UNICODE(str),
					 PyUnicode_GET_SIZE(str),
					 errors),
		    PyUnicode_GET_SIZE(str));
    Py_DECREF(str);
    return v;
}

/* This version provides access to the byteorder parameter of the
   builtin UTF-16 codecs as optional third argument. It defaults to 0
   which means: use the native byte order and prepend the data with a
   BOM mark.  

*/

static PyObject *
utf_16_encode(PyObject *self,
	    PyObject *args)
{
    PyObject *str, *v;
    const char *errors = NULL;
    int byteorder = 0;

    if (!PyArg_ParseTuple(args, "O|zi:utf_16_encode",
			  &str, &errors, &byteorder))
	return NULL;

    str = PyUnicode_FromObject(str);
    if (str == NULL)
	return NULL;
    v = codec_tuple(PyUnicode_EncodeUTF16(PyUnicode_AS_UNICODE(str),
					  PyUnicode_GET_SIZE(str),
					  errors,
					  byteorder),
		    PyUnicode_GET_SIZE(str));
    Py_DECREF(str);
    return v;
}

static PyObject *
utf_16_le_encode(PyObject *self,
		 PyObject *args)
{
    PyObject *str, *v;
    const char *errors = NULL;

    if (!PyArg_ParseTuple(args, "O|zi:utf_16_le_encode",
			  &str, &errors))
	return NULL;

    str = PyUnicode_FromObject(str);
    if (str == NULL)
	return NULL;
    v = codec_tuple(PyUnicode_EncodeUTF16(PyUnicode_AS_UNICODE(str),
					     PyUnicode_GET_SIZE(str),
					     errors,
					     -1),
		       PyUnicode_GET_SIZE(str));
    Py_DECREF(str);
    return v;
}

static PyObject *
utf_16_be_encode(PyObject *self,
		 PyObject *args)
{
    PyObject *str, *v;
    const char *errors = NULL;

    if (!PyArg_ParseTuple(args, "O|zi:utf_16_be_encode",
			  &str, &errors))
	return NULL;

    str = PyUnicode_FromObject(str);
    if (str == NULL)
	return NULL;
    v = codec_tuple(PyUnicode_EncodeUTF16(PyUnicode_AS_UNICODE(str),
					  PyUnicode_GET_SIZE(str),
					  errors,
					  +1),
		    PyUnicode_GET_SIZE(str));
    Py_DECREF(str);
    return v;
}

static PyObject *
unicode_escape_encode(PyObject *self,
		     PyObject *args)
{
    PyObject *str, *v;
    const char *errors = NULL;

    if (!PyArg_ParseTuple(args, "O|z:unicode_escape_encode",
			  &str, &errors))
	return NULL;

    str = PyUnicode_FromObject(str);
    if (str == NULL)
	return NULL;
    v = codec_tuple(PyUnicode_EncodeUnicodeEscape(PyUnicode_AS_UNICODE(str), 
						  PyUnicode_GET_SIZE(str)),
		    PyUnicode_GET_SIZE(str));
    Py_DECREF(str);
    return v;
}

static PyObject *
raw_unicode_escape_encode(PyObject *self,
			PyObject *args)
{
    PyObject *str, *v;
    const char *errors = NULL;

    if (!PyArg_ParseTuple(args, "O|z:raw_unicode_escape_encode",
			  &str, &errors))
	return NULL;

    str = PyUnicode_FromObject(str);
    if (str == NULL)
	return NULL;
    v = codec_tuple(PyUnicode_EncodeRawUnicodeEscape(
			       PyUnicode_AS_UNICODE(str), 
			       PyUnicode_GET_SIZE(str)),
		    PyUnicode_GET_SIZE(str));
    Py_DECREF(str);
    return v;
}

static PyObject *
latin_1_encode(PyObject *self,
	       PyObject *args)
{
    PyObject *str, *v;
    const char *errors = NULL;

    if (!PyArg_ParseTuple(args, "O|z:latin_1_encode",
			  &str, &errors))
	return NULL;

    str = PyUnicode_FromObject(str);
    if (str == NULL)
	return NULL;
    v = codec_tuple(PyUnicode_EncodeLatin1(
			       PyUnicode_AS_UNICODE(str), 
			       PyUnicode_GET_SIZE(str),
			       errors),
		    PyUnicode_GET_SIZE(str));
    Py_DECREF(str);
    return v;
}

static PyObject *
ascii_encode(PyObject *self,
	     PyObject *args)
{
    PyObject *str, *v;
    const char *errors = NULL;

    if (!PyArg_ParseTuple(args, "O|z:ascii_encode",
			  &str, &errors))
	return NULL;

    str = PyUnicode_FromObject(str);
    if (str == NULL)
	return NULL;
    v = codec_tuple(PyUnicode_EncodeASCII(
			       PyUnicode_AS_UNICODE(str), 
			       PyUnicode_GET_SIZE(str),
			       errors),
		    PyUnicode_GET_SIZE(str));
    Py_DECREF(str);
    return v;
}

static PyObject *
charmap_encode(PyObject *self,
	     PyObject *args)
{
    PyObject *str, *v;
    const char *errors = NULL;
    PyObject *mapping = NULL;

    if (!PyArg_ParseTuple(args, "O|zO:charmap_encode",
			  &str, &errors, &mapping))
	return NULL;
    if (mapping == Py_None)
	mapping = NULL;

    str = PyUnicode_FromObject(str);
    if (str == NULL)
	return NULL;
    v = codec_tuple(PyUnicode_EncodeCharmap(
			       PyUnicode_AS_UNICODE(str), 
			       PyUnicode_GET_SIZE(str),
			       mapping, 
			       errors),
		    PyUnicode_GET_SIZE(str));
    Py_DECREF(str);
    return v;
}

#ifdef MS_WIN32

static PyObject *
mbcs_encode(PyObject *self,
	    PyObject *args)
{
    PyObject *str, *v;
    const char *errors = NULL;

    if (!PyArg_ParseTuple(args, "O|z:mbcs_encode",
			  &str, &errors))
	return NULL;

    str = PyUnicode_FromObject(str);
    if (str == NULL)
	return NULL;
    v = codec_tuple(PyUnicode_EncodeMBCS(
			       PyUnicode_AS_UNICODE(str), 
			       PyUnicode_GET_SIZE(str),
			       errors),
		    PyUnicode_GET_SIZE(str));
    Py_DECREF(str);
    return v;
}

#endif /* MS_WIN32 */

/* --- Module API --------------------------------------------------------- */

static PyMethodDef _codecs_functions[] = {
    {"register",		codecregister,			1},
    {"lookup",			codeclookup, 			1},
    {"utf_8_encode",		utf_8_encode,			1},
    {"utf_8_decode",		utf_8_decode,			1},
    {"utf_16_encode",		utf_16_encode,			1},
    {"utf_16_le_encode",	utf_16_le_encode,		1},
    {"utf_16_be_encode",	utf_16_be_encode,		1},
    {"utf_16_decode",		utf_16_decode,			1},
    {"utf_16_le_decode",	utf_16_le_decode,		1},
    {"utf_16_be_decode",	utf_16_be_decode,		1},
    {"utf_16_ex_decode",	utf_16_ex_decode,		1},
    {"unicode_escape_encode",	unicode_escape_encode,		1},
    {"unicode_escape_decode",	unicode_escape_decode,		1},
    {"unicode_internal_encode",	unicode_internal_encode,	1},
    {"unicode_internal_decode",	unicode_internal_decode,	1},
    {"raw_unicode_escape_encode", raw_unicode_escape_encode,	1},
    {"raw_unicode_escape_decode", raw_unicode_escape_decode,	1},
    {"latin_1_encode", 		latin_1_encode,			1},
    {"latin_1_decode", 		latin_1_decode,			1},
    {"ascii_encode", 		ascii_encode,			1},
    {"ascii_decode", 		ascii_decode,			1},
    {"charmap_encode", 		charmap_encode,			1},
    {"charmap_decode", 		charmap_decode,			1},
    {"readbuffer_encode",	readbuffer_encode,		1},
    {"charbuffer_encode",	charbuffer_encode,		1},
#ifdef MS_WIN32
    {"mbcs_encode", 		mbcs_encode,			1},
    {"mbcs_decode", 		mbcs_decode,			1},
#endif
    {NULL, NULL}		/* sentinel */
};

DL_EXPORT(void)
init_codecs(void)
{
    Py_InitModule("_codecs", _codecs_functions);
}
