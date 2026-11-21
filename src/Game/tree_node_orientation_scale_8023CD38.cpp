/* Tree-node transform setters (fn_8023CD38, fn_8023CEC4, fn_8023CFE4).
   Each resolves the node's parent, optionally refreshes the parent's cached
   transposed basis / world matrix, and writes the node's orientation and
   uniform scale relative to the parent: the scale is divided (CD38) or
   multiplied (CEC4, CFE4) by the length of the parent matrix's X column.
   Layout as include/Game/engine_tree_records.h (fn_8023D120 neighbour).
   The engine square root is the established frsqrte/fres fastSqrt helper.
   The length helper must take the three components as parameters (a local
   copy of the column swaps the x/z float registers).  Flags as
   engine_tree_orientation.cpp: -O4,p, -Cpp_exceptions off. */
#pragma fp_contract on
struct TreeVector{float x,y,z;};
struct TreeQuaternion{float x,y,z,w;};
struct TreeMatrix3{float m[9];};
struct TreeMatrix4{float m[16];};
struct TreeHandle{signed int generation:8;signed int index:24;};
struct TreeNode{
    char unknown00[0xC];
    TreeHandle parent;
    char unknown10[0x20];
    TreeMatrix3 basis;
    TreeMatrix3 transposeBasis;
    char unknown78[0x40];
    TreeVector position;
    unsigned int unknownC4;
    TreeQuaternion orientation;
    TreeVector scale;
    char unknownE4[0x3C];
    unsigned int flags;
    TreeMatrix4*local;
    TreeMatrix4*world;
    short unknown12C,index;
};
struct TreeEntry{TreeNode*object;char unknown04[8];signed char generation;char unknown0D[3];};
struct TreeManager{char unknown00[8];TreeEntry*entries;};
struct TreeMatrixBuffers{TreeMatrix4*banks[6];unsigned char active;};
struct TreeContext{char unknown00[0x118];TreeManager*manager;char unknown11C[0x18];TreeMatrixBuffers*matrices;};
extern "C"{
extern TreeContext lbl_801E9D24;
extern const float lbl_8037B32C;
void fn_801F2124(void*,TreeMatrix3*);
void fn_801F1CD8(const TreeQuaternion*,TreeMatrix3*);
void fn_801F223C(TreeMatrix3*,const TreeMatrix3*);
void fn_801F20F4(TreeQuaternion*,const TreeMatrix3*);
void fn_801F230C(TreeMatrix4*,TreeMatrix4*);
void fn_8023D258(TreeNode*,const TreeVector*);
void fn_8023D648(TreeNode*);
}
inline float fastSqrt(register float x){register float r;asm{frsqrte f4,x
fres r,f4}return r;}
static inline TreeNode*resolve(const TreeHandle&h){TreeEntry*entry=&lbl_801E9D24.manager->entries[h.index];return entry->generation==h.generation?entry->object:0;}
static inline void refreshTranspose(TreeNode*node){if(node->flags&0x40){fn_801F2124(&node->basis,&node->transposeBasis);node->flags&=~0x40;}}
static inline void refreshWorld(TreeNode*node){if(node->flags&0x20){node->world=&lbl_801E9D24.matrices->banks[lbl_801E9D24.matrices->active][node->index];fn_801F230C(node->local,node->world);node->flags&=~0x20;}}
static inline float length(float x,float y,float z){float sq=x*x+y*y+z*z;float r=lbl_8037B32C;if(sq!=r)r=fastSqrt(sq);return r;}
static inline float columnLength(const TreeMatrix4&m){return length(m.m[0],m.m[4],m.m[8]);}

extern "C" void fn_8023CD38(TreeNode*self,const TreeVector*point,const TreeQuaternion*orientation,const float*scale){
    TreeNode*parent=resolve(self->parent);
    fn_8023D258(self,point);
    refreshTranspose(parent);
    TreeMatrix3 copy=parent->transposeBasis;
    TreeMatrix3 other;
    TreeQuaternion output;
    fn_801F1CD8(orientation,&other);
    fn_801F223C(&copy,&other);
    fn_801F20F4(&output,&copy);
    self->orientation.x=output.x;
    self->orientation.y=output.y;
    self->orientation.z=output.z;
    self->orientation.w=output.w;
    float value=*scale/columnLength(*parent->local);
    self->scale.x=value;
    self->scale.y=value;
    self->scale.z=value;
}

extern "C" void fn_8023CEC4(TreeNode*self,float scale){
    TreeNode*parent=resolve(self->parent);
    refreshWorld(parent);
    float value=scale*columnLength(*parent->world);
    self->scale.x=value;
    self->scale.y=value;
    self->scale.z=value;
    fn_8023D648(self);
}

extern "C" void fn_8023CFE4(TreeNode*self,const TreeVector*point,float scale){
    fn_8023D258(self,point);
    TreeNode*parent=resolve(self->parent);
    refreshWorld(parent);
    float value=scale*columnLength(*parent->world);
    self->scale.x=value;
    self->scale.y=value;
    self->scale.z=value;
}
