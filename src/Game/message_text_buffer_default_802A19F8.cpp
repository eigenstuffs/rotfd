// Empty message-text work buffer copied by the scene message parser.
// This definition has the same type as the parser's existing declaration.
struct Buffer { char text[2048]; };
extern "C" const Buffer lbl_802A19F8 = {{0}};
typedef char MessageTextBufferSize[sizeof(Buffer)==2048?1:-1];
