/* Shared callback dispatch state; types are established by the callback APIs. */
struct DispatchNode;

int lbl_80378094;
unsigned long lbl_80378090;
unsigned long lbl_8037808C;
struct DispatchNode* lbl_80378088;

typedef char CallbackWordSizeCheck[sizeof(unsigned long) == 4 ? 1 : -1];
typedef char CallbackNodePointerSizeCheck[sizeof(struct DispatchNode*) == 4 ? 1 : -1];
