/* Bound curve owner stream/application reconstruction; see docs/notes/game-bound-curve-owner-apply.md. */
typedef unsigned long BoundCurve_801AF078_Word;
struct BoundCurve_801AF078_Curve{int unknown00,count;void*items;int unknown0C;};
struct BoundCurve_801AF078_Owner{char unknown00[0xC];BoundCurve_801AF078_Curve vector,first,second;};
struct BoundCurve_801AF078_Vector{float x,y,z;};
struct BoundCurve_801AF078_NodeStorage{BoundCurve_801AF078_Word unknown00[2];};
struct BoundCurve_801AF078_Node:BoundCurve_801AF078_NodeStorage{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34(const BoundCurve_801AF078_Vector&);char unknown0C[0x78];float first,second;};
struct BoundCurve_801AF078_Handle{union{BoundCurve_801AF078_Word value;struct{signed int tag:8,index:24;}bits;};};
struct BoundCurve_801AF078_Entry{BoundCurve_801AF078_Node*object;BoundCurve_801AF078_Word unknown04[2];signed char tag;char padding0D[3];int getTag()const{return tag;}};
struct BoundCurve_801AF078_Manager{BoundCurve_801AF078_Word unknown00[2];BoundCurve_801AF078_Entry*entries;};
extern "C"{extern struct{char unknown00[0x118];BoundCurve_801AF078_Manager*manager;}lbl_801E9D24;short fn_801B0AA0(BoundCurve_801AF078_Curve*,float*,short,float);short fn_801AFFE4(BoundCurve_801AF078_Curve*,BoundCurve_801AF078_Vector*,short,float);}
inline BoundCurve_801AF078_Node*resolveBoundCurve_801AF078(const BoundCurve_801AF078_Handle*h){int index=h->bits.index;BoundCurve_801AF078_Entry*entries=lbl_801E9D24.manager->entries;int tag=entries[index].getTag();return tag==h->bits.tag?entries[index].object:0;}
extern "C"void fn_801AF078(BoundCurve_801AF078_Owner*self,const BoundCurve_801AF078_Handle*handle,float time){BoundCurve_801AF078_Node*node=resolveBoundCurve_801AF078(handle);BoundCurve_801AF078_Vector vector;float first,second;
 if(self->first.count){fn_801B0AA0(&self->first,&first,1,time);node->first=first;}
 if(self->second.count){fn_801B0AA0(&self->second,&second,1,time);node->second=second;}
 if(self->vector.count){fn_801AFFE4(&self->vector,&vector,1,time);node->slot34(vector);}
}
