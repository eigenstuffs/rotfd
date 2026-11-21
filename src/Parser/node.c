/* CPython 2.1 parse-tree nodes; see reference/cpython-2.1/LICENSE. */
#define NULL 0
#define INT_MAX 2147483647
#define E_NOMEM 15
#define E_OVERFLOW 19
typedef unsigned int size_t;
void *malloc(size_t);
void *realloc(void *, size_t);
void free(void *);
typedef struct _node {
    short n_type;
    char *n_str;
    int n_lineno;
    int n_nchildren;
    struct _node *n_child;
} node;
#define PyMem_NEW(type, n) ((type *)malloc(1 + (n) * sizeof(type)))
#define PyMem_RESIZE(p, type, n) if ((p) == NULL) (p) = (type *)malloc(1 + (n) * sizeof(type)); else (p) = (type *)realloc((p), 1 + (n) * sizeof(type))
#define PyMem_DEL free
#define NCH(n) ((n)->n_nchildren)
#define CHILD(n, i) (&(n)->n_child[i])
#define STR(n) ((n)->n_str)
/* Parse tree node implementation */


node *
PyNode_New(int type)
{
	node *n = PyMem_NEW(node, 1);
	if (n == NULL)
		return NULL;
	n->n_type = type;
	n->n_str = NULL;
	n->n_lineno = 0;
	n->n_nchildren = 0;
	n->n_child = NULL;
	return n;
}

#define XXX 3 /* Node alignment factor to speed up realloc */
#define XXXROUNDUP(n) ((n) == 1 ? 1 : ((n) + XXX - 1) / XXX * XXX)

int
PyNode_AddChild(register node *n1, int type, char *str, int lineno)
{
	register int nch = n1->n_nchildren;
	register int nch1 = nch+1;
	register node *n;
	if (nch == INT_MAX || nch < 0)
		return E_OVERFLOW;
	if (XXXROUNDUP(nch) < nch1) {
		n = n1->n_child;
		nch1 = XXXROUNDUP(nch1);
		PyMem_RESIZE(n, node, nch1);
		if (n == NULL)
			return E_NOMEM;
		n1->n_child = n;
	}
	n = &n1->n_child[n1->n_nchildren++];
	n->n_type = type;
	n->n_str = str;
	n->n_lineno = lineno;
	n->n_nchildren = 0;
	n->n_child = NULL;
	return 0;
}

/* Forward */
static void freechildren(node *);


void
PyNode_Free(node *n)
{
	if (n != NULL) {
		freechildren(n);
		PyMem_DEL(n);
	}
}

static void
freechildren(node *n)
{
	int i;
	for (i = NCH(n); --i >= 0; )
		freechildren(CHILD(n, i));
	if (n->n_child != NULL)
		PyMem_DEL(n->n_child);
	if (STR(n) != NULL)
		PyMem_DEL(STR(n));
}
