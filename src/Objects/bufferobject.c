
/* Buffer object implementation */

/* Adapted from CPython 2.1; see reference/cpython-2.1/LICENSE.
 * GSQE78 .text 0x80134E70..0x801359FC.
 * CACHE_HASH reproduces the target's 0x1C-byte buffer layout.
 * Only PyBuffer_FromObject and PyBuffer_FromMemory constructors remain in
 * the linked unit. Their shared helpers are emitted inline. */
#include "object.h"
#define CACHE_HASH
#define Py_END_OF_BUFFER (-1)
#define Py_TPFLAGS_DEFAULT 0x6B
#define PyObject_HEAD_INIT(type) 1, type,
#define PyBuffer_Check(o) ((o)->ob_type == &PyBuffer_Type)
#define PyObject_NEW(t, tp) ((t *)PyObject_Init((PyObject *)malloc((tp)->tp_basicsize), (tp)))
#define PyObject_MALLOC malloc
#define PyObject_INIT(o, tp) PyObject_Init((o), (tp))
#define PyObject_DEL free
#define Py_XINCREF(op) if ((op) == NULL) ; else Py_INCREF(op)
#undef Py_DECREF
#define Py_DECREF(op) if (--(op)->ob_refcnt != 0) ; else (*(op)->ob_type->tp_dealloc)((PyObject *)(op))
#define Py_XDECREF(op) if ((op) == NULL) ; else Py_DECREF(op)
#define PyString_AS_STRING(o) (((PyStringObject *)(o))->ob_sval)
typedef struct { PyObject_VAR_HEAD long ob_shash; int ob_sstate; char ob_sval[1]; } PyStringObject;
typedef void (*destructor)(PyObject *);
typedef PyObject *(*reprfunc)(PyObject *);
typedef int (*cmpfunc)(PyObject *, PyObject *);
typedef long (*hashfunc)(PyObject *);
typedef int (*inquiry)(PyObject *);
typedef PyObject *(*binaryfunc)(PyObject *, PyObject *);
typedef PyObject *(*intargfunc)(PyObject *, int);
typedef PyObject *(*intintargfunc)(PyObject *, int, int);
typedef int (*intobjargproc)(PyObject *, int, PyObject *);
typedef int (*intintobjargproc)(PyObject *, int, int, PyObject *);
typedef int (*getreadbufferproc)(PyObject *, int, void **);
typedef int (*getwritebufferproc)(PyObject *, int, void **);
typedef int (*getsegcountproc)(PyObject *, int *);
typedef int (*getcharbufferproc)(PyObject *, int, const char **);
typedef struct {
    getreadbufferproc bf_getreadbuffer;
    getwritebufferproc bf_getwritebuffer;
    getsegcountproc bf_getsegcount;
    getcharbufferproc bf_getcharbuffer;
} PyBufferProcs;
typedef struct {
    inquiry sq_length; binaryfunc sq_concat; intargfunc sq_repeat, sq_item;
    intintargfunc sq_slice; intobjargproc sq_ass_item; intintobjargproc sq_ass_slice;
    void *sq_contains, *sq_inplace_concat, *sq_inplace_repeat;
} PySequenceMethods;
struct _typeobject {
    PyObject_VAR_HEAD
    char *tp_name; int tp_basicsize, tp_itemsize;
    destructor tp_dealloc; void *tp_print, *tp_getattr, *tp_setattr;
    cmpfunc tp_compare; reprfunc tp_repr;
    void *tp_as_number; PySequenceMethods *tp_as_sequence; void *tp_as_mapping;
    hashfunc tp_hash; void *tp_call; reprfunc tp_str;
    void *tp_getattro, *tp_setattro; PyBufferProcs *tp_as_buffer;
    long tp_flags; char *tp_doc;
    void *tp_traverse, *tp_clear, *tp_richcompare; long tp_weaklistoffset;
};
extern PyTypeObject PyBuffer_Type, PyType_Type;
extern PyObject *PyExc_ValueError, *PyExc_TypeError, *PyExc_IndexError, *PyExc_SystemError;
extern void PyErr_SetString(PyObject *, const char *);
extern int PyErr_BadArgument(void);
extern PyObject *PyErr_NoMemory(void);
extern PyObject *PyObject_Init(PyObject *, PyTypeObject *);
extern PyObject *PyString_FromString(const char *), *PyString_FromStringAndSize(const char *, int);
extern int memcmp(const void *, const void *, unsigned int);
extern void *memcpy(void *, const void *, unsigned int);
extern int sprintf(char *, const char *, ...);
extern void *malloc(unsigned int);
extern void free(void *);


typedef struct {
	PyObject_HEAD
	PyObject *b_base;
	void *b_ptr;
	int b_size;
	int b_readonly;
#ifdef CACHE_HASH
	long b_hash;
#endif
} PyBufferObject;


static inline PyObject *
_PyBuffer_FromMemory(PyObject *base, void *ptr, int size, int readonly)
{
	PyBufferObject * b;

	if ( size < 0 ) {
		PyErr_SetString(PyExc_ValueError,
				"size must be zero or positive");
		return NULL;
	}

	b = PyObject_NEW(PyBufferObject, &PyBuffer_Type);
	if ( b == NULL )
		return NULL;

	Py_XINCREF(base);
	b->b_base = base;
	b->b_ptr = ptr;
	b->b_size = size;
	b->b_readonly = readonly;
#ifdef CACHE_HASH
	b->b_hash = -1;
#endif

	return (PyObject *) b;
}

static inline PyObject *
_PyBuffer_FromObject(PyObject *base, int offset, int size,
                     getreadbufferproc proc, int readonly)
{
	PyBufferProcs *pb = base->ob_type->tp_as_buffer;
	void *p;
	int count;

	if ( offset < 0 ) {
		PyErr_SetString(PyExc_ValueError,
				"offset must be zero or positive");
		return NULL;
	}

	if ( (*pb->bf_getsegcount)(base, NULL) != 1 )
	{
		PyErr_SetString(PyExc_TypeError,
				"single-segment buffer object expected");
		return NULL;
	}
	if ( (count = (*proc)(base, 0, &p)) < 0 )
		return NULL;

	/* apply constraints to the start/end */
	if ( size == Py_END_OF_BUFFER || size < 0 )
		size = count;
	if ( offset > count )
		offset = count;
	if ( offset + size > count )
		size = count - offset;

	/* if the base object is another buffer, then "deref" it */
	if ( PyBuffer_Check(base) )
		base = ((PyBufferObject *)base)->b_base;

	return _PyBuffer_FromMemory(base, (char *)p + offset, size, readonly);
}


PyObject *
PyBuffer_FromObject(PyObject *base, int offset, int size)
{
	PyBufferProcs *pb = base->ob_type->tp_as_buffer;

	if ( pb == NULL ||
	     pb->bf_getreadbuffer == NULL ||
	     pb->bf_getsegcount == NULL )
	{
		PyErr_SetString(PyExc_TypeError, "buffer object expected");
		return NULL;
	}

	return _PyBuffer_FromObject(base, offset, size,
				    pb->bf_getreadbuffer, 1);
}


PyObject *
PyBuffer_FromMemory(void *ptr, int size)
{
	return _PyBuffer_FromMemory(NULL, ptr, size, 1);
}


/* Methods */

static void
buffer_dealloc(PyBufferObject *self)
{
	Py_XDECREF(self->b_base);
	PyObject_DEL(self);
}

static int
buffer_compare(PyBufferObject *self, PyBufferObject *other)
{
	int len_self = self->b_size;
	int len_other = other->b_size;
	int min_len = (len_self < len_other) ? len_self : len_other;
	int cmp;
	if (min_len > 0) {
		cmp = memcmp(self->b_ptr, other->b_ptr, min_len);
		if (cmp != 0)
			return cmp;
	}
	return (len_self < len_other) ? -1 : (len_self > len_other) ? 1 : 0;
}

static PyObject *
buffer_repr(PyBufferObject *self)
{
	char buf[300];
	char *status = self->b_readonly ? "read-only" : "read-write";

	if ( self->b_base == NULL )
	{
		sprintf(buf, "<%s buffer ptr %p, size %d at %p>",
			status,
			self->b_ptr,
			self->b_size,
			self);
	}
	else
	{
		sprintf(buf, "<%s buffer for %p, ptr %p, size %d at %p>",
			status,
			self->b_base,
			self->b_ptr,
			self->b_size,
			self);
	}

	return PyString_FromString(buf);
}

static long
buffer_hash(PyBufferObject *self)
{
	register int len;
	register unsigned char *p;
	register long x;

#ifdef CACHE_HASH
	if ( self->b_hash != -1 )
		return self->b_hash;
#endif

	if ( !self->b_readonly )
	{
		/* ### use different wording, since this is conditional? */
		PyErr_SetString(PyExc_TypeError, "unhashable type");
		return -1;
	}

	len = self->b_size;
	p = (unsigned char *) self->b_ptr;
	x = *p << 7;
	while (--len >= 0)
		x = (1000003*x) ^ *p++;
	x ^= self->b_size;
	if (x == -1)
		x = -2;
#ifdef CACHE_HASH
	self->b_hash = x;
#endif
	return x;
}

static PyObject *
buffer_str(PyBufferObject *self)
{
	return PyString_FromStringAndSize(self->b_ptr, self->b_size);
}

/* Sequence methods */

static int
buffer_length(PyBufferObject *self)
{
	return self->b_size;
}

static PyObject *
buffer_concat(PyBufferObject *self, PyObject *other)
{
	PyBufferProcs *pb = other->ob_type->tp_as_buffer;
	char *p1;
	void *p2;
	PyObject *ob;
	int count;

	if ( pb == NULL ||
	     pb->bf_getreadbuffer == NULL ||
	     pb->bf_getsegcount == NULL )
	{
		PyErr_BadArgument();
		return NULL;
	}
	if ( (*pb->bf_getsegcount)(other, NULL) != 1 )
	{
		/* ### use a different exception type/message? */
		PyErr_SetString(PyExc_TypeError,
				"single-segment buffer object expected");
		return NULL;
	}

	/* optimize special case */
	if ( self->b_size == 0 )
	{
	    Py_INCREF(other);
	    return other;
	}

	if ( (count = (*pb->bf_getreadbuffer)(other, 0, &p2)) < 0 )
		return NULL;

	/* optimize special case */
	if ( count == 0 )
	{
	    Py_INCREF(self);
	    return (PyObject *)self;
	}

	ob = PyString_FromStringAndSize(NULL, self->b_size + count);
	p1 = PyString_AS_STRING(ob);
	memcpy(p1, self->b_ptr, self->b_size);
	memcpy(p1 + self->b_size, p2, count);

	/* there is an extra byte in the string object, so this is safe */
	p1[self->b_size + count] = '\0';

	return ob;
}

static PyObject *
buffer_repeat(PyBufferObject *self, int count)
{
	PyObject *ob;
	register char *p;
	void *ptr = self->b_ptr;
	int size = self->b_size;

	if ( count < 0 )
		count = 0;
	ob = PyString_FromStringAndSize(NULL, size * count);
	if ( ob == NULL )
		return NULL;

	p = PyString_AS_STRING(ob);
	while ( count-- )
	{
	    memcpy(p, ptr, size);
	    p += size;
	}

	/* there is an extra byte in the string object, so this is safe */
	*p = '\0';

	return ob;
}

static PyObject *
buffer_item(PyBufferObject *self, int idx)
{
	if ( idx < 0 || idx >= self->b_size )
	{
		PyErr_SetString(PyExc_IndexError, "buffer index out of range");
		return NULL;
	}
	return PyString_FromStringAndSize((char *)self->b_ptr + idx, 1);
}

static PyObject *
buffer_slice(PyBufferObject *self, int left, int right)
{
	if ( left < 0 )
		left = 0;
	if ( right < 0 )
		right = 0;
	if ( right > self->b_size )
		right = self->b_size;
	if ( left == 0 && right == self->b_size )
	{
		/* same as self */
		Py_INCREF(self);
		return (PyObject *)self;
	}
	if ( right < left )
		right = left;
	return PyString_FromStringAndSize((char *)self->b_ptr + left,
					  right - left);
}

static int
buffer_ass_item(PyBufferObject *self, int idx, PyObject *other)
{
	PyBufferProcs *pb;
	void *p;
	int count;

	if ( self->b_readonly ) {
		PyErr_SetString(PyExc_TypeError,
				"buffer is read-only");
		return -1;
	}

	if (idx < 0 || idx >= self->b_size) {
		PyErr_SetString(PyExc_IndexError,
				"buffer assignment index out of range");
		return -1;
	}

	pb = other ? other->ob_type->tp_as_buffer : NULL;
	if ( pb == NULL ||
	     pb->bf_getreadbuffer == NULL ||
	     pb->bf_getsegcount == NULL )
	{
		PyErr_BadArgument();
		return -1;
	}
	if ( (*pb->bf_getsegcount)(other, NULL) != 1 )
	{
		/* ### use a different exception type/message? */
		PyErr_SetString(PyExc_TypeError,
				"single-segment buffer object expected");
		return -1;
	}

	if ( (count = (*pb->bf_getreadbuffer)(other, 0, &p)) < 0 )
		return -1;
	if ( count != 1 ) {
		PyErr_SetString(PyExc_TypeError,
				"right operand must be a single byte");
		return -1;
	}

	((char *)self->b_ptr)[idx] = *(char *)p;
	return 0;
}

static int
buffer_ass_slice(PyBufferObject *self, int left, int right, PyObject *other)
{
	PyBufferProcs *pb;
	void *p;
	int slice_len;
	int count;

	if ( self->b_readonly ) {
		PyErr_SetString(PyExc_TypeError,
				"buffer is read-only");
		return -1;
	}

	pb = other ? other->ob_type->tp_as_buffer : NULL;
	if ( pb == NULL ||
	     pb->bf_getreadbuffer == NULL ||
	     pb->bf_getsegcount == NULL )
	{
		PyErr_BadArgument();
		return -1;
	}
	if ( (*pb->bf_getsegcount)(other, NULL) != 1 )
	{
		/* ### use a different exception type/message? */
		PyErr_SetString(PyExc_TypeError,
				"single-segment buffer object expected");
		return -1;
	}
	if ( (count = (*pb->bf_getreadbuffer)(other, 0, &p)) < 0 )
		return -1;

	if ( left < 0 )
		left = 0;
	else if ( left > self->b_size )
		left = self->b_size;
	if ( right < left )
		right = left;
	else if ( right > self->b_size )
		right = self->b_size;
	slice_len = right - left;

	if ( count != slice_len ) {
		PyErr_SetString(
			PyExc_TypeError,
			"right operand length must match slice length");
		return -1;
	}

	if ( slice_len )
	    memcpy((char *)self->b_ptr + left, p, slice_len);

	return 0;
}

/* Buffer methods */

static int
buffer_getreadbuf(PyBufferObject *self, int idx, void **pp)
{
	if ( idx != 0 ) {
		PyErr_SetString(PyExc_SystemError,
				"accessing non-existent buffer segment");
		return -1;
	}
	*pp = self->b_ptr;
	return self->b_size;
}

static int
buffer_getwritebuf(PyBufferObject *self, int idx, void **pp)
{
	if ( self->b_readonly )
	{
		PyErr_SetString(PyExc_TypeError, "buffer is read-only");
		return -1;
	}
	return buffer_getreadbuf(self, idx, pp);
}

static int
buffer_getsegcount(PyBufferObject *self, int *lenp)
{
	if ( lenp )
		*lenp = self->b_size;
	return 1;
}

static int
buffer_getcharbuf(PyBufferObject *self, int idx, const char **pp)
{
	if ( idx != 0 ) {
		PyErr_SetString(PyExc_SystemError,
				"accessing non-existent buffer segment");
		return -1;
	}
	*pp = (const char *)self->b_ptr;
	return self->b_size;
}


static PySequenceMethods buffer_as_sequence = {
	(inquiry)buffer_length, /*sq_length*/
	(binaryfunc)buffer_concat, /*sq_concat*/
	(intargfunc)buffer_repeat, /*sq_repeat*/
	(intargfunc)buffer_item, /*sq_item*/
	(intintargfunc)buffer_slice, /*sq_slice*/
	(intobjargproc)buffer_ass_item, /*sq_ass_item*/
	(intintobjargproc)buffer_ass_slice, /*sq_ass_slice*/
};

static PyBufferProcs buffer_as_buffer = {
	(getreadbufferproc)buffer_getreadbuf,
	(getwritebufferproc)buffer_getwritebuf,
	(getsegcountproc)buffer_getsegcount,
	(getcharbufferproc)buffer_getcharbuf,
};

PyTypeObject PyBuffer_Type = {
	PyObject_HEAD_INIT(&PyType_Type)
	0,
	"buffer",
	sizeof(PyBufferObject),
	0,
	(destructor)buffer_dealloc, /*tp_dealloc*/
	0,		/*tp_print*/
	0,		/*tp_getattr*/
	0,		/*tp_setattr*/
	(cmpfunc)buffer_compare, /*tp_compare*/
	(reprfunc)buffer_repr, /*tp_repr*/
	0,		/*tp_as_number*/
	&buffer_as_sequence,	/*tp_as_sequence*/
	0,		/*tp_as_mapping*/
	(hashfunc)buffer_hash,	/*tp_hash*/
	0,		/*tp_call*/
	(reprfunc)buffer_str,		/*tp_str*/
	0,		/*tp_getattro*/
	0,		/*tp_setattro*/
	&buffer_as_buffer,	/*tp_as_buffer*/
	Py_TPFLAGS_DEFAULT,	/*tp_flags*/
	0,		/*tp_doc*/
};
