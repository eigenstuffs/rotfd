/* Adapted from CPython 2.1, Objects/funcobject.c.
 * Copyright (c) 2001 Python Software Foundation; All Rights Reserved.
 * License: reference/cpython-2.1/LICENSE (retained with the reference source).
 * Changes: self-contained recovered ABI; disabled cyclic-GC macros; indirect
 * weak-reference cleanup; omitted un-emitted getters; original error locations.
 * Original text: 0x801467C8..0x80147184.
 */

typedef struct _typeobject PyTypeObject;
typedef struct _object {
    int ob_refcnt;
    PyTypeObject *ob_type;
} PyObject;

typedef int (*visitproc)(PyObject *, void *);
typedef void (*destructor)(PyObject *);
typedef PyObject *(*getattrfunc)(PyObject *, char *);
typedef int (*setattrfunc)(PyObject *, char *, PyObject *);
typedef PyObject *(*reprfunc)(PyObject *);
struct _typeobject {
    int ob_refcnt;
    PyTypeObject *ob_type;
    int ob_size;
    char *tp_name;
    int tp_basicsize, tp_itemsize;
    destructor tp_dealloc;
    void *tp_print;
    getattrfunc tp_getattr;
    setattrfunc tp_setattr;
    void *tp_compare;
    reprfunc tp_repr;
    void *tp_as_number, *tp_as_sequence, *tp_as_mapping;
    void *tp_hash, *tp_call, *tp_str, *tp_getattro, *tp_setattro;
    void *tp_as_buffer;
    long tp_flags;
    char *tp_doc;
    int (*tp_traverse)(PyObject *, visitproc, void *);
    void *tp_clear, *tp_richcompare;
    long tp_weaklistoffset;
};

#define NULL 0
#define PyObject_HEAD int ob_refcnt; PyTypeObject *ob_type;
#define PyObject_HEAD_INIT(type) 1, type,
#define Py_INCREF(op) ((op)->ob_refcnt++)
#define Py_XINCREF(op) if ((op) == NULL) ; else Py_INCREF(op)
#define Py_DECREF(op) if (--(op)->ob_refcnt != 0) ; else (*(op)->ob_type->tp_dealloc)((PyObject *)(op))
#define Py_XDECREF(op) if ((op) == NULL) ; else Py_DECREF(op)
#define Py_None (&_Py_NoneStruct)
#define PyObject_NEW(type, tp) ((type *)PyObject_Init((PyObject *)malloc((tp)->tp_basicsize), (tp)))
#define PyObject_DEL(op) free(op)
#define PyGC_HEAD_SIZE 0
#define PyObject_GC_Init(op)
#define PyObject_GC_Fini(op)
#define PyObject_AS_GC(op) (op)
#define Py_TPFLAGS_DEFAULT 0x6bL
#define Py_TPFLAGS_GC 0
#define Py_TPFLAGS_HAVE_WEAKREFS (1L << 6)
#define offsetof(type, member) ((int) &((type *)0)->member)
#define T_OBJECT 6
#define READONLY 1
#define PyFunction_Check(op) ((op)->ob_type == &PyFunction_Type)
#define PyTuple_Check(op) ((op)->ob_type == &PyTuple_Type)
#define PyString_Check(op) ((op)->ob_type == &PyString_Type)
#define PyUnicode_Check(op) ((op)->ob_type == &PyUnicode_Type)
#define PyCode_Check(op) ((op)->ob_type == &PyCode_Type)
#define PyDict_Check(op) ((op)->ob_type == &PyDict_Type)

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
typedef struct {
    PyObject_HEAD
    int co_argcount, co_nlocals, co_stacksize, co_flags;
    PyObject *co_code, *co_consts, *co_names, *co_varnames;
    PyObject *co_freevars, *co_cellvars, *co_filename, *co_name;
    int co_firstlineno;
    PyObject *co_lnotab;
} PyCodeObject;
struct memberlist {
    char *name;
    int type;
    int offset;
    int readonly;
};
typedef int (*traverseproc)(PyObject *, visitproc, void *);

extern PyTypeObject PyFunction_Type, PyType_Type, PyTuple_Type;
extern PyTypeObject PyString_Type, PyUnicode_Type, PyCode_Type, PyDict_Type;
extern PyObject _Py_NoneStruct;
extern PyObject *PyExc_RuntimeError, *PyExc_SystemError, *PyExc_TypeError;
extern PyObject *PyExc_AttributeError, *PyExc_KeyError;
extern int strcmp(const char *, const char *);
extern int sprintf(char *, const char *, ...);
extern void *malloc(unsigned int);
extern void free(void *);
extern PyObject *PyObject_Init(PyObject *, PyTypeObject *);
extern char *PyString_AsString(PyObject *);
extern PyObject *PyString_FromString(const char *);
extern int PyTuple_Size(PyObject *);
extern PyObject *PyTuple_GetItem(PyObject *, int);
extern void _PyErr_BadInternalCall(const char *, int);
extern void PyErr_SetString(PyObject *, const char *);
extern void PyErr_SetObject(PyObject *, PyObject *);
extern void PyErr_Clear(void);
extern int PyErr_ExceptionMatches(PyObject *);
extern int PyEval_GetRestricted(void);
extern PyObject *PyMember_Get(char *, struct memberlist *, char *);
extern int PyMember_Set(char *, struct memberlist *, char *, PyObject *);
extern PyObject *PyDict_New(void);
extern PyObject *PyDict_GetItem(PyObject *, PyObject *);
extern int PyDict_SetItem(PyObject *, PyObject *, PyObject *);
extern int PyDict_DelItem(PyObject *, PyObject *);
extern void (*PyObject_ClearWeakRefs)(PyObject *);

PyObject *
PyFunction_New(PyObject *code, PyObject *globals)
{
	PyFunctionObject *op = PyObject_NEW(PyFunctionObject,
					    &PyFunction_Type);
	if (op != NULL) {
		PyObject *doc;
		PyObject *consts;
		op->func_weakreflist = NULL;
		Py_INCREF(code);
		op->func_code = code;
		Py_INCREF(globals);
		op->func_globals = globals;
		op->func_name = ((PyCodeObject *)code)->co_name;
		Py_INCREF(op->func_name);
		op->func_defaults = NULL; /* No default arguments */
		op->func_closure = NULL;
		consts = ((PyCodeObject *)code)->co_consts;
		if (PyTuple_Size(consts) >= 1) {
			doc = PyTuple_GetItem(consts, 0);
			if (!PyString_Check(doc) && !PyUnicode_Check(doc))
				doc = Py_None;
		}
		else
			doc = Py_None;
		Py_INCREF(doc);
		op->func_doc = doc;
		op->func_dict = NULL;
	}
	else
		return NULL;
	PyObject_GC_Init(op);
	return (PyObject *)op;
}

int
PyFunction_SetDefaults(PyObject *op, PyObject *defaults)
{
	if (!PyFunction_Check(op)) {
		_PyErr_BadInternalCall("funcobject.c", 77);
		return -1;
	}
	if (defaults == Py_None)
		defaults = NULL;
	else if (PyTuple_Check(defaults)) {
		Py_XINCREF(defaults);
	}
	else {
		PyErr_SetString(PyExc_SystemError, "non-tuple default args");
		return -1;
	}
	Py_XDECREF(((PyFunctionObject *) op) -> func_defaults);
	((PyFunctionObject *) op) -> func_defaults = defaults;
	return 0;
}

int
PyFunction_SetClosure(PyObject *op, PyObject *closure)
{
	if (!PyFunction_Check(op)) {
		_PyErr_BadInternalCall("funcobject.c", 108);
		return -1;
	}
	if (closure == Py_None)
		closure = NULL;
	else if (PyTuple_Check(closure)) {
		Py_XINCREF(closure);
	}
	else {
		PyErr_SetString(PyExc_SystemError, "non-tuple closure");
		return -1;
	}
	Py_XDECREF(((PyFunctionObject *) op) -> func_closure);
	((PyFunctionObject *) op) -> func_closure = closure;
	return 0;
}

/* Methods */

#define OFF(x) offsetof(PyFunctionObject, x)

static struct memberlist func_memberlist[] = {
        {"func_code",     T_OBJECT,     OFF(func_code)},
        {"func_globals",  T_OBJECT,     OFF(func_globals),      READONLY},
        {"func_name",     T_OBJECT,     OFF(func_name),         READONLY},
        {"__name__",      T_OBJECT,     OFF(func_name),         READONLY},
        {"func_closure",  T_OBJECT,     OFF(func_closure),      READONLY},
        {"func_defaults", T_OBJECT,     OFF(func_defaults)},
        {"func_doc",      T_OBJECT,     OFF(func_doc)},
        {"__doc__",       T_OBJECT,     OFF(func_doc)},
        {"func_dict",     T_OBJECT,     OFF(func_dict)},
        {"__dict__",      T_OBJECT,     OFF(func_dict)},
        {NULL}  /* Sentinel */
};

static PyObject *
func_getattro(PyFunctionObject *op, PyObject *name)
{
	PyObject *rtn;
	char *sname = PyString_AsString(name);
	
	if (sname[0] != '_' && PyEval_GetRestricted()) {
		PyErr_SetString(PyExc_RuntimeError,
		  "function attributes not accessible in restricted mode");
		return NULL;
	}

	/* no API for PyMember_HasAttr() */
	rtn = PyMember_Get((char *)op, func_memberlist, sname);

	if (rtn == NULL && PyErr_ExceptionMatches(PyExc_AttributeError)) {
		PyErr_Clear();
		if (op->func_dict != NULL) {
			rtn = PyDict_GetItem(op->func_dict, name);
			Py_XINCREF(rtn);
		}
		if (rtn == NULL)
			PyErr_SetObject(PyExc_AttributeError, name);
	}
	return rtn;
}

static int
func_setattro(PyFunctionObject *op, PyObject *name, PyObject *value)
{
	int rtn;
	char *sname = PyString_AsString(name);

	if (PyEval_GetRestricted()) {
		PyErr_SetString(PyExc_RuntimeError,
		  "function attributes not settable in restricted mode");
		return -1;
	}
	if (strcmp(sname, "func_code") == 0) {
		/* not legal to del f.func_code or to set it to anything
		 * other than a code object.
		 */
		if (value == NULL || !PyCode_Check(value)) {
			PyErr_SetString(
				PyExc_TypeError,
				"func_code must be set to a code object");
			return -1;
		}
	}
	else if (strcmp(sname, "func_defaults") == 0) {
		/* legal to del f.func_defaults.  Can only set
		 * func_defaults to NULL or a tuple.
		 */
		if (value == Py_None)
			value = NULL;
		if (value != NULL && !PyTuple_Check(value)) {
			PyErr_SetString(
				PyExc_TypeError,
				"func_defaults must be set to a tuple object");
			return -1;
		}
	}
	else if (!strcmp(sname, "func_dict") || !strcmp(sname, "__dict__")) {
		/* legal to del f.func_dict.  Can only set func_dict to
		 * NULL or a dictionary.
		 */
		if (value == Py_None)
			value = NULL;
		if (value != NULL && !PyDict_Check(value)) {
			PyErr_SetString(
				PyExc_TypeError,
				"func_dict must be set to a dict object");
			return -1;
		}
	}

	rtn = PyMember_Set((char *)op, func_memberlist, sname, value);
	if (rtn < 0 && PyErr_ExceptionMatches(PyExc_AttributeError)) {
		PyErr_Clear();
		if (op->func_dict == NULL) {
			/* don't create the dict if we're deleting an
			 * attribute.  In that case, we know we'll get an
			 * AttributeError.
			 */
			if (value == NULL) {
				PyErr_SetString(PyExc_AttributeError, sname);
				return -1;
			}
			op->func_dict = PyDict_New();
			if (op->func_dict == NULL)
				return -1;
		}
                if (value == NULL)
			rtn = PyDict_DelItem(op->func_dict, name);
                else
			rtn = PyDict_SetItem(op->func_dict, name, value);
		/* transform KeyError into AttributeError */
		if (rtn < 0 && PyErr_ExceptionMatches(PyExc_KeyError))
			PyErr_SetString(PyExc_AttributeError, sname);
	}
	return rtn;
}

static void
func_dealloc(PyFunctionObject *op)
{
	PyObject_ClearWeakRefs((PyObject *) op);
	PyObject_GC_Fini(op);
	Py_DECREF(op->func_code);
	Py_DECREF(op->func_globals);
	Py_DECREF(op->func_name);
	Py_XDECREF(op->func_defaults);
	Py_XDECREF(op->func_doc);
	Py_XDECREF(op->func_dict);
	Py_XDECREF(op->func_closure);
	op = (PyFunctionObject *) PyObject_AS_GC(op);
	PyObject_DEL(op);
}

static PyObject*
func_repr(PyFunctionObject *op)
{
	char buf[140];
	if (op->func_name == Py_None)
		sprintf(buf, "<anonymous function at %p>", op);
	else
		sprintf(buf, "<function %.100s at %p>",
			PyString_AsString(op->func_name),
			op);
	return PyString_FromString(buf);
}

static int
func_traverse(PyFunctionObject *f, visitproc visit, void *arg)
{
	int err;
	if (f->func_code) {
		err = visit(f->func_code, arg);
		if (err)
			return err;
	}
	if (f->func_globals) {
		err = visit(f->func_globals, arg);
		if (err)
			return err;
	}
	if (f->func_defaults) {
		err = visit(f->func_defaults, arg);
		if (err)
			return err;
	}
	if (f->func_doc) {
		err = visit(f->func_doc, arg);
		if (err)
			return err;
	}
	if (f->func_name) {
		err = visit(f->func_name, arg);
		if (err)
			return err;
	}
	if (f->func_dict) {
		err = visit(f->func_dict, arg);
		if (err)
			return err;
	}
	if (f->func_closure) {
		err = visit(f->func_closure, arg);
		if (err)
			return err;
	}
	return 0;
}

PyTypeObject PyFunction_Type = {
	PyObject_HEAD_INIT(&PyType_Type)
	0,
	"function",
	sizeof(PyFunctionObject) + PyGC_HEAD_SIZE,
	0,
	(destructor)func_dealloc, /*tp_dealloc*/
	0,		/*tp_print*/
	0, /*tp_getattr*/
	0, /*tp_setattr*/
	0, /*tp_compare*/
	(reprfunc)func_repr, /*tp_repr*/
	0,		/*tp_as_number*/
	0,		/*tp_as_sequence*/
	0,		/*tp_as_mapping*/
	0,		/*tp_hash*/
	0,		/*tp_call*/
	0,		/*tp_str*/
	(void *)func_getattro,	     /*tp_getattro*/
	(void *)func_setattro,	     /*tp_setattro*/
	0,		/* tp_as_buffer */
	Py_TPFLAGS_DEFAULT | Py_TPFLAGS_GC | Py_TPFLAGS_HAVE_WEAKREFS,
	0,		/* tp_doc */
	(traverseproc)func_traverse,	/* tp_traverse */
	0,		/* tp_clear */
	0,		/* tp_richcompare */
	offsetof(PyFunctionObject, func_weakreflist), /* tp_weaklistoffset */
};
