/* Original array and scalar routines with private observed layouts.
 * See docs/notes/game-scalar-early-more.md. */

struct Child {char pad[0x234];unsigned int flags;float color[4];};

struct Parent {char pad[0x48];struct Child *child;};

extern struct {char pad[0x114];struct Parent *parent;} lbl_801E9D24;

static inline void copy4(float *out,const float *in) {out[0]=in[0];out[1]=in[1];out[2]=in[2];out[3]=in[3];}

void fn_800A846C(float *object,const float *color,float amount) {object[0x60/4]=amount;copy4(object+0x50/4,color);lbl_801E9D24.parent->child->flags|=4U;copy4(lbl_801E9D24.parent->child->color,color);}
