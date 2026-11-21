/* Original short control delegates; see docs/notes/game-short-control-delegates.md. */
struct Resource;extern "C"float fn_8005EC4C(Resource*,Resource*);extern "C"float fn_80066FAC(void*ignored,Resource*first,Resource*second){return fn_8005EC4C(first,second);}
