/* Target parser ABI from CPython 2.1 headers and verified GSQE78 layout.
 * Upstream license: reference/cpython-2.1/LICENSE. */
#ifndef ROTFD_PARSER_ABI_H
#define ROTFD_PARSER_ABI_H
#define NULL 0
#define EOF (-1)
#define BUFSIZ 4096
#define DL_IMPORT(type) type
#define assert(condition) ((void)0)
typedef unsigned int size_t;
typedef struct { char reserved_00[9]; unsigned char eof; char reserved_0a[70]; } FILE;
void *malloc(size_t);
void *realloc(void *, size_t);
void free(void *);
char *strchr(const char *, int);
char *strstr(const char *, const char *);
char *strcpy(char *, const char *);
size_t strlen(const char *);
int strcmp(const char *, const char *);
int strncmp(const char *, const char *, size_t);
int atoi(const char *);
char *fgets(char *, int, FILE *);
#define feof(fp) ((fp)->eof)
void PySys_WriteStderr(const char *, ...);
void PySys_WriteStdout(const char *, ...);
void Py_FatalError(const char *);
extern int Py_TabcheckFlag;
extern int Py_VerboseFlag;
extern unsigned char __ctype_map[];
#define isalpha(c) (__ctype_map[(unsigned char)(c)] & 0xC0)
#define isalnum(c) (__ctype_map[(unsigned char)(c)] & 0xD0)
#define isdigit(c) (__ctype_map[(unsigned char)(c)] & 0x10)
#define isxdigit(c) (__ctype_map[(unsigned char)(c)] & 0x20)
#define isspace(c) (__ctype_map[(unsigned char)(c)] & 0x06)
#define PyMem_NEW(type, n) ((type *)malloc(1 + (n) * sizeof(type)))
#define PyMem_RESIZE(p, type, n) if ((p) == NULL) (p) = (type *)malloc(1 + (n) * sizeof(type)); else (p) = (type *)realloc((p), 1 + (n) * sizeof(type))
#define PyMem_DEL free
#define PyMem_FREE free

/* Token types */

#ifndef Py_TOKEN_H
#define Py_TOKEN_H
#ifdef __cplusplus
extern "C" {
#endif

#define ENDMARKER	0
#define NAME		1
#define NUMBER		2
#define STRING		3
#define NEWLINE		4
#define INDENT		5
#define DEDENT		6
#define LPAR		7
#define RPAR		8
#define LSQB		9
#define RSQB		10
#define COLON		11
#define COMMA		12
#define SEMI		13
#define PLUS		14
#define MINUS		15
#define STAR		16
#define SLASH		17
#define VBAR		18
#define AMPER		19
#define LESS		20
#define GREATER		21
#define EQUAL		22
#define DOT		23
#define PERCENT		24
#define BACKQUOTE	25
#define LBRACE		26
#define RBRACE		27
#define EQEQUAL		28
#define NOTEQUAL	29
#define LESSEQUAL	30
#define GREATEREQUAL	31
#define TILDE		32
#define CIRCUMFLEX	33
#define LEFTSHIFT	34
#define RIGHTSHIFT	35
#define DOUBLESTAR	36
#define PLUSEQUAL	37
#define MINEQUAL	38
#define STAREQUAL	39
#define SLASHEQUAL	40
#define PERCENTEQUAL	41
#define AMPEREQUAL	42
#define VBAREQUAL	43
#define CIRCUMFLEXEQUAL	44
#define LEFTSHIFTEQUAL	45
#define RIGHTSHIFTEQUAL	46
#define DOUBLESTAREQUAL	47
/* Don't forget to update the table _PyParser_TokenNames in tokenizer.c! */
#define OP		48
#define ERRORTOKEN	49
#define N_TOKENS	50

/* Special definitions for cooperation with parser */

#define NT_OFFSET		256

#define ISTERMINAL(x)		((x) < NT_OFFSET)
#define ISNONTERMINAL(x)	((x) >= NT_OFFSET)
#define ISEOF(x)		((x) == ENDMARKER)


extern DL_IMPORT(char *) _PyParser_TokenNames[]; /* Token names */
static inline int PyToken_OneChar(int);
extern DL_IMPORT(int) PyToken_TwoChars(int, int);
static inline int PyToken_ThreeChars(int, int, int);

#ifdef __cplusplus
}
#endif
#endif /* !Py_TOKEN_H */

#ifndef Py_ERRCODE_H
#define Py_ERRCODE_H
#ifdef __cplusplus
extern "C" {
#endif


/* Error codes passed around between file input, tokenizer, parser and
   interpreter.  This is necessary so we can turn them into Python
   exceptions at a higher level.  Note that some errors have a
   slightly different meaning when passed from the tokenizer to the
   parser than when passed from the parser to the interpreter; e.g.
   the parser only returns E_EOF when it hits EOF immediately, and it
   never returns E_OK. */

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

#ifdef __cplusplus
}
#endif
#endif /* !Py_ERRCODE_H */

#ifndef Py_TOKENIZER_H
#define Py_TOKENIZER_H
#ifdef __cplusplus
extern "C" {
#endif


/* Tokenizer interface */


#define MAXINDENT 100	/* Max indentation level */

/* Tokenizer state */
struct tok_state {
	/* Input state; buf <= cur <= inp <= end */
	/* NB an entire line is held in the buffer */
	char *buf;	/* Input buffer, or NULL; malloc'ed if fp != NULL */
	char *cur;	/* Next character in buffer */
	char *inp;	/* End of data in buffer */
	char *end;	/* End of input buffer if buf != NULL */
	char *start;	/* Start of current token if not NULL */
	int done;	/* E_OK normally, E_EOF at EOF, otherwise error code */
	/* NB If done != E_OK, cur must be == inp!!! */
	FILE *fp;	/* Rest of input; NULL if tokenizing a string */
	int tabsize;	/* Tab spacing */
	int indent;	/* Current indentation index */
	int indstack[MAXINDENT];	/* Stack of indents */
	int atbol;	/* Nonzero if at begin of new line */
	int pendin;	/* Pending indents (if > 0) or dedents (if < 0) */
	char *prompt, *nextprompt;	/* For interactive prompting */
	int lineno;	/* Current line number */
	int level;	/* () [] {} Parentheses nesting level */
			/* Used to allow free continuations inside them */
	/* Stuff for checking on different tab sizes */
	char *filename;	/* For error messages */
	int altwarning;	/* Issue warning if alternate tabs don't match */
	int alterror;	/* Issue error if alternate tabs don't match */
	int alttabsize;	/* Alternate tab spacing */
	int altindstack[MAXINDENT];	/* Stack of alternate indents */
};

extern struct tok_state *PyTokenizer_FromString(char *);
extern struct tok_state *PyTokenizer_FromFile(FILE *, char *, char *);
extern void PyTokenizer_Free(struct tok_state *);
extern int PyTokenizer_Get(struct tok_state *, char **, char **);

#ifdef __cplusplus
}
#endif
#endif /* !Py_TOKENIZER_H */



extern FILE __files[];
#define stdin (&__files[0])
#define stdout (&__files[1])
#define stderr (&__files[2])
int fprintf(FILE *, const char *, ...);

#ifndef Py_BITSET_H
#define Py_BITSET_H
#ifdef __cplusplus
extern "C" {
#endif

/* Bitset interface */

#define BYTE		char

typedef BYTE *bitset;

bitset newbitset(int nbits);
void delbitset(bitset bs);
#define testbit(ss, ibit) (((ss)[BIT2BYTE(ibit)] & BIT2MASK(ibit)) != 0)
int addbit(bitset bs, int ibit); /* Returns 0 if already set */
int samebitset(bitset bs1, bitset bs2, int nbits);
void mergebitset(bitset bs1, bitset bs2, int nbits);

#define BITSPERBYTE	(8*sizeof(BYTE))
#define NBYTES(nbits)	(((nbits) + BITSPERBYTE - 1) / BITSPERBYTE)

#define BIT2BYTE(ibit)	((ibit) / BITSPERBYTE)
#define BIT2SHIFT(ibit)	((ibit) % BITSPERBYTE)
#define BIT2MASK(ibit)	(1 << BIT2SHIFT(ibit))
#define BYTE2BIT(ibyte)	((ibyte) * BITSPERBYTE)

#ifdef __cplusplus
}
#endif
#endif /* !Py_BITSET_H */


/* Parse tree node interface */

#ifndef Py_NODE_H
#define Py_NODE_H
#ifdef __cplusplus
extern "C" {
#endif

typedef struct _node {
    short		n_type;
    char		*n_str;
    int			n_lineno;
    int			n_nchildren;
    struct _node	*n_child;
} node;

extern DL_IMPORT(node *) PyNode_New(int type);
extern DL_IMPORT(int) PyNode_AddChild(node *n, int type,
                                      char *str, int lineno);
extern DL_IMPORT(void) PyNode_Free(node *n);

/* Node access functions */
#define NCH(n)		((n)->n_nchildren)
#define CHILD(n, i)	(&(n)->n_child[i])
#define TYPE(n)		((n)->n_type)
#define STR(n)		((n)->n_str)

/* Assert that the type of a node is what we expect */
#ifndef Py_DEBUG
#define REQ(n, type) { /*pass*/ ; }
#else
#define REQ(n, type) \
	{ if (TYPE(n) != (type)) { \
	    fprintf(stderr, "FATAL: node type %d, required %d\n", \
		    TYPE(n), type); \
	    abort(); \
	} }
#endif

extern DL_IMPORT(void) PyNode_ListTree(node *);

#ifdef __cplusplus
}
#endif
#endif /* !Py_NODE_H */


/* Grammar interface */

#ifndef Py_GRAMMAR_H
#define Py_GRAMMAR_H
#ifdef __cplusplus
extern "C" {
#endif


/* A label of an arc */

typedef struct {
    int		 lb_type;
    char	*lb_str;
} label;

#define EMPTY 0		/* Label number 0 is by definition the empty label */

/* A list of labels */

typedef struct {
    int		 ll_nlabels;
    label	*ll_label;
} labellist;

/* An arc from one state to another */

typedef struct {
    short	a_lbl;		/* Label of this arc */
    short	a_arrow;	/* State where this arc goes to */
} arc;

/* A state in a DFA */

typedef struct {
    int		 s_narcs;
    arc		*s_arc;		/* Array of arcs */
	
    /* Optional accelerators */
    int		 s_lower;	/* Lowest label index */
    int		 s_upper;	/* Highest label index */
    int		*s_accel;	/* Accelerator */
    int		 s_accept;	/* Nonzero for accepting state */
} state;

/* A DFA */

typedef struct {
    int		 d_type;	/* Non-terminal this represents */
    char	*d_name;	/* For printing */
    int		 d_initial;	/* Initial state */
    int		 d_nstates;
    state	*d_state;	/* Array of states */
    bitset	 d_first;
} dfa;

/* A grammar */

typedef struct {
    int		 g_ndfas;
    dfa		*g_dfa;		/* Array of DFAs */
    labellist	 g_ll;
    int		 g_start;	/* Start symbol of the grammar */
    int		 g_accel;	/* Set if accelerators present */
} grammar;

/* FUNCTIONS */

grammar *newgrammar(int start);
dfa *adddfa(grammar *g, int type, char *name);
int addstate(dfa *d);
void addarc(dfa *d, int from, int to, int lbl);
dfa *PyGrammar_FindDFA(grammar *g, int type);

int addlabel(labellist *ll, int type, char *str);
int findlabel(labellist *ll, int type, char *str);
char *PyGrammar_LabelRepr(label *lb);
void translatelabels(grammar *g);

void addfirstsets(grammar *g);

void PyGrammar_AddAccelerators(grammar *g);
void PyGrammar_RemoveAccelerators(grammar *);

void printgrammar(grammar *g, FILE *fp);
void printnonterminals(grammar *g, FILE *fp);

#ifdef __cplusplus
}
#endif
#endif /* !Py_GRAMMAR_H */

#ifndef Py_PARSER_H
#define Py_PARSER_H
#ifdef __cplusplus
extern "C" {
#endif


/* Parser interface */

#define MAXSTACK 500

typedef struct {
	int		 s_state;	/* State in current DFA */
	dfa		*s_dfa;		/* Current DFA */
	struct _node	*s_parent;	/* Where to add next node */
} stackentry;

typedef struct {
	stackentry	*s_top;		/* Top entry */
	stackentry	 s_base[MAXSTACK];/* Array of stack entries */
					/* NB The stack grows down */
} stack;

typedef struct {
	stack	 	p_stack;	/* Stack of parser states */
	grammar		*p_grammar;	/* Grammar to use */
	node		*p_tree;	/* Top of parse tree */
} parser_state;

parser_state *PyParser_New(grammar *g, int start);
void PyParser_Delete(parser_state *ps);
int PyParser_AddToken(parser_state *ps, int type, char *str, int lineno,
                      int *expected_ret);
void PyGrammar_AddAccelerators(grammar *g);

#ifdef __cplusplus
}
#endif
#endif /* !Py_PARSER_H */


/* Parser-tokenizer link interface */

#ifndef Py_PARSETOK_H
#define Py_PARSETOK_H
#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int error;
    char *filename;
    int lineno;
    int offset;
    char *text;
    int token;
    int expected;
} perrdetail;

extern DL_IMPORT(node *) PyParser_ParseString(char *, grammar *, int,
                                              perrdetail *);
extern DL_IMPORT(node *) PyParser_ParseFile (FILE *, char *, grammar *, int,
                                             char *, char *, perrdetail *);

#ifdef __cplusplus
}
#endif
#endif /* !Py_PARSETOK_H */


#endif
