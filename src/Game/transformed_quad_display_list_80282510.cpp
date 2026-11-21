typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;

struct DebugVec3 {float x,y,z; DebugVec3(){} DebugVec3(float a,float b,float c):x(a),y(b),z(c){} };
struct DebugQuat {float x,y,z,w;DebugQuat(){} DebugQuat&operator=(const DebugQuat&q){x=q.x;y=q.y;z=q.z;w=q.w;return *this;} };
struct DebugMatrix {float m[4][4];};

struct Entry {void*object;u32 unknown[2];signed char generation;char pad[3];};
struct Manager {int count,capacity;Entry*entries;};
struct Handle_801F7F10 {
    union {
        u32 value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
extern "C" void fn_801F86C8(Manager*, const void*, short);

struct DebugStateStorage {char unknown00[0x278];};
struct DebugState:DebugStateStorage {
 virtual void slot08();
 virtual void slot0C();
 virtual void slot10();
 virtual void slot14();
 virtual void slot18();
 virtual void slot1C();
 virtual void slot20();
 virtual void slot24();
 virtual void slot28();
 virtual void slot2C();
 virtual void slot30();
 virtual void slot34();
 virtual void slot38();
 virtual void slot3C();
 virtual void slot40();
 virtual void slot44();
 virtual void slot48();
 virtual void slot4C();
 virtual void slot50();
 virtual void slot54();
 virtual void slot58();
 virtual void slot5C();
 virtual void slot60();
 virtual void slot64();
 virtual void slot68();
 virtual void slot6C();
 virtual void slot70();
 virtual void slot74();
 virtual void slot78();
 virtual void slot7C();
 virtual void slot80();
 virtual void slot84();
 virtual void slot88();
 virtual void slot8C();
 virtual void slot90();
 virtual void slot94();
 virtual void slot98();
 virtual void slot9C();
 virtual void bind(const Handle_801F7F10&);
 char unknown27C[0x54];unsigned short flags,mask;
};
struct DebugRenderer {char unknown00[0x48];DebugState* state;};
struct DebugNode {char unknown00[0x120];u32 flags;DebugMatrix* source;DebugMatrix* inverse;short unknown12C,slot;};
struct DebugInput {DebugRenderer*renderer;char unknown04[8];DebugNode* transform;DebugNode* resource;};
struct DebugList {void*data;u32 capacity,used;};
struct DebugOwner {char unknown00[0x24];DebugVec3 position,rotation;float radius;DebugList list;};
struct DebugBanks {DebugMatrix* banks[6];unsigned char active;};
struct DebugAssets {char unknown00[0x280];Handle_801F7F10 handle;};
struct DebugGlobals {char unknown00[0x118];Manager* manager;char unknown11C[0x18];DebugBanks* matrices;char unknown138[0x14];DebugAssets* assets;};
extern "C" DebugGlobals lbl_801E9D24;
#define debugGlobals lbl_801E9D24
struct DebugZeroHandle:Handle_801F7F10 {DebugZeroHandle(){value=0;}~DebugZeroHandle(){}};
struct DebugHandle:DebugZeroHandle {
 DebugHandle(const Handle_801F7F10&h){value=h.value;fn_801F86C8(debugGlobals.manager,&h,1);}
 ~DebugHandle(){}
};

/* Write-gather FIFO.  The original code used literal constants, which CodeWarrior
   reloads at every use; the shared pool labels are mutable externs here so that each
   FIFO store (through an unknown pointer) forces the same reload. */
#define GX_FIFO_F32 (*(volatile float*)0xCC008000)
#define GX_FIFO_U32 (*(volatile u32*)0xCC008000)

extern "C" {
 extern float lbl_8037B800,lbl_8037B804,lbl_8037B808;
 void fn_801F230C(const DebugMatrix*,DebugMatrix*);
 DebugQuat fn_801F27BC(const DebugVec3&,const DebugVec3&);
 void* memset(void*,int,unsigned long);
 void fn_801F1D90(const DebugQuat*,DebugMatrix*);
 DebugMatrix* fn_801F2788(DebugMatrix*,const DebugMatrix*);
 void fn_80272F14(DebugState*,DebugMatrix*);
 void fn_8027353C(DebugState*);
 void DCInvalidateRange(void*,u32);
 void DCStoreRange(void*,u32);
 void GXResetWriteGatherPipe();
 void GXBeginDisplayList(void*,u32);
 u32 GXEndDisplayList();
 void GXBegin(int,int,u16);
}

extern "C" void fn_80282510(DebugOwner*self,DebugInput*input){
 if(!(signed char)((input->resource->flags>>19)&1))return;
 DebugMatrix*source=input->resource->source;
 DebugNode*node=input->transform;
 float x=source->m[3][0]+((source->m[0][0]*self->position.x+source->m[1][0]*self->position.y)+source->m[2][0]*self->position.z);
 float y=source->m[3][1]+((source->m[0][1]*self->position.x+source->m[1][1]*self->position.y)+source->m[2][1]*self->position.z);
 float z=source->m[3][2]+((source->m[0][2]*self->position.x+source->m[1][2]*self->position.y)+source->m[2][2]*self->position.z);
 DebugState*state=input->renderer->state;
 if(node->flags&0x20){DebugBanks*banks=debugGlobals.matrices;node->inverse=banks->banks[banks->active]+node->slot;fn_801F230C(node->source,node->inverse);node->flags&=~0x20;}
 DebugMatrix inverse=*node->inverse;
 DebugVec3 axis(lbl_8037B800,lbl_8037B804,lbl_8037B800);
 DebugQuat rotation;rotation=fn_801F27BC(axis,self->rotation);
 DebugMatrix matrix;memset(&matrix,0,sizeof(matrix));
 matrix.m[0][0]=lbl_8037B804;matrix.m[1][1]=lbl_8037B804;matrix.m[2][2]=lbl_8037B804;matrix.m[3][3]=lbl_8037B804;
 fn_801F1D90(&rotation,&matrix);
 matrix.m[3][0]=x;matrix.m[3][1]=y;matrix.m[3][2]=z;
 fn_801F2788(&inverse,&matrix);fn_80272F14(state,&inverse);
 state->flags=0;state->mask=0xFFFF;
 state->bind(DebugHandle(debugGlobals.assets->handle));
 state->flags|=0x2000;fn_8027353C(state);
 DCInvalidateRange(self->list.data,self->list.capacity);GXBeginDisplayList(self->list.data,self->list.capacity);GXResetWriteGatherPipe();GXBegin(0x80,1,4);
{float a=-self->radius;
  GX_FIFO_F32=a;
  GX_FIFO_F32=lbl_8037B808;
  GX_FIFO_F32=a;
  GX_FIFO_U32=127;
  GX_FIFO_F32=lbl_8037B800;
  GX_FIFO_F32=lbl_8037B800;}
 {float c=-self->radius;
  GX_FIFO_F32=self->radius;
  GX_FIFO_F32=lbl_8037B808;
  GX_FIFO_F32=c;
  GX_FIFO_U32=127;
  GX_FIFO_F32=lbl_8037B804;
  GX_FIFO_F32=lbl_8037B800;}
 {float b=self->radius;
  GX_FIFO_F32=b;
  GX_FIFO_F32=lbl_8037B808;
  GX_FIFO_F32=b;
  GX_FIFO_U32=127;
  GX_FIFO_F32=lbl_8037B804;
  GX_FIFO_F32=lbl_8037B804;}
 {float b=self->radius;float c=-b;
  GX_FIFO_F32=c;
  GX_FIFO_F32=lbl_8037B808;
  GX_FIFO_F32=b;
  GX_FIFO_U32=127;
  GX_FIFO_F32=lbl_8037B800;
  GX_FIFO_F32=lbl_8037B804;}
 self->list.used=GXEndDisplayList();DCStoreRange(self->list.data,self->list.capacity);
}
