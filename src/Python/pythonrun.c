/* Adapted from CPython 2.1, Python/pythonrun.c.
 * Copyright (c) 2001 Python Software Foundation; All Rights Reserved.
 * License: reference/cpython-2.1/LICENSE.
 * Changes: self-contained recovered ABI and inline-only un-emitted helpers;
 * omitted APIs absent from the linked original. Four ordinary C functions
 * remain for the original linker to discard while preserving shared literals.
 * Original text: 0x801A01C8..0x801A2310.
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

struct _ts; /* Forward */
struct _is; /* Forward */

typedef struct _is {

    struct _is *next;
    struct _ts *tstate_head;

    PyObject *modules;
    PyObject *sysdict;
    PyObject *builtins;

    int checkinterval;

} PyInterpreterState;


/* State unique per thread */

struct _frame; /* Avoid including frameobject.h */

typedef struct _ts {

    struct _ts *next;
    PyInterpreterState *interp;

    struct _frame *frame;
    int recursion_depth;
    int ticker;
    int tracing;

    PyObject *sys_profilefunc;
    PyObject *sys_tracefunc;

    PyObject *curexc_type;
    PyObject *curexc_value;
    PyObject *curexc_traceback;

    PyObject *exc_type;
    PyObject *exc_value;
    PyObject *exc_traceback;

    PyObject *dict;

    /* XXX signal handlers should also be here */

} PyThreadState;



#define NULL 0
#define PyObject_HEAD int ob_refcnt; PyTypeObject *ob_type;
#define Py_INCREF(op) ((op)->ob_refcnt++)
#define Py_XINCREF(op) if ((op) == NULL) ; else Py_INCREF(op)
#define Py_DECREF(op) if (--(op)->ob_refcnt != 0) ; else (*(op)->ob_type->tp_dealloc)((PyObject *)(op))
#define Py_XDECREF(op) if ((op) == NULL) ; else Py_DECREF(op)
#define Py_None (&_Py_NoneStruct)
#define PyMem_DEL(op) free(op)
#define Py_PRINT_RAW 1
#define Py_file_input 257
#define Py_single_input 256
#define CO_NESTED 0x10
#define INDENT 5
#define DEDENT 6
#define PyTuple_Check(op) ((op)->ob_type == &PyTuple_Type)
#define PyString_Check(op) ((op)->ob_type == &PyString_Type)
#define PyInt_Check(op) ((op)->ob_type == &PyInt_Type)
#define PyClass_Check(op) ((op)->ob_type == &PyClass_Type)
#define PyInstance_Check(op) ((op)->ob_type == &PyInstance_Type)
#define PyString_GET_SIZE(op) (((PyStringObject *)(op))->ob_size)
#define PyEval_CallObject(f,a) PyEval_CallObjectWithKeywords(f,a,NULL)
typedef unsigned int size_t;
typedef struct { char contents[80]; } FILE;
extern FILE __files[];
#define stdin (&__files[0])
#define stdout (&__files[1])
#define stderr (&__files[2])
typedef struct _node node;
typedef struct { int g_ndfas; void *g_dfa; int g_ll_count; void *g_ll_label; int g_start; int g_accel; } grammar;
typedef struct { int cf_nested_scopes; } PyCompilerFlags;
typedef struct { int error; char *filename; int lineno, offset; char *text; int token, expected; } perrdetail;
typedef struct { PyObject_HEAD int ob_size; } PyStringObject;
typedef struct { PyObject_HEAD PyObject *cl_bases, *cl_dict, *cl_name; } PyClassObject;
typedef struct { PyObject_HEAD int co_argcount, co_nlocals, co_stacksize, co_flags; } PyCodeObject;
typedef void (*PyOS_sighandler_t)(int);
#define SIG_IGN ((PyOS_sighandler_t)1)
extern PyObject _Py_NoneStruct;
extern PyTypeObject PyTuple_Type, PyString_Type, PyClass_Type, PyInstance_Type, PyInt_Type;
extern PyObject *PyExc_SystemExit, *PyExc_SyntaxError, *PyExc_IndentationError, *PyExc_KeyboardInterrupt, *PyExc_TabError;
extern int Py_OptimizeFlag;
extern grammar _PyParser_Grammar;
extern char *getenv(const char *);
extern char *strchr(const char *, int);
extern size_t strlen(const char *);
extern int strcmp(const char *, const char *);
extern void free(void *);
extern int fprintf(FILE *, const char *, ...);
extern int sprintf(char *, const char *, ...);
extern int fflush(FILE *);
extern int fclose(FILE *);
extern void abort(void);
extern void exit(int);
extern PyOS_sighandler_t signal(int, PyOS_sighandler_t);
extern PyInterpreterState *PyInterpreterState_New(void);
extern PyThreadState *PyThreadState_New(PyInterpreterState *);
extern PyThreadState *PyThreadState_Swap(PyThreadState *);
extern PyThreadState *PyThreadState_Get(void);
extern void PyInterpreterState_Clear(PyInterpreterState *);
extern void PyInterpreterState_Delete(PyInterpreterState *);
extern PyObject *PyDict_New(void);
extern PyObject *PyDict_GetItemString(PyObject *, const char *);
extern int PyDict_SetItemString(PyObject *, const char *, PyObject *);
extern void _PyCodecRegistry_Init(void);
extern void _PyCodecRegistry_Fini(void);
extern void _PyUnicode_Init(void);
extern void _PyUnicode_Fini(void);
extern PyObject *_PyBuiltin_Init(void);
extern PyObject *_PySys_Init(void);
extern PyObject *PyModule_GetDict(PyObject *);
extern PyObject *_PyImport_FixupExtension(char *, char *);
extern void PySys_SetPath(char *);
extern char *Py_GetPath(void);
extern void _PyImport_Init(void);
extern void _PyImport_Fini(void);
extern void PyImport_Cleanup(void);
extern PyObject *PyImport_AddModule(char *);
extern PyObject *PyImport_ImportModule(char *);
extern void init_exceptions(void);
extern void fini_exceptions(void);
extern void PyOS_InitInterrupts(void);
extern void PyOS_FiniInterrupts(void);
extern void PyMethod_Fini(void);
extern void PyFrame_Fini(void);
extern void PyCFunction_Fini(void);
extern void PyTuple_Fini(void);
extern void PyString_Fini(void);
extern void PyInt_Fini(void);
extern void PyFloat_Fini(void);
extern void PyGrammar_RemoveAccelerators(grammar *);
extern PyObject *PySys_GetObject(char *);
extern int PySys_SetObject(char *, PyObject *);
extern void PySys_WriteStderr(const char *, ...);
extern int PyArg_Parse(PyObject *, const char *, ...);
extern PyObject *PyObject_GetAttrString(PyObject *, const char *);
extern char *PyString_AsString(PyObject *);
extern long PyInt_AsLong(PyObject *);
extern PyObject *PyErr_Occurred(void);
extern void PyErr_Clear(void);
extern void PyErr_SetNone(PyObject *);
extern PyObject *PyErr_NoMemory(void);
extern void PyErr_SetObject(PyObject *, PyObject *);
extern void PyErr_Fetch(PyObject **, PyObject **, PyObject **);
extern void PyErr_NormalizeException(PyObject **, PyObject **, PyObject **);
extern int PyErr_ExceptionMatches(PyObject *);
extern int PyErr_GivenExceptionMatches(PyObject *, PyObject *);
extern int Py_FlushLine(void);
extern int PyFile_WriteString(const char *, PyObject *);
extern int PyFile_WriteObject(PyObject *, PyObject *, int);
extern int PyObject_Print(PyObject *, FILE *, int);
extern int PyTraceBack_Print(PyObject *, PyObject *);
extern PyObject *PyObject_Str(PyObject *);
extern PyObject *Py_BuildValue(char *, ...);
extern PyObject *PyEval_CallObjectWithKeywords(PyObject *, PyObject *, PyObject *);
extern PyObject *PyEval_EvalCode(PyCodeObject *, PyObject *, PyObject *);
extern PyCodeObject *PyNode_CompileFlags(node *, char *, PyCompilerFlags *);
extern void PyNode_Free(node *);
extern node *PyParser_ParseFile(FILE *, char *, grammar *, int, char *, char *, perrdetail *);
extern node *PyParser_ParseString(char *, grammar *, int, perrdetail *);
PyObject *PyRun_String(char *, int, PyObject *, PyObject *);
void Py_FatalError(char *);
void PyErr_Print(void);
void PyErr_PrintEx(int);
void PyErr_Display(PyObject *, PyObject *, PyObject *);
static inline void Py_Exit(int);
node *PyParser_SimpleParseFile(FILE *, char *, int);
static inline node *PyParser_SimpleParseString(char *, int);
PyObject *Py_CompileStringFlags(char *, char *, int, PyCompilerFlags *);
PyObject *PyRun_FileEx(FILE *, char *, int, PyObject *, PyObject *, int);
PyObject *PyRun_FileExFlags(FILE *, char *, int, PyObject *, PyObject *, int, PyCompilerFlags *);
#define E_OK		10	/* No error */
#define E_EOF		11	/* End Of File */
#define E_INTR		12	/* Interrupted */
#define E_TOKEN		13	/* Bad token */
#define E_SYNTAX	14	/* Syntax error */
#define E_NOMEM		15	/* Ran out of memory */
#define E_DONE		16	/* Parsing complete */
#define E_ERROR		17	/* Execution error */
#define E_TABSPACE	18	/* Inconsistent mixing of tabs and spaces */
#define E_OVERFLOW      19	/* Node had too many children */
#define E_TOODEEP	20	/* Too many indentation levels */
#define E_DEDENT	21	/* No matching outer block for dedent */

/* Forward */
static void initmain(void);
static void initsite(void);
static inline PyObject *run_err_node(node *, char *, PyObject *, PyObject *,
			      PyCompilerFlags *);
static inline PyObject *run_node(node *, char *, PyObject *, PyObject *,
			  PyCompilerFlags *);

static void err_input(perrdetail *);
static inline void initsigs(void);
static void call_sys_exitfunc(void);
static inline void call_ll_exitfuncs(void);

#ifdef Py_TRACE_REFS
int _Py_AskYesNo(char *prompt);
#endif

extern void _PyUnicode_Init(void);
extern void _PyUnicode_Fini(void);
extern void _PyCodecRegistry_Init(void);
extern void _PyCodecRegistry_Fini(void);

int Py_DebugFlag; /* Needed by parser.c */
int Py_VerboseFlag; /* Needed by import.c */
int Py_NoSiteFlag; /* Suppress 'import site' */
int Py_UnicodeFlag = 0; /* Needed by compile.c */

static int initialized = 0;

/* API to access the initialized flag -- useful for esoteric use */

int
Py_IsInitialized(void)
{
	return initialized;
}

/* Global initializations.  Can be undone by Py_Finalize().  Don't
   call this twice without an intervening Py_Finalize() call.  When
   initializations fail, a fatal error is issued and the function does
   not return.  On return, the first thread and interpreter state have
   been created.

   Locking: you must hold the interpreter lock while calling this.
   (If the lock has not yet been initialized, that's equivalent to
   having the lock, but you cannot use multiple threads.)

*/

void
Py_Initialize(void)
{
	PyInterpreterState *interp;
	PyThreadState *tstate;
	PyObject *bimod, *sysmod;
	char *p;

	if (initialized)
		return;
	initialized = 1;
	
	if ((p = getenv("PYTHONDEBUG")) && *p != '\0')
		Py_DebugFlag = Py_DebugFlag ? Py_DebugFlag : 1;
	if ((p = getenv("PYTHONVERBOSE")) && *p != '\0')
		Py_VerboseFlag = Py_VerboseFlag ? Py_VerboseFlag : 1;
	if ((p = getenv("PYTHONOPTIMIZE")) && *p != '\0')
		Py_OptimizeFlag = Py_OptimizeFlag ? Py_OptimizeFlag : 1;

	interp = PyInterpreterState_New();
	if (interp == NULL)
		Py_FatalError("Py_Initialize: can't make first interpreter");

	tstate = PyThreadState_New(interp);
	if (tstate == NULL)
		Py_FatalError("Py_Initialize: can't make first thread");
	(void) PyThreadState_Swap(tstate);

	interp->modules = PyDict_New();
	if (interp->modules == NULL)
		Py_FatalError("Py_Initialize: can't make modules dictionary");

	/* Init codec registry */
	_PyCodecRegistry_Init();

	/* Init Unicode implementation; relies on the codec registry */
	_PyUnicode_Init();

	bimod = _PyBuiltin_Init();
	if (bimod == NULL)
		Py_FatalError("Py_Initialize: can't initialize __builtin__");
	interp->builtins = PyModule_GetDict(bimod);
	Py_INCREF(interp->builtins);

	sysmod = _PySys_Init();
	if (sysmod == NULL)
		Py_FatalError("Py_Initialize: can't initialize sys");
	interp->sysdict = PyModule_GetDict(sysmod);
	Py_INCREF(interp->sysdict);
	_PyImport_FixupExtension("sys", "sys");
	PySys_SetPath(Py_GetPath());
	PyDict_SetItemString(interp->sysdict, "modules",
			     interp->modules);

	_PyImport_Init();

	/* initialize builtin exceptions */
	init_exceptions();

	/* phase 2 of builtins */
	_PyImport_FixupExtension("__builtin__", "__builtin__");

	initsigs(); /* Signal handling stuff, including initintr() */

	initmain(); /* Module __main__ */
	if (!Py_NoSiteFlag)
		initsite(); /* Module site */
}

#ifdef COUNT_ALLOCS
extern void dump_counts(void);
#endif

/* Undo the effect of Py_Initialize().

   Beware: if multiple interpreter and/or thread states exist, these
   are not wiped out; only the current thread and interpreter state
   are deleted.  But since everything else is deleted, those other
   interpreter and thread states should no longer be used.

   (XXX We should do better, e.g. wipe out all interpreters and
   threads.)

   Locking: as above.

*/

void
Py_Finalize(void)
{
	PyInterpreterState *interp;
	PyThreadState *tstate;

	if (!initialized)
		return;

	/* The interpreter is still entirely intact at this point, and the
	 * exit funcs may be relying on that.  In particular, if some thread
	 * or exit func is still waiting to do an import, the import machinery
	 * expects Py_IsInitialized() to return true.  So don't say the
	 * interpreter is uninitialized until after the exit funcs have run.
	 * Note that Threading.py uses an exit func to do a join on all the
	 * threads created thru it, so this also protects pending imports in
	 * the threads created via Threading.
	 */
	call_sys_exitfunc();
	initialized = 0;

	/* Get current thread state and interpreter pointer */
	tstate = PyThreadState_Get();
	interp = tstate->interp;

	/* Disable signal handling */
	PyOS_FiniInterrupts();

	/* Cleanup Unicode implementation */
	_PyUnicode_Fini();

	/* Cleanup Codec registry */
	_PyCodecRegistry_Fini();

	/* Destroy all modules */
	PyImport_Cleanup();

	/* Destroy the database used by _PyImport_{Fixup,Find}Extension */
	_PyImport_Fini();

	/* Debugging stuff */
#ifdef COUNT_ALLOCS
	dump_counts();
#endif

#ifdef Py_REF_DEBUG
	fprintf(stderr, "[%ld refs]\n", _Py_RefTotal);
#endif

#ifdef Py_TRACE_REFS
	if (
#ifdef MS_WINDOWS /* Only ask on Windows if env var set */
	    getenv("PYTHONDUMPREFS") &&
#endif /* MS_WINDOWS */
	    _Py_AskYesNo("Print left references?")) {
		_Py_PrintReferences(stderr);
	}
#endif /* Py_TRACE_REFS */

	/* Now we decref the exception classes.  After this point nothing
	   can raise an exception.  That's okay, because each Fini() method
	   below has been checked to make sure no exceptions are ever
	   raised.
	*/
	fini_exceptions();

	/* Delete current thread */
	PyInterpreterState_Clear(interp);
	PyThreadState_Swap(NULL);
	PyInterpreterState_Delete(interp);

	PyMethod_Fini();
	PyFrame_Fini();
	PyCFunction_Fini();
	PyTuple_Fini();
	PyString_Fini();
	PyInt_Fini();
	PyFloat_Fini();

	/* XXX Still allocated:
	   - various static ad-hoc pointers to interned strings
	   - int and float free list blocks
	   - whatever various modules and libraries allocate
	*/

	PyGrammar_RemoveAccelerators(&_PyParser_Grammar);

	call_ll_exitfuncs();

#ifdef Py_TRACE_REFS
	_Py_ResetReferences();
#endif /* Py_TRACE_REFS */
}

/* Create and initialize a new interpreter and thread, and return the
   new thread.  This requires that Py_Initialize() has been called
   first.

   Unsuccessful initialization yields a NULL pointer.  Note that *no*
   exception information is available even in this case -- the
   exception information is held in the thread, and there is no
   thread.

   Locking: as above.

*/



/* Delete an interpreter and its last thread.  This requires that the
   given thread state is current, that the thread has no remaining
   frames, and that it is its interpreter's only remaining thread.
   It is a fatal error to violate these constraints.

   (Py_Finalize() doesn't have these constraints -- it zaps
   everything, regardless.)

   Locking: as above.

*/















/* Create __main__ module */

static void
initmain(void)
{
	PyObject *m, *d;
	m = PyImport_AddModule("__main__");
	if (m == NULL)
		Py_FatalError("can't create __main__ module");
	d = PyModule_GetDict(m);
	if (PyDict_GetItemString(d, "__builtins__") == NULL) {
		PyObject *bimod = PyImport_ImportModule("__builtin__");
		if (bimod == NULL ||
		    PyDict_SetItemString(d, "__builtins__", bimod) != 0)
			Py_FatalError("can't add __builtins__ to __main__");
		Py_DECREF(bimod);
	}
}

/* Import the site module (not into __main__ though) */

static void
initsite(void)
{
	PyObject *m, *f;
	m = PyImport_ImportModule("site");
	if (m == NULL) {
		f = PySys_GetObject("stderr");
		if (Py_VerboseFlag) {
			PyFile_WriteString(
				"'import site' failed; traceback:\n", f);
			PyErr_Print();
		}
		else {
			PyFile_WriteString(
			  "'import site' failed; use -v for traceback\n", f);
			PyErr_Clear();
		}
	}
	else {
		Py_DECREF(m);
	}
}

/* Parse input from a file and execute it */



















/* Check whether a file maybe a pyc file: Look at the extension,
   the file type, and, if we may close it, at the first few bytes. */

 







int
PyRun_SimpleString(char *command)
{
	PyObject *m, *d, *v;
	m = PyImport_AddModule("__main__");
	if (m == NULL)
		return -1;
	d = PyModule_GetDict(m);
	v = PyRun_String(command, Py_file_input, d, d);
	if (v == NULL) {
		PyErr_Print();
		return -1;
	}
	Py_DECREF(v);
	if (Py_FlushLine())
		PyErr_Clear();
	return 0;
}

static int
parse_syntax_error(PyObject *err, PyObject **message, char **filename,
		   int *lineno, int *offset, char **text)
{
	long hold;
	PyObject *v;

	/* old style errors */
	if (PyTuple_Check(err))
		return PyArg_Parse(err, "(O(ziiz))", message, filename,
				   lineno, offset, text);

	/* new style errors.  `err' is an instance */

	if (! (v = PyObject_GetAttrString(err, "msg")))
		goto finally;
	*message = v;

	if (!(v = PyObject_GetAttrString(err, "filename")))
		goto finally;
	if (v == Py_None)
		*filename = NULL;
	else if (! (*filename = PyString_AsString(v)))
		goto finally;

	Py_DECREF(v);
	if (!(v = PyObject_GetAttrString(err, "lineno")))
		goto finally;
	hold = PyInt_AsLong(v);
	Py_DECREF(v);
	v = NULL;
	if (hold < 0 && PyErr_Occurred())
		goto finally;
	*lineno = (int)hold;

	if (!(v = PyObject_GetAttrString(err, "offset")))
		goto finally;
	if (v == Py_None) {
		*offset = -1;
		Py_DECREF(v);
		v = NULL;
	} else {
		hold = PyInt_AsLong(v);
		Py_DECREF(v);
		v = NULL;
		if (hold < 0 && PyErr_Occurred())
			goto finally;
		*offset = (int)hold;
	}

	if (!(v = PyObject_GetAttrString(err, "text")))
		goto finally;
	if (v == Py_None)
		*text = NULL;
	else if (! (*text = PyString_AsString(v)))
		goto finally;
	Py_DECREF(v);
	return 1;

finally:
	Py_XDECREF(v);
	return 0;
}

void
PyErr_Print(void)
{
	PyErr_PrintEx(1);
}

static void
print_error_text(PyObject *f, int offset, char *text)
{
	char *nl;
	if (offset >= 0) {
		if (offset > 0 && offset == (int)strlen(text))
			offset--;
		for (;;) {
			nl = strchr(text, '\n');
			if (nl == NULL || nl-text >= offset)
				break;
			offset -= (nl+1-text);
			text = nl+1;
		}
		while (*text == ' ' || *text == '\t') {
			text++;
			offset--;
		}
	}
	PyFile_WriteString("    ", f);
	PyFile_WriteString(text, f);
	if (*text == '\0' || text[strlen(text)-1] != '\n')
		PyFile_WriteString("\n", f);
	if (offset == -1)
		return;
	PyFile_WriteString("    ", f);
	offset--;
	while (offset > 0) {
		PyFile_WriteString(" ", f);
		offset--;
	}
	PyFile_WriteString("^\n", f);
}

static void
handle_system_exit(void)
{
        PyObject *exception, *value, *tb;
	PyErr_Fetch(&exception, &value, &tb);
	if (Py_FlushLine())
		PyErr_Clear();
	fflush(stdout);
	if (value == NULL || value == Py_None)
		Py_Exit(0);
	if (PyInstance_Check(value)) {
		/* The error code should be in the `code' attribute. */
		PyObject *code = PyObject_GetAttrString(value, "code");
		if (code) {
			Py_DECREF(value);
			value = code;
			if (value == Py_None)
				Py_Exit(0);
		}
		/* If we failed to dig out the 'code' attribute,
		   just let the else clause below print the error. */
	}
	if (PyInt_Check(value))
		Py_Exit((int)PyInt_AsLong(value));
	else {
		PyObject_Print(value, stderr, Py_PRINT_RAW);
		PySys_WriteStderr("\n");
		Py_Exit(1);
	}
}

void
PyErr_PrintEx(int set_sys_last_vars)
{
	PyObject *exception, *v, *tb, *hook;

	if (PyErr_ExceptionMatches(PyExc_SystemExit)) {
		handle_system_exit();
	}
	PyErr_Fetch(&exception, &v, &tb);
	PyErr_NormalizeException(&exception, &v, &tb);
	if (exception == NULL)
		return;
	if (set_sys_last_vars) {
		PySys_SetObject("last_type", exception);
		PySys_SetObject("last_value", v);
		PySys_SetObject("last_traceback", tb);
	}
	hook = PySys_GetObject("excepthook");
	if (hook) {
		PyObject *args = Py_BuildValue("(OOO)",
                    exception, v ? v : Py_None, tb ? tb : Py_None);
		PyObject *result = PyEval_CallObject(hook, args);
		if (result == NULL) {
			PyObject *exception2, *v2, *tb2;
			if (PyErr_ExceptionMatches(PyExc_SystemExit)) {
				handle_system_exit();
			}
			PyErr_Fetch(&exception2, &v2, &tb2);
			PyErr_NormalizeException(&exception2, &v2, &tb2);
			if (Py_FlushLine())
				PyErr_Clear();
			fflush(stdout);
			PySys_WriteStderr("Error in sys.excepthook:\n");
			PyErr_Display(exception2, v2, tb2);
			PySys_WriteStderr("\nOriginal exception was:\n");
			PyErr_Display(exception, v, tb);
		}
		Py_XDECREF(result);
		Py_XDECREF(args);
	} else {
		PySys_WriteStderr("sys.excepthook is missing\n");
		PyErr_Display(exception, v, tb);
	}
	Py_XDECREF(exception);
	Py_XDECREF(v);
	Py_XDECREF(tb);
}

void PyErr_Display(PyObject *exception, PyObject *value, PyObject *tb)
{
	int err = 0;
	PyObject *v = value;
	PyObject *f = PySys_GetObject("stderr");
	if (f == NULL)
		fprintf(stderr, "lost sys.stderr\n");
	else {
		if (Py_FlushLine())
			PyErr_Clear();
		fflush(stdout);
		if (tb && tb != Py_None)
			err = PyTraceBack_Print(tb, f);
		if (err == 0 &&
		    PyErr_GivenExceptionMatches(exception, PyExc_SyntaxError))
		{
			PyObject *message;
			char *filename, *text;
			int lineno, offset;
			if (!parse_syntax_error(v, &message, &filename,
						&lineno, &offset, &text))
				PyErr_Clear();
			else {
				char buf[10];
				PyFile_WriteString("  File \"", f);
				if (filename == NULL)
					PyFile_WriteString("<string>", f);
				else
					PyFile_WriteString(filename, f);
				PyFile_WriteString("\", line ", f);
				sprintf(buf, "%d", lineno);
				PyFile_WriteString(buf, f);
				PyFile_WriteString("\n", f);
				if (text != NULL)
					print_error_text(f, offset, text);
				v = message;
				/* Can't be bothered to check all those
				   PyFile_WriteString() calls */
				if (PyErr_Occurred())
					err = -1;
			}
		}
		if (err) {
			/* Don't do anything else */
		}
		else if (PyClass_Check(exception)) {
			PyClassObject* exc = (PyClassObject*)exception;
			PyObject* className = exc->cl_name;
			PyObject* moduleName =
			      PyDict_GetItemString(exc->cl_dict, "__module__");

			if (moduleName == NULL)
				err = PyFile_WriteString("<unknown>", f);
			else {
				char* modstr = PyString_AsString(moduleName);
				if (modstr && strcmp(modstr, "exceptions")) 
				{
					err = PyFile_WriteString(modstr, f);
					err += PyFile_WriteString(".", f);
				}
			}
			if (err == 0) {
				if (className == NULL)
				      err = PyFile_WriteString("<unknown>", f);
				else
				      err = PyFile_WriteObject(className, f,
							       Py_PRINT_RAW);
			}
		}
		else
			err = PyFile_WriteObject(exception, f, Py_PRINT_RAW);
		if (err == 0) {
			if (v != NULL && v != Py_None) {
				PyObject *s = PyObject_Str(v);
				/* only print colon if the str() of the
				   object is not the empty string
				*/
				if (s == NULL)
					err = -1;
				else if (!PyString_Check(s) ||
					 PyString_GET_SIZE(s) != 0)
					err = PyFile_WriteString(": ", f);
				if (err == 0)
				  err = PyFile_WriteObject(s, f, Py_PRINT_RAW);
				Py_XDECREF(s);
			}
		}
		if (err == 0)
			err = PyFile_WriteString("\n", f);
	}
	/* If an error happened here, don't show it.
	   XXX This is wrong, but too many callers rely on this behavior. */
	if (err != 0)
		PyErr_Clear();
}

PyObject *
PyRun_String(char *str, int start, PyObject *globals, PyObject *locals)
{
	return run_err_node(PyParser_SimpleParseString(str, start),
			    "<string>", globals, locals, NULL);
}

PyObject *
PyRun_File(FILE *fp, char *filename, int start, PyObject *globals,
	   PyObject *locals)
{
	return PyRun_FileEx(fp, filename, start, globals, locals, 0);
}

PyObject *
PyRun_FileEx(FILE *fp, char *filename, int start, PyObject *globals,
	     PyObject *locals, int closeit)
{
	node *n = PyParser_SimpleParseFile(fp, filename, start);
	if (closeit)
		fclose(fp);
	return run_err_node(n, filename, globals, locals, NULL);
}

PyObject *
PyRun_StringFlags(char *str, int start, PyObject *globals, PyObject *locals,
		  PyCompilerFlags *flags)
{
	return run_err_node(PyParser_SimpleParseString(str, start),
			    "<string>", globals, locals, flags);
}

PyObject *
PyRun_FileFlags(FILE *fp, char *filename, int start, PyObject *globals,
		PyObject *locals, PyCompilerFlags *flags)
{
	return PyRun_FileExFlags(fp, filename, start, globals, locals, 0,
				 flags); 
}

PyObject *
PyRun_FileExFlags(FILE *fp, char *filename, int start, PyObject *globals,
		  PyObject *locals, int closeit, PyCompilerFlags *flags)
{
	node *n = PyParser_SimpleParseFile(fp, filename, start);
	if (closeit)
		fclose(fp);
	return run_err_node(n, filename, globals, locals, flags);
}

static inline PyObject *
run_err_node(node *n, char *filename, PyObject *globals, PyObject *locals,
	     PyCompilerFlags *flags)
{
	if (n == NULL)
		return  NULL;
	return run_node(n, filename, globals, locals, flags);
}

static inline PyObject *
run_node(node *n, char *filename, PyObject *globals, PyObject *locals,
	 PyCompilerFlags *flags)
{
	PyCodeObject *co;
	PyObject *v;
	co = PyNode_CompileFlags(n, filename, flags);
	PyNode_Free(n);
	if (co == NULL)
		return NULL;
	v = PyEval_EvalCode(co, globals, locals);
	Py_DECREF(co);
	return v;
}



PyObject *
Py_CompileString(char *str, char *filename, int start)
{
	return Py_CompileStringFlags(str, filename, start, NULL);
}

PyObject *
Py_CompileStringFlags(char *str, char *filename, int start, 
		      PyCompilerFlags *flags)
{
	node *n;
	PyCodeObject *co;
	n = PyParser_SimpleParseString(str, start);
	if (n == NULL)
		return NULL;
	co = PyNode_CompileFlags(n, filename, flags);
	PyNode_Free(n);
	return (PyObject *)co;
}



/* Simplified interface to parsefile -- return node or set exception */

node *
PyParser_SimpleParseFile(FILE *fp, char *filename, int start)
{
	node *n;
	perrdetail err;
	n = PyParser_ParseFile(fp, filename, &_PyParser_Grammar, start,
				(char *)0, (char *)0, &err);
	if (n == NULL)
		err_input(&err);
	return n;
}

/* Simplified interface to parsestring -- return node or set exception */

static inline node *
PyParser_SimpleParseString(char *str, int start)
{
	node *n;
	perrdetail err;
	n = PyParser_ParseString(str, &_PyParser_Grammar, start, &err);
	if (n == NULL)
		err_input(&err);
	return n;
}

/* Set the error appropriate to the given input error code (see errcode.h) */

static void
err_input(perrdetail *err)
{
	PyObject *v, *w, *errtype;
	char *msg = NULL;
	errtype = PyExc_SyntaxError;
	v = Py_BuildValue("(ziiz)", err->filename,
			    err->lineno, err->offset, err->text);
	if (err->text != NULL) {
		PyMem_DEL(err->text);
		err->text = NULL;
	}
	switch (err->error) {
	case E_SYNTAX:
		errtype = PyExc_IndentationError;
		if (err->expected == INDENT)
			msg = "expected an indented block";
		else if (err->token == INDENT)
			msg = "unexpected indent";
		else if (err->token == DEDENT)
			msg = "unexpected unindent";
		else {
			errtype = PyExc_SyntaxError;
			msg = "invalid syntax";
		}
		break;
	case E_TOKEN:
		msg = "invalid token";
		break;
	case E_INTR:
		PyErr_SetNone(PyExc_KeyboardInterrupt);
		Py_XDECREF(v);
		return;
	case E_NOMEM:
		PyErr_NoMemory();
		Py_XDECREF(v);
		return;
	case E_EOF:
		msg = "unexpected EOF while parsing";
		break;
	case E_TABSPACE:
		errtype = PyExc_TabError;
		msg = "inconsistent use of tabs and spaces in indentation";
		break;
	case E_OVERFLOW:
		msg = "expression too long";
		break;
	case E_DEDENT:
		errtype = PyExc_IndentationError;
		msg = "unindent does not match any outer indentation level";
		break;
	case E_TOODEEP:
		errtype = PyExc_IndentationError;
		msg = "too many levels of indentation";
		break;
	default:
		fprintf(stderr, "error=%d\n", err->error);
		msg = "unknown parsing error";
		break;
	}
	w = Py_BuildValue("(sO)", msg, v);
	Py_XDECREF(v);
	PyErr_SetObject(errtype, w);
	Py_XDECREF(w);
}

/* Print fatal error message and abort */

void
Py_FatalError(char *msg)
{
	fprintf(stderr, "Fatal Python error: %s\n", msg);
#ifdef macintosh
	for (;;);
#endif
#ifdef MS_WIN32
	OutputDebugString("Fatal Python error: ");
	OutputDebugString(msg);
	OutputDebugString("\n");
#ifdef _DEBUG
	DebugBreak();
#endif
#endif /* MS_WIN32 */
	abort();
}

/* Clean up and exit */

#ifdef WITH_THREAD
#include "pythread.h"
int _PyThread_Started = 0; /* Set by threadmodule.c and maybe others */
#endif

#define NEXITFUNCS 32
static void (*exitfuncs[NEXITFUNCS])(void);
static int nexitfuncs = 0;



static void
call_sys_exitfunc(void)
{
	PyObject *exitfunc = PySys_GetObject("exitfunc");

	if (exitfunc) {
		PyObject *res;
		Py_INCREF(exitfunc);
		PySys_SetObject("exitfunc", (PyObject *)NULL);
		res = PyEval_CallObject(exitfunc, (PyObject *)NULL);
		if (res == NULL) {
			if (!PyErr_ExceptionMatches(PyExc_SystemExit)) {
				PySys_WriteStderr("Error in sys.exitfunc:\n");
			}
			PyErr_Print();
		}
		Py_DECREF(exitfunc);
	}

	if (Py_FlushLine())
		PyErr_Clear();
}

static inline void
call_ll_exitfuncs(void)
{
	while (nexitfuncs > 0)
		(*exitfuncs[--nexitfuncs])();

	fflush(stdout);
	fflush(stderr);
}

static inline void
Py_Exit(int sts)
{
	Py_Finalize();

#ifdef macintosh
	PyMac_Exit(sts);
#else
	exit(sts);
#endif
}

static inline void
initsigs(void)
{
#ifdef HAVE_SIGNAL_H
#ifdef SIGPIPE
	signal(SIGPIPE, SIG_IGN);
#endif
#endif /* HAVE_SIGNAL_H */
	PyOS_InitInterrupts(); /* May imply initsignal() */
}

#ifdef Py_TRACE_REFS
/* Ask a yes/no question */

int
_Py_AskYesNo(char *prompt)
{
	char buf[256];
	
	printf("%s [ny] ", prompt);
	if (fgets(buf, sizeof buf, stdin) == NULL)
		return 0;
	return buf[0] == 'y' || buf[0] == 'Y';
}
#endif

#ifdef MPW

/* Check for file descriptor connected to interactive device.
   Pretend that stdin is always interactive, other files never. */

int
isatty(int fd)
{
	return fd == fileno(stdin);
}

#endif

/*
 * The file descriptor fd is considered ``interactive'' if either
 *   a) isatty(fd) is TRUE, or
 *   b) the -i flag was given, and the filename associated with
 *      the descriptor is NULL or "<stdin>" or "???".
 */



#if defined(USE_STACKCHECK) 
#if defined(WIN32) && defined(_MSC_VER)

/* Stack checking for Microsoft C */

#include <malloc.h>
#include <excpt.h>

/*
 * Return non-zero when we run out of memory on the stack; zero otherwise.
 */
int
PyOS_CheckStack(void)
{
	__try {
		/* _alloca throws a stack overflow exception if there's
		   not enough space left on the stack */
		_alloca(PYOS_STACK_MARGIN * sizeof(void*));
		return 0;
	} __except (EXCEPTION_EXECUTE_HANDLER) {
		/* just ignore all errors */
	}
	return 1;
}

#endif /* WIN32 && _MSC_VER */

/* Alternate implementations can be added here... */

#endif /* USE_STACKCHECK */


/* Wrappers around sigaction() or signal(). */

PyOS_sighandler_t
PyOS_getsig(int sig)
{
#ifdef HAVE_SIGACTION
	struct sigaction context;
	sigaction(sig, NULL, &context);
	return context.sa_handler;
#else
	PyOS_sighandler_t handler;
	handler = signal(sig, SIG_IGN);
	signal(sig, handler);
	return handler;
#endif
}

PyOS_sighandler_t
PyOS_setsig(int sig, PyOS_sighandler_t handler)
{
#ifdef HAVE_SIGACTION
	struct sigaction context;
	PyOS_sighandler_t oldhandler;
	sigaction(sig, NULL, &context);
	oldhandler = context.sa_handler;
	context.sa_handler = handler;
	sigaction(sig, &context, NULL);
	return oldhandler;
#else
	return signal(sig, handler);
#endif
}
