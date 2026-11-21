/* Original scalar operations with private observed layouts.
 * See docs/notes/game-scalar-early.md. */

struct Child {char pad[0x234];unsigned int flags;float color[4];};

struct Parent {char pad[0x48];struct Child *child;};

extern struct {char pad[0x114];struct Parent *parent;} lbl_801E9D24;

extern const float lbl_80378F7C,lbl_80378F80;

static inline void set4(float *out,float x,float y,float z,float w) {out[0]=x;out[1]=y;out[2]=z;out[3]=w;}

void fn_800A84D8(void) {if(lbl_801E9D24.parent){lbl_801E9D24.parent->child->flags&=~4U;set4(lbl_801E9D24.parent->child->color,lbl_80378F7C,lbl_80378F7C,lbl_80378F7C,lbl_80378F80);}}
